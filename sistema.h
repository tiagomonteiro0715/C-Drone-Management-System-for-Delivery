/*
 * sistema.h
 */

#ifndef H_SISTEMA
#define H_SISTEMA

/* Tipo de dados: sistema */
typedef struct _sistema * sistema;

/* Prototipos das funcoes associadas a um sistema */

/***********************************************
criaSistema - Criacao da instancia da estrutura associada a um sistema.
Parametros:
Retorno: apontador para a instancia criada
Precondicoes:
***********************************************/
sistema criaSistema();

/***********************************************
destroiSistema - Liberta a memoria ocupada pela instancia da estrutura associada ao sistema.
Parametros:
  s - sistema a destruir
Retorno:
Precondicoes: s != NULL
***********************************************/
void destroiSistema(sistema s);

/***********************************************
nomeBaseSistema - consulta o nome da base principal no sistema.
Parametros:
  s - sistema
Retorno: nome da base
Precondicoes: s != NULL
***********************************************/
char * nomeBaseSistema(sistema s);

/***********************************************
tempoAvancaSistema - avanca o tempo do sistema em n horas.
Parametros:
  s - sistema
  n - numero de horas a avancar
Retorno: tempo corrente atualizado
Precondicoes: s != NULL
***********************************************/
int tempoAvancaSistema(sistema s, int n);

/***********************************************
tamanhoDronesSistema - consulta o numero de drones no sistema.
Parametros:
  s - sistema
Retorno: numero de drones
Precondicoes: s != NULL
***********************************************/
int tamanhoDronesSistema(sistema s);

/***********************************************
acederDronesBaseSistema - consulta o dicionario de drones no sistema.
Parametros:
  s - sistema
Retorno: dicionario de drones
Precondicoes: s != NULL
***********************************************/
dicionario acederDronesBaseSistema(sistema s);



/***********************************************
tamanhoEncomendasSistema - consulta o numero de encomendas no sistema.
Parametros:
  s - sistema
Retorno: numero de encomendas
Precondicoes: s != NULL
***********************************************/
int tamanhoEncomendasSistema(sistema s);

/***********************************************
existeDroneSistema - verifica se um drone existe no sistema.
Parametros:
  s - sistema
  drone - identificador do drone
Retorno: 1 se o drone existe, 0 caso contrario
Precondicoes: s != NULL
***********************************************/
int existeDroneSistema(sistema s, int drone);

/***********************************************
criaIteradorDronesSistema - cria um iterador para os drones no sistema.
Parametros:
  s - sistema
Retorno: iterador para os drones
Precondicoes: s != NULL
***********************************************/
iterador criaIteradorDronesSistema(sistema s);

/***********************************************
criaIteradorEncomendaSistema - cria um iterador para as encomendas no sistema.
Parametros:
  s - sistema
Retorno: iterador para as encomendas
Precondicoes: s != NULL
***********************************************/
iterador criaIteradorEncomendaSistema(sistema s);

/***********************************************
tempoSistema - consulta o tempo corrente no sistema.
Parametros:
  s - sistema
Retorno: tempo corrente
Precondicoes: s != NULL
***********************************************/
int tempoSistema(sistema s);


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
drone criaDroneSistema(sistema s, int carga, int alcance, const char *tipo);








/***********************************************
valorIdPrintDroneSistema - Consulta o identificador do próximo drone a ser impresso no sistema.
Parametros:
  s - sistema
Retorno: identificador do próximo drone
Precondicoes: s != NULL
***********************************************/
int valorIdPrintDroneSistema(sistema s);

/***********************************************
valorCapPrintDroneSistema - Consulta a capacidade de carga do próximo drone a ser impresso no sistema.
Parametros:
  s - sistema
Retorno: capacidade de carga do próximo drone
Precondicoes: s != NULL
***********************************************/
int valorCapPrintDroneSistema(sistema s);

/***********************************************
valorAlcancePrintDroneSistema - Consulta o alcance do próximo drone a ser impresso no sistema.
Parametros:
  s - sistema
Retorno: alcance do próximo drone
Precondicoes: s != NULL
***********************************************/
int valorAlcancePrintDroneSistema(sistema s);

