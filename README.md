# Luxe Libft Project - Mi Biblioteca de Funciones en C

Una biblioteca estática que reúne funciones esenciales para proyectos en C, incluyendo reimplementaciones de funciones estándar de `libc`, junto con `get_next_line` y `ft_printf`.

## 📚 Tabla de Contenidos

- [Estructura del Proyecto](#estructura-del-proyecto)
- [Funciones de Libft](#funciones-de-libft)
- [Get Next Line](#get-next-line)
- [ft_printf](#ft_printf)
- [Compilación](#compilación)
- [Uso en Proyectos](#uso-en-proyectos)

## 🗂️ Estructura del Proyecto

```
.
├── include/
│   ├── ft_printf.h
│   └── libft.h
├── src/
│   ├── libft/       # Funciones de la biblioteca estándar
│   ├── gnl/         # Get Next Line
│   └── ft_printf/   # Printf personalizado
├── obj/             # Archivos objeto (generado)
├── deps/            # Archivos de dependencias (generado)
├── Makefile
└── README.md
```


## 📖 Funciones de Libft

### Funciones de Verificación de Caracteres

- `ft_isalpha`: Verifica si un carácter es alfabético (a-z, A-Z) 
- `ft_isdigit` : Verifica si un carácter es un dígito (0-9) 
- `ft_isalnum` : Verifica si un carácter es alfanumérico 
- `ft_isascii` : Verifica si un carácter está en el rango ASCII (0-127) 
- `ft_isprint` : Verifica si un carácter es imprimible 
- `ft_isspace` : Verifica si un carácter es un espacio en blanco 
- `ft_ismetachar` : Verifica si un carácter es un metacarácter de shell 

### Funciones de Conversión

- `ft_toupper` : Convierte un carácter a mayúscula 
- `ft_tolower` : Convierte un carácter a minúscula
- `ft_atoi` : Convierte una cadena a entero 
- `ft_itoa` : Convierte un entero a cadena 

### Funciones de Manipulación de Memoria

- `ft_memset` : Llena un bloque de memoria con un byte específico 
- `ft_bzero` : Establece un bloque de memoria a cero 
- `ft_memcpy` : Copia n bytes de memoria (sin solapamiento) 
- `ft_memmove` : Copia n bytes de memoria (con solapamiento seguro) 
- `ft_memchr` : Busca un byte en un bloque de memoria 
- `ft_memcmp` : Compara dos bloques de memoria 
- `ft_calloc` : Reserva memoria inicializada a cero 
- `ft_realloc` : Redimensiona un bloque de memoria previamente reservado 

### Funciones de Manipulación de Cadenas
- `ft_strlen` : Calcula la longitud de una cadena 
- `ft_strlcpy` : Copia una cadena de forma segura (con límite de tamaño) 
- `ft_strlcat` : Concatena cadenas de forma segura 
- `ft_strchr` : Busca la primera ocurrencia de un carácter 
- `ft_strrchr` : Busca la última ocurrencia de un carácter 
- `ft_strncmp` : Compara dos cadenas hasta n caracteres 
- `ft_strnstr` : Busca una subcadena en una cadena (con límite) 
- `ft_strdup` : Duplica una cadena (reserva memoria) 
- `ft_substr` : Extrae una subcadena 
- `ft_strjoin` : Concatena dos cadenas en una nueva 
- `ft_strtrim` : Elimina caracteres específicos del inicio y final 
- `ft_split` : Divide una cadena en un array usando un delimitador 
- `ft_strmapi` : Aplica una función a cada carácter (con índice) 
- `ft_striteri` : Aplica una función a cada carácter (modifica in-place) 
- `ft_multijoin` : Une múltiples cadenas en una sola 

### Funciones de Salida

- `ft_putchar_fd` : Escribe un carácter en un file descriptor 
- `ft_putstr_fd` : Escribe una cadena en un file descriptor 
- `ft_putendl_fd` : Escribe una cadena seguida de nueva línea 
- `ft_putnbr_fd` : Escribe un número entero en un file descriptor 


## 📄 Get Next Line

### ¿Qué es?

`get_next_line` es una función que lee una línea de un file descriptor, incluyendo el carácter de nueva línea (`\n`). Es especialmente útil para leer archivos línea por línea o entrada estándar.

### Funcionamiento

```
char *get_next_line(int fd);
```

- **Parámetro**: `fd` - file descriptor del cual leer
- **Retorno**: La línea leída (incluyendo `\n`), o `NULL` si no hay más que leer o hay error
- **Gestión de memoria**: Cada llamada devuelve una nueva línea que debe ser liberada por el usuario

### Características

- Lee de cualquier file descriptor (archivos, stdin, sockets, etc.)
- Gestiona múltiples file descriptors simultáneamente
- Utiliza un buffer estático para mantener datos entre llamadas
- Detecta el final del archivo y gestiona errores de lectura
- Buffer size configurable en tiempo de compilación

### Casos de Uso

```c
int fd = open("archivo.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

---

## 🖨️ ft_printf

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

---

## 🔨 Compilación

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

---

## 🚀 Uso en Proyectos

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
#include "ft_printf.h"

int main(void)
{
    char *line;
    int fd;
    
    // Usar ft_printf
    ft_printf("Hola Mundo!\n");
    
    // Usar get_next_line
    fd = open("test.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        ft_printf("%s", line);
        free(line);
    }
    close(fd);
    
    // Usar funciones de libft
    char *str = ft_strdup("42 Barcelona");
    ft_printf("Longitud: %d\n", ft_strlen(str));
    free(str);
    
    return (0);
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

---

## 📝 Notas

- Todas las funciones están protegidas contra `NULL` y parámetros inválidos
- La gestión de memoria es responsabilidad del usuario (funciones que asignan memoria deben ser liberadas)
- Compatible con proyectos de 42 School (norminette)
- Sistema de dependencias automáticas evita recompilaciones innecesarias

---

## 👤 Autor

**mvillavi** - 42 Barcelona

---

## 📜 Licencia

Este proyecto es de código abierto y está disponible para uso educativo.
