#include <iostream>
struct LolDic
{
	char name[16];
	double hp, mp;
	int speed, range;
	char position[7];
};
struct Node {
	LolDic Data;
	Node* next;
	Node* prev;
};
struct List {
	int count;
	Node* tail;
};
int maxhp = 0;
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
List* Createlist();
void AddNode(List*, Node&);
void Print(LolDic);
void PrintAll_DL(List*);
void Insert_DL(List*,Node&);
void Search_DL(List*);
void FindMaxHP_DL(List*);
void SortByHP_DL(List*);
void Delete_DL(List*,char*);
void DeleteAll_DL(List*);
void Array2LinkedList(List*,Node&);

void Array2LinkedList(List* list, Node& node) {
	for (int i = 0; i < 20; ++i) {
		node.Data = cham[i];
		AddNode(list, node);
	}
}
void AddNode(List* list,Node& node) {
	Node* preNode = list->tail;
	Node* newNode = new Node;

	newNode->Data = node.Data;
	if (list->count == 0) {
		newNode->next = newNode;
		newNode->prev = newNode;
		list->tail = newNode;
	}
	else {
		preNode->next->prev = newNode;
		newNode->next = preNode->next;
		preNode->next = newNode;
		newNode->prev = preNode;
		list->tail = newNode;
	}
	list->count++;
}

List* Createlist() {
	List* list = new List;
	if (list == NULL) {
		std::cout << "erro" << std::endl;
	}
	else {
		list->count = 0;
		list->tail = NULL;
	}
	return list;
}
void Print(LolDic a) {
	std::cout << "=====================================" << std::endl;
	std::cout << "�̸� : " << a.name << std::endl;
	std::cout << "HP : " << a.hp << std::endl;
	std::cout << "MP : " << a.mp << std::endl;
	std::cout << "��Ÿ� : " << a.range << std::endl;
	std::cout << "�̵� �ӵ� : " << a.speed << std::endl;
	std::cout << "������ : " << a.position << std::endl;
}
void PrintAll_DL(List* list) {
	int i;
	Node* n;
	if (list->tail == NULL) {
		return;
	}
	for (n = list->tail->next, i = 0; i < list->count; n = n->next, ++i) {
		Print(n->Data);
	}
}
void Search_DL(List* list) {
	char name[16];
	std::cout << "�̸� : ";
	std::cin.getline(name, 16);
	int i;
	Node* n;
	for (n = list->tail->next, i = 0; i < list->count; n = n->next, ++i) {
		if (!strcmp(n->Data.name, name)) {
			Print(n->Data);
			break;
		}
		if (i == list->count - 1) {
			std::cout << "���� è�Ǿ� �Դϴ�." << std::endl;
		}
	}
}
void Insert_DL(List* list,Node& node) {
	std::cout << "�̸� : ";
	std::cin.getline(cham[0].name, 16);
	int i;
	Node* n;
	if (list->tail != NULL) {
		for (n = list->tail->next, i = 0; i < list->count; n = n->next, ++i) {
			if (!strcmp(n->Data.name, cham[0].name)) {
				std::cout << "�̹� �ִ� è�Ǿ� �Դϴ�." << std::endl;
				Insert_DL(list, node);
				return;
			}
		}
	}
	std::cout << "HP : ";
	std::cin >> cham[0].hp;
	std::cout << "MP : ";
	std::cin >> cham[0].mp;
	std::cout << "��Ÿ� : ";
	std::cin >> cham[0].range;
	std::cout << "�̵� �ӵ� : ";
	std::cin >> cham[0].speed;
	std::cout << "������ :  ";
	std::cin.ignore(16, '\n');
	std::cin.getline(cham[0].position,16);
	node.Data = cham[0];
	AddNode(list, node);
	

	SortByHP_DL(list);
	
	std::cout << "�߰� �Ϸ�" << std::endl;
}

