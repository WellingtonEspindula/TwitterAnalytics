/*

HEADER

*/

#ifndef BASE_LIBS_H
#define BASE_LIBS_H
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#endif

#include "DataStructs/retweets_ordered_list.h"
#include "DataStructs/occurrence_ordered_list.h"
#include "DataStructs/tweets.h"

void initializeOperations(FILE *operationsFile);
void readEntryFile(FILE *entryFile);

void processOpA(PtNo_O **hashtagTopList, Tweet tt);
void processOpB(PtNo_O **ativosTopList, Tweet tt);
void processOpC(PtNo_R **retweetsTopList, Tweet tt);
void processOpD(PtNo_O **ativosTopList, Tweet tt);
void processOpE(PtNo_R **influencerTopList, Tweet tt);


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
        // hashtagTopList = hashtagoccurrence(hashtagTopList, "#abc");
        // showHTL(hashtagTopList);
        // hashtagTopList = hashtagoccurrence(hashtagTopList, "#abd");
        // showHTL(hashtagTopList);
        // hashtagTopList = hashtagoccurrence(hashtagTopList, "#ad");
        // showHTL(hashtagTopList);
        // hashtagTopList = hashtagoccurrence(hashtagTopList, "#abcd");
        // showHTL(hashtagTopList);
        // hashtagTopList = hashtagoccurrence(hashtagTopList, "#abc");
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
    char *line;

    PtNo_O *hashtagTopList = NULL;
    PtNo_O *ativosTopList = NULL;
    PtNo_R *retweetsTopList = NULL;
    PtNo_O *mentionTopList = NULL;
    PtNo_R *influencerTopList = NULL;

    while (fgets(line, 500, entryFile) != NULL) {
        line = strchr(line, '@');
        Tweet tt = readTwitte(line);
        if (LIMIT_OP_A != -1){
            processOpA(&hashtagTopList, tt);
        }
        if (LIMIT_OP_B != -1){
            processOpB(&ativosTopList, tt);
        }
        if (LIMIT_OP_C != -1){
            processOpC(&retweetsTopList, tt);
        }
        if (LIMIT_OP_D != -1){
            processOpD(&mentionTopList, tt);
        }
        if (LIMIT_OP_E != -1){
            processOpE(&influencerTopList, tt);
        }
//        if (LIMIT_OP_F != -1){
//            processOpF(&influencerTopList, tt);
//        }


        //  printf("Nome: %s\n",  tt.user);
        //  printf("Texto: %s\n", tt.text);
        //  printf("RTs: %d\n",   tt.rtCount);
        //  printf("Favs: %d\n\n",  tt.favCount);
    }

    // destroyList(NULL);
    showList(hashtagTopList);
    showList(ativosTopList);
    showRetweetsList(retweetsTopList);
    showList(mentionTopList);
    showRetweetsList(influencerTopList);
}

void processOpA(PtNo_O **hashtagTopList, Tweet tt){
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
        *hashtagTopList = occurrence(*hashtagTopList, hashtag);   // indica que houve uma ocorrendia de hashtag
        // showList(*hashtagTopList);   // mostra lista
    }
    // aqui comeca o loop de encontrar outras hashtags no texto do twitte
    while ((ptHashtag != NULL) && (rest != '\0')){
        ptHashtag = strchr(rest, '#');
        if (ptHashtag != NULL){
            token = strtok(ptHashtag, " ");
            strcpy(hashtag, token);
            rest = strtok(NULL, "");
            *hashtagTopList = occurrence(*hashtagTopList, hashtag);
            // showList(*hashtagTopList);
        }
    }
}

void processOpB(PtNo_O **ativosTopList, Tweet tt){
    *ativosTopList = occurrence(*ativosTopList, tt.user);
}

void processOpC(PtNo_R **retweetsTopList, Tweet tt){
    *retweetsTopList = insertRetweetsList(*retweetsTopList, tt.text, tt.rtCount);
}

void processOpD(PtNo_O **mentionTopList, Tweet tt){
    char user[280];      // guarda o user mencionado
    char *ptUserMentioned;    // Aponta para sequencia de caracteres a partir de '@'
    char *rest = NULL;      // armazena o "resto" apos a hashtag encontrada
    char *token = NULL;     // saida do strtok

    // Primeira vez que verifica se tem um '@' e o captura, copiando-o ate o ' '
    ptUserMentioned = strchr(tt.text, '@');   // armazena texto de primeira hashtag em diante
    if (ptUserMentioned != NULL){                 // caso exista uma hashtag
        token = strtok(ptUserMentioned, " ");     // pega da hashtag ate o ' ' e o armazena
        strcpy(user, token);             // copia o token armazenado para hashtag
        rest = strtok(NULL, "");            // copia o resto da frase para rest
        *mentionTopList = occurrence(*mentionTopList, user);   // indica que houve uma ocorrendia de hashtag
        // showList(*hashtagTopList);   // mostra lista
    }
    // aqui comeca o loop de encontrar outros usuarios mencionados no texto do twitte
    while ((ptUserMentioned != NULL) && (rest != '\0')){
        ptUserMentioned = strchr(rest, '@');
        if (ptUserMentioned != NULL){
            token = strtok(ptUserMentioned, " ");
            strcpy(user, token);
            rest = strtok(NULL, "");
            *mentionTopList = occurrence(*mentionTopList, user);
            // showList(*hashtagTopList);
        }
    }
}

void processOpE(PtNo_R **influencerTopList, Tweet tt){
    *influencerTopList = sumRetweetsByContent(*influencerTopList, tt.user, tt.rtCount);
}
