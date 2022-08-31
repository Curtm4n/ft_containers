# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 09:51:12 by cdapurif          #+#    #+#              #
#    Updated: 2022/08/31 13:26:17 by cdapurif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

DIR = containers/stack

BINARY = $(wildcard *_*)

GET_SRCS = $(wildcard $(DIR)/*.cpp)

FT_OBJS	= $(patsubst $(DIR)/%.cpp,$(DIR)/ft_%.o, $(GET_SRCS))
STD_OBJS = $(patsubst $(DIR)/%.cpp,$(DIR)/std_%.o, $(GET_SRCS))

all: stack

############################# STACK RULES #############################
stack: ft_stack std_stack

ft_stack: $(FT_OBJS)
	$(CXX) $< -o $@

std_stack: $(STD_OBJS)
	$(CXX) $< -o $@
#######################################################################

ft_%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -D NSP=0

std_%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -D NSP=1

show:
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