##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

SRC			=	AComponent.cpp					\
				Circuit.cpp						\
				components/AndComponent.cpp		\
				components/FalseComponent.cpp	\
				components/TrueComponent.cpp	\
				components/InputComponent.cpp	\
				components/OutputComponent.cpp	\
				components/ClockComponent.cpp	\
				components/NotComponent.cpp		\
				components/OrComponent.cpp		\
				components/XorComponent.cpp		\
				gates/Nor.cpp					\
				ComponentFactory.cpp			\
				prompt.cpp						\

DIR_SRC		=	$(addprefix src/, $(SRC))

MAIN_SRC	=	main.cpp						\
				Parser/Parser.cpp				\
				Parser/CheckFile.cpp			\
				Parser/CheckCommands.cpp		\
				FileHandling/FileHandling.cpp	\
				Tools/BasicTools.cpp			\

TEST		=	\

DIR_TESTS	=	$(addprefix tests/, $(TEST))

OBJ_DIR_SRC	=	$(DIR_SRC:.cpp=.o)

OBJ_MAIN	=	$(MAIN_SRC:.cpp=.o)

OBJ			=	$(OBJ_DIR_SRC) $(OBJ_MAIN)

CPPFLAGS	=	-I include/						\

CFLAGS		=	-Wall -Wextra -std=c++20

NAME		=	nanotekspice

all: $(NAME)

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -rf unit_tests
		rm -rf *.gcov
		rm -f $(NAME)

re:		fclean all

unit_tests:	re
		mkdir unit_tests
		g++ -o unit_tests/unit_tests $(DIR_SRC) $(DIR_TESTS)\
		--coverage -lcriterion

tests_run:	unit_tests
		./unit_tests/unit_tests

.PHONY: all clean fclean re tests_run