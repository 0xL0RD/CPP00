/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:02:41 by rubsanch          #+#    #+#             */
/*   Updated: 2026/02/11 14:23:44 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	getinput(std::string prompt, std::string *result)
{
	std::cout << prompt;
	getline(std::cin, *result);
	if (std::cin.eof())
	{
		return (-1);
	}
	return (1);
}

int	getinput(std::string prompt, int *r)
{
	std::string	input;

	while (1)
	{
		std::cout << prompt;
		getline(std::cin, input);
		if (std::cin.eof())
			return (-1);
		if (input.length() == 1)
		{
			*r = input[0] - '0';
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
		r = getinput(prompt, &str);
		if (r < 0)
			return (r);
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
	FIRST_NAME_LBL ": ",
	LAST_NAME_LBL ": ",
	NICKNAME_LBL ": ",
	PHONENUMBER_LBL ": ",
	DARKEST_SECRET_LBL ": "
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
		r = cmd_add_core(str[i], &contact, methods[i]);
		if (r < 0)
			return (r);
		i++;
	}
	r = phonebook->add(&contact);
	if (r < 0)
		return (r);
	return (1);
}

std::string	truncate(const std::string strin)
{
	std::string	t;

	t = strin;
	if (t.length() <= TRUNCATE_LEN)
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

int	print_contact(Contact *contact)
{
	std::cout << FIRST_NAME_LBL ": " << contact->first_name_get() << std::endl;
	std::cout << LAST_NAME_LBL ": " << contact->last_name_get() << std::endl;
	std::cout << NICKNAME_LBL ": " << contact->nickname_name_get() << std::endl;
	std::cout << PHONENUMBER_LBL ": " << contact->phonenumber_get() << std::endl;
	std::cout << DARKEST_SECRET_LBL ": " << contact->darkest_secret_get() << std::endl;
	return (1);
}

int	cmd_search(PhoneBook *phonebook)
{
	Contact	*contact;
	int		i;
	int		r;
	std::string	row[4];

	if (phonebook->count_get() == 0)
	{
		std::cout << "Phonebook is empty. " \
			"Plase, ADD contacts first." <<std::endl;
		return (0);
	}
	row[0] = ID_LBL;
	row[1] = FIRST_NAME_LBL;
	row[2] = LAST_NAME_LBL;
	row[3] = NICKNAME_LBL;
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
		r = getinput("Index: ", &i);
		if (r < 0)
			return (r);
		if (i < 0 || i > phonebook->count_get() - 1)
		{
			std::cout << "Wrong index [0-"
				<< phonebook->count_get() - 1 << "].\n";
			continue ;
		}
		break ;
	}
	print_contact(phonebook->get(i));
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
		r = getinput("COMMAND: ", &cmd);
		if (r < 0)
			return (1);
		if (cmd == "EXIT")
			break ;
		if (cmd == "ADD")
		{
			r = cmd_add(&phonebook); 
			if (r < 0)
				break ;
			std::cout << "Contact added" << std::endl;
		}
		if (cmd == "SEARCH")
		{
			r = cmd_search(&phonebook);
			if (r < 0)
				break ;
		}
		std::cout << std::endl;
	}
	return (0);
}
