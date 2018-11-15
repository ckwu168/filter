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
* AcTrie: https://zh.wikipedia.org/wiki/AC%E8%87%AA%E5%8A%A8%E6%9C%BA%E7%AE%97%E6%B3%95
* Time complexity : O(n), we can insert and find strings in O(n) time where n represent the length of a single word.
* Space complexity : O(n*m), n: possible character count, m: average word length

2. Benchmark
* Test the sentence and take out 5 languages to test
* There are 14 languages, 14k keywords in each language, a total of about 200k keywords. https://github.com/ckwu168/filter/blob/master/data/keywords.cn.txt
* A total of 1000 rounds were run, and the keywords were filtered 1000 times per a round.
* Analyze : https://github.com/ckwu168/filter/tree/master/data/analyze.xlsx

3. Optimize
* Compressed trie tree: a compressed trie tree uses very few amount of nodes which gives you a huge memory advantage especially for long strings with long common prefixes.
<pre><code>
                           o (root)                                                
                           + face
                           o                              
                     +-----+------+                           
                     o (ed)       o (book)                   

</code></pre>
