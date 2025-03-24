CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g 

# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
ORANGE = \033[0;38;5;166m

NAME = program
SRCS = \
		main.cpp \
		Harl.cpp \

OBJS = $(SRCS:.cpp=.o)

# Build targets
all:  $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) && echo "$(GREEN)$(NAME) was created$(RESET)"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@ && echo "$(GREEN)object files were created$(RESET)"

RM = rm -rf

clean:
	@$(RM) $(OBJS) && echo "$(ORANGE)object files were deleted$(RESET)"

fclean: clean
	@$(RM) $(NAME) && echo "$(ORANGE)$(NAME) was deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus
