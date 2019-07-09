/*

--------------------------------------------- TWITTER ANALYTICS ---------------------------------------------

Versao: 1.0.0

AUTORES: Ricco Soares (rvcsoares@inf.ufrgs.br) e Wellington Espindula (wmespindula@inf.ufrgs.br)

DESCRIÇÃO: O presente trabalho consiste em um projeto em Linguagem C que realiza operações que
fornecem estatísticas sobre uma base de tweets em arquivo .CSV.
As operações que o projeto visa realizar são:
Operação a.         Top hashtags. Listar as hastags mais citadas em todo arquivo.
Operação b.         Top Ativos. Listar os usuários que mais postam tweets.
Operação c.         Top retweets. Listar os tweets com maior número de retweets.
Operação d.         Top menções. Listar os usuários mais mencionados nos tweets.
Operação e.         Influenciadores. Listar os usuários com maior número de retweets.
Operação f.         Engajamento. Listar os usuários mais engajados da rede.
Operação g.         Termos Associados. Listar as principais hashtags associadas a uma hashtag específica.
Tempo.              Contabilizar o tempo de criação da estrutura de dados e da geração do arquivo de saídas.

COMO USAR?
A chamada do programa é realizada através do console junto com a chamada de 3 arquivos de texto:
    (i) Arquivo de texto da base de tweets;
    (ii) Arquivo de texto relativo aos parâmetros das operações;
    (iii) Arquivo de texto de saída (no qual o programa escreverá a solução de cada uma das operações)

Um exemplo de chamada do programa é dado por:
C:\minhaaplicacao entrada.txt operacoes.txt saida.txt


------------------------------------------------------------------------------------------------------------------
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

#include "DataStructs/tweets.h"


int main(int argc, char ** argv){
    // Ajeita codificacoes
    setlocale(LC_ALL, "pt_BR.UTF-8");

    clock_t startReading = clock();

    // Se tiver o numero certo de argumentos
    if (argc >= 3){
        /* Tenta abrir os arquivos de entrada de dados, de operacoes e de saida */
        FILE *entry = fopen(argv[1], "r");
        if (entry == NULL){
            printf("Arquivo %s nao encontrado!\n", argv[1]);
        }

        FILE *operations = fopen(argv[2], "r");
        if (operations == NULL){
            printf("Arquivo %s nao encontrado!\n", argv[2]);
        }

        FILE *output = fopen(argv[3], "w");
        if (output == NULL){
            printf("Arquivo %s nao encontrado!\n", argv[3]);
        }


        /* PONTEIROS PARA AS TADs USADAS */
        PtNo_O *hashtagTopList = NULL;
        PtNo_O *ativosTopList = NULL;
        PtNo_R *retweetsTopList = NULL;
        PtNo_O *mentionTopList = NULL;
        PtNo_R *influencerTopList = NULL;
        PtNo_E *mostEngagedTopList = NULL;
        PtNo_O *relatedHashtags = NULL;

        // Le o arquivo de operacoes e armazena quais operacoes devem ser realizadas e seus "limites" em flags
        initializeOperations(operations);


        // Le a base a carrega nas estruturas
        readEntryFile(entry, &hashtagTopList, &ativosTopList, &retweetsTopList, &mentionTopList, &influencerTopList, &mostEngagedTopList, &relatedHashtags);

        // Fim da contagem de tempo
        clock_t endReading = clock();
        float readingTime = (float)(endReading - startReading) / CLOCKS_PER_SEC;
        printf("O carregamento da base de dados nas estruturas levou %f segundos\n", readingTime);


        // Inicio da contagem de tempo para escrita do arquivo
        clock_t startWriting = clock();

        // Escreve arquivo
        writeOutput(output, hashtagTopList, ativosTopList, retweetsTopList, mentionTopList, influencerTopList, mostEngagedTopList, relatedHashtags);

        // Fim da contagem de tempo
        clock_t endWriting = clock();
        float writingTime = (float)(endWriting - startWriting) / CLOCKS_PER_SEC;
        printf("A escrita do arquivo de saida levou %f segundos\n", writingTime);


        // Destroi listas
        hashtagTopList = destroyList(hashtagTopList);
        ativosTopList = destroyList(ativosTopList);
        retweetsTopList = destroyRetweetsList(retweetsTopList);
        mentionTopList = destroyList(mentionTopList);
        influencerTopList = destroyRetweetsList(influencerTopList);
        mostEngagedTopList = destroyEngagementList(mostEngagedTopList);
        relatedHashtags = destroyList(relatedHashtags);

        // Fecha arquivos
        fclose(operations);
        fclose(entry);
        fclose(output);
    }

    return 0;
}
