#include "CompressedTrie.h"
#include <iostream>

namespace trie
{

void CompressedTrie::Init(const std::vector<std::string>& dict)
{
    for (const std::string& word : dict)
    {
        Insert(word);
    }
}

int CompressedTrie::Lookup(const std::string& word)
{
    return Search(root, word, 0);
}

void CompressedTrie::Insert(const std::string& word)
{

}
    
int CompressedTrie::Search(const TrieNode* parent, const std::string& word, const size_t idx)
{
	return 0;
}

void CompressedTrie::ReleaseTrie(const TrieNode* root)
{

}

} // ns trie
