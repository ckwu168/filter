#ifndef FILTER_H
#define FILTER_H

#include <string>
#include "Trie.h"
#include "CompressedTrie.h"

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
	//Trie m_tree;
	CompressedTrie m_tree;
	bool m_bInitialized;
};
#endif
