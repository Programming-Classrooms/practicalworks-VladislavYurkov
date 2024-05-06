#include "src/Functions/Functions.hpp"


int main()
{
    std::locale::global(std::locale("ru_RU.UTF-8"));
	std::map<std::wstring, size_t> words;
	std::wifstream wordsFile("src/Resources/words.txt");
	readWords(wordsFile, words);
	printWords(words);
	wordsFile.close();
	return 0;
}
