##
## Makefile for Missile Command in /home/okami/rendu/Orsay/missileCommand2
##
## Made by Pierrick Garcia
## Login   <pierrick.garcia@u-psud.fr>
##
## Started on  Tue Oct 10 13:52:27 2017 Pierrick Garcia
## Last update Fri Oct 20 15:16:46 2017 Pierrick Garcia
##

COMP		= g++

EDITOR		= emacs -nw

CFLAGS		+= -W -Wall -Wextra -Werror -O3

INCLUDES	+= -I./include

RM		= rm -f

NAME		= missileCommand

LDFLAGS		+= -lsfml-graphics -lsfml-window -lsfml-system

DBGFLAGS	= -g3

SRC		= src/main.cpp \
		  src/MissileCommand.cpp

OBJ		= $(SRC:.cpp=.o)

ECHO		= echo -e

DEFAULT		= "\033[00m"
GREEN		= "\033[0;32m"
BLUE		= "\033[1;36m"
RED		= "\033[0;31m"

all: $(NAME)

%.o: %.cpp
	@$(COMP) -o $@ -c $< $(CFLAGS) $(LDFLAGS) $(INCLUDES) && \
	 ($(ECHO) $(GREEN) "[OK]" $(BLUE) $@ $(DEFAULT)) || \
	 ($(ECHO) $(RED) "[XX]" $(BLUE) $@ $(DEFAULT))

$(NAME): $(OBJ)
	@$(COMP) $(OBJ) -o $@ $(CFLAGS) $(LDFLAGS) $(INCLUDES) && \
	 ($(ECHO) $(GREEN) "[OK]" $(BLUE) $@ $(DEFAULT)) || \
	 ($(ECHO) $(RED) "[XX]" $(BLUE) $@ $(DEFAULT))

clean:
	@$(RM) $(OBJ)
	@$(ECHO) $(BLUE) "Cleaning object files" $(DEFAULT)

fclean: clean
	@$(RM) $(NAME)
	@$(ECHO) $(BLUE) "Cleaning binary" $(DEFAULT)

re: fclean all

rec: all clean

edit:
	$(EDITOR) $(SRC)

debug:	CFLAGS += $(DBGFLAGS)
debug:	re

.PHONY: all clean fclean re rec edit debug
