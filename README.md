# C-Drone-Management-System-for-Delivery

Final Project from the class "Algorithms and Data Structures"

My final grade in this class was 17 out of 20

This project implements a drone management system for package delivery, developed in C as part of a final project in Algorithms and Data Structures

## 📋 Description

The system allows you to manage a fleet of drones that can be used to deliver packages. Drones can be of two types:
- **Basic Drones**: Individual drones with specific payload and range
- **Collective Drones**: Drones formed by the combination of multiple basic drones

The system includes features for:
- Creating and managing drones (basic and collective)
- Creating and managing orders
- Dispatching packages using drones
- Advancing the system time
- Listing drones and orders
- Removing drones from the system

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

#### System (`sistema.c/h`)
- Coordinates all system components
- Manages drones, orders, and bases
- Controls system time
- Provides an interface for core operations

#### Drone (`drone.c/h`)
- Deploys basic and collective drones
- Manages payload, range, and status
- Controls flight and maintenance time
- Supports combining drones to form collectives

#### Order (`encomenda.c/h`)
- Represents orders with weight and location
- Manages delivery status
- Controls creation and delivery time

#### Foundation (`base.c/h`)
- Represents operating bases
- Manages drones and local orders
- Coordinates dispatch operations

#### Coordenates (`coordenadas.c/h`)
- Implements geographic coordinate system
- Calculates distances between points

## 🚀 How to Run

### Prerequisites
- GCC Compiler
- Unix/Linux System (or WSL on Windows)

### Compiling and Running

1. **Automatic Compilation:**
```bash
./run.sh
```

2. **Manual Compilation:**
```bash
gcc -o main *.c TADs/*/*.c -Wall -lm
./main
   ```

## 🎮 Available Commands

The system uses an interactive command interpreter. The available commands are:

| Command | Description | Syntax |
|---------|----------|---------|
| `B` | Creates a new basic drone | `B <payload> <range>` |
| `C` | Creates a new collective drone | `C <id1> <id2> ... <id6>` |
| `D` | Dispatches an order | `D <order_id> <drone_id>` |
| `E` | Creates a new order | `E <weight> <latitude> <longitude>` |
| `L` | Lists drones and orders | `L` |
| `R` | Removes a drone | `R <drone_id>` |
| `T` | Advances the time | `T <hours>` |
| `?` | Show available commands | `?` |
| `.` | End the program | `.` |

### Usage Examples

```bash
> B 100 50 # Create a basic drone with a 100kg payload and a 50km range
> E 25 40.7128 -74.0060 # Create a 25kg order in New York
> D 1000 0 # Dispatch order 1000 using drone 0
> T 2 # Advance the time by 2 hours
> L # List all drones and orders
```

## 🧪 Tests

The project includes two sets of tests:

- **`tests/`**: Main system tests (T01-T12)
- **`tests2/`**: Additional tests (T01-T11)

Each test contains:
- `input`: Input file with commands
- `output`: Expected output file

### Run Tests

```bash
# Run a specific test
./main < tests/T01/input > output.txt
diff output.txt tests/T01/output
```

## 📊 Data Structures

### Abstract Data Types (ADTs)

The project implements several fundamental ADTs:

- **Dictionary**: Key-value association
- **Queue**: FIFO (First In, First Out) structure
- **Iterator**: Navigation over collections
- **Stack**: LIFO (Last In, First Out) structure
- **Point**: 2D point representation
- **Sequence**: Ordered collection of elements

### Implementations

- **Dictionary**: Implemented with array
- **Queue**: Implemented with array
- **Iterator**: Implemented with array
- **Stack**: Implemented with array
- **Sequence**: Implemented with array and list Chained

## 🔧 Advanced Features

### Collective Drones
- Combination of up to 6 basic drones
- Combined capacity and range of component drones
- Automatic collective state management

### Time System
- Simulated time in hours
- Flight and maintenance time control
- System timeline

### State Management
- Drone states (available, in flight, in maintenance)
- Order status (pending, in delivery, delivered)
- Availability control

## 📝 Implementation Notes

- **Memory**: Manual memory management with destruction functions
- **Modularity**: Code organized into independent modules
- **Documentation**: Detailed comments in Portuguese
- **Validation**: Input data verification
- **Error Handling**: Informative error messages

## Contribution

This is an academic project developed as a Algorithms and data structures final project. 

Tiago Monteiro

- GitHub: @tiagomonteiro0715
- LinkedIn: [Tiago Monteiro](https://www.linkedin.com/in/tiago-monteiro-/)

For contributions or questions, please contact the authors
