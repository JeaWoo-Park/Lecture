#include <iostream>
#include <fstream>

class Stack
{
private:
	int x = NULL, y = NULL, color = 3;
public:
	void S_Push(int x,int y,int color) {
		Stack::x = x;
		Stack::y = y;
		Stack::color = color;
	}
	void U_Push(Stack& save) {
		Stack::x = save.x;
		Stack::y = save.y;
		Stack::color = save.color;
		save.Pop();
	}
	void Pop() {
		x = NULL;
		y = NULL;
		color = 3;
	}
	int getX() {
		return x;
	}

	int getY() {
		return y;
	}

	int getColor() {
		return color;
	}
};
class Stone
{
private:
	int color = 3;
	char stone = ' ';
public:
	char PrintStone() {
		return stone;
	}
	void SetStone(int x, int y, int color, Stack& save) {
		save.S_Push(x, y, color);
		Stone::color = color;
		if (Stone::color == 1) {
			stone = 'O';
		}
		else if (Stone::color == 2) {
			stone = 'X';
		}
		else if (Stone::color == 3) {
			stone = ' ';
		}

	}
	void UndoStone() {
		color = 3;
		stone = ' ';
	}
};

int main()
{
	Stone stone[20][20];
	Stack save[400], undo[400];
	int x, y,color;
	int blackcount = 0;
	int whitecount = 0;
	int s_sp = -1;
	int u_sp = -1;
	char selection;
	std::ofstream out;
	std::ifstream in;
	while (1) {
	Black:
		color = 1;
		system("cls");
		for (int i = 0; i < 20; ++i) {
			std::cout << "-----------------------------------------" << std::endl;
			for (int j = 0; j < 20; ++j) {
				std::cout << '|' << stone[i][j].PrintStone();
			}
			std::cout << '|' << std::endl;
		}

		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "흑돌 : " << blackcount << ", 백돌 : " << whitecount << std::endl;
		std::cout << "U : 무르기" << std::endl;
		std::cout << "R : 무르기 취소" << std::endl;
		std::cout << "S : 저장" << std::endl;
		std::cout << "L : 불러오기" << std::endl;
		std::cout << "C : 계속하기" << std::endl;
		std::cout << "Q : 종료" << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "입력 : ";
		std::cin >> selection;

		switch (selection)
		{
		case 'U':
			if (s_sp > -1) {
				++u_sp;
				undo[u_sp].U_Push(save[s_sp]);
				stone[undo[u_sp].getY() - 1][undo[u_sp].getX() - 1].UndoStone();
				--s_sp;
			}
			else {
				std::cout << "아무런 돌도 배치되어있지 않습니다." << std::endl;
				system("pause");
				goto Black;
			}
			break;
		case 'R':
			if (u_sp > -1) {
				++s_sp;
				stone[undo[u_sp].getY() - 1][undo[u_sp].getX() - 1].SetStone(undo[u_sp].getX(), undo[u_sp].getY(), undo[u_sp].getColor(), save[s_sp]);
				undo[u_sp].Pop();
				--u_sp;
			}
			else {
				std::cout << "마지막 수 입니다." << std::endl;
				system("pause");
				goto Black;
			}
			break;
		case 'S':
			out.open("오목 저장.txt");
			for (int i = 0; i <= s_sp; ++i) {
				out << save[i].getX() << ' ' << save[i].getY() << ' ' << save[i].getColor() << '\n';
			}
			out.close();
			break;
		case 'L':
			s_sp = -1;
			for (int i = 0; i < 20; ++i) {
				for (int j = 0; j < 20; ++j) {
					stone[i][j].UndoStone();
				}
			}
			in.open("오목 저장.txt");
			while (1) {
				in >> x >> y >> color;
				++s_sp;
				stone[y - 1][x - 1].SetStone(x, y, color, save[s_sp]);
				if (in.get() == EOF) {
					break;
				}
			}
			in.close();
			if (save[s_sp].getColor() == 1) {
				in.close();
				goto White;
			}
			else if (save[s_sp].getColor() == 2) {
				in.close();
				goto Black;
			}
		
			break;
		case 'C':
			std::cout << "흑돌 x좌표 : ";
			std::cin >> x;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(10, '\n');
				std::cout << "숫자를 입력해 주세요..." << std::endl;
				system("puase");
				goto Black;
			}
			std::cout << "흑돌 y좌표 : ";
			std::cin >> y;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(10, '\n');
				std::cout << "숫자를 입력해 주세요..." << std::endl;
				system("puase");
				goto Black;
			}
			if (x < 1 || x > 20 || y < 1 || y > 20) {
				std::cout << "1부터 20 사이의 숫자를입력해 주세요..." << std::endl;
				system("puase");
				goto Black;
			}
			if (stone[y - 1][x - 1].PrintStone() == 'O' || stone[y - 1][x - 1].PrintStone() == 'X') {
				std::cout << "이미 배치되어 있습니다. 다른곳을 선택해 주세요..." << std::endl;
				system("puase");
				goto Black;
			}
			s_sp++;
			stone[y-1][x-1].SetStone(x, y, color, save[s_sp]);
			u_sp = -1;
			++blackcount;
			break;

		case 'Q':
			goto End;
		default:
			std::cout << "입력 오류" << std::endl;
			system("pause");
			goto Black;
			break;
		}
	White:
		color = 2;
		system("cls");
		for (int i = 0; i < 20; ++i) {
			std::cout << "-----------------------------------------" << std::endl;
			for (int j = 0; j < 20; ++j) {
				std::cout << '|' << stone[i][j].PrintStone();
			}
			std::cout << '|' << std::endl;
		}

		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "흑돌 : " << blackcount << ", 백돌 : " << whitecount << std::endl;
		std::cout << "U : 무르기" << std::endl;
		std::cout << "R : 무르기 취소" << std::endl;
		std::cout << "S : 저장" << std::endl;
		std::cout << "L : 불러오기" << std::endl;
		std::cout << "C : 계속하기" << std::endl;
		std::cout << "Q : 종료" << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "입력 : ";
		std::cin >> selection;

		switch (selection)
		{
		case 'U':
			if (s_sp > -1) {
				++u_sp;
				undo[u_sp].U_Push(save[s_sp]);
				stone[undo[u_sp].getY() - 1][undo[u_sp].getX() - 1].UndoStone();
				--s_sp;
			}
			else {
				std::cout << "아무런 돌도 배치되어있지 않습니다." << std::endl;
				system("pause");
				goto White;
			}
			break;
		case 'R':
			if (u_sp > -1) {
				++s_sp;
				stone[undo[u_sp].getY() - 1][undo[u_sp].getX() - 1].SetStone(undo[u_sp].getX(), undo[u_sp].getY(), undo[u_sp].getColor(), save[s_sp]);
				undo[u_sp].Pop();
				--u_sp;
			}
			else {
				std::cout << "마지막 수 입니다." << std::endl;
				system("pause");
				goto Black;
			}
			break;
		case 'S':
			out.open("오목 저장.txt");
			for (int i = 0; i <= s_sp; ++i) {
				out << save[i].getX() << ' ' << save[i].getY() << ' ' << save[i].getColor() << '\n';
			}
			out.close();
			break;
		case 'L':
			s_sp = -1;
			for (int i = 0; i < 20; ++i) {
				for (int j = 0; j < 20; ++j) {
					stone[i][j].UndoStone();
				}
			}
			in.open("오목 저장.txt");
			while (1) {
				in >> x >> y >> color;
				s_sp++;
				stone[y - 1][x - 1].SetStone(x, y, color, save[s_sp]);
				if (in.get() == EOF) {
					break;
				}
			}
			in.close();
			if (save[s_sp].getColor() == 1) {
				in.close();
				goto White;
			}
			else if (save[s_sp].getColor() == 2) {
				in.close();
				goto Black;
			}
			break;
		case 'C':
			std::cout << "백돌 x좌표 : ";
			std::cin >> x;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(10, '\n');
				std::cout << "숫자를 입력해 주세요..." << std::endl;
				system("puase");
				goto White;
			}
			std::cout << "백돌 y좌표 : ";
			std::cin >> y;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(10, '\n');
				std::cout << "숫자를 입력해 주세요..." << std::endl;
				system("puase");
				goto White;
			}
			if (x < 1 || x > 20 || y < 1 || y > 20) {
				std::cout << "1부터 20 사이의 숫자를입력해 주세요..." << std::endl;
				system("puase");
				goto White;
			}
			if (stone[y - 1][x - 1].PrintStone() == 'O' || stone[y - 1][x - 1].PrintStone() == 'X') {
				std::cout << "이미 배치되어 있습니다. 다른곳을 선택해 주세요..." << std::endl;
				system("puase");
				goto White;
			}
			s_sp++;
			stone[y - 1][x - 1].SetStone(x, y, color, save[s_sp]);
			u_sp = -1;
			++blackcount;
			break;

		case 'Q':
			goto End;
		default:
			std::cout << "입력 오류" << std::endl;
			system("pause");
			goto White;
			break;
		}


		//흑돌 끝

	}
End:
	std::cout << "종료" << std::endl;
}