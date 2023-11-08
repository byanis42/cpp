CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CPPFLAGS = -I.
LDFLAGS =
LDLIBS =

SRC_HUMAN_A = HumanA.cpp
SRC_HUMAN_B = HumanB.cpp
SRC_WEAPON = Weapon.cpp
SRC_MAIN = main.cpp

OBJ_HUMAN_A = $(SRC_HUMAN_A:.cpp=.o)
OBJ_HUMAN_B = $(SRC_HUMAN_B:.cpp=.o)
OBJ_WEAPON = $(SRC_WEAPON:.cpp=.o)
OBJ_MAIN = $(SRC_MAIN:.cpp=.o)

NAME = humanity

all: $(NAME)

$(NAME): $(OBJ_HUMAN_A) $(OBJ_HUMAN_B) $(OBJ_WEAPON) $(OBJ_MAIN)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

clean:
	$(RM) $(OBJ_HUMAN_A) $(OBJ_HUMAN_B) $(OBJ_WEAPON) $(OBJ_MAIN)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
