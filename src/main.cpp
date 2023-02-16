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

int main(int argc, char *argv[]) {
	std::vector<std::string> _word_list = get_word_list();
	if (_word_list.size() > 0) {
		std::vector<Word> word_list;
		for (size_t i = 0; i < _word_list.size(); i++) {
			word_list.push_back(Word(_word_list, i));
		}
		std::cout << word_list.size() << std::endl;
	}
	return EXIT_SUCCESS;
}
