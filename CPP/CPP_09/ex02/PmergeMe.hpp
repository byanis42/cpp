#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void sortSequence(char **argv);

private:
	std::vector<int> _vectorSequence;
	std::deque<int> _dequeSequence;

	void parseInput(char **argv);

	void fordJohnsonSort(std::vector<int> &sequence);
	void fordJohnsonSort(std::deque<int> &sequence);

	void insertMinimaVector(std::vector<int> &sortedMaxima, std::vector<int> &minima);
	void insertMinimaDeque(std::deque<int> &sortedMaxima, std::deque<int> &minima);

	void printSequence(const std::string &label, const std::vector<int> &sequence) const;
	void printSequence(const std::string &label, const std::deque<int> &sequence) const;

	std::vector<size_t> generateJacobsthalSequence(size_t n);
};

#endif
