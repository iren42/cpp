NAME	= PmergeMe

HEADER	=	PmergeMe.hpp 


SRC		=	main.cpp \
			PmergeMe.cpp	

OBJ	= $(SRC:.cpp=.o)

CC		= c++

CFLAG	= -g -std=c++98 -Wall -Wextra -Werror 

ifeq ($(DEBUG), 1)
	CFLAG += -DDEBUG -fsanitize=address 
endif

SANI	= 
#-fsanitize=address -g3 
#-Wconversion -Wsign-conversion

RM		= rm -f


.PHONY:	all 
all		: $(NAME)

$(OBJ)	: $(SRC) $(HEADER)
			$(CC) $(CFLAG)  -c $(SRC)

$(NAME) : $(OBJ) $(HEADER)
			$(CC) $(CFLAG)  -o $@ $(OBJ) 


.PHONY: clean
clean	:
		$(RM) $(OBJ)

.PHONY: fclean
fclean	: clean
		$(RM) $(NAME)

.PHONY:re
re		: fclean all

.PHONY:debug
debug	: fclean
		$(MAKE) DEBUG=1

