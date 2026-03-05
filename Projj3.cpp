
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <windows.h> 

using namespace std;

void printMatrix(int mat[][10], int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << setw(4) << mat[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void printMatrixFloat(float mat[][3]) {
	cout << fixed << setprecision(2);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << setw(8) << mat[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void insertSort(int* arr, int size) {
	int* end = arr + size;
	for (int* i = arr + 1; i < end; i++) {
		int key = *i;
		int* j = i - 1;
		while (j >= arr && *j > key) {
			*(j + 1) = *j;
			j--;
		}
		*(j + 1) = key;
	}
}


float determinant33(float mat[][3]) {
	return mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) - mat[0][1] * (mat[1][0] * mat[2][2] -
		mat[1][2] * mat[2][0]) + mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
}
bool inverseMatrix33(float mat[][3], float inv[][3]) {
	float det = determinant33(mat);
	cout << "1.Определитель матрицы: " << det << endl;
	if (fabs(det) < 0.00001) {
		cout << "Определитель равен 0, обратной матрицы не существует" << endl;
		return false;
	}
	float adj[3][3];
	adj[0][0] = (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]);
	adj[0][1] = -(mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]);
	adj[0][2] = (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
	adj[1][0] = -(mat[0][1] * mat[2][2] - mat[0][2] * mat[2][1]);
	adj[1][1] = (mat[0][0] * mat[2][2] - mat[0][2] * mat[2][0]);
	adj[1][2] = -(mat[0][0] * mat[2][1] - mat[0][1] * mat[2][0]);
	adj[2][0] = (mat[0][1] * mat[1][2] - mat[0][2] * mat[1][1]);
	adj[2][1] = -(mat[0][0] * mat[1][2] - mat[0][2] * mat[1][0]);
	adj[2][2] = (mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]);
	cout << "2.Союзная матрица (траспонированная): " << endl;
	printMatrixFloat(adj);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			inv[i][j] = adj[i][j] / det;
		}
	}
	cout << "3.Обратная матрица:" << endl;
	return true;
}
int main() {
	setlocale(LC_ALL, "RU");
	srand(time(0));
	cout << "===== ОСНОВНАЯ РАБОТА =====" << endl;
	int N;
	cout << "Введите порядок матрицы N (6, 8 или 10): ";
	cin >> N;
	int mat1[10][10] = { 0 };
	int mat2[10][10] = { 0 };

	cout << "\n===Пункт 1: Заполнение змейкой ===" << endl;
	cout << "Случайные числа от 1 до " << N * N << endl;
	for (int col = 0; col < N; col++) {
		if (col % 2 == 0) {
			for (int row = 0; row < N; row++) {
				mat1[row][col] = rand() % (N * N) + 1;
				system("cls");
				cout << "ЗМЕЙКА" << endl;
				printMatrix(mat1, N);
				Sleep(200);
			}
		}
		else {
			for (int row = N - 1; row >= 0; row--) {
				mat1[row][col] = rand() % (N * N) + 1;
				system("cls");
				cout << "ЗМЕЙКА" << endl;
				printMatrix(mat1, N);
				Sleep(200);
			}
		}
	}
	cout << "\nИтоговая матрица змейкой: " << endl;
	printMatrix(mat1, N);

	cout << "\n=== Пункт 1: Заполнение спиралью ===" << endl;
	cout << " Случайные числа от 1 до " << N * N << endl;
	int top = 0, bottom = N - 1, left = 0, right = N - 1;
	while (top <= bottom && left <= right) {
		for (int i = left; i <= right; i++) {
			mat2[top][i] = rand() % (N * N) + 1;
			system("cls");
			cout << "СПИРАЛЬ" << endl;
			printMatrix(mat2, N);
			Sleep(200);
		}
		top++;
		for (int i = top; i <= bottom; i++) {
			mat2[i][right] = rand() % (N * N) + 1;
			system("cls");
			cout << "СПИРАЛЬ" << endl;
			printMatrix(mat2, N);
			Sleep(200);
		}
		right--;
		if (top <= bottom) {
			for (int i = right; i >= left; i--) {
				mat2[bottom][i] = rand() % (N * N) + 1;
				system("cls");
				cout << "СПИРАЛЬ" << endl;
				printMatrix(mat2, N);
				Sleep(200);
			}
			bottom--;
		}
		if (left <= right) {
			for (int i = bottom; i >= top; i--) {
				mat2[i][left] = rand() % (N * N) + 1;
				system("cls");
				cout << "СПИРАЛЬ" << endl;
				printMatrix(mat2, N);
				Sleep(200);
			}
			left++;
		}
	}
	system("cls");
	cout << "\n=== Результаты заполнения матриц ===" << endl;
	cout << "1. Матрица заполненная змейкой" << endl;
	printMatrix(mat1, N);
	cout << "2. Матрица заполненная спиралью" << endl;
	printMatrix(mat2, N);
	int mat[10][10] = { 0 };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			mat[i][j] = mat2[i][j];
		}
	}
	cout << "\n=== Пункт 2: Перестановка блоков ===" << endl;
	int half = N / 2;
	char blockChoice;
	cout << "Выберите тип перестановки (a, b, c, или d): ";
	cin >> blockChoice;
	int temp[10][10];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j] = mat[i][j];
		}
	}
	switch (blockChoice) {
	case 'a':
		cout << "Вариант a: обмен по часовой" << endl;
		for (int i = 0; i < half; i++) {
			for (int j = 0; j < half; j++) {
				mat[i][j + half] = temp[i][j];
				mat[i + half][j + half] = temp[i][j + half];
				mat[i + half][j] = temp[i + half][j + half];
				mat[i][j] = temp[i + half][j];
			}
		}
		break;
	case 'b':
		cout << "Вариант b: обмен крест-накрест" << endl;
		for (int i = 0; i < half; i++) {
			for (int j = 0; j < half; j++) {
				swap(mat[i][j], mat[i + half][j + half]);
				swap(mat[i][j + half], mat[i + half][j]);
			}
		}
		break;
	case 'c':
		cout << "Вариант c: вертикальный обмен" << endl;
		for (int i = 0; i < half; i++) {
			for (int j = 0; j < half; j++) {
				swap(mat[i][j], mat[i + half][j]);
				swap(mat[i][j + half], mat[i + half][j + half]);
			}
		}
		break;
	case 'd':
		cout << "Вариант d: горизонтальный обмен" << endl;
		for (int i = 0; i < half; i++) {
			for (int j = 0; j < half; j++) {
				swap(mat[i][j], mat[i][j + half]);
				swap(mat[i + half][j], mat[i + half][j + half]);
			}
		}
		break;
	}
	cout << "Матрица после перестановки блоков:" << endl;
	printMatrix(mat, N);

	cout << "=== Пункт 3: Сортировка всех элементов ===" << endl;
	cout << "Матрица ДО сортировки" << endl;
	printMatrix(mat, N);
	int flat[100];
	int index = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			flat[index] = mat[i][j];
			index++;
		}
	}
	insertSort(flat, N * N);

	index = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			mat[i][j] = flat[index];
			index++;
		}
	}
	cout << "Матрица ПОСЛЕ сортировки:" << endl;
	printMatrix(mat, N);

	cout << "=== Пункт 4: Операции с элементами матрицы ===" << endl;

	char operation;
	double value;

	cout << "Введите число: ";
	cin >> value;
	cout << "Выберите операцию (+, -, *, /): ";
	cin >> operation;

	cout << "Матрица до операции:" << endl;
	printMatrix(mat, N);

	switch (operation) {
	case '+':
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				mat[i][j] += value;
			}
		}
		break;
	case '-':
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				mat[i][j] -= value;
			}
		}
		break;
	case '*':
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				mat[i][j] *= value;
			}
		}
		break;
	case '/':
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				mat[i][j] /= value;
			}
		}
		break;
	}
	cout << "Матрица после операции:" << endl;
	printMatrix(mat, N);

	cout << "\n ИДЗ: Нахождение обратной матрицы " << endl;

	float matrix33[3][3];
	float inverse33[3][3];

	cout << "Исходная матрица 3 на 3 (случайные числа от 1 до 100):" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix33[i][j] = rand() % 100 + 1;
		}
	}
	printMatrixFloat(matrix33);
	cout << "Поиск обратной матрицы..." << endl;
	if (inverseMatrix33(matrix33, inverse33)) {
		printMatrixFloat(inverse33);
	}
	return 0;
}


