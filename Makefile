# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 12:05:37 by cproesch          #+#    #+#              #
#    Updated: 2022/06/22 18:17:32 by cproesch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#								EXECUTABLE									   #
################################################################################

NAME1	=	containers_ft
NAME2	=	containers_std

################################################################################
#									FILES									   #
################################################################################

# T_DIR	=	tests/

SRCS1	=	tests/main.cpp tests/test_pairs.cpp
SRCS2	=	tests/main_std.cpp tests/test_pairs.cpp

OBJS1	=	$(SRCS1:.cpp=.o)
OBJS2	=	$(SRCS2:.cpp=.o)

################################################################################
#							COMMANDS AND FLAGS								   #
################################################################################

RM			=	rm -rf

CXX 		=	c++

IFLAGS		=	-Iincludes -I.

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g


################################################################################
#									RULES									   #
################################################################################

all:	$(NAME1)

%.o:		%.cpp
ifeq ($(LIB), STD)
	$(CXX) -c $< $(CXXFLAGS) -DLIB=1 -o $@ $(IFLAGS)
else
	$(CXX) -c $< $(CXXFLAGS) -o $@ $(IFLAGS)
endif

$(NAME1):	$(OBJS1)
			@echo FT
			$(CXX) $(OBJS1) -o $(NAME1)

$(NAME2):	$(OBJS2)
			@echo STD
			$(CXX) -DLIB=1 $(OBJS2) -o $(NAME2) 

ft:			$(NAME1)

std:		$(NAME2)
			
clean:		
			$(RM) $(OBJS1) $(OBJS2) file*.txt

fclean:		clean
			$(RM) $(NAME1) $(NAME2)

re:			fclean all

.PHONY:		all clean fclean re