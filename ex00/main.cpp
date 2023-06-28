/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:33:40 by corellan          #+#    #+#             */
/*   Updated: 2023/06/27 12:32:23 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	ScalarConverter	tool;
	std::string		input;

	if (argc != 2)
	{
		std::cerr << "Input error" << std::endl;
		return (1);
	}
	input = argv[1];
	tool.convert(input);
	return (0);
}
