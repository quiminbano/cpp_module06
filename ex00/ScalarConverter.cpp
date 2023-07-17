/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:14:43 by corellan          #+#    #+#             */
/*   Updated: 2023/07/17 11:20:14 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) 
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
		ScalarConverter::_integer = rhs.getInteger();
		ScalarConverter::_char = rhs.getChar();
		ScalarConverter::_float = rhs.getFloat();
		ScalarConverter::_double = rhs.getDouble();
		ScalarConverter::_flag = rhs.getFlag();
		ScalarConverter::_overChar = rhs.getOverChar();
		ScalarConverter::_overInt = rhs.getOverInt();
		ScalarConverter::_overFloat = rhs.getOverFloat();
		ScalarConverter::_overDouble = rhs.getOverDouble();
		ScalarConverter::_presicion = rhs.getPresicion();
		ScalarConverter::_sciNot = rhs.getSciNot();
		ScalarConverter::_type = rhs.getType();
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
	{
		if (input[i] == 'e' && input[i + 1] != '\0')
		{
			ScalarConverter::_sciNot = 1;
			return (ScalarConverter::_checkExponent(i, input, 1));
		}
		else	
			return (0);
	}
	i++;
	while (input[i] >= '0' && input[i] <= '9')
	{
		i++;
		j++;
	}
	if (input[i] == 'e')
		return (ScalarConverter::_checkExponent(i, input, 1));
	ScalarConverter::_presicion = j;
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
	{
		if (input[i] == 'e' && (input[i + 1] != '\0' && input[i + 1] != 'f'))
		{
			ScalarConverter::_sciNot = 1;
			return (ScalarConverter::_checkExponent(i, input, 0));
		}
		else
			return (0);
	}
	i++;
	while (input[i] >= '0' && input[i] <= '9')
	{
		i++;
		j++;
	}
	if (input[i] != 'f')
	{
		if ((input[i]) && (input[i] == 'e' && input[i + 1]))
			return (ScalarConverter::_checkExponent(i, input, 0));
		else	
			return (0);
	}
	ScalarConverter::_presicion = j;
	i++;
	if (input.size() == i)
		return (1);
	return (0);
}

int	ScalarConverter::_checkExponent(size_t &i, std::string &input, int analysis)
{
	ScalarConverter::_sciNot = 1;
	i++;
	if ((analysis == 0) && (input[i] == 'f'))
		return (0);
	if (input[i] == '+' || input[i] == '-')
		i++;
	while (input[i] >= '0' && input[i] <= '9')
		i++;
	if (analysis == 0)
	{
		if (input[i] != 'f')
			return (0);
		i++;
	}
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
	else if (ScalarConverter::_intAnalizer(input) == 1)
		return ("int");
	else if (ScalarConverter::_floatAnalizer(input) == 1)
		return ("float");
	else if (ScalarConverter::_doubleAnalizer(input) == 1)
		return ("double");
	return ("string");
}

void	ScalarConverter::_checkOverInt(std::string &input)
{
	std::istringstream	iss;
	std::istringstream	iss2;
	long double			num;

	iss.str(input);
	iss >> ScalarConverter::_integer;
	num = 0;
	if (iss.fail() == false)
	{
		ScalarConverter::_char = static_cast<char>(ScalarConverter::_integer);
		ScalarConverter::_float = static_cast<float>(ScalarConverter::_integer);
		ScalarConverter::_double = static_cast<double>(ScalarConverter::_integer);
		if (ScalarConverter::_integer > 127 || ScalarConverter::_integer < -128)
			ScalarConverter::_overChar = 1;
		return ;
	}
	ScalarConverter::_overInt = 1;
	iss2.str(input);
	iss2 >> num;
	if (iss2.fail() == false)
	{
		ScalarConverter::_char = static_cast<char>(ScalarConverter::_integer);
		ScalarConverter::_float = static_cast<float>(num);
		if (num > FLT_MAX || num < ((-1.0) * FLT_MAX))
			ScalarConverter::_overFloat = 1;
		ScalarConverter::_double = static_cast<double>(num);
		if (num > DBL_MAX || (num < ((-1.0) * DBL_MAX)))
			ScalarConverter::_overDouble = 1;
		ScalarConverter::_overChar = 1;
		return ;
	}
	ScalarConverter::_overChar = 1;
	ScalarConverter::_overInt = 1;
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
	iss >> ScalarConverter::_float;
	if (iss.fail() == false)
	{
		num = static_cast<long long>(ScalarConverter::_float);
		ScalarConverter::_integer = static_cast<int>(ScalarConverter::_float);
		if (num != static_cast<long long>(ScalarConverter::_integer))
		{
			ScalarConverter::_overInt = 1;
			ScalarConverter::_overChar = 1;
		}
		else
		{
			if (ScalarConverter::_integer > 127 || ScalarConverter::_integer < -128)
				ScalarConverter::_overChar = 1;
		}
		ScalarConverter::_char = static_cast<char>(ScalarConverter::_float);
		ScalarConverter::_double = static_cast<double>(ScalarConverter::_float);
		return ;
	}
	iss2.str(input.substr(0, (temp - 1)));
	iss2 >> num2;
	ScalarConverter::_overFloat = 1;
	if (iss2.fail() == false)
	{
		if (std::abs(num2) < FLT_MIN)
		{
			ScalarConverter::_integer = static_cast<int>(num2);
			ScalarConverter::_char = static_cast<char>(num2);
		}
		if (std::abs(num2) > FLT_MAX)
		{
			ScalarConverter::_overChar = 1;
			ScalarConverter::_overInt = 1;
		}
		if ((std::abs(num2) > DBL_MAX) || (std::abs(num2) < DBL_MIN))
		{
			ScalarConverter::_overDouble = 1;
			if (std::abs(num2) > DBL_MAX)
			{
				ScalarConverter::_overChar = 1;
				ScalarConverter::_overInt = 1;
			}
		}
		ScalarConverter::_double = static_cast<double>(num2);
		return ;
	}
	if (static_cast<int>(num2) == 0)
	{
		ScalarConverter::_integer = static_cast<int>(num2);
		ScalarConverter::_char = static_cast<char>(num2);
		ScalarConverter::_overDouble = 1;
		return ;
	}
	ScalarConverter::_overInt = 1;
	ScalarConverter::_overChar = 1;
	ScalarConverter::_overDouble = 1;
	return ;
}

void	ScalarConverter::_checkOverDouble(std::string &input)
{
	std::istringstream	iss;
	long long			num;

	iss.str(input);
	iss >> ScalarConverter::_double;
	if (iss.fail() == false)
	{
		num = static_cast<long long>(ScalarConverter::_double);
		ScalarConverter::_integer = static_cast<int>(ScalarConverter::_double);
		ScalarConverter::_char = static_cast<char>(ScalarConverter::_double);
		if (num != static_cast<long long>(ScalarConverter::_integer))
		{
			ScalarConverter::_overInt = 1;
			ScalarConverter::_overChar = 1;
		}
		else
		{
			if (ScalarConverter::_integer > 127 || ScalarConverter::_integer < -128)
				ScalarConverter::_overChar = 1;
		}
		ScalarConverter::_float = static_cast<float>(ScalarConverter::_double);
		if ((std::abs(ScalarConverter::_double) > FLT_MAX) || (std::abs(ScalarConverter::_double) < FLT_MIN && ScalarConverter::_double != 0.0))
			ScalarConverter::_overFloat = 1;
		return ;
	}
	ScalarConverter::_overFloat = 1;
	ScalarConverter::_overDouble = 1;
	if (static_cast<int>(ScalarConverter::_double) == 0)
	{
		ScalarConverter::_char = static_cast<char>(ScalarConverter::_double);
		ScalarConverter::_integer = static_cast<int>(ScalarConverter::_double);
	}
	else
	{
		ScalarConverter::_overInt = 1;
		ScalarConverter::_overChar = 1;
	}
	return ;
}

void	ScalarConverter::_process(std::string &input)
{
	ScalarConverter::_type = ScalarConverter::_analizer(input);
	if ((!ScalarConverter::_type.compare("string")) && (!input.compare("nan") || !input.compare("nanf")))
	{
		ScalarConverter::_double = nan(input.c_str());
		ScalarConverter::_float = nanf(input.c_str());
		ScalarConverter::_flag = 1;
	}
	else if ((!ScalarConverter::_type.compare("string")) && (!input.compare("+inf") || !input.compare("+inff") || !input.compare("inff") || !input.compare("inf")))
	{
		ScalarConverter::_double = HUGE_VAL;
		ScalarConverter::_float = HUGE_VALF;
		ScalarConverter::_flag = 2;
	}
	else if ((!ScalarConverter::_type.compare("string")) && (!input.compare("-inf") || !input.compare("-inff")))
	{
		ScalarConverter::_double = ((-1.0) * HUGE_VAL);
		ScalarConverter::_float = ((-1.0) * HUGE_VALF);
		ScalarConverter::_flag = 3;
	}
	else if (!ScalarConverter::_type.compare("char"))
	{
		ScalarConverter::_char = input[0];
		ScalarConverter::_integer = static_cast<int>(ScalarConverter::_char);
		ScalarConverter::_float = static_cast<float>(ScalarConverter::_char);
		ScalarConverter::_double = static_cast<double>(ScalarConverter::_char);
	}
	else if (!ScalarConverter::_type.compare("int"))
		ScalarConverter::_checkOverInt(input);
	else if (!ScalarConverter::_type.compare("float"))
		ScalarConverter::_checkOverFloat(input);
	else if (!ScalarConverter::_type.compare("double"))
		ScalarConverter::_checkOverDouble(input);
	else
		ScalarConverter::_flag = 4;
	return ;
}

void	ScalarConverter::_printChar(void)
{
	std::cout << "char: ";
	if ((ScalarConverter::_flag > 0 && ScalarConverter::_flag < 4) || (ScalarConverter::_overChar))
		std::cout << "impossible" << std::endl;
	else if (ScalarConverter::_char < 33 || ScalarConverter::_char > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << ScalarConverter::_char << "'" << std::endl;
	return ;
}

void	ScalarConverter::_printInt(void)
{
	std::cout << "int: ";
	if ((ScalarConverter::_flag > 0 && ScalarConverter::_flag < 4) || (ScalarConverter::_overInt))
		std::cout << "impossible" << std::endl;
	else
		std::cout << ScalarConverter::_integer << std::endl;
	return ;
}

void	ScalarConverter::_printFloat(void)
{
	if (!ScalarConverter::_type.compare("int") || !ScalarConverter::_type.compare("char"))
		ScalarConverter::_presicion = 1;
	std::cout << "float: ";
	if (ScalarConverter::_overFloat)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (ScalarConverter::_sciNot == 0)
	{
		std::cout << std::fixed;
		std::cout << std::setprecision(ScalarConverter::_presicion);
	}
	std::cout << ScalarConverter::_float;
	std::cout << "f" << std::endl;
}

void	ScalarConverter::_printDouble(void)
{
	if (!ScalarConverter::_type.compare("int") || !ScalarConverter::_type.compare("char"))
		ScalarConverter::_presicion = 1;
	std::cout << "double: ";
	if (ScalarConverter::_overDouble)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (ScalarConverter::_sciNot == 0)
	{
		std::cout << std::fixed;
		std::cout << std::setprecision(ScalarConverter::_presicion);
	}
	std::cout << ScalarConverter::_double;
	std::cout << std::endl;
}

void	ScalarConverter::convert(std::string &input)
{
	ScalarConverter::_integer = 0;
	ScalarConverter::_float = 0;
	ScalarConverter::_double = 0;
	ScalarConverter::_char = 0;
	ScalarConverter::_flag = 0;
	ScalarConverter::_overChar = 0;
	ScalarConverter::_overInt = 0;
	ScalarConverter::_overFloat = 0;
	ScalarConverter::_overDouble = 0;
	ScalarConverter::_presicion = 0;
	ScalarConverter::_sciNot = 0;
	std::string	_type = "unknown";
	ScalarConverter::_process(input);
	if (ScalarConverter::_flag == 4)
	{
		std::cerr << "The introduced input is a string. So, the input is not valid" << std::endl;
		return ;
	}
	ScalarConverter::_printChar();
	ScalarConverter::_printInt();
	ScalarConverter::_printFloat();
	ScalarConverter::_printDouble();
	return ;
}

int	ScalarConverter::getInteger(void)
{
	return (ScalarConverter::_integer);
}

float	ScalarConverter::getFloat(void)
{
	return (ScalarConverter::_float);
}

double	ScalarConverter::getDouble(void)
{
	return (ScalarConverter::_double);
}

char	ScalarConverter::getChar(void)
{
	return (ScalarConverter::_char);
}

int	ScalarConverter::getFlag(void)
{
	return (ScalarConverter::_flag);
}

int	ScalarConverter::getOverChar(void)
{
	return (ScalarConverter::_overChar);
}

int	ScalarConverter::getOverInt(void)
{
	return (ScalarConverter::_overInt);
}

int	ScalarConverter::getOverFloat(void)
{
	return (ScalarConverter::_overFloat);
}

int	ScalarConverter::getOverDouble(void)
{
	return (ScalarConverter::_overDouble);
}

int	ScalarConverter::getPresicion(void)
{
	return (ScalarConverter::_presicion);
}

int	ScalarConverter::getSciNot(void)
{
	return (ScalarConverter::_sciNot);
}

std::string	ScalarConverter::getType(void)
{
	return (ScalarConverter::_type);
}

int 		ScalarConverter::_integer = 0;
float		ScalarConverter::_float = 0;
double		ScalarConverter::_double = 0;
char		ScalarConverter::_char = 0;
int			ScalarConverter::_flag = 0;
int			ScalarConverter::_overChar = 0;
int			ScalarConverter::_overInt = 0;
int			ScalarConverter::_overFloat = 0;
int			ScalarConverter::_overDouble = 0;
int			ScalarConverter::_presicion = 0;
int			ScalarConverter::_sciNot = 0;
std::string	ScalarConverter::_type = "unknown";