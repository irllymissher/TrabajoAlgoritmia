# Proyecto de Normalización de Datos: Heart Attack Prediction

Lo que he hecho hassta ahora es llegar a la dipositiva 9-10 (si no recuerdo mal) sobre normalizacion los datos. 
Se han puesto todos entre  [0 - 1].

## Archivos Incluidos

### 1. `persona.h`
Define las estructuras de datos y funciones asociadas para manejar listas enlazadas de personas.

- **Estructura `persona`**: Representa cada nodo de una lista enlazada que almacena los datos de una persona.
- **Estructura `rasgos_persona`**: Modela los atributos de una persona con campos como `age`, `chol`, `output`, etc.
- **Funciones principales**:
  - `agregar_a_lista`: Agrega un nodo a la lista enlazada.
  - `liberar_lista`: Libera toda la memoria usada por la lista enlazada.
  - `imprimir_lista`: Imprime los datos de la lista enlazada.

---

### 2. `persona.c`
Implementa las funciones declaradas en `persona.h`.

---

### 3. `normalizar.h`
Declara funciones para normalizar datos usando el cálculo de máximos y mínimos de cada atributo.

- **Funciones principales**:
  - `normalizarG`: Normaliza los datos de toda la lista o de una persona específica.
  - `normalizarT`: Aplica la normalización a toda la lista enlazada.
  - `maximo` y `minimo`: Calculan los valores máximos y mínimos de cada atributo en la lista.

---

### 4. `normalizar.c`
Implementa las funciones declaradas en `normalizar.h`.

---

### 5. `heart_sin_normalizar.c`
Contiene un programa principal que carga los datos desde `heart.csv`, normaliza los valores y almacena los resultados en una lista enlazada.
Realmente no lo usamos porque no hace hacer esto en otro archivo si no dentro del main o a lo mejor en un macro si nos apetece hacerlo.

---

### 6. `main_prueba.c`
Un programa de prueba diseñado para verificar si los datos están correctamente normalizados. Incluye:

- Carga de datos desde un archivo CSV.
- Normalización de datos.
- Verificación de que los valores estén en el rango [0, 1].

---

### 7. `leerTxt_no_necesario.c`
Un archivo que fue descartado porque no es necesario para este flujo. Originalmente iba a procesar datos intermedios, pero ahora trabajamos directamente sobre el archivo CSV.

---

## Flujo del Programa

1. **Carga de Datos**:
   - Los datos se cargan desde el archivo `heart.csv` en una lista enlazada utilizando `cargar_datos` en `persona.c`.

2. **Normalización**:
   - Se calcula el máximo y mínimo de cada atributo.
   - Los datos se normalizan para estar en el rango [0, 1].

3. **Verificación**:
   - Se comprueba que todos los valores normalizados estén en el rango correcto.
   - Si hay valores fuera del rango, se genera un error.

---

## Uso

### Compilación
Compila el programa principal con:
```bash
gcc -Wall main_prueba.c persona.c normalizar.c 
