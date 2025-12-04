#ifndef laura42_H
#define laura42_H
#include "laura4.h"
#include <vector>
#include <string>
using namespace std;
void fillKeyboard(vector<vector<int>> &matrix); //заполнение с клавиатуры
void fillRandom(vector<vector<int>> &matrix); //заполнение рандом числами
void fill_file(vector<vector<int>> &matrix, string filename); //заполнение из файла
void clearMatrix(vector<vector<int>> &matrix); //очищение матрицы 

void matrixi(vector<vector<int>> &matrix, int n, int m);
#endif