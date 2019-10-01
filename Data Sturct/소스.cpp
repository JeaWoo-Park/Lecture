#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;

#define Width 20
#define Height 20


int save_Board[Height][Width];

struct Point {
	int x;
	int y;
};

struct MaxCheck {
	Point place;
	Point blankPlace;
	int color;   // 1은 검정, 2는 하양
	int max;
};
int top = 0;
int temp_Top = 0;
int MaxCnt = 0;
bool isTrue = false;
Point stack[400];
Point temp_Stack[400];
MaxCheck wid[Width] = { 0, }, hei[Height] = { 0, }, diaR[Height][Width] = { 0, }, diaL[Height][Width] = { 0, };
Point blankP = { 0, 0 };

void push(Point stack[], Point place)
{
	stack[top] = place;
	top++;
}

Point pop(Point stack[])
{
	stack[top] = { 0, 0 };
	top--;
	return stack[top];
}

void temp_push(Point stack[], Point place)
{
	stack[temp_Top] = place;
	temp_Top++;
}

Point temp_pop(Point stack[])
{
	stack[temp_Top] = { 0, 0 };
	temp_Top--;
	return stack[temp_Top];
}

class TicTacToe
{
	Point place;
	int board[Height][Width];   // -1은 비어있음, 1은 검은돌, 2는 흰돌, 3은 막아야 할 곳
public:
	TicTacToe();
	~TicTacToe();
	void setB();
	void setW();
	void Load_Board();
	void Save_Board();
	void Ripen();
	void Cancel(int turn);
	void findMax();
	void isWarn();
	void check() const;
	void draw() const;
};

TicTacToe::TicTacToe()
{
	for (int i = 0; i < Height; ++i) {
		for (int j = 0; j < Width; ++j) {
			board[i][j] = -1;
		}
	}
	place.x = 0;
	place.y = 0;
	for (int i = 0; i < Height; ++i) {
		for (int j = 0; j < Width; ++j) {
			diaR[i][j].blankPlace.x = -1;
			diaR[i][j].blankPlace.y = -1;
			diaL[i][j].blankPlace.x = -1;
			diaL[i][j].blankPlace.y = -1;
			wid[j].blankPlace.x = -1;
			wid[j].blankPlace.y = -1;
		}
		hei[i].blankPlace.x = -1;
		hei[i].blankPlace.y = -1;
	}
}

TicTacToe::~TicTacToe()
{

}

void TicTacToe::setB()
{
	cout << "검은돌의 차례입니다. 좌표를 입력하세요 : ";
	cin >> place.x >> place.y;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(10, '\n');
	}
	if (board[Height - place.y][place.x - 1] == -1 || board[Height - place.y][place.x - 1] == 3) {
		board[Height - place.y][place.x - 1] = 1;
		save_Board[Height - place.y][place.x - 1] = 1;
		push(stack, place);
		for (int i = 0; i < Height * Width; ++i) {
			temp_Stack[i] = { 0, 0 };
		}
		temp_Top = 0;
	}
	else {
		cout << "잘못된 위치입니다. 다른 좌표를 입력하세요." << endl;
		setB();
	}
}

void TicTacToe::setW()
{
	cout << "흰돌의 차례입니다. 좌표를 입력하세요 : ";
	cin >> place.x >> place.y;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(10, '\n');
	}
	if (board[Height - place.y][place.x - 1] == -1 || board[Height - place.y][place.x - 1] == 3) {
		board[Height - place.y][place.x - 1] = 2;
		save_Board[Height - place.y][place.x - 1] = 2;
		push(stack, place);
		for (int i = 0; i < Height * Width; ++i) {
			temp_Stack[i] = { 0, 0 };
		}
		temp_Top = 0;
	}
	else {
		cout << "잘못된 위치입니다. 다른 좌표를 입력하세요." << endl;
		setW();
	}
}

