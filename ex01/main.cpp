/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:02:41 by rubsanch          #+#    #+#             */
/*   Updated: 2026/01/08 16:57:03 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.class.hpp"

int	getinput(std::string prompt, std::string *result)
{
	std::cout << prompt;
	std::cin >> *result;		//TODO: fix crl+D infinite loop
	return (1);
}

int	cmd_add_core(
		std::string prompt,
		Contact& c,
		int (Contact::*f)(std::string *v))
{
	std::string	str;
	int		r;

	while (1)
	{
		getinput(prompt, &str);
		r = (c.*f)(&str);
		if (r > 0)
			break ;
	}
	return (1);
}

int	cmd_add(void)
{
	Contact		contact;
	std::string	str[] = {
	"First name: ",
	"Last name: ",
	"Nickname: ",
	"Phonenumber: ",
	"Darkest secret: "
	};
	int		r;
	int		(Contact::*methods[])(std::string *v) = {
				&Contact::first_name_set,
				&Contact::last_name_set,
				&Contact::nickname_name_set,
				&Contact::phonenumber_set,
				&Contact::darkest_secret_set
	};
	size_t		i;
	
	i = 0;
	while (i < sizeof(methods) / sizeof(methods[0]))
	{
		//r = cmd_add_core("First name: ", contact, methods[i]);
		r = cmd_add_core(str[i], contact, methods[i]);
		if (r < 0)
			return (r);
		i++;
	}
	/*
	r = cmd_add_core("First name: ", contact, &Contact::first_name_set);
	if (r < 0)
		return (r);
		*/
	std::cout << contact.first_name_get() << std::endl;
	std::cout << contact.last_name_get() << std::endl;
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
		//std::cout << cmd;
		std::cout << std::endl;
	}
	return (0);
}
