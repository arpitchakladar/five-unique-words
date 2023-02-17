#include <vector>
#include <string>
#include <iostream>

#include "word.hpp"

Word::Word(std::string&& text)
	: _text(text)
{}

template<size_t N>
bool Word::is_used(std::array<Word*, N> words) const {
	for (size_t i = 0; i < N; i++) {
		std::string& current_word = words[i]->_text;
		for (size_t x = 0; x < 5; x++) {
			char c = current_word[x];
			for (size_t y = 0; y < 5; y++) {
				if (c == _text[y]) {
					return true;
				}
			}
		}
	}
	return false;
}

void Word::set_next_words(std::vector<Word>& word_list) {
	for (size_t i = 0; i < word_list.size(); i++) {
		Word *word = &word_list[i];
		if (!is_used(std::array { word })) {
			_next_words.push_back(word);
		}
	}
}
