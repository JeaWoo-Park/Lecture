#include <iostream>
#include <random>
#include <math.h>

struct Shape {
	int x1, x2, y1, y2;
};

int main() {
	int temp;
	std::random_device rd;
	std::default_random_engine dre(rd());
	std::uniform_int_distribution<> uid(0, 500);
	Shape A, B;
	A.x1 = uid(dre);
	A.x2 = uid(dre);
	A.y1 = uid(dre);
	A.y2 = uid(dre);
	B.x1 = uid(dre);
	B.x2 = uid(dre);
	B.y1 = uid(dre);
	B.y2 = uid(dre);
	if (A.x1 > A.x2) {
		temp = A.x1;
		A.x1 = A.x2;
		A.x2 = temp;
	}
	if (A.y1 > A.y2) {
		temp = A.y1;
		A.y1 = A.y2;
		A.y2 = temp;
	}
	if (B.x1 > B.x2) {
		temp = B.x1;
		B.x1 = B.x2;
		B.x2 = temp;
	}
	if (B.y1 > B.y2) {
		temp = B.y1;
		B.y1 = B.y2;
		B.y2 = temp;
	}
	int dia = B.x2 - B.x1;
	int dia_x = B.x1 + dia / 2;
	int dia_y = B.y1 + dia / 2;
	B.y2 = B.y1 + dia;
	int center_top_x, center_top_y, center_bottom_x, center_bottom_y, center_left_x, center_left_y, center_right_x, center_right_y;
	center_top_x = center_bottom_x = dia_x;
	center_top_y = B.y1;
	center_bottom_y = B.y2;
	center_left_y = center_right_y = dia_y;
	center_left_x = B.x1;
	center_right_x = B.x2;
	char sel;
	int shape;
Back:
	std::cout << "형태 1,2(1:사각 사각 2:사각 원) : ";
	std::cin >> shape;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore();
		std::cout << "잘못된 입력 입니다." << std::endl;
		goto Back;
	}
	if (shape != 1 && shape != 2) {
		std::cout << "잘못된 입력 입니다." << std::endl;
		goto Back;
	}
	std::cout << "Shape 1 : (" << A.x1 << ',' << A.y1 << "),(" << A.x2 << "," << A.y2 << ')' << std::endl;
	std::cout << "Shape 2 : (" << B.x1 << ',' << B.y1 << "),(" << B.x2 << "," << B.y2 << ')' << std::endl;
	while (1) {
	re:
		std::cout << "명령어 : ";
		std::cin >> sel;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "잘못된 입력 입니다." << std::endl;
			goto re;
		}
		switch (sel)
		{
		case 'a':
			B.x1 = B.x1 - 40;
			B.x2 = B.x2 - 40;
			dia_x -= 40;
			center_bottom_x -= 40;
			center_left_x -= 40;
			center_right_x -= 40;
			center_top_x -= 40;
			std::cout << "Shape 1 : (" << A.x1 << ',' << A.y1 << "),(" << A.x2 << "," << A.y2 << ')' << std::endl;
			std::cout << "Shape 2 : (" << B.x1 << ',' << B.y1 << "),(" << B.x2 << "," << B.y2 << ')' << std::endl;

			if (shape == 1) {
				if (B.x1 >= A.x1 && B.x1 <=A.x2 && B.y1>=A.y1 && B.y1 <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if (B.x1 >= A.x1 && B.x1 <= A.x2 && B.y2>=A.y1 && B.y2 <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if (B.x2 >= A.x1 && B.x2 <= A.x2 && B.y1>=A.y1 && B.y1 <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if (B.x2 >= A.x1 && B.x2 <= A.x2 && B.y2>=A.y1 && B.y2 <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}

			}
			if (shape == 2) {
				if ((A.x1 - dia_x) * (A.x1 - dia_x) + (A.y1 - dia_y) * (A.y1 - dia_y) < (dia / 2) * (dia / 2)) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if ((A.x2 - dia_x) * (A.x2 - dia_x) + (A.y1 - dia_y) * (A.y1 - dia_y) < (dia / 2) * (dia / 2)) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if ((A.x1 - dia_x) * (A.x1 - dia_x) + (A.y2 - dia_y) * (A.y2 - dia_y) < (dia / 2) * (dia / 2)) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if ((A.x2 - dia_x) * (A.x2 - dia_x) + (A.y2 - dia_y) * (A.y2 - dia_y) < (dia / 2) * (dia / 2)) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if (dia_x >= A.x1 && dia_x <= A.x2 && dia_y >= A.y1 && dia_y <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if (center_bottom_x >= A.x1 && center_bottom_x <= A.x2 && center_bottom_y >= A.y1 && center_bottom_y <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if (center_top_x >= A.x1 && center_top_x <= A.x2 && center_top_y >= A.y1 && center_top_y <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if (center_left_x >= A.x1 && center_left_x <= A.x2 && center_left_y >= A.y1 && center_left_y <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if (center_right_x >= A.x1 && center_right_x <= A.x2 && center_right_y >= A.y1 && center_right_y <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}
			}
			break;
		case 's':
			B.y1 = B.y1 + 40;
			B.y2 = B.y2 + 40;
			dia_y += 40;
			center_bottom_y += 40;
			center_left_y += 40;
			center_right_y += 40;
			center_top_y += 40;
			std::cout << "Shape 1 : (" << A.x1 << ',' << A.y1 << "),(" << A.x2 << "," << A.y2 << ')' << std::endl;
			std::cout << "Shape 2 : (" << B.x1 << ',' << B.y1 << "),(" << B.x2 << "," << B.y2 << ')' << std::endl;

			if (shape == 1) {
				if (B.x1 >= A.x1 && B.x1 <= A.x2 && B.y1 >= A.y1 && B.y1 <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if (B.x1 >= A.x1 && B.x1 <= A.x2 && B.y2 >= A.y1 && B.y2 <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if (B.x2 >= A.x1 && B.x2 <= A.x2 && B.y1 >= A.y1 && B.y1 <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if (B.x2 >= A.x1 && B.x2 <= A.x2 && B.y2 >= A.y1 && B.y2 <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}

			}
			if (shape == 2) {
				if ((A.x1 - dia_x) * (A.x1 - dia_x) + (A.y1 - dia_y) * (A.y1 - dia_y) < (dia / 2) * (dia / 2)) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if ((A.x2 - dia_x) * (A.x2 - dia_x) + (A.y1 - dia_y) * (A.y1 - dia_y) < (dia / 2) * (dia / 2)) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if ((A.x1 - dia_x) * (A.x1 - dia_x) + (A.y2 - dia_y) * (A.y2 - dia_y) < (dia / 2) * (dia / 2)) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if ((A.x2 - dia_x) * (A.x2 - dia_x) + (A.y2 - dia_y) * (A.y2 - dia_y) < (dia / 2) * (dia / 2)) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if (dia_x >= A.x1 && dia_x <= A.x2 && dia_y >= A.y1 && dia_y <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if (center_bottom_x >= A.x1 && center_bottom_x <= A.x2 && center_bottom_y >= A.y1 && center_bottom_y <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if (center_top_x >= A.x1 && center_top_x <= A.x2 && center_top_y >= A.y1 && center_top_y <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if (center_left_x >= A.x1 && center_left_x <= A.x2 && center_left_y >= A.y1 && center_left_y <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if (center_right_x >= A.x1 && center_right_x <= A.x2 && center_right_y >= A.y1 && center_right_y <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}
			}
			break;
		case 'd':
			B.x1 = B.x1 + 40;
			B.x2 = B.x2 + 40;
			dia_x += 40;
			center_bottom_x += 40;
			center_left_x += 40;
			center_right_x += 40;
			center_top_x += 40;
			std::cout << "Shape 1 : (" << A.x1 << ',' << A.y1 << "),(" << A.x2 << "," << A.y2 << ')' << std::endl;
			std::cout << "Shape 2 : (" << B.x1 << ',' << B.y1 << "),(" << B.x2 << "," << B.y2 << ')' << std::endl;
			if (shape == 1) {
				if (B.x1 >= A.x1 && B.x1 <= A.x2 && B.y1 >= A.y1 && B.y1 <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if (B.x1 >= A.x1 && B.x1 <= A.x2 && B.y2 >= A.y1 && B.y2 <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if (B.x2 >= A.x1 && B.x2 <= A.x2 && B.y1 >= A.y1 && B.y1 <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if (B.x2 >= A.x1 && B.x2 <= A.x2 && B.y2 >= A.y1 && B.y2 <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}

			}
			if (shape == 2) {
				if ((A.x1 - dia_x) * (A.x1 - dia_x) + (A.y1 - dia_y) * (A.y1 - dia_y) < (dia / 2) * (dia / 2)) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if ((A.x2 - dia_x) * (A.x2 - dia_x) + (A.y1 - dia_y) * (A.y1 - dia_y) < (dia / 2) * (dia / 2)) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if ((A.x1 - dia_x) * (A.x1 - dia_x) + (A.y2 - dia_y) * (A.y2 - dia_y) < (dia / 2) * (dia / 2)) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if ((A.x2 - dia_x) * (A.x2 - dia_x) + (A.y2 - dia_y) * (A.y2 - dia_y) < (dia / 2) * (dia / 2)) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if (dia_x >= A.x1 && dia_x <= A.x2 && dia_y >= A.y1 && dia_y <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if (center_bottom_x >= A.x1 && center_bottom_x <= A.x2 && center_bottom_y >= A.y1 && center_bottom_y <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if (center_top_x >= A.x1 && center_top_x <= A.x2 && center_top_y >= A.y1 && center_top_y <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if (center_left_x >= A.x1 && center_left_x <= A.x2 && center_left_y >= A.y1 && center_left_y <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if (center_right_x >= A.x1 && center_right_x <= A.x2 && center_right_y >= A.y1 && center_right_y <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}
			}
			break;
		case 'w':
			B.y1 = B.y1 - 40;
			B.y2 = B.y2 - 40;
			dia_y -= 40;
			center_bottom_y -= 40;
			center_left_y -= 40;
			center_right_y -= 40;
			center_top_y -= 40;
			std::cout << "Shape 1 : (" << A.x1 << ',' << A.y1 << "),(" << A.x2 << "," << A.y2 << ')' << std::endl;
			std::cout << "Shape 2 : (" << B.x1 << ',' << B.y1 << "),(" << B.x2 << "," << B.y2 << ')' << std::endl;
			if (shape == 1) {
				if (B.x1 >= A.x1 && B.x1 <= A.x2 && B.y1 >= A.y1 && B.y1 <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if (B.x1 >= A.x1 && B.x1 <= A.x2 && B.y2 >= A.y1 && B.y2 <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if (B.x2 >= A.x1 && B.x2 <= A.x2 && B.y1 >= A.y1 && B.y1 <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if (B.x2 >= A.x1 && B.x2 <= A.x2 && B.y2 >= A.y1 && B.y2 <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}

			}
			if (shape == 2) {
				if ((A.x1 - dia_x) * (A.x1 - dia_x) + (A.y1 - dia_y) * (A.y1 - dia_y) < (dia / 2) * (dia / 2)) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if ((A.x2 - dia_x) * (A.x2 - dia_x) + (A.y1 - dia_y) * (A.y1 - dia_y) < (dia / 2) * (dia / 2)) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if ((A.x1 - dia_x) * (A.x1 - dia_x) + (A.y2 - dia_y) * (A.y2 - dia_y) < (dia / 2) * (dia / 2)) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if ((A.x2 - dia_x) * (A.x2 - dia_x) + (A.y2 - dia_y) * (A.y2 - dia_y) < (dia / 2) * (dia / 2)) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if (dia_x >= A.x1 && dia_x <= A.x2 && dia_y >= A.y1 && dia_y <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if (center_bottom_x >= A.x1 && center_bottom_x <= A.x2 && center_bottom_y >= A.y1 && center_bottom_y <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if (center_top_x >= A.x1 && center_top_x <= A.x2 && center_top_y >= A.y1 && center_top_y <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if (center_left_x >= A.x1 && center_left_x <= A.x2 && center_left_y >= A.y1 && center_left_y <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}
				if (center_right_x >= A.x1 && center_right_x <= A.x2 && center_right_y >= A.y1 && center_right_y <= A.y2) {
					std::cout << "충돌" << std::endl;
					break;
				}
			}
			break; 
		default:
			std::cout << "잘못된 입력 입니다." << std::endl;
			break;
		}
	}
}