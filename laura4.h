#ifndef H_H
#define H_H

#include <vector>
#include <string>
using namespace std;
void fillKeyboard(vector<vector<int>> &matrix); //заполнение с клавиатуры
void fillRandom(vector<vector<int>> &matrix); //заполнение рандом числами
void fill_file(vector<vector<int>> &matrix, string filename); //заполнение из файла
void clearMatrix(vector<vector<int>> &matrix); //очищение матрицы 

void matrix27(vector<vector<int>> &matrix);
void matrix27file(vector<vector<int>> &matrix);

void matrix53(vector<vector<int>> &matrix);
void matrix53file(vector<vector<int>> &matrix);

#endif