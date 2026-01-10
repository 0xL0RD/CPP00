/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:02:41 by rubsanch          #+#    #+#             */
/*   Updated: 2026/01/10 11:26:53 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"
#include <iomanip>
#include "main.hpp"

int	getinput(std::string prompt, std::string *result)
{
	std::cout << prompt;
	std::cin >> *result;		//TODO: fix crl+D infinite loop
					//TODO: fix when user inserts just \n
	return (1);
}

int	getinput(std::string prompt, int *r)
{
	char	c;

	while (1)
	{
		std::cout << prompt;
		std::cin >> c;
		if (c >= '0' && c <= '9')
		{
			*r = c + '0';
			return (1);
		}
		std::cout << "Wrong value, try again." << std::endl;
	}
	return (-1);
}

int	cmd_add_core(
		std::string prompt,
		Contact *c,
		int (Contact::*f)(std::string *v))
{
	std::string	str;
	int		r;

	while (1)
	{
		getinput(prompt, &str);
		r = (c->*f)(&str);
		if (r > 0)
			break ;
	}
	return (1);
}

int	cmd_add(PhoneBook *phonebook)
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
		r = cmd_add_core(str[i], &contact, methods[i]);
		if (r < 0)
			return (r);
		i++;
	}
	/*
	r = cmd_add_core("First name: ", contact, &Contact::first_name_set);
	if (r < 0)
		return (r);
		*/
	r = phonebook->add(&contact);
	if (r < 0)
		return (r);
	std::cout << contact.first_name_get() << std::endl;
	std::cout << contact.last_name_get() << std::endl;
	return (1);
}

std::string	truncate(const std::string strin)
{
	std::string	t;

	t = strin;
	if (t.length() < TRUNCATE_LEN)
		return (t);
	t.resize(TRUNCATE_LEN);
	t[TRUNCATE_LEN - 1] = TRUNCATE_CHAR;
	return (t);
}

void	print_row_separator(void)
{
	std::cout << std::string(10 * 4 + 4 + 1, '-');
	std::cout << std::endl;
}

void	print_table_row(const std::string (&field)[4])
{
	std::cout << "|" << std::setw(10) << truncate(field[0]);
	std::cout << "|" << std::setw(10) << truncate(field[1]);
	std::cout << "|" << std::setw(10) << truncate(field[2]);
	std::cout << "|" << std::setw(10) << truncate(field[3]);
	std::cout << "|" << std::endl;
}

int	cmd_search(PhoneBook *phonebook)
{
	Contact	*contact;
	int		i;
	std::string	row[4];

	//std::cout << std::setw(10);
	if (phonebook->count_get() == 0)
	{
		std::cout << "Phonebook is empty. " \
			"Plase, ADD contacts first." <<std::endl;
		return (0);
	}
	row[0] = "Id";
	row[1] = "First name";
	row[2] = "Last name";
	row[3] = "Nickname";
	print_row_separator();
	print_table_row(row);
	print_row_separator();
	i = 0;
	while (i < phonebook->count_get())
	{
		contact = phonebook->get(i);
		row[0] = i + '0';
		row[1] = contact->first_name_get();
		row[2] = contact->last_name_get();
		row[3] = contact->nickname_name_get();
		print_table_row(row);
		print_row_separator();
		i++;
	}
	while (1)
	{
		getinput("Index: ", &i);
		std::cout << "i choosen is " << i;
		if (i < 0 || i > phonebook->count_get() - 1)
		{
			std::cout << "Wrong index [0-" << phonebook->count_get() << "].";
		}
		break ;
	}
	

	return (1);
}

int	main(int argc, char *argv[])
{
	std::string	cmd;
	int		r;
	PhoneBook	phonebook;

	(void) argv;
	if (argc > 1)
		return (1);
	std::cout << "· --=== PhoneBook app ===-- ·" << std::endl << std::endl;
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
			r = cmd_add(&phonebook); 
			if (r < 0)
				break ;
		}
		if (cmd == "SEARCH")
		{
			r = cmd_search(&phonebook);
			if (r < 0)
				break ;
		}
		//std::cout << cmd;
		std::cout << std::endl;
	}
	return (0);
}
