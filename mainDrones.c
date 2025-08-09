/*
 * main.c
 */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#include "TADs/iterador/iterador.h"
#include "TADs/dicionario/dicionario.h"
#include "TADs/dicionario/chaveInt.h"

#include "drone.h"
#include "encomenda.h"
#include "base.h"
#include "sistema.h"

#define MAX_LINHA 80
#define MAX_DRONES 6

/* Função que imprime uma mensagem de dados inválidos */
void invalido(void) {
  printf("Dados invalidos\n");
}

/* Função que imprime uma mensagem de ação proibida */
void proibido(void) {
  printf("Nao pode fazer isso\n");
}

/***********************************************
cmdTempoAvanca - Avança o tempo do sistema em um determinado número de horas.
Parametros:
  s - sistema
  linha - linha de comando contendo as horas a avançar
Retorno:
Precondicoes:
***********************************************/
void cmdTempoAvanca(sistema s, char * linha) {
  char ignorar;
  int horas, extra;
  if (sscanf(linha, "%c %d %d", & ignorar, & horas, & extra) != 2) {
    invalido();
    return;
  }
  if (horas >= 0) {
    horas = tempoAvancaSistema(s, horas);
    printf("O novo tempo e' %d\n", horas);
  } else {
    invalido();
  }
}

/***********************************************
cmdCriaDroneBasico - Cria um novo drone básico e adiciona ao sistema.
Parametros:
  s - sistema
  linha - linha de comando contendo os parâmetros do drone
Retorno:
Precondicoes:
***********************************************/
void cmdCriaDroneBasico(sistema s, char * linha) {
  int carga, alcance, limite;
  const char basico[] = "basico";

  if (sscanf(linha, "%*c %d %d %d", & carga, & alcance, & limite) != 2 || carga < 0 || alcance < 0) {
    invalido();
    return;
  }

  if (criaDroneSistema(s, carga, alcance, basico) != NULL)
    printf("Adicionado drone(cat=%s, id=%d, cap=%d, alc=%d/%d, voo=0, manut=%d)\n",
      basico, valorIdPrintDroneSistema(s), valorCapPrintDroneSistema(s),
      valorAlcancePrintDroneSistema(s), valorAlcancePrintDroneSistema(s), valorVooPrintDroneSistema(s));
  else
    proibido();
}

/***********************************************
cmdCriaDroneColetivo - Cria um novo drone coletivo a partir de drones existentes e adiciona ao sistema.
Parametros:
  s - sistema
  linha - linha de comando contendo os IDs dos drones a combinar
Retorno:
Precondicoes:
***********************************************/
void cmdCriaDroneColetivo(sistema s, char * linha) {

  int verificar, i, limite;
  int iddrones[MAX_DRONES];

  verificar = sscanf(linha, "%*c %d %d %d %d %d %d %d", & iddrones[0], & iddrones[1], & iddrones[2], & iddrones[3], & iddrones[4], & iddrones[5], & limite);
  for (i = 0; i < verificar; i++) {
    if (iddrones[i] < 0) {
      verificar = 7;
    }
  }

  if (verificar == 7) { //Argumentos para além do Limite
    invalido();
    return;
  }
  if (verificar == -1)
    verificar = 0;

  // Valores > 0 e Verificar dentro do Esperado entre -1 e 6
  if (adicionarDroneColetivoSistema(s, verificar, iddrones) == 1) {
    printf("Adicionado drone(cat=%s, id=%d, cap=%d, alc=%d/%d, voo=0, manut=%d, elems=(",
      "coletivo",
      valorIdPrintDroneSistema(s),
      valorCapPrintDroneSistema(s),
      valorAlcancePrintDroneSistema(s),
      valorAlcancePrintDroneSistema(s),
      valorVooPrintDroneSistema(s));
    for (i = 0; i < verificar - 1; i++) {
      printf("%d ", * valorelementoSequenciaDroneSistema(s, i));
    }
    if (verificar != 0)
      printf("%d", * valorelementoSequenciaDroneSistema(s, i));
    printf("))\n");
  } else {
    proibido();
  }
}

/***********************************************
cmdDespachaEncomenda - Despacha uma encomenda usando um drone específico.
Parametros:
  s - sistema
  linha - linha de comando contendo o ID da encomenda e do drone
Retorno:
Precondicoes:
***********************************************/
void cmdDespachaEncomenda(sistema s, char * linha) {
  int idencomenda, iddrone, limite;

  if (sscanf(linha, "%*c %d %d %d", & idencomenda, & iddrone, & limite) != 2)
    invalido();
  else {
    if (idencomenda < 0 || iddrone < 0)
      invalido();
    else {
      if (despachaEncomendaSistema(s, idencomenda, iddrone) == 1) {

        printf("Encomenda %d enviada pelo drone %d\n",
          idencomenda,
          iddrone
        );

      } else {
        proibido();
      }
    }
  }
}

/***********************************************
cmdCriaEncomenda - Cria uma nova encomenda e adiciona ao sistema.
Parametros:
  s - sistema
  linha - linha de comando contendo os parâmetros da encomenda
Retorno:
Precondicoes:
***********************************************/
void cmdCriaEncomenda(sistema s, char * linha) {
  int peso, latitude, longitude, limite;

  if (sscanf(linha, "%*c %d %d %d %d", & peso, & latitude, & longitude, & limite) != 3)
    invalido();
  else if (peso < 0) {
    invalido();
  } else {

    CriaEncomendaSistema(s, peso, latitude, longitude);

    printf("Adicionada encomenda(id=%d, peso=%d, coord=(%d,%d), cria=%d, saida=0, entrega=0)\n",
      idValorEncomendaSistema(s),
      pesoValorEncomendaSistema(s),
      latValorEncomendaSistema(s),
      lonValorEncomendaSistema(s),
      tempoValorEncomendaSistema(s)
    );
  }
}

