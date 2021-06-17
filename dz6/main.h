#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
static const int arrayWidht = 4;




void task1();
..void task2();
//void task3();

void CreateWidhtTwoSizeArray(int **, const size_t&, const size_t&); //создание второй ветки двухмерного динамического массива

void PrintArray(int [], size_t);//вывод на экран одномерного массива
void PrintArray(int **, const size_t &);//вывод на экран двухмерного массива
void FillArray(int *, size_t );//заполнение массива и файлов (задание 1 и 3)
//void FillArray( ReturnFillArry);
void FillArray(int **, const size_t &);// заполнение динамического массива (задание 2)



void deleteTwoArray(int **array, const size_t &arrayHeight);

void CretateTXTFiles(const string &, const size_t &);
string GetFileName();
void SaveFile(ofstream &, const  size_t&);
//4 задание
void GluingFiles(string f1, string f2);
string ReedFile(string fileName);

