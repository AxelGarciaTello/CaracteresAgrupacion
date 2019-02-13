/*
 * Instituto Politecnico Nacional
 * Escuela Superior de Cómputo
 * Estructura de datos
 * Grupo: 1CV8
 * Alumno: García Tello Axel
 * Profesor: Benjamín Luna Benoso
 * @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
 * Verificación de caracteres de agrupación
 * 
 * Fecha: 11 de febrero de 2019
*/

//Bibliotecas usadas
#include <stdio.h>
#include "funcionesPILA.h"

//Función principal
void verificarAgrupaciones(void){
	char car, error, comparacion;
	int linea=1;
	PILA datos;
	crearPila(&datos);
	//Abrir el archivo
	FILE *fp=fopen("ejem.txt","r");
	if(fp==NULL){
		printf("No se pudo cargar el archivo\n");
		return;
	}
	printf("Nombre del archivo: ejem.txt\n");
	//Leer el archivo hasta su finalización
	while((car=fgetc(fp))!=EOF){
		//Si es un salto te parrafo, registrarlo en el contador
		if(car=='\n'){
			linea++;
		}
		//Si es un signo de agrupación para abrir, guardarlo en la pila
		else if(car=='(' || car=='[' || car=='{' || car=='<'){
			insertarPila(&datos,car);
		}
		//Si es un signo de agrupación para cerrar...
		else if(car==')' || car==']' || car=='}' || car=='>'){
			//Si la pila esta vacia indiar que hace falta abrir
			if(pilaVacia(datos)){
				printf("Posible linea de error: %d\n",linea);
				switch(car){
					case ')': error='(';
					break;
					case ']': error='[';
					break;
					case '}': error='{';
					break;
					case '>': error='<';
					break;
				}
				printf("Posible error: Hace falta simbolo %c\n",error);
				fclose(fp);
				return;
			}
			else{
				comparacion=quitarPila(&datos);
				/*Si los caracter no corresponden, indicar que hace
				falta el caracter cerrar*/
				if(!((comparacion=='(' && car==')') ||
				(comparacion=='[' && car==']') ||
				(comparacion=='{' && car=='}') ||
				(comparacion=='<' && car=='>'))){
					printf("Posible linea de error %d\n",linea);
					switch(comparacion){
						case '(': error=')';
						break;
						case '[': error=']';
						break;
						case '{': error='}';
						break;
						case '<': error='>';
						break;
					}
					printf("Posible error: Hace falta simbolo %c\n",error);
					fclose(fp);
					return;
				}
			}
		}
	}
	/*Si la pila no esta vacia una vez terminado el archivo, entonces
	hace falta el carater de cierre*/
	if(!pilaVacia(datos)){
		comparacion=quitarPila(&datos);
		printf("Posible linea de error: %d\n", linea);
		switch(comparacion){
			case '(': error=')';
			break;
			case '[': error=']';
			break;
			case '{': error='}';
			break;
			case '<': error='>';
			break;
		}
		printf("Posible error: Hace falta simbolo %c\n",error);
		fclose(fp);
		return;
	}
	else {
		printf("Todo esta bien\n");
		fclose(fp);
		return;
	}
}

//Función main para ejecutar nuestra función principal
int main(void){
	verificarAgrupaciones();
	return 0;
}
