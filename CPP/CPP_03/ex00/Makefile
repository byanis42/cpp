CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = claptrap
SOURCES = main.cpp ClapTrap.cpp
HEADERS = ClapTrap.hpp
OBJECTS = $(SOURCES:.cpp=.o)

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
