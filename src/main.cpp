#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include <string>

#include "word.hpp"
#include "limiting.hpp"

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

int main(int argc, char *argv[]) {
	std::vector<Word> word_list = get_word_list();
	for (size_t i = 0; i < word_list.size(); i++) {
		word_list[i].set_next_words(word_list);
	}
	std::cout << word_list[2].get_next_words().size() << std::endl;
	std::cout << word_list[5].get_next_words().size() << std::endl;
	std::cout << word_list[7].get_next_words().size() << std::endl;
	std::cout << Limiting<2>({ &word_list[2], &word_list[5], &word_list[7] }).get_next_words().size() << std::endl;
	return EXIT_SUCCESS;
}
