NAME	= ex01

HEADER	=	Animal.hpp \
			Cat.hpp \
			WrongCat.hpp \
			WrongAnimal.hpp \
			Brain.hpp \
			Dog.hpp


SRC		=	Animal.cpp \
			Cat.cpp \
			WrongCat.cpp \
			WrongAnimal.cpp \
			Dog.cpp \
			Brain.cpp \
			main.cpp

OBJ	= $(SRC:.cpp=.o)


CC		= c++

CFLAG	= -Wall -Wextra -Werror -std=c++98

SANI	= -fsanitize=address -g3 -Wconversion -Wsign-conversion

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
