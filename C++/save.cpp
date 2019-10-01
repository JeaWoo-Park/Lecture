#include <fstream>
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>

void save()
{
	// 저장할 파일을 연다. --덧붙여 쓰기 모드로 열어야 한다
	std::ofstream out("2018 2학기 C++ 강의내용.txt", std::ios::app);

	// 읽어올 파일을 연다
	std::ifstream in("소스.cpp");

	// 저장한 날짜도 파일에 기록하자 (495쪽)
	auto tp = std::chrono::system_clock::now();	//현재시간
	auto t = std::chrono::system_clock::to_time_t(tp); 	//시간형태로 변환
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
