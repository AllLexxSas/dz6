#pragma once
#include "main.h"


class WordSearch
{
public:
	WordSearch(string filePath);
	bool SearchWordInText(string);

private:
	string path;//путь к файлу
	string stringBuf;//буфер, куда будет заноситься считанный файл

	void ReadingTextFromFile();


};

