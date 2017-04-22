CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
SRC = main.c strings_compare.c string_to_integer.c find_ex.c get_path.c print_number.c print_char.c concat_strings.c str_ncomp.c str_len.c libshell.a
OBJ = main

all: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OBJ)

clean:
	rm $(OBJ)

	/* Makefile shall not relink */
