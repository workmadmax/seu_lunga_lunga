/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:29:34 by mdouglas          #+#    #+#             */
/*   Updated: 2022/09/17 14:34:25 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/**
 * @brief A list of nodes with content.
 */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;


/**
 * @brief Checks if the passed character is alphabetic.
 * 
 * @param c This is the character to be checked.
 * @return This function returns non-zero value if 'c' is an alphabetic,
 * else it returns 0.
*/
int			ft_isalpha(int c);

/**
 * @brief Checks if the passed character is a decimal digit character.
 * numbers (0 to 9).
 * 
 * @param c This the character to be checked.
 * @return This function returns non-zero value if 'c' is a digit,
 * else it returns 0.
*/
int			ft_isdigit(int c);

/**
 * @brief Checks if the passed character is alphanumeric.
 * @param c This is the character to be checked.
 * @return This function returns non-zero value if 'c' is a digit or a letter,
 * else it returns 0.
*/
int			ft_isalnum(int c);

/**
 * @brief Function tests for an ASCII character (in the range 0 to 127).
 * @param c Character to be checked.
 * @return Nonzero if c is an ASCII character, otherwise, zero.
*/
int			ft_isascii(int c);

/**
 * @brief Checkes whether the passed character is printable. 
 * A printable character is a character that is not a control character.
 * @param c This is the character to be checked.
 * @return This function returns a non-zero value(true)
 * if c is a printable character else, zero (false).
*/
int			ft_isprint(int c);

/**
 * @brief Computes the length of the string 'str' up to,
 * but not including the terminating null character '\0'.
 * @param str This is the string whose length is to be found.
 * @return This function returns the length of string.
*/
size_t		ft_strlen(const char *str);

/**
 * @brief fills the first n bytes of the memory
 * area pointed to by s with the constant byte c.
 * 
 * @param s Pointer of memory area.
 * @param c Constant byte to fill memory area.
 * @param n Number of bytes to fill.
 * @return void* Return a pointer to the memory area s
 */
void		*ft_memset(void *str, int c, size_t n);

/**
 * @brief Fills the first 'n' bytes of the project
 * pointed to by dest with zero (NUL) bytes.
 * 
 * @param dest An existing object that you want to fill whit zeroes.
 * @param n The number of bytes to fill.
*/
void		ft_bzero(void *dest, size_t n);

/**
 * @brief Copies 'n' characters from memory area 'src' to memory 'dest'.
 * 
 * @param dest This is pointer to the destination array 
 * where the content is to be copied,
 * type-casted to a pointer of type void*.
 * @param src This is pointer to the source of data to be copied,
 * type-casted to a pointer of type void*.
 * @param n This is number of bytes ti be copied.
 * @return This function return a pointer to destination, which is str1 'dest'.
*/
void		*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Copies 'n' characters from 'str2'  to 'str1',
 *  but for overlapping memory blocks,
 * 'memmove()' is a safer approach than 'memcpy()'.
 * 
 * @param str1 This is a pointer to the destination
 * array where the content is to be copied,
 * type-casted to a pointer of type void*.
 * @param str2 This is a pointer to the sourcer
 * of data to be copied,
 * type-casted to a pointer of type void*.
 * @param n This is the number of bytes to be copied.
 * @return This function returns a pointer to the destination,
 * which is str1.
*/
void		*ft_memmove(void *str1, const void *str2, size_t n);

/**
 * @brief Copies up to size - 1 characters
 * from the NUL-terminated string src to dest,
 * NUL-terminating the result.
 * @param dest Pointer to the destination area of memory.
 * @param src Pointer to the source area of memory.
 * @param size Buffer size in byte.
 * @return Function return the length of the string it tried to create.
*/
size_t		ft_strlcpy(char *dest, const char *src, size_t size);

/**
 * @brief Append the NUL-terminated string 'src'
 * to the end of 'dest'.
 * It will append at most 'size'-'ft_strlen(dest)' - 1 bytes,
 * NUL-terminating the result.
 * 
 * @param dest Pointer to the destination area of memory.
 * @param src Pointer to the source area of memory.
 * @param size Buffer size in bytes.
 * @return 'size_t' Return the total length of the string,
 * that is the initial length of 'dest' plus the length of src.
*/
size_t  	ft_strlcat(char *dest, const char *src, size_t size);

/**
 * @brief Converts lowercase letter to uppercase.
 * 
 * @param c This is the letter to be converted to uppercase.
 * @return This function return uppercase equivalent to c,
 * if such value exists, else c remains unchanged.
 * The value is returnd as an 'int' value 
 * that can be implicitly casted to 'char'.
*/
int			ft_toupper(int c);

/**
 * @brief Coverts a given letter to lowercase.
 * 
 * @param c This is letter to be converted to lowercase.
 * @return This function returns lowercase equivalent to c,
 * if such value exists, else c remains unchanged.
 * The value is returned as an 'int' value
 * that can be implicitly casted to 'char'.
*/
int			ft_tolower(int c);

