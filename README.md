# Luxe Libft Project - My C Function Library

A static library that brings together essential functions for C projects, including reimplementations of standard `libc` functions, along with `get_next_line` and `ft_printf`.

## Project Structure

```c
.
├── include/
│ ├── ft_printf.h
│ └── libft.h
├── src/
│ ├── libft/        # Standard Library Functions
│ ├── gnl/          # Get Next Line
│ └── ft_printf/    # Custom Printf
├── obj/            # Object Files (generated)
├── deps/           # Dependency Files (generated)
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

### Casos de Uso

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

### ¿Qué es?

`ft_printf` es una reimplementación de la función `printf` de la biblioteca estándar de C, que formatea y escribe datos en la salida estándar.

### Prototipo

```c
int ft_printf(const char *format, ...);
```

- **Parámetro**: `format` - cadena de formato con especificadores
- **Retorno**: Número de caracteres impresos, o -1 en caso de error

### Conversiones Soportadas

| Especificador | Descripción |
|---------------|-------------|
| `%c` | Carácter individual |
| `%s` | Cadena de caracteres |
| `%p` | Puntero en formato hexadecimal |
| `%d` | Entero decimal con signo |
| `%i` | Entero decimal con signo |
| `%u` | Entero decimal sin signo |
| `%x` | Hexadecimal en minúsculas |
| `%X` | Hexadecimal en mayúsculas |
| `%%` | Carácter literal '%' |

### Ejemplo de Uso

```c
ft_printf("Hola %s, tienes %d años\n", "mundo", 42);
ft_printf("Dirección: %p\n", ptr);
ft_printf("Hexadecimal: %x\n", 255);
```

### Implementación

La función utiliza argumentos variables (`stdarg.h`) para procesar diferentes tipos de datos. Analiza la cadena de formato carácter por carácter, identificando especificadores y delegando la conversión a funciones auxiliares especializadas.


## Compilación

### Requisitos

- Compilador GCC o Clang
- Make

### Comandos del Makefile

```bash
make          # Compila la biblioteca libft.a
make clean    # Elimina archivos objeto y dependencias
make fclean   # Elimina todo (incluido libft.a)
make re       # Recompila desde cero (fclean + all)
```

### Proceso de Compilación

1. **Generación de directorios**: Se crean `obj/` y `deps/` automáticamente
2. **Compilación de archivos fuente**: Cada `.c` se compila en un `.o` correspondiente
3. **Generación de dependencias**: Flag `-MMD -MP` genera archivos `.d` que rastrean dependencias de headers
4. **Creación de biblioteca**: `ar -rcs` empaqueta todos los `.o` en `libft.a`

### Flags de Compilación

- `-Wall -Werror -Wextra`: Activar advertencias y tratarlas como errores
- `-Iinclude`: Incluir el directorio de headers
- `-MMD -MP`: Generar archivos de dependencias automáticas


## Uso en Proyectos

### 1. Incluir la Biblioteca

Copia `libft.a` y los headers a tu proyecto:

```bash
cp libft.a /ruta/a/tu/proyecto/
cp include/*.h /ruta/a/tu/proyecto/
```

### 2. Compilar con la Biblioteca

```bash
gcc main.c libft.a -o programa
```

O especificando la ruta:

```bash
gcc main.c -L. -lft -o programa
```

### 3. Incluir Headers en tu Código

```c
#include "libft.h"

int main() {
	...
}
```

### 4. Integrar en tu Makefile

```makefile
NAME = mi_programa
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

## Notas

- Todas las funciones están protegidas contra `NULL` y parámetros inválidos
- La gestión de memoria es responsabilidad del usuario (funciones que asignan memoria deben ser liberadas)
- Compatible con proyectos de 42 School (norminette)
- Sistema de dependencias automáticas evita recompilaciones innecesarias
