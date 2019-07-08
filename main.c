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
#include <locale.h>
#include <strings.h>
#endif

#include "DataStructs/retweets_ordered_list.h"
#include "DataStructs/occurrence_ordered_list.h"
#include "DataStructs/engagement_ordered_list.h"
#include "DataStructs/tweets.h"

void initializeOperations(FILE *operationsFile);
void readEntryFile(FILE *entryFile, PtNo_O **hashtagTopList, PtNo_O **ativosTopList,
                PtNo_R **retweetsTopList, PtNo_O **mentionTopList, PtNo_R **influencerTopList,
                PtNo_E **mostEngagedTopList, PtNo_O **relatedHashtags);
void writeOutput(FILE *output, PtNo_O *hashtagTopList, PtNo_O *ativosTopList,
                PtNo_R *retweetsTopList, PtNo_O *mentionTopList, PtNo_R *influencerTopList,
                PtNo_E *mostEngagedTopList, PtNo_O *relatedHashtags);

void processOpA(PtNo_O **hashtagTopList, Tweet tt);
void processOpB(PtNo_O **ativosTopList, Tweet tt);
void processOpC(PtNo_R **retweetsTopList, Tweet tt);
void processOpD(PtNo_O **mentionTopList, Tweet tt);
void processOpE(PtNo_R **influencerTopList, Tweet tt);
void processOpF(PtNo_E **mostEngagedTopList, Tweet tt);
void processOpG(PtNo_O **relatedHashtags, Tweet tt, char *hashtagSearch);


int LIMIT_OP_A = -1;
int LIMIT_OP_B = -1;
int LIMIT_OP_C = -1;
int LIMIT_OP_D = -1;
int LIMIT_OP_E = -1;
int LIMIT_OP_F = -1;
int LIMIT_OP_G = -1;
char HASHTAG_OP_G[280];


int main(int argc, char ** argv){
    setlocale(LC_ALL, "Portuguese");

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

        // fgets(NULL, 500, entry);
        // fgets(NULL, 500, operations);


        PtNo_O *hashtagTopList = NULL;
        PtNo_O *ativosTopList = NULL;
        PtNo_R *retweetsTopList = NULL;
        PtNo_O *mentionTopList = NULL;
        PtNo_R *influencerTopList = NULL;
        PtNo_E *mostEngagedTopList = NULL;
        PtNo_O *relatedHashtags = NULL;

        initializeOperations(operations);
        readEntryFile(entry, &hashtagTopList, &ativosTopList, &retweetsTopList, &mentionTopList, &influencerTopList, &mostEngagedTopList, &relatedHashtags);
        writeOutput(output, hashtagTopList, ativosTopList, retweetsTopList, mentionTopList, influencerTopList, mostEngagedTopList, relatedHashtags);

        fclose(operations);
        fclose(entry);
        fclose(output);


    }

    return 0;
}



/** \brief Conforme as informacoes contidas no arquivo de operacoes, verifica
 * quais operacoes serao realizadas, habilitando-as e definindo a entrada dessas
 * operacoes
 */
void initializeOperations(FILE *operationsFile){
    char operation[282];
    fflush(operationsFile);
    while (fgets(operation, 280, operationsFile) != NULL) {
        char *op;
        op = strtok(operation, ";");

        if (op[0] == 'g'){
            strcpy(HASHTAG_OP_G, strtok(NULL, ";"));

        }

        char *limit;
        limit = strtok(NULL, ";");
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
            case 'g':
                LIMIT_OP_G = atoi(limit);
                break;
        }
    }
}

void readEntryFile(FILE *entryFile, PtNo_O **hashtagTopList, PtNo_O **ativosTopList,
                PtNo_R **retweetsTopList, PtNo_O **mentionTopList, PtNo_R **influencerTopList,
                PtNo_E **mostEngagedTopList, PtNo_O **relatedHashtags){
    char *line;

    while (fgets(line, 500, entryFile) != NULL) {
        line = strchr(line, '@');           // aponta pro primeiro '@' da linha
        Tweet tt = readTwitte(line);
        // printf("%s\n", tt.user);
        // printf("%s\n", tt.text);
        // printf("%d\n", tt.rtCount);
        // printf("%d\n\n", tt.favCount);
        if (LIMIT_OP_A != -1){
            processOpA(hashtagTopList, tt);
        }
        if (LIMIT_OP_B != -1){
            processOpB(ativosTopList, tt);
        }
        if (LIMIT_OP_C != -1){
            processOpC(retweetsTopList, tt);
        }
        if (LIMIT_OP_D != -1){
            processOpD(mentionTopList, tt);
        }
        if (LIMIT_OP_E != -1){
            processOpE(influencerTopList, tt);
        }
        if (LIMIT_OP_F != -1){
            processOpF(mostEngagedTopList, tt);
        }
        if (LIMIT_OP_F != -1){
            processOpG(relatedHashtags, tt, HASHTAG_OP_G);
        }
    }

    // showList(*hashtagTopList);
    // showList(*ativosTopList);
    // showRetweetsList(*retweetsTopList);
    // showList(*mentionTopList);
    // showRetweetsList(*influencerTopList);
    // showEngagementList(*mostEngagedTopList);
    // showList(*relatedHashtags);
}

