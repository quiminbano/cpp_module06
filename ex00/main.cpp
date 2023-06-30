/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:33:40 by corellan          #+#    #+#             */
/*   Updated: 2023/06/30 10:45:10 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	std::string	input;

	if (argc != 2)
	{
		std::cerr << "Input error" << std::endl;
		return (1);
	}
	input = argv[1];
	ScalarConverter::convert(input);
	return (0);
}
