/*
 * sistema.c
 */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "TADs/dicionario/chaveInt.h"
#include "TADs/iterador/iterador.h"
#include "TADs/dicionario/dicionario.h"

#include "coordenadas.h"
#include "encomenda.h"
#include "drone.h"
#include "base.h"
#include "sistema.h"

#define TEMPO_ORIGEM 0

/* Estrutura de dados associada a um sistema */
struct _sistema {
  base b; // A base principal do sistema
  int tempo; // Tempo corrente no sistema
};

/* Implementacao das funcoes associadas a um sistema */

/***********************************************
criaSistema - Criacao da instancia da estrutura associada a um sistema.
Parametros:
Retorno: apontador para a instancia criada
Precondicoes:
***********************************************/
sistema criaSistema() {
  sistema s = malloc(sizeof(struct _sistema));
  if (!s) return NULL;

  // Cria a base principal do sistema
  s -> b = criaBase("FCT", criaCoordenadas(0, 0));
  if (!s -> b) {
    free(s);
    return NULL;
  }

  s -> tempo = TEMPO_ORIGEM; // Define o tempo corrente para a origem
  return s;
}

/***********************************************
destroiSistema - Liberta a memoria ocupada pela instancia da estrutura associada ao sistema.
Parametros:
  s - sistema a destruir
Retorno:
Precondicoes: s != NULL
***********************************************/
void destroiSistema(sistema s) {
  destroiBase(s -> b);
  free(s);
}

/***********************************************
nomeBaseSistema - consulta o nome da base principal no sistema.
Parametros:
  s - sistema
Retorno: nome da base
Precondicoes: s != NULL
***********************************************/
char * nomeBaseSistema(sistema s) {
  return nomeBase(s -> b);
}

/***********************************************
tempoAvancaSistema - avanca o tempo do sistema em n horas.
Parametros:
  s - sistema
  n - numero de horas a avancar
Retorno: tempo corrente atualizado
Precondicoes: s != NULL
***********************************************/
int tempoAvancaSistema(sistema s, int n) {
  for (int i = 0; i < n; i++) {
    avancaUmaHoraBase(s -> b, ++s -> tempo);
  }
  return s -> tempo;
}

/***********************************************
tamanhoDronesSistema - consulta o numero de drones no sistema.
Parametros:
  s - sistema
Retorno: numero de drones
Precondicoes: s != NULL
***********************************************/
int tamanhoDronesSistema(sistema s) {
  return tamanhoDronesBase(s -> b);
}

/***********************************************
acederDronesBaseSistema - consulta o dicionario de drones no sistema.
Parametros:
  s - sistema
Retorno: dicionario de drones
Precondicoes: s != NULL
***********************************************/
dicionario acederDronesBaseSistema(sistema s) {
  return acederDronesBase(s -> b);
}

/***********************************************
tamanhoEncomendasSistema - consulta o numero de encomendas no sistema.
Parametros:
  s - sistema
Retorno: numero de encomendas
Precondicoes: s != NULL
***********************************************/
int tamanhoEncomendasSistema(sistema s) {
  return tamanhoEncomendasBase(s -> b);
}

//MUDAR ISTO PARA DENTRO Do Remover drone
/***********************************************
existeDroneSistema - verifica se um drone existe no sistema.
Parametros:
  s - sistema
  drone - identificador do drone
Retorno: 1 se o drone existe, 0 caso contrario
Precondicoes: s != NULL
***********************************************/
int existeDroneSistema(sistema s, int drone) {
  return existeDroneBase(s -> b, drone);
}

/***********************************************
criaIteradorDronesSistema - cria um iterador para os drones no sistema.
Parametros:
  s - sistema
Retorno: iterador para os drones
Precondicoes: s != NULL
***********************************************/
iterador criaIteradorDronesSistema(sistema s) {
  return criaIteradorDronesBase(s -> b);
}

