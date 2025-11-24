#define _HAS_STD_BYTE 0
#define NOMINMAX
#include "laura4.h"
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
    matrix.resize(n);
    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);
    }
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << "Матрица заполнена с клавиатуры!" << endl;
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
    int n, m;
    cout << "Введите размер массива n * m" << endl;
    cout << "Введите количество строк: " << endl;
    cin >> n;
    cout << "Введите количество столбцов: " << endl;
    cin >> m;
    matrix.resize(n);
    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);
    }
    srand(time(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % 201 - 100; //-100 до 100
        }
    }
    cout << "Матрица заполнена случайными числами!" << endl;
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
    cout << "Матрица заполнена из файла!" << endl;
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
    cout << "Матрица очищена!" << endl;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++(1)

void matrix27(vector<vector<int>> &matrix) { //запись в консоль
    if (matrix.empty() || matrix[0].empty()) {
        cout << "Матрица пуста" << endl;
    }
    int n = matrix.size();
    int m = matrix[0].size();
    int minFirst = matrix[0][0]; // Находим минимальный элемент первой строки
    for (int j = 1; j < m; j++) {
        if (matrix[0][j] < minFirst) {
            minFirst = matrix[0][j];
        }
    }
    int maxOfMin = minFirst; // начинаем с минимального элемента первой строки
    for (int i = 1; i < n; i++) { // Обрабатываем остальные строки
        int minInRow = matrix[i][0];
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] < minInRow) {
                minInRow = matrix[i][j];
            }
        }
        if (minInRow > maxOfMin) {
            maxOfMin = minInRow;
        }
    }
    cout << "Макcимальный среди минимальных элементов строк: " << maxOfMin << endl;
    cout << endl;
}

void matrix27file(vector<vector<int>> &matrix) { //запись в консоль
    ofstream file("c.txt");
    if (file.is_open()) {   
        int n = matrix.size();
        int m = matrix[0].size();
        int minFirst = matrix[0][0]; // Находим минимальный элемент первой строки
        for (int j = 1; j < m; j++) {
            if (matrix[0][j] < minFirst) {
                minFirst = matrix[0][j];
            }
        }

        int maxOfMin = minFirst; // начинаем с минимального элемента первой строки
        for (int i = 1; i < n; i++) { // Обрабатываем остальные строки
            int minInRow = matrix[i][0];
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] < minInRow) {
                    minInRow = matrix[i][j];
                }
            }
            if (minInRow > maxOfMin) {
                maxOfMin = minInRow;
            }
        }
        file << "Макcимальный среди минимальных элементов строк: " << maxOfMin << endl;
        file.close();
        cout << "Результаты Matrix27 записаны в файл c.txt" << endl;
    }
    cout << endl;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++(2)

void matrix53(vector<vector<int>> &matrix) {
    if (matrix.empty() || matrix[0].empty()) {
    cout << "Матрица пуста" << endl;
    }
    int n = matrix.size(); //строки
    int m = matrix[0].size(); //столбцы
    // Поиск столбцов с только положительными элементами
    int firstCol = m;
    int lastCol = m;   
    
    
    for (int j = 0; j < m; j++) { // Ищем столбцы с положительными элементами
        // Проверяем, все ли элементы в столбце положительные
        int otric = 0; // счетчик отрицательных элементов
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] < 0) {
                otric = 1; // нашли отрицательный эл-т
                break;
            }
        }
        if (otric == 0) {
            if (firstCol == m) {
                firstCol = j; // нашли первый такой столбец
            }
            lastCol = j; // обновляем последний найденный столбец
        }
    }
    
    // Меняем столбцы местами, если нашли разные столбцы
    if (firstCol != m && lastCol != m && firstCol != lastCol) {
        for (int i = 0; i < n; i++) {
            // Меняем элементы местами
            int temp = matrix[i][firstCol];
            matrix[i][firstCol] = matrix[i][lastCol];
            matrix[i][lastCol] = temp;
        }
        cout << "Поменяли местами столбцы " << firstCol + 1 << " и " << lastCol + 1 << endl;
    } else {
        cout << "Матрица без изменений" << endl;
    }
    
    // Вывод результата
    cout << "Полученная матрица:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void matrix53file(vector<vector<int>> &matrix) {
    ofstream file("c.txt");
        if (file.is_open()) {
        int n = matrix.size();
        int m = matrix[0].size();
        int firstCol = m;
        int lastCol = m; 
        // Создаем копию матрицы чтобы не изменять оригинал
        for (int j = 0; j < m; j++) { // Ищем столбцы с положительными элементами
        // Проверяем, все ли элементы в столбце положительные
        int otric = 0; // счетчик отрицательных элементов
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] < 0) {
                otric = 1; // нашли отрицательный эл-т
                break;
            }
        }

        if (otric == 0) {
            if (firstCol == m) {
                firstCol = j; // нашли первый такой столбец
            }
            lastCol = j; // обновляем последний найденный столбец
        }
    }
    
    // Меняем столбцы местами, если нашли разные столбцы
    if (firstCol != m && lastCol != m && firstCol != lastCol) {
        for (int i = 0; i < n; i++) {
            // Меняем элементы местами
            int temp = matrix[i][firstCol];
            matrix[i][firstCol] = matrix[i][lastCol];
            matrix[i][lastCol] = temp;
        }
        file << "Поменяли местами столбцы " << firstCol + 1 << " и " << lastCol + 1 << endl;
    } else {
        file << "Матрица без изменений" << endl;
    }
    
    // Вывод результата
    file << "Полученная матрица:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            file << matrix[i][j] << " ";
        }
        file << endl;
    }
    file.close();
    cout << "Результаты Matrix53 записаны в файл c.txt" << endl;
    }
    cout << endl;
}

//---------------------------------------------------------------------------------------(3)