#include "tweets.h"
PtNo *TrataHash(PtNo *pthashtags, char hash_achada[])//funcao que trata as hashtags encontradas no texto dos tweets.
{//recebe como parametros o ponteiro que aponta para o primeiro elemento da lista e a hashtag encontrada
    //printf("\n hashtag encontrada: %s\n", hash_achada);
    PtNo *Pt = pthashtags;//variavel auxiliar.
    PtNo *aux = NULL;
    PtNo *temp = NULL;
    if(pthashtags == NULL)//se a lista estiver vazia
    {
        Pt = (PtNo*) malloc(sizeof(PtNo));
        strcpy(Pt->conteudo, hash_achada);//equivale a novo = hashtag encontrada.
        Pt->ocorrencias = 1;
        Pt->ant = NULL;
        Pt->prox = NULL;
        pthashtags = Pt;
    }
    else//caso onde a lista nao se encontra vazia.
    {
        while((Pt->prox != NULL)&&(strcmp(Pt->conteudo,hash_achada) != 0))//procura o nodo na lista.
        {
            Pt = Pt->prox;
        }
        if(stricmp(Pt->conteudo,hash_achada) ==0)
        {//caso em que encontrou a hashtag na lista.
            Pt->ocorrencias++;
            while(Pt->ant != NULL &&(Pt->ocorrencias > Pt->ant->ocorrencias || (Pt->ocorrencias == Pt->ant->ocorrencias && strcasecmp(Pt->conteudo, Pt->ant->conteudo) < 0)))
            {
                temp = Pt->ant->ant;
                if(Pt->ant->ant != NULL){
                    Pt->ant->ant->prox = Pt;
                }
                Pt->ant->ant = Pt;

                if(Pt->prox != NULL){
                    Pt->prox->ant = Pt->ant;
                }
                Pt->ant->prox = Pt->prox;
                Pt->prox = Pt->ant;
                Pt->ant = temp;
            }
            if(Pt->ant == NULL)
                pthashtags = Pt;
        }
        else //caso em que a hashtag deve ser inserida na lista.
        {
            Pt = (PtNo*) malloc(sizeof(PtNo));
            strcpy(Pt->conteudo, hash_achada);//equivale a novo = hashtag encontrada.
            Pt->ocorrencias = 1;
            aux = pthashtags;
            while(aux->prox != NULL)
                 {//insere no fim.
                     aux = aux->prox;
                 }
                 aux->prox = Pt;
                 Pt->ant = aux;
                 Pt->prox = NULL;
           while(Pt->ant != NULL &&(Pt->ocorrencias > Pt->ant->ocorrencias || (Pt->ocorrencias == Pt->ant->ocorrencias && strcasecmp(Pt->conteudo, Pt->ant->conteudo) < 0)))
            {//atualiza a posicao do nodo.
                temp = Pt->ant->ant;
                if(Pt->ant->ant != NULL){
                    Pt->ant->ant->prox = Pt;
                }
                Pt->ant->ant = Pt;

                if(Pt->prox != NULL){
                    Pt->prox->ant = Pt->ant;
                }
                Pt->ant->prox = Pt->prox;
                Pt->prox = Pt->ant;
                Pt->ant = temp;
            }
            if(Pt->ant == NULL)
                pthashtags = Pt;

        }
    }
    return pthashtags;
}

PtNo *TrataMencoes(PtNo *ptmencoes, char mencao_achada[])
{//recebe como parametros o ponteiro que aponta para o primeiro elemento da lista e a hashtag encontrada
    //printf("\n mencao encontrada: %s", mencao_achada);
    PtNo *Pt = ptmencoes;//variavel auxiliar.
    PtNo *aux = NULL;
    PtNo *temp = NULL;
    if(ptmencoes == NULL)//se a lista estiver vazia
    {
        Pt = (PtNo*) malloc(sizeof(PtNo));
        strcpy(Pt->conteudo, mencao_achada);//equivale a novo = hashtag encontrada.
        Pt->ocorrencias = 1;
        Pt->ant = NULL;
        Pt->prox = NULL;
        ptmencoes = Pt;
    }
    else//caso onde a lista nao se encontra vazia.
    {
        while((Pt->prox != NULL)&&(strcmp(Pt->conteudo,mencao_achada) != 0))//procura o nodo na lista.
        {
            Pt = Pt->prox;
        }
        if(stricmp(Pt->conteudo,mencao_achada) == 0)
        {//caso em que encontrou a hashtag na lista.
            Pt->ocorrencias++;
            while(Pt->ant != NULL &&(Pt->ocorrencias > Pt->ant->ocorrencias || (Pt->ocorrencias == Pt->ant->ocorrencias && strcasecmp(Pt->conteudo, Pt->ant->conteudo) < 0)))
            {
                temp = Pt->ant->ant;
                if(Pt->ant->ant != NULL){
                    Pt->ant->ant->prox = Pt;
                }
                Pt->ant->ant = Pt;

                if(Pt->prox != NULL){
                    Pt->prox->ant = Pt->ant;
                }
                Pt->ant->prox = Pt->prox;
                Pt->prox = Pt->ant;
                Pt->ant = temp;
            }
            if(Pt->ant == NULL)
                ptmencoes = Pt;
        }
        else //caso em que a hashtag deve ser inserida na lista.
        {
            Pt = (PtNo*) malloc(sizeof(PtNo));
            strcpy(Pt->conteudo, mencao_achada);//equivale a novo = hashtag encontrada.
            Pt->ocorrencias = 1;
            aux = ptmencoes;
            while(aux->prox != NULL)
                 {//insere no fim.
                     aux = aux->prox;
                 }
                 aux->prox = Pt;
                 Pt->ant = aux;
                 Pt->prox = NULL;
           while(Pt->ant != NULL &&(Pt->ocorrencias > Pt->ant->ocorrencias || (Pt->ocorrencias == Pt->ant->ocorrencias && strcasecmp(Pt->conteudo, Pt->ant->conteudo) < 0)))
            {//atualiza a posicao do nodo.
                temp = Pt->ant->ant;
                if(Pt->ant->ant != NULL){
                    Pt->ant->ant->prox = Pt;
                }
                Pt->ant->ant = Pt;

                if(Pt->prox != NULL){
                    Pt->prox->ant = Pt->ant;
                }
                Pt->ant->prox = Pt->prox;
                Pt->prox = Pt->ant;
                Pt->ant = temp;
            }
            if(Pt->ant == NULL)
                ptmencoes = Pt;

        }
    }
    return ptmencoes;
}

