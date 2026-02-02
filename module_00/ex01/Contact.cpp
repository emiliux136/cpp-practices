/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:37:21 by emilgarc          #+#    #+#             */
/*   Updated: 2026/01/15 11:41:23 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iomanip>

Contact::Contact(void)
{}

Contact::~Contact(void)
{}

std::string Contact::getFirstName(void) const
{
	return(this->FirstName);
}

std::string Contact::getLastName(void) const
{
	return(this->LastName);
}

std::string Contact::getNickName(void) const
{
	return(this->NickName);
}

std::string Contact::getPhoneNumber(void) const
{
	return(this->PhoneNumber);
}

std::string Contact::getSecretShh(void) const
{
	return(this->SecretShh);
}

void	Contact::setFirstName(std::string s)
{
	this->FirstName = s;
}
void	Contact::setLastName(std::string s)
{
	this->LastName = s;
}

void	Contact::setNickName(std::string s)
{
	this->NickName = s;
}
void	Contact::setPhoneNumber(std::string s)
{
	this->PhoneNumber = s;
}
void	Contact::setSecretShh(std::string s)
{
	this->SecretShh = s;
}

bool Contact::setContact()
{
	std::string s;
	s = "";
	while(s == "" && !std::cin.eof())
	{
		std::cout << "Enter a first name: ";
		s = getpropperline();
		if (s != "")
			this->setFirstName(s);
	}
	s = "";
	while(s == "" && !std::cin.eof())  //comprobación recomendada por juan mondon para cortar con ctrl + D
	{
		std::cout << "Enter " << this->FirstName << "'s Last name: ";
		s = getpropperline();
		if(s != "")
			this->setLastName(s);
	}
	s = "";
	while(s == "" && !std::cin.eof())
	{
		std::cout << "Enter " << this->FirstName << "'s Nick name: ";
		s = getpropperline();
		if (s != "")
			this->setNickName(s);
	}
	s = "";
	while(s == "" && !std::cin.eof())
	{
		std::cout << "Enter " << this->FirstName << "'s Phone Number: ";
		s = getpropperline();
		if (s != "")
			this->setPhoneNumber(s);
	}
	s = "";
	while(s == "" && !std::cin.eof())
	{
		std::cout << "Enter " << this->FirstName << "'s darkest secret: ";
		s = getpropperline();
		if (s != "")
			this->setSecretShh(s);
	}
	if (!std::cin.eof())
		std::cout << this->FirstName << " has been successfully added to phonebook." << std::endl;
	if (std::cin.eof())
	{
		std::cout << std::endl << "\nCtrl + D detected.";
		std::cout << this->FirstName << "\nExiting the adding form ..." << std::endl;
	}
	return (true);
}

std::string normalize(const std::string &s)
{
	if (s.size() > 10)
		return s.substr(0, 9) + ".";
	if (s.size() < 10)
		return std::string(10 - s.size(), ' ') + s;
	return s;
}


void Contact::table(PhoneBook con)
{
	int			i;
	std::string	str;
	std::cout << std::endl;
	std::cout << "+___________________________________________+" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|==========|==========|==========|==========|" << std::endl;
	i = 0;
	while (i <= 7)
	{
		Contact c = con.getContact(i);
		if (!c.getFirstName().empty())
		{
			std::cout << "|" << std::setw(10) << (i + 1)
					  << "|" << normalize(c.getFirstName())
					  << "|" << normalize(c.getLastName())
					  << "|" << normalize(c.getNickName())
					  << "|" << std::endl;
		}
		i++;
	}
	std::cout << "+==========-==========-==========-==========+" << std::endl;
	std::cout << std::endl;
}

std::string getpropperline(void)
{
	std::string s;
	std::string result;
	
	std::getline(std::cin, s);
	
	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] == '\t')
			result += ' ';
		else if (i + 1 < s.length() && (unsigned char)s[i] == 0xc3) //Deteccion de ñ en UTF8 (vaya movida)
		{
			if ((unsigned char)s[i + 1] == 0xb1)
			{
				result += 'n';
				i++;
			}
			else if ((unsigned char)s[i + 1] == 0x91)
			{
				result += 'N';
				i++;
			}
			else
			{
				result += s[i];
			}
		}
		else
			result += s[i];
	}
	return (result);
}