#include <stdio.h>
#include <stdlib.h>

//Criando struct para a lista. Info = dados / Prox = ponteiro para o prox elemento da lista
struct lista{
    int info;
    struct lista* prox;
};

//Define o tipo "Lista"
typedef struct lista Lista;


//Cria uma lista vazia, retorna NULL por estar vazia
Lista* lista_cria(void){
    return NULL;
}

//Insere elementos no inicio da lista
Lista* lista_insere(Lista* l, int i){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}

//Insere um dado v numa lista ordenada
Lista* lista_insere_ordenado(Lista* l, int v){
    Lista* p = l;
    Lista* ant = NULL;
    Lista* novo;

    while(p != NULL && p->info < v){
        ant = p;
        p = p->prox;
    }

    //Cria um novo elemento
    novo = (Lista*)malloc(sizeof(Lista));
    novo->info = v;

    //Se ant == NULL insere no inicio da lista
    if(ant == NULL){
        novo->prox = l;
        l = novo;
    }
    else{
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return l;
}


//Imprime todos os elementos da lista
Lista* lista_imprime(Lista* l){
    Lista* p;
    for(p = l; p != NULL; p = p->prox){
        printf("info = %d\n", p->info);
    }
}

//Imprime uma lista usando recursividade
Lista* lista_imprime_rec(Lista* l){
    if(lista_vazia(l)){
        return;
    }
    printf("info: %d\n", l->info);
    lista_imprime_rec(l->prox);
}

//Confere se a lista estiver vazia. Caso sim retorne 1, caso nao retorne 0
Lista* lista_vazia(Lista* l){
    if(l == NULL){
        return 1;
    }
    return 0;
}

//Busca um elemento V na lista, se encontrar retorna o ponteiro do no, se nao, retorna NULL
Lista* lista_busca(Lista* l, int v){
    Lista* p;
    for(p = l; p != NULL; p = p->prox){
        if(p->info == v){
            return p;
        }
    }
    return NULL;
}

//Remove um elemento "v" da lista
Lista* lista_remove(Lista* l, int v){
    //Ponteiro para percorrer a lista
    Lista* p;
    //Ponteiro para o no anterior
    Lista* ant = NULL;

    //Procura "v" na lista, guarda o elemento anterior
    while(p != NULL && p->info != v){
        ant = p;
        p = p->prox;
    }
    //Se nao encontrar retorna a lista sem alteracao
    if(p == NULL){
        return l;
    }
    //Se a condicao for satisfeita, o primeiro elemento deve ser retirado.
    if(ant == NULL){
        l = p->prox;
    }
    //Remove o elemento no meio da lista
    else{
        ant->prox = p->prox;
    }
    free(p);
    //Retorna a lista alterada
    return l;
}

//Remove um elemento "v" da lista usando recursividade
Lista* lista_remove_rec(Lista* l, int v){
    if(lista_vazia(l)){
        return l;
    }
    if(l->info == v){
        Lista* t = l;
        l = l->prox;
        free(t);
    }
    else{
        l->prox = lista_remove_rec(l->prox, v);
    }
    return l;
}

void lista_libera(Lista* l){
    //Deve ser 1 para entrar na funcao
    Lista* p = 1;
    while(p != NULL){
        //Guarda o valor de p
        Lista* t = p->prox;
        free(p);
        //p agora aponta para o proximo elemento
        p = t;
    }
}

void lista_libera_rec(Lista* l){
    if(lista_vazia(l)){
        return l;
    }
    else{
        lista_libera_rec(l->prox);
        free(l);
    }
}

int lista_igual(Lista* l1, Lista* l2){
    Lista* p1;
    Lista* p2;

    for(p1 = l1, p2 = l2; p1 != NULL && p2 != NULL; p1->prox, p2->prox){
        if(p1 -> info == p2 -> info){
            return 0;
        }
    }
    return p1==p2;
}
