#include <iostream>
#include <math.h>

struct Point {
	int x;
	int y;
	int z;
	int data = 0;
};



int main() {
	Point i[10];
	int top = -1;
	char sel;
	int x, y, z;
	int len;
	int max = 0;
	int min,index;
	bool full = false;
	Point p;
	while (true)
	{
	Back:
		std::cout << "명령어 : ";
		std::cin >> sel;
		if (std::cin.fail()) {
			std::cout << "잘못된 입력 입니다." << std::endl;
			std::cin.ignore();
			std::cin.clear();
			goto Back;
		}
		switch (sel)
		{
		case'-':
			if (top < 0) {
				std::cout << "비었습니다." << std::endl;
				break;
			}
			for (int n = 9; n >= 0; --n) {
				if (i[n].data == 1) {
					i[n].data = 0;
					i[n].x = NULL;
					i[n].y = NULL;
					i[n].z = NULL;
					--top;
					break;

				}
			}
			for (int n = 9; n >= 0; --n) {
				if (i[n].data == 0) {
					std::cout << n << std::endl;
				}
				else {
					std::cout << n << ' ' << i[n].x << ' ' << i[n].y << ' ' << i[n].z << std::endl;
				}
			}
			break;
		case'+':
			for (int n = 0; n < 10; ++n) {
				if (i[n].data != 1) {
					full = false;
					break;
				}
				else {
					full = true;
				}
			}
			if (full) {
				std::cout << "꽉 찼습니다." << std::endl;
				break;
			}
			std::cout << "x : ";
			std::cin >> x;
			if (std::cin.fail()) {
				std::cout << "잘못된 입력 입니다." << std::endl;
				break;
			}
			std::cout << "y : ";
			std::cin >> y;
			if (std::cin.fail()) {
				std::cout << "잘못된 입력 입니다." << std::endl;
				break;
			}
			std::cout << "z : ";
			std::cin >> z;
			if (std::cin.fail()) {
				std::cout << "잘못된 입력 입니다." << std::endl;
				break;
			}
			if (top < 0) {
				i[0].x = x;
				i[0].y = y;
				i[0].z = z;
				i[0].data = 1;
				top = 0;
			}
			else if (i[9].data==1) {
				for (int n = 0; n < 10; ++n) {
					if (i[n].data != 1) {
						i[n].x = x;
						i[n].y = y;
						i[n].z = z;
						i[n].data = 1;
						break;
					}
				}
			}
			else {
				i[top + 1].x = x;
				i[top + 1].y = y;
				i[top + 1].z = z;
				i[top + 1].data = 1;
				top++;
			}
			for (int n = 9; n >= 0; --n) {
				if (i[n].data == 0) {
					std::cout << n << std::endl;
				}
				else {
					std::cout << n << ' ' << i[n].x << ' ' << i[n].y << ' ' << i[n].z << std::endl;
				}
			}
			break;
		case 'e':
			for (int n = 0; n < 10; ++n) {
				if (i[n].data != 1) {
					full = false;
					break;
				}
				else {
					full = true;
				}
			}
			std::cout << "x : ";
			std::cin >> x;
			if (std::cin.fail()) {
				std::cout << "잘못된 입력 입니다." << std::endl;
				break;
			}
			std::cout << "y : ";
			std::cin >> y;
			if (std::cin.fail()) {
				std::cout << "잘못된 입력 입니다." << std::endl;
				break;
			}
			std::cout << "z : ";
			std::cin >> z;
			if (std::cin.fail()) {
				std::cout << "잘못된 입력 입니다." << std::endl;
				break;
			}
			if (top < 0) {
				i[0].data = 1;
				i[0].x = x;
				i[0].y = y;
				i[0].z = z;
				top = 0;
				for (int n = 9; n >= 0; --n) {
					if (i[n].data == 0) {
						std::cout << n << std::endl;
					}
					else {
						std::cout << n << ' ' << i[n].x << ' ' << i[n].y << ' ' << i[n].z << std::endl;
					}
				}
				break;
			}
			if (i[0].data != 1) {
				for (int n = 0; n <= top; ++n) {
					if (i[n].data == 1) {
						i[n - 1].data = 1;
						i[n - 1].x = x;
						i[n - 1].y = y;
						i[n - 1].z = z;
						break;
					}
				}
			}
			else {
				for (int n = 9; n >= 0; --n) {
					if (i[n].data != 1) {
						continue;
					}
					else if (i[n].data == 1) {
						i[n + 1].data = 1;
						i[n + 1].x = i[n].x;
						i[n + 1].y = i[n].y;
						i[n + 1].z = i[n].z;
						i[n].data = 0;
						i[n].x = NULL;
						i[n].y = NULL;
						i[n].z = NULL;
					}
				}
				i[0].data = 1;
				i[0].x = x;
				i[0].y = y;
				i[0].z = z;
				++top;
			}
			for (int n = 9; n >= 0; --n) {
				if (i[n].data == 0) {
					std::cout << n << std::endl;
				}
				else {
					std::cout << n << ' ' << i[n].x << ' ' << i[n].y << ' ' << i[n].z << std::endl;
				}
			}
			break;
		case 'd':
			for (int n = 0; n < 10; ++n) {
				if (i[n].data == 1) {
					i[n].data = 0;
					i[n].x = NULL;
					i[n].y = NULL;
					i[n].z = NULL;
					break;
				}
			}
			for (int n = 9; n >= 0; --n) {
				if (i[n].data == 0) {
					std::cout << n << std::endl;
				}
				else {
					std::cout << n << ' ' << i[n].x << ' ' << i[n].y << ' ' << i[n].z << std::endl;
				}
			}
			break;
		case 'l':
			len = 0;
			for (int n = 0; n < 10; ++n) {
				if (i[n].data == 1) {
					++len;
				}
			}
			std::cout << len << std::endl;
			std::cout << std::endl;
			for (int n = 9; n >= 0; --n) {
				if (i[n].data == 0) {
					std::cout << n << std::endl;
				}
				else {
					std::cout << n << ' ' << i[n].x << ' ' << i[n].y << ' ' << i[n].z << std::endl;
				}
			}
			break;
		case 'c':
			for (int n = 0; n < 10; ++n) {
				i[n].x = NULL;
				i[n].y = NULL;
				i[n].z = NULL;
				i[n].data = 0;
				top = -1;
			}
			for (int n = 9; n >= 0; --n) {
				if (i[n].data == 0) {
					std::cout << n << std::endl;
				}
				else {
					std::cout << n << ' ' << i[n].x << ' ' << i[n].y << ' ' << i[n].z << std::endl;
				}
			}
			break;
		case 'm':
			for (int n = 0; n < 10; ++n) {
				if (i[n].data != 1) {
					continue;
				}
				if (sqrt(i[n].x * i[n].x + i[n].y * i[n].y + i[n].z * i[n].z) > max) {
					max = sqrt(i[n].x * i[n].x + i[n].y * i[n].y + i[n].z * i[n].z);
					p = i[n];
					index = n;
				}
			}
			std::cout << index << ' ' << p.x << ' ' << p.y << ' ' << p.z << std::endl;
			std::cout << std::endl;
			for (int n = 9; n >= 0; --n) {
				if (i[n].data == 0) {
					std::cout << n << std::endl;
				}
				else {
					std::cout << n << ' ' << i[n].x << ' ' << i[n].y << ' ' << i[n].z << std::endl;
				}
			}
			break;
		case'n':
		
			min = sqrt(i[0].x * i[0].x + i[0].y * i[0].y + i[0].z * i[0].z);
			for (int n = 0; n < 10; ++n) {
				if (i[n].data != 1) {
					continue;
				}
				if (sqrt(i[n].x * i[n].x + i[n].y * i[n].y + i[n].z * i[n].z) < min) {
					min = sqrt(i[n].x * i[n].x + i[n].y * i[n].y + i[n].z * i[n].z);
					p = i[n];
					index = n;
				}
			}
			std::cout << index << ' ' << p.x << ' ' << p.y << ' ' << p.z << std::endl;
			std::cout << std::endl;
			for (int n = 9; n >= 0; --n) {
				if (i[n].data == 0) {
					std::cout << n << std::endl;
				}
				else {
					std::cout << n << ' ' << i[n].x << ' ' << i[n].y << ' ' << i[n].z << std::endl;
				}
			}
			break;
		case'q':
			return 0;
			break;
		default:
			std::cout << "잘못된 입력 입니다." << std::endl;
			break;
		}
	}
}