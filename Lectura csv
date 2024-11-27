#include <stdio.h>
#include <stdlib.h>
#include <errno.h>   // Para manejar errores y usar errno
#include <string.h>  // Para usar strerror

int main(void){
	char linea[350];
	FILE *lectura = fopen("heart.csv", "r");

	if (lectura == NULL) {
        fprintf(stderr, "[ERROR] no se ha podido abrir el archivo de entrada 'heart.csv': %s\n", strerror(errno));
        return EXIT_FAILURE; // Salir con error
    }

	FILE *escritura = fopen("heart_sin_normalizar.txt", "w");

	if (escritura == NULL) {
        fprintf(stderr, "[ERROR] no se ha podido crear el archivo de salida 'heart_sin_normaliz.txt': %s\n", strerror(errno));
        fclose(lectura); // Cerrar el archivo de lectura antes de salir
        return EXIT_FAILURE;
    }

	//Leo con fgets todas las lineas del csv.
	while (fgets(linea, sizeof(linea), lectura)) {
		//En caso de que lleguemos al final de ficheor y hallamos tenido algun problema.
        if (fputs(linea, escritura) == EOF) {
            fprintf(stderr, "[ERROR] no se ha podido escribir en el archivo de salida: %s\n", strerror(errno));

			//Cerramos en caso de fugas. (manias.)
            fclose(lectura);
            fclose(escritura);
            return EXIT_FAILURE;
        }
    }

	// No es necesario, no tenemos caracteristicas especiales ni cadenas de caracteres que tengamos que parsear para distinguirlas

	// while (fgets(linea, 350, lectura)){
	// 	int posComa = 0, lenUltComa = 0;
	// 	for (int i = 0; i < 350; i++){
	// 		if (linea[i] == ','){
	// 			posComa++;
	// 			if (posComa == 1 ||  posComa == 23 || posComa == 24){
	// 				int j;
	// 				for (j = i - lenUltComa; j <= i; j++){
	// 					linea[j] = '@';
	// 				}
	// 				if (posComa == 24){ linea[j-1] = ',';}
	// 			}
	// 			lenUltComa = 0;
	// 		}
	// 		lenUltComa++;
	// 	}
	// 	int posMod = 0;
 //
	// 	char lineaMod[350];
	// 	for (int i = 0; i < 350; i++){
	// 		if (linea[i] != '@'){
	// 			if (linea[i] == '/'){
	// 				lineaMod[posMod] = ',';
	// 			}
	// 			else{
	// 				lineaMod[posMod] = linea[i];
	// 			}
	// 			posMod++;
	// 		}
	// 	}
	// 	fputs(lineaMod, escritura);
	// }
	fclose(lectura);
	fclose(escritura);
	return 0;
}

/**
 * [CHANGELOG]:
 * 27/11/24:
 * 		Decido cambiar la estructura de lectura y la manera en la que eran leidos
 * 		los datos. Este nuevo CSV tiene enteros de manera que en ciertas categorias
 * 		tenemos 0 y 1 para distinguir, por ejemplo, si es hombre o mujer.
 *
 * 		Decido manejar los errores de manera más especifica en caso de fallo para
 * 		poder saber en que caso he fallado. Manera de debugiar barata.
 * 
 * 		Añado liberias para el uso correcto de los errores.
 */
