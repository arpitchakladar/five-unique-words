#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include <string>

#include "word.hpp"
#include "limiting.hpp"
#include "possible_words.hpp"

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
		for (size_t i = 0; i < word_list.size(); i++) {
			word_list[i].set_next_words(word_list);
		}
	} else {
		std::cout << "FAILED: Failed to open file." << std::endl;
	}
	return word_list;
}

int main(int argc, char *argv[]) {
	std::vector<Word> word_list = get_word_list();
	std::vector<std::array<Word*, 5>> results = get_possible_words(word_list);
	for (size_t i = 0; i < results.size(); i++) {
		Word::print_words(results[i]);
	}
	std::cout << "Total = " << results.size() << std::endl;
	return EXIT_SUCCESS;
}
