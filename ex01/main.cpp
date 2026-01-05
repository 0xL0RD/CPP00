/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:22:06 by rubsanch          #+#    #+#             */
/*   Updated: 2026/01/05 09:42:45 by rubsanch         ###   ########.fr       */
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

/*
int	cmd_add(void)
{

}
*/

int	main(int argc, char *argv[])
{
	std::string cmd;

	(void) argv;
	if (argc > 1)
		return (1);
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
		std::cout << cmd;
		std::cout << std::endl;
	}
	return (0);
}
