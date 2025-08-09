/*
 * base.c
 */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "TADs/dicionario/chaveInt.h"
#include "TADs/iterador/iterador.h"
#include "TADs/dicionario/dicionario.h"

#include "coordenadas.h"
#include "drone.h"
#include "encomenda.h"
#include "base.h"

#define CAP 100
#define VELOCIDADE_MAXIMA 10

/* Estrutura de dados associada a uma base */
struct _base {
  char * nome;
  coordenadas localizacao;
  dicionario drones;
  dicionario encomendas;
  int proximoId;
  int proximoIdEncomenda;
  int tempo;
};

/* Implementacao das funcoes associadas a uma base */

/***********************************************
criaBase - Criacao da instancia da estrutura associada a uma base.
Parametros:
    nome - nome da base
    localizacao - coordenadas da localizacao da base
Retorno: apontador para a instancia criada
Precondicoes:
***********************************************/
base criaBase(char * nome, coordenadas localizacao) {
  base b = malloc(sizeof(struct _base));
  if (!b) return NULL;
  b -> nome = strcpy(malloc(strlen(nome) + 1), nome);
  b -> localizacao = localizacao;
  b -> drones = criaDicionario(CAP, (comparaFun) comparaChavesInt, (destroiFun) destroiChaveInt, (destroiFun) destroiDrone);
  b -> encomendas = criaDicionario(CAP, (comparaFun) comparaChavesInt, (destroiFun) destroiChaveInt, (destroiFun) destroiEncomenda);
  b -> proximoId = 0;
  b -> proximoIdEncomenda = 1000;
  if (!b -> drones || !b -> encomendas) {
    destroiBase(b);
    return NULL;
  }
  return b;
}

/***********************************************
destroiBase - Liberta a memoria ocupada pela instancia da estrutura associada a base.
Parametros:
    b - base a destruir
Retorno:
Precondicoes: b != NULL
***********************************************/
void destroiBase(base b) {
  if (b) {
    destroiDicEElems(b -> drones);
    destroiDicEElems(b -> encomendas);
    destroiCoordenadas(b -> localizacao);
    free(b -> nome);
    free(b);
  }
}

/***********************************************
nomeBase - consulta o nome de uma base dada.
Parametros:
    b - base
Retorno: nome da base
Precondicoes: b != NULL
***********************************************/
char * nomeBase(base b) {
  return b -> nome;
}

/***********************************************
localizacaoBase - consulta a localizacao de uma base dada.
Parametros:
    b - base
Retorno: coordenadas da localizacao da base
Precondicoes: b != NULL
***********************************************/
coordenadas localizacaoBase(base b) {
  return b -> localizacao;
}

/***********************************************
avancaUmaHoraBase - avanca o tempo de uma base dada.
Parametros:
    b - base
    tempo - tempo a ser avancado
Retorno:
Precondicoes: b != NULL
***********************************************/
void avancaUmaHoraBase(base b, int tempo) {
  iterador it = iteradorDicionario(b -> drones);
  int distanciaencomenda;

  while (temSeguinteIterador(it)) {
    drone d = seguinteIterador(it);

    if (restoManutencaoDrone(d) > 0) {
      avancaManutencaoDrone(d);
    }

    if (datempovooDrone(d) > 0) {
      avancaVooDrone(d);
      avancaAlcanceDrone(d);
    }

  }

  it = iteradorDicionario(b -> encomendas);
  while (temSeguinteIterador(it)) {
    encomenda e = seguinteIterador(it);

    if (estadoEncomenda(e) == true && tempoEntregaEncomenda(e) == 0) {
      distanciaencomenda = distanciaCoordenadas(localizacaoBase(b), localizacaoEncomenda(e), VELOCIDADE_MAXIMA);

      if ((tempo == tempoSaidaEncomenda(e) + (calculaTempoVooDrone(distanciaencomenda) / 2)) == 1) {
        registarEntregaEncomenda(e, tempo);
      }
    }
  }
  destroiIterador(it);
  b -> tempo = tempo;
}
/***********************************************
tamanhoDronesBase - consulta o numero de drones de uma base dada.
Parametros:
    b - base
Retorno: numero de drones
Precondicoes: b != NULL
***********************************************/
int tamanhoDronesBase(base b) {
  return tamanhoDicionario(b -> drones);
}

