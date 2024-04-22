#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <list>
#include <deque>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <stdlib.h>

class PmergeMe
{
	private:
		std::deque<int> sequence;
		std::list<int> sequenceList;

		template <typename Iterator>
		void mergeSortDequeHelper(Iterator begin, Iterator end);

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(PmergeMe const& copy);
		PmergeMe& operator=(PmergeMe const& copy);

		PmergeMe(const std::deque<int>& inputSequence) : sequence(inputSequence.begin(), inputSequence.end()), sequenceList(inputSequence.begin(), inputSequence.end()) {}
		void mergeSortDeque();
		void mergeSortList();
		void printUnsortedSequence() const;
		void printSortedSequenceDeque() const;
		void printSortedSequenceList() const;
		void printTimeUsedDeque(clock_t startTime) const;
		void printTimeUsedList(clock_t startTime) const;

};

#endif
