# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 09:51:12 by cdapurif          #+#    #+#              #
#    Updated: 2022/08/25 15:20:41 by cdapurif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

############################ STACK PART #############################
STACK_SRCS =	main.cpp

STACK_OBJS =	$(addprefix containers/stack/, $(STACK_SRCS:.cpp=.o))
#####################################################################

############################ VECTOR PART ############################
#####################################################################

############################# MAP PART ##############################
#####################################################################

all: stack

################# STACK #################
stack: ft_stack std_stack

ft_stack: NAMESPACE = 0
ft_stack: NS = ft_
ft_stack: $(STACK_OBJS)
#	$(CXX) $(CXXFLAGS) $(STACK_OBJS) -o ft_stack
	$(CXX) $(CXXFLAGS) $(addprefix $(dir $<)$(NS), $(notdir $<)) -o $@

std_stack: NAMESPACE = 1
std_stack: NS = std_
std_stack: $(STACK_OBJS)
	$(CXX) $(CXXFLAGS) $(STACK_OBJS) -o std_stack

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $(addprefix $(dir $@)$(NS), $(notdir $@)) -D NSP=$(NAMESPACE)

clean:
	$(RM) ./containers/stack/*.o

fclean: clean
	$(RM) ft_* std_*

re: fclean all

.PHONY: all stack clean fclean re