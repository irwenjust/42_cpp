NAME := violence
FLAGS := -Wall -Wextra -Werror -std=c++11
SRCS := main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJS_DIR := objs
COMPILER := c++

OBJS = $(SRCS:.cpp=.o)
TARGETS = $(addprefix $(OBJS_DIR)/, $(OBJS))

all: $(NAME)

$(OBJS_DIR)/%.o: %.cpp
	$(COMPILER) $(FLAGS) -c $^ -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS_DIR) $(TARGETS)
	$(COMPILER) $(FLAGS) -o $(NAME) $(TARGETS)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
