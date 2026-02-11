/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:13:11 by rubsanch          #+#    #+#             */
/*   Updated: 2026/02/11 14:29:44 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# define PHONE_BOOK_LEN 8

# include "Contact.class.hpp"

class PhoneBook {
	private:
		Contact	_contact[PHONE_BOOK_LEN];
		int	_last_inserted;
		int	_count;
	public:
		int	add(Contact *contact);
		Contact *get(int index);
		int	count_get(void);
		PhoneBook(void);
};

#endif
