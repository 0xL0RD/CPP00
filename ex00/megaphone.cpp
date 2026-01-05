/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:50:22 by rubsanch          #+#    #+#             */
/*   Updated: 2026/01/05 08:51:40 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstddef>

int	replace_space(std::string str)
{
	size_t	pos;
	const std::string space = " \f\n\r\t\v";

	if (str.length() < 2)
		return (0);
	pos = 0;
	//std::cout << str << std::endl;
	while (1)
	{
		pos = str.find_first_of(space, pos);
		//std::cout << pos << std::endl;
		//std::cout << "size: " << str.length() << std::endl;
		//std::cout << "pos : " << pos << std::endl;
		if (pos == std::string::npos || pos == str.length() - 1)
		{
			//std::cout << "break" << std::endl;
			break;
		}
		pos++;
		//std::cout << "next" << std::endl;
	}
	//std::cout << "-----------------" << std::endl;
	while (1)
	{
		pos = str.find("  ");
		if (pos == std::string::npos)
		{
			//std::cout << "break2" << std::endl;
			break;
		}
		str.replace(pos, 2, " ");
	}
	if (str.find_first_of(space) == 0)
		str.erase(0, 1);
	//std::cout << "len3: " << str.length() << std::endl;
	if (str.find_last_of(space, std::string::npos) == str.length() - 1)
		str.erase(str.length() - 1);
	//std::cout << "len4: " << str.length() << std::endl;
	if (str.length() < 1)
		return (0);
	for (long unsigned int i = 0; i <= str.length() - 1; i++)
		str.at(i) = toupper(str.at(i));
	std::cout << str << std::endl;
	//std::cout << "2-----------------" << std::endl;
	return (1);
}

void	default_msg(void)
{
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}

int	main(int argc, char *argv[])
{
	int	i;
	std::string params = "";

	i = 1;
	while (i < argc)
	{
		params.append(std::string(argv[i])).append(" ");;
		i++;
	}
	if (replace_space(params) == 0)
	{
		default_msg();	
	}
	//std::cout << params << std::endl;
	return (0);
}
