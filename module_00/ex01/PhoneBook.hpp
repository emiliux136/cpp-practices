/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:57:31 by emilgarc          #+#    #+#             */
/*   Updated: 2026/01/15 13:30:47 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP

# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>

class PhoneBook
{
	private:
		Contact _contacts[8];
		int		_index;
		bool	_full;
		
	public:
		PhoneBook();
		~PhoneBook();
		void add(void);
		void search(void);
		void print(Contact Contact);
		Contact getContact(int index);
};

#endif