/**
 * @brief Searches for the first occurrence
 * of the character 'c' (an unsigned char)
 * in the string pointed to by the argument 'str'.
 * 
 * @param str This is the C string to be scanned.
 * @param c This is the character to be searched in str.
 * @return This returns a pointer to the first occurrence
 * of the character c in the string str,
 * or NULL if the character is not found.
*/
char		*ft_strchr(const char *str, int c);

/**
 * @brief Searches for the last occurrence
 * of the character c (an unsigned char)
 * in the string pointed to, by the argument 'str'.
 * 
 * @param str This is the C string.
 * @param c This is the character to be located.
 * It is passed as its int promotion,
 * but is internally converted back to char.
*/
char		*ft_strrchr(const char *str, int c);

/**
 * @brief Compares at most the first 'n' bytes
 * of 'str1' and 'str2'.
 * 
 * @param str1 This is the first string to be compared.
 * @param str2 This is the second string to be compared.
 * @param n The maximum number of characters to be compared.
 * @return If Return value < 0 then it indicates 'str1'
 * is less than 'str2'.
 * If Return value > 0 then it indicates 'str2'
 * is less than 'str1'.
 * If Return value = 0 the in indicates 'str1'
 * is equal 'str2'.
*/
int			ft_strncmp(const char *str1, const char *str2, size_t n);

/**
 * @brief Searches for the first occurrence
 * of the character c (an unsigned char)
 * in the first 'n' bytes of the string pointed to,
 * by the argument 'str'.
 * 
 * @param str This is the pointer to the block of memory
 * where the search is performed.
 * 
 * @param c This is the value to be passed as an int,
 * but the function performs a byte per byte
 * search using the unsigned char 
 * conversion of this value.
 * @param n This is the number of bytes to be analyzed.
 * @return This function returns a pointer to
 * the matching byte or NULL
 * if the character does not occurin
 * the given memory area.
*/
void		*ft_memchr(const void *str, int c, size_t n);

/**
 * @brief compares the first 'n' bytes
 * of memory area 'str1' and memory area 'str2'.
 * 
 * @param str1 This is the pointer to a block of memory.
 * @param str2 This is the pointer to a block of memory.
 * @param n This is the number of bytes to compared.
 * @return if Return value < 0 then it indicates 'str1'
 * is less than 'str2'.
 * if Return value > 0 then it indicates 'str2'
 * is less than 'str1'.
 * if Return value = 0 then it indicates 'str1'
 * is equal to 'str2'.
*/
int			ft_memcmp(const void *str1, const void *str2, size_t n);

/**
 * @brief Converts the string argument 'str'
 * to an integer (type int).
 * 
 * @param str This is the string representation
 * of an integral number.
 * @return This function returns the converted integral
 * number as an int value.
 * If no valid conversion could be performed,
 * it returns zero.
*/
int			ft_atoi(const char *str);

/**
 * @brief Allocates the requested memory and
 * returns a pointer to it.
 * The difference in 'malloc' and 'calloc'
 * is that malloc
 * does not set the memory to zero where
 * as calloc sets allocated memory to zero.
 * 
 * @param nitems This is the number of elements to be allocated.
 * @param size This is the size of elements.
 * @return This function returns a pointer to
 * the allocated memory,
 * or NULL if the request fails.
*/
void		*ft_calloc(size_t nitem, size_t size);

/**
 * @brief Function returns a pointer to
 * a new string which is a duplicate of the string 's'.
 * Memory for the new string is obtained with 'malloc',
 * and can be freed with 'free'.
 * 
 * @param s ponter to the start of the string to be copied.
 * @return It returns a pointer to the duplicated string 's'.
*/
char		*ft_strdup(const char *s);

/**
 * @brief Allocates (with malloc(3)) and returns
 * a substring from the string 's'.
 * The substring begins at index 'start'
 * and is of maximum size 'len'.
 * 
 * @param s The string from wich to create the substring.
 * @param start The start index of the substring in the string 's'.
 * @param len The maximum length of the substring.
 * @return The substring. NULL if the allocation fails.
*/
char		*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Allocates (with malloc(3)) and return a new string,
 * wich is the result of the concatenation of 's1' and 's2'.
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string. NULL if the allocation fails.
*/
char		*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Outputs the character 'c' to the given file descriptor.
 * @param c The character to output.
 * @param fd The file descriptor on which to write.
 * @return None.
*/
void		ft_putchar_fd(char c, int fd);

/**
 * @brief Outputs the string 's' to the given file descriptor.
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 * @return None.
*/
void		ft_putstr_fd(char *s, int fd);

/**
 * @brief Outputs the string 's' to the given
 * file descriptor followed by a newline.
 * 
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 * @return None.
*/
void		ft_putendl_fd(char *s, int fd);

