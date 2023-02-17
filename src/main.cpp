#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include <string>

#include "word.hpp"

std::vector<std::string> get_word_list() {
	std::ifstream file("res/words.txt");
	std::vector<std::string> word_list;
	if (file.is_open()) {
		while (file) {
			std::string line;
			std::getline(file, line);
			if (line.size() == 5) {
				word_list.push_back(std::move(line));
			}
		}
	} else {
		std::cout << "FAILED: Failed to open file." << std::endl;
	}
	return word_list;
}

template<size_t N>
const std::vector<size_t>& get_most_limiting(std::vector<Word>& word_list, std::array<size_t, N> indexes) {
	const std::vector<size_t> *current_min = &word_list[indexes[0]].get_next_words();
	for (size_t i = 0; i < N; i++) {
		const std::vector<size_t>& current_list = word_list[indexes[i]].get_next_words();
		if (current_list.size() < current_min->size()) {
			current_min = &current_list;
		}
	}
	return *current_min;
}

int main(int argc, char *argv[]) {
	std::vector<std::string> _word_list = get_word_list();
	if (_word_list.size() > 0) {
		std::vector<Word> word_list;
		for (size_t i = 0; i < _word_list.size(); i++) {
			word_list.push_back(Word(_word_list, i));
		}
		std::cout << word_list[2].get_next_words().size() << std::endl;
		std::cout << word_list[5].get_next_words().size() << std::endl;
		std::cout << word_list[7].get_next_words().size() << std::endl;
		std::cout << get_most_limiting(word_list, std::array { 2UL, 5UL, 7UL }).size() << std::endl;
	}
	return EXIT_SUCCESS;
}
