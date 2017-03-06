# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mseinic <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/28 16:27:43 by mseinic           #+#    #+#              #
#    Updated: 2016/08/19 15:55:10 by mseinic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

T_TAB_PATH:=t_tab_fnct/
T_TAB:=t_tab_add t_tab_expand t_tab_free t_tab_init t_tab_reserve

STR_PATH:=ft_string/
STR:=ft_strcat ft_strcmp ft_strcpy ft_strdup ft_strlen ft_strlcat \
	 ft_strchr ft_strncmp ft_strncpy ft_strncat ft_strnstr ft_strrchr \
	 ft_strstr ft_strdel ft_strjoin ft_strnew ft_strequ ft_strmap ft_strsplit \
	 ft_striter ft_strmapi ft_strsub ft_strclr ft_striteri ft_strnequ \
	 ft_strtrim ft_str_lower ft_str_error ft_strtrimchr
TREE_PATH:=ft_tree_utilities/
TREE:=ft_add_node_to_tree

FILES:= ft_bzero ft_isalnum ft_isalpha ft_isascii ft_isdigit \
	ft_isprint ft_memchr ft_memcmp ft_memset \
	ft_tolower \
	ft_toupper ft_atoi ft_memcpy ft_memmove ft_memccpy \
	ft_itoa ft_putchar_fd ft_putnbr_fd\
	ft_memalloc ft_putendl ft_putstr\
	ft_memdel ft_putendl_fd ft_putstr_fd \
	ft_putchar ft_putnbr\
	ft_lstadd ft_lstdel ft_lstdelone ft_lstiter ft_lstmap ft_lstnew	\
	ft_abs ft_iswhitespaces ft_lstaddend ft_count_alpha \
	ft_count_digit ft_count_alnum get_next_line ft_tree_destructor
HEADERS_LIST = libft

SRC_PATH:=src/

HEADERS_PATH:=includes/

CACHE_PATH:=cache/

COMPILER:=clang

CFLAGS:= -Wall -Werror -Wextra

ALL_FLAGS:=$(CFLAGS) -I $(HEADERS_PATH)

#----------------ADDING PATH AND FORMAT TO THE FILENAMES--------------------#
FILES+=$(addprefix $(T_TAB_PATH),$(T_TAB))
FILES+=$(addprefix $(STR_PATH),$(STR))
FILES+=$(addprefix $(TREE_PATH),$(TREE))

SRC = $(addprefix $(SRC_PATH),$(addsuffix .c,$(FILES)))
OBJ = $(addprefix $(CACHE_PATH),$(addsuffix .o,$(FILES)))
#----------------ADDING PATH AND FORMAT TO THE FILENAMES--------------------#

#-----------------COLORS------------------#
#-------B = Bolt---------#
#-------I = Intense------#
#-------U = Underline----#
Green = "\033[0;32m"
B_I_Red = "\033[1;91m"
Yellow  = "\033[0;33m"
END     = "\033[0m"
#-----------------COLORS------------------#
CACHE:=.cache_exists

all: $(NAME)

#======= compiling NAME file =======
$(NAME): $(OBJ)
	@echo $(Yellow) " Compiling --------> $@ <--------" $(END)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo $(Green) " !!! Ready !!!" $(END)

#======= compiling *.c in *.o ======
$(CACHE_PATH)%.o: $(SRC_PATH)%.c | $(CACHE)
	@echo $(Green)" -------- Compiling $< into \t >> \t$@ --------" $(END)
	@$(COMPILER) $(ALL_FLAGS) -c $< -o $@

%.c:
	@echo $(B_I_Red) "Missing file : $@" $(END)

$(CACHE):
	@mkdir $(CACHE_PATH)
	@mkdir $(CACHE_PATH)$(T_TAB_PATH)
	@mkdir $(CACHE_PATH)$(STR_PATH)
	@mkdir $(CACHE_PATH)$(TREE_PATH)
	@touch $(CACHE)

#======= compiling *.h files ======
#$(CACHE_PATH)%.h.gch: $(HEADERS_PATH)%.h $(CACHE_PATH)
#	@echo " -------- Compiling $< into $@ --------" $(END)
#	@$(COMPILER) $(ALL_FLAGS) -o $@ -c $<
#======= creating cache file if not existing =======
#$(CACHE_PATH):
#	@echo $(Yellow) " cache not yet existing creating it ./" $(END)
clean:
	/bin/rm -rf $(CACHE_PATH)
	/bin/rm -rf $(CACHE)
fclean: clean
	/bin/rm -rf $(NAME)
re: fclean all

test:
	@echo "obj :" $(OBJ)
	@echo "files :" $(SRC)

.PHONY: all clean fclean re
