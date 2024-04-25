#include "src/Functions/Functions.hpp"


int main()
{
	try
	{
		std::vector<std::string>words;
		std::ifstream wordsFile("src/txtFiles/words.txt");
		checkFile(wordsFile);
		words = readWordsFromFile(wordsFile);
		std::sort(words.begin(), words.end());
		printVector(words);
		printWordsStartsWithSymbol(words, 'f');
		deleteWordsStartsWithSymbol(words, 's');
		std::cout << "Words started with \'s\' deleted from vector\n";
		printVector(words);
		return 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
