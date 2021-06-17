#include "WordSearch.h"

WordSearch::WordSearch(string filePath)
{
	path = filePath;
	ReadingTextFromFile();
}

bool WordSearch::SearchWordInText(string searchWord)
{
	auto rez = stringBuf.find(searchWord);
	if (rez != std::string::npos)
		return true;

	return false;
}


//чтение данных из файла
void WordSearch::ReadingTextFromFile()
{
	ifstream file(path);
	stringstream buf;
	file >> buf.rdbuf();
	stringBuf = buf.str();
}


