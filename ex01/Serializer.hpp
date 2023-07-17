/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:05:24 by corellan          #+#    #+#             */
/*   Updated: 2023/07/17 11:29:16 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <cstdint>
# include <iostream>
# include "Data.hpp"

class	Serializer
{
public:

	static uintptr_t	serialize(Data *ptr);
	static Data			*deserialize(uintptr_t raw);

private:

	Serializer(void);
	Serializer(Serializer const &rhs);
	~Serializer(void);

	Serializer	&operator=(Serializer const &rhs);
};

#endif