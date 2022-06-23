# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 12:05:37 by cproesch          #+#    #+#              #
#    Updated: 2022/06/23 17:59:16 by cproesch         ###   ########.fr        #
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

OBJS_FT			=	$(SRCS:%.cpp=objects_ft/%.o)
OBJS_STD 		=	$(SRCS:%.cpp=objects_std/%.o)

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

all:			$(NAME_FT) $(NAME_STD)

objects_ft/%.o:	%.cpp
				mkdir objects_ft/
				$(CXX) -c $< $(CXXFLAGS) -o $@ $(IFLAGS)

objects_std/%.o:%.cpp
				mkdir objects_std/
				$(CXX) -c $< $(CXXFLAGS) -o $@ $(IFLAGS)

$(NAME_FT):		$(OBJS_FT)
				$(CXX) $(OBJS_FT) -o $(NAME_FT)

$(NAME_STD):	$(OBJS_STD)
				$(CXX) $(OBJS_STD) -o $(NAME_STD)

$(OBJ_DIR):
				mkdir $(OBJ_DIR)
			
clean:		
				$(RM) $(OBJS_FT) $(OBJS_STD) file*

fclean:			clean
				$(RM) $(NAME1) $(NAME2)

re:				fclean all

.PHONY:			all clean fclean re