void imprime(PtNo* PtLista)
{
     PtNo* ptaux=PtLista;
     if (PtLista == NULL)
        puts("lista vazia");
     else
     {
        //printf("\nLista: ");
        do {
            printf(" %s", ptaux->conteudo);
            printf(" %d vezes;", ptaux->ocorrencias);
            ptaux = ptaux->prox;
        } while (ptaux != NULL);
     }
}

void leOP(FILE *operacoes, int *par_a, int *par_b, int *par_c, int *par_d, int *par_e, int *par_f, char par_g[])
{//recebe por parâmetro as variáveis que armazenarão os parâmetros associados a cada operação do arquivo de entrada.
    //printf("%d",*par_a);
    int contador;
    for(contador = 0; contador<= 1; contador++)
            {
                fgetc(operacoes);
            }
            *par_a = fgetc(operacoes);
            *par_a = *par_a - 48; //a variavel agora armazena o parametro associado a operacao A que foi lido no arquivo.

            for(contador = 0; contador<= 2; contador++)
            {
                fgetc(operacoes);
            }
            *par_b = fgetc(operacoes);
            *par_b = *par_b - 48; //a variavel agora armazena o parametro associado a operacao B que foi lido no arquivo.

            for(contador = 0; contador<= 2; contador++)
            {
                fgetc(operacoes);
            }
            *par_c = fgetc(operacoes);
            *par_c = *par_c - 48;

            for(contador = 0; contador<= 2; contador++)
            {
                fgetc(operacoes);
            }
            *par_d = fgetc(operacoes);
            *par_d = *par_d - 48;

            for(contador = 0; contador<= 2; contador++)
            {
                fgetc(operacoes);
            }
            *par_e = fgetc(operacoes);
            *par_e = *par_e - 48;

            for(contador = 0; contador<= 2; contador++)
            {
                fgetc(operacoes);
            }
            *par_f = fgetc(operacoes);
            *par_f = *par_f - 48;

            while(fgetc(operacoes)!= '#')
            {

            }
            fgets(par_g, 280, operacoes);

}

void leTW(FILE *base)
{
    char qtd_likes[5];
    char qtd_rts[5];
    Tweet aux; //auxiliar utilizada para a manipulação de tweets.
    int fim = 0; //flag que indica o fim de um tweet
    PtNo *pthashtags; //declara uma variavel ponteiro que aponta para o inicio da LDE de hashtags.
    PtNo *ptmencoes;
    char aux_char;
    char aux_txt[280];
    ptmencoes = NULL;
    pthashtags = NULL;
    do{
        fim = 0;
        fgetc(base); //inicia o loop avançando uma posição no cursor do arquivo, desprezando o caractere '@' do usuário de cada tweet.
        fscanf(base,"%[^@;#]s", aux.user);  //move o nome do usuário para o campo correspondente da variável auxiliar.
        fgetc(base); //avança o cursor para pular o caractere de ponto e vírgula que separa o nome do usuário do texto.
        /*
            Realizar a chamada da função que incrementa o número de tweets de um usuário.
        */
        //é iniciado o loop de análise do conteúdo do texto do tweet.
        do{
            fscanf(base,"%[^@;#]s", aux_txt);
            aux_char = fgetc(base); //o caractere especial ';', '@' ou '#' encontrado foi transferido para uma variavel aleatoria.
            switch(aux_char){//o caractere especial sera descoberto.
                case '#':   //caso o caractere especial encontrado tenha sido uma hashtag, chama uma funcao que realiza o tratamento desse caso.
                    fscanf(base,"%[^@;# ]s", aux.hashtags);  //le do arquivo a hashtag encontrada.
                    pthashtags = TrataHash(pthashtags, aux.hashtags);//chama a funcao que trata as hashtags passando o inicio da lista e a hashtag lida
                    break;

                case '@': //encontrar '@' no corpo do tweet indica uma mencao realizada nele. Tal mencao sera copiada e uma funcao especial pra trata-la sera chamada.
                    fscanf(base,"%[^@;# ]s", aux.mencoes);
                    ptmencoes = TrataMencoes(ptmencoes, aux.mencoes);
                    break;
                case ' ':
                    break;

                default://o ultimo caso possivel de caractere encontrado no corpo do tweet seria ';'. Por isso, indica o fim do conteudo do tweet.
                    fim = 1;
                    break;
            }
        }while(fim != 1);
        //agora as informacoes de like e retweets devem ser lidas do arquivo e contabilizadas.
        fscanf(base,"%[^;]s", qtd_rts);  //colhe o ASCII da quantidade de rts do tweet.
        fgetc(base);
        fscanf(base,"%[^;\n]s", qtd_likes);   //colhe o ASCII da quantidade de likes do tweet.
        fgetc(base);    //despreza o caractere de dois pontos no fim do tweet.
    }while(!feof(base));
    printf("\n\n Lista de hashtags: ");
    imprime(pthashtags);
    printf("\n\n Lista de mencoes: ");
    imprime(ptmencoes);
}