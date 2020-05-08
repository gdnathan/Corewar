/*
** EPITECH PROJECT, 2019
** LIBMY
** File description:
** Functions for manipulating strings
*/

#ifndef __MY_STR_H
#define __MY_STR_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

///
/// \file       my_str.h
/// \brief      Functions for string manipulation and management
///
/// This file contains function definitions for string manipulation and
/// memory management.
///

/// In {@link is_char_type}, match if the character is lower case
#define C_LOWER     0b0001
/// In {@link is_char_type}, match if the character is upper case
#define C_UPPER     0b0010
/// In {@link is_char_type}, match if the character is a digit
#define C_NUMBER    0b0100
/// In {@link is_char_type}, match if the character is non-printable
#define C_SPECIAL   0b1000

///
/// This function will return the number of characters in a given string
/// all the way to (but not including) the null terminator.
///
/// \brief      Return the length of a given string
/// \param str  The string to measure the length of
/// \return     The number of characters in the given string
///
int   my_strlen(char const *str);

///
/// This function takes a source string, and copies it into a pre-allocated
/// destination string. The destination needs to be able to fit the entire
/// source string, else a segmentation fault may occur.
/// The function adds a null terminator to the destination string
/// automatically.
///
/// \brief      Copy the contents of a string into a given preallocated space
/// \param dest The pointer to the space to copy the string into
/// \param src  The origin string to copy
/// \return     The destination string
/// \see   my_strncpy to copy only the first n characters
/// \see   my_strdup to automatically allocate the destination space
///
char *my_strcpy(char *dest, char const *src);

///
/// This function copies the first n characters from a source string into
/// a pre-allocated destination string. The destination needs to be able to fit
/// the number of characters specified, else a segmentation fault may occur.
///
/// \brief      Copy n characters of a string into a given preallocated spece
/// \param dest The pointer to the space to copy the string into
/// \param src  The origin string to copy
/// \param n    The number of characters to copy
/// \return     The destination string
/// \see   my_strcpy for the base principle
/// \see   my_strndup to automatically allocate the destination space
///
char *my_strncpy(char *dest, char const *src, int n);

///
/// This function takes a source string, and creates a destination string of
/// the same size. It then copies the source string into that new string, and
/// returns it.
///
/// \brief      Duplicate a string into a new area of memory
/// \param str  The origin string to duplicate
/// \return     The destination string
/// \see   my_strcpy for the base copy principle
/// \see   my_strndup to duplicate only the first n characters
///
char *my_strdup(char const *str);

///
/// This function copies the first n characters from a source string into
/// a destination string that it allocates to the proper size, then copies
/// the source string into it, and returns it.
///
/// \brief      Duplicate n characters of a string into a new area of memory
/// \param str  The origin string to duplicate
/// \param n    The number of characters to copy
/// \return     The destination string
/// \see   my_strcpy for the base copy principle
/// \see   my_strdup to copy the entire string
///
char *my_strndup(char const *str, int n);

///
/// This function takes two origin strings, and copies them one after the
/// other into a newly allocated string, which it then returns. For example,
/// <tt>my_strcat("Hello ", "world")</tt> will return "Hello world".
///
/// \brief      Merge two strings into a new one
/// \param dest The string that will be copied at the beginning
/// \param src  The string that will be copied at the end
/// \return     The newly created string
/// \see   my_strdup for the underlying string copy principle
/// \see   str_append for a version that overwrites the destination string
///
char *my_strcat(char const *dest, char const *src);

///
/// This function takes a pointer to a destination string, which it will
/// re-allocate to write the source string at the end (append it).
/// As such, the operation is destructive, unlike {@link my_strcat}.
///
/// \brief      Merge two strings into the first one (destructive)
/// \param dest The pointer to the string that will be overwritten
/// \param src  The string to write at the end of the destination string
/// \see   my_strcat for a non-destructive version of this operation
///
void  str_append(char **dest, char const *src);

///
/// This function searches for a specified sub-string within a parent string.
/// When a match is found, it returns a pointer to the beginning of the match.
/// For example <tt>my_strstr("Hello world", "lo")</tt> will return "lo world",
/// where the resulting pointer is within the given parent string.
///
/// \brief      Find a substring within a parent string
/// \param str  The parent string to search in
/// \param sub  The sub-string to search for
/// \return     A pointer to where the substring begins in the parent string,
///             or 0 if there was no match
/// \see   str_contains to match a single character
///
char *my_strstr(char *str, char const *sub);

///
/// This function checks if two strings are identical. In order to match, the
/// strings need to have the same length, and contain the same characters.
///
/// \brief      Check if two strings are identical
/// \param s1   The first string to compare
/// \param s2   The second string to compare
/// \return     1 if the two strings match, else 0
/// \see   my_strstr to search for a substring
/// \see   my_strncmp to only match the first n characters
///
int   my_strcmp(char const *s1, char const *s2);

///
/// This function checks if the first n characters of two strings are
/// identical. In the event of an underrun (the number to check is longer)
/// than the longest string, the function will only match identical strings
/// of the same length, like {@link my_strcmp}.
///
/// \brief      Check if the first n characters of two strings are identical
/// \param s1   The first string to compare
/// \param s2   The second string to compare
/// \param n    The number of characters to check
/// \return     1 if there is a match, else 0
/// \see   my_strcmp to compare the full strings
///
int   my_strncmp(char const *s1, char const *s2, int n);

///
/// This function searches for a given character within a string, and if it
/// matches, returns the location of the first occurence of the character,
/// starting from zero. Otherwise, it returns -1. For example,
/// <tt>str_contains("hello", 'l')</tt> will return 2.
///
/// \brief      Get the position of a specific character within a string
/// \param str  The string to search in
/// \param c    The character to search for in the string
/// \return     The location, starting from zero, of the character if it was
///             found, else -1
/// \see   my_strstr to search for a substring
/// \see   my_strcmp to match two strings
///
int   str_contains(char const *str, char c);

///
/// This function takes a single character, and matches it against a specific
/// category of characters, from {@link C_LOWER}, {@link C_UPPER},
/// {@link C_NUMBER}, and {@link C_SPECIAL}. Several categories can be OR'ed
/// together to match any one.
///
/// \brief      Match a character against a certain type of character
/// \param c    The character to check
/// \param mask The type, or types, of character for which to check
/// \return     1 if the character belongs to one of the specified types,
///             else 0
///
int   is_char_type(char c, int mask);

char *my_strdup_to_char(char *src, char c);
#endif //__MY_STR_H
