#include <iostream>
#include <fstream>


class Stack
{
private:
	int x = NULL, y = NULL, color = 3;
public:
	void SPush(int x, int y, int color) {
		Stack::x = x;
		Stack::y = y;
		Stack::color = color;
	}
	void UPush(Stack& save) {
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
	int color = 3;	//1 B 2 W 3 N
	int x = NULL, y = NULL;
	char stone = ' ';
public:
	char PrintStone() {
		return stone;
	}
	void SetStone(int x, int y , int color,Stack& save) {
		Stone::color = color;
		Stone::x = x;
		Stone::y = y;
		if (Stone::color == 1) {
			stone = 'o';
		}
		else if (Stone::color == 2) {
			stone = 'x';
		}
		else if (Stone::color == 3) {
			stone = ' ';
		}
		save.SPush(x, y, color);
	}
	void UndoStone() {
		Stone::color = 3;
		Stone::x = NULL;
		Stone::y = NULL;
		Stone::stone = ' ';
	}
};



int main() {
	char selection;
	int x, y;
	int color = 1;
	int ssp = -1, usp = -1;
	Stack s_save[100], s_undo[100];

	Stone s[10][10];
	std::ofstream out;
	std::ifstream in;
	while (1) {
	L1:
		system("cls");
		color = 1;
		for (int i = 0; i < 10; ++i) {
			std::cout << "---------------------" << std::endl;
			for (int j = 0; j < 10; ++j) {
				std::cout << '|' << s[i][j].PrintStone();
			}
			std::cout << "|" << std::endl;
		}
		std::cout << "---------------------" << std::endl;
		std::cout << "U : ������" << std::endl;
		std::cout << "R : ������ ��� " << std::endl;
		std::cout << "S : ������� ����" << std::endl;
		std::cout << "L : �ҷ�����" << std::endl;
		std::cout << "C : ���� ����ϱ�" << std::endl;
		std::cout << "Q : �����ϱ�" << std::endl;
		std::cout << "---------------------" << std::endl;
	back1:
		std::cout << "�Է� : ";
		std::cin >> selection;
		if (std::cin.fail()) {
			std::cin.ignore('\n');
			std::cin.clear();
			std::cout << "�߸� �Է�" << std::endl;
			goto back1;
		}
		switch (selection)
		{
		case 'U':
			if (ssp > -1) {
				++usp;
				s_undo[usp].UPush(s_save[ssp]);
				s[s_undo[usp].getY() - 1][s_undo[usp].getX() - 1].UndoStone();
				--ssp;
			}
			else {
				std::cout << "�ƹ� ���� �÷��� ���� �ʽ��ϴ�." << std::endl;
				goto back1;
			}
			break;
		case 'R':
			if (usp > -1) {
				++ssp;
				s[s_undo[usp].getY() - 1][s_undo[usp].getX() - 1].SetStone(s_undo[usp].getX(), s_undo[usp].getY(), s_undo[usp].getColor(), s_save[ssp]);
				s_undo[usp].Pop();
				--usp;
			}
			else {
				std::cout << "������ �� �Դϴ�." << std::endl;
				goto back1;
			}
			break;
		case 'S':
			out.open("���� ����.txt");
			for (int i = 0; i <= ssp; ++i) {
				out << s_save[i].getX() << ' ' << s_save[i].getY() << ' ' << s_save[i].getColor() << '\n';
			}
			out.close();
			goto back1;
			break;
		case 'L':
			in.open("���� ����.txt");
			while (1)
			{
				in >> x >> y >> color;
				++ssp;
				s[y - 1][x - 1].SetStone(x, y, color, s_save[ssp]);
				if (in.get() == EOF) {
					break;
				}
			}
			if (color == 1) {
				in.close();
				goto L2;
			}
			else if (color == 2) {
				in.close();
				goto L1;
			}
			break;
		case 'C':
			std::cout << "�� ���� " << std::endl;
			std::cout << " x��ǥ : ";
			std::cin >> x;
			std::cout << "y��ǥ : ";
			std::cin >> y;
			++ssp;
			s[y - 1][x - 1].SetStone(x, y, color, s_save[ssp]);
			for (int i = 0; i <= usp; ++i) {
				s_undo[i].Pop();
			}
			usp = -1;
			break;
		case 'Q':
			std::cout << "����" << std::endl;
			goto end;
		default:
			std::cout << "�߸��� �Է�" << std::endl;
			goto back1;
			break;
		}
	L2:
		system("cls");
		color = 2;
		for (int i = 0; i < 10; ++i) {
			std::cout << "---------------------" << std::endl;
			for (int j = 0; j < 10; ++j) {
				std::cout << '|' << s[i][j].PrintStone();
			}
			std::cout << "|" << std::endl;
		}
		std::cout << "U : ������" << std::endl;
		std::cout << "R : ������ ��� " << std::endl;
		std::cout << "S : ������� ����" << std::endl;
		std::cout << "L : �ҷ�����" << std::endl;
		std::cout << "C : ���� ����ϱ�" << std::endl;
		std::cout << "Q : �����ϱ�" << std::endl;
		std::cout << "---------------------" << std::endl;
	back2:
		std::cout << "�Է� : ";
		std::cin >> selection;
		if (std::cin.fail()) {
			std::cin.ignore('\n');
			std::cin.clear();
			std::cout << "�߸� �Է�" << std::endl;
			goto back2;
		}
		switch (selection)
		{
		case 'U':
			if (ssp > -1) {
				++usp;
				s_undo[usp].UPush(s_save[ssp]);
				s[s_undo[usp].getY() - 1][s_undo[usp].getX() - 1].UndoStone();
				--ssp;
			}
			else {
				std::cout << "�ƹ� ���� �÷��� ���� �ʽ��ϴ�." << std::endl;
				goto back2;
			}
			break;
		case 'R':
			if (usp > -1) {
				++ssp;
				s[s_undo[usp].getY() - 1][s_undo[usp].getX() - 1].SetStone(s_undo[usp].getX(), s_undo[usp].getY(), s_undo[usp].getColor(), s_save[ssp]);
				s_undo[usp].Pop();
				--usp;
			}
			else {
				std::cout << "������ �� �Դϴ�." << std::endl;
				goto back2;
			}
			break;
		case 'S':
			out.open("���� ����.txt");
			for (int i = 0; i <= ssp; ++i) {
				out << s_save[i].getX() << ' ' << s_save[i].getY() << ' ' << s_save[i].getColor() << '\n';
			}
			out.close();
			goto back2;
			break;
		case 'L':
			in.open("���� ����.txt");
			while (1)
			{
				in >> x >> y >> color;
				++ssp;
				s[y - 1][x - 1].SetStone(x, y, color, s_save[ssp]);
				if (in.get() == EOF) {
					break;
				}
			}
			if (color == 1) {
				in.close();
				goto L2;
			}
			else if (color == 2) {
				in.close();
				goto L1;
			}
			break;
		case 'C':
			std::cout << "�� ���� " << std::endl;
			std::cout << " x��ǥ : ";
			std::cin >> x;
			std::cout << "y��ǥ : ";
			std::cin >> y;
			++ssp;
			s[y - 1][x - 1].SetStone(x, y, color, s_save[ssp]);
			for (int i = 0; i <= usp; ++i) {
				s_undo[i].Pop();
			}
			usp = -1;
			break;
		case 'Q':
			std::cout << "����" << std::endl;
			goto end;
		default:
			std::cout << "�߸��� �Է�" << std::endl;
			goto back2;
			break;
		}
	}
end:
	return 0;

}