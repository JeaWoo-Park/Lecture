#include <fstream>
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>

void save()
{
	// ������ ������ ����. --���ٿ� ���� ���� ����� �Ѵ�
	std::ofstream out("2018 2�б� C++ ���ǳ���.txt", std::ios::app);

	// �о�� ������ ����
	std::ifstream in("�ҽ�.cpp");

	// ������ ��¥�� ���Ͽ� ������� (495��)
	auto tp = std::chrono::system_clock::now();	//����ð�
	auto t = std::chrono::system_clock::to_time_t(tp); 	//�ð����·� ��ȯ
	std::string date = ctime(&t);

	out << "-----------------------------------" << std::endl;
	out << date << std::endl;
	out << "-----------------------------------" << std::endl;

	char c;

	while (in.get(c))
		out.put(c);

	in.close();
	out.close();
}