/***********************************************
valorVooPrintDroneSistema - Consulta o tempo de manutenção do próximo drone a ser impresso no sistema.
Parametros:
  s - sistema
Retorno: tempo de manutenção do próximo drone
Precondicoes: s != NULL
***********************************************/
int valorVooPrintDroneSistema(sistema s);

/***********************************************
adicionarDroneColetivoSistema - Adiciona um drone coletivo ao sistema.
Parametros:
  s - sistema
  verificar - número de drones a verificar
  iddrones - array de identificadores dos drones a serem verificados
Retorno: 1 se o drone coletivo foi adicionado com sucesso, 0 caso contrário
Precondicoes: s != NULL
***********************************************/
int adicionarDroneColetivoSistema(sistema s,int verificar,int * iddrones);

/***********************************************
valorelementoSequenciaDroneSistema - Consulta um elemento de uma sequência de drones no sistema.
Parametros:
  s - sistema
  pos - posição do drone na sequência
Retorno: ponteiro para o elemento na sequência
Precondicoes: s != NULL
***********************************************/
int * valorelementoSequenciaDroneSistema(sistema s,int pos);



/***********************************************
valoridDroneSistema - Consulta o identificador de um drone no sistema em uma posição especificada.
Parametros:
  s - sistema
  pos - posição do drone
Retorno: identificador do drone
Precondicoes: s != NULL
***********************************************/
int valoridDroneSistema(sistema s, int pos);

/***********************************************
valorcapacidadeDroneSistema - Consulta a capacidade de carga de um drone no sistema em uma posição especificada.
Parametros:
  s - sistema
  pos - posição do drone
Retorno: capacidade de carga do drone
Precondicoes: s != NULL
***********************************************/
int valorcapacidadeDroneSistema(sistema s, int pos);

/***********************************************
valoralcanceDroneSistema - Consulta o alcance de um drone no sistema em uma posição especificada.
Parametros:
  s - sistema
  pos - posição do drone
Retorno: alcance do drone
Precondicoes: s != NULL
***********************************************/
int valoralcanceDroneSistema(sistema s, int pos);

/***********************************************
valorManuDroneSistema - Consulta o tempo de manutenção de um drone no sistema em uma posição especificada.
Parametros:
  s - sistema
  pos - posição do drone
Retorno: tempo de manutenção do drone
Precondicoes: s != NULL
***********************************************/
int valorManuDroneSistema(sistema s, int pos);



/***********************************************
//valorprintelementoSequenciaDroneSistema - Consulta um elemento da sequência de drones no sistema em uma posição especificada.
Parametros:
  s - sistema
  i - índice da sequência
  j - índice do elemento na sequência
Retorno: ponteiro para o elemento da sequência
Precondicoes: s != NULL
***********************************************/
//int *valorprintelementoSequenciaDroneSistema(sistema s, int i, int j);

/***********************************************
valorIdEncomendaSistema - Consulta o identificador de uma encomenda no sistema.
Parametros:
  s - sistema
  i - identificador da encomenda
Retorno: identificador da encomenda
Precondicoes: s != NULL
***********************************************/
int valorIdEncomendaSistema(sistema s,int i);

/***********************************************
valorPesoEncomendaSistema - Consulta o peso de uma encomenda no sistema.
Parametros:
  s - sistema
  i - identificador da encomenda
Retorno: peso da encomenda
Precondicoes: s != NULL
***********************************************/
int valorPesoEncomendaSistema(sistema s,int i);

/***********************************************
valorLatEncomendaSistema - Consulta a latitude de uma encomenda no sistema.
Parametros:
  s - sistema
  i - identificador da encomenda
Retorno: latitude da encomenda
Precondicoes: s != NULL
***********************************************/
int valorLatEncomendaSistema(sistema s,int i);

/***********************************************
valorLonEncomendaSistema - Consulta a longitude de uma encomenda no sistema.
Parametros:
  s - sistema
  i - identificador da encomenda
Retorno: longitude da encomenda
Precondicoes: s != NULL
***********************************************/
int valorLonEncomendaSistema(sistema s,int i);

