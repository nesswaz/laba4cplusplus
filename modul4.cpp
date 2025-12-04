#define _HAS_STD_BYTE 0
#define NOMINMAX
#include "laura4.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++(1)

void matrix27(vector<vector<int>> &matrix) { //запись в консоль
    if (matrix.empty() || matrix[0].empty()) {
        cout << "Матрица пуста" << endl;
    }
    int n = matrix.size(); //размер строк
    int m = matrix[0].size(); //размер стобцов
    int mini = matrix[0][0]; // Находим минимальный элемент первой строки
    for (int j = 1; j < m; j++) { //начинаем с 1 пот. что у нас эл-т 0 0 минимальный и с ним сравниваем
        if (matrix[0][j] < mini) {
            mini = matrix[0][j];
        }
    }
    int maxi = mini; // начинаем с минимального 00 0
    for (int i = 1; i < n; i++) { // остальные столбики
        int mininstr = matrix[i][0]; 
        //проверяем по столбикам
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] < mininstr) {
                mininstr = matrix[i][j];
            }
        }
        if (mininstr > maxi) { //после циклов проверяем значения найденные 
            maxi = mininstr;
        }
    }
    cout << "Макcимальный среди минимальных элементов строк: " << maxi << endl;
    cout << endl;
}

void matrix27file(vector<vector<int>> &matrix) { //запись в консоль
    ofstream file("c.txt");
    if (file.is_open()) {   
        int n = matrix.size();
        int m = matrix[0].size();
        int mini = matrix[0][0]; // Находим минимальный элемент первой строки
        for (int j = 1; j < m; j++) {
            if (matrix[0][j] < mini) {
                mini = matrix[0][j];
            }
        }

        int maxi = mini; // начинаем с минимального элемента первой строки
        for (int i = 1; i < n; i++) { // Обрабатываем остальные строки
            int mininstr = matrix[i][0];
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] < mininstr) {
                    mininstr = matrix[i][j];
                }
            }
            if (mininstr > maxi) {
                maxi = mininstr;
            }
        }
        file << "Макcимальный среди минимальных элементов строк: " << maxi << endl;
        file.close();
        cout << "Результаты Matrix27 записаны в файл c.txt" << endl;
    }
    cout << endl;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++(2)

void matrix53(vector<vector<int>> &matrix) {
    // if (matrix.empty() || matrix[0].empty()) {
    // cout << "Матрица пуста" << endl;
    // }
    int n = matrix.size(); //строки
    int m = matrix[0].size(); //столбцы
    // Поиск столбцов с только положительными элементами
    int first = m;
    int last = m;   
    for (int j = 0; j < m; j++) { // Ищем столбцы с положительными элементами
        // Проверяем, все ли элементы в столбце положительные
        int otric = 0; // для отрицательных элементов
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] < 0) {
                otric = 1; // нашли отрицательный эл-т
                break;
            }
        }
        if (otric == 0) {
            if (first == m) {
                first = j; // нашли первый такой столбец
            }
            last = j; // обновляем последний найденный столбец
        }
    }
    // Меняем столбцы местами, если нашли разные столбцы
    if (first != m && last != m && first != last) {
        for (int i = 0; i < n; i++) {
            // Меняем элементы местами
            int temp = matrix[i][first];
            matrix[i][first] = matrix[i][last];
            matrix[i][last] = temp;
        }
        cout << "Поменяли местами столбцы " << first + 1 << " и " << last + 1 << endl;
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
        int first = m;
        int last = m; 
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
            if (first == m) {
                first = j; // нашли первый такой столбец
            }
            last = j; // обновляем последний найденный столбец
        }
    }
    
    // Меняем столбцы местами, если нашли разные столбцы
    if (first != m && last != m && first != last) {
        for (int i = 0; i < n; i++) {
            // Меняем элементы местами
            int temp = matrix[i][first];
            matrix[i][first] = matrix[i][last];
            matrix[i][last] = temp;
        }
        file << "Поменяли местами столбцы " << first + 1 << " и " << last + 1 << endl;
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
void Darray7(vector<vector<int>> &matrix) {
    int m;
    int n = matrix.size(); //размер строк
    m = n; 
    m = matrix[0].size(); //размер стобцов
    int mini = matrix[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) { //i + j = n - 1
            if (matrix[i][j] < mini) {
                mini = matrix[i][j];
            }
        }
    }
    cout << "Минимальный эл-т выше побочной диагонали: " << mini << endl;
}

