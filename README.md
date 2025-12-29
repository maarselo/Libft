# Luxe Libft Project - My C Function Library

A static library that brings together essential functions for C projects, including reimplementations of standard `libc` functions, along with `get_next_line` and `ft_printf`.

## Project Structure

```bash
.
├── include/
│ ├── ft_printf.h
│ └── libft.h
├── src/
│ ├── libft/        #Standard Library Functions
│ ├── gnl/          #Get Next Line
│ └── ft_printf/    #Custom Printf
├── obj/            #Object Files (generated)
├── deps/           #Dependency Files (generated)
├── Makefile
└── README.md
```

## Libft Functions

### Character Verification Functions

- `ft_isalpha`: Checks if a `ft_isdigit`: Checks if a character is alphabetic (a-z, A-Z)
- `ft_isdigit`: Checks if a character is a digit (0-9)
- `ft_isalnum`: Checks if a character is alphanumeric
- `ft_isascii`: Checks if a character is in the ASCII range (0-127)
- `ft_isprint`: Checks if a character is printable
- `ft_isspace`: Checks if a character is a whitespace character
- `ft_ismetachar`: Checks if a character is a shell metacharacter

### Conversion Functions

- `ft_toupper`: Converts a character to uppercase
- `ft_tolower`: Converts a character to lowercase
- `ft_atoi`: Converts a string to an integer
- `ft_itoa`: Converts an integer to a string

### Functions of Memory Manipulation

- `ft_memset`: Fills a memory block with a specific byte
- `ft_bzero`: Sets a memory block to zero
- `ft_memcpy`: Copies n bytes of memory (without overlap)
- `ft_memmove`: Copies n bytes of memory (with safe overlap)
- `ft_memchr`: Searches for a byte in a memory block
- `ft_memcmp`: Compares two memory blocks
- `ft_calloc`: Allocates memory initialized to zero
- `ft_realloc`: Resizes a previously allocated memory block

### String Manipulation Functions
- `ft_strlen`: Calculates the length of a string
- `ft_strlcpy`: Copies a string safely (with a size limit)
- `ft_strlcat`: Concatenates strings Safely
- `ft_strchr`: Finds the first occurrence of a character
- `ft_strrchr`: Finds the last occurrence of a character
- `ft_strncmp`: Compares two strings up to n characters
- `ft_strnstr`: Searches for a substring within a string (with a limit)
- `ft_strdup`: Duplicates a string (allocates memory)
- `ft_substr`: Extracts a substring
- `ft_strjoin`: Concatenates two strings into a new one
- `ft_strtrim`: Removes specific characters from the beginning and end
- `ft_split`: Splits a string into an array using a delimiter
- `ft_strmapi`: Applies a function to each character (with an index)
- `ft_striteri`: Applies a function to each character (modifies in-place)
- `ft_multijoin`: Joins multiple strings into a single string

### Output Functions

- `ft_putchar_fd`: Writes a character to a file descriptor
- `ft_putstr_fd`: Writes a string to a file descriptor
- `ft_putendl_fd`: Writes a string followed by a newline character
- `ft_putnbr_fd`: Writes an integer to a file descriptor

## Get Next Line

### What is it?

`get_next_line` is a function that reads a line from a file descriptor, including the newline character (`\n`). It is especially useful for reading files line by line or standard input.

### Operation

```c
char *get_next_line(int fd);
```
- **Parameter**: `fd` - file descriptor to read from
- **Return**: The line read (including `\n`), or `NULL` if there is nothing more to read or an error occurs
- **Memory Management**: Each call returns a new line that must be freed by the user

### Features

- Reads from any file descriptor (files, stdin, sockets, etc.)
- Handles multiple file descriptors simultaneously
- Uses a static buffer to hold data between calls
- Detects the end of the file and handles read errors
- Buffer size configurable at compile time

### ### Use Cases

```c
int fd = open("archivo.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL) {
    printf("%s", line);
    free(line);
}
close(fd);
```


## Ft_printf

### What is it?

`ft_printf` is a reimplementation of the `printf` function from the C standard library, which formats and writes data to standard output.

### Prototype

```c
int ft_printf(const char *format, ...);
```

- **Parameter**: `format` - format string with specifiers
- **Return**: Number of characters printed, or -1 in case of error

### ### Supported Conversions

| Especificador | Descripción |
|---------------|-------------|
| `%c` | individual character |
| `%s` | String |
| `%p` | Hexadecimal pointer |
| `%d` | Signed decimal integer |
| `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x` | Lowercase hexadecimal |
| `%X` | Uppercase hexadecimal |
| `%%` | Literal character '%' |

### Example of Use

```c
ft_printf("Hello %s, you have %d years\n", "World", 42);
ft_printf("Address: %p\n", ptr);
ft_printf("Hexadecimal: %x\n", 255);
```

### Implementation

The function uses variable arguments (`stdarg.h`) to process different data types. It analyzes the format string character by character, identifying specifiers and delegating the conversion to specialized helper functions.


## Compilación

### Requisitos

- Compilador GCC o Clang
- Make

### Comandos del Makefile

```bash
make 		# Compiles the libft.a library
make clean  # Removes object files and dependencies
make fclean # Removes everything (including libft.a)
make re 	# Recompiles from zero (fclean + all)
```

### Compilation Process

1. **Directory Generation**: `obj/` and `deps/` are created automatically
2. **Source File Compilation**: Each `.c` file is compiled into a corresponding `.o` file
3. **Dependency Generation**: The `-MMD -MP` flag generates `.d` files that track header dependencies
4. **Library Creation**: `ar -rcs` packages all `.o` files into `libft.a`

### Flags de Compilación

- `-Wall -Werror -Wextra`: Activar advertencias y tratarlas como errores
- `-Iinclude`: Incluir el directorio de headers
- `-MMD -MP`: Generar archivos de dependencias automáticas


## Usage in Projects

### 1. Include the Library

Copy `libft.a` and the headers into your project:

```bash
cp libft.a /path/to/your/project/
cp include/*.h /path/to/your/project/
```

### 2. Compile with the Library

```bash
gcc main.c libft.a -o program
```

Or specifying the path:

```bash
gcc main.c -L. -lft -o program
```

### 3. Include Headers in your Code

```c
#include "libft.h"
int main() { 
	...
}
```

### 4. Integrate into your Makefile

```makefile
NAME = my_program
LIBFT = libft/libft.a
SRCS = main.c utils.c
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT): 
make -C libft

$(NAME): $(OBJS) 
gcc $(OBJS) $(LIBFT) -o $(NAME)

clean: 
rm -f $(OBJS) 
make -C libft clean

fclean: clean 
rm -f $(NAME) 
make -C libft fclean

re: fclean all
```

## Notes

- All functions are protected against `NULL` and invalid parameters
- Memory management is the user's responsibility (functions that allocate memory must be freed)
- Compatible with 42 School (norminette) projects
- Automatic dependency management prevents unnecessary recompilation
