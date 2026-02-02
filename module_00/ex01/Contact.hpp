/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:38:44 by emilgarc          #+#    #+#             */
/*   Updated: 2026/01/15 11:36:56 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP

# define CONTACT_HPP

# include <iostream>
# include <string>

class PhoneBook;

class	Contact
{
	private:
		std::string FirstName;
		std::string LastName;
		std::string NickName;
		std::string PhoneNumber;
		std::string SecretShh;
	public:
		Contact(void);
		~Contact(void);
		std::string getFirstName (void) const;
		std::string getLastName (void) const;
		std::string getNickName (void) const;
		std::string getPhoneNumber (void) const;
		std::string getSecretShh (void) const;
		bool setContact (void);
		void table(PhoneBook con);
		void setFirstName (std::string s);
		void setLastName (std::string s);
		void setNickName (std::string s);
		void setPhoneNumber (std::string s);
		void setSecretShh (std::string s);
};

std::string getpropperline(void);

#endif
