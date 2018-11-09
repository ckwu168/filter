
#include <string>
#include "trie.h"

using namespace trie;

class Filter
{
public:
	Filter():m_initialized(false)
	{
	}

	~Filter()
	{
	}

	void load(std::string& fileName);
	void censor(std::string& source);

private:
	Trie m_tree;
	bool m_initialized;
};
