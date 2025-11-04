NAME := runner
SRC :=  $(wildcard *.c)
LIBFT_DIR := Libft/
LIBFT := libft.a
OBJ  := $(SRC:.c=.o)

RM := rm -f
CC := cc 
CFLAGS := -g3

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) -LLibft -lft -o $(NAME)

$(LIBFT):
	cd $(LIBFT_DIR); make;

# === CLEANING UP ===
clean:
	$(RM) $(OBJ) $(OBJ:.o=.d)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

# Run your program easily
run: $(NAME)
	./$(NAME)


