/*
    Autores: Ricco Soares e Wellington Espindula
    
    Descricao: Nesse arquivo foi definida uma estrutura do tipo 
    Lista Duplamente Encadeada que serve de base para todas as 
    funções implementadas em LDE que possuem tratamento conforme
    o numero de retwittes, como os influenciados e twittes mais retwittados.

 */

#ifndef BASE_LIBS_H
#define BASE_LIBS_H
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <strings.h>
#endif

struct Retweets_LDE{
       int retwittes;
       char content[280];
       struct Retweets_LDE* prev;
       struct Retweets_LDE* next;
       };
typedef struct Retweets_LDE PtNo_R;


/** \brief Metodo que inicializa a lista alocando endereço de memória
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
*/
PtNo_R* initializeRetweetList(PtNo_R *ptNo);

/** \brief Busca um elemento na lista e retorna um ponteiro para o mesmo
 * \param *ptNo - Ponteiro para a primeira posicao da LDE
 * \param *content - string que sera buscada na lista
 * \return Retorna o ponteiro para o elemento. Se nao encontrado, retorna NULL 
  */
PtNo_R* selectRetweetsList(PtNo_R *ptNo, char *content);


/** \brief Método que insere elementos na LDE
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
 * \param *content - string da conteudo que sera inserido na lista
 * \param rts - inteiro que indica quantos retwittes tem um conteudo
 * \return Retorna lista com elementos inseridos
*/
PtNo_R* insertRetweetsList(PtNo_R *ptNo, char *content, int rts);

/** \brief Trata a ocorrencia de um conteudo na lista.
 * Busca o conteudo, se achou soma os retwittes anteriores com os entrados.
 * Se nao encontrou o conteudo, o insere na lista com o numero de retwittes entrados.
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
 * \param *content - string da conteudo que sera inserido na lista
 * \param rts - inteiro que indica quantos retwittes tem um conteudo
 * \return Retorna lista atualizada com o novo elemento inserido ou com update no numero de rts
 */
PtNo_R* sumRetweetsByContent(PtNo_R *ptNo, char *content, int rts);

/** \brief Remove um conteudo da lista
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
 * \param *content - conteudo que sera removido da lista
 * \return Retorna lista com o elemento removido
 */
PtNo_R* removeRetweetsList(PtNo_R *ptNo, char *content);

/** \brief Método que destroi a lista e libera endereços de memoria alocados para a LDE
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
 * \return Retorna um ponteiro para a lista com todos os laços destruidos e os elementos liberados da memória
*/
PtNo_R* destroyRetweetsList(PtNo_R *ptNo);


/* Auxiliares */

/** \brief Método que exibe a lista
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
*/
void showRetweetsList(PtNo_R *ptNo);
