/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:31:22 by rubsanch          #+#    #+#             */
/*   Updated: 2026/01/10 10:43:35 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include <iostream>

PhoneBook::PhoneBook(void) : _last_inserted(-1), _count(0)
{
	//this->_last_inserted = -1;
	//this->_count = 0;
}

int	PhoneBook::add(Contact *contact)
{
	int	i;

	i = this->_last_inserted;
	std::cout << "last inserted: " << i << std::endl;
	if (i == -1)
		i = 0;
	else
		i++;
	i = i % PHONE_BOOK_LEN;
	if (contact->isValid() == 0)
		return (-1);
	std::cout << "adding to i: " << i << std::endl;
	this->_contact[i] = *contact;
	this->_count++;
	if (this->_count > PHONE_BOOK_LEN)
		this->_count = PHONE_BOOK_LEN;
	this->_last_inserted = i;
	return (1);
}

int	PhoneBook::count_get(void)
{
	return (this->_count);
}

Contact *PhoneBook::get(int index)
{
	if (index >= this->_count)
		return (NULL);
	if (index < 0)
		return (NULL);
	return (&this->_contact[index]);
	
}