/***********************************************
acederDronesBase - consulta o dicionario de drones de uma base dada.
Parametros:
    b - base
Retorno: dicionario de drones
Precondicoes: b != NULL
***********************************************/
dicionario acederDronesBase(base b) {
  return b -> drones;
}

/***********************************************
tamanhoEncomendasBase - consulta o numero de encomendas de uma base dada.
Parametros:
    b - base
Retorno: numero de encomendas
Precondicoes: b != NULL
***********************************************/
int tamanhoEncomendasBase(base b) {
  return tamanhoDicionario(b -> encomendas);
}

/***********************************************
existeDroneBase - verifica se um drone existe na base.
Parametros:
    b - base
    drone - identificador do drone
Retorno: 1 se o drone existe, 0 caso contrario
Precondicoes: b != NULL
***********************************************/
int existeDroneBase(base b, int drone) {
  return existeElemDicionario(b -> drones, & drone);
}

/***********************************************
criaIteradorDronesBase - cria um iterador para os drones da base.
Parametros:
    b - base
Retorno: iterador para os drones
Precondicoes: b != NULL
***********************************************/
iterador criaIteradorDronesBase(base b) {
  return iteradorOrdenadoChavesDicionario(b -> drones);
}

/***********************************************
criaIteradorEncomendaBase - cria um iterador para as encomendas da base.
Parametros:
    b - base
Retorno: iterador para as encomendas
Precondicoes: b != NULL
***********************************************/
iterador criaIteradorEncomendaBase(base b) {
  return iteradorDicionario(b -> encomendas);
}

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
drone criaDroneBase(base b, int carga, int alcance,
  const char * tipo) {
  drone d = criaDrone(carga, alcance, tipo);
  adicionaElemDicionario(acederDronesBase(b), idApontadorDrone(d), d);
  b -> proximoId++;
  return d;
}

/***********************************************
alcanceDroneBase - Consulta o alcance de um drone.
Parametros:
    d - drone
Retorno: alcance do drone
Precondicoes: d != NULL
***********************************************/
int alcanceDroneBase(drone d) {
  return alcanceDrone(d);
}
/***********************************************
idValorDroneBase - Consulta o identificador de um drone.
Parametros:
    d - drone
Retorno: identificador do drone
Precondicoes: d != NULL
***********************************************/
int idValorDroneBase(drone d) {
  return idValorDrone(d);
}
/***********************************************
capacidadeCargaDroneBase - Consulta a capacidade de carga de um drone.
Parametros:
    d - drone
Retorno: capacidade de carga do drone
Precondicoes: d != NULL
***********************************************/
int capacidadeCargaDroneBase(drone d) {
  return capacidadeCargaDrone(d);
}

/***********************************************
valorIdPrintDroneBase - Consulta o identificador do próximo drone a ser impresso.
Parametros:
    b - base
Retorno: identificador do próximo drone
Precondicoes: b != NULL
***********************************************/
int valorIdPrintDroneBase(base b) {
  return idValorDroneBase(elementoDicionario(b -> drones, & b -> proximoId));
}

/***********************************************
valorCapPrintDroneBase - Consulta a capacidade de carga do próximo drone a ser impresso.
Parametros:
    b - base
Retorno: capacidade de carga do próximo drone
Precondicoes: b != NULL
***********************************************/
int valorCapPrintDroneBase(base b) {
  return capacidadeCargaDroneBase(elementoDicionario(b -> drones, & b -> proximoId));
}

/***********************************************
valorAlcancePrintDroneBase - Consulta o alcance do próximo drone a ser impresso.
Parametros:
    b - base
Retorno: alcance do próximo drone
Precondicoes: b != NULL
***********************************************/
int valorAlcancePrintDroneBase(base b) {
  return alcanceDroneBase(elementoDicionario(b -> drones, & b -> proximoId));
}

