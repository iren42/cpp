NAME	= ex03

HEADER	=	Weapon.hpp \
			HumanB.hpp \
			HumanA.hpp 

SRC		=	Weapon.cpp \
			HumanB.cpp \
			main.cpp \
			HumanA.cpp 

OBJ	= $(SRC:.cpp=.o)

GCH	= $(HEADER:.hpp=.hpp.gch)

CC		= g++

CFLAG	= -Wall -Wextra -Werror -std=c++98

SANI	= 
#-fsanitize=address -g

RM		= rm -f

all		: $(NAME)

$(OBJ)	: $(SRC) $(HEADER)
		$(CC) $(CFLAG) $(SANI) $(HEADER) -c $(SRC)

$(NAME) : $(OBJ) $(HEADER)
		$(CC) $(CFLAG) $(SANI) $(HEADER) -o $@ $(OBJ) 


clean	:
		$(RM) $(OBJ) $(GCH)

fclean	: clean
		$(RM) $(NAME)

re		: fclean all


.PHONY:	all clean fclean re
