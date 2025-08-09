/*
 * drone.h
 */

#ifndef H_DRONE
#define H_DRONE

#include "TADs/iterador/iterador.h"
#include "TADs/sequencia/sequencia.h"

/* Tipo de dados: drone */
typedef struct _drone *drone;

/* Prototipos das funcoes associadas a um drone */

/***********************************************
criaDrone - Criação da instância da estrutura associada a um drone.
Parametros:
    id - ID do drone
    capacidadeCarga - Capacidade de carga do drone
    distanciaVooMaxima - Distância máxima de voo
    tipo - Tipo do drone
Retorno: apontador para a instância criada
Precondicoes:
***********************************************/
drone criaDrone(int capacidadeCarga, int distanciaVooMaxima, const char *tipo);

/***********************************************
destroiDrone - Liberta a memória ocupada pela instância da estrutura associada ao drone.
Parametros:
    d - drone a destruir
Retorno:
Precondicoes: d != NULL
***********************************************/
void destroiDrone(drone d);

/***********************************************
basicoDrone - Consulta do tipo de um drone.
Parametros:
    d - drone
Retorno: tipo do drone
Precondicoes: d != NULL
***********************************************/
char *basicoDrone(drone d);

/***********************************************
idApontadorDrone - Consulta do apontador do ID de um drone.
Parametros:
    d - drone
Retorno: ID do drone
Precondicoes: d != NULL
***********************************************/
int *idApontadorDrone(drone d);

/***********************************************
idValorDrone - Consulta do valor do ID de um drone.
Parametros:
    d - drone
Retorno: valor do ID do drone
Precondicoes: d != NULL
***********************************************/
int idValorDrone(drone d);

/***********************************************
capacidadeCargaDrone - Consulta da capacidade de carga de um drone.
Parametros:
    d - drone
Retorno: capacidade de carga do drone
Precondicoes: d != NULL
***********************************************/
int capacidadeCargaDrone(drone d);

/***********************************************
alcanceDrone - Consulta da distância máxima de voo de um drone.
Parametros:
    d - drone
Retorno: distância máxima de voo do drone
Precondicoes: d != NULL
***********************************************/
int alcanceDrone(drone d);

/***********************************************
restoVooDrone - Consulta da distância de voo restante de um drone.
Parametros:
    d - drone
Retorno: distância de voo restante do drone
Precondicoes: d != NULL
***********************************************/
int restoVooDrone(drone d);

/***********************************************
restoManutencaoDrone - Verifica se um drone está em manutenção.
Parametros:
    d - drone
Retorno: indicador de manutenção do drone
Precondicoes: d != NULL
***********************************************/
int restoManutencaoDrone(drone d);

/***********************************************
mudaEstadoColetivoDrone - Altera o estado do drone para coletivo.
Parametros:
    d - drone
Retorno:
Precondicoes: d != NULL
***********************************************/
void mudaEstadoColetivoDrone(drone d);

/***********************************************
mudaEstadoBasicoDrone - Altera o estado do drone para basico.
Parametros:
    d - drone
Retorno:
Precondicoes: d != NULL
***********************************************/
void mudaEstadoBasicoDrone(drone d);

/***********************************************
eColetivoDrone - Verifica se um drone faz parte de um coletivo.
Parametros:
    d - drone
Retorno: indicador de coletivo do drone
Precondicoes: d != NULL
***********************************************/
bool eColetivoDrone(drone d);

/***********************************************
consultaColetivosDrone - Consulta dos drones coletivos de um drone.
Parametros:
    d - drone
Retorno: sequência de drones coletivos
Precondicoes: d != NULL
***********************************************/
sequencia consultaColetivosDrone(drone d);

/***********************************************
tamanhoSequenciaColetivosDrone - Consulta do tamanho da sequência de drones coletivos de um drone.
Parametros:
    d - drone
Retorno: tamanho da sequência de drones coletivos
Precondicoes: d != NULL
***********************************************/
int tamanhoSequenciaColetivosDrone(drone d);

