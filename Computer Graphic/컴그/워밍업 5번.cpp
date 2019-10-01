#include <iostream>
#include <random>

int main() {
	std::random_device rd;
	std::default_random_engine dre(rd());
	std::uniform_int_distribution<>uid(0, 2);//0 보통 1 위로 2 아래로
	int y = 0, x = 0;
	int last_way = 3;
	char maze[50][50];
	char sel;
	while (true)
	{
		for (y = 0; y < 50; ++y) {
			for (x = 0; x < 50; ++x) {
				maze[y][x] = 1;
			}
		}
		
		y = 0; x = 0;
		for (int n = 0; n < 12; ++n) {
			for (y = 0; y < 5; ++y) {
				maze[y + n * 4][x + n * 4] = 0;
			}
			y = 4;
			for (x = 0; x < 5; ++x) {
				maze[y + n * 4][x + n * 4] = 0;
			}
			x = 0;
		}
		maze[49][48] = 0;
		maze[49][49] = 0;
		y = 0; x = 0;
		for (int i = 1; i < 11; ++i) {
		re:
			switch (uid(dre))
			{
			case 0:
				break;
			case 1:
				maze[i * 4][i * 4] = 1;
				maze[i * 4 - 1][i * 4 - 1] = 0;
				maze[i * 4 - 1][i * 4] = 0;
				maze[i * 4 - 1][i * 4 + 1] = 0;
				maze[i * 4][i * 4 + 1] = 0;
				maze[i * 4 + 1][i * 4 + 1] = 0;
				break;
			case 2:
				if (maze[i * 4 + 1][i * 4 - 2] == 0) {
					goto re;
				}
				maze[i * 4][i * 4] = 1;
				maze[i * 4 + 1][i * 4 - 1] = 0;
				maze[i * 4 + 1][i * 4 + 1] = 0;
				maze[i * 4 + 2][i * 4 + 1] = 0;
				maze[i * 4 + 3][i * 4 + 1] = 0;
				maze[i * 4 + 4][i * 4 + 1] = 1;
				maze[i * 4 + 5][i * 4 + 1] = 0;
				maze[i * 4 + 5][i * 4] = 0;
				maze[i * 4 + 5][i * 4 + 2] = 0;
				maze[i * 4 + 2][i * 4] = 1;
				break;
			}
		}
		for (y = 0; y < 50; ++y) {
			for (x = 0; x < 50; ++x) {
				if (maze[y][x] == 0) {
					std::cout << "□";
				}
				else if (maze[y][x] == 1) {
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

