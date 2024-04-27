#include <iostream>
//Шаблонный массив.
template <typename T>
void fill_arr(T arr[], int const length, int left, int right) {
	srand(time(NULL));
	std::cout << "{ ";
	for (int i = 0; i < length; i++) {
		arr[i] = rand() % (right - left) + left;
		std::cout << *(arr + i) << ", ";
	}
	std::cout << "\b\b }\n";
}
template <typename T>
void print_arr(T arr[], int const length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}

//Задача 1. Максамальное число.
void number_max(int& num1, int& num2, int& num3) {
	int max = num1;
	max = max > num2 ? max : num2;
	max = max > num3 ? max : num3;
	num1 = max;
	num2 = max;
	num3 = max;
}

//Задача 2. Ввывод отрицательного чиисла из массива.
int& neg(int arr[], int const length) {
	for (int i = 0; i < length; i++)
		if (arr[i] < 0)
			return *(arr + i);
	return *(arr);
}
//Задача 3. Обнуление элементов второго массива.
template <typename T>
void two_mas_zero(T arr1[], int const length1, T arr2[], int const length2) {
	for (int i = 0; i < length1; i++)
		for (int j = 0; j < length2; j++)
			if (*(arr1 + i) == *(arr2 + j))
				*(arr2 + j) = 0;
}


int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	//Задача 1. Максамальное число.
	std::cout << "Задача 1.\n";
	int a = 3, b = 5, c = 6;
	std::cout << "Не измененные числа:\n";
	std::cout << a << ' ' << b << ' ' << c << std::endl;
	std::cout << "Максимальное число:\n";
	number_max(a, b, c);
	std::cout << a << ' ' << b << ' ' << c << std::endl;

	//Задача 2. Ввывод отрицательного чиисла из массива.
	std::cout << "Задача 1.\n";
	const int size = 6;
	int arr[size];
	std::cout << "Массив:\n";
	fill_arr(arr, size, -1, 10);
	if (neg(arr, size) > 0)
		std::cout << "В массиве нет отрицательных элементов.\n";
	else
		std::cout << "Первый отрицательный элемент -> " << neg(arr, size) << std::endl;

	//Задача 3. Обнуление элементов второго массива.
	std::cout << "Задача 3.\n";
	int const size1 = 7;
	int arr1[size1]{ 2, 4, 8, 4, 2, 0, 9 };
	int const size2 = 6;
	int arr2[size2]{ 2, 5, 6, 4, 7, 1 };
	std::cout << "Массив 1:\n";
	print_arr(arr1, size1);
	std::cout << "Массив 2:\n";
	print_arr(arr2, size2);
	std::cout << "Массив с обнулением:\n";
	two_mas_zero(arr1, size1, arr2, size2);
	print_arr(arr2, size2);


	return 0;
}