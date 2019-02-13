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

#include<stdio.h>
#include<stdlib.h>
#define TAM 50

//Creación de la estructura pila
struct pila{
	int listaPila[TAM];
	int cima;
};

//Renombreramiento de las palabras reservadas
typedef struct pila PILA;
typedef char tipoDato;

//Funciones de pila.c
void crearPila(PILA *stack);
tipoDato pilaLlena(PILA stack);
tipoDato pilaVacia(PILA stack);
void insertarPila(PILA *stack, int x);
tipoDato quitarPila(PILA *stack);
tipoDato cimaPila(PILA stack);
void eliminarPila(PILA *stack);
