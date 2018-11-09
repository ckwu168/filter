#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <sys/timeb.h>
#include <vector>
#include "filter/trie.h"
#include "filter/filter.h"

using namespace trie;

void readFile2Vector(const std::string& file, std::vector<std::string>& vec)
{
	std::fstream infile(file, std::ios_base::in);
	std::string line;
	while (getline(infile, line, '\n'))
	{
		vec.emplace_back(line);
	}
}

int main(int argc, char* argv[])
{
	// keywords
	std::vector<std::string> vLang = { "ar", "cn", "de", "fa", "fr", "is", "it", "iw", "ja", "ko", "la", "mn", "no", "th" };
	Filter filter;
	std::string strKeywords;
	for (int i = 0; i < vLang.size(); ++i)
	{
		strKeywords = std::string("..\\..\\data\\keywords.") + vLang[i] + std::string(".txt");
		filter.load(strKeywords);
	}

	// input
	std::ifstream inputFile("..\\..\\data\\input.txt", std::ios::in);
	std::string source;
	std::string read;
	while (getline(inputFile, read))
	{
		source += read;
	}
	inputFile.close();

	// analyze
	std::ofstream analyzeFile("..\\..\\data\\analyze.csv", std::ios::out);
	struct timeb startTime, endTime;
	analyzeFile << "search time (per 1000 time)" << std::endl;
	std::string strOutput = source;
	for (int i = 0; i < 1000; ++i)
	{
		ftime(&startTime);
		for (int j = 0; j < 1000; ++j)
		{
			strOutput = source;
			filter.censor(strOutput);
		}
		ftime(&endTime);
		analyzeFile << (endTime.time - startTime.time) * 1000 + (endTime.millitm - startTime.millitm) << std::endl; // ms
	}
	analyzeFile.close();

	// output
	std::ofstream outputFile("..\\..\\data\\output.txt", std::ios::out);
	outputFile << strOutput << std::endl;
	outputFile.close();

	return 0;
}