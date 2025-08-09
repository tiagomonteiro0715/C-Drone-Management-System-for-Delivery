/*
 * base.h
 */

#ifndef H_BASE
#define H_BASE



/* Tipo de dados: base */
typedef struct _base * base;

/* Prototipos das funcoes associadas a uma base */

/***********************************************
criaBase - Criacao da instancia da estrutura associada a uma base.
Parametros:
    nome - nome da base
    localizacao - coordenadas da localizacao da base
Retorno: apontador para a instancia criada
Precondicoes:
***********************************************/
base criaBase(char *nome, coordenadas localizacao);

/***********************************************
destroiBase - Liberta a memoria ocupada pela instancia da estrutura associada a base.
Parametros:
    b - base a destruir
Retorno:
Precondicoes: b != NULL
***********************************************/
void destroiBase(base b);

/***********************************************
nomeBase - consulta o nome de uma base dada.
Parametros:
    b - base
Retorno: nome da base
Precondicoes: b != NULL
***********************************************/
char *nomeBase(base b);

/***********************************************
localizacaoBase - consulta a localizacao de uma base dada.
Parametros:
    b - base
Retorno: coordenadas da localizacao da base
Precondicoes: b != NULL
***********************************************/
coordenadas localizacaoBase(base b);

/***********************************************
avancaUmaHoraBase - avanca o tempo de uma base dada.
Parametros:
    b - base
    tempo - tempo a ser avancado
Retorno:
Precondicoes: b != NULL
***********************************************/
void avancaUmaHoraBase(base b, int tempo);

/***********************************************
tamanhoDronesBase - consulta o numero de drones de uma base dada.
Parametros:
    b - base
Retorno: numero de drones
Precondicoes: b != NULL
***********************************************/
int tamanhoDronesBase(base b);

/***********************************************
acederDronesBase - consulta o dicionario de drones de uma base dada.
Parametros:
    b - base
Retorno: dicionario de drones
Precondicoes: b != NULL
***********************************************/
dicionario acederDronesBase(base b);


/***********************************************
idValorDroneBase - Consulta o identificador de um drone.
Parametros:
    d - drone
Retorno: identificador do drone
Precondicoes: d != NULL
***********************************************/
int idValorDroneBase(drone d);

/***********************************************
alcanceDroneBase - Consulta o alcance de um drone.
Parametros:
    d - drone
Retorno: alcance do drone
Precondicoes: d != NULL
***********************************************/
int alcanceDroneBase(drone d);

/***********************************************
capacidadeCargaDroneBase - Consulta a capacidade de carga de um drone.
Parametros:
    d - drone
Retorno: capacidade de carga do drone
Precondicoes: d != NULL
***********************************************/
int capacidadeCargaDroneBase(drone d);

/***********************************************
tamanhoEncomendasBase - consulta o numero de encomendas de uma base dada.
Parametros:
    b - base
Retorno: numero de encomendas
Precondicoes: b != NULL
***********************************************/
int tamanhoEncomendasBase(base b);

/***********************************************
existeDroneBase - verifica se um drone existe na base.
Parametros:
    b - base
    drone - identificador do drone
Retorno: 1 se o drone existe, 0 caso contrario
Precondicoes: b != NULL
***********************************************/
int existeDroneBase(base b, int drone);

/***********************************************
criaIteradorDronesBase - cria um iterador para os drones da base.
Parametros:
    b - base
Retorno: iterador para os drones
Precondicoes: b != NULL
***********************************************/
iterador criaIteradorDronesBase(base b);

/***********************************************
criaIteradorEncomendaBase - cria um iterador para as encomendas da base.
Parametros:
    b - base
Retorno: iterador para as encomendas
Precondicoes: b != NULL
***********************************************/
iterador criaIteradorEncomendaBase(base b);


//----------------------------------------------------
//----------------------------------------------------
//Funções gerais de uso do mainDrones

/***********************************************
criaDroneBase - Cria um drone e adiciona-o à base.
Parametros:
    b - base
    carga - capacidade de carga do drone
    alcance - alcance do drone
    tipo - tipo de drone
Retorno: drone criado
Precondicoes: b != NULL
***********************************************/
drone criaDroneBase(base b, int carga, int alcance, const char *tipo);


/***********************************************
valorIdPrintDroneBase - Consulta o identificador do próximo drone a ser impresso.
Parametros:
    b - base
Retorno: identificador do próximo drone
Precondicoes: b != NULL
***********************************************/
int valorIdPrintDroneBase(base b);

