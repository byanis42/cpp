CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Fixed.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = fixed

all: $(TARGET)

$(TARGET): main.cpp $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ main.cpp $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
