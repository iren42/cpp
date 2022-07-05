NAME	= phonebook

HEADER	=	PhoneBook.hpp \
			Contact.hpp \
			main.hpp

SRC		=	PhoneBook.cpp \
			Contact.cpp \
			main.cpp

OBJ	= $(SRC:.cpp=.o)

GCH = $(HEADER:.hpp=.hpp.gch)

CC		= g++

CFLAG	= -Wall -Wextra -Werror -std=c++98

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
