# Nom du programme
NAME = btc

# Fichiers sources
SRC = main.cpp BitcoinExchange.cpp

# Fichiers objets
OBJ = $(SRC:.cpp=.o)

# Flags de compilation
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Commandes
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Ne relink pas si déjà à jour
$(OBJ): BitcoinExchange.hpp

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
