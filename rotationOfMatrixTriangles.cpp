#include <iostream>
#include "rotationOfMatrixTriangles.h"

using namespace std;

int rotate() {
	setlocale(LC_ALL, "Russian");
	int size;
	cout << "Введите размер массива" << endl;
	cin >> size;
	while (size % 2 == 0) {
		cout << "Размер не соответствует условию задачи. Повторите ввод" << endl;
		cin >> size;
	}
	int **array = new int*[size];
	for (int row = 0; row < size; row++) {
		array[row] = new int[size];
	}
	cout << "Введите массив размерностью " << size << " x " << size << endl;
	for (int row = 0; row < size; ++row) {
		for (int column = 0; column < size; ++column) {
			cin >> array[row][column];
		}
	}
	cout << endl << "Исходный массив" << endl;
	for (int row = 0; row < size; ++row) {
		for (int column = 0; column < size; ++column) {
			cout << array[row][column] << " ";
		}
		cout << endl;
	}
	int tmp;
	for (int row = 0; row < size / 2; ++row) {
		for (int column = row; column < size - 1 - row; ++column) {
			if (row == column || row + column == size + 1)
				continue;
			else {
				tmp = array[row][column];
				array[row][column] = array[size - column - 1][row];
				array[size - column - 1][row] = array[size - row - 1][size - column - 1];
				array[size - row - 1][size - column - 1] = array[column][size - row - 1];
				array[column][size - row - 1] = tmp;
			}
		}
	}
	cout << endl << "Развернутый массив" << endl;
	for (int row = 0; row < size; ++row) {
		for (int column = 0; column < size; ++column) {
			cout << array[row][column] << " ";
		}
		cout << endl;
	}
	for (int row = 0; row < size; ++row)
		delete[] array[row];
	delete[] array;
	system("pause");
	return 0;
}