/***********************************************
cmdLista - Lista todos os drones e encomendas presentes no sistema.
Parametros:
  s - sistema
  linha - linha de comando
Retorno:
Precondicoes:
***********************************************/
void cmdLista(sistema s, char * linha) {
  int ignora, j, i = 0;
  chaveInt ch;
  if (sscanf(linha, "%*c %d", & ignora) != -1) {
    invalido();
    return;
  }

  //  Lista Drones
  iterador it = iteradorDroneSistema(s);
  while (temSeguinteIterador(it)) {
    ch = seguinteIterador(it);
    drone d = dadroneSistema(s, ch);
    //Listagem Drone Básico
    i++;
    if (strcmp(basicoDrone(d), "basico") == 0) {
      printf("drone(cat=%s, id=%d, cap=%d, alc=%d/%d, voo=%d, manut=%d)\n",
        basicoDrone(d),
        idValorDrone(d),
        capacidadeCargaDrone(d),
        restoVooAtualDrone(d),
        alcanceDrone(d),
        datempovooDrone(d),
        restoManutencaoDrone(d)
      );

    } else {
      //Listagem Drone Coletivo
      if (strcmp(basicoDrone(d), "coletivo") == 0) {
        printf("drone(cat=%s, id=%d, cap=%d, alc=%d/%d, voo=%d, manut=%d, elems=(",
          basicoDrone(d),
          idValorDrone(d),
          capacidadeCargaDrone(d),
          restoVooAtualDrone(d),
          alcanceDrone(d),
          datempovooDrone(d),
          restoManutencaoDrone(d)
        );
        for (j = 0; j < (tamanhoSequenciaColetivosDrone(d) - 1); j++) {
          printf("%d ", * valorelementoSequenciaDrone(d, j));
        }
        if (tamanhoSequenciaColetivosDrone(d) != 0)
          printf("%d", * valorelementoSequenciaDrone(d, j));
        printf("))\n");
      }
    }
  }
  //Listagem das Encomendas
  it = iteradorEncomendaSistema(s);

  while (temSeguinteIterador(it)) {
    encomenda e = seguinteIterador(it);
    printf("encomenda(id=%d, peso=%d, coord=(%d,%d), cria=%d, saida=%d, entrega=%d)\n",
      idValorEncomenda(e),
      pesoEncomenda(e),
      latitudeEncomenda(e),
      longitudeEncomenda(e),
      tempoCriacaoEncomenda(e),
      tempoSaidaEncomenda(e),
      tempoEntregaEncomenda(e)
    );
    i++;
  }
  destroiIterador(it);
  if (i == 0)
    printf("Nao existem drones nem encomendas\n");
}

/* Função de placeholder para remover um drone */
void cmdRemoveDrone(sistema s, char * linha) {
  int iddestruir, ignora;

  if (sscanf(linha, "%*c %d %d", & iddestruir, & ignora) != 1) {
    invalido();
  } else {
    if (existeDroneSistema(s, iddestruir) == 1) {
      if (removeDroneSistema(s, iddestruir) == 1)
        printf("Removido o drone %d\n", iddestruir);
      else
        proibido();
    } else {
      proibido();
    }
  }
}

/* Função que exibe o menu de comandos disponíveis */
void cmdMenu(void) {
  printf("Menu:\n");
  printf("  B - cria um novo drone Basico e regista-o na base\n");
  printf("  C - cria um novo drone Coletivo e regista-o na base\n");
  printf("  D - Despacha uma encomenda usando um drone\n");
  printf("  E - cria uma nova Encomenda\n");
  printf("  L - Lista drones e encomendas\n");
  printf("  R - Remove drone da base e destroi-o\n");
  printf("  T - avanca o Tempo um dado numero de horas\n");
  printf("  ? - mostra os comandos disponiveis\n");
  printf("  . - finaliza a execucao do programa\n");
}

/***********************************************
interpretador - Interpreta os comandos fornecidos pelo usuário e executa as funções correspondentes.
Parametros:
  s - sistema
Retorno:
Precondicoes:
***********************************************/
void interpretador(sistema s) {
  char linha[MAX_LINHA], cmd;
  do {
    printf("> ");
    if (fgets(linha, MAX_LINHA, stdin) == NULL) {
      printf("\n");
      break;
    }
    cmd = toupper(linha[0]);
    switch (cmd) {
    case 'T':
      cmdTempoAvanca(s, linha);
      break;
    case '?':
      cmdMenu();
      break;
    case 'B':
      cmdCriaDroneBasico(s, linha);
      break;
    case 'C':
      cmdCriaDroneColetivo(s, linha);
      break;
    case 'D':
      cmdDespachaEncomenda(s, linha);
      break;
    case 'E':
      cmdCriaEncomenda(s, linha);
      break;
    case 'L':
      cmdLista(s, linha);
      break;
    case 'R':
      cmdRemoveDrone(s, linha);
      break;
    case '.':
      break;
    case '\n':
      break;
    default:
      printf("Comando invalido\n");
      break;
    }
  } while (cmd != '.');
  printf("Obrigado. Volte sempre!\n");
}

/***********************************************
main - Função principal que inicializa o sistema e inicia o interpretador de comandos.
Parametros:
Retorno:
Precondicoes:
***********************************************/
int main(void) {
  sistema s = criaSistema();
  interpretador(s);
  destroiSistema(s);
  return 0;
}