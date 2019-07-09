/*
    Autores: Ricco Soares e Wellington Espindula
    
    Descricao: Esse módulo tem a estrutura basica de um Twitte
    e contem tambem os principais metodos utilizados no programa.

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

#include "retweets_ordered_list.h"
#include "occurrence_ordered_list.h"
#include "engagement_ordered_list.h"

/* Defini-se aqui a estrutura base de um twitte */
struct str_tweet
{
    char user[100];
    char text[300];
    int rtCount;
    int favCount;
};
typedef struct str_tweet Tweet;

/*  --------  METODOS REFERENTES A ESTRUTURA TWEET -------- */
/** \brief A partir de uma linha de um arquivo CSV, transfere as informacoes
 * para uma variavel do tipo Tweet
 * \param *linha - string que recebe o valor de uma linha do arquivo de twittes
  */
Tweet readTwitte(char *linha);


/* --------  METODOS DE LEITURA E ESCRITA DE ARQUIVOS (IO METHODS) -------- */

/** \brief Conforme as informacoes contidas no arquivo de operacoes, verifica
 * quais operacoes serao realizadas, habilitando-as e definindo a entrada dessas
 * operacoes
 * \param *operationsFile - ponteiro para arquivo de operacoes
 */
void initializeOperations(FILE *operationsFile);

/** \brief Le arquivo, realizando as operacoes
 * \param FILE *entryFile - arquivo de entrada da base de dados
 * \param **hashtagTopList - ponteiro para a lista de hashtags
 * \param **ativosTopList -  ponteiro para a lista dos usuarios mais ativos
 * \param **retweetsTopList - ponteiro para a lista de retwittes
 * \param **mentionTopList - ponteiro para a lista de mencoes
 * \param **influencerTopList - ponteiro para a lista de usuarios influenciadores
 * \param **mostEngagedTopList - ponteiro para a lista de usuarios mais engajados
 * \param **relatedHashtags - ponteiro para a lista de hashtags relacionadas
 */
void readEntryFile(FILE *entryFile, PtNo_O **hashtagTopList, PtNo_O **ativosTopList,
                PtNo_R **retweetsTopList, PtNo_O **mentionTopList, PtNo_R **influencerTopList,
                PtNo_E **mostEngagedTopList, PtNo_O **relatedHashtags);


/** \brief Escreve arquivo final com as operacoes ja realizadas
 * \param FILE *output - arquivo de saida de dados
 * \param **hashtagTopList - ponteiro para a lista de hashtags
 * \param **ativosTopList -  ponteiro para a lista dos usuarios mais ativos
 * \param **retweetsTopList - ponteiro para a lista de retwittes
 * \param **mentionTopList - ponteiro para a lista de mencoes
 * \param **influencerTopList - ponteiro para a lista de usuarios influenciadores
 * \param **mostEngagedTopList - ponteiro para a lista de usuarios mais engajados
 * \param **relatedHashtags - ponteiro para a lista de hashtags relacionadas
 */
void writeOutput(FILE *output, PtNo_O *hashtagTopList, PtNo_O *ativosTopList,
                PtNo_R *retweetsTopList, PtNo_O *mentionTopList, PtNo_R *influencerTopList,
                PtNo_E *mostEngagedTopList, PtNo_O *relatedHashtags);


/* -------- METODOS DE PROCESSAMENTO DE OPERACOES -------- */

/** \brief Funcao de processamento da operacao A.
 * Essa funcao eh responsavel pelo tratamento das hashtags 
 * que aparecem durante os tweets, para que seja feita a operacao A.
 * Procura hashtags presentes no tweet e registrar uma ocorrencia
 * da hashtag no texto, para que ela seja inserida ou contabilizada na lista.

 * \param **hashtagTopList - ponteiro para a lista de hashtags dada por PtNo_O (LDE de Ocorrencias)
 * \param tt - Twitte no qual serao procuradas as hashtags
 */
void processOpA(PtNo_O **hashtagTopList, Tweet tt);

/** \brief Funcao de processamento da operacao B.
 * Essa funcao eh responsavel pelo tratamento dos usuarios 
 * que mais postam tweets, para que seja feita a operacao B.
 * Registra ocorrencia de um tweet escrito por um determinado
 * usuario, para que a lista relativa aos usuários que mais 
 * postam tweets seja atualizada.

 * \param **ativosTopList - ponteiro para a lista dos usuarios mais ativos dada por PtNo_O (LDE de Ocorrencias)
 * \param tt - Twitte no qual serao procurados os usuarios
 */
void processOpB(PtNo_O **ativosTopList, Tweet tt);

/** \brief Funcao de processamento da operacao C.
 * Essa funcao eh responsavel por inserir o tweet lido 
 * na lista de tweets que possuem mais retweets.

 * \param **retweetsTopList - ponteiro para a lista de retwittes dada por PtNo_R (LDE de Retwittes)
 * \param tt - Twitte que sera inserido
 */
void processOpC(PtNo_R **retweetsTopList, Tweet tt);

/** \brief Funcao de processamento da operacao D.
 * Realiza a verificacao de se houve mencoes a usuarios 
 * e em caso positivo, realiza a chamada da funcao que 
 * registra a ocorrencia de uma mencao a um determinado 
 * usuario, passando para ela o ponteiro relativo ao 
 * inicio da lista e o usuario que foi mencionado.

 * \param **mentionTopList - ponteiro para a lista de mencoes dada por PtNo_O (LDE de Ocorrencias)
 * \param tt - Twitte no qual serao procuradas as mencoes
 */
void processOpD(PtNo_O **mentionTopList, Tweet tt);

/** \brief Funcao de processamento da operacao E.
 * Atualiza a lista de usuarios com maior numero de retweets.

 * \param **influencerTopList - ponteiro para a lista de usuarios influenciadores dada por PtNo_R (LDE de Retwittes)
 * \param tt - Twitte que sera inserido
 */
void processOpE(PtNo_R **influencerTopList, Tweet tt);

/** \brief Funcao de processamento da operacao F.
 * Responsavel por atualizar a lista de usuarios mais engajados,
 * usando para isso os likes, retwittes e mencoes que cada usuario
 * recebeu.

 * \param **mostEngagedTopList - ponteiro para a lista de usuarios mais engajados dada por PtNo_E (LDE de Engajamentos)
 * \param tt - Twitte no qual serao procurados os usuarios mais engajados
 */
void processOpF(PtNo_E **mostEngagedTopList, Tweet tt);

/** \brief Funcao de processamento da operacao G.
 * Em suma, a funcao atualiza as hashtags relacionadas a uma hashtag entrada.
 * A função procura em cada twitte se existe a hashtag buscada.
 * Se sim, registra a ocorrencia das outras hashtags que estao no mesmo twitte,
 * atualizando a lista.

 * \param **relatedHashtags - ponteiro para a lista de hashtags relacionadas dada por PtNo_O (LDE de Ocorrencias)
 * \param tt - Twitte no qual serao procuradas as hashtags
 */
void processOpG(PtNo_O **relatedHashtags, Tweet tt, char *hashtagSearch);
