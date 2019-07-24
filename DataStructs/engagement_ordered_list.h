/*
    Autores: Ricco Soares e Wellington Espindula
    
    Descricao: A classe eh responsavel pelas operacoes relativa à lista 
    (Lista Duplamente Encadeada) de usuarios mais engajados, alem dos 
    cabeçalhos das funcoes basicas correspondentes a essa estrutura.

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


struct Engagement_LDE{
       int engagement;
       char content[280];
       struct Engagement_LDE* prev;
       struct Engagement_LDE* next;
       };
typedef struct Engagement_LDE PtNo_E;


/** \brief Metodo que inicializa a lista alocando endereço de memória
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
*/
PtNo_E* initializeEngagementList(PtNo_E *ptNo);

/** \brief Busca um elemento na lista e retorna um ponteiro para o mesmo
 * \param *ptNo - Ponteiro para a primeira posicao da LDE
 * \param *content - string que sera buscada na lista
 * \return Retorna o ponteiro para o elemento. Se nao encontrado, retorna NULL 
  */
PtNo_E* selectEngagementList(PtNo_E *ptNo, char *content);


/** \brief Método que insere elementos na LDE
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
 * \param *content - conteudo que sera inserido na lista
 * \param mention - numero de mencoes de um conteudo
 * \param likes - numero de likes de um conteudo
 * \param rts - numero de rts de um conteudo
 * \return Retorna lista com elementos inseridos
*/
PtNo_E* insertEngagementList(PtNo_E *ptNo, char *content, int mention, int likes, int rts);

/** \brief Busca se ja havia instancia do conteudo na LDE. 
 * Se sim, soma os likes e rts com o engagement anterior. 
 * Se nao, insere um novo conteudo com os likes e os rts entrados
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
 * \param *content - conteudo que sera buscado na lista
 * \param mention - numero de mencoes de um conteudo
 * \param likes - numero de likes de um conteudo
 * \param rts - numero de rts de um conteudo
 * \return Retorna lista com engajamentos atualizados
*/
PtNo_E* sumEngagementsByContent(PtNo_E *ptNo, char *content, int likes, int rts);

/** \brief Registra uma mencao de um conteudo na lista.
 * Busca se ja havia instancia do conteudo na LDE. 
 * Se sim, soma uma mencao com o engajamento anterior
 * Se nao, insere um novo conteudo com uma mencao (engajamento = 1)
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
 * \param *content - conteudo que sera buscado na lista
 * \return Retorna lista com engajamentos atualizados
*/
PtNo_E* mentioned(PtNo_E *ptNo, char *content);

/** \brief Método que destroi a lista e libera endereços de memoria alocados para a LDE
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
 * \return Retorna um ponteiro para a lista com todos os laços destruidos e os elementos liberados da memória
*/
PtNo_E* destroyEngagementList(PtNo_E *ptNo);


/* Auxiliares */

/** \brief Método que exibe a lista
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
*/
void showEngagementList(PtNo_E *ptNo);
