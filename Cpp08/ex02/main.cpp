#include "MutantStack.hpp"

int	main()
{
MutantStack<int> mstack;
mstack.push(5);

std::cout << mstack.top() << std::endl;
}
