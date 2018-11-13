#ifndef COMPRESSED_TRIE_H
#define COMPRESSED_TRIE_H

#include <vector>
#include <string>

namespace trie
{

class CompressedTrie
{
    static constexpr size_t kAsciiCount = 256;
    struct TrieNode
    {
        TrieNode(bool isEnd)
			: bEnd(isEnd)
			, vChildrens(kAsciiCount, nullptr)
			, vEdgeLable(kAsciiCount, "")
        {
        }

        bool bEnd;
        std::vector<TrieNode*> vChildrens;
		std::vector<std::string> vEdgeLable;
    };

public:
	CompressedTrie()
    {
        root = new TrieNode(false);
		m_nCount = 0;
    }

    ~CompressedTrie()
    {
        ReleaseTrie(root);
    }

	CompressedTrie(const CompressedTrie&) = delete;
	CompressedTrie& operator = (const CompressedTrie&) = delete;

	void Insert(const std::string& word);

    std::string Filter(std::string& text);
	int Search(const std::string& word);

private:
    
    void ReleaseTrie(const TrieNode* root);

    TrieNode* root;

	int m_nCount;
};
} // ns trie
#endif


