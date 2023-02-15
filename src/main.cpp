#include <iostream>
#include <vector>
#include <fstream>
#include <string>

std::vector<std::string> get_word_list() {
	std::ifstream file("res/words.txt");
	std::vector<std::string> word_list;
	if (file.is_open()) {
		while (file) {
			std::string line;
			std::getline(file, line);
			word_list.push_back(std::move(line));
		}
	} else {
		std::cout << "FAILED: Failed to open file." << std::endl;
	}
	return word_list;
}

int main(int argc, char *argv[]) {
	std::vector<std::string> word_list = get_word_list();
	std::cout << "word_list.size() = " << word_list.size() << std::endl;
	return EXIT_SUCCESS;
}