void writeOutput(FILE *output, PtNo_O *hashtagTopList, PtNo_O *ativosTopList,
                PtNo_R *retweetsTopList, PtNo_O *mentionTopList, PtNo_R *influencerTopList,
                PtNo_E *mostEngagedTopList, PtNo_O *relatedHashtags){

   fprintf(output, "--- OP A\n");
   if (LIMIT_OP_A != -1){
       PtNo_O *aux = hashtagTopList;
       if (LIMIT_OP_A == 0){
           while (aux != NULL){
                fprintf(output, "%s, %d\n", aux->content, aux->occurrences);
                aux = aux->next;
           }
       } else {
            int i = 0;
            while ((aux != NULL) && (i < LIMIT_OP_A)){
                fprintf(output, "%s, %d\n", aux->content, aux->occurrences);
                aux = aux->next;
                i++;
            }
       }
   }

   fprintf(output, "--- OP B\n");
   if (LIMIT_OP_B != -1){
       PtNo_O *aux = ativosTopList;
       if (LIMIT_OP_B == 0){
           while (aux != NULL){
                fprintf(output, "%s, %d\n", aux->content, aux->occurrences);
                aux = aux->next;
           }
       } else {
            int i = 0;
            while ((aux != NULL) && (i < LIMIT_OP_B)){
                fprintf(output, "%s, %d\n", aux->content, aux->occurrences);
                aux = aux->next;
                i++;
            }
       }
   }

   fprintf(output, "--- OP C\n");
   if (LIMIT_OP_C != -1){
       PtNo_R *aux = retweetsTopList;
       if (LIMIT_OP_C == 0){
           while (aux != NULL){
                fprintf(output, "%s, %d\n", aux->content, aux->retwittes);
                aux = aux->next;
           }
       } else {
            int i = 0;
            while ((aux != NULL) && (i < LIMIT_OP_C)){
                fprintf(output, "%s, %d\n", aux->content, aux->retwittes);
                aux = aux->next;
                i++;
            }
       }
   }

   fprintf(output, "--- OP D\n");
   if (LIMIT_OP_D != -1){
       PtNo_O *aux = mentionTopList;
       if (LIMIT_OP_D == 0){
           while (aux != NULL){
                fprintf(output, "%s, %d\n", aux->content, aux->occurrences);
                aux = aux->next;
           }
       } else {
            int i = 0;
            while ((aux != NULL) && (i < LIMIT_OP_D)){
                fprintf(output, "%s, %d\n", aux->content, aux->occurrences);
                aux = aux->next;
                i++;
            }
       }
   }

  fprintf(output, "--- OP E\n");
  if (LIMIT_OP_E != -1){
      PtNo_R *aux = influencerTopList;
      if (LIMIT_OP_E == 0){
          while (aux != NULL){
               fprintf(output, "%s, %d\n", aux->content, aux->retwittes);
               aux = aux->next;
          }
      } else {
            int i = 0;
            while ((aux != NULL) && (i < LIMIT_OP_E)){
               fprintf(output, "%s, %d\n", aux->content, aux->retwittes);
               aux = aux->next;
               i++;
           }
      }
  }

  fprintf(output, "--- OP F\n");
  if (LIMIT_OP_F != -1){
      PtNo_E *aux = mostEngagedTopList;
      if (LIMIT_OP_F == 0){
          while (aux != NULL){
               fprintf(output, "%s, %d\n", aux->content, aux->engagement);
               aux = aux->next;
          }
      } else {
            int i = 0;
            while ((aux != NULL) && (i < LIMIT_OP_F)){
               fprintf(output, "%s, %d\n", aux->content, aux->engagement);
               aux = aux->next;
               i++;
           }
      }
  }

  fprintf(output, "--- OP G\n");
  if (LIMIT_OP_G != -1){
      PtNo_O *aux = relatedHashtags;
      if (LIMIT_OP_G == 0){
          while (aux != NULL){
               fprintf(output, "%s, %d\n", aux->content, aux->occurrences);
               aux = aux->next;
          }
      } else {
            int i = 0;
            while ((aux != NULL) && (i < LIMIT_OP_G)){
               fprintf(output, "%s, %d\n", aux->content, aux->occurrences);
               aux = aux->next;
               i++;
           }
      }
  }


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

void processOpF(PtNo_E **mostEngagedTopList, Tweet tt){
    /* AQUI BUSCA OS LIKES E OS RETWITTES DE UM USUARIO */
    *mostEngagedTopList = sumEngagementsByContent(*mostEngagedTopList, tt.user, tt.favCount, tt.rtCount);


    /* AQUI BUSCA MENCOES DE OUTROS USUARIOS NO MESMO TWITTE */
    char user[280];             // guarda o user mencionado
    char *ptUserMentioned;      // Aponta para sequencia de caracteres a partir de '@'
    char *rest = NULL;          // armazena o "resto" apos a hashtag encontrada
    char *token = NULL;         // saida do strtok

    // Primeira vez que verifica se tem um '@' e o captura, copiando-o ate o ' '
    ptUserMentioned = strchr(tt.text, '@');         // armazena texto de primeira hashtag em diante
    if (ptUserMentioned != NULL){                   // caso exista uma hashtag
        token = strtok(ptUserMentioned, " ");       // pega da hashtag ate o ' ' e o armazena
        strcpy(user, token);                        // copia o token armazenado para hashtag
        rest = strtok(NULL, "");                    // copia o resto da frase para rest
        *mostEngagedTopList = mentioned(*mostEngagedTopList, user);   // indica que houve uma ocorrendia de hashtag
        // showList(*hashtagTopList);   // mostra lista
    }
    // aqui comeca o loop de encontrar outros usuarios mencionados no texto do twitte
    while ((ptUserMentioned != NULL) && (rest != '\0')){
        ptUserMentioned = strchr(rest, '@');
        if (ptUserMentioned != NULL){
            token = strtok(ptUserMentioned, " ");
            strcpy(user, token);
            rest = strtok(NULL, "");
            *mostEngagedTopList = mentioned(*mostEngagedTopList, user);
            // showList(*hashtagTopList);
        }
    }
}

void processOpG(PtNo_O **relatedHashtags, Tweet tt, char *hashtagSearch){
    char hashtagsOnTwitte[150][280];    // Guarda as hashtags encontradas no texto
    bool hashtagFound = false;          // Flag para verificar se a hashtag buscada foi encontrada no determinado texto
    int index = 0;                      // Guarda a posicao a ser inserida a proxima hashtag encontrada

    char hashtag[280];      // guarda uma hashtag
    char *ptHashtag;        // Aponta para sequencia de caracteres a partir de '#'
    char *rest = NULL;      // armazena o "resto" apos a hashtag encontrada
    char *token = NULL;     // saida do strtok

    // Primeira vez que verifica se tem um '#' e o captura, copiando-o ate o ' '
    ptHashtag = strchr(tt.text, '#');       // armazena texto de primeira hashtag em diante
    if (ptHashtag != NULL){                 // caso exista uma hashtag
        token = strtok(ptHashtag, " ");     // pega da hashtag ate o ' ' e o armazena
        strcpy(hashtag, token);             // copia o token armazenado para hashtag
        rest = strtok(NULL, "");            // copia o resto da frase para rest
        if (strcmp(hashtag, hashtagSearch) ==  0){
            hashtagFound = true;
        } else {
            strcpy(hashtagsOnTwitte[index], hashtag);
            index++;
        }
    }
    // aqui comeca o loop de encontrar outras hashtags no texto do twitte
    while ((ptHashtag != NULL) && (rest != '\0')){
        ptHashtag = strchr(rest, '#');
        if (ptHashtag != NULL){
            token = strtok(ptHashtag, " ");
            strcpy(hashtag, token);
            rest = strtok(NULL, "");
            if (strcmp(hashtag, hashtagSearch) == 0){
                hashtagFound = true;
            } else {
                strcpy(hashtagsOnTwitte[index], hashtag);
                index++;
            }
        }
    }

    // Se a hashtag foi encontrada no texto, adiciona as outras hashtags que estao
    // no mesmo texto na lista de hashtags relacionadas
    if (hashtagFound){
        for (int i = 0; i < index; i++){
            *relatedHashtags = occurrence(*relatedHashtags, hashtagsOnTwitte[i]);
        }
    }


}
