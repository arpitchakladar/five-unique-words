#include <vector>
#include <string>
#include <array>

#pragma once

class Word {
	private:
		std::string _text;
		std::vector<Word*> _next_words;

	public:
		Word(std::string&&);
		~Word() = default;
		template<size_t N>
		bool is_used(std::array<Word*, N>) const;
		void set_next_words(std::vector<Word>&);

	public:
		inline const std::vector<Word*>& get_next_words() const { return _next_words; }
		inline const std::string& get_text() const { return _text; }
};
