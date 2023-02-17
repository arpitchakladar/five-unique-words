#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include <string>

#include "word.hpp"

std::vector<Word> get_word_list() {
	std::ifstream file("res/words.txt");
	std::vector<Word> word_list;
	if (file.is_open()) {
		while (file) {
			std::string line;
			std::getline(file, line);
			if (line.size() == 5) {
				word_list.push_back(Word(std::move(line)));
			}
		}
	} else {
		std::cout << "FAILED: Failed to open file." << std::endl;
	}
	return word_list;
}

template<size_t N>
const std::vector<Word*>& get_most_limiting(std::vector<Word>& word_list, std::array<Word, N> words) {
	const std::vector<Word*> *current_min = &words[0].get_next_words();
	for (size_t i = 0; i < N; i++) {
		const std::vector<Word*>& current_list = words[i].get_next_words();
		if (current_list.size() < current_min->size()) {
			current_min = &current_list;
		}
	}
	return *current_min;
}

int main(int argc, char *argv[]) {
	std::vector<Word> word_list = get_word_list();
	for (size_t i = 0; i < word_list.size(); i++) {
		word_list[i].set_next_words(word_list);
	}
	std::cout << word_list[2].get_next_words().size() << std::endl;
	std::cout << word_list[5].get_next_words().size() << std::endl;
	std::cout << word_list[7].get_next_words().size() << std::endl;
	std::cout << get_most_limiting(word_list, std::array { word_list[2], word_list[5], word_list[7] }).size() << std::endl;
	return EXIT_SUCCESS;
}
