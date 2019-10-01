#include <iostream>
#include <random>

std::random_device rd;
std::default_random_engine dre(rd());
std::uniform_int_distribution<> uid(0,200);

int sortArr[100];

void Merge(int arr[], int left, int mid, int right) {
	int left_idx = left;
	int right_idx = mid + 1;

	int sidx = left;
	while (left_idx <= mid && right_idx <=right)
	{
		if (arr[left_idx] <= arr[right_idx]) {
			sortArr[sidx] = arr[left_idx++];
		}
		else {
			sortArr[sidx] = arr[right_idx++];
		}
		sidx++;
	}
	if (left_idx > mid) {
		for (int i = right_idx; i <= right; i++, sidx++) {
			sortArr[sidx] = arr[i];
		}
	}
	else {
		for (int i = left_idx; i <= mid; i++, sidx++) {
			sortArr[sidx] = arr[i];
		}
	}
	for (int i = left; i <= right; i++) {
		arr[i] = sortArr[i];
	}

}

void MergeSort(int arr[], int left, int right) {
	if (left < right) {
		int mid = (right + left) / 2;
		
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		Merge(arr,left,mid,right);
	}
}
int main() {
	int temp;
	int arr1[10], arr2[30], arr3[50], arr4[70], arr5[100];
	for (int i = 0; i < 100; ++i) {
		if (i < 10) {
			temp = uid(dre);
			for (int j = 0; j < i; ++j) {
				if (temp == arr1[j]) {
					temp = uid(dre);
					j = 0;
				}
			}
			arr1[i] = temp;
		}
		if (i < 30) {
			temp = uid(dre);
			for (int j = 0; j < i; ++j) {
				if (temp == arr2[j]) {
					temp = uid(dre);
					j = 0;
				}
			}
			arr2[i] = temp;
		}
		if (i < 50) {
			temp = uid(dre);
			for (int j = 0; j < i; ++j) {
				if (temp == arr3[j]) {
					temp = uid(dre);
					j = 0;
				}
			}
			arr3[i] = temp;
		}
		if (i < 70) {
			temp = uid(dre);
			for (int j = 0; j < i; ++j) {
				if (temp == arr4[j]) {
					temp = uid(dre);
					j = 0;
				}
			}
			arr4[i] = temp;
		}
		if (i < 100) {
			temp = uid(dre);
			for (int j = 0; j < i; ++j) {
				if (temp == arr5[j]) {
					temp = uid(dre);
					j = 0;
				}
			}
			arr5[i] = temp;
		}
	}
	int sel;
	while (1)
	{


		std::cout << "명령어 : ";
		std::cin >> sel;
		switch (sel)
		{
		case 1:
		Print:
			std::cout << "현재 배열" << std::endl;
			std::cout << "arr1" << std::endl;
			for (int i = 0; i < 10; ++i) {
				std::cout << arr1[i] << ' ';
			}
			std::cout << std::endl;
			std::cout << "arr2" << std::endl;
			for (int i = 0; i < 30; ++i) {
				std::cout << arr2[i] << ' ';
			}
			std::cout << std::endl;
			std::cout << "arr3" << std::endl;
			for (int i = 0; i < 50; ++i) {
				std::cout << arr3[i] << ' ';
			}
			std::cout << std::endl;
			std::cout << "arr4" << std::endl;
			for (int i = 0; i < 70; ++i) {
				std::cout << arr4[i] << ' ';
			}
			std::cout << std::endl;
			std::cout << "arr5" << std::endl;
			for (int i = 0; i < 100; ++i) {
				std::cout << arr5[i] << ' ';
			}
			std::cout << std::endl;
			break;
		case 2:
			MergeSort(arr1, 0, sizeof(arr1) / sizeof(int) - 1);

			MergeSort(arr2, 0, sizeof(arr2) / sizeof(int) - 1);

			MergeSort(arr3, 0, sizeof(arr3) / sizeof(int) - 1);

			MergeSort(arr4, 0, sizeof(arr4) / sizeof(int) - 1);

			MergeSort(arr5, 0, sizeof(arr5) / sizeof(int) - 1);
			break;
		case 3:
			MergeSort(arr1, 0, sizeof(arr1) / sizeof(int) - 1);

			MergeSort(arr2, 0, sizeof(arr2) / sizeof(int) - 1);

			MergeSort(arr3, 0, sizeof(arr3) / sizeof(int) - 1);

			MergeSort(arr4, 0, sizeof(arr4) / sizeof(int) - 1);

			MergeSort(arr5, 0, sizeof(arr5) / sizeof(int) - 1);
			goto Print;
		case 4:
			std::cout << "초기화 중" << std::endl;
			for (int i = 0; i < 100; ++i) {
				if (i < 10) {
					temp = uid(dre);
					for (int j = 0; j < i; ++j) {
						if (temp == arr1[j]) {
							temp = uid(dre);
							j = 0;
						}
					}
					arr1[i] = temp;
				}
				if (i < 30) {
					temp = uid(dre);
					for (int j = 0; j < i; ++j) {
						if (temp == arr2[j]) {
							temp = uid(dre);
							j = 0;
						}
					}
					arr2[i] = temp;
				}
				if (i < 50) {
					temp = uid(dre);
					for (int j = 0; j < i; ++j) {
						if (temp == arr3[j]) {
							temp = uid(dre);
							j = 0;
						}
					}
					arr3[i] = temp;
				}
				if (i < 70) {
					temp = uid(dre);
					for (int j = 0; j < i; ++j) {
						if (temp == arr4[j]) {
							temp = uid(dre);
							j = 0;
						}
					}
					arr4[i] = temp;
				}
				if (i < 100) {
					temp = uid(dre);
					for (int j = 0; j < i; ++j) {
						if (temp == arr5[j]) {
							temp = uid(dre);
							j = 0;
						}
					}
					arr5[i] = temp;
				}
			}
			std::cout << "초기화 완료" << std::endl;
			break;
		case 5:
			std::cout << "종료 합니다." << std::endl;
			return 0;
		default:
			std::cout << "잘못된 입력 입니다." << std::endl;
			break;
		}
	}
}