/***********************************************
valorCapPrintDroneBase - Consulta a capacidade de carga do próximo drone a ser impresso.
Parametros:
    b - base
Retorno: capacidade de carga do próximo drone
Precondicoes: b != NULL
***********************************************/
int valorCapPrintDroneBase(base b);

/***********************************************
valorAlcancePrintDroneBase - Consulta o alcance do próximo drone a ser impresso.
Parametros:
    b - base
Retorno: alcance do próximo drone
Precondicoes: b != NULL
***********************************************/
int valorAlcancePrintDroneBase(base b);

/***********************************************
valorVooPrintDroneBase - Consulta o tempo de manutenção do próximo drone a ser impresso.
Parametros:
    b - base
Retorno: tempo de manutenção do próximo drone
Precondicoes: b != NULL
***********************************************/
int valorVooPrintDroneBase(base b);

/***********************************************
adicionarDroneColetivoBase - Adiciona um drone coletivo à base.
Parametros:
    b - base
    verificar - número de drones a verificar
    iddrones - array de identificadores dos drones a serem verificados
Retorno: 1 se o drone coletivo foi adicionado com sucesso, 0 caso contrário
Precondicoes: b != NULL
***********************************************/
int adicionarDroneColetivoBase(base b, int verificar, int * iddrones);


/***********************************************
valoridDroneBase - Consulta o identificador de um drone em uma posição especificada.
Parametros:
    b - base
    pos - posição do drone
Retorno: identificador do drone
Precondicoes: b != NULL
***********************************************/
int valoridDroneBase(base b, int pos);

/***********************************************
valorelementoSequenciaDroneBase - Consulta um elemento de uma sequência de drones.
Parametros:
    b - base
    pos - posição do drone na sequência
Retorno: ponteiro para o elemento na sequência
Precondicoes: b != NULL
***********************************************/
int * valorelementoSequenciaDroneBase(base b, int pos);

/***********************************************
valorcapacidadeDroneBase - Consulta a capacidade de carga de um drone em uma posição especificada.
Parametros:
    b - base
    pos - posição do drone
Retorno: capacidade de carga do drone
Precondicoes: b != NULL
***********************************************/
int valorcapacidadeDroneBase(base b, int pos);

/***********************************************
valoralcanceDroneBase - Consulta o alcance de um drone em uma posição especificada.
Parametros:
    b - base
    pos - posição do drone
Retorno: alcance do drone
Precondicoes: b != NULL
***********************************************/
int valoralcanceDroneBase(base b, int pos);

/***********************************************
valorManuDroneBase - Consulta o tempo de manutenção de um drone em uma posição especificada.
Parametros:
    b - base
    pos - posição do drone
Retorno: tempo de manutenção do drone
Precondicoes: b != NULL
***********************************************/
int valorManuDroneBase(base b, int pos);



/***********************************************
valorprintelementoSequenciaDroneBase - Consulta um elemento da sequência de drones em uma posição especificada.
Parametros:
    b - base
    i - índice da sequência
    j - índice do elemento na sequência
Retorno: ponteiro para o elemento da sequência
Precondicoes: b != NULL
***********************************************/
int * valorprintelementoSequenciaDroneBase(base b, int i, int j);

// ENCOMENDAS

/***********************************************
valorIdEncomendaBase - Consulta o identificador de uma encomenda.
Parametros:
    b - base
    i - identificador da encomenda
Retorno: identificador da encomenda
Precondicoes: b != NULL
***********************************************/
int valorIdEncomendaBase(base b, int i);

/***********************************************
valorPesoEncomendaBase - Consulta o peso de uma encomenda.
Parametros:
    b - base
    i - identificador da encomenda
Retorno: peso da encomenda
Precondicoes: b != NULL
***********************************************/
int valorPesoEncomendaBase(base b, int i);

/***********************************************
valorLatEncomendaBase - Consulta a latitude de uma encomenda.
Parametros:
    b - base
    i - identificador da encomenda
Retorno: latitude da encomenda
Precondicoes: b != NULL
***********************************************/
int valorLatEncomendaBase(base b, int i);

/***********************************************
valorLonEncomendaBase - Consulta a longitude de uma encomenda.
Parametros:
    b - base
    i - identificador da encomenda
Retorno: longitude da encomenda
Precondicoes: b != NULL
***********************************************/
int valorLonEncomendaBase(base b, int i);