/***********************************************
criaIteradorEncomendaSistema - cria um iterador para as encomendas no sistema.
Parametros:
  s - sistema
Retorno: iterador para as encomendas
Precondicoes: s != NULL
***********************************************/
iterador criaIteradorEncomendaSistema(sistema s) {
  return criaIteradorEncomendaBase(s -> b);
}

/***********************************************
tempoSistema - consulta o tempo corrente no sistema.
Parametros:
  s - sistema
Retorno: tempo corrente
Precondicoes: s != NULL
***********************************************/
int tempoSistema(sistema s) {
  return s -> tempo;
}

//----------------------------------------------------
//----------------------------------------------------
//Funções gerais de uso do mainDrones

/***********************************************
criaDroneSistema - Cria um drone no sistema e adiciona-o à base principal.
Parametros:
  s - sistema
  carga - capacidade de carga do drone
  alcance - alcance do drone
  tipo - tipo de drone
Retorno: drone criado
Precondicoes: s != NULL
***********************************************/
drone criaDroneSistema(sistema s, int carga, int alcance,
  const char * tipo) {
  return criaDroneBase(s -> b, carga, alcance, tipo);
}

/***********************************************
valorIdPrintDroneSistema - Consulta o identificador do próximo drone a ser impresso no sistema.
Parametros:
  s - sistema
Retorno: identificador do próximo drone
Precondicoes: s != NULL
***********************************************/
int valorIdPrintDroneSistema(sistema s) {
  return valorIdPrintDroneBase(s -> b);
}

/***********************************************
valorCapPrintDroneSistema - Consulta a capacidade de carga do próximo drone a ser impresso no sistema.
Parametros:
  s - sistema
Retorno: capacidade de carga do próximo drone
Precondicoes: s != NULL
***********************************************/
int valorCapPrintDroneSistema(sistema s) {
  return valorCapPrintDroneBase(s -> b);
}

/***********************************************
valorAlcancePrintDroneSistema - Consulta o alcance do próximo drone a ser impresso no sistema.
Parametros:
  s - sistema
Retorno: alcance do próximo drone
Precondicoes: s != NULL
***********************************************/
int valorAlcancePrintDroneSistema(sistema s) {
  return valorAlcancePrintDroneBase(s -> b);
}

/***********************************************
valorVooPrintDroneSistema - Consulta o tempo de manutenção do próximo drone a ser impresso no sistema.
Parametros:
  s - sistema
Retorno: tempo de manutenção do próximo drone
Precondicoes: s != NULL
***********************************************/
int valorVooPrintDroneSistema(sistema s) {
  return valorVooPrintDroneBase(s -> b);
}

/***********************************************
adicionarDroneColetivoSistema - Adiciona um drone coletivo ao sistema.
Parametros:
  s - sistema
  verificar - número de drones a verificar
  iddrones - array de identificadores dos drones a serem verificados
Retorno: 1 se o drone coletivo foi adicionado com sucesso, 0 caso contrário
Precondicoes: s != NULL
***********************************************/
int adicionarDroneColetivoSistema(sistema s, int verificar, int * iddrones) {
  return adicionarDroneColetivoBase(s -> b, verificar, iddrones);
}

/***********************************************
valorelementoSequenciaDroneSistema - Consulta um elemento de uma sequência de drones no sistema.
Parametros:
  s - sistema
  pos - posição do drone na sequência
Retorno: ponteiro para o elemento na sequência
Precondicoes: s != NULL
***********************************************/
int * valorelementoSequenciaDroneSistema(sistema s, int pos) {
  return valorelementoSequenciaDroneBase(s -> b, pos);
}

/***********************************************
valoridDroneSistema - Consulta o identificador de um drone no sistema em uma posição especificada.
Parametros:
  s - sistema
  pos - posição do drone
Retorno: identificador do drone
Precondicoes: s != NULL
***********************************************/
int valoridDroneSistema(sistema s, int pos) {
  return valoridDroneBase(s -> b, pos);
}