/**
 * @brief Outputs the integer 'n' to the given file descriptor.
 * @param n The integer to output.
 * @param fd The file descriptor on which to write.
 * @return None.
*/
void		ft_putnbr_fd(int n, int fd);

/**
 * @brief Applies the function 'f' on each character
 * of the string passed as argument,
 * passing its index as first argument.
 * Each character is passed by adress to 'f'
 * to be modified if necessary.
 * 
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 * @return None.
*/
void		ft_striteri(char *s, void (*f)(unsigned int, char *));

/**
 * @brief Applies the function 'f'
 * to each character of the string 's',
 * and passing its index as first argument
 * to create a new string (with malloc(3))
 * resulting from succesive applications of 'f'.
 * 
 * @param s The string on wich to iterate
 * @param f The function to apply to each character.
 * @return The string created from the successive
 * application of 'f'.
 * Returns NULL if the allocation fails.
*/
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Allocates (with malloc(3)) and returns
 * a copy of 's1' with the characters specified
 * in 'set' removed from the beginning
 * and the end of the string.
 * 
 * @param s1 The string to be trim.
 * @param set The reference set of characters to trim.
 * @return The trimmed string NULL if the allocation fails.
*/
char		*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Allocates (with malloc(3)) and returns
 * a string representing the integer received
 * as an argument. Negative numbers must be handled.
 * 
 * @param n The integer to covert.
 * @return The string representing the integer. NULL if the allocation fails.
*/
char		*ft_itoa(int n);

/**
 * @brief Allocates (with malloc(3)) and returns
 * an array of strings obtained by splitting 's'
 * using the character 'c' as
 * a delimiter the array mus end with a NULL pointer.
 * 
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return The array of new string resulting from the split.
 * NULL if the allocation fails.
*/
char		**ft_split(char const *s, char c);

/**
 * @brief Locates the first occurrence
 * of the null-terminated string
 * 'little' in the string 'big',
 * where not more than 'len' characters
 * are searched.
 * Characters that appear after
 * a '\0' character are not searched..
 * 
 * @param big String to be searched by 'little'.
 * @param little String to search in 'big'.
 * @param len Number of bytes to search.
 * @return char* If little is an empety string,
 * big is returned.
 * If little occurs nowhere in big, NULL is returned.
 * otherwise a pointer to the first character
 * of the first occurrence of little is returned.
*/
char		*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * @brief Allocates (with malloc(3)) and returns a new element.
 * The variable 'content' is initialized with the value of the
 * parameter 'content'. The variable 'next' is initialized to NULL.
 * 
 * @param content The content to create the new element with.
 * @return t_list* The new element
 */
t_list		*ft_lstnew(void *content);

/**
 * @brief Adds the element 'new' at the beginning of the list.
 * 
 * @param lst The adress of a pointer to the first link of a list.
 * @param new The adress of a pointer to the element to be added to the list.
 */
t_list		*ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Counts the number of elements in a list.
 * 
 * @param lst The beginning of a list.
 * @return int Returns the length of a list.
 */
int			*ft_lstsize(t_list *lst);

/**
 * @brief Returns the last element of the list.
 * 
 * @param lst The beginning of the listç.
 * @return 't_list*' Returns the last element of the list.
 * Return NULL if 'lst' is empety or is already in the last element.
 */
t_list		*ft_lstlast(t_list *lst);

/**
 * @brief Adds the 'new' element at the end of the list.
 * 
 * @param lst The adress of a pointer to the first link of a list.
 * @param new The adress of a pointer to the element to be
 * add to the list.
 */
void		ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Takes as a parameter an element and frees the
 * memory of the element's content using the function
 * 'del' given as a parameter and free the element.
 * The memory of 'next' must not be freed.
 * 
 * @param lst The element to free.
 * @param del The adress of the function used to delete the content.
 */
void		ft_lstdelone(t_list *list, void (*del)(void *));

/**
 * @brief Deletes and frees thegiven element and every
 * successor of that element, using the function 'del' and free(3).
 * Finally, the pointer to the list must be set to NULL.
 * 
 * @param lst The adress of a pointer to an element
 * @param del The adress of the function used to delete
 * the content of the element.
 */
void		ft_lstclear(t_list **lst, void (*del)(void*));

/**
 * @brief Iterates the list 'lst' and applies the function
 * 'f' to the content of each element.
 * 
 * @param lst The adress of a pointer to an element
 * @param f The adress of the function used to iterate on the list.
 */
void		ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Iterates the list 'lst' and applies
 * the function 'f'
 * to the content of each element.
 * Creates a new list resulting
 * of the sucessive application of the function 'f'.
 * The 'del' function is used to
 * delete the content of an element if needed.
 * 
 * @param lst The adress of a pointer to an element.
 * @param f The adress of the function used to iterate on the list
 * @param del The adress of the function used to delete the
 * content of an element if needed
 * @return 't_list*' Returns the new list or NULL if the allocation fails.
 */
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* gnl */

char    *get_next_line(int fd);

#endif