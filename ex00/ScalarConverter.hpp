/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:31:23 by corellan          #+#    #+#             */
/*   Updated: 2023/06/28 02:17:53 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <cmath>
# include <iomanip>
# include <float.h>

class	ScalarConverter
{
public:

	ScalarConverter(void);
	ScalarConverter(ScalarConverter const &rhs);
	~ScalarConverter(void);

	ScalarConverter	&operator=(ScalarConverter const &rhs);

	void		convert(std::string &input);
	int			getInteger(void) const;
	float		getFloat(void) const;
	double		getDouble(void) const;
	char		getChar(void) const;
	int			getFlag(void) const;
	int			getOverChar(void) const;
	int			getOverInt(void) const;
	int			getOverFloat(void) const;
	int			getOverDouble(void) const;
	int			getPresicion(void) const;
	std::string	getType(void) const;

private:

	int			_integer;
	float		_float;
	double		_double;
	char		_char;
	int			_flag;
	int			_overChar;
	int			_overInt;
	int			_overFloat;
	int			_overDouble;
	int			_presicion;
	std::string	_type;

	std::string	_analizer(std::string &input);
	int			_intAnalizer(std::string &input);
	int			_floatAnalizer(std::string &input);
	int			_doubleAnalizer(std::string &input);
	void		_process(std::string &input);
	void		_checkOverInt(std::string &input);
	void		_checkOverFloat(std::string &input);
	void		_checkOverDouble(std::string &input);
	void		_printChar(void);
	void		_printInt(void);
	void		_printFloat(void);
	void		_printDouble(void);
};

#endif