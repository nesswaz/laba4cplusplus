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
        cout << "777. Выход из программы" << endl;
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
            case 777: {
                cout << "Выход из программы" << endl;
                break;
            }
            default:
                cout << "Введены неверные данные" << endl;
                break;
        }
    } while (choice != 777);
    return 0;
}
//g++ osn4.cpp modul4.cpp -o program.exe