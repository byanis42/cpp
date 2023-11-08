CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: replace

replace: main.cpp
	$(CXX) $(CXXFLAGS) -o replace main.cpp

clean:
	rm -f replace

fclean: clean
	rm -rf replace

re: fclean all

.PHONY: all clean fclean re