void TicTacToe::Load_Board() {
	temp_Top = 0;
	top = 0;
	ifstream in("save.txt");
	if (in.is_open()) {
		for (int i = 0; i < Height; ++i) {
			for (int j = 0; j < Width; ++j) {
				in >> board[i][j];
			}
		}
	}
	in.close();
	ifstream in_stack("stack.txt");
	if (in_stack.is_open()) {
		for (int i = 0; i < Height * Width; ++i) {
			in_stack >> stack[i].x >> stack[i].y;
			if (stack[i].x != 0) {
				top++;
			}
		}
	}
	in_stack.close();
	ifstream in_Temp_stack("temp_stack.txt");
	if (in_Temp_stack.is_open()) {
		for (int i = 0; i < Height * Width; ++i) {
			in_Temp_stack >> temp_Stack[i].x >> temp_Stack[i].y;
			if (temp_Stack[i].x != 0) {
				temp_Top++;
			}
		}
	}
	in_Temp_stack.close();
	temp_Top--;
}

void TicTacToe::Save_Board()
{
	ofstream out("save.txt");
	if (out.is_open()) {
		for (int i = 0; i < Height; ++i) {
			for (int j = 0; j < Width; ++j) {
				out << board[i][j] << " ";
			}
		}
	}
	out.close();
	ofstream out_stack("stack.txt");
	if (out_stack.is_open()) {
		for (int i = 0; i < Height * Width; ++i) {
			out_stack << stack[i].x << " " << stack[i].y << " ";
		}
	}
	out_stack.close();
	ofstream out_Temp_stack("temp_stack.txt");
	if (out_Temp_stack.is_open()) {
		for (int i = 0; i < Height * Width; ++i) {
			out_Temp_stack << temp_Stack[i].x << " " << temp_Stack[i].y << " ";
		}
	}
	out_Temp_stack.close();
}

void TicTacToe::Ripen()
{
	if (top > 0) {
		place = pop(stack);
		board[Height - place.y][place.x - 1] = -1;
		temp_push(temp_Stack, place);
		isTrue = true;

		for (int i = 0; i < Height; ++i) {
			for (int j = 0; j < Width; ++j) {
				diaR[i][j] = { 0, };
				diaR[i][j].blankPlace.x = -1;
				diaR[i][j].blankPlace.y = -1;
				diaL[i][j] = { 0, };
				diaL[i][j].blankPlace.x = -1;
				diaL[i][j].blankPlace.y = -1;
				wid[j] = { 0, };
				wid[j].blankPlace.x = -1;
				wid[j].blankPlace.y = -1;
			}
			hei[i] = { 0, };
			hei[i].blankPlace.x = -1;
			hei[i].blankPlace.y = -1;
		}
		MaxCnt = 0;
	}
}

void TicTacToe::Cancel(int turn)
{
	if (temp_Top > 0) {
		place = temp_pop(temp_Stack);
		if (turn % 2 == 1) {
			board[Height - place.y][place.x - 1] = 1;
		}
		else if (turn % 2 == 0) {
			board[Height - place.y][place.x - 1] = 2;
		}
		push(stack, place);
		isTrue = true;
	}
}