void Delete_DL(List* list,char* name) {

	int i = 0;
	Node* n;
	for (n = list->tail->next, i = 0; i < list->count; ++i, n = n->next) {
		if (!strcmp(name, n->Data.name)) {
			if (n != list->tail) {
				n->prev->next = n->next;
				n->next->prev = n->prev;
				n = NULL;
			}
			else if (n == list->tail) {
				if (list->tail->next == list->tail) {
					list->tail = NULL;
				}
				else {
					n->prev->next = n->next;
					n->next->prev = n->prev;
					list->tail = n->prev;
					n = NULL;
					
				}
			}
			list->count--;
			break;
		}
	}

}
void DeleteAll_DL(List* list) {
	int num = list->count;
	char name[16];
	std::cout << "������ : ";
	std::cin.getline(name, 16);
	int i = 0;
	Node* n;
	for (n = list->tail->next, i = 0; i < list->count; ++i, n = n->next) {
		if (!strcmp(name, n->Data.position)) {
			Delete_DL(list, n->Data.name);
			n = n->prev;
		}
	}
	for (n = list->tail->next, i = 0; i < list->count; ++i, n = n->next) {
		if (!strcmp(name, n->Data.position)) {
			Delete_DL(list, n->Data.name);
			n = n->prev;
		}
	}
	if (!strcmp(name, list->tail->Data.position)) {
		Delete_DL(list,list->tail->Data.name);
	}
	if (list->count == num) {
		std::cout << "�̹� �����ϴ�." << std::endl;
	}

	std::cout << "���� �Ϸ�" << std::endl;
}

void FindMaxHP_DL(List* list) {
	int i;
	Node* n;
	int max = 0;
	for (n = list->tail->next, i = 0; i < list->count; ++i, n = n->next) {
		if (max < n->Data.hp) {
			max = n->Data.hp;
			maxhp = max;
		}
	}
	for (n = list->tail->next, i = 0; i < list->count; ++i, n = n->next) {
		if (max == n->Data.hp) {
			Print(n->Data);
		}
	}
}

void SortByHP_DL(List* list) {
	int i;
	Node* n;

	int min = list->tail->Data.hp;
	for (n = list->tail->next, i = 0; i < list->count; ++i, n = n->next) {
		if (min > n->Data.hp) {
			min = n->Data.hp;
		}
	}
	for (n = list->tail->next, i = 0; i < list->count; ++i, n = n->next) {
		if (min == n->Data.hp) {
			list->tail = n;
			break;
		}
	}
	for (int j = 0; j < list->count; ++j) {
		for (n = list->tail->next, i = 0; i < list->count - j; ++i, n = n->next) {
			if (n->Data.hp < n->next->Data.hp) {
				LolDic temp = n->Data;
				n->Data = n->next->Data;
				n->next->Data = temp;
			}
		}
	}

	std::cout << "���� �Ϸ�" << std::endl;
}
int main() {
	List* list = Createlist();
	Node node;
	Array2LinkedList(list, node);
	int selection;
	char name[16];
	while (1) {
		system("cls");
		std::cout << "=====================================" << std::endl;
		std::cout << "1. �˻�" << std::endl;
		std::cout << "2. �߰�" << std::endl;
		std::cout << "3. ����" << std::endl;
		std::cout << "4. ���λ���" << std::endl;
		std::cout << "5. ��ü ���" << std::endl;
		std::cout << "6. �ִ� ���" << std::endl;
		std::cout << "7. ����" << std::endl;
		std::cout << "8. ����" << std::endl;
		std::cout << "=====================================" << std::endl;
		std::cin >> selection;
		switch (selection)
		{
		case 1:
			system("cls");
			std::cin.ignore(16, '\n');
			Search_DL(list);
			system("pause");
			break;
		case 2:
			system("cls");
			std::cin.ignore(16, '\n');
			Insert_DL(list, node);
			system("pause");
			break;
		case 3:
			system("cls");
			std::cin.ignore(16, '\n');
			std::cout << "�̸� : ";
			std::cin.getline(name, 16);
			Delete_DL(list,name);
			std::cout << "���� �Ϸ�" << std::endl;
			system("pause");
			break;
		case 4:
			system("cls");
			std::cin.ignore(16, '\n');
			DeleteAll_DL(list);
			system("pause");
			break;
		case 5:
			system("cls");
			std::cin.ignore(16, '\n');
			PrintAll_DL(list);
			system("pause");
			break;
		case 6:
			system("cls");
			std::cin.ignore(16, '\n');
			FindMaxHP_DL(list);
			system("pause");
			break;
		case 7:
			system("cls");
			std::cin.ignore(16, '\n');
			SortByHP_DL(list);
			system("pause");
			break;
		case 8:
			return 0;
		default:
			std::cout << "�߸� �Է��ϼ˽��ϴ�." << std::endl;
			system("pause");
			break;
		}
	
	}
}