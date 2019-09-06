##
## Makefile for make in /home/morgan/rendu/cpp_gkrellm
##
## Made by Morgan Simon
## Login   <morgan.simon@epitech.eu>
##
## Started on  Sat Jan 21 11:44:48 2017 Morgan Simon
## Last update Sun Mar  5 04:44:50 2017 rousse_i
##

NAME	=	nanotekspice

CXX	=	clang++ -g

SRC	=	src/2716.cpp		\
		src/4001.cpp		\
		src/4008.cpp		\
		src/4011.cpp		\
		src/4013.cpp		\
		src/4030.cpp		\
		src/4040.cpp		\
		src/4069.cpp		\
		src/4071.cpp		\
		src/4081.cpp		\
		src/terminal.cpp	\
		src/main.cpp		\
		src/Parser.cpp		\
		src/Action.cpp		\
		src/chipset.cpp		\
		src/CompoManager.cpp	\
		src/CompoPin.cpp	\

INC	=	include/

CXXFLAGS	+=	-Wall -Wextra -Werror -std=c++11 -I$(INC)

LDFLAGS	=

OBJ	=	$(SRC:.cpp=.o)

RM	=	rm -f

ECHO	=	/bin/echo -e

all:		flag $(NAME)

flag:
		@$(ECHO) "\n\033[0;31mFLAGS : \033[00m" $(CXXFLAGS) "\n"

$(NAME):	$(OBJ)
		@$(CXX) $(OBJ) -o $(NAME) $(LDFLAGS)
		@$(ECHO) "\n\e[1;32m >> " $(NAME) " OK <<\e[00m\n"

clean:
		@$(RM) $(OBJ)
		@$(ECHO) "\033[0;32mClean OBJ    Files\033[00m"

fclean:		clean
		@$(RM) $(NAME)
		@$(ECHO) "\033[0;32mClean Binary Files\033[00m"

re:		fclean all

%.o:		%.cpp
		@$(CXX) $(CXXFLAGS) -c $< -o $@ && \
		 $(ECHO) "\033[0;32m ◉  »\033[1;34m" $< "\033[00m" || \
		 $(ECHO) "\033[0;31m ⊗  »\033[1;34m" $< "\033[00m"

.PHONY:		all clean fclean re
