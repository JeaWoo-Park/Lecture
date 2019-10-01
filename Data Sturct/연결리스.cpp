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
LolDic cham[40] = {
{ "파이크", 2300, 1265, 330, 150, "서포터" },
{ "럭스", 1935, 879.5, 330, 550, "미드" },
{ "룰루", 1783, 1285, 330, 550, "서포터" },
{ "사일러스", 2030, 1130, 340, 175, "미드" },
{ "리 신", 2015.8, 200, 345, 125, "정글" },
{ "케인", 2030, 1022, 340, 175, "정글" },
{ "잭스", 2037.8, 882.8, 350, 125, "탑" },
{ "헤카림", 2110, 956.2, 345, 175, "정글" },
{ "징크스", 2009, 1010.6, 325, 525, "원딜" },
{ "피오라", 1995, 980, 345, 150, "탑" },
{ "케이틀린", 2028.4, 908.8, 325, 650, "원딜" },
{ "쓰레쉬", 2141.52, 1021.92, 335, 450, "서포터" },
{ "자이라", 1847, 843, 340, 575, "서포터" },
{ "조이", 2124, 850, 340, 525, "미드" },
{ "오른", 2205, 1065, 335, 175, "탑" },
{ "문도", 2095.52, 0, 345, 125, "탑" },
{ "진", 2103, 1150, 330, 550, "원딜" },
{ "렉사이", 2056.2, 100, 335, 750, "정글" },
{ "미스포츈", 2088, 920.84, 325, 550, "원딜" },
{ "신드라", 2053, 990, 330, 550, "미드" }
};

int maxhp = 0;
void AddNode(List* list, Node node) {
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
void  Array2LinkedList(List* list,Node& node) {
	for (int i = 0; i < 20; ++ i) {
		node.Data = cham[i];
		AddNode(list, node);
	}
}
void Insert_SL(List* list,Node& node) {
	std::cout << "이름 : ";
	std::cin.getline(cham[0].name, 16);
	int i = 0;
	Node* n;
	for (n = list->tail->next, i = 0; i < list->count; ++i, n = n->next) {
		if (!strcmp(cham[0].name, n->Data.name)) {
			std::cout << "이미 있는 챔피언" << std::endl;
			Insert_SL(list, node);
			return;
		}
	}
	std::cout << "HP : ";
	std::cin >> cham[0].hp;
	std::cout << "MP : ";
	std::cin >> cham[0].mp;
	std::cout << "이동 속도 : ";
	std::cin >> cham[0].speed;
	std::cout << "사거리 : ";
	std::cin >> cham[0].range;
	std::cout << "포지션 : ";
	std::cin >> cham[0].position;
	node.Data = cham[0];
	std::cin.ignore(16,'\n');
	AddNode(list, node);
	
}

void Print(LolDic a) {
	std::cout << "=====================================" << std::endl;
	std::cout << "이름 : " << a.name << std::endl;

	std::cout << "HP : " << a.hp << std::endl;
	std::cout << "MP : " << a.mp << std::endl;
	std::cout << "사거리 : " << a.range << std::endl;
	std::cout << "이동 속도 : " << a.speed << std::endl;
	std::cout << "포지션 : " << a.position << std::endl;
}
void PrintAll_SL(List* list) {
	int i = 0;
	Node* n;
	for (n = list->tail->next, i = 0; i < list->count;++i ,n = n->next) {
		Print(n->Data);
	}
}
List* CreateList() {
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
void Delete_SL(List* list) {
	char name[16];
	std::cout << "이름 : ";
	std::cin.getline(name, 16);
	int i = 0;
	Node* n;
	for (n = list->tail->next, i = 0; i < list->count; ++i, n = n->next) {
		if (!strcmp(name, n->Data.name)) {
			if (n != list->tail) {
				n->prev->next = n->next;
				n->next->prev = n->prev;
				n = NULL;
			}
			else if(n == list->tail) {
				n->prev->next = n->next;
				n->next->prev = n->prev;
				list->tail = n->prev;
				n = NULL;
			}
			list->count--;
			break;
		}
	}
}
void DeleteAll_SL(List* list) {
	int num=list->count;
	char name[16];
	std::cout << "포지션 : ";
	std::cin.getline(name, 16);
	int i = 0;
	Node* n;
	for (n = list->tail->next, i = 0; i < list->count; ++i, n = n->next) {
		if (!strcmp(name, n->Data.position)) {
			if (n != list->tail) {
				n->prev->next = n->next;
				n->next->prev = n->prev;
				n = n->prev;
				list->count--;
			}
			else if (n == list->tail) {
				n->prev->next = n->next;
				n->next->prev = n->prev;
				list->tail = n->prev;
				n = list->tail;
				list->count--;
			}
		
			
		}
	}
	if (!strcmp(list->tail->Data.position, name)) {
		list->tail->prev->next = list->tail->next;
		list->tail->next->prev = list->tail->prev;
		list->count--;
	}
	if (list->count == num) {
		std::cout << "이미 없습니다." << std::endl;
	}

}
void FindMaxHP_SL(List* list) {
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
void Search_SL(List* list) {
	char name[16];
	std::cout << "이름 : ";
	std::cin.getline(name, 16);
	int i = 0;
	Node* n;
	for (n = list->tail->next, i = 0; i < list->count; ++i, n = n->next) {
		if (!strcmp(name, n->Data.name)) {
			Print(n->Data);
			break;
		}
		else {
			std::cout << "이미 없습니다." << std::endl;
		}
	}
}
void SortByHP_SL(List* list) {
	int i;
	Node* n;
	
	int min=list->tail->Data.hp;
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
}
int main() {
	List* list = CreateList();
	Node node;

	std::cout << "정렬" << std::endl;
	Array2LinkedList(list,node);
	DeleteAll_SL(list);
	Print(list->tail->Data);
}
