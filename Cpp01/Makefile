NAME	= zombie

INC		=	Zombie.hpp 

SRC		=	Zombie.cpp \
			randomChump.cpp \
			newZombie.cpp

OBJ	= $(SRC:.cpp=.o)

CC		= g++

CFLAG	= -Wall -Wextra -Werror -std=c++98

RM		= rm -f

all		: $(NAME) $(HEADER)

$(OBJ)	: $(SRC) $(HEADER)
		$(CC) $(CFLAG) $(HEADER) -c $(SRC)

$(NAME) : $(OBJ) $(HEADER)
		$(CC) $(CFLAG) -o $@ $(OBJ) 


clean	:
		$(RM) $(OBJ)

fclean	: clean
		$(RM) $(NAME)

re		: fclean all


.PHONY:	all clean fclean re
