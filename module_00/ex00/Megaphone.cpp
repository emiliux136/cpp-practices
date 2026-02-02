/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:06:14 by emilgarc          #+#    #+#             */
/*   Updated: 2026/01/12 16:17:11 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int i;
	int j = 0;
	
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (argc > 1 && argv[j])
	{
		i = 0;
		while (j > 0 && argv[j][i])
		{
			std::cout << (char)std::toupper(argv[j][i]);
			i++;
		}
		j++;
	}
		std::cout << std::endl;
		return (0);
}
