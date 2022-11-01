# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 09:51:12 by cdapurif          #+#    #+#              #
#    Updated: 2022/11/01 17:08:27 by cdapurif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = containers

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

DIR =	containers/stack \
		containers/vector

BINARY =	ft_stack \
			std_stack \
			ft_vector \
			std_vector

SRCS = $(foreach dir,$(DIR),$(dir)/main.cpp)

FT_OBJS	= $(SRCS:main.cpp=ft_main.o)
STD_OBJS = $(SRCS:main.cpp=std_main.o)

all: $(NAME)

$(NAME): stack vector

############################# STACK RULES #############################
stack: ft_stack std_stack

ft_stack: $(FT_OBJS)
	$(CXX) containers/stack/ft_main.o -o $@

std_stack: $(STD_OBJS)
	$(CXX) containers/stack/std_main.o -o $@
#######################################################################

############################# VECTOR RULES ############################
vector: ft_vector std_vector

ft_vector: $(FT_OBJS)
	$(CXX) containers/vector/ft_main.o -o $@

std_vector: $(STD_OBJS)
	$(CXX) containers/vector/std_main.o -o $@
#######################################################################

ft_%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -D NSP=0

std_%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -D NSP=1

show:
	@echo SRCS: $(SRCS)
	@echo FT_OBJS: $(FT_OBJS)
	@echo STD_OBJS: $(STD_OBJS)
	@echo BINARY: $(BINARY)

clean:
	$(RM) $(FT_OBJS)
	$(RM) $(STD_OBJS)

fclean: clean
	$(RM) $(BINARY)

re: fclean all

.PHONY: all stack clean fclean re