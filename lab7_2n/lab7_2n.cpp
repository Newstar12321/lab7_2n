/*
2. Дан массив размера N.
Возвести в квадрат все его локальные минимумы
(то есть числа, меньшие своих соседей).
*/

#include <iostream>

using namespace std;

void ar_in(size_t, int*);
void ar_sqrt(size_t, int*);
void ar_copy(size_t, int*, int*);
void ar_out(size_t, int*);

int main()
{
	setlocale(LC_ALL, "ru");

	size_t n;
	cout << "Введите размер матрицы: ";
	cin >> n;

	if (n == 0)
	{
		cerr << "Ошибка! Недопустимое значение";
		return 1;
	}

	int* array = new int[n];
	ar_in(n, array);

	switch (n)
	{
	case 1:
		break;
	case 2:
		if (array[0] < array[1])
		{
			array[0] *= array[0];
		}
		else
		{
			array[1] *= array[1];
		}
		break;
	default:
		ar_sqrt(n, array);
		break;
	}

	ar_out(n, array);

	delete[] array;
}

void ar_in(size_t n, int* array)
{
	cout << "Введите значения матрицы:\n";
	for (size_t i = 0; i < n; i++)
	{
		cin >> array[i];
	}
}

void ar_copy(size_t n, int* array, int* new_array)
{
	for (size_t i = 0; i < n; i++)
	{
		new_array[i] = array[i];
	}
}

void ar_sqrt(size_t n, int* array)
{
	int* new_array = new int[n];
	ar_copy(n, array, new_array);

	if (new_array[0] < new_array[1])
	{
		array[0] *= array[0];
	}

	for (size_t i = 1; i < n - 1; i++)
	{
		int a0 = new_array[i - 1], a1 = new_array[i], a2 = new_array[i + 1];
		if ((a0 > a1) && (a1 < a2))
		{
			array[i] *= array[i];
		}
	}

	if (new_array[n - 1] < new_array[n - 2])
	{
		array[n - 1] *= array[n - 1];
	}

	delete[] new_array;
}

void ar_out(size_t n, int* array)
{
	cout << "Массив после преобразований:\n";
	for (size_t i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
}