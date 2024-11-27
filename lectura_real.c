#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"

int main(void) {
    FILE *file = fopen("heart.csv", "r");
    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        return EXIT_FAILURE;
    }

    char linea[125];
    fgets(linea, sizeof(linea), file); // Leer encabezado (descartado en este caso)
    int lineaActual = 0;

    tipo_de_persona lista_personas = NULL;

    while (fgets(linea, sizeof(linea), file)) {
        lineaActual++;
        rasgos_persona persona_temp;

        // Leer y procesar cada campo
        sscanf(linea, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%f,%d,%d,%d,%d",
               &persona_temp.age,
               &persona_temp.sex,
               &persona_temp.cp,
               &persona_temp.trtbps,
               &persona_temp.chol,
               &persona_temp.fbs,
               &persona_temp.restecg,
               &persona_temp.thalachh,
               &persona_temp.exng,
               &persona_temp.oldpeak,
               &persona_temp.slp,
               &persona_temp.caa,
               &persona_temp.thall,
               &persona_temp.output);

        // Agregar a la lista dinámica
        agregar_a_lista(&lista_personas, persona_temp);

        // Imprimir cada línea procesada
        char *token = strtok(linea, ",");
        int columna = 0;

        printf("Línea %d: ", lineaActual);
        while (token != NULL) {
            printf("Columna %d: %s ", columna, token);
            token = strtok(NULL, ",");
            columna++;
        }
        printf("\n");
    }

    fclose(file);

    // Imprimir lista procesada
    printf("\nDatos almacenados en la lista:\n");
    imprimir_lista(lista_personas);

    // Liberar memoria
    liberar_lista(&lista_personas);

    return EXIT_SUCCESS;
}
