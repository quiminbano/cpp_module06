/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:23:21 by corellan          #+#    #+#             */
/*   Updated: 2023/07/16 20:12:24 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void)
{
	std::cout << "Destructor for the Base class called" << std::endl;
	return ;
}

Base	*Base::generate(void)
{
	int		random;
	Base	*ptr;

	ptr = NULL;
	std::srand(std::time(NULL));
	random = ((rand() % 3) + 1);
	if (random == 1)
		ptr = new A();
	else if (random == 2)
		ptr = new B();
	else if (random == 3)
		ptr = new C();
	return (ptr);
}

void	Base::identify(Base *p)
{
	if (p == NULL)
		std::cout << "Wait! You are trying to analyze a NULL pointer" << std::endl;
	else if (dynamic_cast<A *>(p) != NULL)
		std::cout << "The Base pointer passed as a parameter was initialized with the A class" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "The Base pointer passed as a parameter was initialized with the B class" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "The Base pointer passed as a parameter was initialized with the C class" << std::endl;
	else
		std::cout << "The Base pointer passed as a parameter was initialized neither A, B nor C class" << std::endl;
	return ;
}

void	Base::identify(Base &p)
{
	Base b;

	try
	{
		b = dynamic_cast<A &>(p);
	}
	catch(const std::exception& e)
	{
		try
		{
			b = dynamic_cast<B &>(p);
		}
		catch(const std::exception& e)
		{
			try
			{
				b = dynamic_cast<C &>(p);
			}
			catch(const std::exception& e)
			{
				std::cout << "The reference of the Base class passed as a parameter was initialized neither A, B nor C class" << std::endl;
				return ;
			}
			std::cout << "The reference of the Base class passed as a parameter was initialized with the C class" << std::endl;
			return ;
		}
		std::cout << "TThe reference of the Base class passed as a parameter was initialized with the B class" << std::endl;
		return ;
	}
	std::cout << "The reference of the Base class passed as a parameter was initialized with the A class" << std::endl;
	return ;
}
