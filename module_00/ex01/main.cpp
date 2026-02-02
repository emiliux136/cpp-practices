/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:55:18 by emilgarc          #+#    #+#             */
/*   Updated: 2026/01/15 13:07:54 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void)
{
	PhoneBook list;
	std::string input;
	
	while(input != "EXIT")
	{
		std::cout << "Type a command -> ";
		getline(std::cin, input);
		if (input == "ADD")
			list.add();
		else if (input == "SEARCH")
			list.search();
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return 0;
		}
	}
	std::cout << "Ciao ciao!" << std::endl;
	return 0;
}