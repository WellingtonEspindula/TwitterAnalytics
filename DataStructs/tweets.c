#include "tweets.h"


/** \brief A partir de uma linha de um arquivo CSV, transfere as informacoes
 * para uma variavel do tipo Tweet
  */
Tweet readTwitte(char *linha){
    Tweet twitte;
    strcpy(twitte.user, strtok(linha, ";"));
    strcpy(twitte.text, strtok(NULL, ";"));

    char rtCountStr[10];
    char favCountStr[10];

    strcpy(rtCountStr, strtok(NULL, ";"));
    strcpy(favCountStr, strtok(NULL, "\n"));

    twitte.rtCount = atoi(rtCountStr);
    twitte.favCount = atoi(favCountStr);

    return twitte;
}


/* Flags para as operacoes. Guardam os limites de exibicao para as operacoes. Se alguma das operacoes nao constar na lista, recebe -1 */
int LIMIT_OP_A = -1;
int LIMIT_OP_B = -1;
int LIMIT_OP_C = -1;
int LIMIT_OP_D = -1;
int LIMIT_OP_E = -1;
int LIMIT_OP_F = -1;
int LIMIT_OP_G = -1;
char HASHTAG_OP_G[280];

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

        /* Verifica se a operacao consta no arquivo de operacoes antes de realziar a mesma */
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
        if (LIMIT_OP_G != -1){
            processOpG(relatedHashtags, tt, HASHTAG_OP_G);
        }
    }
}

void writeOutput(FILE *output, PtNo_O *hashtagTopList, PtNo_O *ativosTopList,
                PtNo_R *retweetsTopList, PtNo_O *mentionTopList, PtNo_R *influencerTopList,
                PtNo_E *mostEngagedTopList, PtNo_O *relatedHashtags){

   fprintf(output, "--- OP a\n");
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

   fprintf(output, "--- OP b\n");
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

   fprintf(output, "--- OP c\n");
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

   fprintf(output, "--- OP d\n");
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

  fprintf(output, "--- OP e\n");
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

  fprintf(output, "--- OP f\n");
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

  fprintf(output, "--- OP g\n");
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
    char *ptHashtag;        // Aponta para sequencia de caracteres a partir de '#'
    char *rest = NULL;      // armazena o "resto" apos a hashtag encontrada
    char *token = NULL;     // saida do strtok

    // Primeira vez que verifica se tem um '#' e o captura, copiando-o ate o delimitador
    ptHashtag = strchr(tt.text, '#');                // armazena texto da primeira hashtag em diante
    if (ptHashtag != NULL){                          // caso exista uma hashtag
        token = strtok(ptHashtag, " .!?;,'\"");       // pega da hashtag ate o delimitador e o armazena
        strcpy(hashtag, token);                     // copia o token armazenado para hashtag
        rest = strtok(NULL, "");                    // copia o resto da frase para rest
        *hashtagTopList = occurrence(*hashtagTopList, hashtag);   // indica que houve uma ocorrendia de hashtag
    }
    // aqui comeca o loop de encontrar outras hashtags no texto do twitte
    while ((ptHashtag != NULL) && (rest != '\0')){
        ptHashtag = strchr(rest, '#');
        if (ptHashtag != NULL){
            token = strtok(ptHashtag, " .!?;,'\"");
            strcpy(hashtag, token);
            rest = strtok(NULL, "");
            *hashtagTopList = occurrence(*hashtagTopList, hashtag);
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

    // Primeira vez que verifica se tem um '@' e o captura, copiando-o ate o delimitador
    ptUserMentioned = strchr(tt.text, '@');         // armazena texto do primeiro arroba em diante
    if (ptUserMentioned != NULL){                   // caso exista um arroba
        token = strtok(ptUserMentioned, " .!?;,'\"");       // pega do arroba ate o delimitador e o armazena
        strcpy(user, token);                        // copia o token armazenado para user
        rest = strtok(NULL, "");                    // copia o resto da frase para rest
        *mentionTopList = occurrence(*mentionTopList, user);   // indica que houve uma ocorrencia de hashtag
    }
    // aqui comeca o loop de encontrar outros usuarios mencionados no texto do twitte
    while ((ptUserMentioned != NULL) && (rest != '\0')){
        ptUserMentioned = strchr(rest, '@');
        if (ptUserMentioned != NULL){
            token = strtok(ptUserMentioned, " .!?;,'\"");
            strcpy(user, token);
            rest = strtok(NULL, "");
            *mentionTopList = occurrence(*mentionTopList, user);
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

    // Primeira vez que verifica se tem um '@' e o captura, copiando-o ate o delimitador
    ptUserMentioned = strchr(tt.text, '@');                 // armazena texto do primeiro arroba em diante
    if (ptUserMentioned != NULL){                           // caso exista um arroba
        token = strtok(ptUserMentioned, " .!?;,'\"");         // pega do arroba ate o delimitador e o armazena
        strcpy(user, token);                                // copia o token armazenado para user
        rest = strtok(NULL, "");                            // copia o resto da frase para rest
        *mostEngagedTopList = mentioned(*mostEngagedTopList, user);   // indica que houve uma ocorrendia de arroba
        // showList(*hashtagTopList);   // mostra lista
    }
    // aqui comeca o loop de encontrar outros usuarios mencionados no texto do twitte
    while ((ptUserMentioned != NULL) && (rest != '\0')){
        ptUserMentioned = strchr(rest, '@');
        if (ptUserMentioned != NULL){
            token = strtok(ptUserMentioned, " .!?;,'\"");
            strcpy(user, token);
            rest = strtok(NULL, "");
            *mostEngagedTopList = mentioned(*mostEngagedTopList, user);
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

    // Primeira vez que verifica se tem um '#' e o captura, copiando-o ate o delimitador
    ptHashtag = strchr(tt.text, '#');               // armazena texto de primeira hashtag em diante
    if (ptHashtag != NULL){                         // caso exista uma hashtag
        token = strtok(ptHashtag, " .!?;,'\"");       // pega da hashtag ate o delimitador e o armazena
        strcpy(hashtag, token);                     // copia o token armazenado para hashtag
        rest = strtok(NULL, "");                    // copia o resto da frase para rest
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
            token = strtok(ptHashtag, " .!?;,'\"");
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
