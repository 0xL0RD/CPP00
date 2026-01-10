/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:09:42 by rubsanch          #+#    #+#             */
/*   Updated: 2026/01/08 17:49:19 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <string>
#include <iostream>

class Contact {
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phonenumber;
		std::string	_darkest_secret;
		int		isPhoneNumber(std::string str);
	public:
		int		first_name_set(std::string *v);
		int		last_name_set(std::string *v);
		int		nickname_name_set(std::string *v);
		int		phonenumber_set(std::string *v);
		int		darkest_secret_set(std::string *v);
		std::string	first_name_get(void);
		std::string	last_name_get(void);
		std::string	nickname_name_get(void);
		std::string	phonenumber_get(void);
		std::string	darkest_secret_get(void);
		int		isValid();
};

#endif
