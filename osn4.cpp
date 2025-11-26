#define _HAS_STD_BYTE 0
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN 
#include <iostream>
#include <vector>
#include <string>
#include "laura4.h"
#include <windows.h> 

using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    vector<vector<int>> matrix;
    int choice;
    do {
        cout << "1. Заполнить двумерный массив с клавиатуры" << endl;
        cout << "2. Заполнить двумерный массив случайными числами" << endl;
        cout << "3. Заполнить двумерный массив из файла" << endl;
        cout << "4. Задание Matrix27" << endl;
        cout << "5. Задание Matrix53" << endl;
        cout << "6. Задание DArray7" << endl;
        cout << "7. Задание DArray17" << endl;
        cout << "999. Выход из программы" << endl;
        cin >> choice;
        switch (choice) {
            case 1: {
                fillKeyboard(matrix);
                break;
            }
            case 2: {
                fillRandom(matrix);
                break;
            }
            case 3: {
                clearMatrix(matrix);
                string filename;
                cout << "Введите название файла: ";
                cin >> filename;
                fill_file(matrix, filename);
                break;
            }
            case 4: {
                matrix27(matrix);
                matrix27file(matrix);
                break;
            }
            case 5: {
                matrix53(matrix);
                matrix53file(matrix);
                break;
            }
            case 6: {
                Darray7(matrix);
                Darray7file(matrix);
            }
            case 7: {
                Darray17(matrix);
                Darray17file(matrix);
            }
            case 999: {
                cout << "Выход из программы" << endl;
                break;
            }
            default:
                cout << "Введены неверные данные" << endl;
                break;
        }
    } while (choice != 999);
    return 0;
}
//g++ osn4.cpp modul4.cpp -o program.exe
/*
matrix - это vector<vector<int>> (вектор векторов)
resize(n) устанавливает, что во внешнем векторе будет n элементов
Каждый элемент внешнего вектора - это отдельный вектор (строка матрицы)
После этой операции у нас есть n пустых строк
matrix[0] = []  (пустой вектор)
matrix[1] = []  (пустой вектор)  
matrix[2] = []  (пустой вектор)
Проходим по каждой строке (от 0 до n-1)
matrix[i].resize(m) устанавливает, что в каждой строке будет m элементов
Все элементы инициализируются значением по умолчанию (для int - это 0)
matrix[0] = [0, 0, 0, ..., 0]  (m нулей)
matrix[1] = [0, 0, 0, ..., 0]  (m нулей)
matrix[2] = [0, 0, 0, ..., 0]  (m нулей)
*/