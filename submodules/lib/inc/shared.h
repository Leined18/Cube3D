/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:56:22 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 10:57:06 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <signal.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

// Definiciones de colores ANSI como macros
# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define RESET "\033[0m"

# define BOLD_BLACK "\033[1;30m"
# define BOLD_RED "\033[1;31m"
# define BOLD_GREEN "\033[1;32m"
# define BOLD_YELLOW "\033[1;33m"
# define BOLD_BLUE "\033[1;34m"
# define BOLD_MAGENTA "\033[1;35m"
# define BOLD_CYAN "\033[1;36m"
# define BOLD_WHITE "\033[1;37m"

# define ORANGE "\033[38;5;208m"
# define WINE "\033[38;5;88m"
# define LIME "\033[38;5;190m"
# define TURQUOISE "\033[38;5;38m"
# define LIGHT_PINK "\033[38;5;13m"
# define DARK_GRAY "\033[38;5;235m"
# define LIGHT_RED "\033[38;5;203m"
# define LIGHT_BLUE "\033[38;5;75m"

# define BRIGHT_BLUE "\033[38;5;27m"
# define BRIGHT_GREEN "\033[38;5;46m"
# define BRIGHT_YELLOW "\033[38;5;226m"
# define BRIGHT_CYAN "\033[38;5;51m"
# define BRIGHT_WHITE "\033[38;5;231m"

# define TABLE_SIZE 1000003

#endif // SHARED_H