/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:13:11 by rubsanch          #+#    #+#             */
/*   Updated: 2026/01/05 13:34:28 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

class PhoneBook {
	public:
		//int	add(char *first_name, second_name....
		//int	add(char *ar[5]);
		int	add(Contact *contact);
	private:
		Contact	contact[8];
}
