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
3. Optimize
* Compressed-trie-tree: a compressed trie tree uses very few amount of nodes which gives you a huge memory advantage especially for long strings with long common prefixes.
