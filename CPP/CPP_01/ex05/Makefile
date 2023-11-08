CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Harl.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = harl

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
