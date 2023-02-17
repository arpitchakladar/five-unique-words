#include <vector>
#include <string>
#include <cinttypes>

#include <iostream>

#include "word.hpp"

Word::Word(std::string&& text)
	: _text(text), _bit_map(0)
{
	for (size_t i = 0; i < 5; i++) {
		_bit_map += 1 << (_text[i] - 97);
	}
}

template<size_t N>
bool Word::is_used(const std::array<Word*, N>& words) const {
	for (size_t i = 0; i < N; i++) {
		if ((words[i]->_bit_map & _bit_map) > 0) {
			return true;
		}
	}
	return false;
}

template bool Word::is_used(const std::array<Word*, 1>&) const;
template bool Word::is_used(const std::array<Word*, 2>&) const;
template bool Word::is_used(const std::array<Word*, 3>&) const;

void Word::set_next_words(std::vector<Word>& word_list) {
	for (size_t i = 0; i < word_list.size(); i++) {
		Word *word = &word_list[i];
		if (!is_used(std::array { word })) {
			_next_words.push_back(word);
		}
	}
}

template<size_t N>
void Word::print_words(const std::array<Word*, N>& words) {
	std::cout << "{ ";
	for (size_t i = 0; i < N; i++) {
		std::cout << words[i]->get_text();
		if (i < N - 1) {
			std::cout << ", ";
		}
	}
	std::cout << " }" << std::endl;
}

template void Word::print_words(const std::array<Word*, 1>&);
template void Word::print_words(const std::array<Word*, 2>&);
template void Word::print_words(const std::array<Word*, 3>&);
template void Word::print_words(const std::array<Word*, 4>&);
template void Word::print_words(const std::array<Word*, 5>&);

void Word::print_words(const std::vector<Word*>& words) {
	std::cout << "{ ";
	for (size_t i = 0; i < words.size(); i++) {
		std::cout << words[i]->get_text();
		if (i < words.size()) {
			std::cout << ", ";
		}
	}
	std::cout << " }" << std::endl;
}
