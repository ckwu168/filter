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
* Test the sentence and take out 5 languages to test
* There are 14 languages, 14k keywords in each language, a total of about 200k keywords
* A total of 1000 rounds were run, and the keywords were filtered 1000 times per round.

平均數	98.911
標準誤	0.382339198
中間值	96
眾數	92
標準差	12.09062704
變異數	146.1832623
峰度	48.17608222
偏態	5.576638758
範圍	162
最小值	89
最大值	251
總和	98911
個數	1000
信賴度(95.0%)	0.75028006


3. Optimize
* The memory is too large, each node needs 256bytes and the path is too long, if we can compress the path, we can greatly reduce the space.
* Compressed-trie-tree: a compressed trie tree uses very few amount of nodes which gives you a huge memory advantage especially for long strings with long common prefixes.
