#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char site[40];
	char data [40];
}tdado;

typedef struct no{
	tdado dado;
	struct no*prox;
}tno;

typedef struct{
	tno*topo;
}tpilha;

void inicializa(tpilha *p){
	p->topo = NULL;
}

int push(tpilha *p, tdado x){
	tno *novo;
	novo = malloc(sizeof(tno));
	if(novo == NULL){ // erro ao alocar
		return 0;
	}
	novo->prox = p->topo;
	novo->dado = x;
	p->topo = novo;
	return 1;
}

tdado pop(tpilha *p){
	tno *aux;
	aux = p->topo;
	p->topo = p->topo->prox;
	tdado x = aux->dado;
	free(aux);
	return x;
}

int isEmpty(tpilha p){
	return p.topo == NULL?1:0;
}

void mostraPilha(){
	while(p.topo != NULL){
		printf("%s | %s ->", p.topo->dado.site, p.topo->dado.data);
		p.topo = p.topo->prox;
	}
	printf("\n");
}

int menu(){
	int op;
	printf("*** Estrutura de Dados I - Fila Estatica ****\n");
	printf("1 - Push (Inserir)\n");
	printf("2 - Pop  (Remover)\n");
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