/***********************************************
valorcapacidadeDroneSistema - Consulta a capacidade de carga de um drone no sistema em uma posição especificada.
Parametros:
  s - sistema
  pos - posição do drone
Retorno: capacidade de carga do drone
Precondicoes: s != NULL
***********************************************/
int valorcapacidadeDroneSistema(sistema s, int pos) {
  return valorcapacidadeDroneBase(s -> b, pos);
}

/***********************************************
valoralcanceDroneSistema - Consulta o alcance de um drone no sistema em uma posição especificada.
Parametros:
  s - sistema
  pos - posição do drone
Retorno: alcance do drone
Precondicoes: s != NULL
***********************************************/
int valoralcanceDroneSistema(sistema s, int pos) {
  return valoralcanceDroneBase(s -> b, pos);
}

/***********************************************
valorManuDroneSistema - Consulta o tempo de manutenção de um drone no sistema em uma posição especificada.
Parametros:
  s - sistema
  pos - posição do drone
Retorno: tempo de manutenção do drone
Precondicoes: s != NULL
***********************************************/
int valorManuDroneSistema(sistema s, int pos) {
  return valorManuDroneBase(s -> b, pos);
}

/***********************************************
valorIdEncomendaSistema - Consulta o identificador de uma encomenda no sistema.
Parametros:
  s - sistema
  i - identificador da encomenda
Retorno: identificador da encomenda
Precondicoes: s != NULL
***********************************************/
int valorIdEncomendaSistema(sistema s, int i) {
  return valorIdEncomendaBase(s -> b, i + 1001);
}

/***********************************************
valorPesoEncomendaSistema - Consulta o peso de uma encomenda no sistema.
Parametros:
  s - sistema
  i - identificador da encomenda
Retorno: peso da encomenda
Precondicoes: s != NULL
***********************************************/
int valorPesoEncomendaSistema(sistema s, int i) {
  return valorPesoEncomendaBase(s -> b, i + 1001);
}

/***********************************************
valorLatEncomendaSistema - Consulta a latitude de uma encomenda no sistema.
Parametros:
  s - sistema
  i - identificador da encomenda
Retorno: latitude da encomenda
Precondicoes: s != NULL
***********************************************/
int valorLatEncomendaSistema(sistema s, int i) {
  return valorLatEncomendaBase(s -> b, i + 1001);
}

/***********************************************
valorLonEncomendaSistema - Consulta a longitude de uma encomenda no sistema.
Parametros:
  s - sistema
  i - identificador da encomenda
Retorno: longitude da encomenda
Precondicoes: s != NULL
***********************************************/
int valorLonEncomendaSistema(sistema s, int i) {
  return valorLonEncomendaBase(s -> b, i + 1001);
}

/***********************************************
valorCriaEncomendaSistema - Consulta o tempo de criação de uma encomenda no sistema.
Parametros:
  s - sistema
  i - identificador da encomenda
Retorno: tempo de criação da encomenda
Precondicoes: s != NULL
***********************************************/
int valorCriaEncomendaSistema(sistema s, int i) {
  return valorCriaEncomendaBase(s -> b, i + 1001);
}

/***********************************************
CriaEncomendaSistema - Cria uma nova encomenda no sistema e a adiciona à base principal.
Parametros:
  s - sistema
  peso - peso da encomenda
  latitude - latitude da encomenda
  longitude - longitude da encomenda
Retorno:
Precondicoes: s != NULL
***********************************************/
void CriaEncomendaSistema(sistema s, int peso, int latitude, int longitude) {
  CriaEncomendaBase(s -> b, peso, latitude, longitude, s -> tempo);
  return;
}

/***********************************************
idValorEncomendaSistema - Consulta o identificador da próxima encomenda a ser impressa no sistema.
Parametros:
  s - sistema
Retorno: identificador da próxima encomenda
Precondicoes: s != NULL
***********************************************/
int idValorEncomendaSistema(sistema s) {
  return idValorEncomendaBase(s -> b);
}

