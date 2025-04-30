/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:31:30 by vde-maga          #+#    #+#             */
/*   Updated: 2025/04/26 12:31:30 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int		ft_putchar_fd_l(char c, int fd);
int		ft_putstr_fd_l(char *s, int fd);
int		ft_putnbr_fd_l(int n, int fd);
int		ft_u_putnbr_fd_l(unsigned int n, int fd);
int		ft_hexadecimal(unsigned int x, char a);
int		ft_pointer(size_t x);

#endif