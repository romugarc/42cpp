#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>

class PmergeMe
{
    private:
        /* data */
    public:
        PmergeMe( void );
        PmergeMe( PmergeMe const &src );
        ~PmergeMe();

        PmergeMe    &operator=( PmergeMe const &rhs );
};

#endif