#include <iostream>


struct SCNT
{
	int scnt = 0;
	int way;
};

struct POINT
{
	int x; int y;
};


POINT p[20];
POINT p1[20];
int print;
int way;
int index = 0;
int cnt = 0, max = 0, printmax = 0;
char stone[20][20]{ ' ' };
SCNT scnt[20][20];
void Check();
void PlusB(int y, int x, int way);
void PlusW(int y, int x, int way);
void NotB(int y, int x, int way);
void NotW(int y, int x, int way);

void Print() {
	std::cout << max << std::endl;
	for (int y = 0; y < 20; ++y) {
		for (int x = 0; x < 20; ++x) {
			if (scnt[y][x].scnt == max) {
				std::cout << "X : " << x + 1 << " Y : " << y + 1;
				if (scnt[y][x].way == 1) {
					std::cout << "가로" << std::endl;
				}
				if (scnt[y][x].way == 2) {
					std::cout << "세로" << std::endl;
				}
				if (scnt[y][x].way == 3) {
					std::cout << "오른쪽 대각" << std::endl;
				}
				if (scnt[y][x].way == 4) {
					std::cout << "왼쪽 대각" << std::endl;
				}
			}

		}
	}
}


void Check() {
	way = 1;
	for (int y = 0; y < 20; ++y) {
		for (int x = 0; x < 20; ++x) {
			if (stone[y][x] == 'O') {
				PlusB(y, x, way);

			}
			if (stone[y][x] == 'X') {
				PlusW(y, x, way);

			}
			if (cnt > max) {
				max = cnt;
			}
			if (scnt[y][x].scnt < cnt) {
				scnt[y][x].scnt = cnt;
				scnt[y][x].way = way;
			}
			cnt = 0;
		}
	}
	way = 2;
	for (int x = 0; x < 20; ++x) {
		for (int y = 0; y < 20; ++y) {
			if (stone[y][x] == 'O') {
				PlusB(y, x, way);

			}
			if (stone[y][x] == 'X') {
				PlusW(y, x, way);
			}
			if (cnt > max) {
				max = cnt;

			}
			if (scnt[y][x].scnt < cnt) {
				scnt[y][x].scnt = cnt;
				scnt[y][x].way = way;
			}
			cnt = 0;
		}
	}
	way = 3;
	for (int y = 0; y < 20; ++y) {
		for (int x = 0; x < 20; ++x) {
			if (stone[y][x] == 'O') {
				PlusB(y, x, way);
			}
			if (stone[y][x] == 'X') {
				PlusW(y, x, way);
			}
			if (cnt > max) {
				max = cnt;
			}
			if (scnt[y][x].scnt < cnt) {
				scnt[y][x].scnt = cnt;
				scnt[y][x].way = way;
			}
			cnt = 0;
		}
	}
	way = 4;
	for (int y = 0; y < 20; ++y) {
		for (int x = 0; x < 20; ++x) {
			if (stone[y][x] == 'O') {
				PlusB(y, x, way);
			}
			if (stone[y][x] == 'X') {
				PlusW(y, x, way);
			}
			if (cnt > max) {
				max = cnt;
			}
			if (scnt[y][x].scnt < cnt) {
				scnt[y][x].scnt = cnt;
				scnt[y][x].way = way;
			}
			cnt = 0;

		}
	}
}
void PlusB(int y, int x, int way) {
	++cnt;
	if (way == 1) {
		if (stone[y][x + 1] == 'O') {
			PlusB(y, x + 1, way);
		}
		else {
			NotB(y, x + 1, way);
		}
	}
	if (way == 2) {
		if (stone[y + 1][x] == 'O') {
			PlusB(y + 1, x, way);
		}
		else {
			NotB(y + 1, x, way);
		}
	}
	if (way == 3) {
		if (stone[y + 1][x + 1] == 'O') {
			PlusB(y + 1, x + 1, way);
		}
		else {
			NotB(y + 1, x + 1, way);
		}
	}
	if (way == 4) {
		if (stone[y + 1][x - 1] == 'O') {
			PlusB(y + 1, x - 1, way);
		}
		else {
			NotB(y + 1, x - 1, way);
		}
	}
}
void PlusW(int y, int x, int way) {
	++cnt;
	if (way == 1) {
		if (stone[y][x + 1] == 'X') {
			PlusW(y, x + 1, way);
		}
		else {
			NotW(y, x + 1, way);
		}
	}
	if (way == 2) {
		if (stone[y + 1][x] == 'X') {
			PlusW(y + 1, x, way);
		}
		else {
			NotW(y + 1, x, way);
		}
	}
	if (way == 3) {
		if (stone[y + 1][x + 1] == 'X') {
			PlusW(y + 1, x + 1, way);
		}
		else {
			NotW(y + 1, x + 1, way);
		}
	}
	if (way == 4) {
		if (stone[y + 1][x - 1] == 'X') {
			PlusW(y + 1, x - 1, way);
		}
		else {
			NotW(y + 1, x - 1, way);
		}
	}
}
void NotB(int y, int x, int way) {
	if (way == 1) {
		if (cnt > 2 && cnt < 5) {
			if (stone[y][x] != 'O' && stone[y][x] != 'X' && stone[y][x] != '6') {
				stone[y][x] = '!';
			}
			if (cnt == 3 && x - 4 >= 0) {
				if (stone[y][x - 5] != 'O' && stone[y][x - 5] != 'X' && stone[y][x - 5] != '6' && stone[y][x - 4] == 'O') {
					stone[y][x - 5] = '!';
				}
				if (stone[y][x - 4] != 'O' && stone[y][x - 4] != 'X' && stone[y][x - 4] != '6') {
					stone[y][x - 4] = '!';
				}
				if (stone[y][x - 3] != 'O' && stone[y][x - 3] != 'X' && stone[y][x - 3] != '6') {
					stone[y][x - 3] = '!';
				}
				if (stone[y][x - 2] != 'O' && stone[y][x - 2] != 'X' && stone[y][x - 2] != '6') {
					stone[y][x - 2] = '!';
				}
				if (stone[y][x - 1] != 'O' && stone[y][x - 1] != 'X' && stone[y][x - 1] != '6') {
					stone[y][x - 1] = '!';
				}
			}

			if (cnt == 4 && x - 5 >= 0) {
				if (stone[y][x - 6] != 'O' && stone[y][x - 6] != 'X' && stone[y][x - 6] != '6' && stone[y][x - 5] == 'O') {
					stone[y][x - 6] = '!';
				}
				if (stone[y][x - 5] != 'O' && stone[y][x - 5] != 'X' && stone[y][x - 5] != '6') {
					stone[y][x - 5] = '!';
				}
				if (stone[y][x - 4] != 'O' && stone[y][x - 4] != 'X' && stone[y][x - 4] != '6') {
					stone[y][x - 4] = '!';
				}
				if (stone[y][x - 3] != 'O' && stone[y][x - 3] != 'X' && stone[y][x - 3] != '6') {
					stone[y][x - 3] = '!';
				}
				if (stone[y][x - 2] != 'O' && stone[y][x - 2] != 'X' && stone[y][x - 2] != '6') {
					stone[y][x - 2] = '!';
				}
				if (stone[y][x - 1] != 'O' && stone[y][x - 1] != 'X' && stone[y][x - 1] != '6') {
					stone[y][x - 1] = '!';
				}
			}
		}
		else if (cnt >= 5) {
			if (stone[y][x] != 'O' && stone[y][x] != 'X') {
				stone[y][x] = '6';
			}
			if (stone[y][x - 5] != 'O' && stone[y][x - 5] != 'X' && stone[y][x - 5] != '6') {
				stone[y][x - 5] = '6';
			}
			if (stone[y][x - 4] != 'O' && stone[y][x - 4] != 'X' && stone[y][x - 4] != '6') {
				stone[y][x - 4] = '6';
			}
			if (stone[y][x - 3] != 'O' && stone[y][x - 3] != 'X' && stone[y][x - 3] != '6') {
				stone[y][x - 3] = '6';
			}
			if (stone[y][x - 2] != 'O' && stone[y][x - 2] != 'X' && stone[y][x - 2] != '6') {
				stone[y][x - 2] = '6';
			}
			if (stone[y][x - 1] != 'O' && stone[y][x - 1] != 'X' && stone[y][x - 1] != '6') {
				stone[y][x - 1] = '6';
			}
		}
		if (stone[y][x + 1] == 'O') {

			PlusB(y, x + 1, way);
		}
		else {
			return;
		}
	}
	if (way == 2) {
		if (cnt > 2 && cnt < 5) {
			if (stone[y][x] != 'O' && stone[y][x] != 'X') {
				stone[y][x] = '!';
			}
			if (cnt == 3 && y - 4 >= 0) {
				if (stone[y - 5][x] != 'O' && stone[y - 5][x] != 'X' && stone[y - 5][x] != '6' && stone[y - 4][x] == 'O') {
					stone[y - 5][x] = '!';
				}
				if (stone[y - 4][x] != 'O' && stone[y - 4][x] != 'X' && stone[y - 4][x] != '6') {
					stone[y - 4][x] = '!';
				}
				if (stone[y - 3][x] != 'O' && stone[y - 3][x] != 'X' && stone[y - 3][x] != '6') {
					stone[y - 3][x] = '!';
				}
				if (stone[y - 2][x] != 'O' && stone[y - 2][x] != 'X' && stone[y - 2][x] != '6') {
					stone[y - 2][x] = '!';
				}
				if (stone[y - 1][x] != 'O' && stone[y - 1][x] != 'X' && stone[y - 1][x] != '6') {
					stone[y - 1][x] = '!';
				}
			}
			if (cnt == 4 && y - 5 >= 0) {
				if (stone[y - 6][x] != 'O' && stone[y - 6][x] != 'X' && stone[y - 6][x] != '6' && stone[y - 5][x] == 'O') {
					stone[y - 6][x] = '!';
				}
				if (stone[y][x - 5] != 'O' && stone[y][x - 5] != 'X' && stone[y][x - 5] != '6') {
					stone[y][x - 5] = '!';
				}
				if (stone[y][x - 4] != 'O' && stone[y][x - 4] != 'X' && stone[y][x - 4] != '6') {
					stone[y][x - 4] = '!';
				}
				if (stone[y][x - 3] != 'O' && stone[y][x - 3] != 'X' && stone[y][x - 3] != '6') {
					stone[y][x - 3] = '!';
				}
				if (stone[y][x - 2] != 'O' && stone[y][x - 2] != 'X' && stone[y][x - 2] != '6') {
					stone[y][x - 2] = '!';
				}
				if (stone[y][x - 1] != 'O' && stone[y][x - 1] != 'X' && stone[y][x - 1] != '6') {
					stone[y][x - 1] = '!';
				}
			}
		}
		else if (cnt >= 5) {
			if (stone[y][x] != 'O' && stone[y][x] != 'X') {
				stone[y][x] = '6';
			}
			if (stone[y - 5][x] != 'O' && stone[y - 5][x] != 'X' && stone[y - 5][x] != '6') {
				stone[y - 5][x] = '6';
			}
			if (stone[y - 4][x] != 'O' && stone[y - 4][x] != 'X' && stone[y - 4][x] != '6') {
				stone[y - 4][x] = '6';
			}
			if (stone[y - 3][x] != 'O' && stone[y - 3][x] != 'X' && stone[y - 3][x] != '6') {
				stone[y - 3][x] = '6';
			}
			if (stone[y - 2][x] != 'O' && stone[y - 2][x] != 'X' && stone[y - 2][x] != '6') {
				stone[y - 2][x] = '6';
			}
			if (stone[y - 1][x] != 'O' && stone[y - 1][x] != 'X' && stone[y - 1][x] != '6') {
				stone[y - 1][x] = '6';
			}
		}
		if (stone[y + 1][x] == 'O') {

			PlusB(y + 1, x, way);
		}
		else {
			return;
		}
	}
	if (way == 3) {
		if (cnt > 2 && cnt < 5) {
			if (stone[y][x] != 'O' && stone[y][x] != 'X') {
				stone[y][x] = '!';
			}
			if (cnt == 3 && x - 4 >= 0) {
				if (stone[y - 5][x - 5] != 'O' && stone[y - 5][x - 5] != 'X' && stone[y - 5][x - 5] != '6' && stone[y - 4][x - 4] == 'O') {
					stone[y - 5][x - 5] = '!';
				}
				if (stone[y - 4][x - 4] != 'O' && stone[y - 4][x - 4] != 'X' && stone[y - 4][x - 4] != '6') {
					stone[y - 4][x - 4] = '!';
				}
				if (stone[y - 3][x - 3] != 'O' && stone[y - 3][x - 3] != 'X' && stone[y - 3][x - 3] != '6') {
					stone[y - 3][x - 3] = '!';
				}
				if (stone[y - 2][x - 2] != 'O' && stone[y - 2][x - 2] != 'X' && stone[y - 2][x - 2] != '6') {
					stone[y - 2][x - 2] = '!';
				}
				if (stone[y - 1][x - 1] != 'O' && stone[y - 1][x - 1] != 'X' && stone[y - 1][x - 1] != '6') {
					stone[y - 1][x - 1] = '!';
				}
			}

			if (cnt == 4 && x - 5 >= 0) {
				if (stone[y - 6][x - 6] != 'O' && stone[y - 6][x - 6] != 'X' && stone[y - 6][x - 6] != '6' && stone[y - 5][x - 5] == 'O') {
					stone[y - 6][x - 6] = '!';
				}
				if (stone[y - 5][x - 5] != 'O' && stone[y - 5][x - 5] != 'X' && stone[y - 5][x - 5] != '6') {
					stone[y - 5][x - 5] = '!';
				}
				if (stone[y - 4][x - 4] != 'O' && stone[y - 4][x - 4] != 'X' && stone[y - 4][x - 4] != '6') {
					stone[y - 4][x - 4] = '!';
				}
				if (stone[y - 3][x - 3] != 'O' && stone[y - 3][x - 3] != 'X' && stone[y - 3][x - 3] != '6') {
					stone[y - 3][x - 3] = '!';
				}
				if (stone[y - 2][x - 2] != 'O' && stone[y - 2][x - 2] != 'X' && stone[y - 2][x - 2] != '6') {
					stone[y - 2][x - 2] = '!';
				}
				if (stone[y - 1][x - 1] != 'O' && stone[y - 1][x - 1] != 'X' && stone[y][x - 1] != '6') {
					stone[y - 1][x - 1] = '!';
				}
			}
		}
		else if (cnt >= 5) {
			if (stone[y][x] != 'O' && stone[y][x] != 'X') {
				stone[y][x] = '6';
			}
			if (stone[y - 5][x - 5] != 'O' && stone[y - 5][x - 5] != 'X' && stone[y - 5][x - 5] != '6') {
				stone[y - 5][x - 5] = '!';
			}
			if (stone[y - 4][x - 4] != 'O' && stone[y - 4][x - 4] != 'X' && stone[y - 4][x - 4] != '6') {
				stone[y - 4][x - 4] = '6';
			}
			if (stone[y - 3][x - 3] != 'O' && stone[y - 3][x - 3] != 'X' && stone[y - 3][x - 3] != '6') {
				stone[y - 3][x - 3] = '6';
			}
			if (stone[y - 2][x - 2] != 'O' && stone[y - 2][x - 2] != 'X' && stone[y - 2][x - 2] != '6') {
				stone[y - 2][x - 2] = '6';
			}
			if (stone[y][x - 1] != 'O' && stone[y][x - 1] != 'X' && stone[y - 1][x - 1] != '6') {
				stone[y][x - 1] = '6';
			}
		}
		if (stone[y + 1][x + 1] == 'O') {
			if (x + 1 < 19) {
				PlusB(y + 1, x + 1, way);
			}
		}

		else {
			return;
		}
	}

	if (way == 4) {
		if (cnt > 2 && cnt < 5) {
			if (stone[y][x] != 'O' && stone[y][x] != 'X') {
				stone[y][x] = '!';
			}
			if (cnt == 3 && x + 4 <= 19 && y - 4 >= 0) {
				if (stone[y - 5][x + 5] != 'O' && stone[y - 5][x + 5] != 'X' && stone[y - 5][x + 5] != '6' && stone[y - 4][x + 4] == 'O') {
					stone[y - 5][x + 5] = '!';
				}
				if (stone[y - 4][x + 4] != 'O' && stone[y - 4][x + 4] != 'X' && stone[y - 4][x + 4] != '6') {
					stone[y - 4][x + 4] = '!';
				}
				if (stone[y - 3][x + 3] != 'O' && stone[y - 3][x + 3] != 'X' && stone[y - 3][x + 3] != '6') {
					stone[y - 3][x + 3] = '!';
				}
				if (stone[y - 2][x + 2] != 'O' && stone[y - 2][x + 2] != 'X' && stone[y - 2][x + 2] != '6') {
					stone[y - 2][x + 2] = '!';
				}
				if (stone[y - 1][x + 1] != 'O' && stone[y - 1][x + 1] != 'X' && stone[y - 1][x + 1] != '6') {
					stone[y - 1][x + 1] = '!';
				}
			}
			if (cnt == 4 && x + 5 <= 19 && y - 5 >= 0) {
				if (stone[y - 6][x + 6] != 'O' && stone[y - 6][x + 6] != 'X' && stone[y - 6][x + 6] != '6' && stone[y - 5][x + 5] == 'O') {
					stone[y - 6][x + 6] = '!';
				}
				if (stone[y - 5][x + 5] != 'O' && stone[y - 5][x + 5] != 'X' && stone[y - 5][x + 5] != '6') {
					stone[y - 5][x + 5] = '!';
				}
				if (stone[y - 4][x + 4] != 'O' && stone[y - 4][x + 4] != 'X' && stone[y - 4][x + 4] != '6') {
					stone[y - 4][x + 4] = '!';
				}
				if (stone[y - 3][x + 3] != 'O' && stone[y - 3][x + 3] != 'X' && stone[y - 3][x + 3] != '6') {
					stone[y - 3][x + 3] = '!';
				}
				if (stone[y - 2][x + 2] != 'O' && stone[y - 2][x + 2] != 'X' && stone[y - 2][x + 2] != '6') {
					stone[y - 2][x + 2] = '!';
				}
				if (stone[y - 1][x + 1] != 'O' && stone[y - 1][x + 1] != 'X' && stone[y - 1][x + 1] != '6') {
					stone[y - 1][x + 1] = '!';
				}
			}
		}
		else if (cnt >= 5) {
			if (stone[y][x] != 'O' && stone[y][x] != 'X') {
				stone[y][x] = '6';
			}
			if (stone[y - 5][x + 5] != 'O' && stone[y - 5][x + 5] != 'X' && stone[y - 5][x + 5] != '6') {
				stone[y - 5][x + 5] = '!';
			}
			if (stone[y - 4][x + 4] != 'O' && stone[y - 4][x + 4] != 'X' && stone[y - 4][x + 4] != '6') {
				stone[y - 4][x + 4] = '6';
			}
			if (stone[y - 3][x + 3] != 'O' && stone[y - 3][x + 3] != 'X' && stone[y - 3][x + 3] != '6') {
				stone[y - 3][x + 3] = '6';
			}
			if (stone[y - 2][x + 2] != 'O' && stone[y - 2][x + 2] != 'X' && stone[y - 2][x + 2] != '6') {
				stone[y - 2][x + 2] = '6';
			}
			if (stone[y][x - 1] != 'O' && stone[y][x - 1] != 'X' && stone[y][x - 1] != '6') {
				stone[y][x - 1] = '6';
			}
		}
		if (stone[y + 1][x - 1] == 'O') {
			if (x - 1 >= 0) {
				PlusB(y + 1, x - 1, way);
			}
		}

		else {
			return;
		}
	}
}
void NotW(int y, int x, int way) {
	if (way == 1) {
		if (cnt > 2 && cnt < 5) {
			if (stone[y][x] != 'O' && stone[y][x] != 'X' && stone[y][x] != '6') {
				stone[y][x] = '!';
			}
			if (cnt == 3 && x - 4 >= 0) {
				if (stone[y][x - 5] != 'O' && stone[y][x - 5] != 'X' && stone[y][x - 5] != '6' && stone[y][x - 4] == 'X') {
					stone[y][x - 5] = '!';
				}
				if (stone[y][x - 4] != 'O' && stone[y][x - 4] != 'X' && stone[y][x - 4] != '6') {
					stone[y][x - 4] = '!';
				}
				if (stone[y][x - 3] != 'O' && stone[y][x - 3] != 'X' && stone[y][x - 3] != '6') {
					stone[y][x - 3] = '!';
				}
				if (stone[y][x - 2] != 'O' && stone[y][x - 2] != 'X' && stone[y][x - 2] != '6') {
					stone[y][x - 2] = '!';
				}
				if (stone[y][x - 1] != 'O' && stone[y][x - 1] != 'X' && stone[y][x - 1] != '6') {
					stone[y][x - 1] = '!';
				}
			}

			if (cnt == 4 && x - 5 >= 0) {
				if (stone[y][x - 6] != 'O' && stone[y][x - 6] != 'X' && stone[y][x - 6] != '6' && stone[y][x - 5] == 'X') {
					stone[y][x - 6] = '!';
				}
				if (stone[y][x - 5] != 'O' && stone[y][x - 5] != 'X' && stone[y][x - 5] != '6') {
					stone[y][x - 5] = '!';
				}
				if (stone[y][x - 4] != 'O' && stone[y][x - 4] != 'X' && stone[y][x - 4] != '6') {
					stone[y][x - 4] = '!';
				}
				if (stone[y][x - 3] != 'O' && stone[y][x - 3] != 'X' && stone[y][x - 3] != '6') {
					stone[y][x - 3] = '!';
				}
				if (stone[y][x - 2] != 'O' && stone[y][x - 2] != 'X' && stone[y][x - 2] != '6') {
					stone[y][x - 2] = '!';
				}
				if (stone[y][x - 1] != 'O' && stone[y][x - 1] != 'X' && stone[y][x - 1] != '6') {
					stone[y][x - 1] = '!';
				}
			}
		}
		else if (cnt >= 5) {
			if (stone[y][x] != 'O' && stone[y][x] != 'X') {
				stone[y][x] = '6';
			}
			if (stone[y][x - 5] != 'O' && stone[y][x - 5] != 'X' && stone[y][x - 5] != '6') {
				stone[y][x - 5] = '6';
			}
			if (stone[y][x - 4] != 'O' && stone[y][x - 4] != 'X' && stone[y][x - 4] != '6') {
				stone[y][x - 4] = '6';
			}
			if (stone[y][x - 3] != 'O' && stone[y][x - 3] != 'X' && stone[y][x - 3] != '6') {
				stone[y][x - 3] = '6';
			}
			if (stone[y][x - 2] != 'O' && stone[y][x - 2] != 'X' && stone[y][x - 2] != '6') {
				stone[y][x - 2] = '6';
			}
			if (stone[y][x - 1] != 'O' && stone[y][x - 1] != 'X' && stone[y][x - 1] != '6') {
				stone[y][x - 1] = '6';
			}
		}
		if (stone[y][x + 1] == 'X') {

			PlusW(y, x + 1, way);
		}
		else {
			return;
		}
	}
	if (way == 2) {
		if (cnt > 2 && cnt < 5) {
			if (stone[y][x] != 'O' && stone[y][x] != 'X') {
				stone[y][x] = '!';
			}
			if (cnt == 3 && y - 4 >= 0) {
				if (stone[y - 5][x] != 'O' && stone[y - 5][x] != 'X' && stone[y - 5][x] != '6' && stone[y - 4][x] == 'X') {
					stone[y - 5][x] = '!';
				}
				if (stone[y - 4][x] != 'O' && stone[y - 4][x] != 'X' && stone[y - 4][x] != '6') {
					stone[y - 4][x] = '!';
				}
				if (stone[y - 3][x] != 'O' && stone[y - 3][x] != 'X' && stone[y - 3][x] != '6') {
					stone[y - 3][x] = '!';
				}
				if (stone[y - 2][x] != 'O' && stone[y - 2][x] != 'X' && stone[y - 2][x] != '6') {
					stone[y - 2][x] = '!';
				}
				if (stone[y - 1][x] != 'O' && stone[y - 1][x] != 'X' && stone[y - 1][x] != '6') {
					stone[y - 1][x] = '!';
				}
			}
			if (cnt == 4 && y - 5 >= 0) {
				if (stone[y - 6][x] != 'O' && stone[y - 6][x] != 'X' && stone[y - 6][x] != '6' && stone[y - 5][x] == 'X') {
					stone[y - 6][x] = '!';
				}
				if (stone[y][x - 5] != 'O' && stone[y][x - 5] != 'X' && stone[y][x - 5] != '6') {
					stone[y][x - 5] = '!';
				}
				if (stone[y][x - 4] != 'O' && stone[y][x - 4] != 'X' && stone[y][x - 4] != '6') {
					stone[y][x - 4] = '!';
				}
				if (stone[y][x - 3] != 'O' && stone[y][x - 3] != 'X' && stone[y][x - 3] != '6') {
					stone[y][x - 3] = '!';
				}
				if (stone[y][x - 2] != 'O' && stone[y][x - 2] != 'X' && stone[y][x - 2] != '6') {
					stone[y][x - 2] = '!';
				}
				if (stone[y][x - 1] != 'O' && stone[y][x - 1] != 'X' && stone[y][x - 1] != '6') {
					stone[y][x - 1] = '!';
				}
			}
		}
		else if (cnt >= 5) {
			if (stone[y][x] != 'O' && stone[y][x] != 'X') {
				stone[y][x] = '6';
			}
			if (stone[y - 5][x] != 'O' && stone[y - 5][x] != 'X' && stone[y - 5][x] != '6') {
				stone[y - 5][x] = '6';
			}
			if (stone[y - 4][x] != 'O' && stone[y - 4][x] != 'X' && stone[y - 4][x] != '6') {
				stone[y - 4][x] = '6';
			}
			if (stone[y - 3][x] != 'O' && stone[y - 3][x] != 'X' && stone[y - 3][x] != '6') {
				stone[y - 3][x] = '6';
			}
			if (stone[y - 2][x] != 'O' && stone[y - 2][x] != 'X' && stone[y - 2][x] != '6') {
				stone[y - 2][x] = '6';
			}
			if (stone[y - 1][x] != 'O' && stone[y - 1][x] != 'X' && stone[y - 1][x] != '6') {
				stone[y - 1][x] = '6';
			}
		}
		if (stone[y + 1][x] == 'X') {

			PlusW(y + 1, x, way);
		}
		else {
			return;
		}
	}
	if (way == 3) {
		if (cnt > 2 && cnt < 5) {
			if (stone[y][x] != 'O' && stone[y][x] != 'X') {
				stone[y][x] = '!';
			}
			if (cnt == 3 && x - 4 >= 0) {
				if (stone[y - 5][x - 5] != 'O' && stone[y - 5][x - 5] != 'X' && stone[y - 5][x - 5] != '6' && stone[y - 4][x - 4] == 'X') {
					stone[y - 5][x - 5] = '!';
				}
				if (stone[y - 4][x - 4] != 'O' && stone[y - 4][x - 4] != 'X' && stone[y - 4][x - 4] != '6') {
					stone[y - 4][x - 4] = '!';
				}
				if (stone[y - 3][x - 3] != 'O' && stone[y - 3][x - 3] != 'X' && stone[y - 3][x - 3] != '6') {
					stone[y - 3][x - 3] = '!';
				}
				if (stone[y - 2][x - 2] != 'O' && stone[y - 2][x - 2] != 'X' && stone[y - 2][x - 2] != '6') {
					stone[y - 2][x - 2] = '!';
				}
				if (stone[y - 1][x - 1] != 'O' && stone[y - 1][x - 1] != 'X' && stone[y - 1][x - 1] != '6') {
					stone[y - 1][x - 1] = '!';
				}
			}

			if (cnt == 4 && x - 5 >= 0) {
				if (stone[y - 6][x - 6] != 'O' && stone[y - 6][x - 6] != 'X' && stone[y - 6][x - 6] != '6' && stone[y - 5][x - 5] == 'X') {
					stone[y - 6][x - 6] = '!';
				}
				if (stone[y - 5][x - 5] != 'O' && stone[y - 5][x - 5] != 'X' && stone[y - 5][x - 5] != '6') {
					stone[y - 5][x - 5] = '!';
				}
				if (stone[y - 4][x - 4] != 'O' && stone[y - 4][x - 4] != 'X' && stone[y - 4][x - 4] != '6') {
					stone[y - 4][x - 4] = '!';
				}
				if (stone[y - 3][x - 3] != 'O' && stone[y - 3][x - 3] != 'X' && stone[y - 3][x - 3] != '6') {
					stone[y - 3][x - 3] = '!';
				}
				if (stone[y - 2][x - 2] != 'O' && stone[y - 2][x - 2] != 'X' && stone[y - 2][x - 2] != '6') {
					stone[y - 2][x - 2] = '!';
				}
				if (stone[y - 1][x - 1] != 'O' && stone[y - 1][x - 1] != 'X' && stone[y][x - 1] != '6') {
					stone[y - 1][x - 1] = '!';
				}
			}
		}
		else if (cnt >= 5) {
			if (stone[y][x] != 'O' && stone[y][x] != 'X') {
				stone[y][x] = '6';
			}
			if (stone[y - 5][x - 5] != 'O' && stone[y - 5][x - 5] != 'X' && stone[y - 5][x - 5] != '6') {
				stone[y - 5][x - 5] = '!';
			}
			if (stone[y - 4][x - 4] != 'O' && stone[y - 4][x - 4] != 'X' && stone[y - 4][x - 4] != '6') {
				stone[y - 4][x - 4] = '6';
			}
			if (stone[y - 3][x - 3] != 'O' && stone[y - 3][x - 3] != 'X' && stone[y - 3][x - 3] != '6') {
				stone[y - 3][x - 3] = '6';
			}
			if (stone[y - 2][x - 2] != 'O' && stone[y - 2][x - 2] != 'X' && stone[y - 2][x - 2] != '6') {
				stone[y - 2][x - 2] = '6';
			}
			if (stone[y][x - 1] != 'O' && stone[y][x - 1] != 'X' && stone[y - 1][x - 1] != '6') {
				stone[y][x - 1] = '6';
			}
		}
		if (stone[y + 1][x + 1] == 'X') {
			if (x + 1 < 19) {
				PlusW(y + 1, x + 1, way);
			}
		}

		else {
			return;
		}
	}

	if (way == 4) {
		if (cnt > 2 && cnt < 5) {
			if (stone[y][x] != 'O' && stone[y][x] != 'X') {
				stone[y][x] = '!';
			}
			if (cnt == 3 && x + 4 <= 19 && y - 4 >= 0) {
				if (stone[y - 5][x + 5] != 'O' && stone[y - 5][x + 5] != 'X' && stone[y - 5][x + 5] != '6' && stone[y -4][x + 4] == 'X') {
					stone[y - 5][x + 5] = '!';
				}
				if (stone[y - 4][x + 4] != 'O' && stone[y - 4][x + 4] != 'X' && stone[y - 4][x + 4] != '6') {
					stone[y - 4][x + 4] = '!';
				}
				if (stone[y - 3][x + 3] != 'O' && stone[y - 3][x + 3] != 'X' && stone[y - 3][x + 3] != '6') {
					stone[y - 3][x + 3] = '!';
				}
				if (stone[y - 2][x + 2] != 'O' && stone[y - 2][x + 2] != 'X' && stone[y - 2][x + 2] != '6') {
					stone[y - 2][x + 2] = '!';
				}
				if (stone[y - 1][x + 1] != 'O' && stone[y - 1][x + 1] != 'X' && stone[y - 1][x + 1] != '6') {
					stone[y - 1][x + 1] = '!';
				}
			}
			if (cnt == 4 && x + 5 <= 19 && y - 5 >= 0) {
				if (stone[y - 6][x + 6] != 'O' && stone[y - 6][x + 6] != 'X' && stone[y - 6][x + 6] != '6' && stone[y - 5][x + 5] == 'X') {
					stone[y - 6][x - 6] = '!';
				}
				if (stone[y - 5][x + 5] != 'O' && stone[y - 5][x + 5] != 'X' && stone[y - 5][x + 5] != '6') {
					stone[y - 5][x + 5] = '!';
				}
				if (stone[y - 4][x + 4] != 'O' && stone[y - 4][x + 4] != 'X' && stone[y - 4][x + 4] != '6') {
					stone[y - 4][x + 4] = '!';
				}
				if (stone[y - 3][x + 3] != 'O' && stone[y - 3][x + 3] != 'X' && stone[y - 3][x + 3] != '6') {
					stone[y - 3][x + 3] = '!';
				}
				if (stone[y - 2][x + 2] != 'O' && stone[y - 2][x + 2] != 'X' && stone[y - 2][x + 2] != '6') {
					stone[y - 2][x + 2] = '!';
				}
				if (stone[y - 1][x + 1] != 'O' && stone[y - 1][x + 1] != 'X' && stone[y - 1][x + 1] != '6') {
					stone[y - 1][x + 1] = '!';
				}
			}
		}
		else if (cnt >= 5) {
			if (stone[y][x] != 'O' && stone[y][x] != 'X') {
				stone[y][x] = '6';
			}
			if (stone[y - 5][x + 5] != 'O' && stone[y - 5][x + 5] != 'X' && stone[y - 5][x + 5] != '6') {
				stone[y - 5][x + 5] = '!';
			}
			if (stone[y - 4][x + 4] != 'O' && stone[y - 4][x + 4] != 'X' && stone[y - 4][x + 4] != '6') {
				stone[y - 4][x + 4] = '6';
			}
			if (stone[y - 3][x + 3] != 'O' && stone[y - 3][x + 3] != 'X' && stone[y - 3][x + 3] != '6') {
				stone[y - 3][x + 3] = '6';
			}
			if (stone[y - 2][x + 2] != 'O' && stone[y - 2][x + 2] != 'X' && stone[y - 2][x + 2] != '6') {
				stone[y - 2][x + 2] = '6';
			}
			if (stone[y][x - 1] != 'O' && stone[y][x - 1] != 'X' && stone[y][x - 1] != '6') {
				stone[y][x - 1] = '6';
			}
		}
		if (stone[y + 1][x - 1] == 'X') {
			if (x - 1 > 0) {
				PlusW(y + 1, x - 1, way);
			}
		}

		else {
			return;
		}
	}
}
int main()
{

	int x, y;

	for (int i = 0; i < 20; ++i) {
		std::cout << "-----------------------------------------" << std::endl;
		for (int j = 0; j < 20; ++j) {
			std::cout << '|' << stone[i][j];
		}
		std::cout << '|' << std::endl;
	}
	std::cout << "-----------------------------------------" << std::endl;
	while (1) {
	Black:

		std::cout << "흑돌 x좌표 : ";
		std::cin >> x;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(10, '\n');
			std::cout << "숫자를 입력해 주세요..." << std::endl;
			goto Black;
		}
		std::cout << "흑돌 y좌표 : ";
		std::cin >> y;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(10, '\n');
			std::cout << "숫자를 입력해 주세요..." << std::endl;
			goto Black;
		}
		--x; --y;
		if (x < 0 || x >= 20 || y < 0 || y >= 20) {
			std::cout << "1부터 20 사이의 숫자를입력해 주세요..." << std::endl;
			goto Black;
		}
		if (stone[y][x] == 'O' || stone[y][x] == 'X') {
			std::cout << "이미 배치되어 있습니다. 다른곳을 선택해 주세요..." << std::endl;
			goto Black;
		}
		stone[y][x] = 'O';
		Check();
		system("cls");

		for (int i = 0; i < 20; ++i) {
			std::cout << "-----------------------------------------" << std::endl;
			for (int j = 0; j < 20; ++j) {
				std::cout << '|' << stone[i][j];
			}
			std::cout << '|' << std::endl;
		}
		std::cout << "-----------------------------------------" << std::endl;

		Print();
	White:
		std::cout << "백돌 x좌표 : ";
		std::cin >> x;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(10, '\n');
			std::cout << "숫자를 입력해 주세요..." << std::endl;
			goto White;
		}
		std::cout << "백돌 y좌표 : ";
		std::cin >> y;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(10, '\n');
			std::cout << "숫자를 입력해 주세요..." << std::endl;
			goto White;
		}
		--x; --y;
		if (x < 0 || x >= 20 || y < 0 || y >= 20) {
			std::cout << "1부터 20 사이의 숫자를입력해 주세요..." << std::endl;
			goto White;
		}
		if (stone[y][x] == 'O' || stone[y][x] == 'X') {
			std::cout << "이미 배치되어 있습니다. 다른곳을 선택해 주세요..." << std::endl;
			goto White;
		}
		stone[y][x] = 'X';
		Check();

		system("cls");

		for (int i = 0; i < 20; ++i) {
			std::cout << "-----------------------------------------" << std::endl;
			for (int j = 0; j < 20; ++j) {
				std::cout << '|' << stone[i][j];
			}
			std::cout << '|' << std::endl;
		}
		std::cout << "-----------------------------------------" << std::endl;

		Print();
	}
}