void Darray7file(vector<vector<int>> &matrix) {
    ofstream file("c.txt");
        if (file.is_open()) {
                int m;
                int n = matrix.size(); //размер строк
                m = n;
                m = matrix[0].size(); //размер стобцов
                int mini = matrix[0][0];
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (matrix[i][j] < mini) {
                            mini = matrix[i][j];
                        }
                    }
                }
                file << "Минимальный эл-т выше побочной диагонали: " << mini << endl;
                file.close();
                cout << "Результаты Darray7 записаны в файл c.txt" << endl;
        }
    cout << endl;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++(4)
void Darray17(vector<vector<int>> &matrix) {
    int m, count1 = 1, count2 = 1, count = 1; //единичная, диагональная, нулевая предположим что матрицы сразу же все три типа при проверки если находим не правильные эл-ты то эти переменные обнуляемы
    int n = matrix.size(); //размер строк
    m = n;
    m = matrix[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) { //проверяем если нашли ненулевой эл-т значит не нулевая матрица
                count = 0;//за нулевую отвечает
            }

            if (i == j) { //проверяем если индексы одинак = диаг 
                if (matrix[i][j] != 1) //если диаг эл-ты не равны 1 то это не единичная матрица
                {
                    count1 = 0; //за единичную
                } 
            }
            else { //проверяем ост эл-ты
                if (matrix[i][j] != 0) { //если эл-ты не равны нулю то это не единичная
                    count1 = 0; //единичная
                    count2 = 0; //за диагональ
                }
            }
        }
    }
    if (count1 == 1) {
        cout << "2 - Единичная матрица" << endl;
    } else if (count == 1) {
        cout << "3 - Нулевая матрица" << endl;
    } else if (count2 == 1) {
        cout << "1 - Диагональная матрица" << endl;
    } else {
        cout << "Обычная матрица" << endl;
    }
}

void Darray17file(vector<vector<int>> &matrix) {
    ofstream file("c.txt");
        if (file.is_open()) {
            int m, count1 = 1, count2 = 1, count = 1; //единичная, диагональная, нулеваяю
            int n = matrix.size(); //размер строк
            m = n;
            m = matrix[0].size();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][j] != 0) { //проверяем если нашли ненулевой эл-т значит не нулевая матрица
                        count = 0;//за нулевую отвечает
                    }
                    if (i == j) { //проверяем если индексы одинак = диаг 
                        if (matrix[i][j] != 1) //если диаг эл-ты не равны 1 то это не единичная матрица
                        {
                            count1 = 0; //за единичную
                        } 
                    }
                    else { //проверяем ост эл-ты
                        if (matrix[i][j] != 0) { //если эл-ты не равны нулю то это не единичная
                            count1 = 0; //единичная
                            count2 = 0; //за диагональ
                        }
                    }
                }
            }
            if (count1 == 1) {
                file << "2 - Единичная матрица" << endl;
            } else if (count == 1) {
                file << "3 - Нулевая матрица" << endl;
            } else if (count2 == 1) {
                file << "1 - Диагональная матрица" << endl;
            } else {
                file << "Обычная матрица" << endl;
            }
            file.close();
            cout << "Результаты Darray17 записаны в файл c.txt" << endl;
        }
    cout << endl;
}

int print() {
    cout << " /\\_/\\ " << endl;    
    cout << "( o.o )" << endl;     
    cout << " > ^ < " << endl;
    return 0;
}