void TicTacToe::findMax()
{
	int nowBcnt = 0;
	bool isBlank = false;
	int k = 0;
	int tempMax = 0;
	for (int i = 0; i < Height; ++i) {
		for (int j = 0; j < Width; ++j) {
			// 가로
			// 검은돌
			if (board[i][j] == 1) {
				while (1) {
					if (board[i][j + k] == 1) {
						nowBcnt++;
					}
					else {
						break;
					}
					k++;
				}
				k = 0;
				if (board[i][j + nowBcnt + 1] == 1 && board[i][j + nowBcnt] != 2) {
					blankP.x = j + nowBcnt;
					blankP.y = i;
					isBlank = true;
					while (1) {
						if (board[i][j + nowBcnt + k + 1] == 1) {
							nowBcnt++;
						}
						else {
							break;
						}

					}
				}
				k = 0;
				if (wid[i].max < nowBcnt) {
					wid[i].max = nowBcnt;
					wid[i].place.x = j;
					wid[i].place.y = i;
					wid[i].color = 1;
					if (isBlank) {
						wid[i].blankPlace = blankP;
						isBlank = false;
					}
				}
				if (MaxCnt < nowBcnt) {
					MaxCnt = nowBcnt;
				}
			}
			nowBcnt = 0;
			// 흰돌
			if (board[i][j] == 2) {
				while (1) {
					if (board[i][j + k] == 2) {
						nowBcnt++;
					}
					else {
						break;
					}
					k++;
				}
				k = 0;
				if (board[i][j + nowBcnt + 1] == 2 && board[i][j + nowBcnt] != 1) {
					blankP.x = j + nowBcnt;
					blankP.y = i;
					isBlank = true;
					while (1) {
						if (board[i][j + nowBcnt + k + 1] == 2) {
							nowBcnt++;
						}
						else {
							break;
						}

					}
				}
				k = 0;
				if (wid[i].max < nowBcnt) {
					wid[i].max = nowBcnt;
					wid[i].place.x = j;
					wid[i].place.y = i;
					wid[i].color = 2;
					if (isBlank) {
						wid[i].blankPlace = blankP;
						isBlank = false;
					}
				}
				if (MaxCnt < nowBcnt) {
					MaxCnt = nowBcnt;
				}
			}
			nowBcnt = 0;


			// 세로
			// 검은돌
			if (board[j][i] == 1) {
				while (1) {
					if (board[j + k][i] == 1) {
						nowBcnt++;
					}
					else {
						break;
					}
					k++;
				}
				k = 0;
				if (board[j + nowBcnt + 1][i] == 1 && board[j + nowBcnt][i] != 2) {
					blankP.x = i;
					blankP.y = j + nowBcnt;
					isBlank = true;
					while (1) {
						if (board[j + nowBcnt + k + 1][i] == 1) {
							nowBcnt++;
						}
						else {
							break;
						}

					}
				}
				k = 0;
				if (hei[i].max < nowBcnt) {
					hei[i].max = nowBcnt;
					hei[i].place.x = i;
					hei[i].place.y = j;
					hei[i].color = 1;
					if (isBlank) {
						hei[i].blankPlace = blankP;
						isBlank = false;
					}
				}
				if (MaxCnt < nowBcnt) {
					MaxCnt = nowBcnt;
				}
			}
			nowBcnt = 0;
			// 흰돌
			if (board[j][i] == 2) {
				while (1) {
					if (board[j + k][i] == 2) {
						nowBcnt++;
					}
					else {
						break;
					}
					k++;
				}
				k = 0;
				if (board[j + nowBcnt + 1][i] == 2 && board[j + nowBcnt][i] != 1) {
					blankP.x = i;
					blankP.y = j + nowBcnt;
					isBlank = true;
					while (1) {
						if (board[j + nowBcnt + k + 1][i] == 2) {
							nowBcnt++;
						}
						else {
							break;
						}

					}
				}
				k = 0;
				if (hei[i].max < nowBcnt) {
					hei[i].max = nowBcnt;
					hei[i].place.x = i;
					hei[i].place.y = j;
					hei[i].color = 2;
					if (isBlank) {
						hei[i].blankPlace = blankP;
						isBlank = false;
					}
				}
				if (MaxCnt < nowBcnt) {
					MaxCnt = nowBcnt;
				}
			}
			nowBcnt = 0;


			// 아래 대각선 ↘
			// 검은돌
			if (board[i][j] == 1) {
				while (1) {
					if (board[i + k][j + k] == 1) {
						nowBcnt++;
					}
					else {
						break;
					}
					k++;
				}
				k = 0;
				if (board[i + nowBcnt + 1][j + nowBcnt + 1] == 1 && board[i + nowBcnt][j + nowBcnt] != 2) {
					blankP.x = j + nowBcnt;
					blankP.y = i + nowBcnt;
					isBlank = true;
					while (1) {
						if (board[i + nowBcnt + k + 1][j + nowBcnt + k + 1] == 1) {
							nowBcnt++;
						}
						else {
							break;
						}

					}
				}
				k = 0;
				if (diaR[i][j].max < nowBcnt) {
					diaR[i][j].max = nowBcnt;
					diaR[i][j].place.x = j;
					diaR[i][j].place.y = i;
					diaR[i][j].color = 1;
					if (isBlank) {
						diaR[i][j].blankPlace = blankP;
						isBlank = false;
					}
				}
				if (MaxCnt < nowBcnt) {
					MaxCnt = nowBcnt;
				}
			}
			nowBcnt = 0;
			// 흰돌
			if (board[i][j] == 2) {
				while (1) {
					if (board[i + k][j + k] == 2) {
						nowBcnt++;
					}
					else {
						break;
					}
					k++;
				}
				k = 0;
				if (board[i + nowBcnt + 1][j + nowBcnt + 1] == 2 && board[i + nowBcnt][j + nowBcnt] != 1) {
					blankP.x = j + nowBcnt;
					blankP.y = i + nowBcnt;
					isBlank = true;
					while (1) {
						if (board[i + nowBcnt + k + 1][j + nowBcnt + k + 1] == 2) {
							nowBcnt++;
						}
						else {
							break;
						}

					}
				}
				k = 0;
				if (diaR[i][j].max < nowBcnt) {
					diaR[i][j].max = nowBcnt;
					diaR[i][j].place.x = j;
					diaR[i][j].place.y = i;
					diaR[i][j].color = 2;
					if (isBlank) {
						diaR[i][j].blankPlace = blankP;
						isBlank = false;
					}
				}
				if (MaxCnt < nowBcnt) {
					MaxCnt = nowBcnt;
				}
			}
			nowBcnt = 0;

			// 위쪽 대각선 ↗
			// 검은돌
			if (board[i][j] == 1) {
				while (1) {
					if (board[i - k][j + k] == 1) {
						nowBcnt++;
					}
					else {
						break;
					}
					k++;
				}
				k = 0;
				if (board[i - nowBcnt - 1][j + nowBcnt + 1] == 1 && board[i - nowBcnt][j + nowBcnt] != 2) {
					blankP.x = j + nowBcnt;
					blankP.y = i - nowBcnt;
					isBlank = true;
					while (1) {
						if (board[i - nowBcnt - k - 1][j + nowBcnt + k + 1] == 1) {
							nowBcnt++;
						}
						else {
							break;
						}

					}
				}
				k = 0;
				if (diaL[i][j].max < nowBcnt) {
					diaL[i][j].max = nowBcnt;
					diaL[i][j].place.x = j;
					diaL[i][j].place.y = i;
					diaL[i][j].color = 1;
					if (isBlank) {
						diaL[i][j].blankPlace = blankP;
						isBlank = false;
					}
				}
				if (MaxCnt < nowBcnt) {
					MaxCnt = nowBcnt;
				}
			}
			nowBcnt = 0;
			// 흰돌
			if (board[i][j] == 2) {
				while (1) {
					if (board[i - k][j + k] == 2) {
						nowBcnt++;
					}
					else {
						break;
					}
					k++;
				}
				k = 0;
				if (board[i - nowBcnt - 1][j + nowBcnt + 1] == 2 && board[i - nowBcnt][j + nowBcnt] != 1) {
					blankP.x = j + nowBcnt;
					blankP.y = i - nowBcnt;
					isBlank = true;
					while (1) {
						if (board[i - nowBcnt - k - 1][j + nowBcnt + k + 1] == 2) {
							nowBcnt++;
						}
						else {
							break;
						}

					}
				}
				k = 0;
				if (diaL[i][j].max < nowBcnt) {
					diaL[i][j].max = nowBcnt;
					diaL[i][j].place.x = j;
					diaL[i][j].place.y = i;
					diaL[i][j].color = 2;
					if (isBlank) {
						diaL[i][j].blankPlace = blankP;
						isBlank = false;
					}
				}
				if (MaxCnt < nowBcnt) {
					MaxCnt = nowBcnt;
				}
			}
			nowBcnt = 0;
		}
	}


	//출력
	if (MaxCnt > 1) {
		//가로 출력
		for (int i = 0; i < Width; ++i) {
			if (wid[i].max == MaxCnt) {
				if (wid[i].blankPlace.x != -1 && wid[i].blankPlace.y != -1) {
					tempMax++;
				}

				for (int j = 0; j < wid[i].max + tempMax; ++j) {
					if (wid[i].blankPlace.x != wid[i].place.x + j) {
						cout << "(" << wid[i].place.x + j + 1 << ", " << Height - wid[i].place.y << ") ";
						if (wid[i].color == 1) {
							cout << "검은돌 ";
						}
						else if (wid[i].color == 2) {
							cout << "흰돌 ";
						}
					}
				}
				cout << endl;
			}
		}
		tempMax = 0;

		//세로 출력
		for (int i = 0; i < Height; ++i) {
			if (hei[i].max == MaxCnt) {
				if (hei[i].blankPlace.x != -1 && hei[i].blankPlace.y != -1) {
					tempMax++;
				}

				for (int j = 0; j < hei[i].max + tempMax; ++j) {
					if (hei[i].blankPlace.x != hei[i].place.x + j) {
						cout << "(" << hei[i].place.x + 1 << ", " << Height - hei[i].place.y - j << ") ";
						if (hei[i].color == 1) {
							cout << "검은돌 ";
						}
						else if (hei[i].color == 2) {
							cout << "흰돌 ";
						}
					}
				}
				cout << endl;
			}
		}
		tempMax = 0;

		// 아래 대각선↘ 출력
		for (int i = 0; i < Height; ++i) {
			for (int j = 0; j < Width; ++j) {
				if (diaR[i][j].max == MaxCnt) {
					if (diaR[i][j].blankPlace.x != -1 && diaR[i][j].blankPlace.y != -1) {
						tempMax++;
					}

					for (int k = 0; k < diaR[i][j].max + tempMax; ++k) {
						if (diaR[i][j].blankPlace.x != diaR[i][j].place.x + k && diaR[i][j].blankPlace.y != diaR[i][j].place.y + k) {
							cout << "(" << diaR[i][j].place.x + k + 1 << ", " << Height - diaR[i][j].place.y - k << ") ";
							if (diaR[i][j].color == 1) {
								cout << "검은돌 ";
							}
							else if (diaR[i][j].color == 2) {
								cout << "흰돌 ";
							}
						}
					}
					cout << endl;
				}
			}
		}
		tempMax = 0;

		// 위쪽 대각선↗ 출력
		for (int i = 0; i < Height; ++i) {
			for (int j = 0; j < Width; ++j) {
				if (diaL[i][j].max == MaxCnt) {
					if (diaL[i][j].blankPlace.x != -1 && diaL[i][j].blankPlace.y != -1) {
						tempMax++;
					}

					for (int k = 0; k < diaL[i][j].max + tempMax; ++k) {
						if (diaL[i][j].blankPlace.x != diaL[i][j].place.x + k && diaL[i][j].blankPlace.y != diaL[i][j].place.y - k) {
							cout << "(" << diaL[i][j].place.x + k + 1 << ", " << Height - diaL[i][j].place.y + k << ") ";
							if (diaL[i][j].color == 1) {
								cout << "검은돌 ";
							}
							else if (diaL[i][j].color == 2) {
								cout << "흰돌 ";
							}
						}
					}
					cout << endl;
				}
			}
		}
		tempMax = 0;
	}
}

