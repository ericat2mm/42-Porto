/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 12:24:13 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/20 22:58:41 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_DEFINES_H
# define FDF_DEFINES_H

#define LOGO "\n \033[0;31m   \t\t\t________   _____     _________  \n\
\033[0;33m                       |   _____| | ___ \\    |   _____| \n \
 \033[0;31m                     |  |__     ||   \\ \\   |  |___     \n \
 \033[0;33m                     |   __|    ||   | |   |  ___|   \n \
 \033[0;31m                     |  |       ||   | |   | |        \n \
 \033[0;33m                     |  |       ||__ / /   | |        \n \
 \033[0;31m                     |__|       |_____/    |_|        \n \
\t\t\t\t\t\t \033[0;34m  \e[3m\e[1m made by emedeiro \n\n"

# define INPUT_ERR "\033[1;35mFDF_1337: ====> \033[1;33m \
please enter a valid fdf map as follows: ./fdf [map.42]"
# define MALLOC_ERR "\033[1;35mFDF_1337: -----> \033[1;33 \
mthere was an unexpected error in malloc :( "
# define FILE_ERR "\033[1;35mFDF_1337: -----> \033[1;33m \
the file you entered was not found :("
# define EXTENSION_ERR "\033[1;35mFDF_1337: -----> \
\033[1;33mplease enter a file that ends with [.fdf]"
# define INVALID_MAP_ERR "\033[1;35mFDF_1337: -----> \033[1;33m \
the map you entered is invalid :("
# define END_MSG "\033[1;35m FDF_1337 -----> \033[1;33m \
the program has been closed properly!"
# define MLX_ERR "\033[1;35mFDF_1337: -----> \033[1;33m \
THERE WAS AN ERROR IN THE MINILIBX INITIALIZATION :("
# define WIN_ERR "\033[1;35mFDF_1337: -----> \033[1;33m \
THERE WAS AN UNEXPECTED ERROR IN CREATING THE WINDOW :("
# define TITLE "FDF_1337"

# define MAX_COLOR_HEX 16777215
# define VIOLET_HEX 0x8F00FF
# define YELLOW_HEX 0xFFFF00
# define BLUE_HEX 0x177E89

#define ISO 1

#endif
