#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

