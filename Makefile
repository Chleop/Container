# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cproesch <cproesch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 12:05:37 by cproesch          #+#    #+#              #
#    Updated: 2022/06/24 12:07:03 by cproesch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#								EXECUTABLE									   #
################################################################################

NAME_FT				=	containers_ft
NAME_STD			=	containers_std

################################################################################
#									FILES									   #
################################################################################

SRC_DIR				=	tests/
SRC_FILES			=	main.cpp test_pairs.cpp test_equal.cpp
SRCS				=	$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJS_FT				=	$(SRCS:%.cpp=objs/ft_out/%.o)
OBJS_STD			=	$(SRCS:%.cpp=objs/std_out/%.o)

################################################################################
#							COMMANDS AND FLAGS								   #
################################################################################

RM					=	rm -rf

CXX 				=	c++

IFLAGS				=	-Iincludes -I.

CXXFLAGS			=	-Wall -Wextra -Werror -std=c++98 -g

################################################################################
#									RULES									   #
################################################################################

all:				$(NAME_FT) $(NAME_STD)

$(NAME_FT):			$(OBJS_FT)
					$(CXX) $(OBJS_FT) -o $(NAME_FT)

$(NAME_STD):		$(OBJS_STD)
					$(CXX) $(OBJS_STD) -o $(NAME_STD)

objs/ft_out/%.o:	%.cpp
					mkdir -p $(@D)
					$(CXX) -c $< $(CXXFLAGS) -o $@ $(IFLAGS)

objs/std_out/%.o:	CXXFLAGS += -D LIB=std
objs/std_out/%.o:	%.cpp
					mkdir -p $(@D)
					$(CXX) -c $< $(CXXFLAGS) -o $@ $(IFLAGS)
			
clean:		
					$(RM) $(OBJS_FT) $(OBJS_STD) file* objs/ft_out/ objs/std_out/ objs/

fclean:				clean
					$(RM) $(NAME_FT) $(NAME_STD)

re:					fclean all

.PHONY:				all clean fclean re