#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
//# define DEBUG

class Data
{
	private:
		int	_num;

	public:
		~Data();
		Data();
		Data(int num);
		Data(const Data &other);
		Data &operator = (const Data &other);

		void	sing(void);
};

#endif