/***********************************************
daIdBasicoDoColetivoDrone - Consulta do iterador da sequência de drones coletivos de um drone.
Parametros:
    d - drone
Retorno: iterador da sequência de drones coletivos
Precondicoes: d != NULL
***********************************************/
iterador daIdBasicoDoColetivoDrone(drone d);

/***********************************************
valorelementoSequenciaDrone - Consulta um elemento em uma posição especificada na sequência de drones coletivos de um drone.
Parametros:
    d - drone
    pos - posição do elemento na sequência
Retorno: ponteiro para o elemento na posição especificada
Precondicoes: d != NULL
***********************************************/
int * valorelementoSequenciaDrone(drone d,int pos);

/***********************************************
estaVooDrone - Verifica se o drone está em voo.
Parametros:
d - drone
Retorno: booleano indicando se o drone está em voo
Precondicoes: d != NULL
***********************************************/
bool estaVooDrone(drone d);

/***********************************************
calculaTempoVooDrone - Calcula o tempo de voo necessário para uma determinada distância.
Parametros:
distancia - distância a ser percorrida pelo drone
Retorno: tempo de voo necessário para percorrer a distância especificada
Precondicoes: distancia >= 0
***********************************************/
int calculaTempoVooDrone(int distancia);

/***********************************************
registaTempoVooDrone - Regista o tempo de voo de um drone.
Parametros:
d - drone
tempoVoo - tempo de voo a ser registrado
Retorno: nenhum
Precondicoes: d != NULL e tempoVoo >= 0
***********************************************/
void registaTempoVooDrone(drone d, int tempoVoo);

/***********************************************
registaTempoManutencaoDrone - Regista o tempo de manutenção de um drone.
Parametros:
d - drone
Retorno: nenhum
Precondicoes: d != NULL
***********************************************/
void registaTempoManutencaoDrone(drone d);

/***********************************************
manutencaoDrone - Realiza a manutenção do drone.
Parametros:
d - drone
Retorno: nenhum
Precondicoes: d != NULL
***********************************************/
void manutencaoDrone(drone d);

/***********************************************
datempovooDrone - Obtém o tempo de voo atual do drone.
Parametros:
d - drone
Retorno: tempo de voo atual do drone
Precondicoes: d != NULL
***********************************************/
int datempovooDrone(drone d);

/***********************************************
avancaManutencaoDrone - Avança o estado de manutenção do drone.
Parametros:
d - drone
Retorno: nenhum
Precondicoes: d != NULL
***********************************************/
void avancaManutencaoDrone(drone d);

/***********************************************
avancaVooDrone - Avança o estado de voo do drone.
Parametros:
d - drone
Retorno: nenhum
Precondicoes: d != NULL
***********************************************/
void avancaVooDrone(drone d);

/***********************************************
avancaAlcanceDrone - Avança o alcance do drone.
Parametros:
d - drone
Retorno: nenhum
Precondicoes: d != NULL
***********************************************/
void avancaAlcanceDrone(drone d);

/***********************************************
restoVooAtualDrone - Obtém o tempo restante de voo atual do drone.
Parametros:
d - drone
Retorno: tempo restante de voo do drone
Precondicoes: d != NULL
***********************************************/
int restoVooAtualDrone(drone d);

/***********************************************
entregouencomendaDrone - Verifica se o drone entregou a encomenda.
Parametros:
d - drone
Retorno: booleano indicando se o drone entregou a encomenda
Precondicoes: d != NULL
***********************************************/
bool entregouencomendaDrone(drone d);

/***********************************************
entregueencomendaDrone - Marca a encomenda como entregue pelo drone.
Parametros:
d - drone
Retorno: nenhum
Precondicoes: d != NULL
***********************************************/
void entregueencomendaDrone(drone d);
#endif /* H_DRONE */
