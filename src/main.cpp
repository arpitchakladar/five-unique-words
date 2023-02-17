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

template<size_t N>
void print_words(const std::array<Word*, N>& words) {
	std::cout << "{ ";
	for (size_t i = 0; i < N; i++) {
		std::cout << words[i]->get_text();
		if (i < N - 1) {
			std::cout << ", ";
		}
	}
	std::cout << " }" << std::endl;
}

void print_words(const std::vector<Word*>& words) {
	std::cout << "{ ";
	for (size_t i = 0; i < words.size(); i++) {
		std::cout << words[i]->get_text();
		if (i < words.size() - 1) {
			std::cout << ", ";
		}
	}
	std::cout << " }" << std::endl;
}

int main(int argc, char *argv[]) {
	std::vector<Word> word_list = get_word_list();
	std::vector<std::array<Word*, 5>> results = get_possible_words(word_list);
	for (size_t i = 0; i < results.size(); i++) {
		print_words(results[i]);
	}
	std::cout << "Total = " << results.size() << std::endl;
	return EXIT_SUCCESS;
}
