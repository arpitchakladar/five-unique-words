#include <vector>
#include <array>

#include "word.hpp"

#pragma once

template<size_t N>
class Limiting {
	private:
		const std::vector<Word*>* _next_words;
		std::array<Word*, N> _remaining_words;

	public:
		Limiting(std::array<Word*, N + 1> words) {
			_next_words = &words[0]->get_next_words();
			size_t excluded_word_index = 0;
			for (size_t i = 0; i < N + 1; i++) {
				const std::vector<Word*>& current_list = words[i]->get_next_words();
				if (current_list.size() < _next_words->size()) {
					_next_words = &current_list;
					excluded_word_index = i;
				}
			}
			for (size_t i = 0, j = 0; j < N + 1; j++) {
				if (j != excluded_word_index) {
					_remaining_words[i] = words[j];
					i++;
				}
			}
		}
		~Limiting() = default;

	public:
		inline const std::vector<Word*>& get_next_words() const { return *_next_words; }
		inline std::array<Word*, N> remaining_next_words() const { return _remaining_words; }
};
