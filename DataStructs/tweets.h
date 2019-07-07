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

struct user //estrutura que contém as informações de um usuário, para caso seja conveniente usar.
{
   char nome[50];
   int n_posts; //representa o número de posts feito por um usuário.
   int likes;   //representa o número de likes de um usuário.
   int rts; //representa o numero de retweets de um usuário.
   int n_mencoes; //representa o número de menções de um usuário.
   int engajamento; //representa uma constante que determina o engajamento de um usuário.


};
typedef struct user User;

typedef struct texto Texto;

/** \brief A partir de uma linha de um arquivo CSV, transfere as informacoes
 * para uma variavel do tipo Tweet
  */
Tweet readTwitte(char *linha);


/* DEPRECATED */
// void leOP(FILE *operacoes ,int *par_a, int *par_b, int *par_c, int *par_d, int *par_e, int *par_f, char par_g[]); //função que lê o arquivo de ops.
// void leTW(FILE *entrada);//funcao que realiza a leitura do arquivo de entrada da base de tweets.
// PtNo *Trata(PtNo *ptNo, char *found);//funcao que realiza o tratamento de hashtags encontradas em tweets atualizando a lista.
// void imprime(PtNo* PtLista);
// PtNo *UserInfluente(PtNo *ptinfluentes, char user[], int qtd_rts);
