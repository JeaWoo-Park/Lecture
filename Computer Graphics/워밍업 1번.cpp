#include <iostream>
#include <random>

int main() {
	std::random_device rd;
	std::default_random_engine dre(rd());
	std::uniform_int_distribution<> uid(0, 1);

	int A1[3][3];
	int A2[3][3];
	int B[4][4];
	
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			A1[i][j] = uid(dre);
			A2[i][j] = uid(dre);
			B[i][j] = A1[i][j];
		}
	}
	
	B[3][0] = 0;
	B[3][1] = 0;
	B[3][2] = 0;
	B[3][3] = 1;
	B[0][3] = 0;
	B[1][3] = 0;
	B[2][3] = 0;
	int a = A1[0][0] * A1[1][1] * A1[2][2] + A1[0][1] * A1[1][2] * A1[2][0] + A1[0][2] * A1[1][0] * A1[2][1] - A1[0][2] * A1[1][1] * A1[2][0] - A1[0][0] * A1[1][2] * A1[2][1] - A1[0][1] * A1[1][0] * A1[2][2];
	
	for (int i = 0; i < 3; ++i) {
		std::cout << '|' << A1[i][0] << ' ' << A1[i][1] << ' ' << A1[i][2] << '|' << '\t' << '|' << A2[i][0] << ' ' << A2[i][1] << ' ' << A2[i][2] << '|' << std::endl;
	}
	char work;
	while (true) {
	Back:
		std::cout << "명령어 : ";
		std::cin >> work;
		if (std::cin.fail()) {
			std::cout << "잘못된 입력" << std::endl;
			std::cin.clear();
			std::cin.ignore();
			goto Back;
		}
		switch (work)
		{
		case 'M':
		case'm':
			for (int i = 0; i < 3; ++i) {
				std::cout << '|' << A1[i][0] << ' ' << A1[i][1] << ' ' << A1[i][2] << '|'; 
				if (i == 1) {
					std::cout << "*";
				}
				else {
					std::cout << "\t";
				}
				std::cout << '|' << A2[i][0] << ' ' << A2[i][1] << ' ' << A2[i][2] << '|';
				if (i == 1) {
					std::cout << "=";
				}
				else {
					std::cout << "\t";
				}
				std::cout << '|' << A1[i][0] * A2[0][0] + A1[i][1] * A2[1][0] + A1[i][2] * A2[2][0] << ' ' << A1[i][0] * A2[0][1] + A1[i][1] * A2[1][1] + A1[i][2] * A2[1][2] << ' ' << A1[i][0] * A2[0][2] + A1[i][1] * A2[2][1] + A1[i][2] * A2[2][2] << '|' << std::endl;
			}
		break;
		case 'A':
		case'a':
			for (int i = 0; i < 3; ++i) {
				std::cout << '|' << A1[i][0] << ' ' << A1[i][1] << ' ' << A1[i][2] << '|';
				if (i == 1) {
					std::cout << "+";
				}
				else {
					std::cout << "\t";
				}
				std::cout << '|' << A2[i][0] << ' ' << A2[i][1] << ' ' << A2[i][2] << '|';
				if (i == 1) {
					std::cout << "=";
				}
				else {
					std::cout << "\t";
				}
				std::cout << '|' << A1[i][0] + A2[i][0] << ' ' << A1[i][1] + A2[i][1] << ' ' << A1[i][2] + A2[i][2] << '|' << std::endl;
			}
			break;
		case 'D':
		case'd':
			for (int i = 0; i < 3; ++i) {
				std::cout << '|' << A1[i][0] << ' ' << A1[i][1] << ' ' << A1[i][2] << '|';
				if (i == 1) {
					std::cout << "-";
				}
				else {
					std::cout << "\t";
				}
				std::cout << '|' << A2[i][0] << ' ' << A2[i][1] << ' ' << A2[i][2] << '|';
				if (i == 1) {
					std::cout << "=";
				}
				else {
					std::cout << "\t";
				}
				std::cout << '|' << A1[i][0] - A2[i][0] << ' ' << A1[i][1] - A2[i][1] << ' ' << A1[i][2] - A2[i][2] << '|' << std::endl;
			}
			break;
		case 'R':
		case'r':
			for (int i = 0; i < 3; ++i) {
				std::cout << '|' << A1[i][0] << ' ' << A1[i][1] << ' ' << A1[i][2] << '|';
				if (i == 1) {
					std::cout << " = " << a << std::endl;
				}
				else {
					std::cout << "\t" << std::endl;
				}
			}
			break;
		case 'H':
		case'h':
			for (int i = 0; i < 3; ++i) {
				std::cout << '|' << A1[i][0] << ' ' << A1[i][1] << ' ' << A1[i][2] << '|';
				if (i == 1) {
					std::cout << "->";
				}
				else {
					std::cout << "  ";
				}
				std::cout << '|' << B[i][0] << ' ' << B[i][1] << ' ' << B[i][2] << ' ' <<  B[i][3];
				if (i == 1) {
					std::cout << "| = " << a * -1 << std::endl;
				}
				else {
					std::cout << "|" << std::endl;
				}
			}
			std::cout << "         " << '|' << B[3][0] << ' ' << B[3][1] << ' ' << B[3][2] << ' ' << B[3][3] << '|' << std::endl;
			break;
		case 'Q':
		case'q':
			std::cout << "종료합니다." << std::endl;
			return 0;
			break;
		default:
			std::cout << "잘못된 입력" << std::endl;
			std::cin.clear();
			std::cin.ignore();
			goto Back;
			break;
		}


	}
}