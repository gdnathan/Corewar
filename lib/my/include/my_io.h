/*
** EPITECH PROJECT, 2019
** LIBMY
** File description:
** Functions for data input/output
*/

#ifndef __MY_IO_H
#define __MY_IO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

///
/// \file       my_io.h
/// \brief      Functions to control input/output
///
/// This file contains function definitions for reading and writing to files.
///

///
/// \brief      This macro controls the amount of bytes to buffer when
///             reading a file in function {@link get_next_line}.
///
#ifndef  READ_SIZE
# define READ_SIZE (10)
#endif //READ_SIZE

///
/// This function will take a single char (a byte) and output it to
/// the standard output.
///
/// \brief      Output a single character to stdout
/// \param c    The character to print
///
void  my_putchar(char c);

///
/// This function will take a single char (a byte) and output it to
/// the specified file descriptor. It can be stdout (1), stderr (2)
/// or any other file descriptor opened with open() or fileno()
///
/// \brief      Output a single character to the given file descriptor
/// \param fd   The open file descriptor to write to
/// \param c    The character to print
///
void  my_dputchar(int fd, char c);

///
/// This function will take a null-terminated char* and output it to
/// the standard output.
///
/// \brief      Output a string to stdout
/// \param str  The null-terminated string to output
///
void  my_puts(char const *str);

///
/// This function will take a null-terminated char* and output it to
/// the specified file descriptor. The descriptor can be stdout (1), stderr (2)
/// or any other file descriptor opened with open() or fileno()
///
/// \brief      Output a string to the given file descriptor
/// \param fd   The open file descriptor to write to
/// \param str  The null-terminated string to output
///
void  my_dputs(int fd, char const *str);

///
/// This function will take a null-terminated char* and output it to
/// the standard output, in a format where all non-printable characters
/// will be escaped in octal. For example, \c "Hello\nworld!" will be output
/// as: \c "Hello\012world!", instead of producing a new line.
///
/// \brief      Output a string by displaying non-printables in octal
/// \param str  The null-terminated string to output
///
void  my_showstr(char const *str);

///
/// This function will take a format string and an arbitrary number of
/// arguments following it, and produce an output comparable to the
/// <tt>printf()</tt> function from libC. Currently, the following flags
/// are implemented: <tt>c</tt>, <tt>s</tt>, <tt>x</tt>, <tt>i</tt>,
/// <tt>o</tt>, <tt>b</tt>.
///
/// \brief      Produce an output similar to libC <tt>printf()</tt>
/// \param fmt  The string format describing the output
///
void  my_printf(char const *fmt, ...);

///
/// This function will take an open file descriptor as argument, and from it
/// will read the next full line (excluding the newline character).
/// It will return a null-terminated char* containing the line that was read.
/// If get_next_line encounters an empty line, or the end of the file, it will
/// return 0 (a null pointer) instead.
/// The amount of characters to read at once can be controlled using macro
/// {@link READ_SIZE}.
///
/// \brief      Get the next line from a specified file descriptor
/// \param fd   The open file descriptor to read from
/// \return     A null-terminated char* representing the line read,
///             or 0 if there is nothing left to read.
///             The returned pointer can be freed using free().
///
char *get_next_line(int fd);

#endif //__MY_OUTPUT_H
