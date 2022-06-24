# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 12:05:37 by cproesch          #+#    #+#              #
#    Updated: 2022/06/24 10:58:53 by cproesch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#								EXECUTABLE									   #
################################################################################

NAME_FT		=	containers_ft
NAME_STD	=	containers_std

################################################################################
#									FILES									   #
################################################################################

SRC_DIR			=	tests/
SRC_FILES		=	main.cpp test_pairs.cpp
SRCS			=	$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJS_DIR_FT		=	objects_ft/
OBJS_DIR_STD	=	objects_std/
OBJS_FILES		=	$(SRC_FILES:.cpp=.o)
OBJS_FT			=	$(addprefix $(OBJS_DIR_FT), $(OBJS_FILES))
OBJS_STD 		=	$(addprefix $(OBJS_DIR_STD), $(OBJS_FILES))

################################################################################
#							COMMANDS AND FLAGS								   #
################################################################################

RM			=	rm -rf

CXX 		=	c++

IFLAGS		=	-Iincludes -I.

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g

$(NAME_FT)	= 	CXXFLAGS += -D LIB=ft
$(NAME_STD)	= 	CXXFLAGS += -D LIB=std

################################################################################
#									RULES									   #
################################################################################

all:				$(NAME_FT) $(NAME_STD)

$(NAME_FT):			$(OBJS_DIR_FT) $(OBJS_FT)
					$(CXX) $(OBJS_FT) -o $(NAME_FT)

$(NAME_STD):		$(OBJS_DIR_STD) $(OBJS_STD)
					$(CXX) $(OBJS_STD) -o $(NAME_STD)

$(OBJS_DIR_FT):
					mkdir $(OBJS_DIR_FT)

$(OBJS_DIR_STD):
					mkdir $(OBJS_DIR_STD)

$(OBJS_DIR_FT)%.o:	$(SRC_DIR)%.cpp
					$(CXX) -c $< $(CXXFLAGS) -o $@ $(IFLAGS)

$(OBJS_DIR_STD)%.o:	$(SRC_DIR)%.cpp
					$(CXX) -c $< $(CXXFLAGS) -o $@ $(IFLAGS)
			
clean:		
					$(RM) $(OBJS_FT) $(OBJS_STD) file*

fclean:				clean
					$(RM) $(NAME_FT) $(NAME_STD)

re:					fclean all

.PHONY:				all clean fclean re