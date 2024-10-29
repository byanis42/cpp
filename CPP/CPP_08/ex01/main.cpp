#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
	// Example provided in the exercise
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl; // Output: 2
		std::cout << sp.longestSpan() << std::endl;  // Output: 14
	}

	// Test with 10,000 numbers
	{
		Span sp(10000);
		srand(time(NULL));
		for (int i = 0; i < 10000; ++i)
		{
			sp.addNumber(rand());
		}
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}

	// Test adding numbers using a range of iterators
	{
		Span sp(5);
		int arr[] = {5, 3, 17, 9, 11};
		std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
		sp.addNumber(vec.begin(), vec.end());

		std::cout << sp.shortestSpan() << std::endl; // Output: 2
		std::cout << sp.longestSpan() << std::endl;  // Output: 14
	}

	// Test exception when adding more numbers than capacity
	try
	{
		Span sp(3);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		sp.addNumber(4); // Should throw exception
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	// Test exception when computing spans with insufficient numbers
	try
	{
		Span sp(1);
		sp.addNumber(42);
		std::cout << sp.shortestSpan() << std::endl; // Should throw exception
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
