#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>

class Span
{
public:
	// Constructors and Destructor
	Span(unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	// Member functions
	void addNumber(int number);

	// Template function to add multiple numbers using iterators
	template <typename InputIterator>
	void addNumber(InputIterator begin, InputIterator end)
	{
		if (static_cast<unsigned int>(std::distance(begin, end)) + _numbers.size() > _N)
			throw std::out_of_range("Cannot add more numbers: Span will exceed its maximum capacity");
		_numbers.insert(_numbers.end(), begin, end);
	}

	int shortestSpan() const;
	int longestSpan() const;

private:
	unsigned int _N;
	std::vector<int> _numbers;
};

#endif
