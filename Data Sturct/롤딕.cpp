#include <iostream>
struct LolDic
{
	char name[16];
	double hp, mp;
	int speed, range;
	char position[10];
};
LolDic cham[40] = {
	{ "파이크", 2300, 1265, 330, 150, "서포터" },
	{ "럭스", 1935, 879.5, 330, 550, "미드" },
	{ "룰루", 1783, 1285, 330, 550, "서포터" },
	{ "사일러스", 2030, 1130, 340, 175, "미드" },
	{ "리 신", 2015.8, 200, 345, 125, "정글" },
	{ "케인", 2030, 1022, 340, 175, "정글" },
	{ "잭스", 2037.8, 882.8, 350, 125, "탑" },
	{ "헤카림", 2110, 956.2, 345, 175, "정글" },
	{"징크스", 2009, 1010.6, 325, 525, "원딜" },
	{"피오라", 1995, 980, 345, 150, "탑" },
	{"케이틀린", 2028.4, 908.8, 325, 650, "원딜" },
	{"쓰레쉬", 2141.52, 1021.92, 335, 450, "서포터" },
	{ "자이라", 1847, 843, 340, 575, "서포터" },
	{ "조이", 2124, 850, 340, 525, "미드" },
	{ "오른", 2205, 1065, 335, 175, "탑" },
	{ "문도", 2095.52, 0, 345, 125, "탑" },
	{ "진", 2103, 1150, 330, 550, "원딜" },
	{ "렉사이", 2056.2, 100, 335, 750, "정글" },
	{ "미스포츈", 2088, 920.84, 325, 550, "원딜" },
	{ "신드라", 2053, 990, 330, 550, "미드" }
};
int Ccount = 20;
void Print(int);
void Search();
void Insert();
void Delete();
void DeleteAll();
void PrintAll();
void FindMaxHP();
void SortByHP();
void Print(int i) {
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "이름 : "<< cham[i].name << std::endl;
	std::cout << "HP : " << cham[i].hp << std::endl;
	std::cout << "MP : " << cham[i].mp << std::endl;
	std::cout << "이동 속도 : " << cham[i].speed << std::endl;
	std::cout << "사거리 : "<< cham[i].range << std::endl;
	std::cout << "포지션 : "<< cham[i].position << std::endl;
	std::cout << "-----------------------------------" << std::endl;
}
void Search() {
	system("cls");
	std::cout << "찾는 챔피언의 이름을 입력하세요 : ";
	char name[16];
	std::cin >> name;
	for (int i = 0; i < Ccount; ++i) {
		if (!(strcmp(cham[i].name, name))) {
			Print(i);
			goto SFin;
		}
	}
	std::cout << "찾으시는 챔피언의 정보가 없습니다." << std::endl;
SFin:
	system("pause");
}
void Insert() {
	system("cls");
	std::cout << "챔피언의 정보를 추가합니다." << std::endl;
	std::cout << "이름 : ";
	std::cin >> cham[Ccount].name;
	for (int i = 0; i < Ccount; ++i) {
		if (!(strcmp(cham[i].name, cham[Ccount].name))) {
			std::cout << "이미 있는 챔피언 입니다. 다시입력해 주세요." << std::endl;
			std::cin.clear();
			std::cin.ignore(16, '\n');
			system("pause");
			Insert();
			goto IFin;
		}
	}
HP:
	std::cout << "HP : ";
	std::cin >> cham[Ccount].hp;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(10, '\n');
		std::cout << "잘못입력하셧습니다." << std::endl;
		goto HP;
	}
MP:
	std::cout << "MP : ";
	std::cin >> cham[Ccount].mp;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(10, '\n');
		std::cout << "잘못입력하셧습니다." << std::endl;
		goto MP;
	}
Speed:
	std::cout << "이동 속도 : ";
	std::cin >> cham[Ccount].speed;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(10, '\n');
		std::cout << "잘못입력하셧습니다." << std::endl;
		goto Speed;
	}
Range:
	std::cout << "사거리 : ";
	std::cin >> cham[Ccount].range;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(10, '\n');
		std::cout << "잘못입력하셧습니다." << std::endl;
		goto Range;
	}
Position:
	std::cout << "포지션 : ";
	std::cin >> cham[Ccount].position;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(10, '\n');
		std::cout << "잘못입력하셧습니다." << std::endl;
		goto Position;
	}

	std::cout << "정상적으로 추가 되었습니다." << std::endl;
	++Ccount;
