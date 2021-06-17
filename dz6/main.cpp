
#include "main.h"
#include "WordSearch.h"


/* Задание 1
* Выделить в памяти динамический одномерный массив типа int. Размер массива запросить у пользователя.
* Инициализировать его числами степенями двойки: 1, 2, 4, 8, 16, 32, 64, 128 … Вывести массив на экран.
* Не забыть освободить память. =) Разбить программу на функции.
*/
#pragma region задание 1
//void task1(ReturnFillArry PrtF)
void task1()
{
	cout << "Введите размер массива: ";
	size_t arraySize;
	cin >> arraySize;
	int * array = new int[arraySize];

	FillArray(array, arraySize);
	PrintArray(array, arraySize);
	delete[]array;

}

//заполнение массива
void FillArray(int * array, size_t arraySize)
{
	int* pArray = array;
	for (int i = 1; i < pow(2, arraySize); i = i * 2)
	{
		*pArray = i;
		pArray++;
	}
}

//печать массива
void PrintArray(int array[], size_t arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
#pragma endregion


/*задание 2
* Динамически выделить матрицу 4х4 типа int. Инициализировать ее псевдослучайными числами через функцию rand.
* Вывести на экран. Разбейте вашу программу на функции которые вызываются из main.
*/
#pragma region задание 2


//void task2(ReturnFillArry PrtF)
void task2()
{
	int **ss = new int*[arrayWidht];
	CreateWidhtTwoSizeArray(ss, 4, 4);
	FillArray(ss, 4);
	PrintArray(ss, 4);
	deleteTwoArray(ss, 4);
}

void CreateWidhtTwoSizeArray(int ** twoSizeArray, const size_t& sizeHeight = 0, const size_t& sizeWidht = 0)
{
	for (size_t i = 0; i < sizeHeight; i++)
	{
		twoSizeArray[i] = new int[sizeWidht];
	}
}

void FillArray(int **array, const size_t &arrayHeight)
{
	for (size_t i = 0; i < arrayHeight; i++)
	{
		for (size_t j = 0; j < arrayWidht; j++)
		{
			array[i][j] = rand();
		}
	}
}

void PrintArray(int **array, const size_t &arrayHeight)
{
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			cout << setw(6) << right << array[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

void deleteTwoArray(int **array, const size_t &arrayHeight)
{
	for (size_t i = 0; i < arrayHeight; i++)
	{
		delete[]  array[i];
	}
	delete[] array;
	array = nullptr;

}

#pragma endregion

/*задание 3
* Написать программу c 2-я функциями, которая создаст два текстовых файла (*.txt), примерно по 50-100 символов
* в каждом (особого значения не имеет с каким именно содержимым). Имена файлов запросить у польлзователя.
*/
#pragma region задание 3

void task3()
{
	const size_t SIZEFISTTXTTILES = 77;
	const size_t SIZESECONDTXTTILES = 99;
	string f1_name = GetFileName();
	string f2_name = GetFileName();
	CretateTXTFiles(f1_name, SIZEFISTTXTTILES);
	CretateTXTFiles(f2_name, SIZESECONDTXTTILES);

	GluingFiles(f1_name, f2_name);
}
string GetFileName()
{
	string fileName;
	cin >> fileName;
	fileName = "d:\\" + fileName + "\.txt";
	return fileName;
}
void CretateTXTFiles(const string &nameFiles, const size_t &сharacters)
{
	ofstream fout(nameFiles);
	SaveFile(fout, сharacters);
}
void SaveFile(ofstream &ofstr, const size_t &сharacters)
{
	int wordLength = 0;
	for (size_t i = 0; i < сharacters; i++)
	{
		wordLength = 5 + rand() % 15;
		for (size_t j = 0; j < wordLength; j++)
		{
			ofstr << static_cast<char> (65 + rand() % 25);
		}
		ofstr << ' ';
	}
	//ofstr << '\n';
	ofstr.close();
}

#pragma endregion
#pragma region задание 4
/*Задание 4
* Написать функцию, «склеивающую» эти файлы в третий текстовый файл (имя файлов спросить у пользователя).
*/
void GluingFiles(string f1, string f2)
{
	string str = "1 file\n" + ReedFile(f1) + "\n2 file\n" + ReedFile(f2);//склеиваем два файла
	string path = "d:\\fempfiles.txt";//задание имя файла, где будут храниться склеенные файлы
	ofstream fout(path);//сохраняем
	fout << str;//склеенные
	fout.close();//файлы
}
//чтение из текстового файла в буфер
string ReedFile(string fileName)
{
	ifstream file(fileName);
	stringstream buf;
	file >> buf.rdbuf();
	file.close();
	return buf.str();
}
#pragma endregion



void main()
{
	setlocale(0, "rus");
	//task3();
	//5 задание вынес в отдельный класс
	WordSearch d ("d:\\fempfiles.txt");
	cout << boolalpha << d.SearchWordInText("dsd") ? "слова нет" : "слово есть";
	cout << endl;
	cout << boolalpha << d.SearchWordInText("FARLEXVOVNTN") ? "слова нет" : "слово есть";
	cout << endl;
	
	

}