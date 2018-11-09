#ifndef TRIE_HPP
#define TRIE_HPP

#include <vector>
#include <string>

namespace trie
{

class Trie
{
    static constexpr size_t kAsciiCount = 256;
    struct TrieNode
    {
        TrieNode(const char val)
          : val(val), is_end(false), childrens(kAsciiCount, nullptr)
        {
        }

        char val;
        bool is_end;
        std::vector<TrieNode*> childrens;
    };

  public:
    Trie()
    {
        root = new TrieNode('0');
		m_count = 0;
    }

    ~Trie()
    {
        ReleaseTrie(root);
    }

    Trie(const Trie&) = delete;
    Trie& operator = (const Trie&) = delete;

    void Init(const std::vector<std::string>& dict);

	void Insert(const std::string& word);

    int Lookup(const std::string& word);

  private:
    
    int Search(const TrieNode* parent, const std::string& word, const size_t idx); 

    void ReleaseTrie(const TrieNode* root);

    TrieNode* root;

	int m_count;
};
} // ns trie
#endif

