/*
    TODO ESCREVER SOBRE A CLASSE

 */

struct Engagement_LDE{
       int engagement;
       char content[280];
       struct Engagement_LDE* prev;
       struct Engagement_LDE* next;
       };
typedef struct Engagement_LDE PtNo_E;


/** \brief Metodo que inicializa a lista alocando endereço de memória
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
*/
PtNo_E* initializeEngagementList(PtNo_E *ptNo);

/* TODO  */
PtNo_E* selectEngagementList(PtNo_E *ptNo, char *content);


/** \brief Método que insere elementos na LDE
 * \param *ptHashtag - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
 * \param *hashtag - string da hashtag que sera inserida na lista
 * \return Retorna lista com elementos inseridos
*/
PtNo_E* insertEngagementList(PtNo_E *ptNo, char *content, int mention, int likes, int rts);

/* TODO */
PtNo_E* sumEngagementsByContent(PtNo_E *ptNo, char *content, int likes, int rts);

/* TODO */
PtNo_E* mentioned(PtNo_E *ptNo, char *content);


/* TODO */
PtNo_E* removeEngagementList(PtNo_E *ptNo, char *content);

/** \brief Método que destroi a lista e libera endereços de memoria alocados para a LDE
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
 * \return Retorna um ponteiro para a lista com todos os laços destruidos e os elementos liberados da memória
*/
PtNo_E* destroyEngagementList(PtNo_E *ptNo);


/* Auxiliares */

/** \brief Método que exibe a lista
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
*/
void showEngagementList(PtNo_E *ptNo);
