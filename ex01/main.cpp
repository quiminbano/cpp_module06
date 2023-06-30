/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:21:05 by corellan          #+#    #+#             */
/*   Updated: 2023/06/30 16:16:10 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data		hello;
	Data		*hello2;
	uintptr_t	ptr;

	hello.number = 1;
	std::cout << "Address of hello Data structure: " << &hello << std::endl;
	std::cout << "Content of number in hello data structure: " << hello.number << std::endl;
	ptr = Serializer::serialize(&hello);
	std::cout << "Content of uintptr_t: " << ptr << std::endl;
	std::cout << "Address of uintptr_t: " << &ptr << std::endl;
	hello2 = Serializer::deserialize(ptr);
	std::cout << "Address of hello2 Data structure: " << hello2 << std::endl;
	std::cout << "Content of number in hello2 data structure: " << hello2->number << std::endl;
	return (0);
}