/***********************************************
valorCriaEncomendaSistema - Consulta o tempo de criação de uma encomenda no sistema.
Parametros:
  s - sistema
  i - identificador da encomenda
Retorno: tempo de criação da encomenda
Precondicoes: s != NULL
***********************************************/
int valorCriaEncomendaSistema(sistema s,int i);

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
void CriaEncomendaSistema(sistema s, int peso, int latitude, int longitude);

/***********************************************
idValorEncomendaSistema - Consulta o identificador da próxima encomenda a ser impressa no sistema.
Parametros:
  s - sistema
Retorno: identificador da próxima encomenda
Precondicoes: s != NULL
***********************************************/
int idValorEncomendaSistema(sistema s);

/***********************************************
pesoValorEncomendaSistema - Consulta o peso da próxima encomenda a ser impressa no sistema.
Parametros:
  s - sistema
Retorno: peso da próxima encomenda
Precondicoes: s != NULL
***********************************************/
int pesoValorEncomendaSistema(sistema s);

/***********************************************
latValorEncomendaSistema - Consulta a latitude da próxima encomenda a ser impressa no sistema.
Parametros:
  s - sistema
Retorno: latitude da próxima encomenda
Precondicoes: s != NULL
***********************************************/
int latValorEncomendaSistema(sistema s);

/***********************************************
lonValorEncomendaSistema - Consulta a longitude da próxima encomenda a ser impressa no sistema.
Parametros:
  s - sistema
Retorno: longitude da próxima encomenda
Precondicoes: s != NULL
***********************************************/
int lonValorEncomendaSistema(sistema s);

/***********************************************
tempoValorEncomendaSistema - Consulta o tempo de criação da próxima encomenda a ser impressa no sistema.
Parametros:
  s - sistema
Retorno: tempo de criação da próxima encomenda
Precondicoes: s != NULL
***********************************************/
int tempoValorEncomendaSistema(sistema s);

/***********************************************
tempoAtualSistema - Consulta o tempo atual do sistema.
Parametros:
  s - sistema
Retorno: tempo atual do sistema
Precondicoes: s != NULL
***********************************************/
int tempoAtualSistema(sistema s);

/***********************************************
despachaEncomendaSistema - Despacha uma encomenda especificada por seu identificador utilizando um drone especificado.
Parametros:
  s - sistema
  idencomenda - identificador da encomenda a ser despachada
  iddrone - identificador do drone que fará o despacho
Retorno: código de sucesso ou erro
Precondicoes: s != NULL, idencomenda >= 0, iddrone >= 0
***********************************************/
int despachaEncomendaSistema(sistema s, int idencomenda, int iddrone);

/***********************************************
removeDroneSistema - Remove um drone especificado por seu identificador do sistema.
Parametros:
  s - sistema
  iddrone - identificador do drone a ser removido
Retorno: código de sucesso ou erro
Precondicoes: s != NULL, iddrone >= 0
***********************************************/
int removeDroneSistema(sistema s, int iddrone);

/***********************************************
dadroneSistema - Recupera um drone do sistema a partir de sua chave.
Parametros:
  s - sistema
  ch - chave do drone
Retorno: drone correspondente à chave fornecida
Precondicoes: s != NULL, ch != NULL
***********************************************/
drone dadroneSistema(sistema s, chaveInt ch);

/***********************************************
iteradorDroneSistema - Retorna um iterador para percorrer todos os drones do sistema.
Parametros:
  s - sistema
Retorno: iterador para drones
Precondicoes: s != NULL
***********************************************/
iterador iteradorDroneSistema(sistema s);

/***********************************************
iteradorEncomendaSistema - Retorna um iterador para percorrer todas as encomendas do sistema.
Parametros:
  s - sistema
Retorno: iterador para encomendas
Precondicoes: s != NULL
***********************************************/
iterador iteradorEncomendaSistema(sistema s);
#endif /* H_SISTEMA */
