/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:50:22 by rubsanch          #+#    #+#             */
/*   Updated: 2026/01/04 19:13:23 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstddef>

void	replace_space(std::string str)
{
	size_t	pos;
	const std::string space = " \f\n\r\t\v";

	pos = 0;
	std::cout << str << std::endl;
	while (1)
	{
		pos = str.find_first_of(space, pos);
		std::cout << pos << std::endl;
		std::cout << "size: " << str.length() << std::endl;
		if (pos == str.length() - 1)
			break;
		pos++;
		//str.replace(pos, -1, " ");
	}
	std::cout << "-----------------" << std::endl;
	while (1)
	{
		pos = str.find("  ");
		//if (pos == str.length() -1)
		//if (pos == 18446744073709551615)
		//if (pos == (size_t) -1)
		if (pos == std::string::npos)
			break;
		str.replace(pos, 2, " ");
		pos++;
	}
	//str.replace(str.begin(), str.end(), "I
	std::cout << str << std::endl;
	std::cout << "2-----------------" << std::endl;
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	std::string params = "";

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		params.append(std::string(argv[i])).append(" ");;
		i++;
	}
	replace_space(params);
	std::cout << params << std::endl;
	return (0);
}
