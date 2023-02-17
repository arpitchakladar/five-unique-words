#include <array>
#include <vector>

#include "word.hpp"

#pragma once

void get_possible_words(std::array<Word*, 4> last_words);
template<size_t N>
void get_possible_words(std::array<Word*, N> last_words);
void get_possible_words(std::array<Word*, 1> last_words);
void get_possible_words(std::vector<Word>& word_list);