/***********************************************
valorVooPrintDroneBase - Consulta o tempo de manutenção do próximo drone a ser impresso.
Parametros:
    b - base
Retorno: tempo de manutenção do próximo drone
Precondicoes: b != NULL
***********************************************/
int valorVooPrintDroneBase(base b) {
  return restoManutencaoDrone(elementoDicionario(b -> drones, & b -> proximoId));
}

/***********************************************
adicionarDroneColetivoBase - Adiciona um drone coletivo à base.
Parametros:
    b - base
    verificar - número de drones a verificar
    iddrones - array de identificadores dos drones a serem verificados
Retorno: 1 se o drone coletivo foi adicionado com sucesso, 0 caso contrário
Precondicoes: b != NULL
***********************************************/
int adicionarDroneColetivoBase(base b, int verificar, int * iddrones) {
  int i = 0, j = 0, resultado = 0, alcanceMinimo = 0, alcanceAtual, cargaTotal = 0;
  int limpadrones[6];
  drone d, dronecoletivo;
  const char coletivo[] = "coletivo";

  for (i = 0; i < 6; i++) {
    limpadrones[i] = 0;
  }

  for (i = 0; i < verificar; i++) {
    if (existeElemDicionario(b -> drones, & iddrones[i])) {
      d = elementoDicionario(b -> drones, & iddrones[i]);
      if (eColetivoDrone(d) == true || datempovooDrone(d) > 0 || restoManutencaoDrone(d) > 0) {
        resultado = 0;
        i = verificar;
      } else {
        alcanceAtual = alcanceDrone(d);
        cargaTotal += capacidadeCargaDrone(d);
        if (alcanceAtual < alcanceMinimo || (alcanceMinimo == 0 && i == 0)) {
          alcanceMinimo = alcanceAtual;
        }
        mudaEstadoColetivoDrone(elementoDicionario(b -> drones, & iddrones[i]));
        limpadrones[j++] = iddrones[i];
        resultado = 1;
      }
    } else {
      i = verificar;
      resultado = 0;
    }
  }

  if (i <= verificar || verificar == 0) {
    dronecoletivo = criaDrone(cargaTotal, alcanceMinimo, coletivo);

    for (i = 0; i < verificar; i++) {
      d = elementoDicionario(b -> drones, & iddrones[i]);
      adicionaPosSequencia(consultaColetivosDrone(dronecoletivo), idApontadorDrone(d), i);
    }
    adicionaElemDicionario(b -> drones, idApontadorDrone(dronecoletivo), dronecoletivo);
    b -> proximoId++;
    resultado = 1;
  } else {
    for (i = 0; i < j; i++) {
      if (existeElemDicionario(b -> drones, & limpadrones[i]) == 1)
        mudaEstadoBasicoDrone(elementoDicionario(b -> drones, & limpadrones[i]));
      resultado = 0;
    }
  }
  return resultado;
}

/***********************************************
valorelementoSequenciaDroneBase - Consulta um elemento de uma sequência de drones.
Parametros:
    b - base
    pos - posição do drone na sequência
Retorno: ponteiro para o elemento na sequência
Precondicoes: b != NULL
***********************************************/
int * valorelementoSequenciaDroneBase(base b, int pos) {
  return valorelementoSequenciaDrone(elementoDicionario(b -> drones, & b -> proximoId), pos);
}

/***********************************************
valoridDroneBase - Consulta o identificador de um drone em uma posição especificada.
Parametros:
    b - base
    pos - posição do drone
Retorno: identificador do drone
Precondicoes: b != NULL
***********************************************/
int valoridDroneBase(base b, int pos) {
  iterador it = iteradorOrdenadoChavesDicionario(b -> drones);
  chaveInt * ch;
  for (int i = 0; i <= pos; i++)
    ch = seguinteIterador(it);

  destroiIterador(it);

  return idValorDroneBase(elementoDicionario(b -> drones, ch));
}