IFin:
	system("pause");
}
void Delete() {
	system("cls");
	std::cout << "삭제할 챔피언의 이름을 입력하세요 : ";
	char name[16];
	std::cin >> name;
	for (int i = 0; i < Ccount; ++i) {
		if (!(strcmp(cham[i].name, name))) {
			for (int j = i; j < Ccount; ++j) {
				memcpy(cham[j].name, cham[j + 1].name, 16);
				cham[j].hp = cham[j + 1].hp;
				cham[j].mp = cham[j + 1].mp;
				cham[j].speed = cham[j + 1].speed;
				cham[j].range = cham[j + 1].range;
				memcpy(cham[j].position, cham[j + 1].position, 10);
				--Ccount;
			}
			goto FDel;
		}
	}
	std::cout << "해당 챔피언이 이미 없습니다." << std::endl;
	goto Del;
FDel:
	std::cout << "성공적으로 삭제했습니다." << std::endl;
Del:
	system("pause");
}
void DeleteAll() {
	system("cls");
	int count = 0;
	std::cout << "삭제할 포지션을 입력하세요 : ";
	char position[10];
	std::cin >> position;
	for (int i = 0; i < Ccount; ++i) {
		if (!(strcmp(cham[i].position, position))) {
			for (int j = i; j < Ccount; ++j) {
				memcpy(cham[j].name, cham[j + 1].name, 16);
				cham[j].hp = cham[j + 1].hp;
				cham[j].mp = cham[j + 1].mp;
				cham[j].speed = cham[j + 1].speed;
				cham[j].range = cham[j + 1].range;
				memcpy(cham[j].position, cham[j + 1].position, 10);
			}
			--Ccount;
			--i;
		}
		++count;
	}
	if (count == Ccount) {
		std::cout << "해당 포지션의 챔피언이 이미 없습니다." << std::endl;
		goto Del;
	}
	std::cout << "성공적으로 삭제했습니다." << std::endl;
Del:
	system("pause");
}
void PrintAll() {
	system("cls");
	for (int i = 0; i < Ccount; ++i) {
		Print(i);
	}
	system("pause");
}
void FindMaxHP() {
	system("cls");
	int MaxHP = 0;
	for (int i = 0; i < Ccount; ++i) {
		if (MaxHP < cham[i].hp) {
			MaxHP = cham[i].hp;
		}
	}
	for (int i = 0; i < Ccount; ++i) {
		if (MaxHP == cham[i].hp) {
			Print(i);
		}
	}
	system("pause");
	
}
void SortByHP() {
	system("cls");
	for (int i = 0; i < Ccount; ++i){
		for (int j = 0; j < Ccount - 1; ++j) {
			if (cham[j].hp < cham[j + 1].hp) {
				LolDic temp = cham[j];
				cham[j] = cham[j + 1];
				cham[j + 1] = temp;
			}
		}
	}
	std::cout << "성공적으로 정렬했습니다." << std::endl;
	system("pause");
}
int main() {
	while (1) {
		system("cls");
		std::cout << "------------롤 백과사전------------" << std::endl;
		std::cout << "1. 챔피언 정보 검색" << std::endl;
		std::cout << "2. 챔피언 정보 추가" << std::endl;
		std::cout << "3. 챔피언 삭제" << std::endl;
		std::cout << "4. 라인별 챔피언 삭제" << std::endl;
		std::cout << "5. 모든 챔피언 정보 출력" << std::endl;
		std::cout << "6. 체력이 가장 높은 챔피언 검색" << std::endl;
		std::cout << "7. 최대 체력순으로 정력" << std::endl;
		std::cout << "8. 종료" << std::endl;
		std::cout << "-----------------------------------" << std::endl;
		int select;
		std::cin >> select;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(10, '\n');
		}
		switch (select)
		{
		case 1:
			Search();
			break;
		case 2:
			Insert();
			break;
		case 3:
			Delete();
			break;
		case 4:
			DeleteAll();
			break;
		case 5:
			PrintAll();
			break;
		case 6:
			FindMaxHP();
			break;
		case 7:
			SortByHP();
			break; 
		case 8:
			goto end;
		default:
			std::cout << "잘못입력하셧습니다." << std::endl;
			break;
		}
	}
end:
	std::cout << "종료합니다." << std::endl;
};
