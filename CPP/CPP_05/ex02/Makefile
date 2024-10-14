# Variables
NAME = ex02
CXX = g++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = main.cpp Bureaucrat.cpp Form.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
OBJS_DIR = .objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

# Colors
GREEN = \033[0;32m
RESET = \033[0m

# Rule: Create the .objs directory if it doesn't exist
$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule: Compile and create executable
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Executable ready!$(RESET)"

# Rule: Clean object files
clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(GREEN)Object files cleaned!$(RESET)"

# Rule: Full clean (object files and executable)
fclean: clean
	@rm -f $(NAME)
	@rm -f *_shrubbery
	@echo "$(GREEN)EExecutable, object files and shrubbery files fully cleaned!$(RESET)"

# Rule: Recompile everything
re: fclean all

# No relinking if not necessary
.PHONY: all clean fclean re
