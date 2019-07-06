#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//estrutura tweet.
struct tweet //estrutura basica de um tweet.
{
    char user[50];//string correspondente ao nome do usuario do tweet
    char hashtags[280];//hashtag do tweet que pode ter até 280 caracteres.
    char mencoes[280];//corresponde a uma mencao em um tweet.
    int rts; //numero correspondente a quantidade de retweets que determinado tweet teve.
    int likes; //numero de likes que o tweet recebeu.
};
typedef struct tweet Tweet;


struct TipoPtNo{
       int ocorrencias;
       char conteudo[280];
       struct TipoPtNo* ant;
       struct TipoPtNo* prox;
       };
typedef struct TipoPtNo PtNo;

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

void leOP(FILE *operacoes ,int *par_a, int *par_b, int *par_c, int *par_d, int *par_e, int *par_f, char par_g[]); //função que lê o arquivo de ops.
void leTW(FILE *entrada);//funcao que realiza a leitura do arquivo de entrada da base de tweets.
PtNo *TrataHash(PtNo *pthashtags, char hash_achada[]);//funcao que realiza o tratamento de hashtags encontradas em tweets atualizando a lista.
void imprime(PtNo* PtLista);
PtNo *TrataMencoes(PtNo *ptmencoes, char mencao_achada[]);