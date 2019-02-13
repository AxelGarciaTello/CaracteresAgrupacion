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

#include "funcionesPILA.h"

//Función para crear una pila
void crearPila(PILA *stack){
	stack->cima = -1;
}

//Función para saber si una pila esta llena
tipoDato pilaLlena(PILA stack){
	if(stack.cima== TAM-1){
		return 1;
	}else{
		return 0;
	}
}

//Función para saber si una pila esta vacia
tipoDato pilaVacia(PILA stack){
	if(stack.cima == -1){
		return 1;
	}else{
		return 0;
	}
}

//Función para insertar datos en una pila
void insertarPila(PILA *stack, int x){
	if(pilaLlena(*stack)){
		printf("Error al intentar insertar, la pila esta llena. \n");
		exit(-1);
	}
	stack->cima = stack->cima + 1;
	stack->listaPila[stack->cima] = x;
}

//Función para quitar datos en una pila
tipoDato quitarPila(PILA *stack){
	if(pilaVacia(*stack)==1){
		printf("Error al quitar valores, la pila esta vacia. \n");
		exit(-1);
	}
	int aux = stack->listaPila[stack->cima];
		stack->cima = stack->cima - 1;	
	return aux;
}

//Función para obtener el dato superior de la pila
tipoDato cimaPila(PILA stack){
	if(pilaVacia(stack)){
		printf("La pila esta vacia");
		exit(-1);
	}
	return stack.listaPila[stack.cima];
}

//Función para eliminar pila
void eliminarPila(PILA *stack){
	stack->cima = -1;
}
