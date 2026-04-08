/**
 * @file anagram_dict.cpp
 * Implementation of the AnagramDict class.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "anagram_dict.h"

#include <algorithm> /* I wonder why this is included... */
#include <fstream>

using std::string;
using std::vector;
using std::ifstream;

/** 
 * Constructs an AnagramDict from a filename with newline-separated
 * words.
 * @param filename The name of the word list file.
 */ 
AnagramDict::AnagramDict(const string& filename)
{
    /* Your code goes here! */
    vector<string> words;

    ifstream words_file(filename);
    string word;
    if (!words_file.is_open()) {
        return;
    }
    while (getline(words_file, word)) {
        words.push_back(word);
    }
    words_file.close();

    construct_dict(words);
}

/** 
 * Constructs an AnagramDict from a vector of words.
 * @param words The vector of strings to be used as source words.
 */ 
AnagramDict::AnagramDict(const vector< string >& words)
{
    /* Your code goes here! */
    construct_dict(words);
}

/**
 * @param word The word to find anagrams of. 
 * @return A vector of strings of anagrams of the given word. Empty
 * vector returned if no anagrams are found or the word is not in the 
 * word list.
 */
vector< string > AnagramDict::get_anagrams(const string& word) const
{
    /* Your code goes here! */
    string key = word;
    std::sort(key.begin(), key.end());
    return dict.at(key);
}       

/**
 * @return A vector of vectors of strings. Each inner vector contains
 * the "anagram siblings", i.e. words that are anagrams of one another.
 * NOTE: It is impossible to have one of these vectors have less than
 * two elements, i.e. words with no anagrams are ommitted.
 */
vector< vector< string > > AnagramDict::get_all_anagrams() const
{
    /* Your code goes here! */
    vector< vector < string > > anagrams;
    for (const auto& key_value : dict) {
        if (key_value.second.size() > 1) {
            anagrams.push_back(key_value.second);
        }
    }
    return anagrams;
}

void AnagramDict::construct_dict(const vector< string >& words) {
    for (string word: words) {
        string original_word = word;
        std::sort(word.begin(), word.end());
        bool word_exists = std::find(dict[word].begin(), dict[word].end(), original_word) != dict[word].end();
        if (!word_exists) {
            dict[word].push_back(original_word);
        }
    }
}
