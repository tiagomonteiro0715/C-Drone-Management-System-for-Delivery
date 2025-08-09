/*
 * coordenadas.h
 */

#ifndef H_COORDENADAS
#define H_COORDENADAS

/* Tipo de dados: coordenadas */
typedef struct _coordenadas * coordenadas;

/* Prototipos das funcoes associadas a coordenadas */

/***********************************************
criaCoordenadas - Criacao da instancia da estrutura associada a coordenadas.
Parametros:
    lat - latitude das coordenadas
    lon - longitude das coordenadas
Retorno: apontador para a instancia criada
Precondicoes:
***********************************************/
coordenadas criaCoordenadas(int lat, int lon);

/***********************************************
destroiCoordenadas - Liberta a memoria ocupada pela instancia da estrutura associada as coordenadas.
Parametros:
    c - coordenadas a destruir
Retorno:
Precondicoes: c != NULL
***********************************************/
void destroiCoordenadas(coordenadas c);

/***********************************************
latCoordenadas - consulta da latitude de uma coordenada dada.
Parametros:
    c - coordenadas
Retorno: latitude das coordenadas
Precondicoes: c != NULL
***********************************************/
int latCoordenadas(coordenadas c);

/***********************************************
lonCoordenadas - consulta da longitude de uma coordenada dada.
Parametros:
    c - coordenadas
Retorno: longitude das coordenadas
Precondicoes: c != NULL
***********************************************/
int lonCoordenadas(coordenadas c);

/***********************************************
distanciaCoordenadas - calcula a distancia entre duas coordenadas dadas.
Parametros:
    c1 - coordenadas
    c2 - coordenadas
    velocidade - velocidade do deslocamento
Retorno: distancia ajustada pela velocidade entre as coordenadas c1 e c2
Precondicoes: c1 != NULL && c2 != NULL
***********************************************/
int distanciaCoordenadas(coordenadas c1, coordenadas c2, int velocidade);

#endif /* H_COORDENADAS */