/***********************************************
valorCriaEncomendaBase - Consulta o tempo de criação de uma encomenda.
Parametros:
    b - base
    i - identificador da encomenda
Retorno: tempo de criação da encomenda
Precondicoes: b != NULL
***********************************************/
int valorCriaEncomendaBase(base b, int i);

/***********************************************
CriaEncomendaBase - Cria uma nova encomenda e a adiciona à base.
Parametros:
    b - base
    peso - peso da encomenda
    latitude - latitude da encomenda
    longitude - longitude da encomenda
    tempo - tempo de criação da encomenda
Retorno:
Precondicoes: b != NULL
***********************************************/
void CriaEncomendaBase(base b, int peso, int latitude, int longitude, int tempo);

/***********************************************
idValorEncomendaBase - Consulta o identificador da próxima encomenda a ser impressa.
Parametros:
    b - base
Retorno: identificador da próxima encomenda
Precondicoes: b != NULL
***********************************************/
int idValorEncomendaBase(base b);

/***********************************************
pesoValorEncomendaBase - Consulta o peso da próxima encomenda a ser impressa.
Parametros:
    b - base
Retorno: peso da próxima encomenda
Precondicoes: b != NULL
***********************************************/
int pesoValorEncomendaBase(base b);

/***********************************************
latValorEncomendaBase - Consulta a latitude da próxima encomenda a ser impressa.
Parametros:
    b - base
Retorno: latitude da próxima encomenda
Precondicoes: b != NULL
***********************************************/
int latValorEncomendaBase(base b);

/***********************************************
lonValorEncomendaBase - Consulta a longitude da próxima encomenda a ser impressa.
Parametros:
    b - base
Retorno: longitude da próxima encomenda
Precondicoes: b != NULL
***********************************************/
int lonValorEncomendaBase(base b);

/***********************************************
tempoValorEncomendaBase - Consulta o tempo de criação da próxima encomenda a ser impressa.
Parametros:
    b - base
Retorno: tempo de criação da próxima encomenda
Precondicoes: b != NULL
***********************************************/
int tempoValorEncomendaBase(base b);



/***********************************************
estaDroneDisponivelBase - Verifica se um drone não se encontra a realizar, nenhum voo, manutençao, ou acabado de chegar no
                          caso de ser um drone coletivo e não tenha sido destruido. Verifica também se o Drone é capaz de 
                          realizar a entrega.
Parametros:
    b - base
    idDrone - Drone a Verificar 
    idEncomenda - Encomenda a ser entregue 
Retorno: Quando Possível true
         Se não for possível devolve false
Precondicoes: b != NULL
***********************************************/
bool estaDroneDisponivelBase(base b, int idDrone, int idEncomenda);


/***********************************************
despachaEncomendaBase - 
Parametros:
    b - base
    idDrone - id do Drone para Entrega
    idEncomenda - id da Encomenda para Entrega
    tempoAtual - tempo atual do sistema
Retorno: 1 para encomenda a ser entregue  e 0 para quando não for possivel
Precondicoes: b != NULL, idDrone > 0 , idEncomenda > 0, Drone e Encomenda Existe 
***********************************************/
int despachaEncomendaBase(base b, int idDrone, int idEncomenda, int tempoAtual);


/***********************************************
removeDroneBase - Remove um drone especificado por seu identificador da base.
Parametros:
    b - base
    idDrone - identificador do drone a ser removido
Retorno: código de sucesso ou erro
Precondicoes: b != NULL, idDrone > 0
***********************************************/
int removeDroneBase(base b, int idDrone);

/***********************************************
dadroneBase - Recupera um drone da base a partir de sua chave.
Parametros:
    b - base
    ch - chave do drone
Retorno: drone correspondente à chave fornecida
Precondicoes: b != NULL, ch != NULL
***********************************************/
drone dadroneBase(base b, chaveInt ch);

/***********************************************
iteradorDroneBase - Retorna um iterador para percorrer todos os drones da base.
Parametros:
    b - base
Retorno: iterador para drones
Precondicoes: b != NULL
***********************************************/
iterador iteradorDroneBase(base b);

/***********************************************
iteradorEncomendaBase - Retorna um iterador para percorrer todas as encomendas da base.
Parametros:
    b - base
Retorno: iterador para encomendas
Precondicoes: b != NULL
***********************************************/
iterador iteradorEncomendaBase(base b);

#endif /* H_BASE */
