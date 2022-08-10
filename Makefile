# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 09:51:12 by cdapurif          #+#    #+#              #
#    Updated: 2022/08/10 13:17:43 by cdapurif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########################## STACK PART ##########################
STACKNAME = ft_stack

STACKSRCS =	main.cpp

STACKOBJS = $(addprefix containers/stack/, $(STACKSRCS:.cpp=.o))
################################################################

########################## VECTOR PART #########################
################################################################

########################### MAP PART ###########################
################################################################

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

all: $(STACKNAME)

$(STACKNAME): $(STACKOBJS)
	$(CXX) $(CXXFLAGS) $(STACKOBJS) -o $(STACKNAME)

clean:
	$(RM) $(STACKOBJS)

fclean: clean
	$(RM) $(STACKNAME)

re: fclean all

.PHONY: all clean fclean re