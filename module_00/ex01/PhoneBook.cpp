/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:09:06 by emilgarc          #+#    #+#             */
/*   Updated: 2026/01/15 13:26:03 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_index = 0;
	this->_full = false;
	std::cout << \
		"Hello user! You have just created an 8 contacts empty phonebook." \
		<< std::endl;
}

PhoneBook::~PhoneBook()
{
	if(std::cin.eof())
		std::cout << "Ciao ciao!" << std::endl;
}

void PhoneBook::add(void)
{
	std::string input;
	if (this->_full == false)
	{
		std::cout << "This is your contact number #" << this->_index + 1 << std::endl;
		if (this->_contacts[this->_index].setContact() == true)
		{
			if (this->_index == 7)
			{
				this->_full = true;
			}
			else
				this->_index++;
		}
	}
	else if (this->_full == true)
	{
		std::cout << "Your PhoneBook is full\nIf you want to add another contact I will delete the #1 contact you add\n";
		std::cout << "if you want to proceed press 'y' and 'Enter' to confirm,\nif not, press any other key and 'Enter' to go back to menu\n";
		getline(std::cin, input);
		if (std::cin.eof() == true)
		{
			std::cout << "Exiting the program\n" << std::endl;
			std::exit(0);
		}
		if(input.compare("y") == 0)
		{
			int i = 1;
			while (i < 8)
			{
            	this->_contacts[i - 1] = this->_contacts[i];
				i++;
			}
        	std::cout << "This is your contact #8" << std::endl;
        	this->_contacts[this->_index].setContact();
		}
		else
			std::cout << "Back to main menu without deleting and creating a contact." << std::endl;
	}
}

void PhoneBook::search()
{
	std::string input;
	
	if (this->_index == 0 && this->_full == false)
	{
		std::cout << "You don't have any contact yet." << std::endl;
		return;
	}
	else
	{
		Contact tmp;
		tmp.table(*this);
		std::cout << "Type an index to see more information,\nor type 'BACK' to return to main menu." << std::endl;
		while(!std::cin.eof())
		{
			std::cout << "-> ";
			if(std::getline(std::cin, input) && input != "")
			{
				if(input.size() == 1 && input[0] >= '1' && input[0] <= '8' && this->_contacts[input[0] - 1 - '0'].getFirstName().size())
				{
					std::cout << "Searching information ..." << std::endl;
					this->print(this->_contacts[input[0] - 1 - '0']);
					break ;
				}
				else if (input == "BACK")
				{
					std::cout << "Going back to main menu ..." << std::endl;
					return;
				}
				else if (input != "")
					std::cout << "Invalid index." << std::endl;
			}
		}
	}
}

void	PhoneBook::print(Contact contact)
{
	std::cout << std::endl;
	std::cout << "First Name: " << contact.getFirstName() << std::endl;
	std::cout << "Last Name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickName() << std::endl;
	std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contact.getSecretShh() << std::endl;
	std::cout << std::endl;
}

Contact PhoneBook::getContact(int index)
{
	if (index < 0 || index >= 8)
		return Contact();
	return this->_contacts[index];
}