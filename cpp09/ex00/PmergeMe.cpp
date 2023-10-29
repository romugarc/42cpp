#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void ) {
}

PmergeMe::PmergeMe( PmergeMe const &src ) {
    (void)src;
}

PmergeMe::~PmergeMe( void ) {
}

PmergeMe    &PmergeMe::operator=( PmergeMe const &rhs ) {
    (void)rhs;
    return *this;
}