void TicTacToe::isWarn()
{
	for (int i = 0; i < Height; ++i) {
		for (int j = 0; j < Width; ++j) {
			if (board[i][j] == 3) {
				board[i][j] = -1;
			}
		}
	}
	for (int i = 0; i < Height; ++i) {
		for (int j = 0; j < Width; ++j) {
			// 검은돌
			if (board[i][j] == 1 && board[i][j + 1] == 1 && board[i][j + 2] == 1) {      //가로줄 검사
				if (board[i][j + 3] == 1) {
					if (board[i][j + 4] == -1) {
						board[i][j + 4] = 3;
					}
					if (board[i][j - 1] == -1) {
						board[i][j - 1] = 3;
					}
				}
				else {
					if (board[i][j + 3] == -1) {
						board[i][j + 3] = 3;
					}
					if (board[i][j - 1] == -1 && j != 0) {
						board[i][j - 1] = 3;
					}
				}
			}

			if (board[j][i] == 1 && board[j + 1][i] == 1 && board[j + 2][i] == 1) {      //세로줄 검사
				if (board[j + 3][i] == 1) {
					if (board[j + 4][i] == -1) {
						board[j + 4][i] = 3;
					}
					if (board[j - 1][i] == -1) {
						board[j - 1][i] = 3;
					}
				}
				else {
					if (board[j + 3][i] == -1) {
						board[j + 3][i] = 3;
					}
					if (board[j - 1][i] == -1) {
						board[j - 1][i] = 3;
					}
				}
			}

			if (board[i][j] == 1 && board[i + 1][j + 1] == 1 && board[i + 2][j + 2] == 1) {      //아래 대각선 검사 ↘
				if (board[i + 3][j + 3] == 1) {
					if (board[i + 4][j + 4] == -1) {
						board[i + 4][j + 4] = 3;
					}
					if (board[i - 1][j - 1] == -1) {
						board[i - 1][j - 1] = 3;
					}
				}
				else {
					if (board[i + 3][j + 3] == -1) {
						board[i + 3][j + 3] = 3;
					}
					if (board[i - 1][j - 1] == -1) {
						board[i - 1][j - 1] = 3;
					}
				}
			}

			if (board[i][j] == 1 && board[i - 1][j + 1] == 1 && board[i - 2][j + 2] == 1) {      //위 대각선 검사 ↗
				if (board[i - 3][j + 3] == 1) {
					if (board[i - 4][j + 4] == -1) {
						board[i - 4][j + 4] = 3;
					}
					if (board[i + 1][j - 1] == -1) {
						board[i + 1][j - 1] = 3;
					}
				}
				else {
					if (board[i - 3][j + 3] == -1) {
						board[i - 3][j + 3] = 3;
					}
					if (board[i + 1][j - 1] == -1) {
						board[i + 1][j - 1] = 3;
					}
				}
			}

			//흰돌
			if (board[i][j] == 2 && board[i][j + 1] == 2 && board[i][j + 2] == 2) {      //가로줄 검사
				if (board[i][j + 3] == 2 && (board[i][j + 4] == -1)) {
					board[i][j + 4] = 3;
				}
				else {
					if (board[i][j + 3] == -1) {
						board[i][j + 3] = 3;
					}
					if (board[i][j - 1] == -1) {
						board[i][j - 1] = 3;
					}
				}
			}

			if (board[j][i] == 2 && board[j + 1][i] == 2 && board[j + 2][i] == 2) {      //세로줄 검사
				if (board[j + 3][i] == 2 && board[j + 4][i] == -1) {
					board[j + 4][i] = 3;
				}
				else {
					if (board[j + 3][i] == -1) {
						board[j + 3][i] = 3;
					}
					if (board[j - 1][i] == -1) {
						board[j - 1][i] = 3;
					}
				}
			}

			if (board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 2) {      //왼 대각선 검사
				if (board[i + 3][j + 3] == 2 && board[i + 4][j + 4] == -1) {
					board[i + 4][j + 4] = 3;
				}
				else {
					if (board[i + 3][j + 3] == -1) {
						board[i + 3][j + 3] = 3;
					}
					if (board[i - 1][j - 1] == -1 && i - 1 >= 0 && j - 1 >= 0) {
						board[i - 1][j - 1] = 3;
					}
				}
			}

			if (board[i][j] == 2 && board[i - 1][j + 1] == 2 && board[i - 2][j + 2] == 2 && i - 2 >= 0 && j + 2 <= 19) {      //오른 대각선 검사
				if (board[i - 3][j + 3] == 2 && board[i - 4][j + 4] == -1 && i - 4 >= 0 && j + 4 <= 19) {
					board[i - 4][j + 4] = 3;
				}
				else {
					if (board[i - 3][j + 3] == -1 && i >= 3 && j <= 16) {
						board[i - 3][j + 3] = 3;
					}
					if (board[i + 1][j - 1] == -1 && i + 1 <= 19 && j - 1 >= 0) {
						board[i + 1][j - 1] = 3;
					}
				}
			}

		}
	}

}

