#include <vector>
#include <string>
#include <iostream>

#include "word.hpp"

Word::Word(std::vector<std::string>& word_list, size_t index)
	: _word_list(word_list), _index(index)
{
	for (size_t j = _index; j < _word_list.size(); j++) {
		if (!is_used(std::array { j } )) {
			_next_words.push_back(j);
		}
	}
}

template<size_t N>
bool Word::is_used(std::array<size_t, N> indexes) {
	for (size_t i = 0; i < N; i++) {
		std::string& current_word = _word_list[indexes[i]];
		std::string& word_to_check = _word_list[_index];
		for (size_t x = 0; x < 5; x++) {
			char c = current_word[x];
			for (size_t y = 0; y < 5; y++) {
				if (c == word_to_check[y]) {
					return true;
				}
			}
		}
	}

	return false;
}
