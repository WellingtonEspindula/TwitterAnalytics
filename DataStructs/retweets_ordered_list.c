/*
    Autores: Ricco Soares e Wellington Espindula

*/

#include "retweets_ordered_list.h"

PtNo_R* initializeRetweetsList(PtNo_R *ptNo){
  ptNo = (PtNo_R *) malloc(sizeof(PtNo_R));
  return ptNo;
}


PtNo_R* selectRetweetsList(PtNo_R *ptNo, char *content){
  if (ptNo != NULL){
    PtNo_R *aux = ptNo;

    while (aux != NULL){
      if (strcmp(aux->content, content) == 0){
        return aux;
      }
      aux = aux->next;
    }
  }
  return NULL;
}

PtNo_R* insertRetweetsList(PtNo_R *ptNo, char *content, int rts){
    PtNo_R *Pt = ptNo;  //variavel auxiliar.
    PtNo_R *aux = NULL;
    PtNo_R *temp = NULL;

    if(ptNo == NULL)  //se a lista estiver vazia
    {
        Pt = (PtNo_R*) malloc(sizeof(PtNo_R));  // cria nova lista
        strcpy(Pt->content, content);       // copia o conteudo para o conteudo da lista
        Pt->retwittes = rts;                // com 1 ocorrencia
        Pt->prev = NULL;                    // sem anterior
        Pt->next = NULL;                    // e sem posteior
        ptNo = Pt;

        return ptNo;
    } else {
        Pt = (PtNo_R*) malloc(sizeof(PtNo_R));      // Novo item
        strcpy(Pt->content, content);
        Pt->retwittes = rts;
        aux = ptNo;
        while(aux->next != NULL) {               // Busca o fim
            aux = aux->next;
        }
        aux->next = Pt;                         // INSERE NO FIM
        Pt->prev = aux;
        Pt->next = NULL;

        // Agora atualiza a posicao do nodo.
        while(Pt->prev != NULL && (Pt->retwittes > Pt->prev->retwittes || (Pt->retwittes == Pt->prev->retwittes && strcasecmp(Pt->content, Pt->prev->content) < 0))) {
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

PtNo_R* sumRetweetsByContent(PtNo_R *ptNo, char *content, int rts){
    PtNo_R *Pt = selectRetweetsList(ptNo, content);  //variavel auxiliar.
    PtNo_R *aux = NULL;
    PtNo_R *temp = NULL;
    if(Pt == NULL)  // Caso nao tenha sido encontrado o elemento na lista, insere-o
    {
        ptNo = insertRetweetsList(ptNo, content, rts);
    }
    else            // Caso tenha o encontrado, aumenta a contagem e o realoca na lista
    {
        if (strcasecmp(Pt->content, content) == 0)
        {
            Pt->retwittes += rts;
            while(Pt->prev != NULL && (Pt->retwittes > Pt->prev->retwittes || (Pt->retwittes == Pt->prev->retwittes && strcasecmp(Pt->content, Pt->prev->content) < 0)))
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

PtNo_R* removeRetweetsList(PtNo_R *ptNo, char *hashtag){
  /* TODO */
  return NULL;
}

PtNo_R* destroyRetweetsList(PtNo_R *ptNo){
    if (ptNo != NULL)             // Verifica se a lista é nula para evitar erros
    {
        PtNo_R *aux1 = ptNo;   // auxiliar que recebe a primeira posição da lista
        PtNo_R *aux2;

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
void showRetweetsList(PtNo_R *ptNo){
    PtNo_R *aux;
    aux = ptNo;

    printf("\n----- LISTA -----\n");
    /* Itera a lista, usando um ponteiro auxiliar, e exibe cada nó da lista */
    if (ptNo != NULL)            // Verifica se a lista é nula para evitar erros
    {
        while (aux != NULL)
        {
            printf("%s: %d\n", aux->content, aux->retwittes);
            aux = aux->next;
        }
    }
    printf("----- FIM DA LISTA -----\n");

    getchar(); //Similar ao system("PAUSE");
}

