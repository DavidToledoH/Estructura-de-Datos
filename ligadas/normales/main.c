#include <stdio.h>
#include <stdlib.h>

struct lista{
 int dato;
 struct lista *sig;
};


struct lista*  eliminarEnN(struct lista* lista, int n){
 int i;
 n--;
 struct lista* temp;
 if(n==0){
  temp=lista->sig;
  free(lista);
  return temp;

 }else if (n==1){
  temp=lista->sig;
  lista->sig=temp->sig;
  free(temp);

 }else {
  struct lista* sig;	 
  for(i=1;i<n;i++){
   temp=temp->sig;
  }
  sig=temp->sig;
  temp->sig=sig->sig;
  free(sig);
 }
 return lista;
}

struct lista* eliminar(struct lista* lista){
 struct lista* temp;
 if(lista!=NULL){
  temp=lista;
  lista=lista->sig;
  free(temp);
 }
 return lista;
}

struct lista* agregar(struct lista* lista, int dato){
 struct lista* nuevo=(struct lista*)malloc(sizeof(struct lista));
 nuevo->dato=dato; 
 nuevo->sig=lista;
 lista=nuevo;
}

void mostrar(struct lista* lista){
 while(lista->sig!=NULL){
  printf("%d\n",lista->dato);
  lista=lista->sig;
 }
}

int main(){
 struct lista* L;
 L=(struct lista*)malloc(sizeof(struct lista));

 L= agregar (L,0);
 L= agregar (L,13);
 L= agregar (L,50);
 L= agregar (L,40);
 L= agregar (L,13);
 L= agregar (L,12);
 L= agregar (L,20);
 L= agregar (L,1);
 mostrar (L);
 printf("\n");
 L= eliminar(L);
 L= eliminar(L);
 mostrar (L);
 
 return 0;
}
