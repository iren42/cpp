NAME	= megaphone

SRC		=	megaphone.cpp 

OBJ	= $(SRC:.cpp=.o)

CC		= g++

CFLAG	= -Wall -Wextra -Werror -std=c++98

SANI	= 
#-fsanitize=address -g -Wconversion -Wsign-conversion

RM		= rm -f

all		: $(NAME)

$(OBJ)	: $(SRC)
		$(CC) $(CFLAG) $(SANI) -c $(SRC)

$(NAME) : $(OBJ)
		$(CC) $(CFLAG) $(SANI) -o $@ $(OBJ) 


clean	:
		$(RM) $(OBJ)

fclean	: clean
		$(RM) $(NAME)

re		: fclean all


.PHONY:	all clean fclean re