/***********************************************
pesoValorEncomendaSistema - Consulta o peso da próxima encomenda a ser impressa no sistema.
Parametros:
  s - sistema
Retorno: peso da próxima encomenda
Precondicoes: s != NULL
***********************************************/
int pesoValorEncomendaSistema(sistema s) {
  return pesoValorEncomendaBase(s -> b);
}

/***********************************************
latValorEncomendaSistema - Consulta a latitude da próxima encomenda a ser impressa no sistema.
Parametros:
  s - sistema
Retorno: latitude da próxima encomenda
Precondicoes: s != NULL
***********************************************/
int latValorEncomendaSistema(sistema s) {
  return latValorEncomendaBase(s -> b);
}

/***********************************************
lonValorEncomendaSistema - Consulta a longitude da próxima encomenda a ser impressa no sistema.
Parametros:
  s - sistema
Retorno: longitude da próxima encomenda
Precondicoes: s != NULL
***********************************************/
int lonValorEncomendaSistema(sistema s) {
  return lonValorEncomendaBase(s -> b);
}

/***********************************************
tempoValorEncomendaSistema - Consulta o tempo de criação da próxima encomenda a ser impressa no sistema.
Parametros:
  s - sistema
Retorno: tempo de criação da próxima encomenda
Precondicoes: s != NULL
***********************************************/
int tempoValorEncomendaSistema(sistema s) {
  return tempoValorEncomendaBase(s -> b);
}

/***********************************************
tempoAtualSistema - Consulta o tempo atual do Sistema.
Parametros:
  s - sistema
Retorno: tempo atual
Precondicoes: s != NULL
***********************************************/
int tempoAtualSistema(sistema s) {
  return s -> tempo;
}

/***********************************************
despachaEncomendaSistema - Chama a funcao base responsavel por verificar se a encomenda está em condições de ser enviada
Parametros:
  s - sistema
  idencomenda - encomenda a ser enviada
  iddrone - drone responsavel pelo o envio
Retorno: tempo atual
Precondicoes: s != NULL
***********************************************/
int despachaEncomendaSistema(sistema s, int idencomenda, int iddrone) {
  return despachaEncomendaBase(s -> b, idencomenda, iddrone, s -> tempo);
}

/***********************************************
removeDroneSistema - Chama a funcao da Base responsavel por remover o drone do Sistema
Parametros:
  s - sistema
  iddrone - id do drone a ser removido
Retorno: 1 remove drone 0 não removeu o drone
Precondicoes: s != NULL
***********************************************/
int removeDroneSistema(sistema s, int iddrone) {
  return removeDroneBase(s -> b, iddrone);
}

/***********************************************
dadroneSistema - Chama a funcao para procurar o drone na base a ser printado
Parametros:
  s - sistema
  ch - chave do drone para tirar valores
Retorno: Drone para Printar na Lista
Precondicoes: s != NULL
***********************************************/
drone dadroneSistema(sistema s, chaveInt ch) {
  return dadroneBase(s -> b, ch);
}

/***********************************************
iteradorDroneSistema - Chama a funcao para devolver os iterador contendo todas as chaves ordenadas dos Drones
Parametros:
  s - sistema
Retorno: Iterador com as chaves ordenadas
Precondicoes: s != NULL
***********************************************/
iterador iteradorDroneSistema(sistema s) {
  return iteradorDroneBase(s -> b);
}

/***********************************************
iteradorEncomendaSistema - Chama a funcao para devolver os iterador contendo todas as encomendas
Parametros:
  s - sistema
Retorno: Iterador com encomendas
Precondicoes: s != NULL
***********************************************/
iterador iteradorEncomendaSistema(sistema s) {
  return iteradorEncomendaBase(s -> b);
}