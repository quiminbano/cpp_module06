/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:31:23 by corellan          #+#    #+#             */
/*   Updated: 2023/07/17 10:03:33 by corellan         ###   ########.fr       */
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

	static void			convert(std::string &input);
	static int			getInteger(void);
	static float		getFloat(void);
	static double		getDouble(void);
	static char			getChar(void);
	static int			getFlag(void);
	static int			getOverChar(void);
	static int			getOverInt(void);
	static int			getOverFloat(void);
	static int			getOverDouble(void);
	static int			getPresicion(void);
	static int			getSciNot(void);
	static std::string	getType(void);

private:

	static int			_integer;
	static float		_float;
	static double		_double;
	static char			_char;
	static int			_flag;
	static int			_overChar;
	static int			_overInt;
	static int			_overFloat;
	static int			_overDouble;
	static int			_presicion;
	static int			_sciNot;
	static std::string	_type;

	ScalarConverter(void);
	ScalarConverter(ScalarConverter const &rhs);
	~ScalarConverter(void);

	ScalarConverter	&operator=(ScalarConverter const &rhs);

	static std::string	_analizer(std::string &input);
	static int			_intAnalizer(std::string &input);
	static int			_floatAnalizer(std::string &input);
	static int			_doubleAnalizer(std::string &input);
	static void			_process(std::string &input);
	static void			_checkOverInt(std::string &input);
	static void			_checkOverFloat(std::string &input);
	static void			_checkOverDouble(std::string &input);
	static int			_checkExponent(size_t &i, std::string &input, int analysis);
	static void			_printChar(void);
	static void			_printInt(void);
	static void			_printFloat(void);
	static void			_printDouble(void);
};

#endif