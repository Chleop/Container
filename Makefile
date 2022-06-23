# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 12:05:37 by cproesch          #+#    #+#              #
#    Updated: 2022/06/23 15:46:50 by cproesch         ###   ########.fr        #
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

all:	$(OBJS1) $(OBJS2)
ifeq ($(LIB), FT)
	@echo FT
	make fclean
	$(CXX) $(OBJS1) -o $(NAME1)
else
	@echo STD
	make fclean
	$(CXX) -DLIB=1 $(OBJS2) -o $(NAME2)
endif

%.o:		%.cpp
ifeq ($(LIB), FT)
	$(CXX) -c $< $(CXXFLAGS) -o $@ $(IFLAGS)
else
	$(CXX) -c $< $(CXXFLAGS) -DLIB=1 -o $@ $(IFLAGS)
endif
			
clean:		
			$(RM) $(OBJS1) $(OBJS2) file*

fclean:		clean
			$(RM) $(NAME1) $(NAME2)

re:			fclean all

.PHONY:		all clean fclean re