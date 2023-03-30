#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct cel
{
    cel *prox;
    int conteudo;
}celula ;

celula *separar (celula *start,celula *end,celula *cabeca_pivo,celula *novo_fim){ 

    celula *aux=cabeca;
    celula *pivo=end;
    celula *ant=NULL;
    celula *tail=pivo;


while(aux!=pivo){ 
    if(aux->conteudo<pivo->conteudo){
        if(*cabeca_pivo==NULL){
            *cabeca_pivo=aux;

        }
        ant=aux;
        aux=aux->prox;
    }else{
        if(ant){
            ant->prox=aux->prox;
        }
        celula *temporaria=aux->prox;
        aux->prox=NULL;
        tail->prox=aux;
        tail=aux;
        aux=temporaria;


        }

    } 
    if((*cabeca_pivo)==NULL){
*cabeca_pivo=pivo;
    }
    *novo_fim=tail;

    return pivo;



}

celula *quicksort(){
if(cabeca==end){
    return cabeca;
}

celula *novacabeca=NULL;
celula *novofim=NULL;

celula *pivo=separar(cabeca,end,&novacabca,&novofim);

if(novacabeca!=pivo){
    celula *temporaria=novacabeca;
    while(temporaria->prox !=pivo){
        temporaria=temporaria->prox;
    }
    temporaria->prox=NULL;
novacabeca=quicksort(novacabeca,temporaria);

temporaria=end;
end=pivo;
pivo->prox=quicksort(pivo->prox,temporaria);
}else{
    novacabeca=quicksort(novacabeca,pivo->prox);
    pivo->prox=quicksort(pivo->prox,novofim);

}
return novacabeca;

}








int main(){
    return 0;
}