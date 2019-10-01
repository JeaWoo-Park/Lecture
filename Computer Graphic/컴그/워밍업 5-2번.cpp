#include <iostream>
#include <random>

int main() {
	std::random_device rd;
	std::default_random_engine dre(rd());
	std::uniform_int_distribution<>uid(0, 3);//0 → 1 ← 2 ↑ 3 ↓
	int y = 0, x = 0;
	int last_way = 0;
	char maze[50][50];
	for (int i = 0; i < 50; ++i) {
		for (int j = 0; j < 50; ++j) {
			maze[i][j] = 1;
		}
	}
	maze[0][0] = 0;
	maze[49][49] = 0;
	

	char sel;
	while (true)
	{
		//while (x != 49 && y != 49) {
		b:
			switch (uid(dre))
			{
			case 0:
				if (last_way == 1) {
					goto b;
				}
				if (x == 49) {
					goto b;
				}
				if (x >= 4) {
					if (maze[x][y] == 0 && maze[x - 1][y] == 0 && maze[x - 2][y] == 0 && maze[x - 3][y] == 0 && maze[x - 4][y] == 0) {
						goto b;
					}
				}
				if (maze[x + 1][y - 1] == 0 || maze[x + 1][y + 1]== 0) {
					goto b;
				}
				x += 1;
				maze[y][x] = 0;
				last_way = 0;
				break;
			case 1:
				if (last_way == 0) {
					goto b;
				}
				if (x == 0) {
					goto b;
				}
				if (x <= 45) {
					if (maze[x][y] == 0 && maze[x + 1][y] == 0 && maze[x + 2][y] == 0 && maze[x + 3][y] == 0 && maze[x + 4][y] == 0) {
						goto b;
					}
				}
				if (maze[x - 1][y - 1] == 0 || maze[x - 1][y + 1] == 0) {
					goto b;
				}
				x -= 1;
				maze[y][x] = 0;
				last_way = 1;
				break;
			case 2:
				if (last_way == 3) {
					goto b;
				}
				if (y == 0) {
					goto b;
				}
				if (y <= 45) {
					if (maze[x][y] == 0 && maze[x][y + 1] == 0 && maze[x][y + 2] == 0 && maze[x][y + 3] == 0 && maze[x][y + 4] == 0) {
						goto b;
					}
				}
				if (maze[x + 1][y - 1] == 0 || maze[x - 1][y - 1] == 0) {
					goto b;
				}
				y -= 1;
				maze[y][x] = 0;
				last_way = 2;
				break;
			case 3:
				if (last_way == 2) {
					goto b;
				}
				if (y == 49) {
					goto b;
				}
				if (y >= 4) {
					if (maze[x][y] == 0 && maze[x][y - 1] == 0 && maze[x][y - 2] == 0 && maze[x][y - 3] == 0 && maze[x][y - 4] == 0) {
						goto b;
					}
				}
				if (maze[x + 1][y + 1] == 0 || maze[x - 1][y + 1] == 0) {
					goto b;
				}
				y += 1;
				maze[y][x] = 0;
				last_way = 3;
				break;
			}
		//}
		for (int i = 0; i < 50; ++i) {
			for (int j = 0; j < 50; ++j) {
				if (maze[i][j] == 0) {
					std::cout << "□";
				}
				else if (maze[i][j] == 1) {
					std::cout << "■";
				}

			}
			std::cout << std::endl;
		}

	sellect:
		std::cout << "명령어 : " << std::endl;
		sel = std::cin.get();
		switch (sel)
		{
		case '\n':
			system("cls");
			break;
		case 'q':
			return 0;
			break;
		default:
			std::cout << "잘못된 입력 입니다." << std::endl;
			std::cin.clear();
			std::cin.ignore();
			goto sellect;
			break;
		}
	}
}


