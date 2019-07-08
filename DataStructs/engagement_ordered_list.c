#ifndef BASE_LIBS_H
#define BASE_LIBS_H
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#endif


#include "engagement_ordered_list.h"



/** \brief Metodo que inicializa a lista alocando endereço de memória
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
*/
PtNo_E* initializeEngagementList(PtNo_E *ptNo){
    ptNo = (PtNo_E *) malloc(sizeof(PtNo_E));
    return ptNo;
}

/* TODO  */
PtNo_E* selectEngagementList(PtNo_E *ptNo, char *content){
    if (ptNo != NULL){
        PtNo_E *aux = ptNo;

        while (aux != NULL){
            if (strcmp(aux->content, content) == 0){
                return aux;
            }
            aux = aux->next;
        }
    }
    return NULL;
}


/** \brief Método que insere elementos na LDE
 * \param *ptHashtag - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
 * \param *hashtag - string da hashtag que sera inserida na lista
 * \return Retorna lista com elementos inseridos
*/
PtNo_E* insertEngagementList(PtNo_E *ptNo, char *content, int mention, int likes, int rts){
    PtNo_E *Pt = ptNo;  //variavel auxiliar.
    PtNo_E *aux = NULL;
    PtNo_E *temp = NULL;

    if(ptNo == NULL)  //se a lista estiver vazia
    {
        Pt = (PtNo_E*) malloc(sizeof(PtNo_E));  // cria nova lista
        strcpy(Pt->content, content);       // copia o conteudo para o conteudo da lista
        Pt->engagement = (mention+rts+likes);                // com 1 ocorrencia
        Pt->prev = NULL;                    // sem anterior
        Pt->next = NULL;                    // e sem posteior
        ptNo = Pt;

        return ptNo;
    } else {
        Pt = (PtNo_E*) malloc(sizeof(PtNo_E));      // Novo item
        strcpy(Pt->content, content);
        Pt->engagement = (mention+rts+likes);
        aux = ptNo;
        while(aux->next != NULL) {               // Busca o fim
            aux = aux->next;
        }
        aux->next = Pt;                         // INSERE NO FIM
        Pt->prev = aux;
        Pt->next = NULL;

        // Agora atualiza a posicao do nodo.
        while(Pt->prev != NULL && (Pt->engagement > Pt->prev->engagement || (Pt->engagement == Pt->prev->engagement && strcasecmp(Pt->content, Pt->prev->content) < 0))) {
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



PtNo_E* sumEngagementsByContent(PtNo_E *ptNo, char *content, int likes, int rts){
    PtNo_E *Pt = selectEngagementList(ptNo, content);  //variavel auxiliar.
    PtNo_E *aux = NULL;
    PtNo_E *temp = NULL;
    if(Pt == NULL)  // Caso nao tenha sido encontrado o elemento na lista, insere-o
    {
        ptNo = insertEngagementList(ptNo, content, 0, likes, rts);
    }
    else            // Caso tenha o encontrado, aumenta a contagem e o realoca na lista
    {
        if (strcasecmp(Pt->content, content) == 0)
        {
            Pt->engagement += (likes + rts);
            while(Pt->prev != NULL && (Pt->engagement > Pt->prev->engagement || (Pt->engagement == Pt->prev->engagement && strcasecmp(Pt->content, Pt->prev->content) < 0)))
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



/* TODO */
PtNo_E* mentioned(PtNo_E *ptNo, char *content){
    PtNo_E *Pt = selectEngagementList(ptNo, content);  //variavel auxiliar.
    PtNo_E *aux = NULL;
    PtNo_E *temp = NULL;
    if(Pt == NULL)  // Caso nao tenha sido encontrado o elemento na lista, insere-o
    {
        ptNo = insertEngagementList(ptNo, content, 1, 0, 0);
    }
    else            // Caso tenha o encontrado, aumenta a contagem e o realoca na lista
    {
        if (strcasecmp(Pt->content, content) == 0)
        {
            Pt->engagement++;
            while(Pt->prev != NULL &&(Pt->engagement > Pt->prev->engagement || (Pt->engagement == Pt->prev->engagement && strcasecmp(Pt->content, Pt->prev->content) < 0)))
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


/* TODO */
PtNo_E* removeEngagementList(PtNo_E *ptNo, char *content){
  /* TODO */
  return NULL;
}

/** \brief Método que destroi a lista e libera endereços de memoria alocados para a LDE
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
 * \return Retorna um ponteiro para a lista com todos os laços destruidos e os elementos liberados da memória
*/
PtNo_E* destroyEngagementList(PtNo_E *ptNo){

}


/* Auxiliares */

/** \brief Método que exibe a lista
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
*/
void showEngagementList(PtNo_E *ptNo){
    PtNo_E *aux;
    aux = ptNo;

    printf("\n----- LISTA -----\n");
    /* Itera a lista, usando um ponteiro auxiliar, e exibe cada nó da lista */
    if (ptNo != NULL)            // Verifica se a lista é nula para evitar erros
    {
        while (aux != NULL)
        {
            printf("%s: %d\n", aux->content, aux->engagement);
            aux = aux->next;
        }
    }
    printf("----- FIM DA LISTA -----\n");

    getchar(); //Similar ao system("PAUSE");
}
