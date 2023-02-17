#include <vector>
#include <array>

#include "limiting.hpp"

template<size_t N>
Limiting<N>::Limiting(std::array<Word*, N + 1> words) {
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

template class Limiting<1>;
template class Limiting<2>;
template class Limiting<3>;
