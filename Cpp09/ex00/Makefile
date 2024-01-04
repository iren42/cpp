NAME	= btc

HEADER	=	BitcoinExchange.hpp 


SRC		=	BitcoinExchange.cpp \
			main.cpp

OBJ	= $(SRC:.cpp=.o)


CC		= c++

CFLAG	= -std=c++98 -Wall -Wextra -Werror 

SANI	= 
#-fsanitize=address -g3 -Wconversion -Wsign-conversion

RM		= rm -f

all		: $(NAME)

$(OBJ)	: $(SRC) $(HEADER)
		$(CC) $(CFLAG) $(SANI) -c $(SRC)

$(NAME) : $(OBJ) $(HEADER)
		$(CC) $(CFLAG) $(SANI) -o $@ $(OBJ) 


clean	:
		$(RM) $(OBJ)

fclean	: clean
		$(RM) $(NAME)

re		: fclean all


.PHONY:	all clean fclean re
