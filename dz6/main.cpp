
#include "main.h"
#include "WordSearch.h"


/* ������� 1
* �������� � ������ ������������ ���������� ������ ���� int. ������ ������� ��������� � ������������.
* ���������������� ��� ������� ��������� ������: 1, 2, 4, 8, 16, 32, 64, 128 � ������� ������ �� �����.
* �� ������ ���������� ������. =) ������� ��������� �� �������.
*/
#pragma region ������� 1
//void task1(ReturnFillArry PrtF)
void task1()
{
	cout << "������� ������ �������: ";
	size_t arraySize;
	cin >> arraySize;
	int * array = new int[arraySize];

	FillArray(array, arraySize);
	PrintArray(array, arraySize);
	delete[]array;

}

//���������� �������
void FillArray(int * array, size_t arraySize)
{
	int* pArray = array;
	for (int i = 1; i < pow(2, arraySize); i = i * 2)
	{
		*pArray = i;
		pArray++;
	}
}

//������ �������
void PrintArray(int array[], size_t arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
#pragma endregion


/*������� 2
* ����������� �������� ������� 4�4 ���� int. ���������������� �� ���������������� ������� ����� ������� rand.
* ������� �� �����. �������� ���� ��������� �� ������� ������� ���������� �� main.
*/
#pragma region ������� 2


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

/*������� 3
* �������� ��������� c 2-� ���������, ������� ������� ��� ��������� ����� (*.txt), �������� �� 50-100 ��������
* � ������ (������� �������� �� ����� � ����� ������ ����������). ����� ������ ��������� � �������������.
*/
#pragma region ������� 3

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
void CretateTXTFiles(const string &nameFiles, const size_t &�haracters)
{
	ofstream fout(nameFiles);
	SaveFile(fout, �haracters);
}
void SaveFile(ofstream &ofstr, const size_t &�haracters)
{
	int wordLength = 0;
	for (size_t i = 0; i < �haracters; i++)
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
#pragma region ������� 4
/*������� 4
* �������� �������, ������������� ��� ����� � ������ ��������� ���� (��� ������ �������� � ������������).
*/
void GluingFiles(string f1, string f2)
{
	string str = "1 file\n" + ReedFile(f1) + "\n2 file\n" + ReedFile(f2);//��������� ��� �����
	string path = "d:\\fempfiles.txt";//������� ��� �����, ��� ����� ��������� ��������� �����
	ofstream fout(path);//���������
	fout << str;//���������
	fout.close();//�����
}
//������ �� ���������� ����� � �����
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
	//5 ������� ����� � ��������� �����
	WordSearch d ("d:\\fempfiles.txt");
	cout << boolalpha << d.SearchWordInText("dsd") ? "����� ���" : "����� ����";
	cout << endl;
	cout << boolalpha << d.SearchWordInText("FARLEXVOVNTN") ? "����� ���" : "����� ����";
	cout << endl;
	
	

}