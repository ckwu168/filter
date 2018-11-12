cmake_minimum_required(VERSION 2.6)

project(filter)
add_library(filter Filter.cpp Filter.h Trie.cpp Trie.h CompressedTrie.cpp CompressedTrie.h)