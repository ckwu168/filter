#ifndef TRIE_H
#define TRIE_H

#include <vector>
#include <string>

namespace trie
{

class Trie
{
    static constexpr size_t kAsciiCount = 256;
    struct TrieNode
    {
        TrieNode(const char szVal)
          : szVal(szVal), bEnd(false), childrens(kAsciiCount, nullptr)
        {
        }

        char szVal;
        bool bEnd;
        std::vector<TrieNode*> childrens;
    };

  public:
    Trie()
    {
        root = new TrieNode('0');
		m_nCount = 0;
    }

    ~Trie()
    {
        ReleaseTrie(root);
    }

    Trie(const Trie&) = delete;
    Trie& operator = (const Trie&) = delete;

	void Insert(const std::string& word);

    int Lookup(const std::string& word);

  private:
    
    int Search(const TrieNode* parent, const std::string& word, const size_t idx); 

    void ReleaseTrie(const TrieNode* root);

    TrieNode* root;

	int m_nCount;
};
} // ns trie
#endif


