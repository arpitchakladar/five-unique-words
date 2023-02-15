#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include <string>

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

bool is_used(std::vector<std::string>& word_list, size_t index, std::array<long, 4> indexes) {
	for (size_t i = 0; i < 4; i++) {
		int current_index = indexes[i];
		if (current_index < 0) {
			break;
		} else {
			std::string& current_word = word_list[current_index];
			std::string& word_to_check = word_list[index];
			for (size_t x = 0; x < 5; x++) {
				char c = current_word[x];
				for (size_t y = 0; y < 5; y++) {
					if (c == word_to_check[y]) {
						return true;
					}
				}
			}
		}
	}

	return false;
}

int main(int argc, char *argv[]) {
	std::vector<std::string> word_list = get_word_list();
	if (word_list.size() > 0) {
		for (long a = 0; a < word_list.size(); a++) {
			for (long b = a; b < word_list.size(); b++) {
				if (is_used(word_list, b, { a, -1, -1, -1 })) continue;
				for (long c = b; c < word_list.size(); c++) {
					if (is_used(word_list, c, { a, b, -1, -1 })) continue;
					for (long d = c; d < word_list.size(); d++) {
						if (is_used(word_list, d, { a, b, c, -1 })) continue;
						for (long e = d; e < word_list.size(); e++) {
							if (!is_used(word_list, e, { a, b, c, d })) {
								std::cout << word_list[a] << word_list[b] << word_list[c] << word_list[d] << word_list[e] << std::endl;
							}
						}
					}
				}
			}
		}
	}
	return EXIT_SUCCESS;
}
