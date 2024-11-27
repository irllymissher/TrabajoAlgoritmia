#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

// Agregar un nodo a la lista dinámica
void agregar_a_lista(tipo_de_persona* lista, rasgos_persona datos) {
    tipo_de_persona nuevo = (tipo_de_persona)malloc(sizeof(persona));
    if (nuevo == NULL) {
        fprintf(stderr, "[ERROR] No se pudo asignar memoria para el nodo.\n");
        return;
    }

    // Transferir datos desde rasgos_persona al nodo
    nuevo->datos_persona[0] = datos.age;
    nuevo->datos_persona[1] = datos.sex;
    nuevo->datos_persona[2] = datos.cp;
    nuevo->datos_persona[3] = datos.trtbps;
    nuevo->datos_persona[4] = datos.chol;
    nuevo->datos_persona[5] = datos.fbs;
    nuevo->datos_persona[6] = datos.restecg;
    nuevo->datos_persona[7] = datos.thalachh;
    nuevo->datos_persona[8] = datos.exng;
    nuevo->datos_persona[9] = datos.oldpeak;
    nuevo->datos_persona[10] = datos.slp;
    nuevo->datos_persona[11] = datos.caa;
    nuevo->datos_persona[12] = datos.thall;
    nuevo->datos_persona[13] = datos.output;

    nuevo->sig = *lista;
    *lista = nuevo;
}

// Liberar toda la memoria usada por la lista dinámica
void liberar_lista(tipo_de_persona* lista) {
    while (*lista != NULL) {
        tipo_de_persona temp = *lista;
        *lista = (*lista)->sig;
        free(temp);
    }
}

// Imprimir el contenido de la lista
void imprimir_lista(tipo_de_persona lista) {
    int i = 0;
    while (lista != NULL) {
        printf("Persona %d: Edad=%.0f, Sexo=%.0f, Colesterol=%.0f, Output=%.0f\n",
               i + 1,
               lista->datos_persona[0],
               lista->datos_persona[1],
               lista->datos_persona[4],
               lista->datos_persona[13]);
        lista = lista->sig;
        i++;
    }
}
