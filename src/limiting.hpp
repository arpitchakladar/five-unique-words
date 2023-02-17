#include <vector>
#include <array>

#include "word.hpp"

#pragma once

template<size_t N>
class Limiting {
	private:
		const std::vector<Word*>* _next_words;
		std::array<Word*, N> _remaining_words;

	public:
		Limiting(std::array<Word*, N + 1> words);
		~Limiting() = default;

	public:
		inline const std::vector<Word*>& get_next_words() const { return *_next_words; }
		inline std::array<Word*, N> remaining_next_words() const { return _remaining_words; }
};
