#include <iostream>
#include <cstdlib>
#include <climits>
#include <cctype>

#ifndef CONVERT_HPP
# define CONVERT_HPP

bool	is_char(std::string input);
bool	is_int(char *input);
bool	is_float(std::string input);
bool	is_double(std::string input);

void	convert_char(char characterValue);
void	convert_int(int integerValue);
void	convert_float(float floatValue);
void	convert_double(double doubleValue);

void	display_char(double numericValue);
void	display_inf(std::string input);
void	display_nan();

#endif
