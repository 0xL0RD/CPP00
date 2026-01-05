/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:22:06 by rubsanch          #+#    #+#             */
/*   Updated: 2026/01/05 10:57:49 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	getinput(std::string prompt, std::string *result)
{
	std::cout << prompt;
	std::cin >> *result;		//TODO: fix crl+D infinite loop
	//std::cout << resultI/;
	return (1);
}

int	isPhoneNumber(std::string str)
{
	if (str.find_first_not_of("0123456789") != std::string::npos)
		return (0);
	return (1);
}

int	cmd_add(void)
{
	const std::string	prompt[] = {
	 "First name",
	 "Last name",
	 "Nickname",
	 "Phone number",
	 "Darkest secret"
	};
	std::string		value[5];
	int			r;
	long unsigned int	i;

	i = 0;
	//for (long unsigned int i = 0; i < sizeof(prompt) / sizeof(prompt[0]); i++)
	while (i < sizeof(prompt) / sizeof(prompt[0]))
	{
	 	r = getinput(prompt[i] + ": ", &value[i]);
		if (r < 0)
			return (-1);
		if (prompt[i] == "Phone number")
		{
			if (isPhoneNumber(value[i]) == 0)
			{
				std::cout << "Wrong phone number." << std::endl;
				continue ;
			}
		}
		std::cout << value[i] << std::endl;
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	std::string	cmd;
	int		r;

	(void) argv;
	if (argc > 1)
		return (1);
	std::cout << "· --=== Phonebook app ===-- ·" << std::endl << std::endl;
	std::cout << "Allowed commands: ADD, SEARCH and EXIT." << std::endl;
	while (1)
	{
		/*
		std::cout << "COMMAND: ";
		std::cin >> cmd;		//TODO: fix crl+D infinite loop
		std::cout << cmd;
		*/
		getinput("COMMAND: ", &cmd);
		if (cmd == "EXIT")
			break ;
		if (cmd == "ADD")
		{
			r = cmd_add(); 
			if (r < 0)
				break ;
		}
		std::cout << cmd;
		std::cout << std::endl;
	}
	return (0);
}
