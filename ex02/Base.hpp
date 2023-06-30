/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:17:49 by corellan          #+#    #+#             */
/*   Updated: 2023/06/30 18:58:33 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BASE_HPP
# define BASE_HPP

# include <iostream>

class	Base
{
public:
	virtual	~Base(void);

	Base	*generate(void);
	void	identify(Base *p);
	void	identify(Base &p);
};

#endif