/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:32:41 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/11 11:17:40 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstring>

//#define DEBUG
// Returns a string: <filename>.replace
static std::string	fileDotReplace(const char *s)
{
	std::string	filename(s);
	std::string	newFileStr;

	newFileStr = filename + ".replace";
	return (newFileStr);
}

// copies the content of <filename> in <filename>.replace
// while replacing every occurence of <s1> with <s2>
static void	ft_replace(std::ifstream &ifs, const std::string newFileStr,
		const std::string str1, const std::string str2)
{
	const char		*newFile = &newFileStr[0];
	std::ofstream	ofs(newFile, std::ofstream::out);
	int				len = (int)str1.length();
	std::string		line;
	std::string		tmp_after;
	std::string		tmp_before;
	int				pos;

#ifdef DEBUG
	std::cout << len << std::endl;
#endif
	while (std::getline(ifs, line))
	{
		pos = (int)line.find(str1);
#ifdef DEBUG
		std::cout << pos << std::endl;
#endif
		if (pos >= 0)
		{
			while (pos >= 0)
			{
				tmp_before = line.substr(0, (long unsigned int)pos);
				tmp_after = line.substr((long unsigned int)(pos + len));
#ifdef DEBUG
				std::cout << "tmp_before : " << tmp_before << std::endl;
				std::cout << "tmp_after : " << tmp_after << std::endl;
#endif
				ofs << tmp_before;
				ofs << str2;
				pos = (int)tmp_after.find(str1);
				if (pos < 0 || tmp_after == "")
				{
					ofs << tmp_after << std::endl;
					break ;
				}
				line = tmp_after;
#ifdef DEBUG
				std::cout << "End of loop" << std::endl;
#endif
			}
		}
		else
			ofs << line << std::endl;
	}
	ofs.close();
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Error: program takes three parameters" << std::endl;
		std::cout << "./ex04 <filename> <string1> <string2>" << std::endl;
		return (0);
	}
	std::ifstream ifs;
	ifs.open(av[1], std::ios_base::in);
	if (ifs.is_open() == true)
	{
		std::cout << "File is opened" << std::endl;

		const std::string	str1(av[2]);
		if (str1 == "")
		{
			std::cout << "Invalid parameter for <string1>" << std::endl;
			return (0);
		}
		const std::string	str2(av[3]);
		const std::string	newFileStr = fileDotReplace(av[1]);
		ft_replace(ifs, newFileStr, str1, str2);
		ifs.close();
	}
	else
		std::cout << "Could not open file" << std::endl;
	return (0);
}
