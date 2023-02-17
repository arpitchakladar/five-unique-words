#include <vector>
#include <array>

#include "word.hpp"

#pragma once

template<size_t N>
class Limiting {
	private:
		const std::vector<Word*>* _next_words;
		std::array<Word*, N> _unchecked_words;

	public:
		Limiting(std::array<Word*, N + 1>);
		~Limiting() = default;

	public:
		inline const std::vector<Word*>& get_next_words() const { return *_next_words; }
		inline std::array<Word*, N> get_unchecked_words() const { return _unchecked_words; }
};
