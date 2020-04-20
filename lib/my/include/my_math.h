/*
** EPITECH PROJECT, 2019
** LIBMY
** File description:
** Functions for math and integer manipulation
*/

#ifndef __MY_MATH_H
#define __MY_MATH_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

///
/// \file       my_math.h
/// \brief      Functions for advanced number manipulation
///
/// This file contains function definitions for common mathematical and number
/// manipulation functions.
///

///
/// This function calculates the integer power of a number using a recursive
/// method. For example, \c my_ipow_r(2, 3) will return 8.
/// For higher powers, this method can be less memory efficient. In these
/// cases, you should prefer {@link my_ipow} over this function.
///
/// \brief      Calculate the integer power of a number recursively
/// \param nb   The number to multiply
/// \param pow  The power to raise the number to
/// \return     The result of the operation
/// \see   my_ipow for the iterative variant of this function
///
int   my_ipow_r(int nb, int pow);

///
/// This function calculates the integer power of a number using an iterative
/// method. For example, \c my_ipow(2, 3) will return 8.
/// For higher powers, this method is preferred over {@link my_ipow_r}.
///
/// \brief      Calculate the integer power of a number iteratively
/// \param nb   The number to multiply
/// \param pow  The power to raise the number to
/// \return     The result of the operation
/// \see   my_ipow_r for the recursive variant of this function
///
int   my_ipow(int nb, int pow);

///
/// This function takes a string as input, and returns the decimal integer
/// that it parsed. For example, \c my_getnbr("1234") will return 1234.
/// The function stops at the first non-numeric character (except from
/// negative signs at the beginning).
///
/// Note that this function will copy the entire string for parsing. If
/// the text you are parsing is very large, prefer using {@link my_getnbr_n}.
///
/// \brief      Return a decimal integer parsed out of a given string
/// \param str  The string to parse the number from
/// \return     The extracted integer
/// \see   my_getnbr_n for scanning only part of a string
///
int   my_getnbr(char const *str);

///
/// This function takes a string as input, and returns the decimal integer
/// that it parsed, for the first n characters in the string. For example,
/// <tt>my_getnbr_n("1234", 2)</tt> will return 12, since it will only use
/// the first two characters.
/// The function stops at the first non-numeric character (except from
/// negative signs at the beginning).
///
/// Note that this function will copy the first n characters of the string
/// for parsing. You should prefer this function over {@link my_getnbr} for
/// longer strings.
///
/// \brief      Return a decimal integer parsed out of the first n bytes of
///             a string
/// \param str  The string to parse the number from
/// \param n    The number of characters to read
/// \return     The extracted integer
/// \see   my_getnbr for scanning an entire string
///
int   my_getnbr_n(char const *str, int n);

///
/// This function takes an integer to print to the standard output, and
/// a string containing the digits to use to output the number. The length
/// of that string determines the numerical base to use. For example,
/// <tt>my_putnbr_base(24, "0123456789")</tt> will output "24", while
/// <tt>my_putnbr_base(24, "01234567")</tt> will output "30".
///
/// \brief      Output a given number as text using the given number base
/// \param n    The number to output
/// \param base The string representing the numerical base to use
/// \see   put_padded_nbr_base
///             to automatically add trailing zeroes to the output
///
void  my_putnbr_base(int n, char const *base);

///
/// This function takes an integer to print to the standard output, and
/// a string containing the digits to use to output the number (see
/// {@link my_putnbr_base}).
/// The pad argument states the minimum amount of numbers to output.
/// for example, <tt>put_padded_nbr_base(20, "0123456789", 4)</tt> will output
/// "0020", with two leading zeroes to match the minimum of 4 numbers. However,
/// <tt>put_padded_nbr_base(1234, "0123456789", 2)</tt> will output "1234",
/// since the pad argument does not indicate a maximum.
///
/// \brief      Output a given number as text, with a minimum length
/// \param n    The number to output
/// \param base The string representing the numerical base to use
/// \param pad  The minimum amount of numbers to output
/// \see   my_putnbr_base
///             for documentation on how the base argument is used
///
void  put_padded_nbr_base(int n, char const *base, int pad);

#endif //__MY_MATH_H
