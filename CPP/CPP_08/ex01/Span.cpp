#include "Span.hpp"

Span::Span(unsigned int N) : _N(N)
{
}

Span::Span(const Span &other) : _N(other._N), _numbers(other._numbers)
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_N = other._N;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _N)
		throw std::out_of_range("Cannot add more numbers: Span is already full");
	_numbers.push_back(number);
}

int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");

	std::vector<int> sorted_numbers(_numbers);
	std::sort(sorted_numbers.begin(), sorted_numbers.end());

	int min_span = sorted_numbers[1] - sorted_numbers[0];
	for (std::size_t i = 1; i < sorted_numbers.size() - 1; ++i)
	{
		int span = sorted_numbers[i + 1] - sorted_numbers[i];
		if (span < min_span)
			min_span = span;
	}
	return min_span;
}

int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");

	int min_value = *std::min_element(_numbers.begin(), _numbers.end());
	int max_value = *std::max_element(_numbers.begin(), _numbers.end());

	return max_value - min_value;
}
