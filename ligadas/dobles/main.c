#include<stdio.h>
#include<stdlib.h>
struct doble{
	int dato;
	struct doble* ant;
	struct doble* sig;
};
////////AGREGAR//////////////
struct doble* agregar(struct doble* lista ,int dato ){
	struct doble* nuevo = (struct doble*) malloc(sizeof(struct doble));
	if(lista==NULL){
		nuevo->ant=NULL;
		nuevo->sig=NULL;
		nuevo->dato=dato;
		return nuevo;
	}

	nuevo->ant=NULL;
	nuevo->dato=dato;	
	nuevo->sig=lista;
	lista->ant=nuevo;
	lista=nuevo;

	return lista;
}
////////ELIMINAR////////////
struct doble* eliminar(struct doble* lista){
	if(lista!=NULL){
		struct doble* temp;
		temp=lista;
		lista=lista->sig;
		lista->ant=NULL;
		free(temp);
	}
	return lista;
}
///////MOSTRAR////////////
void mostrar(struct doble* lista){
	while(lista->sig!=NULL){
		printf("%d\n",lista->dato);
		lista=lista->sig;
	}
}
////MOSTRAR INVERSO////
void mostrarInv(struct doble* lista){
	while (lista->sig->sig){
		lista=lista->sig;
	}
	while(lista){
		printf("%d\n",lista->dato);
		lista=lista->ant;
	}
}
int main(){
	struct doble* L;
	L=(struct doble*)malloc(sizeof(struct doble));
	int A = 150;
	for(int i = 0; i < 10000000; i++){
		if(i%2 == 0){
	
			L=agregar(L,-1*A*i);
		}else
		{
			L=agregar(L,A*i);
		}
		A++;
	}
	mostrar(L);
	printf("\n");
	mostrarInv(L);
	return 0;
}
