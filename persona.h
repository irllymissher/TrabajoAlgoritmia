#ifndef PERSONA_H
#define PERSONA_H

#include <stdlib.h>  // Para malloc y free

// Estructura para listas dinámicas de personas
typedef struct pers {
    float datos_persona[24];
    struct pers* sig;
} persona;
typedef persona* tipo_de_persona;

// Estructura para datos estáticos de personas
typedef struct {
    int age;
    int sex;
    int cp;
    int trtbps;
    int chol;
    int fbs;
    int restecg;
    int thalachh;
    int exng;
    float oldpeak;
    int slp;
    int caa;
    int thall;
    int output;
} rasgos_persona;

// Funciones públicas
void agregar_a_lista(tipo_de_persona* lista, rasgos_persona datos);
void liberar_lista(tipo_de_persona* lista);
void imprimir_lista(tipo_de_persona lista);

#endif /* PERSONA_H */
