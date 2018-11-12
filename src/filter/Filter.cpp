#include <iostream>
#include <fstream>
#include "Filter.h"

void Filter::Load(std::string& filepath)
{
	std::ifstream infile(filepath, std::ios::in);

	if (!infile)
	{
		std::cout << "open file error" << std::endl;
	}
	else
	{
		std::cout << "open file succeed" << std::endl;
		std::string read;
		while (getline(infile, read))
		{
			m_tree.Insert(read);
		}
	}

	infile.close();
	m_bInitialized = true;
}


void Filter::Censor(std::string& source)
{
	if (!m_bInitialized)
	{
		return;
	}

	int length = source.size();
	for (int i = 0; i < length; ++i)
	{
		std::string substring = source.substr(i, length - i);
		int idx = m_tree.Lookup(substring);
		if (idx)
		{
			source.replace(i, idx, "**");
			length = source.size();
		}
	}
}