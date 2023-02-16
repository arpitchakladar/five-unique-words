#include <vector>
#include <string>
#include <array>

#pragma once

class Word {
	private:
		size_t _index;
		std::vector<size_t> _next_words;
		std::vector<std::string>& _word_list;

	public:
		Word(std::vector<std::string>&, size_t);
		~Word() = default;
		template<size_t N>
		bool is_used(std::array<size_t, N>);

	public:
		inline const std::vector<size_t>& get_next_words() const { return _next_words; }
		inline size_t get_index() const { return _index; }
		inline const std::string& get_word() const { return _word_list[_index]; }
};
