/*
    TODO ESCREVER SOBRE A CLASSE

 */

struct Occurrence_LDE{
       int occurrences;
       char content[280];
       struct Occurrence_LDE* prev;
       struct Occurrence_LDE* next;
       };
typedef struct Occurrence_LDE PtNo_O;


/** \brief Metodo que inicializa a lista alocando endereço de memória
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
*/
PtNo_O* initializeList(PtNo_O *ptNo);

/** \brief Funcao que trata as ocorrencias de um texto na lista
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
 * \param *content - Texto que sera adicionado uma ocorrencia na lista
*/
PtNo_O* occurrence(PtNo_O *ptNo, char *content);

/* TODO  */
PtNo_O* selectList(PtNo_O *ptNo, char *content);


/** \brief Método que insere elementos na LDE
 * \param *ptHashtag - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
 * \param *hashtag - string da hashtag que sera inserida na lista
 * \return Retorna lista com elementos inseridos
*/
PtNo_O* insertList(PtNo_O *ptNo, char *content);

/* TODO */
PtNo_O* removeList(PtNo_O *ptNo, char *content);

/** \brief Método que destroi a lista e libera endereços de memoria alocados para a LDE
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
 * \return Retorna um ponteiro para a lista com todos os laços destruidos e os elementos liberados da memória
*/
PtNo_O* destroyList(PtNo_O *ptNo);


/* Auxiliares */

/** \brief Método que exibe a lista
 * \param *ptNo - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
*/
void showList(PtNo_O *ptNo);
