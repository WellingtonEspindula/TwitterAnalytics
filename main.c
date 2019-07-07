/*

HEADER

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "DataStructs/ordered_list.h"
#include "DataStructs/tweets.h"

void initializeOperations(FILE *operationsFile);
void readEntryFile(FILE *entryFile);

void processOpA(PtNo **hashtagTopList, Tweet tt);
void processOpB(PtNo **ativosTopList, Tweet tt);


int LIMIT_OP_A = -1;
int LIMIT_OP_B = -1;
int LIMIT_OP_C = -1;
int LIMIT_OP_D = -1;
int LIMIT_OP_E = -1;
int LIMIT_OP_F = -1;
char HASHTAG_OP_G[280];


int main(int argc, char ** argv){
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

        // fgets(NULL, 500, entry);
        // fgets(NULL, 500, operations);


        initializeOperations(operations);
        readEntryFile(entry);


        // HashtagTL *hashtagTopList;
        // hashtagTopList = hashtagOcurrence(hashtagTopList, "#abc");
        // showHTL(hashtagTopList);
        // hashtagTopList = hashtagOcurrence(hashtagTopList, "#abd");
        // showHTL(hashtagTopList);
        // hashtagTopList = hashtagOcurrence(hashtagTopList, "#ad");
        // showHTL(hashtagTopList);
        // hashtagTopList = hashtagOcurrence(hashtagTopList, "#abcd");
        // showHTL(hashtagTopList);
        // hashtagTopList = hashtagOcurrence(hashtagTopList, "#abc");
        // showHTL(hashtagTopList);

        // hashtagTopList = destroyHTL(hashtagTopList);
        // showHTL(hashtagTopList);















        // printf("Operations:\n");
        // printf("A: %d\n", LIMIT_OP_A);
        // printf("B: %d\n", LIMIT_OP_B);
        // printf("C: %d\n", LIMIT_OP_C);
        // printf("D: %d\n", LIMIT_OP_D);
        // printf("E: %d\n", LIMIT_OP_E);
        // printf("F: %d\n", LIMIT_OP_F);
        // printf("G: %s\n", HASHTAG_OP_G);


        // char texto[75] = "@MrsPaulocarlos1;#QueroUFRGS Rela��es Internacionais @ufrgsnoticias;3;9";
        // Tweet tt1 = leTwitte(texto);
        // printf("Nome: %s\n",  tt1.user);
        // printf("Texto: %s\n", tt1.text);
        // printf("RTs: %d\n",   tt1.rtCount);
        // printf("Favs: %d\n",  tt1.favCount);

    }

    // system("PAUSE");
    return 0;
}



/** \brief Conforme as informacoes contidas no arquivo de operacoes, verifica
 * quais operacoes serao realizadas, habilitando-as e definindo a entrada dessas
 * operacoes
 */
void initializeOperations(FILE *operationsFile){
    char operation[282];
    while (fgets(operation, 280, operationsFile) != NULL) {
        // printf("operation: %s", operation);
        char *op;
        op = strtok(operation, ";");

        if (op[0] == 'g'){
            strcpy(HASHTAG_OP_G, strtok(NULL, ";"));

        } else{
            char *limit;
            limit = strtok(NULL, ";");
            // printf("op: %s\n", limit);
            // printf("limite: %s\n", limit);
            switch (op[0]){
                case 'a':
                    LIMIT_OP_A = atoi(limit);
                    break;
                case 'b':
                    LIMIT_OP_B = atoi(limit);
                    break;
                case 'c':
                    LIMIT_OP_C = atoi(limit);
                    break;
                case 'd':
                    LIMIT_OP_D = atoi(limit);
                    break;
                case 'e':
                    LIMIT_OP_E = atoi(limit);
                    break;
                case 'f':
                    LIMIT_OP_F = atoi(limit);
                    break;
            }
        }
    }
}

void readEntryFile(FILE *entryFile){
    char line[500];

    PtNo *hashtagTopList = NULL;
    PtNo *ativosTopList = NULL;

    while (fgets(line, 500, entryFile) != NULL) {
        Tweet tt = readTwitte(line);
        if (LIMIT_OP_A != -1){
            processOpA(&hashtagTopList, tt);
        }
        if (LIMIT_OP_B != -1){
            processOpB(&ativosTopList, tt);
        }


        //  printf("Nome: %s\n",  tt.user);
        //  printf("Texto: %s\n", tt.text);
        //  printf("RTs: %d\n",   tt.rtCount);
        //  printf("Favs: %d\n\n",  tt.favCount);
    }

    // destroyList(NULL);
    showList(hashtagTopList);
    showList(ativosTopList);
}

void processOpA(PtNo **hashtagTopList, Tweet tt){
    char hashtag[280];      // guarda uma hashtag
    char *ptHashtag;    // Aponta para sequencia de caracteres a partir de '#'
    char *rest = NULL;      // armazena o "resto" apos a hashtag encontrada
    char *token = NULL;     // saida do strtok

    // Primeira vez que verifica se tem um '#' e o captura, copiando-o ate o ' '
    ptHashtag = strchr(tt.text, '#');   // armazena texto de primeira hashtag em diante
    if (ptHashtag != NULL){                 // caso exista uma hashtag
        token = strtok(ptHashtag, " ");     // pega da hashtag ate o ' ' e o armazena
        strcpy(hashtag, token);             // copia o token armazenado para hashtag
        rest = strtok(NULL, "");            // copia o resto da frase para rest
        *hashtagTopList = ocurrence(*hashtagTopList, hashtag);   // indica que houve uma ocorrendia de hashtag
        // showList(*hashtagTopList);   // mostra lista
    }
    // aqui comeca o loop de encontrar outras hashtags no texto do twitte
    while ((ptHashtag != NULL) && (rest != '\0')){
        ptHashtag = strchr(rest, '#');
        if (ptHashtag != NULL){
            token = strtok(ptHashtag, " ");
            strcpy(hashtag, token);
            rest = strtok(NULL, "");
            *hashtagTopList = ocurrence(*hashtagTopList, hashtag);
            // showList(*hashtagTopList);
        }
    }
}

void processOpB(PtNo **ativosTopList, Tweet tt){
    *ativosTopList = ocurrence(*ativosTopList, tt.user);
    // showList(*ativosTopList);
}