void TicTacToe::check() const
{
	for (int i = 0; i < Height; ++i) {
		for (int j = 0; j < Width; ++j) {
			if (board[i][j] == 1 && board[i][j + 1] == 1 && board[i][j + 2] == 1 && board[i][j + 3] == 1 && board[i][j + 4] == 1) {
				cout << "검은돌 승리!" << endl;
				exit(0);
			}
			else if (board[j][i] == 1 && board[j + 1][i] == 1 && board[j + 2][i] == 1 && board[j + 3][i] == 1 && board[j + 4][i] == 1) {
				cout << "검은돌 승리!" << endl;
				exit(0);
			}
			else if (board[i][j] == 1 && board[i + 1][j + 1] == 1 && board[i + 2][j + 2] == 1 && board[i + 3][j + 3] == 1 && board[i + 4][j + 4] == 1) {
				cout << "검은돌 승리!" << endl;
				exit(0);
			}
			else if (board[i][j] == 1 && board[i - 1][j + 1] == 1 && board[i - 2][j + 2] == 1 && board[i - 3][j + 3] == 1 && board[i - 4][j + 4] == 1) {
				cout << "검은돌 승리!" << endl;
				exit(0);
			}

			if (board[i][j] == 2 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 2 && board[i][j + 4] == 2) {
				cout << "흰돌 승리!" << endl;
				exit(0);
			}
			else if (board[j][i] == 2 && board[j + 1][i] == 2 && board[j + 2][i] == 2 && board[j + 3][i] == 2 && board[j + 4][i] == 2) {
				cout << "흰돌 승리!" << endl;
				exit(0);
			}
			else if (board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 2 && board[i + 4][j + 4] == 2) {
				cout << "흰돌 승리!" << endl;
				exit(0);
			}
			else if (board[i][j] == 2 && board[i - 1][j + 1] == 2 && board[i - 2][j + 2] == 2 && board[i - 3][j + 3] == 2 && board[i - 4][j + 4] == 2) {
				cout << "흰돌 승리!" << endl;
				exit(0);
			}
		}
	}
}

