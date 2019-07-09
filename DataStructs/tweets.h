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

#include "DataStructs/retweets_ordered_list.h"
#include "DataStructs/occurrence_ordered_list.h"
#include "DataStructs/engagement_ordered_list.h"

/* Defini-se aqui a estrutura base de um twitte */
struct str_tweet
{
    char user[100];
    char text[300];
    int rtCount;
    int favCount;
};
typedef struct str_tweet Tweet;

/** \brief A partir de uma linha de um arquivo CSV, transfere as informacoes
 * para uma variavel do tipo Tweet
  */
Tweet readTwitte(char *linha);



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
