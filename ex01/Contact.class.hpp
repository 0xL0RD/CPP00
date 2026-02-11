/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:09:42 by rubsanch          #+#    #+#             */
/*   Updated: 2026/02/11 12:34:37 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <string>
# include <iostream>

# define ID_LBL "Id"
# define FIRST_NAME_LBL "First name"
# define LAST_NAME_LBL "Last name"
# define NICKNAME_LBL "Nickname"
# define PHONENUMBER_LBL "Phonenumber"
# define DARKEST_SECRET_LBL "Darkest secret"

class Contact {
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phonenumber;
		std::string	_darkest_secret;
		int		isPhoneNumber(const std::string *str);
		int		isEmpty(const std::string *str);
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
