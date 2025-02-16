# Proyecto `libft.a` 📚

El proyecto **libft.a** consiste en la creación de una librería estática en C que emula parte de la funcionalidad de la librería estándar `libc`, además de incluir un conjunto de funciones adicionales que ayudan en la manipulación de cadenas, memoria y listas. El objetivo es ofrecer herramientas reutilizables para diversas aplicaciones en C, y la implementación se divide en dos partes:

1. **Parte Obligatoria**: Funciones fundamentales de la librería estándar `libc` que manejan cadenas y memoria.
2. **Parte Bonus**: Funciones más avanzadas para trabajar con listas, que requieren un mayor enfoque en la manipulación de estructuras de datos.

## Parte Obligatoria: Funciones de `libc` ⚙️

Estas funciones proporcionan herramientas básicas para trabajar con cadenas y memoria en C, ayudando a evitar la reescritura de código estándar.

- **`ft_strlen`**: Devuelve la longitud de una cadena.
- **`ft_memset`**: Rellena un bloque de memoria con un valor específico.
- **`ft_bzero`**: Rellena un área de memoria con ceros.
- **`ft_memcpy`**: Copia bloques de memoria de una ubicación a otra.
- **`ft_memmove`**: Mueve bloques de memoria de una ubicación a otra sin corrupción de datos.
- **`ft_strlcpy`**: Copia una cadena de caracteres de forma segura, previniendo desbordamientos.
- **`ft_strlcat`**: Concatena dos cadenas de caracteres de forma segura.
- **`ft_toupper`**: Convierte un carácter a su versión en mayúscula.
- **`ft_tolower`**: Convierte un carácter a su versión en minúscula.
- **`ft_strchr`**: Busca la primera aparición de un carácter en una cadena.
- **`ft_strrchr`**: Busca la última aparición de un carácter en una cadena.
- **`ft_strncmp`**: Compara dos cadenas hasta un número específico de caracteres.
- **`ft_memchr`**: Busca un byte en un bloque de memoria.
- **`ft_memcmp`**: Compara dos bloques de memoria.
- **`ft_strnstr`**: Busca una subcadena en una cadena.
- **`ft_atoi`**: Convierte una cadena de caracteres a un número entero.
- **`ft_calloc`**: Reserva memoria e inicializa a cero.
- **`ft_strdup`**: Duplica una cadena de caracteres.

## Parte Bonus: Funciones de Lista 🔗

Las funciones bonus están diseñadas para trabajar con listas enlazadas, una estructura de datos dinámica muy útil cuando necesitamos almacenar una colección de elementos sin un tamaño fijo. En esta parte, el foco está en la manipulación de nodos y la creación de funciones que gestionan listas enlazadas de manera eficiente.
## Estructura `t_list` 📝

La estructura `t_list` se utiliza para definir los nodos de una lista enlazada. Cada nodo contiene dos componentes:

- **`content`**: Un puntero a cualquier tipo de contenido que el nodo almacena.
- **`next`**: Un puntero al siguiente nodo en la lista. Si es `NULL`, significa que es el último nodo.

```c
typedef struct s_list {
    void *content;   // Contenido del nodo
    struct s_list *next;  // Puntero al siguiente nodo
} t_list;
```
### Explicación general de las funciones de lista:
Las funciones implementadas permiten crear, modificar, y eliminar nodos dentro de una lista enlazada, lo que ofrece una flexibilidad adicional frente a arrays estáticos. Cada nodo contiene un puntero a su contenido y otro puntero al siguiente nodo de la lista, lo que facilita la inserción y eliminación de elementos.

- **`ft_lstnew`**: Crea un nuevo nodo con un contenido determinado.
- **`ft_lstadd_front`**: Añade un nodo al principio de la lista, moviendo la cabeza de la lista.
- **`ft_lstsize`**: Devuelve el número de nodos en la lista.
- **`ft_lstlast`**: Devuelve el último nodo de la lista, útil para añadir nuevos nodos al final.
- **`ft_lstadd_back`**: Añade un nodo al final de la lista.
- **`ft_lstdelone`**: Elimina un nodo de la lista y libera su memoria.
- **`ft_lstclear`**: Elimina todos los nodos de la lista y libera la memoria asociada.
- **`ft_lstiter`**: Itera sobre todos los nodos y aplica una función a cada uno.
- **`ft_lstmap`**: Crea una nueva lista aplicando una función a cada nodo de la lista original.

# Explicación General del `Makefile` y Proceso de Compilación ⚙️

El `Makefile` es utilizado para automatizar el proceso de compilación del proyecto. Su objetivo principal es definir las reglas y dependencias que aseguran que los archivos fuente se compilen correctamente y se genere la librería estática `libft.a`.

### Objetivo del `Makefile`

El `Makefile` tiene varias reglas que:
1. **Compilan** los archivos fuente `.c` en archivos objeto `.o`.
2. **Generan** la librería estática `libft.a` usando el comando `ar` para combinar los archivos objeto `.o` en una sola librería.

### Proceso de Compilación

1. Los archivos `.c` se compilan a archivos objeto `.o` mediante el compilador de C.
2. Los archivos `.o` se agrupan en un archivo estático `libft.a` utilizando `ar`.

Esto se hace de forma eficiente gracias al uso del `Makefile`, que automatiza la compilación y optimiza el flujo de trabajo.