void TicTacToe::draw() const
{
	system("cls");
	cout << "1 2 3 4 5...." << endl;
	for (int i = 0; i < Height; ++i) {
		for (int j = 0; j < Width; ++j) {
			if (board[i][j] == -1) {
				cout << "□";
			}
			else if (board[i][j] == 1) {
				cout << "○";
			}
			else if (board[i][j] == 2) {
				cout << "●";
			}
			else if (board[i][j] == 3) {
				cout << "★";
			}
		}
		cout << endl;
	}
	cout << "명령어" << endl << "A : 계속해서 둔다." << endl << "U : 무른다." << endl << "R : 무르기를 취소한다." << endl << "S : 저장한다." << endl <<
		"L : 불러온다." << endl << "Q : 종료" << endl;
}

int main()
{
	int turn = 1;
	int count = 0;
	char input;
	TicTacToe game;
	game.draw();
	while (1)
	{
		cin >> input;
		switch (input)
		{
		case 'A':
		case 'a':
		{
			if (turn % 2 == 1) {
				game.setB();
				game.isWarn();
				game.draw();
				game.findMax();
				turn++;
				count++;

			}
			else if (turn % 2 == 0) {
				game.setW();
				game.isWarn();
				game.draw();
				game.findMax();
				turn++;
				count++;
			}
			game.check();
			break;
		}
		case 'S':
		case 's':
		{
			ofstream out_turn("turn.txt");
			if (out_turn.is_open()) {
				out_turn << turn;
			}
			out_turn.close();
			game.Save_Board();
			game.draw();
			game.findMax();
			break;
		}
		case 'L':
		case 'l':
		{
			ifstream in_turn("turn.txt");
			if (in_turn.is_open()) {
				in_turn >> turn;
			}
			in_turn.close();
			game.Load_Board();
			game.draw();
			game.findMax();

			break;
		}
		case 'U':
		case 'u':
		{
			game.Ripen();
			if (isTrue) {
				turn--;
				isTrue = false;
			}
			game.isWarn();
			game.draw();
			game.findMax();

			break;
		}
		case 'R':
		case 'r':
		{
			game.Cancel(turn);
			if (isTrue) {
				turn++;
				isTrue = false;
			}
			game.isWarn();
			game.draw();
			game.findMax();

			break;
		}
		case 'Q':
		case 'q':
		{
			exit(0);

			break;
		}
		default:
			cout << "제대로된 명령을 입력해주세요." << endl;
			break;
		}
	}
}