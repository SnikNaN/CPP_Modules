NAME = BraiiiiiiinnnzzzZ
CC = clang++
FLAGS = -Wall -Wextra -Werror -MMD -MP -std=c++98
SRCS = main Zombie newZombie randomChump
OBJ_DIR = obj
SRC_FILE = $(addsuffix .cpp, $(SRCS))
OBJ_FILE = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRCS)))

all: $(NAME)

$(NAME): $(OBJ_FILE)
	$(CC) $(OBJ_FILE) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(@D)
	$(CC) -c $(FLAGS) $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(addprefix $(OBJ_DIR)/, $(addsuffix .d, $(SRCS)))

.PHONY: all, clean, fclean, re