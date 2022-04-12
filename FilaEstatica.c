#include<stdio.h>
#define MAX 5

typedef struct {
	char nome[40];
	int idade;
}tdado;

typedef struct{
	tdado fila[MAX];
	int inc, fim, qtd;
}tfila;

void inicializa(tfila *f){
	f->inc = 0;
	f->fim = -1;
	f->qtd = 0;
}

int enqueue(tfila *f, tdado x){//enfileirar
	if(f->qtd == MAX){//cheio
		return 0; //fila cheia
	}
	if(f->fim == MAX-1){
		f->fim = 0;
	} else {
		//insere pq tem espaço
		f->fim ++;
		f->fila[f->fim] = x;
		f->qtd++;
		return 1;
	}

}

tdado dequeue(tfila *f){//desinfileirar
	tdado aux = f->fila[f->inc];
	if(f->inc == MAX-1){
		f->inc = 0;
	} else {
		f->inc++;
	}
	f->qtd--;
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
		printf("%s: %d | ", f.fila[f.inc].nome, f.fila[f.inc].idade, "\n");
		f.inc ++;
	}
}

int menu(){
	int op;
	printf("*** Estrutura de Dados I - Fila Estatica ****\n");
	printf("1 - Enqueue (Inserir)\n");
	printf("2 - Dequeue  (Remover)\n");
	printf("3 - Mostrar pilha\n");
	printf("0-Sair\n");
	scanf("%d",&op);
	return op;
}

int main(){
	tfila f1;
	tdado x;
	int op;
	inicializa(&f1);
	do{
		op = menu();
		switch(op){
			
			case 1:
				printf("Entre com o nome e idade: ");
				fflush(stdin);
				gets(x.nome);
				scanf("%d", &x.idade);
				if(enqueue(&f1, x) == 1){
					printf("Dado inserido!\n");
				} else {
					printf("Vagas esgotadas :(\n");
				}
			break;
			
			case 2:
				if(isEmpty(f1) != 1){
					x = dequeue(&f1);
					printf("dado removido: %s | %d", x.nome, x.idade);
				} else {
					printf("Lista vazia! Impossivel remover!");
				}
			break;
			
			case 3:
				mostra(f1);
			break;
			
			case 0:
				printf("Saindo...\n");
			break;
		}
		getch();
		system("cls");	
	}while(op != 0);
}


