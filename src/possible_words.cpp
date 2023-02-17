#include <array>
#include <vector>

#include "word.hpp"
#include "limiting.hpp"
#include "possible_words.hpp"

static void _get_possible_words(std::array<Word*, 4> last_words, std::vector<std::array<Word*, 5>>& results) {
	Limiting<3> limiting(last_words);
	for (size_t i = 0; i < limiting.get_next_words().size(); i++) {
		Word* current_word = limiting.get_next_words()[i];
		if (!current_word->is_used(limiting.get_unchecked_words())) {
			std::array<Word*, 5> current_result;
			for (size_t i = 0; i < 4; i++) {
				current_result[i] = last_words[i];
			}
			current_result[4] = current_word;
			results.push_back(current_result);
		}
	}
}

template<size_t N>
static void _get_possible_words(std::array<Word*, N> last_words, std::vector<std::array<Word*, 5>>& results) {
	Limiting<N - 1> limiting(last_words);
	for (size_t i = 0; i < limiting.get_next_words().size(); i++) {
		Word* current_word = limiting.get_next_words()[i];
		if (!current_word->is_used(limiting.get_unchecked_words())) {
			std::array<Word*, N + 1> next_words;
			for (size_t i = 0; i < N; i++) {
				next_words[i] = last_words[i];
			}
			next_words[N] = current_word;
			_get_possible_words(next_words, results);
		}
	}
}

static void _get_possible_words(std::array<Word*, 1> last_words, std::vector<std::array<Word*, 5>>& results) {
	Word *word = last_words[0];
	for (size_t i = 0; i < word->get_next_words().size(); i++) {
		_get_possible_words(std::array<Word*, 2> { word, word->get_next_words()[i] }, results);
	}
}

std::vector<std::array<Word*, 5>> get_possible_words(std::vector<Word>& word_list) {
	std::vector<std::array<Word*, 5>> results;
	for (size_t i = 0; i < word_list.size(); i++) {
		_get_possible_words(std::array<Word*, 1> { &word_list[i] }, results);
	}
	return results;
}
