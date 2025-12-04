#define _HAS_STD_BYTE 0
#define NOMINMAX
#include "laura42.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
// Функция для заполнения матрицы с клавиатуры
void fillKeyboard(vector<vector<int>> &matrix) {
    clearMatrix(matrix);
    int n, m;
    cout << "Введите размер массива n * m" << endl;
    cout << "Введите количество строк: " << endl;
    cin >> n;
    cout << "Введите количество столбцов: " << endl;
    cin >> m;
    matrix.resize(n); //изменяет размер вектора до n элементов
    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);
    }
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << "Матрица заполнена с клавиатуры" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Функция для заполнения матрицы случайными числами
void fillRandom(vector<vector<int>> &matrix) {
    clearMatrix(matrix);
    int n, m, a, b;
    cout << "Введите размер массива n * m" << endl;
    cout << "Введите количество строк: " << endl;
    cin >> n;
    cout << "Введите количество столбцов: " << endl;
    cin >> m;
    cout << "Введите диапозон для рандом ввода a и b" << endl;
    cin >> a >> b;
    matrix.resize(n); //создает строчки пустые потом по номеру создаем столбцы 
    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);
    }
    srand(time(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % (b - a + 1) + a; //-100 до 100
        }
    }
    cout << "Матрица заполнена случайными числами" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

//Функция заполнения матрицы из файла
void fill_file(vector<vector<int>> &matrix, string filename) {
    int n, m;
    ifstream file(filename);
    if (file.is_open()) {
        file >> n >> m;
        matrix.resize(n);
        for (int i = 0; i < n; i++) {
            matrix[i].resize(m);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                file >> matrix[i][j];
            }
        }
        file.close();
    }
    else {
        cout << "Error: файл не открывается" << endl;
    }
    cout << "Матрица заполнена из файла" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Функция для очистки матрицы
void clearMatrix(vector<vector<int>> &matrix) {
    matrix.clear();
    cout << "Матрица очищена" << endl;
}

void matrixi(vector<vector<int>> &matrix, int n, int m) {
    std::cout << "\nИсходная матрица: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

}
