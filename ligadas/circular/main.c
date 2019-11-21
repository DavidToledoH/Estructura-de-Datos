#include <stdio.h>
#include <stdlib.h>

struct circ{
	int dato;
	struct circ* sig;
};

struct circ* agregar(struct circ* l, int dato){
	if(l==NULL){
		l=(struct circ*) malloc(sizeof(struct circ));
		if(l!=NULL){
			l->dato=dato;
			l->sig=l;
			return l;
		}else{
			return NULL;
		}
	}
	struct circ* nuevo=(struct circ*) malloc (sizeof(struct circ));
	if(nuevo!=NULL){
		struct circ *temp = l;
		while(temp->sig!=l){
			temp=temp->sig;
		}
		nuevo->dato=dato;
		nuevo->sig=l;
		temp->sig=nuevo;
		return nuevo;
	}else{
		return l;
	}
}

void mostrar(struct circ* l){
	if(l->sig==l){
		printf("%d\n",l->dato);
	}else{
		struct circ* temp=l;
		while(temp->sig!=l){
			printf("%d\n",temp->dato);
			temp=temp->sig;
		}
		printf("%d\n",temp->dato);
	}
}


struct circ* eliminar(struct circ* l) {
	if(l == NULL){
			printf("La lista está vacía");
			return l;
		}
		struct circ* temp = l;
		while(temp->sig !=l){
			temp=temp->sig;
		}
		temp->sig=l->sig,
		    free(l);
		return temp->sig;

}
int main(){
	struct circ* L= (struct circ*)malloc(sizeof(struct circ));
	L=agregar(L,10);
	L=agregar(L,50);
	L=agregar(L,20);
	mostrar(L);
	L=eliminar(L);
	mostrar(L);

	printf("Funciona\n" );
	return 0;
}
