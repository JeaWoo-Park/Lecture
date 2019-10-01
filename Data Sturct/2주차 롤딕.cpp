#include <iostream>
struct LolDic
{
	char name[16];
	double hp, mp;
	int speed, range;
	char position[16];
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
{ "¡ũ��", 2009, 1010.6, 325, 525, "����" },
{ "�ǿ���", 1995, 980, 345, 150, "ž" },
{ "����Ʋ��", 2028.4, 908.8, 325, 650, "����" },
{ "������", 2141.52, 1021.92, 335, 450, "������" },
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
int erro = 0;


int Mycmp(const char* str1, const char* str2) {
	while (1)
	{
		if (*str1 != *str2) break;
		if (*str1 == '\0') break;
		str1++;
		str2++;
	}
	if (*str1 == *str2) return 1;
	return 0;
}
void Print(int i) {
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "�̸� : " << cham[i].name << std::endl;
	std::cout << "HP : " << cham[i].hp << std::endl;
	std::cout << "MP : " << cham[i].mp << std::endl;
	std::cout << "�̵� �ӵ� : " << cham[i].speed << std::endl;
	std::cout << "��Ÿ� : " << cham[i].range << std::endl;
	std::cout << "������ : " << cham[i].position << std::endl;
	std::cout << "-----------------------------------" << std::endl;
}
void Search_R(char* name,int i) {

	if (i == Ccount) {
		std::cout << "ã���ô� è�Ǿ��� �����ϴ�." << std::endl;
	}

 	if (Mycmp(cham[i].name, name) == 1) {
		Print(i);
	}
	else if (Mycmp(cham[i].name, name) == 0 && i != Ccount) {
		Search_R(name, i + 1);
	}
}
void Insert() {
	system("cls");
	std::cout << "è�Ǿ��� ������ �߰��մϴ�." << std::endl;
	std::cout << "�̸� : ";
	std::cin.getline(cham[Ccount].name,16);
	for (int i = 0; i < Ccount; ++i) {

		if (Mycmp(cham[i].name, cham[Ccount].name)) {
			
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
void Delete(char* name , int i) {
		if (Mycmp(name, cham[i].name)) {
			for (int j = i; j < Ccount; ++j) {
				memcpy(cham[j].name, cham[j + 1].name,16);
				cham[j].hp = cham[j + 1].hp;
				cham[j].mp = cham[j + 1].mp;
				cham[j].speed = cham[j + 1].speed;
				cham[j].range = cham[j + 1].range;
				memcpy(cham[j].position, cham[j + 1].position, 16);
				--Ccount;
			}
			goto FDel;
		}
		if (Mycmp(name, cham[i].name) == 0 && i != Ccount) {
			std::cout << "�ش� è�Ǿ��� �̹� �����ϴ�." << std::endl;
			goto Del;
		}

	
FDel:
	std::cout << "���������� �����߽��ϴ�." << std::endl;
Del:
	system("pause");
}
void DeleteAll(char* position,int i,int ccount) {
		
		if (Mycmp(position, cham[i].position)) {
			for (int j = i; j < Ccount; ++j) {
				memcpy(cham[j].name, cham[j + 1].name, 16);
				cham[j].hp = cham[j + 1].hp;
				cham[j].mp = cham[j + 1].mp;
				cham[j].speed = cham[j + 1].speed;
				cham[j].range = cham[j + 1].range;
				memcpy(cham[j].position, cham[j + 1].position, 16);
			}
			--i;
			--Ccount;	
		}
		if (Mycmp(position, cham[i].position) == 0 && i != Ccount) {
			DeleteAll(position, i + 1, ccount);
		}
		erro = 1;
		if (Ccount == ccount) {
			
			erro = 0;
		}

}
void PrintAll(int i) {
	
	if (i != Ccount) {
		Print(i);
		PrintAll(i + 1);
	}
	system("pause");
}
void FindMaxHP(int MaxHP, int i) {
	system("cls");
		if (MaxHP < cham[i].hp) {
			MaxHP = cham[i].hp;
		}
		if (i!=Ccount) {
			FindMaxHP(MaxHP, i + 1);
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
	for (int i = 0; i < Ccount; ++i) {
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
	char name[16];
	while (1) {
		system("cls");
		std::cout << "----------------------------------" << std::endl;
		std::cout << "1. è�Ǿ� �˻�" << std::endl;
		std::cout << "2. è�Ǿ�  �߰�" << std::endl;
		std::cout << "3. è�Ǿ� ����" << std::endl;
		std::cout << "4. �����Ǻ� è�Ǿ� ����" << std::endl;
		std::cout << "5. ��� è�Ǿ� ���� ���" << std::endl;
		std::cout << "6. ü���� ���� ���� è�Ǿ� �˻�" << std::endl;
		std::cout << "7. ü�¼����� ����" << std::endl;
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
			std::cin.ignore(1);
			system("cls");
			std::cout << "è�Ǿ��� �˻��մϴ�." << std::endl;
			std::cout << "�̸� : ";
			std::cin.getline(name, 16);
			Search_R(name, 0);
			system("pause");
			break;
		case 2:
			std::cin.ignore(1);
			Insert();
			break;
		case 3:
			std::cin.ignore(1);
			system("cls");
			std::cout << "è�Ǿ��� �����մϴ�." << std::endl;
			std::cout << "�̸� : ";
			std::cin.getline(name, 16);
			Delete(name, 0);
			break;
		case 4:
			std::cin.ignore(1);
			system("cls");
			std::cout << "�������� �����մϴ�. " << std::endl;
			std::cout << "������ : ";
			std::cin.getline(name, 16);
			DeleteAll(name, 0,Ccount);
			if (erro == 0) {
				std::cout << "�ش� �������� è�Ǿ��� �̹� �����ϴ�." << std::endl;
				system("pause");
				break;
			}
			std::cout << "���������� �����߽��ϴ�." << std::endl;
			system("pause");
			break;
		case 5:
			system("cls");
			std::cin.ignore(1);
			PrintAll(0);
			break;
		case 6:
			std::cin.ignore(1);
			FindMaxHP(0,0);
			break;
		case 7:
			std::cin.ignore(1);
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
