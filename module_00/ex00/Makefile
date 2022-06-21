NAME = megaphone
CC = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = megaphone
OBJ_DIR = obj
SRC_FILE = $(addsuffix .cpp, $(SRCS))
OBJ_FILE = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRCS)))

all: $(NAME)

$(NAME): $(OBJ_FILE)
	$(CC) $(FLAGS) $(OBJ_FILE) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(@D)
	$(CC) -c $(FLAGS) $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re