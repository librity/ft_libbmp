# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 16:25:08 by lpaulo-m          #+#    #+#              #
#    Updated: 2022/02/22 10:49:02 by lpaulo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_libbmp.a

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
CC_STRICT = $(CC) $(CC_FLAGS)
CC_DEBUG_FLAGS = -g -fsanitize=address

SAFE_MAKEDIR = mkdir -p
ARCHIVE_AND_INDEX = ar -rcs

REMOVE = /bin/rm -f
REMOVE_RECURSIVE = /bin/rm -rf

OBJECTS_PATH = ./objects
SOURCES_PATH = ./sources
INCLUDES_PATH = ./includes
EXAMPLES_PATH = ./examples

HEADER_FILE = ft_libbmp.h
HEADER = $(addprefix $(INCLUDES_PATH)/,$(HEADER_FILE))

SOURCES = $(wildcard $(SOURCES_PATH)/*.c)

OBJECTS = $(subst $(SOURCES_PATH)/,$(OBJECTS_PATH)/,$(subst .c,.o,$(SOURCES)))

################################################################################
# REQUIRED
################################################################################

all: $(NAME)

$(NAME): initialize $(HEADER) $(OBJECTS)
	$(ARCHIVE_AND_INDEX) $(NAME) $(OBJECTS)

$(OBJECTS_PATH)/%.o: $(SOURCES_PATH)/%.c
	$(CC_STRICT) -I $(INCLUDES_PATH) -c -o $@ $<

clean:
	$(REMOVE) $(OBJECTS)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

initialize: $(OBJECTS_PATH)

$(OBJECTS_PATH):
	$(SAFE_MAKEDIR) $@

################################################################################
# EXAMPLE
################################################################################

EXAMPLE_MAIN = $(EXAMPLES_PATH)/example.c
IMAGE_NAME = hello.bmp
EXECUTE_EXAMPLE = ./a.out $(IMAGE_NAME)
OPEN_IMAGE = ffplay
EXAMPLE_GARBAGE = a.out a.out.dSYM $(IMAGE_NAME)

example: $(NAME)
	$(CC) $(CC_DEBUG_FLAGS) -I $(INCLUDES_PATH) $(EXAMPLE_MAIN) $(NAME)
	$(EXECUTE_EXAMPLE)
	$(OPEN_IMAGE) $(IMAGE_NAME)

example_clean: fclean
	$(REMOVE_RECURSIVE) $(EXAMPLE_GARBAGE)

################################################################################
# MISC
################################################################################

norm:
	norminette $(INCLUDES_PATH)
	@printf "\n$(G)=== No norminette errors found in $(INCLUDES_PATH) ===$(RC)\n\n"
	norminette $(SOURCES_PATH)
	@printf "\n$(G)=== No norminette errors found in $(SOURCES_PATH) ===$(RC)\n\n"

git:
	git add -A
	git commit -m "update"
	git push

gitm:
	git add -A
	git commit -m $m
	git push

################################################################################
# PHONY
################################################################################

.PHONY: all re clean fclean initialize \
	example example_clean \
	norm git gitm

################################################################################
# Colors
################################################################################

# Black, Red, Green, Yellow, Blue, Purple, Cyan, White
Bk = \033[0;30m
R = \033[0;31m
G = \033[0;32m
Y = \033[0;33m
B = \033[0;34m
P = \033[0;35m
C = \033[0;36m
W = \033[0;37m
# Bold
BkB = \033[1;30m
RB = \033[1;31m
GB = \033[1;32m
YB = \033[1;33m
BB = \033[1;34m
PB = \033[1;35m
CB = \033[1;36m
WB = \033[1;37m
# Reset Color
RC	= \033[0m
