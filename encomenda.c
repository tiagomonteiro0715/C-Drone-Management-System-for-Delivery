/*
 * encomenda.c
 */

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "encomenda.h"
#include "coordenadas.h"

// Definição da estrutura para armazenar informações da encomenda
struct _encomenda {
  int * id; // Identificador único da encomenda
  int peso; // Peso da encomenda em kg
  coordenadas localizacao; // Localização da encomenda
  int momentoCriacao; // Momento da criação da encomenda
  int momentoSaida; // Momento em que a encomenda sai da base
  int momentoEntrega; // Momento em que a encomenda chega ao destino
  bool emEntrega;
};

// Variável global para gerar IDs únicos para cada encomenda
const int comecaId = 1000; // Começando de 1001, conforme especificado

/***********************************************
criaEncomenda - Criação da instância da estrutura associada a uma encomenda.
Parâmetros:
    id - identificador da encomenda
    peso - peso da encomenda
    lat - latitude da localização da encomenda
    lon - longitude da localização da encomenda
    tempo - momento da criação da encomenda
Retorno: apontador para a instância criada
Precondições:
***********************************************/
encomenda criaEncomenda(int peso, int lat, int lon, int tempo) {
  encomenda e = malloc(sizeof(struct _encomenda));
  static int id = 1001;

  if (e == NULL) {
    return NULL;
  }

  e -> id = malloc(sizeof(int));
  e -> localizacao = criaCoordenadas(lat, lon);
  *(e -> id) = id; // Incrementando o último ID para garantir unicidade
  e -> peso = peso;
  e -> momentoCriacao = tempo; // Assumindo que o relógio do sistema começa em 0
  e -> momentoSaida = 0;
  e -> momentoEntrega = 0;
  e -> emEntrega = false;
  id++;

  return e;
}

/***********************************************
IdApontadorEncomenda - Consulta do apontador do ID de uma encomenda.
Parâmetros:
    e - encomenda
Retorno: ID da encomenda
Precondições: e != NULL
***********************************************/
int * IdApontadorEncomenda(encomenda e) {
  return e -> id;
}

/***********************************************
idValorEncomenda - Consulta do valor do ID de uma encomenda.
Parâmetros:
    e - encomenda
Retorno: valor do ID da encomenda
Precondições: e != NULL
***********************************************/
int idValorEncomenda(encomenda e) {
  return * (e -> id);
}

/***********************************************
latitudeEncomenda - Consulta da latitude de uma encomenda.
Parâmetros:
    e - encomenda
Retorno: latitude da encomenda
Precondições: e != NULL
***********************************************/
int latitudeEncomenda(encomenda e) {
  return latCoordenadas(e -> localizacao);
}

/***********************************************
pesoEncomenda - Consulta do peso de uma encomenda.
Parâmetros:
    e - encomenda
Retorno: peso da encomenda
Precondições: e != NULL
***********************************************/
int pesoEncomenda(encomenda e) {
  return e -> peso;
}

/***********************************************
longitudeEncomenda - Consulta da longitude de uma encomenda.
Parâmetros:
    e - encomenda
Retorno: longitude da encomenda
Precondições: e != NULL
***********************************************/
int longitudeEncomenda(encomenda e) {
  return lonCoordenadas(e -> localizacao);
}

/***********************************************
destroiEncomenda - Liberta a memória ocupada pela instância da estrutura associada à encomenda.
Parâmetros:
    e - encomenda a destruir
Retorno:
Precondições: e != NULL
***********************************************/
void destroiEncomenda(encomenda e) {
  destroiCoordenadas(e -> localizacao);
  free(e);
}

/***********************************************
tempoCriacaoEncomenda - Consulta do momento da criação de uma encomenda.
Parâmetros:
    e - encomenda
Retorno: momento da criação da encomenda
Precondições: e != NULL
***********************************************/
int tempoCriacaoEncomenda(encomenda e) {
  return e -> momentoCriacao;
}

/***********************************************
localizacaoEncomenda - Consulta a localização de uma encomenda dada.
Parametros:
  e - encomenda
Retorno: coordenadas da localização da encomenda
Precondicoes: e != NULL
***********************************************/
coordenadas localizacaoEncomenda(encomenda e) {
  return e -> localizacao;
}

/***********************************************
registarSaida - Registra o tempo de saída de uma encomenda.
Parametros:
  e - encomenda
  tempoSaida - tempo em que a encomenda saiu para entrega
Retorno: código de sucesso ou erro
Precondicoes: e != NULL, tempoSaida >= 0
***********************************************/
int registarSaida(encomenda e, int tempoSaida) {
  e -> momentoSaida = tempoSaida;
  return 1;
}

/***********************************************
registarEntregaEncomenda - Registra o tempo de entrega de uma encomenda.
Parametros:
  e - encomenda
  tempoEntrega - tempo em que a encomenda foi entregue
Retorno: nenhum
Precondicoes: e != NULL, tempoEntrega >= 0
***********************************************/
void registarEntregaEncomenda(encomenda e, int tempoEntrega) {
  e -> momentoEntrega = tempoEntrega;
}

/***********************************************
tempoSaidaEncomenda - Consulta o tempo de saída de uma encomenda.
Parametros:
  e - encomenda
Retorno: tempo de saída da encomenda
Precondicoes: e != NULL
***********************************************/
int tempoSaidaEncomenda(encomenda e);
int tempoSaidaEncomenda(encomenda e) {
  return e -> momentoSaida;
}
/***********************************************
tempoEntregaEncomenda - Consulta o tempo de entrega de uma encomenda.
Parametros:
  e - encomenda
Retorno: tempo de entrega da encomenda
Precondicoes: e != NULL
***********************************************/
int tempoEntregaEncomenda(encomenda e) {
  return e -> momentoEntrega;
}

/***********************************************
emEntregaEncomenda - Marca uma encomenda como estando em entrega.
Parametros:
  e - encomenda
Retorno: nenhum
Precondicoes: e != NULL
***********************************************/
void emEntregaEncomenda(encomenda e) {
  e -> emEntrega = true;
}

/***********************************************
estadoEncomenda - Consulta o estado de uma encomenda (entregue ou não).
Parametros:
  e - encomenda
Retorno: estado da encomenda (true se entregue, false se não entregue)
Precondicoes: e != NULL
***********************************************/
bool estadoEncomenda(encomenda e) {
  return e -> emEntrega;
}