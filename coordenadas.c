/*
 * coordenadas.c
 */

#include <stdlib.h>
#include <math.h>

#include "coordenadas.h"

/* Estrutura de dados associada a coordenadas */
struct _coordenadas {
  int lat;
  int lon;
};

/* Implementacao das funcoes associadas a coordenadas */

/***********************************************
criaCoordenadas - Criacao da instancia da estrutura associada a coordenadas.
Parametros:
    lat - latitude das coordenadas
    lon - longitude das coordenadas
Retorno: apontador para a instancia criada
Precondicoes:
***********************************************/
coordenadas criaCoordenadas(int lat, int lon) {
  coordenadas c = malloc(sizeof(struct _coordenadas));
  if (c == NULL)
    return NULL;
  c -> lat = lat;
  c -> lon = lon;
  return c;
}

/***********************************************
destroiCoordenadas - Liberta a memoria ocupada pela instancia da estrutura associada as coordenadas.
Parametros:
    c - coordenadas a destruir
Retorno:
Precondicoes: c != NULL
***********************************************/
void destroiCoordenadas(coordenadas c) {
  free(c);
}

/***********************************************
latCoordenadas - consulta da latitude de uma coordenada dada.
Parametros:
    c - coordenadas
Retorno: latitude das coordenadas
Precondicoes: c != NULL
***********************************************/
int latCoordenadas(coordenadas c) {
  return c -> lat;
}

/***********************************************
lonCoordenadas - consulta da longitude de uma coordenada dada.
Parametros:
    c - coordenadas
Retorno: longitude das coordenadas
Precondicoes: c != NULL
***********************************************/
int lonCoordenadas(coordenadas c) {
  return c -> lon;
}

/***********************************************
distanciaCoordenadas - calcula a distancia entre duas coordenadas dadas.
Parametros:
    c1 - coordenadas
    c2 - coordenadas
    velocidade - velocidade do deslocamento
Retorno: distancia ajustada pela velocidade entre as coordenadas c1 e c2
Precondicoes: c1 != NULL && c2 != NULL
***********************************************/
int distanciaCoordenadas(coordenadas c1, coordenadas c2, int velocidade) {
  int dLat = c1 -> lat - c2 -> lat;
  int dLon = c1 -> lon - c2 -> lon;
  int dist = ceil(sqrt(dLat * dLat + dLon * dLon));
  return ((dist + velocidade - 1) / velocidade) * velocidade;
}