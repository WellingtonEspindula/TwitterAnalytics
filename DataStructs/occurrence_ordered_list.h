/*
    Autores: Ricco Soares e Wellington Espindula
    
    Descricao: Nesse arquivo foi definida uma estrutura do tipo 
    Lista Duplamente Encadeada que serve de base para todas as 
    funções implementadas em LDE que possuem tratamento conforme
    a ocorrência dos nodos ao longo dos tweets, a exemplo das menções, 
    hashtags e usuários que realizaram tweets.

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


struct Occurrence_LDE{
       int occurrences;
       char content[280];
       struct Occurrence_LDE* prev;
       struct Occurrence_LDE* next;
       };
typedef struct Occurrence_LDE PtNo_O;


/** \brief Metodo que inicializa a lista alocando endereço de memória
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
*/
PtNo_O* initializeList(PtNo_O *ptNo);

/** \brief Funcao que trata as ocorrencias de um texto na lista.
 * Se elemento ja existia no texto, registra a ocorrencia.
 * Se nao, insere-o na lista
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
 * \param *content - Texto que sera adicionado uma ocorrencia na lista
 * \return Retorna ponteiro para a lista com elementos atualizados.
*/
PtNo_O* occurrence(PtNo_O *ptNo, char *content);

/** \brief Busca um elemento na lista e retorna um ponteiro para o mesmo
 * \param *ptNo - Ponteiro para a primeira posicao da LDE
 * \param *content - string que sera buscada na lista
 * \return Retorna o ponteiro para o elemento. Se nao encontrado, retorna NULL 
  */
PtNo_O* selectList(PtNo_O *ptNo, char *content);


/** \brief Método que insere elementos na LDE
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
 * \param *content - string da conteudo que sera inserido na lista
 * \return Retorna lista com elementos inseridos
*/
PtNo_O* insertList(PtNo_O *ptNo, char *content);

/** \brief Método que destroi a lista e libera endereços de memoria alocados para a LDE
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
 * \return Retorna um ponteiro para a lista com todos os laços destruidos e os elementos liberados da memória
*/
PtNo_O* destroyList(PtNo_O *ptNo);


/* Auxiliares */

/** \brief Método que exibe a lista
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
*/
void showList(PtNo_O *ptNo);
