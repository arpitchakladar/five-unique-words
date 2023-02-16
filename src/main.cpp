#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include <string>

class WordNode {
	public:
		long index;
		std::vector<long> possible_words;
		WordNode(long index, std::vector<long>&& possible_words)
			: index(index), possible_words(possible_words)
		{}
};

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

bool is_used(std::vector<std::string>& word_list, size_t index, std::array<long, 3> indexes) {
	for (size_t i = 0; i < 3; i++) {
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
	std::vector<WordNode> word_list_graph;
	for (int i = 0; i < word_list.size(); i++) {
		std::vector<long> indexes;
		for (int j = i; j < word_list.size(); j++) {
			if (!is_used(word_list, j, { i, -1, -1 })) {
				indexes.push_back(j);
			}
		}
		word_list_graph.push_back(WordNode(i, std::move(indexes)));
	}
	if (word_list.size() > 0) {
		for (long a = 0; a < word_list_graph.size(); a++) {
			auto& ap = word_list_graph[a];
			std::cout << word_list[ap.index] << std::endl;
			for (long b = 0; b < ap.possible_words.size(); b++) {
				auto& bp = word_list_graph[ap.possible_words[b]];
				for (long c = 0; c < bp.possible_words.size(); c++) {
					auto& cp = word_list_graph[bp.possible_words[c]];
					if (is_used(word_list, cp.index, { ap.index, -1, -1 })) continue;
					for (long d = 0; d < cp.possible_words.size(); d++) {
						auto& dp = word_list_graph[cp.possible_words[d]];
						if (is_used(word_list, dp.index, { ap.index, bp.index, -1 })) continue;
						for (long e = 0; e < dp.possible_words.size(); e++) {
							auto& ep = word_list_graph[dp.possible_words[e]];
							if (!is_used(word_list, ep.index, { ap.index, bp.index, cp.index })) {
								std::cout << word_list[ap.index] << word_list[bp.index] << word_list[cp.index] << word_list[dp.index] << word_list[ep.index] << std::endl;
							}
						}
					}
				}
			}
		}
	}
	return EXIT_SUCCESS;
}
