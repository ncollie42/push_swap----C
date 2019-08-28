CC = gcc
FILES = main.c \
stack.c \
functions.c
NAME = checker
LIB = -L $(LIBRARY_PATH)/standard -I $(LIBRARY_PATH)/standard -lstandard

all: $(NAME)

$(NAME): $(FILES)
	$(CC) $(FILES) $(LIB) -o $@

g: $(FILES)
	$(CC) -g $(FILES) $(LIB) -o $@ 
f:  $(FILES)
	$(CC) -fsanitize=address $(FILES) $(LIB) -o $@ 
clean:
	rm $(NAME)

re: clean all