/***********************************************
valorcapacidadeDroneBase - Consulta a capacidade de carga de um drone em uma posição especificada.
Parametros:
    b - base
    pos - posição do drone
Retorno: capacidade de carga do drone
Precondicoes: b != NULL
***********************************************/
int valorcapacidadeDroneBase(base b, int pos) {
  iterador it = iteradorOrdenadoChavesDicionario(b -> drones);
  chaveInt * ch;
  for (int i = 0; i <= pos; i++)
    ch = seguinteIterador(it);

  destroiIterador(it);

  return capacidadeCargaDrone(elementoDicionario(b -> drones, ch));
}

/***********************************************
valoralcanceDroneBase - Consulta o alcance de um drone em uma posição especificada.
Parametros:
    b - base
    pos - posição do drone
Retorno: alcance do drone
Precondicoes: b != NULL
***********************************************/
int valoralcanceDroneBase(base b, int pos) {
  iterador it = iteradorOrdenadoChavesDicionario(b -> drones);
  chaveInt * ch;
  for (int i = 0; i <= pos; i++)
    ch = seguinteIterador(it);

  destroiIterador(it);

  return alcanceDrone(elementoDicionario(b -> drones, ch));
}

/***********************************************
valorManuDroneBase - Consulta o tempo de manutenção de um drone em uma posição especificada.
Parametros:
    b - base
    pos - posição do drone
Retorno: tempo de manutenção do drone
Precondicoes: b != NULL
***********************************************/
int valorManuDroneBase(base b, int pos) {
  iterador it = iteradorOrdenadoChavesDicionario(b -> drones);
  chaveInt * ch;
  for (int i = 0; i <= pos; i++)
    ch = seguinteIterador(it);

  destroiIterador(it);

  return restoManutencaoDrone(elementoDicionario(b -> drones, ch));
}

/***********************************************
valorprintelementoSequenciaDroneBase - Consulta um elemento da sequência de drones em uma posição especificada.
Parametros:
    b - base
    i - índice da sequência
    j - índice do elemento na sequência
Retorno: ponteiro para o elemento da sequência
Precondicoes: b != NULL
***********************************************/
int * valorprintelementoSequenciaDroneBase(base b, int i, int j) {
  iterador it = iteradorOrdenadoChavesDicionario(b -> drones);
  chaveInt * ch;
  for (int k = 0; k <= i; k++) {
    ch = seguinteIterador(it);
  }

  destroiIterador(it);

  return valorelementoSequenciaDrone(elementoDicionario(b -> drones, ch), j);
}

// ENCOMENDAS

/***********************************************
valorIdEncomendaBase - Consulta o identificador de uma encomenda.
Parametros:
    b - base
    i - identificador da encomenda
Retorno: identificador da encomenda
Precondicoes: b != NULL
***********************************************/
int valorIdEncomendaBase(base b, int i) {
  return idValorEncomenda(elementoDicionario(b -> encomendas, & i));
}

/***********************************************
valorPesoEncomendaBase - Consulta o peso de uma encomenda.
Parametros:
    b - base
    i - identificador da encomenda
Retorno: peso da encomenda
Precondicoes: b != NULL
***********************************************/
int valorPesoEncomendaBase(base b, int i) {
  return pesoEncomenda(elementoDicionario(b -> encomendas, & i));
}

/***********************************************
valorLatEncomendaBase - Consulta a latitude de uma encomenda.
Parametros:
    b - base
    i - identificador da encomenda
Retorno: latitude da encomenda
Precondicoes: b != NULL
***********************************************/
int valorLatEncomendaBase(base b, int i) {
  return latitudeEncomenda(elementoDicionario(b -> encomendas, & i));
}

/***********************************************
valorLonEncomendaBase - Consulta a longitude de uma encomenda.
Parametros:
    b - base
    i - identificador da encomenda
Retorno: longitude da encomenda
Precondicoes: b != NULL
***********************************************/
int valorLonEncomendaBase(base b, int i) {
  return longitudeEncomenda(elementoDicionario(b -> encomendas, & i));
}

