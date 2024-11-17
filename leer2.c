#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *file = fopen("heart.csv", "r");
    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    char linea[125]; 
    fgets(linea, sizeof(linea), file);
    int lineaActual = 0;

    while (fgets(linea, sizeof(linea), file)) {
        lineaActual++;

        char *token = strtok(linea, ",");
        int columna = 0;

        while (token != NULL) {
            printf("%s ", token);
            token = strtok(NULL, ",");
            columna++;
        }
        printf("\n");
    }

    fclose(file);
    return 0;
}
