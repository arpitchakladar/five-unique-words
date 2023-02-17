#include <array>
#include <vector>

#include <iostream>

#include "word.hpp"
#include "limiting.hpp"
#include "possible_words.hpp"

void get_possible_words(std::array<Word*, 4> last_words) {
	Limiting<3> limiting(last_words);
	for (size_t i = 0; i < limiting.get_next_words().size(); i++) {
		Word* current_word = limiting.get_next_words()[i];
		if (!current_word->is_used(limiting.get_unchecked_words())) {
			std::cout << "Found one!" << std::endl;
		}
	}
}

template<size_t N>
void get_possible_words(std::array<Word*, N> last_words) {
	Limiting<N - 1> limiting(last_words);
	for (size_t i = 0; i < limiting.get_next_words().size(); i++) {
		Word* current_word = limiting.get_next_words()[i];
		if (!current_word->is_used(limiting.get_unchecked_words())) {
			std::array<Word*, N + 1> next_words;
			for (size_t i = 0; i < N; i++) {
				next_words[i] = last_words[i];
			}
			next_words[N] = current_word;
			get_possible_words(next_words);
		}
	}
}

void get_possible_words(std::array<Word*, 1> last_words) {
	Word *word = last_words[0];
	for (size_t i = 0; i < word->get_next_words().size(); i++) {
		get_possible_words(std::array<Word*, 2> { word, word->get_next_words()[i] });
	}
}

void get_possible_words(std::vector<Word>& word_list) {
	for (size_t i = 0; i < word_list.size(); i++) {
		std::cout << word_list[i].get_text() << std::endl;
		get_possible_words(std::array<Word*, 1> { &word_list[i] });
	}
}
