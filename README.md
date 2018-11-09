# string filter
a text filter with C++11
* Based on UTF-8 encoding and supporting different languages
* Adding keywords and filtering keywords

Sample code:

Filter filter;
filter.load(strKeywords);
filter.censor(strOutput);
