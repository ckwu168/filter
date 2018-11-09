#include "trie.h"
#include <iostream>

namespace trie
{

void Trie::Init(const std::vector<std::string>& dict)
{
    for (const std::string& word : dict)
    {
        Insert(word);
    }
}

int Trie::Lookup(const std::string& word)
{
    return Search(root, word, 0);
}

void Trie::Insert(const std::string& word)
{
    if (word.empty())
        return;
    
    TrieNode* cur = root;
    // unsigned char range : 0 ~ 255
    for (const unsigned char c : word)
    {
        if (!cur->childrens[c])
        {
            cur->childrens[c] = new TrieNode(c);
        }
        cur = cur->childrens[c];
    }
    cur->is_end = true;
}
    
int Trie::Search(const TrieNode* parent, const std::string& word, const size_t idx) 
{
    if (word.empty())
    {
        return false;
    }   
    const std::vector<TrieNode*>& childrens = parent->childrens;
    // explicitly cast to unsigned char is needed
    const unsigned char c = word[idx];
    TrieNode* cur = childrens[c];
    if (!cur)
    {
		//return 0;
        return parent->is_end ? idx : 0;
    }
    if (idx == word.size() - 1)
	{
        return cur->is_end ? idx + 1 : 0;
    }

    return Search(cur, word, idx + 1);
}

void Trie::ReleaseTrie(const TrieNode* root)
{
    if (!root) return;
    bool no_children = true;
    const std::vector<TrieNode*>& childrens = root->childrens;
    for (const TrieNode* children : childrens)
    {
        if (children)
        {
            no_children = false;
            ReleaseTrie(children);
        }
    }

    if (no_children)
    {
        delete root;
    }
}

} // ns trie
