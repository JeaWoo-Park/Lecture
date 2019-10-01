#include <iostream>
#include <random>
#include <chrono>
void Insert_Sort(int arr[]) {
	int idx = 0;
	int tmp;
	int j;
	for (int i = 1; i < 100; ++i) {
		tmp = arr[i];
		for (j = i - 1; j >= 0; --j) {
			if (arr[j] > tmp) {
				arr[j + 1] = arr[j];
			}
			else {
				break;
			}
		}
		arr[j + 1] = tmp;
	}
}
void Bubble_Sort(int arr[]) {
	int tmp;
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 99; ++j) {
			if (arr[j + 1] < arr[j]) {
				tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}
void Selection_Sort(int arr[]) {
	int min = 500;
	int tmp = 0;
	int idx = 0;
	for (int i = 0; i < 100; ++i) {
		min = 500;
		for (int j = i; j < 100; ++j) {
			if (arr[j] < min) {
				idx = j;
				min = arr[j];
			}
		}
		tmp = arr[i];
		arr[i] = arr[idx];
		arr[idx] = tmp;
	}
}

int main() {
	std::random_device rd;
	std::default_random_engine dre(rd());
	std::uniform_int_distribution<> uid(0, 500);
	int A[100];
	int B[100];
	int C[100];
	for (int i = 0; i < 100; ++i) {
		C[i] = i + 1;
		B[i] = uid(dre);
	
		A[i] = 100 - i;
	}
	int sel;
	std::cin >> sel;
	switch (sel)
	{
	case 1:
		std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
		for (int i = 0; i < 33; ++i) {
			Insert_Sort(A);
		}
		std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
		std::chrono::nanoseconds times = end - start;
		std::cout << "A : " << times.count();
		std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
		for (int i = 0; i < 34; ++i) {
			Insert_Sort(B);
		}
		std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
times = end - start;
		std::cout << "B : " << times.count();
		std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
		for (int i = 0; i < 33; ++i) {
			Insert_Sort(C);
		}
		std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
times = end - start;
		std::cout << "C : " << times.count();
		break;
	case 2:
		std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
		for (int i = 0; i < 33; ++i) {
			Bubble_Sort(A);
		}
		std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
	 times = end - start;
		std::cout << "A : " << times.count();
		std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
		for (int i = 0; i < 34; ++i) {
			Bubble_Sort(B);
		}
		std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
		times = end - start;
		std::cout << "B : " << times.count();
		std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
		for (int i = 0; i < 33; ++i) {
			Bubble_Sort(C);
		}
		std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
		 times = end - start;
		std::cout << "C : " << times.count();
		break;
	case 3:
		std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
		for (int i = 0; i < 33; ++i) {
			Selection_Sort(A);
		}
		std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
	times = end - start;
		std::cout << "A : " << times.count();
		std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
		for (int i = 0; i < 34; ++i) {
			Selection_Sort(B);
		}
		std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
	 times = end - start;
		std::cout << "B : " << times.count();
		std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
		for (int i = 0; i < 33; ++i) {
			Selection_Sort(C);
		}
		std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
	 times = end - start;
		std::cout << "C : " << times.count();
		break;
	case 4:
		for (int i = 0; i < 100; ++i) {
			C[i] = i + 1;
			B[i] = uid(dre);
			A[i] = 100 - i;
		}
		break;
	case 5:
		return 0;
	default:
		break;
	}
	

}