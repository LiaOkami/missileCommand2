##
## Makefile for Missile Command in /home/okami/rendu/Orsay/missileCommand2
##
## Made by Pierrick Garcia
## Login   <pierrick.garcia@u-psud.fr>
##
## Started on  Tue Oct 10 13:52:27 2017 Pierrick Garcia
## Last update Tue Oct 10 14:10:56 2017 Pierrick Garcia
##

COMP		= g++

EDITOR		= emacs -nw

CFLAGS		+= -W -Wall -Wextra -Werror
CFLAGS		+= -ldl -lpthread

INCLUDES	+= -I./include

RM		= rm -f

NAME		= missileCommand

LDFLAGS		+= -Llib -lsfml-graphics -lsfml-window -lsfml-system

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
	@$(COMP) -o $@ -c $< $(CFLAGS) $(LDFLAGS) $(INCLUDES) $(INCLUDES) && \
	 ($(ECHO) $(GREEN) "[OK]" $(BLUE) $@ $(DEFAULT)) || \
	 ($(ECHO) $(RED) "[XX]" $(BLUE) $@ $(DEFAULT))

$(NAME): $(OBJ)
	@$(COMP) $(OBJ) -o $@ $(CFLAGS) $(LDFLAGS) $(INCLUDES) && \
	 ($(ECHO) $(GREEN) "[OK]" $(BLUE) $@ $(DEFAULT)) || \
	 ($(ECHO) $(RED) "[XX]" $(BLUE) $@ $(DEFAULT))

debug:
	$(COMP) -o $(NAME).debug $(SRC) $(INCLUDES) $(CFLAGS) $(LDFLAGS) -g

clean:
	@$(RM) $(OBJ)
	@$(ECHO) $(BLUE) "Cleaning object files" $(DEFAULT)

fclean: clean
	@$(RM) $(NAME) $(NAME).debug
	@$(ECHO) $(BLUE) "Cleaning binary" $(DEFAULT)

re: fclean all

rec: all clean

edit:
	$(EDITOR) $(SRC)

dbg:	CFLAGS += $(DBGFLAGS)
dbg:	re

.PHONY: all clean fclean re rec edit dbg