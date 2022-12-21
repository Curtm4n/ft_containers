# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 09:51:12 by cdapurif          #+#    #+#              #
#    Updated: 2022/12/21 17:32:08 by cdapurif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = containers

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

DIR =	containers/stack \
		containers/vector \
		containers/map

BINARY =	ft_stack \
			std_stack \
			ft_vector \
			std_vector \
			ft_map \
			std_map

SRCS = $(foreach dir,$(DIR),$(dir)/main.cpp)

UTILS = containers/map/tree.cpp
UTILS_OBJS = $(UTILS:.cpp=.o)

FT_OBJS	= $(SRCS:main.cpp=ft_main.o)
STD_OBJS = $(SRCS:main.cpp=std_main.o)

all: $(NAME)

$(NAME): stack vector map

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

############################## MAP RULES ##############################
map: ft_map std_map

ft_map: $(FT_OBJS) $(UTILS_OBJS)
	$(CXX) containers/map/ft_main.o containers/map/tree.o -o $@

std_map: $(STD_OBJS) $(UTILS_OBJS)
	$(CXX) containers/map/std_main.o containers/map/tree.o -o $@
#######################################################################

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

ft_%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -D NSP=0

std_%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -D NSP=1

show:
	@echo SRCS: $(SRCS)
	@echo FT_OBJS: $(FT_OBJS)
	@echo STD_OBJS: $(STD_OBJS)
	@echo UTILS_OBJS: $(UTILS_OBJS)
	@echo BINARY: $(BINARY)

clean:
	$(RM) $(FT_OBJS)
	$(RM) $(STD_OBJS)
	$(RM) $(UTILS_OBJS)

fclean: clean
	$(RM) $(BINARY)

re: fclean all

.PHONY: all stack vector clean fclean re