NAME	= ex00

HEADER	=	Zombie.hpp 

SRC		=	Zombie.cpp \
			randomChump.cpp \
			newZombie.cpp \
			main.cpp

OBJ	= $(SRC:.cpp=.o)

GCH = $(HEADER:.hpp=.hpp.gch)

CC		= c++

CFLAG	= -Wall -Wextra -Werror -std=c++98

SANI	= 
#-fsanitize=address -g -Wconversion -Wsign-conversion

RM		= rm -f

all		: $(NAME) $(HEADER)

$(OBJ)	: $(SRC) $(HEADER)
		$(CC) $(CFLAG) $(HEADER) -c $(SRC)

$(NAME) : $(OBJ) $(HEADER)
		$(CC) $(CFLAG) -o $@ $(OBJ) 


clean	:
		$(RM) $(OBJ) $(GCH)

fclean	: clean
		$(RM) $(NAME)

re		: fclean all


.PHONY:	all clean fclean re
