#include<stdio.h>
#define MAX 5

typedef struct {
	char nome[40];
	int idade;
}tdado;

typedef struct{
	tdado fila[MAX];
	int inc, fim;
}tfila;

void inicializa(tfila *f){
	f->inc = 0;
	f->fim = -1;
}

int enqueue(tfila *f, tdado x){
	if(f->fim == MAX-1){//cheio
		return 0; //para função
	}
	//insere pq tem espaço
	f->fim ++;
	f->fila[f->fim] = x;
	return 1;
}

tdado dequeue(tfila *f){
	tdado aux = f->fila[f->inc];
	f->inc ++;
	return aux;
}

int isEmpty(tfila f){
	if(f.fim < f.inc)
		return 1;
	else
		return 0;
}

void mostra(tfila f){
	while(f.inc <= f.fim){
		printf("%s: %d |", f.fila[f.inc].nome, f.fila[f.inc].idade, "\n");
	}
}




