# string filter
1. Implement: a text filter with C++11
* Based on UTF-8 encoding and supporting different languages
* Adding keywords and filtering keywords

Sample code:
<pre><code>Filter filter;
filter.load(strKeywords);
filter.censor(strOutput);
</code></pre>

Data structure and algorithm
* Trie: https://zh.wikipedia.org/wiki/Trie
* Time complexity : O(n), we can insert and find strings in O(n) time where n represent the length of a single word.
* Space complexity : O(n*m), n: possible character count, m: average word length

2. Benchmark
* 200K 個以上長度不等的不完全重複關鍵詞，過濾時輸入長度為 100 左右的句子進行測試
* 共有14國語言，每國語言共有14k個關鍵詞，共約200k個關鍵詞
* 測試句字，從中取出5國語言來測試
*
3. Optimize
* The memory is too large, each node needs 256bytes, if you can compress the path, you can greatly reduce the space.
* Compressed-trie-tree: a compressed trie tree uses very few amount of nodes which gives you a huge memory advantage especially for long strings with long common prefixes.