/***********************************************
valorCriaEncomendaBase - Consulta o tempo de criação de uma encomenda.
Parametros:
    b - base
    i - identificador da encomenda
Retorno: tempo de criação da encomenda
Precondicoes: b != NULL
***********************************************/
int valorCriaEncomendaBase(base b, int i) {
  return tempoCriacaoEncomenda(elementoDicionario(b -> encomendas, & i));
}

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
void CriaEncomendaBase(base b, int peso, int latitude, int longitude, int tempo) {
  encomenda e = criaEncomenda(peso, latitude, longitude, tempo);
  adicionaElemDicionario(b -> encomendas, IdApontadorEncomenda(e), e);
  b -> proximoIdEncomenda++;
  return;
}

/***********************************************
idValorEncomendaBase - Consulta o identificador da próxima encomenda a ser impressa.
Parametros:
    b - base
Retorno: identificador da próxima encomenda
Precondicoes: b != NULL
***********************************************/
int idValorEncomendaBase(base b) {
  return idValorEncomenda(elementoDicionario(b -> encomendas, & b -> proximoIdEncomenda));
}

/***********************************************
pesoValorEncomendaBase - Consulta o peso da próxima encomenda a ser impressa.
Parametros:
    b - base
Retorno: peso da próxima encomenda
Precondicoes: b != NULL
***********************************************/
int pesoValorEncomendaBase(base b) {
  return pesoEncomenda(elementoDicionario(b -> encomendas, & b -> proximoIdEncomenda));
}

/***********************************************
latValorEncomendaBase - Consulta a latitude da próxima encomenda a ser impressa.
Parametros:
    b - base
Retorno: latitude da próxima encomenda
Precondicoes: b != NULL
***********************************************/
int latValorEncomendaBase(base b) {
  return latitudeEncomenda(elementoDicionario(b -> encomendas, & b -> proximoIdEncomenda));
}

/***********************************************
lonValorEncomendaBase - Consulta a longitude da próxima encomenda a ser impressa.
Parametros:
    b - base
Retorno: longitude da próxima encomenda
Precondicoes: b != NULL
***********************************************/
int lonValorEncomendaBase(base b) {
  return longitudeEncomenda(elementoDicionario(b -> encomendas, & b -> proximoIdEncomenda));
}

/***********************************************
tempoValorEncomendaBase - Consulta o tempo de criação da próxima encomenda a ser impressa.
Parametros:
    b - base
Retorno: tempo de criação da próxima encomenda
Precondicoes: b != NULL
***********************************************/
int tempoValorEncomendaBase(base b) {
  return tempoCriacaoEncomenda(elementoDicionario(b -> encomendas, & b -> proximoIdEncomenda));
}

