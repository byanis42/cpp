# Variables
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Serializer.cpp Data.cpp
OBJS_DIR = .objs/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))
NAME = Serializer

# Règle all (compilation de l'exécutable)
all: $(NAME)

# Compilation de l'exécutable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Compilation des fichiers .o dans le dossier .objs/
$(OBJS_DIR)%.o: %.cpp
	@mkdir -p $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage des fichiers objets et du dossier .objs/
clean:
	@rm -rf $(OBJS_DIR)

# Nettoyage complet des fichiers objets, du dossier .objs/ et de l'exécutable
fclean: clean
	@rm -f $(NAME)

# Recompilation complète
re: fclean all

# Indiquer que certaines cibles ne sont pas des fichiers
.PHONY: all clean fclean re
