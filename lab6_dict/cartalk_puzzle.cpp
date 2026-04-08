/**
 * @file cartalk_puzzle.cpp
 * Holds the function which solves a CarTalk puzzler.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include <fstream>

#include "cartalk_puzzle.h"

using std::vector;
using std::string;

/**
 * Solves the CarTalk puzzler described here:
 * http://www.cartalk.com/content/wordplay-anyone.
 * @return A vector of "StringTriples" (a typedef'd std::tuple, see top of 
 * cartalk_puzzle.h). Returns an empty vector if no solutions are found.
 * @param d The PronounceDict to be used to solve the puzzle.
 * @param word_list_fname The filename of the word list to be used.
 */
vector< StringTriple > cartalk_puzzle(PronounceDict d,
                                      const string& word_list_fname)
{
    /* Your code goes here! */
    vector< StringTriple > result;

    std::ifstream word_list_file(word_list_fname);
    if (!word_list_file.is_open()) {
        return vector< StringTriple >();
    }

    string word;
    string first_removed;
    string second_removed;
    while (getline(word_list_file, word)) {
        if (word.length() < 5) {
            continue;
        }
        first_removed = word.substr(1);
        if (!d.homophones(word, first_removed)) {
            continue;
        }
        second_removed = word.at(0) + word.substr(2);
        if (d.homophones(word, second_removed)) {
            StringTriple words(word, first_removed, second_removed);
            result.push_back(words);
        }
    }
    word_list_file.close();

    return result;
}


