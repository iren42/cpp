NAME	= RPN

HEADER	=	RPN.hpp 


SRC		=	main.cpp \
			RPN.cpp	

OBJ	= $(SRC:.cpp=.o)

CC		= c++

CFLAG	= -Wall -Wextra -Werror -std=c++98 

ifeq ($(DEBUG), 1)
	CFLAG += -DDEBUG
endif

SANI	= 
#-fsanitize=address -g3 -Wconversion -Wsign-conversion

RM		= rm -f


.PHONY:	all 
all		: $(NAME)

$(OBJ)	: $(SRC) $(HEADER)
			$(CC) $(CFLAG) $(SANI) -c $(SRC)

$(NAME) : $(OBJ) $(HEADER)
			$(CC) $(CFLAG) $(SANI) -o $@ $(OBJ) 


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

