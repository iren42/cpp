NAME	= megaphone

SRC		=	megaphone.cpp 

OBJ	= $(SRC:.cpp=.o)

CC		= g++

CFLAG	= -Wall -Wextra -Werror -std=c++98

RM		= rm -f

all		: $(NAME)

$(OBJ)	: $(SRC)
		$(CC) $(CFLAG) -c $(SRC)

$(NAME) : $(OBJ)
		$(CC) $(CFLAG) -o $@ $(OBJ) 


clean	:
		$(RM) $(OBJ)

fclean	: clean
		$(RM) $(NAME)

re		: fclean all


.PHONY:	all clean fclean re
