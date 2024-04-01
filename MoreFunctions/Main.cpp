#include <iostream>

/*Области применения статических элиментов
1. Сохранение данных внутри функции для следующего ее вызова;
2. Щадящее отношение к памяти и быстродействию программы;
3. Создание общей памяти для всех элиментов принадлежащих одному множеству (классу или структуре).
*/

//Все экземпляры перегруженной функции должны различаться между собой по набору параметров, а именно по их типам или их количеству.


int  NUM; //Глобальная переменная, по умолчанию значение 0. Пишется капсом.
const double PI = 3.1416; //Глобальная константа
int ARR[3]; //Глобальный массив

void func() {
	static int a{}; //static делает переменную статической.
	a++;
	std::cout << a << std::endl;
}
int power(int left, int right = 2) {
	int result = 1;
	for (int i = 1; i <= right; i++) {
		result *= left;
	}
	return result;
}
inline int sum(int num1, int num2) {
	return (num1 + num2);
}
int sum_arr(int arr[], const int lenght) {
	int result = 0;
	for (int i = 0; i < lenght; i++)
		result += arr[i];
	return result;
}
int max(int num1, int num2) {
	std::cout << "TWO INTS\n";
	return num1 > num2 ? num1 : num2;
}
double max(double num1, double num2) {
	std::cout << "TWO DOUBLES\n";
	return num1 > num2 ? num1 : num2;
}
char max(char sym1, char sym2) {
	std::cout << "TWO CHARS\n";
	return sym1 > sym2 ? sym1 : sym2;
}
int max(int num1, int num2, int num3) {
	std::cout << "THREE INTS\n";
	return max(max(num1, num2), num3);
}

template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n{}, m{};
	//Области видимости данных
	std::cout << "NUM = " << NUM << std::endl;
	std::cout << "PI = " << PI << std::endl;

	//Параметры по умолчанию 
	std::cout << "7^2 = " << power(7) << std::endl;
	std::cout << "4^3 = " << power(4, 3) << std::endl;
	std::cout << "5^2 = " << power(5) << std::endl;
	std::cout << "10^5 = " << power(10, 5) << std::endl;

	//Встраиваемая функция
	std::cout << "Введите два числа -> ";
	std::cin >> n >> m;
	std::cout << n << " + " << m << " = " << sum(n, m) << std::endl;

	//Перегруженные функции
	std::cout << max(7, 15) << std::endl;
	std::cout << max(5.4, 5.04) << std::endl;
	std::cout << max('k', '0') << std::endl;
	std::cout << max(7, 42, 15) << std::endl;

	//Шаблонная функция

	const int size = 5;
	int arr[size]{ 7, 15, 42, 105, -77 };
	std::cout << " Массив: \n";
	print_arr(arr, size);







	return 0;
}