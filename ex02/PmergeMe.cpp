#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const& copy)
{
	*this = copy;
}

PmergeMe& PmergeMe::operator=(PmergeMe const& copy)
{
	sequence = copy.sequence;
	sequenceList = copy.sequenceList;

	return *this;
}

void PmergeMe::mergeSortDeque()
{
	if (sequence.size() <= 1)
	{
		return ;
	}

	mergeSortDequeHelper(sequence.begin(), sequence.end());
}

void PmergeMe::mergeSortList()
{
	sequenceList.sort();
}

void PmergeMe::printUnsortedSequence() const
{
	std::cout << "Unsorted Sequence: ";
	for (std::deque<int>::const_iterator it = sequence.begin(); it != sequence.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}

void PmergeMe::printSortedSequenceDeque() const
{
	std::cout << "Sorted Sequence: ";
	for (std::deque<int>::const_iterator it = sequence.begin(); it != sequence.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}

void PmergeMe::printSortedSequenceList() const
{
	std::cout << "Sorted Sequence (List):";
	for (std::list<int>::const_iterator it = sequenceList.begin(); it != sequenceList.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}

void PmergeMe::printTimeUsedDeque(clock_t startTime) const
{
	clock_t endTime = clock();
	double elapsedTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
	double elapsedTimeMicros = elapsedTime * 1e6;
	std::cout << "Time to process for deque: " << std::fixed << std::setprecision(2) << elapsedTimeMicros << " µs." << std::endl;
}

void PmergeMe::printTimeUsedList(clock_t startTime) const
{
	clock_t endTime = clock();
	double elapsedTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
	double elapsedTimeMicros = elapsedTime * 1e6;
	std::cout << "Time to process for list: " << std::fixed << std::setprecision(2) << elapsedTimeMicros << " µs." << std::endl;
}

template <typename Iterator>
void PmergeMe::mergeSortDequeHelper(Iterator begin, Iterator end)
{
	if (end - begin > 1) {
			Iterator middle = begin + (end - begin) / 2;
			mergeSortDequeHelper(begin, middle);
			mergeSortDequeHelper(middle, end);
			std::inplace_merge(begin, middle, end);
		}
}
