/*
 * drone.c
 */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

#include "TADs/iterador/iterador.h"
#include "TADs/sequencia/sequencia.h"

#include "drone.h"

#define MAX_DRONES 6
#define TEMPO_MANUTENCAO 3

/* Estrutura de dados associada a um drone */
struct _drone {
  char * tipo; // Tipo de drone
  int * id; // ID do drone
  int distanciaVooMaxima; // Distância máxima de voo
  int capacidadeCarga; // Capacidade de carga
  int distanciaVooAtual; // Distância de voo atual
  int tempoEmManutencao; // Indicador de manutenção
  bool emColetivo; // Indicador de coletivo

  sequencia coletivos; // Sequência de drones coletivos

  int tempoEmVoo; // Indicador de voo
  bool entregouencomenda;
};

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
drone criaDrone(int capacidadeCarga, int distanciaVooMaxima,
  const char * tipo) {
  drone d = malloc(sizeof(struct _drone));
  int static iddrone = 1;
  if (d == NULL) {
    return NULL;
  }

  d -> tipo = (char * ) malloc(strlen(tipo) + 1);
  if (d -> tipo == NULL) {
    free(d);
    return NULL;
  }
  strcpy(d -> tipo, tipo);
  d -> id = malloc(sizeof(int));
  if (d -> id == NULL) {
    free(d -> tipo);
    free(d);
    return NULL;
  }
  *(d -> id) = iddrone;
  iddrone++;

  d -> coletivos = criaSequencia(MAX_DRONES, (destroiFun) destroiSeqEElems);

  if (strcmp(tipo, "coletivo") == 0) {
    d -> emColetivo = true;
  } else {
    d -> emColetivo = false;
  }

  if (d -> coletivos == NULL) {
    free(d -> tipo);
    free(d -> id);
    free(d);
    return NULL;
  }

  d -> distanciaVooMaxima = distanciaVooMaxima;
  d -> capacidadeCarga = capacidadeCarga;
  d -> distanciaVooAtual = distanciaVooMaxima;
  d -> tempoEmManutencao = 0;
  d -> entregouencomenda = false;
  return d;
}

/***********************************************
destroiDrone - Liberta a memória ocupada pela instância da estrutura associada ao drone.
Parametros:
    d - drone a destruir
Retorno:
Precondicoes: d != NULL
***********************************************/
void destroiDrone(drone d) {
  free(d -> tipo);
  free(d);
}

/***********************************************
basicoDrone - Consulta do tipo de um drone.
Parametros:
    d - drone
Retorno: tipo do drone
Precondicoes: d != NULL
***********************************************/
char * basicoDrone(drone d) {
  return d -> tipo;
}

/***********************************************
idApontadorDrone - Consulta do apontador do ID de um drone.
Parametros:
    d - drone
Retorno: ID do drone
Precondicoes: d != NULL
***********************************************/
int * idApontadorDrone(drone d) {
  return d -> id;
}

/***********************************************
idValorDrone - Consulta do valor do ID de um drone.
Parametros:
    d - drone
Retorno: valor do ID do drone
Precondicoes: d != NULL
***********************************************/
int idValorDrone(drone d) {
  return * (d -> id);
}

/***********************************************
capacidadeCargaDrone - Consulta da capacidade de carga de um drone.
Parametros:
    d - drone
Retorno: capacidade de carga do drone
Precondicoes: d != NULL
***********************************************/
int capacidadeCargaDrone(drone d) {
  return d -> capacidadeCarga;
}

/***********************************************
alcanceDrone - Consulta da distância máxima de voo de um drone.
Parametros:
    d - drone
Retorno: distância máxima de voo do drone
Precondicoes: d != NULL
***********************************************/
int alcanceDrone(drone d) {
  return d -> distanciaVooMaxima;
}

/***********************************************
restoVooDrone - Consulta da distância de voo restante de um drone.
Parametros:
    d - drone
Retorno: distância de voo restante do drone
Precondicoes: d != NULL
***********************************************/
int restoVooDrone(drone d) {
  return d -> distanciaVooMaxima - d -> distanciaVooAtual;
}

/***********************************************
restoManutencaoDrone - Verifica se um drone está em manutenção.
Parametros:
    d - drone
Retorno: indicador de manutenção do drone
Precondicoes: d != NULL
***********************************************/
int restoManutencaoDrone(drone d) {
  return d -> tempoEmManutencao;
}

/***********************************************
mudaEstadoColetivoDrone - Altera o estado do drone para coletivo.
Parametros:
    d - drone
Retorno:
Precondicoes: d != NULL
***********************************************/
void mudaEstadoColetivoDrone(drone d) {
  d -> emColetivo = true;
}
/***********************************************
mudaEstadoBasicoDrone - Altera o estado do drone para basico.
Parametros:
    d - drone
Retorno:
Precondicoes: d != NULL
***********************************************/
void mudaEstadoBasicoDrone(drone d) {
  d -> emColetivo = false;
}
/***********************************************
eColetivoDrone - Verifica se um drone faz parte de um coletivo.
Parametros:
    d - drone
Retorno: indicador de coletivo do drone
Precondicoes: d != NULL
***********************************************/
bool eColetivoDrone(drone d) {
  return d -> emColetivo;
}

/***********************************************
consultaColetivosDrone - Consulta dos drones coletivos de um drone.
Parametros:
    d - drone
Retorno: sequência de drones coletivos
Precondicoes: d != NULL
***********************************************/
sequencia consultaColetivosDrone(drone d) {
  return d -> coletivos;
}

