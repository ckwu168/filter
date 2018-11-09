#ifndef FILTER_H
#define FILTER_H

#include <string>
#include "trie.h"

using namespace trie;

class Filter
{
public:
	Filter():m_bInitialized(false)
	{
	}

	~Filter()
	{
	}

	void Load(std::string& fileName);
	void Censor(std::string& source);

private:
	Trie m_tree;
	bool m_bInitialized;
};
#endif