//Comando D
/***********************************************
estaDroneDisponivelBase - Verifica se o Drone se encontra disponivel para realizar entrega de encomendas
Parametros:
    b - base
    idDrone - Drone a Enviar a Encomenda 
    idEncomenda - Encomenda a ser enviada pelo drone
Retorno: true se poder e false quando não pode
Precondicoes: b != NULL
***********************************************/
bool estaDroneDisponivelBase(base b, int idDrone, int idEncomenda) {

  drone d = elementoDicionario(b -> drones, & idDrone);
  encomenda e = elementoDicionario(b -> encomendas, & idEncomenda);
  int distanciaEncomenda = distanciaCoordenadas(localizacaoBase(b), localizacaoEncomenda(e), VELOCIDADE_MAXIMA);

  if (eColetivoDrone(d) == false && estadoEncomenda(e) == false) { //Se for drone basico
    if ((estaVooDrone(d) == false) && (pesoEncomenda(e) <= capacidadeCargaDrone(d)) && (restoManutencaoDrone(d) == 0) && (alcanceDrone(d) >= distanciaEncomenda)) {
      return true;
    } else {
      return false;
    }
  }

  if (eColetivoDrone(d) == true && strcmp(basicoDrone(d), "coletivo") == 0 && estadoEncomenda(e) == false && entregouencomendaDrone(d) == false) { //Se for drone coletivo
    if ((estaVooDrone(d) == false) && (alcanceDrone(d) >= distanciaEncomenda) && (pesoEncomenda(e) <= capacidadeCargaDrone(d))) {
      return true;
    } else {
      return false;
    }
  }

  return false; //Se nem for drone basico nem drone coletivo
}

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
int despachaEncomendaBase(base b, int idEncomenda, int idDrone, int tempoAtual) {

  if (existeElemDicionario(b -> drones, & idDrone) == 0 || existeElemDicionario(b -> encomendas, & idEncomenda) == 0)
    return 0;

  drone d = elementoDicionario(b -> drones, & idDrone);
  encomenda e = elementoDicionario(b -> encomendas, & idEncomenda);

  int distanciaEncomenda = distanciaCoordenadas(localizacaoBase(b), localizacaoEncomenda(e), VELOCIDADE_MAXIMA);

  if (estaDroneDisponivelBase(b, idDrone, idEncomenda) == true) {
    if (alcanceDrone(d) >= distanciaEncomenda * 2 && capacidadeCargaDrone(d) >= pesoEncomenda(e)) {
      registarSaida(e, tempoAtual);
      if (strcmp(basicoDrone(d), "coletivo") == 0) {
        for (int i = 0; i < tamanhoSequenciaColetivosDrone(d); i++) {
          drone d2 = elementoDicionario(b -> drones, valorelementoSequenciaDrone(d, i));
          registaTempoVooDrone(d2, calculaTempoVooDrone(distanciaEncomenda));
        }
      }
      if (distanciaEncomenda == 0) {

        registarEntregaEncomenda(e, b -> tempo);
        if (strcmp(basicoDrone(d), "basico") == 0)
          manutencaoDrone(d);
        else
          entregueencomendaDrone(d);
      }
      registaTempoVooDrone(d, calculaTempoVooDrone(distanciaEncomenda));
      emEntregaEncomenda(e);
      return 1;
    }
  }
  return 0;
}

/***********************************************
removeDroneBase - Remove um drone especificado por seu identificador da base.
Parametros:
    b - base
    idDrone - identificador do drone a ser removido
Retorno: código de sucesso ou erro
Precondicoes: b != NULL, idDrone > 0
***********************************************/
int removeDroneBase(base b, int idDrone) {
  drone d = elementoDicionario(b -> drones, & idDrone);

  if (eColetivoDrone(d) == false) { //Se for basico
    if ((datempovooDrone(d) >= false) && (restoManutencaoDrone(d) == 0) && (restoVooDrone(d) == 0)) {
      removeElemDicionario(b -> drones, & idDrone);
      return 1;
    }
  }

  if (eColetivoDrone(d) == true && strcmp(basicoDrone(d), "coletivo") == 0 && (datempovooDrone(d) == 0)) { //Se for coletivo

    //Colocar drones individuais em manutenção
    for (int i = 0; i < tamanhoSequenciaColetivosDrone(d); i++) {
      drone d2 = elementoDicionario(b -> drones, valorelementoSequenciaDrone(d, i));
      registaTempoManutencaoDrone(d2);
      mudaEstadoBasicoDrone(d2);
    }

    removeElemDicionario(b -> drones, & idDrone);
    return 1;
  }
  return 0;
}

/***********************************************
dadroneBase - Recupera um drone da base a partir de sua chave.
Parametros:
    b - base
    ch - chave do drone
Retorno: drone correspondente à chave fornecida
Precondicoes: b != NULL, ch != NULL
***********************************************/
drone dadroneBase(base b, chaveInt ch) {
  return elementoDicionario(b -> drones, ch);
}

/***********************************************
iteradorDroneBase - Retorna um iterador para percorrer todos os drones da base.
Parametros:
    b - base
Retorno: iterador para drones
Precondicoes: b != NULL
***********************************************/
iterador iteradorDroneBase(base b) {
  return iteradorOrdenadoChavesDicionario(b -> drones);
}

/***********************************************
iteradorEncomendaBase - Retorna um iterador para percorrer todas as encomendas da base.
Parametros:
    b - base
Retorno: iterador para encomendas
Precondicoes: b != NULL
***********************************************/
iterador iteradorEncomendaBase(base b) {
  return iteradorDicionario(b -> encomendas);
}