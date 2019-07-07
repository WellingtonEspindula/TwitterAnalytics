#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>

#ifndef ORDERED_LIST_H
#define ORDERED_LIST_H
#include "occurrence_ordered_list.h"
#endif

/** \brief Metodo que inicializa a lista alocando endereço de memória
 * \param *ptLista - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
*/
PtNo_O* initializeList(PtNo_O *ptNo){
  ptNo = (PtNo_O *) malloc(sizeof(PtNo_O));
  return ptNo;
}


PtNo_O* selectList(PtNo_O *ptNo, char *content){
  if (ptNo != NULL){
    PtNo_O *aux = ptNo;

    while (aux != NULL){
      if (strcmp(aux->content, content) == 0){
        return aux;
      }
      aux = aux->next;
    }
  }
  return NULL;
}

PtNo_O* insertList(PtNo_O *ptNo, char *content){
    PtNo_O *Pt = ptNo;  //variavel auxiliar.
    PtNo_O *aux = NULL;
    PtNo_O *temp = NULL;

    if(ptNo == NULL)  //se a lista estiver vazia
    {
        Pt = (PtNo_O*) malloc(sizeof(PtNo_O));  // cria nova lista
        strcpy(Pt->content, content);       // copia o conteudo para o conteudo da lista
        Pt->occurrences = 1;                // com 1 ocorrencia
        Pt->prev = NULL;                    // sem anterior
        Pt->next = NULL;                    // e sem posteior
        ptNo = Pt;

        return ptNo;
    } else {
        Pt = (PtNo_O*) malloc(sizeof(PtNo_O));      // Novo item
        strcpy(Pt->content, content);
        Pt->occurrences = 1;
        aux = ptNo;
        while(aux->next != NULL) {               // Busca o fim
            aux = aux->next;
        }
        aux->next = Pt;                         // INSERE NO FIM
        Pt->prev = aux;
        Pt->next = NULL;

        // Agora atualiza a posicao do nodo.
        while(Pt->prev != NULL && (Pt->occurrences > Pt->prev->occurrences || (Pt->occurrences == Pt->prev->occurrences && strcasecmp(Pt->content, Pt->prev->content) < 0))) {
            temp = Pt->prev->prev;
            if (Pt->prev->prev != NULL){
                Pt->prev->prev->next = Pt;
            }
            Pt->prev->prev = Pt;

            if(Pt->next != NULL){
                Pt->next->prev = Pt->prev;
            }
            Pt->prev->next = Pt->next;
            Pt->next = Pt->prev;
            Pt->prev = temp;
        }
        if(Pt->prev == NULL)
            ptNo = Pt;
    }

    return ptNo;
}



/** \brief Funcao que trata as ocorrencias de um texto na lista
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
 * \param *content - Texto que sera adicionado uma ocorrencia na lista
*/
PtNo_O* occurrence(PtNo_O *ptNo, char *content)
{
    PtNo_O *Pt = selectList(ptNo, content);  //variavel auxiliar.
    PtNo_O *aux = NULL;
    PtNo_O *temp = NULL;
    if(Pt == NULL)  // Caso nao tenha sido encontrado o elemento na lista, insere-o
    {
        ptNo = insertList(ptNo, content);
    }
    else            // Caso tenha o encontrado, aumenta a contagem e o realoca na lista
    {
        if (strcasecmp(Pt->content, content) == 0)
        {
            Pt->occurrences++;
            while(Pt->prev != NULL &&(Pt->occurrences > Pt->prev->occurrences || (Pt->occurrences == Pt->prev->occurrences && strcasecmp(Pt->content, Pt->prev->content) < 0)))
            {
                temp = Pt->prev->prev;
                if(Pt->prev->prev != NULL){
                    Pt->prev->prev->next = Pt;
                }
                Pt->prev->prev = Pt;

                if(Pt->next != NULL){
                    Pt->next->prev = Pt->prev;
                }
                Pt->prev->next = Pt->next;
                Pt->next = Pt->prev;
                Pt->prev = temp;
            }
            if(Pt->prev == NULL)
                ptNo = Pt;
        }
    }
    return ptNo;
}



PtNo_O* removeList(PtNo_O *ptNo, char *hashtag){
  /* TODO */
  return NULL;
}


/** \brief Método que destroi a lista e libera endereços de memoria alocados para a LDE
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
 * \return Retorna um ponteiro para a lista com todos os laços destruidos e os elementos liberados da memória
*/
PtNo_O* destroyList(PtNo_O *ptNo){
    if (ptNo != NULL)             // Verifica se a lista é nula para evitar erros
    {
        PtNo_O *aux1 = ptNo;   // auxiliar que recebe a primeira posição da lista
        PtNo_O *aux2;

        while (aux1 != NULL);        // enquanto não chegar ao fim da lista
        {
            aux2 = aux1;            // utiliza 2 auxiliares para guardar a informação da próxima posição e da posição atual da lista
            aux1 = aux1->next;
            free(aux2);             // e liberar a memória da posição atual
        }
    }

    return NULL;                    // retorna a lista como nula
}


/* Auxiliares */
void showList(PtNo_O *ptNo){
    PtNo_O *aux;
    aux = ptNo;

    printf("\n----- LISTA -----\n");
    /* Itera a lista, usando um ponteiro auxiliar, e exibe cada nó da lista */
    if (ptNo != NULL)            // Verifica se a lista é nula para evitar erros
    {
        while (aux != NULL)
        {
            printf("%s: %d\n", aux->content, aux->occurrences);
            aux = aux->next;
        }
    }
    printf("----- FIM DA LISTA -----\n");

    getchar(); //Similar ao system("PAUSE");
}

