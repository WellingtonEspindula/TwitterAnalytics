/*
    TODO ESCREVER SOBRE A CLASSE

 */

struct LDE{
       int ocurrencies;
       char content[280];
       struct LDE* prev;
       struct LDE* next;
       };
typedef struct LDE PtNo;


/** \brief Metodo que inicializa a lista alocando endereço de memória
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
*/
PtNo* initializeList(PtNo *ptNo);

/** \brief Funcao que trata as ocorrencias de um texto na lista
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
 * \param *content - Texto que sera adicionado uma ocorrencia na lista
*/
PtNo* ocurrence(PtNo *ptNo, char *content);

/* TODO  */
PtNo* selectList(PtNo *ptNo, char *content);


/** \brief Método que insere elementos na LDE
 * \param *ptHashtag - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
 * \param *hashtag - string da hashtag que sera inserida na lista
 * \return Retorna lista com elementos inseridos
*/
PtNo* insertList(PtNo *ptNo, char *content);

/* TODO */
PtNo* removeList(PtNo *ptNo, char *content);

/** \brief Método que destroi a lista e libera endereços de memoria alocados para a LDE
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
 * \return Retorna um ponteiro para a lista com todos os laços destruidos e os elementos liberados da memória
*/
PtNo* destroyList(PtNo *ptNo);


/* Auxiliares */

/** \brief Método que exibe a lista
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
*/
void showList(PtNo *ptNo);
