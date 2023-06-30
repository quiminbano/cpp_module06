/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:07:12 by corellan          #+#    #+#             */
/*   Updated: 2023/06/30 19:11:25 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main(void)
{
	Base	test;
	Base	*test2;
	Base	*test3;

	test2 = test.generate();
	test3 = test.generate();
	test.identify(test2);
	test.identify(*test3);
	delete test2;
	delete test3;
	return (0);
}