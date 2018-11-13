#include "CompressedTrie.h"
#include <iostream>

namespace trie
{

void CompressedTrie::Insert(const std::string& word)
{
	if (word.empty())
		return;

	TrieNode* cur = root;

	int i = 0;
	while (i < word.size() && cur->vEdgeLable[static_cast<unsigned char>(word[i])] != "")
	{
		int index = static_cast<unsigned char>(word[i]), j = 0;
		std::string label = cur->vEdgeLable[index];

		while (j < label.length() && i < word.length() && label[j] == word[i]) 
		{
			++i;
			++j;
		}

		if (j == label.length()) 
		{
			cur = cur->vChildrens[index];
		}
		else 
		{
			if (i == word.length()) 
			{   // inserting a prefix of exisiting word
				TrieNode* existingChild = cur->vChildrens[index];
				TrieNode* newChild = new TrieNode(true);
				std::string remainingLabel = label.substr(j);
		
				cur->vEdgeLable[index] = label.substr(0, j);	// making "faceboook" as "face"
				cur->vChildrens[index] = newChild;				// new node for "face"
				newChild->vChildrens[static_cast<unsigned char>(remainingLabel[0])] = existingChild;
				newChild->vEdgeLable[static_cast<unsigned char>(remainingLabel[0])] = remainingLabel;
			}
			else 
			{	// inserting word which has a partial match with existing word
				std::string remainingLabel = label.substr(j);
				TrieNode* newChild = new TrieNode(false);
				std::string remainingWord = word.substr(i);
				TrieNode* temp = cur->vChildrens[index];

				cur->vEdgeLable[index] = label.substr(0, j);
				cur->vChildrens[index] = newChild;
				newChild->vEdgeLable[static_cast<unsigned char>(remainingLabel[0])] = remainingLabel;
				newChild->vChildrens[static_cast<unsigned char>(remainingLabel[0])] = temp;
				newChild->vEdgeLable[static_cast<unsigned char>(remainingWord[0])] = remainingWord;
				newChild->vChildrens[static_cast<unsigned char>(remainingWord[0])] = new TrieNode(true);
			}

			return;
		}

	}
	if (i < word.length()) 
	{   // inserting new node for new word
		cur->vEdgeLable[static_cast<unsigned char>(word[i])] = word.substr(i);
		cur->vChildrens[static_cast<unsigned char>(word[i])] = new TrieNode(true);
	}
	else 
	{   // inserting "there" when "therein" and "thereafter" are existing
		cur->bEnd = true;
	}
}
    
std::string CompressedTrie::Filter(std::string& text)
{
	std::string result;
	int begin = 0;
	int position = 0;
	while (position < text.length())
	{
		bool bFind = false;
		{
			TrieNode* cur = root;
			while (cur->vEdgeLable[static_cast<unsigned char>(text[position])] != "")
			{
				int index = static_cast<unsigned char>(text[position]);
				std::string label = cur->vEdgeLable[index];

				int j = 0;
				while (j < label.length())
				{
					if (text[position] != label[j])
					{
						// character mismatch
						break;
					}
					++position;
					++j;
				}

				if (j == label.length() && position <= text.length())
				{
					cur = cur->vChildrens[index];
					if (cur->bEnd)
					{
						begin = position;
						bFind = true;
					}
				}
				else
				{
					break;
				}
			}
		}

		if (bFind)
		{
			result.append("**");
		}
		else
		{
			result.append(1, text[begin]);
			position = begin + 1;
			begin = position;
		}
		
	}
	return result;
}

int CompressedTrie::Search(const std::string& word)
{
	int i = 0;
	TrieNode* cur = root;

	int position = 0;
	while (i < word.length() && cur->vEdgeLable[static_cast<unsigned char>(word[i])] != "")
	{
		int index = static_cast<unsigned char>(word[i]);
		std::string label = cur->vEdgeLable[index];
		
		int j = 0;
		while (i < word.length() && j < label.length()) 
		{
			if (word[i] != label[j]) 
			{
				return false;   // character mismatch
			}

			++i;
			++j;
		}

		if (j == label.length() && i <= word.length()) 
		{
			cur = cur->vChildrens[index];    // traverse further
			position = i;
		}
		else 
		{
			// edge label is larger than target word
			// searching for "face" when tree has "facebook"
			return false;
		}
	}

	// target word fully traversed and current node is a word ending
	return cur->bEnd ? position : 0;
}

void CompressedTrie::ReleaseTrie(const TrieNode* root)
{
	if (!root) return;
	bool bNoChildren = true;
	const std::vector<TrieNode*>& childrens = root->vChildrens;
	for (const TrieNode* children : childrens)
	{
		if (children)
		{
			bNoChildren = false;
			ReleaseTrie(children);
		}
	}

	if (bNoChildren)
	{
		delete root;
	}
}

} // ns trie
