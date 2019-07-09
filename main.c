/*

TODO HEADER

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

    // Inicializa G como string nula
    HASHTAG_OP_G[0] = '\0';

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
        // end = clock();
    //    float readingTime = (float)(end - start) / CLOCKS_PER_SEC;
        // printf("O carregamento da base de dados nas estruturas levou %f segundos\n", readingTime);


        // Inicio da contagem de tempo para escrita do arquivo
        // start = clock();

        // Escreve arquivo
        writeOutput(output, hashtagTopList, ativosTopList, retweetsTopList, mentionTopList, influencerTopList, mostEngagedTopList, relatedHashtags);

        // Fim da contagem de tempo
        // end = clock();
        // float writingTime = (float)(end - start) / CLOCKS_PER_SEC;
        // printf("A escrita do arquivo de saida levou %f segundos\n", writingTime);


        fclose(operations);
        fclose(entry);
        fclose(output);
    }

    return 0;
}