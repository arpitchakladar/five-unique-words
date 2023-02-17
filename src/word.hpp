#include <vector>
#include <string>
#include <array>
#include <cinttypes>

#pragma once

class Word {
	private:
		std::string _text;
		uint32_t _bit_map;
		std::vector<Word*> _next_words;

	public:
		Word(std::string&&);
		~Word() = default;
		template<size_t N>
		bool is_used(const std::array<Word*, N>&) const;
		void set_next_words(std::vector<Word>&);
		static void print_words(const std::vector<Word*>&);
		template<size_t N>
		static void print_words(const std::array<Word*, N>&);

	public:
		inline const std::vector<Word*>& get_next_words() const { return _next_words; }
		inline const std::string& get_text() const { return _text; }
};
