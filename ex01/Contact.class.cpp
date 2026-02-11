/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:31:52 by rubsanch          #+#    #+#             */
/*   Updated: 2026/02/11 12:38:00 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

int	Contact::isEmpty(const std::string *str)
{
	if (str->empty() == 1)
		return (1);
	if (str->find_first_not_of(" \f\n\r\t\v") == std::string::npos)
		return (1);
	return (0);
}

int	Contact::isPhoneNumber(const std::string *str)
{
	if (str->find_first_not_of("0123456789") != std::string::npos)
		return (0);
	return (1);
}

int	Contact::isValid(void)
{
	if (this->_first_name.empty() == 1
		|| this->_last_name.empty() == 1
		|| this->_nickname.empty() == 1
		|| this->_phonenumber.empty() == 1
		|| this->_darkest_secret.empty() == 1
	   )
		return (0);
	return (1);
}

int	Contact::first_name_set(std::string *v)
{
	//TODO: if only spaces --> invalid
	//if ((*v).empty() == 1)
	if (isEmpty(v) == 1)
		return (-1);
	this->_first_name = *v;
	return (1);
}

int	Contact::last_name_set(std::string *v)
{
	//if ((*v).empty() == 1)
	if (isEmpty(v) == 1)
		return (-1);
	this->_last_name = *v;
	return (1);
}

int	Contact::nickname_name_set(std::string *v)
{
	//if ((*v).empty() == 1)
	if (isEmpty(v) == 1)
		return (-1);
	this->_nickname = *v;
	return (1);
}

int	Contact::phonenumber_set(std::string *v)
{
	//if ((*v).empty() == 1)
	if (isEmpty(v) == 1)
		return (-1);
	if (this->isPhoneNumber(v) == 0)
		return (-1);
	this->_phonenumber = *v;
	return (1);
}

int	Contact::darkest_secret_set(std::string *v)
{
	if ((*v).empty() == 1)
		return (-1);
	this->_darkest_secret = *v;
	return (1);
}

std::string	Contact::first_name_get(void)
{
	return (this->_first_name);
}

std::string	Contact::last_name_get(void)
{
	return (this->_last_name);
}

std::string	Contact::nickname_name_get(void)
{
	return (this->_nickname);
}

std::string	Contact::phonenumber_get(void)
{
	return (this->_phonenumber);
}

std::string	Contact::darkest_secret_get(void)
{
	return (this->_darkest_secret);
}
