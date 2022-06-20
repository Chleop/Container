# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 12:05:37 by cproesch          #+#    #+#              #
#    Updated: 2022/06/17 12:06:04 by cproesch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#								EXECUTABLE									   #
################################################################################

NAME	=	containers

################################################################################
#									FILES									   #
################################################################################

SRCS	=	main.cpp 

OBJS	=	$(SRCS:.cpp=.o)

################################################################################
#							COMMANDS AND FLAGS								   #
################################################################################

RM			=	rm -rf

CXX 		=	c++

IFLAGS		=	-I.

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g

################################################################################
#									RULES									   #
################################################################################

all:		$(NAME)

%.o:		%.cpp
			$(CXX) -c $< $(CXXFLAGS) -o $@ $(IFLAGS)

$(NAME):	$(OBJS)
			$(CXX) $(OBJS) -o $(NAME)

clean:		
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re