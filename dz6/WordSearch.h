#pragma once
#include "main.h"


class WordSearch
{
public:
	WordSearch(string filePath);
	bool SearchWordInText(string);

private:
	string path;//���� � �����
	string stringBuf;//�����, ���� ����� ���������� ��������� ����

	void ReadingTextFromFile();


};

