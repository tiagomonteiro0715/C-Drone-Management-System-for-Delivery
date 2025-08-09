/*
 * encomenda.h
 */

#ifndef H_ENCOMENDA
#define H_ENCOMENDA

#include "coordenadas.h"


/* Tipo de dados: encomenda */
typedef struct _encomenda * encomenda;

/* Prototipos das funcoes associadas a uma encomenda */

/***********************************************
criaEncomenda - Criacao da instancia da estrutura associada a uma encomenda.
Parametros:
	id - id único da encomenda
	peso - peso da encomenda em kg
	lat - latitude da localização da encomenda
	lon - longitude da localização da encomenda
	tempo - momento da criação da encomenda
Retorno: apontador para a instancia criada
Precondicoes:
***********************************************/
encomenda criaEncomenda( int peso, int lat, int lon, int tempo);

/***********************************************
IdApontadorEncomenda - Consulta do apontador do ID de uma encomenda.
Parametros:
	e - encomenda
Retorno: id da encomenda
Precondicoes: e != NULL
***********************************************/
int * IdApontadorEncomenda(encomenda e);

/***********************************************
idValorEncomenda - consulta do valor do id de uma encomenda dada.
Parametros:
	e - encomenda
Retorno: valor do id da encomenda
Precondicoes: e != NULL
***********************************************/
int idValorEncomenda(encomenda e);

/***********************************************
latitudeEncomenda - consulta da latitude de uma encomenda dada.
Parametros:
	e - encomenda
Retorno: latitude da localização da encomenda
Precondicoes: e != NULL
***********************************************/
int latitudeEncomenda(encomenda e);

/***********************************************
pesoEncomenda - consulta do peso de uma encomenda dada.
Parametros:
	e - encomenda
Retorno: peso da encomenda
Precondicoes: e != NULL
***********************************************/
int pesoEncomenda(encomenda e);

/***********************************************
longitudeEncomenda - consulta da longitude de uma encomenda dada.
Parametros:
	e - encomenda
Retorno: longitude da localização da encomenda
Precondicoes: e != NULL
***********************************************/
int longitudeEncomenda(encomenda e);

/***********************************************
destroiEncomenda - Liberta a memoria ocupada pela instancia da estrutura associada a encomenda.
Parametros:
	e - encomenda a destruir
Retorno:
Precondicoes: e != NULL
***********************************************/
void destroiEncomenda(encomenda e);

/***********************************************
tempoCriacaoEncomenda - consulta do momento da criação de uma encomenda dada.
Parametros:
	e - encomenda
Retorno: momento da criação da encomenda
Precondicoes: e != NULL
***********************************************/
int tempoCriacaoEncomenda(encomenda e);

/***********************************************
localizacaoEncomenda - Consulta a localização de uma encomenda dada.
Parametros:
  e - encomenda
Retorno: coordenadas da localização da encomenda
Precondicoes: e != NULL
***********************************************/
coordenadas localizacaoEncomenda(encomenda e);

/***********************************************
registarSaida - Registra o tempo de saída de uma encomenda.
Parametros:
  e - encomenda
  tempoSaida - tempo em que a encomenda saiu para entrega
Retorno: código de sucesso ou erro
Precondicoes: e != NULL, tempoSaida >= 0
***********************************************/
int registarSaida(encomenda e, int tempoSaida);

/***********************************************
tempoSaidaEncomenda - Consulta o tempo de saída de uma encomenda.
Parametros:
  e - encomenda
Retorno: tempo de saída da encomenda
Precondicoes: e != NULL
***********************************************/
int tempoSaidaEncomenda(encomenda e);

/***********************************************
tempoEntregaEncomenda - Consulta o tempo de entrega de uma encomenda.
Parametros:
  e - encomenda
Retorno: tempo de entrega da encomenda
Precondicoes: e != NULL
***********************************************/
int tempoEntregaEncomenda(encomenda e);

/***********************************************
registarEntregaEncomenda - Registra o tempo de entrega de uma encomenda.
Parametros:
  e - encomenda
  tempoEntrega - tempo em que a encomenda foi entregue
Retorno: nenhum
Precondicoes: e != NULL, tempoEntrega >= 0
***********************************************/
void registarEntregaEncomenda(encomenda e, int tempoEntrega);

/***********************************************
estadoEncomenda - Consulta o estado de uma encomenda (entregue ou não).
Parametros:
  e - encomenda
Retorno: estado da encomenda (true se entregue, false se não entregue)
Precondicoes: e != NULL
***********************************************/
bool estadoEncomenda(encomenda e);

/***********************************************
emEntregaEncomenda - Marca uma encomenda como estando em entrega.
Parametros:
  e - encomenda
Retorno: nenhum
Precondicoes: e != NULL
***********************************************/
void emEntregaEncomenda(encomenda e);
#endif /* H_ENCOMENDA */
