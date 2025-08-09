# Sistema de Gestão de Drones para Entrega

**Repository Name:** `drone-delivery-system-aed`

> Sistema de gestão de frota de drones para entrega de encomendas, desenvolvido em C com implementação de TADs (Tipos Abstratos de Dados).

Este projeto implementa um sistema de gestão de drones para entrega de encomendas, desenvolvido em C como parte de um trabalho final de Algoritmos e Estruturas de Dados (AED).

## 📋 Descrição

O sistema permite gerir uma frota de drones que podem ser utilizados para entregar encomendas. Os drones podem ser de dois tipos:
- **Drones Básicos**: Drones individuais com capacidade de carga e alcance específicos
- **Drones Coletivos**: Drones formados pela combinação de múltiplos drones básicos

O sistema inclui funcionalidades para:
- Criar e gerir drones (básicos e coletivos)
- Criar e gerir encomendas
- Despachar encomendas usando drones
- Avançar o tempo do sistema
- Listar drones e encomendas
- Remover drones do sistema

## 🏗️ Arquitetura do Projeto

### Estrutura de Diretórios

```
TrabalhoFinalaed2/
├── mainDrones.c          # Programa principal com interpretador de comandos
├── sistema.c/h           # Sistema principal que coordena todos os componentes
├── drone.c/h             # Implementação dos drones (básicos e coletivos)
├── encomenda.c/h         # Implementação das encomendas
├── base.c/h              # Implementação das bases de operação
├── coordenadas.c/h       # Implementação das coordenadas geográficas
├── TADs/                 # Tipos Abstratos de Dados
│   ├── dicionario/       # Implementação de dicionários
│   ├── fila/             # Implementação de filas
│   ├── iterador/         # Implementação de iteradores
│   ├── pilha/            # Implementação de pilhas
│   ├── ponto/            # Implementação de pontos
│   └── sequencia/        # Implementação de sequências
├── tests/                # Testes do sistema
├── tests2/               # Testes adicionais
├── run.sh                # Script para compilar e executar
└── zip.sh                # Script para criar arquivo ZIP
```

### Componentes Principais

#### Sistema (`sistema.c/h`)
- Coordena todos os componentes do sistema
- Gerencia drones, encomendas e bases
- Controla o tempo do sistema
- Fornece interface para operações principais

#### Drone (`drone.c/h`)
- Implementa drones básicos e coletivos
- Gerencia capacidade de carga, alcance e estado
- Controla tempo de voo e manutenção
- Suporta combinação de drones para formar coletivos

#### Encomenda (`encomenda.c/h`)
- Representa encomendas com peso e localização
- Gerencia estado de entrega
- Controla tempo de criação e entrega

#### Base (`base.c/h`)
- Representa bases de operação
- Gerencia drones e encomendas locais
- Coordena operações de despacho

#### Coordenadas (`coordenadas.c/h`)
- Implementa sistema de coordenadas geográficas
- Calcula distâncias entre pontos

## 🚀 Como Executar

### Pré-requisitos
- Compilador GCC
- Sistema Unix/Linux (ou WSL no Windows)

### Compilação e Execução

1. **Compilação automática:**
   ```bash
   ./run.sh
   ```

2. **Compilação manual:**
   ```bash
   gcc -o main *.c TADs/*/*.c -Wall -lm
   ./main
   ```

## 🎮 Comandos Disponíveis

O sistema utiliza um interpretador de comandos interativo. Os comandos disponíveis são:

| Comando | Descrição | Sintaxe |
|---------|-----------|---------|
| `B` | Cria um novo drone básico | `B <carga> <alcance>` |
| `C` | Cria um novo drone coletivo | `C <id1> <id2> ... <id6>` |
| `D` | Despacha uma encomenda | `D <id_encomenda> <id_drone>` |
| `E` | Cria uma nova encomenda | `E <peso> <latitude> <longitude>` |
| `L` | Lista drones e encomendas | `L` |
| `R` | Remove um drone | `R <id_drone>` |
| `T` | Avança o tempo | `T <horas>` |
| `?` | Mostra comandos disponíveis | `?` |
| `.` | Finaliza o programa | `.` |

### Exemplos de Uso

```bash
> B 100 50          # Cria drone básico com carga 100kg e alcance 50km
> E 25 40.7128 -74.0060  # Cria encomenda de 25kg em Nova York
> D 1000 0          # Despacha encomenda 1000 usando drone 0
> T 2               # Avança o tempo em 2 horas
> L                 # Lista todos os drones e encomendas
```

## 🧪 Testes

O projeto inclui dois conjuntos de testes:

- **`tests/`**: Testes principais do sistema (T01-T12)
- **`tests2/`**: Testes adicionais (T01-T11)

Cada teste contém:
- `input`: Arquivo de entrada com comandos
- `output`: Arquivo de saída esperado

### Executar Testes

```bash
# Executar um teste específico
./main < tests/T01/input > output.txt
diff output.txt tests/T01/output
```

## 📊 Estruturas de Dados

### Tipos Abstratos de Dados (TADs)

O projeto implementa vários TADs fundamentais:

- **Dicionário**: Associação chave-valor
- **Fila**: Estrutura FIFO (First In, First Out)
- **Iterador**: Navegação sobre coleções
- **Pilha**: Estrutura LIFO (Last In, First Out)
- **Ponto**: Representação de pontos 2D
- **Sequência**: Coleção ordenada de elementos

### Implementações

- **Dicionário**: Implementado com vetor
- **Fila**: Implementada com vetor
- **Iterador**: Implementado com vetor
- **Pilha**: Implementada com vetor
- **Sequência**: Implementada com vetor e lista ligada

## 🔧 Funcionalidades Avançadas

### Drones Coletivos
- Combinação de até 6 drones básicos
- Capacidade e alcance somados dos drones componentes
- Gestão automática de estado coletivo

### Sistema de Tempo
- Tempo simulado em horas
- Controlo de tempo de voo e manutenção
- Avanço temporal do sistema

### Gestão de Estado
- Estados de drones (disponível, em voo, em manutenção)
- Estados de encomendas (pendente, em entrega, entregue)
- Controlo de disponibilidade

## 📝 Notas de Implementação

- **Memória**: Gestão manual de memória com funções de destruição
- **Modularidade**: Código organizado em módulos independentes
- **Documentação**: Comentários detalhados em português
- **Validação**: Verificação de dados de entrada
- **Tratamento de Erros**: Mensagens de erro informativas

## 🤝 Contribuição

Este é um projeto académico desenvolvido como trabalho final de AED. Para contribuições ou questões, contacte os autores.

## 📄 Licença

Este projeto foi desenvolvido para fins académicos no âmbito da disciplina de Algoritmos e Estruturas de Dados. 