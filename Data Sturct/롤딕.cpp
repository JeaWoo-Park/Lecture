#include <iostream>
struct LolDic
{
	char name[16];
	double hp, mp;
	int speed, range;
	char position[10];
};
LolDic cham[40] = {
	{ "����ũ", 2300, 1265, 330, 150, "������" },
	{ "����", 1935, 879.5, 330, 550, "�̵�" },
	{ "���", 1783, 1285, 330, 550, "������" },
	{ "���Ϸ���", 2030, 1130, 340, 175, "�̵�" },
	{ "�� ��", 2015.8, 200, 345, 125, "����" },
	{ "����", 2030, 1022, 340, 175, "����" },
	{ "�轺", 2037.8, 882.8, 350, 125, "ž" },
	{ "��ī��", 2110, 956.2, 345, 175, "����" },
	{"¡ũ��", 2009, 1010.6, 325, 525, "����" },
	{"�ǿ���", 1995, 980, 345, 150, "ž" },
	{"����Ʋ��", 2028.4, 908.8, 325, 650, "����" },
	{"������", 2141.52, 1021.92, 335, 450, "������" },
	{ "���̶�", 1847, 843, 340, 575, "������" },
	{ "����", 2124, 850, 340, 525, "�̵�" },
	{ "����", 2205, 1065, 335, 175, "ž" },
	{ "����", 2095.52, 0, 345, 125, "ž" },
	{ "��", 2103, 1150, 330, 550, "����" },
	{ "������", 2056.2, 100, 335, 750, "����" },
	{ "�̽�����", 2088, 920.84, 325, 550, "����" },
	{ "�ŵ��", 2053, 990, 330, 550, "�̵�" }
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
	std::cout << "�̸� : "<< cham[i].name << std::endl;
	std::cout << "HP : " << cham[i].hp << std::endl;
	std::cout << "MP : " << cham[i].mp << std::endl;
	std::cout << "�̵� �ӵ� : " << cham[i].speed << std::endl;
	std::cout << "��Ÿ� : "<< cham[i].range << std::endl;
	std::cout << "������ : "<< cham[i].position << std::endl;
	std::cout << "-----------------------------------" << std::endl;
}
void Search() {
	system("cls");
	std::cout << "ã�� è�Ǿ��� �̸��� �Է��ϼ��� : ";
	char name[16];
	std::cin >> name;
	for (int i = 0; i < Ccount; ++i) {
		if (!(strcmp(cham[i].name, name))) {
			Print(i);
			goto SFin;
		}
	}
	std::cout << "ã���ô� è�Ǿ��� ������ �����ϴ�." << std::endl;
SFin:
	system("pause");
}
void Insert() {
	system("cls");
	std::cout << "è�Ǿ��� ������ �߰��մϴ�." << std::endl;
	std::cout << "�̸� : ";
	std::cin >> cham[Ccount].name;
	for (int i = 0; i < Ccount; ++i) {
		if (!(strcmp(cham[i].name, cham[Ccount].name))) {
			std::cout << "�̹� �ִ� è�Ǿ� �Դϴ�. �ٽ��Է��� �ּ���." << std::endl;
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
		std::cout << "�߸��Է��ϼ˽��ϴ�." << std::endl;
		goto HP;
	}
MP:
	std::cout << "MP : ";
	std::cin >> cham[Ccount].mp;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(10, '\n');
		std::cout << "�߸��Է��ϼ˽��ϴ�." << std::endl;
		goto MP;
	}
Speed:
	std::cout << "�̵� �ӵ� : ";
	std::cin >> cham[Ccount].speed;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(10, '\n');
		std::cout << "�߸��Է��ϼ˽��ϴ�." << std::endl;
		goto Speed;
	}
Range:
	std::cout << "��Ÿ� : ";
	std::cin >> cham[Ccount].range;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(10, '\n');
		std::cout << "�߸��Է��ϼ˽��ϴ�." << std::endl;
		goto Range;
	}
Position:
	std::cout << "������ : ";
	std::cin >> cham[Ccount].position;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(10, '\n');
		std::cout << "�߸��Է��ϼ˽��ϴ�." << std::endl;
		goto Position;
	}

	std::cout << "���������� �߰� �Ǿ����ϴ�." << std::endl;
	++Ccount;
IFin:
	system("pause");
}
void Delete() {
	system("cls");
	std::cout << "������ è�Ǿ��� �̸��� �Է��ϼ��� : ";
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
	std::cout << "�ش� è�Ǿ��� �̹� �����ϴ�." << std::endl;
	goto Del;
FDel:
	std::cout << "���������� �����߽��ϴ�." << std::endl;
Del:
	system("pause");
}
void DeleteAll() {
	system("cls");
	int count = 0;
	std::cout << "������ �������� �Է��ϼ��� : ";
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
		std::cout << "�ش� �������� è�Ǿ��� �̹� �����ϴ�." << std::endl;
		goto Del;
	}
	std::cout << "���������� �����߽��ϴ�." << std::endl;
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
	std::cout << "���������� �����߽��ϴ�." << std::endl;
	system("pause");
}
int main() {
	while (1) {
		system("cls");
		std::cout << "------------�� �������------------" << std::endl;
		std::cout << "1. è�Ǿ� ���� �˻�" << std::endl;
		std::cout << "2. è�Ǿ� ���� �߰�" << std::endl;
		std::cout << "3. è�Ǿ� ����" << std::endl;
		std::cout << "4. ���κ� è�Ǿ� ����" << std::endl;
		std::cout << "5. ��� è�Ǿ� ���� ���" << std::endl;
		std::cout << "6. ü���� ���� ���� è�Ǿ� �˻�" << std::endl;
		std::cout << "7. �ִ� ü�¼����� ����" << std::endl;
		std::cout << "8. ����" << std::endl;
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
			std::cout << "�߸��Է��ϼ˽��ϴ�." << std::endl;
			break;
		}
	}
end:
	std::cout << "�����մϴ�." << std::endl;
};