/***********************************************
tamanhoSequenciaColetivosDrone - Consulta do tamanho da sequência de drones coletivos de um drone.
Parametros:
    d - drone
Retorno: tamanho da sequência de drones coletivos
Precondicoes: d != NULL
***********************************************/
int tamanhoSequenciaColetivosDrone(drone d) {
  return tamanhoSequencia(d -> coletivos);
}

/***********************************************
daIdBasicoDoColetivoDrone - Consulta do iterador da sequência de drones coletivos de um drone.
Parametros:
    d - drone
Retorno: iterador da sequência de drones coletivos
Precondicoes: d != NULL
***********************************************/
iterador daIdBasicoDoColetivoDrone(drone d) {
  return iteradorSequencia(d -> coletivos);
}

/***********************************************
valorelementoSequenciaDrone - Consulta um elemento em uma posição especificada na sequência de drones coletivos de um drone.
Parametros:
    d - drone
    pos - posição do elemento na sequência
Retorno: ponteiro para o elemento na posição especificada
Precondicoes: d != NULL
***********************************************/
int * valorelementoSequenciaDrone(drone d, int pos) {
  return elementoPosSequencia(d -> coletivos, pos);
}

/***********************************************
estaVooDrone - Verifica se o drone está em voo.
Parametros:
d - drone
Retorno: booleano indicando se o drone está em voo
Precondicoes: d != NULL
***********************************************/
bool estaVooDrone(drone d) {
  if (d -> distanciaVooAtual < d -> distanciaVooMaxima) {
    return true;
  }
  return false;
}

/***********************************************
calculaTempoVooDrone - Calcula o tempo de voo necessário para uma determinada distância.
Parametros:
distancia - distância a ser percorrida pelo drone
Retorno: tempo de voo necessário para percorrer a distância especificada
Precondicoes: distancia >= 0
***********************************************/
int calculaTempoVooDrone(int distancia) {

  int distanciaIda = (int) ceil(distancia / 10.0) * 10;
  int distanciaTotal = 2 * distanciaIda;
  int tempoVoo = distanciaTotal / 10;

  return tempoVoo;
}

/***********************************************
registaTempoVooDrone - Regista o tempo de voo de um drone.
Parametros:
d - drone
tempoVoo - tempo de voo a ser registrado
Retorno: nenhum
Precondicoes: d != NULL e tempoVoo >= 0
***********************************************/
void registaTempoVooDrone(drone d, int tempoVoo) {

  d -> tempoEmVoo = tempoVoo;
}

/***********************************************
registaTempoManutencaoDrone - Regista o tempo de manutenção de um drone.
Parametros:
d - drone
Retorno: nenhum
Precondicoes: d != NULL
***********************************************/
void registaTempoManutencaoDrone(drone d) {
  d -> tempoEmManutencao = TEMPO_MANUTENCAO;
}

/***********************************************
manutencaoDrone - Realiza a manutenção do drone.
Parametros:
d - drone
Retorno: nenhum
Precondicoes: d != NULL
***********************************************/
void manutencaoDrone(drone d) {
  d -> tempoEmManutencao = 3;
}

/***********************************************
datempovooDrone - Obtém o tempo de voo atual do drone.
Parametros:
d - drone
Retorno: tempo de voo atual do drone
Precondicoes: d != NULL
***********************************************/
int datempovooDrone(drone d) {
  return d -> tempoEmVoo;
}

/***********************************************
avancaManutencaoDrone - Avança o estado de manutenção do drone.
Parametros:
d - drone
Retorno: nenhum
Precondicoes: d != NULL
***********************************************/
void avancaManutencaoDrone(drone d) {
  d -> tempoEmManutencao -= 1;
  if (d -> tempoEmManutencao == 0)
    d -> distanciaVooAtual = d -> distanciaVooMaxima;
}

/***********************************************
avancaVooDrone - Avança o estado de voo do drone.
Parametros:
d - drone
Retorno: nenhum
Precondicoes: d != NULL
***********************************************/
void avancaVooDrone(drone d) {
  d -> tempoEmVoo -= 1;
  if (d -> tempoEmVoo == 0 && strcmp(basicoDrone(d), "basico") == 0 && d -> emColetivo == false)
    manutencaoDrone(d);
}

/***********************************************
avancaAlcanceDrone - Avança o alcance do drone.
Parametros:
d - drone
Retorno: nenhum
Precondicoes: d != NULL
***********************************************/
void avancaAlcanceDrone(drone d) {
  d -> distanciaVooAtual -= 10;
}

/***********************************************
restoVooAtualDrone - Obtém o tempo restante de voo atual do drone.
Parametros:
d - drone
Retorno: tempo restante de voo do drone
Precondicoes: d != NULL
***********************************************/
int restoVooAtualDrone(drone d) {
  return d -> distanciaVooAtual;
}

/***********************************************
entregouencomendaDrone - Verifica se o drone entregou a encomenda.
Parametros:
d - drone
Retorno: booleano indicando se o drone entregou a encomenda
Precondicoes: d != NULL
***********************************************/
bool entregouencomendaDrone(drone d) {
  return d -> entregouencomenda;
}

/***********************************************
entregueencomendaDrone - Marca a encomenda como entregue pelo drone.
Parametros:
d - drone
Retorno: nenhum
Precondicoes: d != NULL
***********************************************/
void entregueencomendaDrone(drone d) {
  d -> entregouencomenda = true;
}