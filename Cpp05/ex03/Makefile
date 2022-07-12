NAME	= ex03

HEADER	=	Bureaucrat.hpp \
			RobotomyRequestForm.hpp \
			PresidentialPardonForm.hpp \
			ShrubberyCreationForm.hpp \
			Intern.hpp \
			Form.hpp


SRC		=	Bureaucrat.cpp \
			Form.cpp \
			RobotomyRequestForm.cpp \
			PresidentialPardonForm.cpp \
			ShrubberyCreationForm.cpp \
			Intern.cpp \
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
