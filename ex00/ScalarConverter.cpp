/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:14:43 by corellan          #+#    #+#             */
/*   Updated: 2023/06/28 03:29:54 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) : _integer(0), _float(0), _double(0), _char(0), _flag(0), _overChar(0), _overInt(0), _overFloat(0), _overDouble(0), _presicion(0), _type("unknown")
{
	std::cout << "Default constructor for ScalarConverter class called" << std::endl;
	return ;
}

ScalarConverter::ScalarConverter(ScalarConverter const &rhs)
{
	std::cout << "Copy constructor for ScalarConverter class called" << std::endl;
	*this = rhs;
	return ;
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &rhs)
{
	std::cout << "Copy assigment operator for ScalarConverter class called" << std::endl;
	if (this != &rhs)
	{
		this->_integer = rhs.getInteger();
		this->_char = rhs.getChar();
		this->_float = rhs.getFloat();
		this->_double = rhs.getDouble();
		this->_flag = rhs.getFlag();
		this->_overChar = rhs.getOverChar();
		this->_overInt = rhs.getOverInt();
		this->_overFloat = rhs.getOverFloat();
		this->_overDouble = rhs.getOverDouble();
		this->_presicion = rhs.getPresicion();
		this->_type = rhs.getType();
	}
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "Default destructor for ScalarConverter class called" << std::endl;
	return ;
}

int	ScalarConverter::_doubleAnalizer(std::string &input)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	while (input[i] >= '0' && input[i] <= '9')
		i++;
	if (input[i] != '.')
		return (0);
	i++;
	while (input[i] >= '0' && input[i] <= '9')
	{
		i++;
		j++;
	}
	this->_presicion = j;
	if (input.size() == i)
		return (1);
	return (0);
}

int	ScalarConverter::_floatAnalizer(std::string &input)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	while (input[i] >= '0' && input[i] <= '9')
		i++;
	if (input[i] != '.')
		return (0);
	i++;
	while (input[i] >= '0' && input[i] <= '9')
	{
		i++;
		j++;
	}
	if (input[i] != 'f')
		return (0);
	this->_presicion = j;
	i++;
	if (input.size() == i)
		return (1);
	return (0);
}

int	ScalarConverter::_intAnalizer(std::string &input)
{
	size_t	i;

	i = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	while (input[i] >= '0' && input[i] <= '9')
		i++;
	if (input.size() == i)
		return (1);
	return (0);
}

std::string	ScalarConverter::_analizer(std::string &input)
{
	if (input.size() == 0)
		return ("char");
	else if ((input.size() == 1) && (input[0] < '0' || input[0] > '9'))
		return ("char");
	else if (this->_intAnalizer(input) == 1)
		return ("int");
	else if (this->_floatAnalizer(input) == 1)
		return ("float");
	else if (this->_doubleAnalizer(input) == 1)
		return ("double");
	return ("string");
}

void	ScalarConverter::_checkOverInt(std::string &input)
{
	std::istringstream	iss;
	std::istringstream	iss2;
	long double			num;

	iss.str(input);
	iss >> this->_integer;
	num = 0;
	if (iss.fail() == false)
	{
		this->_char = static_cast<char>(this->_integer);
		this->_float = static_cast<float>(this->_integer);
		this->_double = static_cast<double>(this->_integer);
		if (this->_integer > 127 || this->_integer < 0)
			this->_overChar = 1;
		return ;
	}
	this->_overInt = 1;
	iss2.str(input);
	iss2 >> num;
	if (iss2.fail() == false)
	{
		this->_char = static_cast<char>(this->_integer);
		this->_float = static_cast<float>(num);
		if (num > FLT_MAX || num < ((-1.0) * FLT_MAX))
			this->_overFloat = 1;
		this->_double = static_cast<double>(num);
		if (num > DBL_MAX || (num < ((-1.0) * DBL_MAX)))
			this->_overDouble = 1;
		this->_overChar = 1;
		return ;
	}
	this->_overChar = 1;
	this->_overInt = 1;
	return ;
}

void	ScalarConverter::_checkOverFloat(std::string &input)
{
	std::istringstream	iss;
	std::istringstream	iss2;
	long long			num;
	long double			num2;
	size_t				temp;

	temp = input.size();
	iss.str(input.substr(0, (temp - 1)));
	iss >> this->_float;
	if (iss.fail() == false)
	{
		num = static_cast<long long>(this->_float);
		this->_integer = static_cast<int>(this->_float);
		if (num != static_cast<long long>(this->_integer))
		{
			this->_overInt = 1;
			this->_overChar = 1;
		}
		else
		{
			if (this->_integer > 127 || this->_integer < 0)
				this->_overChar = 1;
		}
		this->_char = static_cast<char>(this->_float);
		this->_double = static_cast<double>(this->_float);
		return ;
	}
	iss2.str(input);
	iss2 >> num2;
	this->_overFloat = 1;
	if (iss2.fail() == false)
	{
		if (std::abs(num2) < FLT_MIN)
		{
			this->_integer = static_cast<int>(num2);
			this->_char = static_cast<char>(num2);
		}
		if ((std::abs(num2) > DBL_MAX) || (std::abs(num2) < DBL_MIN))
		{
			this->_overDouble = 1;
			if (std::abs(num2) > DBL_MAX)
			{
				this->_overChar = 1;
				this->_overInt = 1;
			}
		}
		this->_double = static_cast<double>(num2);
		return ;
	}
	if (static_cast<int>(num2) == 0)
	{
		this->_integer = static_cast<int>(num2);
		this->_char = static_cast<char>(num2);
		this->_overDouble = 1;
		return ;
	}
	this->_overInt = 1;
	this->_overChar = 1;
	this->_overDouble = 1;
	return ;
}

void	ScalarConverter::_checkOverDouble(std::string &input)
{
	std::istringstream	iss;
	long long			num;

	iss.str(input);
	iss >> this->_double;
	if (iss.fail() == false)
	{
		num = static_cast<long long>(this->_double);
		this->_integer = static_cast<int>(this->_double);
		this->_char = static_cast<char>(this->_double);
		if (num != static_cast<long long>(this->_integer))
		{
			this->_overInt = 1;
			this->_overChar = 1;
		}
		else
		{
			if (this->_integer > 127 || this->_integer < 0)
				this->_overChar = 1;
		}
		this->_float = static_cast<float>(this->_double);
		if ((std::abs(this->_double) > FLT_MAX) || (std::abs(this->_double) < FLT_MIN))
			this->_overFloat = 1;
		return ;
	}
	this->_overFloat = 1;
	this->_overDouble = 1;
	if (static_cast<int>(this->_double) == 0)
	{
		this->_char = static_cast<char>(this->_double);
		this->_integer = static_cast<int>(this->_double);
	}
	else
	{
		this->_integer = 1;
		this->_char = 1;
	}
	return ;
}

void	ScalarConverter::_process(std::string &input)
{
	this->_type = this->_analizer(input);
	if ((!this->_type.compare("string")) && (!input.compare("nan") || !input.compare("nanf")))
	{
		this->_double = nan(input.c_str());
		this->_float = nanf(input.c_str());
		this->_flag = 1;
	}
	else if ((!this->_type.compare("string")) && (!input.compare("+inf") || !input.compare("+inff")))
	{
		this->_double = HUGE_VAL;
		this->_float = HUGE_VALF;
		this->_flag = 2;
	}
	else if ((!this->_type.compare("string")) && (!input.compare("-inf") || !input.compare("-inff")))
	{
		this->_double = ((-1.0) * HUGE_VAL);
		this->_float = ((-1.0) * HUGE_VALF);
		this->_flag = 3;
	}
	else if (!this->_type.compare("char"))
	{
		this->_char = input[0];
		this->_integer = static_cast<int>(this->_char);
		this->_float = static_cast<float>(this->_char);
		this->_double = static_cast<double>(this->_char);
	}
	else if (!this->_type.compare("int"))
		this->_checkOverInt(input);
	else if (!this->_type.compare("float"))
		this->_checkOverFloat(input);
	else if (!this->_type.compare("double"))
		this->_checkOverDouble(input);
	else
		this->_flag = 4;
	return ;
}

void	ScalarConverter::_printChar(void)
{
	std::cout << "char: ";
	if ((this->_flag > 0 && this->_flag < 4) || (this->_overChar))
		std::cout << "impossible" << std::endl;
	else if (this->_char < 33 || this->_char > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << this->_char << "'" << std::endl;
	return ;
}

void	ScalarConverter::_printInt(void)
{
	std::cout << "int: ";
	if ((this->_flag > 0 && this->_flag < 4) || (this->_overInt))
		std::cout << "impossible" << std::endl;
	else
		std::cout << this->_integer << std::endl;
	return ;
}

void	ScalarConverter::_printFloat(void)
{
	if (!this->_type.compare("int") || !this->_type.compare("char"))
		this->_presicion = 1;
	std::cout << "float: ";
	if (this->_overFloat)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << std::fixed;
	std::cout << std::setprecision(this->_presicion);
	std::cout << this->_float;
	std::cout << "f" << std::endl;
}

void	ScalarConverter::_printDouble(void)
{
	if (!this->_type.compare("int") || !this->_type.compare("char"))
		this->_presicion = 1;
	std::cout << "double: ";
	if (this->_overDouble)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << std::fixed;
	std::cout << std::setprecision(this->_presicion);
	std::cout << this->_double;
	std::cout << std::endl;
}

void	ScalarConverter::convert(std::string &input)
{
	this->_process(input);
	if (this->_flag == 4)
	{
		std::cerr << "The introduced input is a string. So, the input is not valid" << std::endl;
		return ;
	}
	this->_printChar();
	this->_printInt();
	this->_printFloat();
	this->_printDouble();
	return ;
}

int	ScalarConverter::getInteger(void) const
{
	return (this->_integer);
}

float	ScalarConverter::getFloat(void) const
{
	return (this->_float);
}

double	ScalarConverter::getDouble(void) const
{
	return (this->_double);
}

char	ScalarConverter::getChar(void) const
{
	return (this->_char);
}

int	ScalarConverter::getFlag(void) const
{
	return (this->_flag);
}

int	ScalarConverter::getOverChar(void) const
{
	return (this->_overChar);
}

int	ScalarConverter::getOverInt(void) const
{
	return (this->_overInt);
}

int	ScalarConverter::getOverFloat(void) const
{
	return (this->_overFloat);
}

int	ScalarConverter::getOverDouble(void) const
{
	return (this->_overDouble);
}

int	ScalarConverter::getPresicion(void) const
{
	return (this->_presicion);
}

std::string	ScalarConverter::getType(void) const
{
	return (this->_type);
}
