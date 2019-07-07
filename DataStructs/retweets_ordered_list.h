/*
    TODO ESCREVER SOBRE A CLASSE

 */

struct Retweets_LDE{
       int retwittes;
       char content[280];
       struct Retweets_LDE* prev;
       struct Retweets_LDE* next;
       };
typedef struct Retweets_LDE PtNo_R;


/** \brief Metodo que inicializa a lista alocando endereço de memória
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
*/
PtNo_R* initializeRetweetList(PtNo_R *ptNo);

/* TODO  */
PtNo_R* selectRetweetList(PtNo_R *ptNo, char *content);


/** \brief Método que insere elementos na LDE
 * \param *ptHashtag - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
 * \param *hashtag - string da hashtag que sera inserida na lista
 * \return Retorna lista com elementos inseridos
*/
PtNo_R* insertRetweetList(PtNo_R *ptNo, char *content, int rts);

/* TODO */
PtNo_R* sumRetweetsByContent(PtNo_R *ptNo, char *content, int rts);


/* TODO */
PtNo_R* removeRetweetList(PtNo_R *ptNo, char *content);

/** \brief Método que destroi a lista e libera endereços de memoria alocados para a LDE
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
 * \return Retorna um ponteiro para a lista com todos os laços destruidos e os elementos liberados da memória
*/
PtNo_R* destroyRetweetList(PtNo_R *ptNo);


/* Auxiliares */

/** \brief Método que exibe a lista
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
*/
void showRetweetList(PtNo_R *ptNo);
