# Airport Mapper

C++ application for managing airport data and finding optimal flight itineraries using Dijkstra's algorithm. Uses a Binary Search Tree (ABB) for airport lookup and a directed graph for route planning.

## Features

- **Airport catalog**: Search, add, and remove airports by IATA code
- **Flight network**: Directed graph of connections between airports
- **Optimal routes**: Minimum path by flight duration or cost (Dijkstra)
- **Data persistence**: Load from text files at startup

## Requirements

- C++11 compatible compiler (g++, clang++)
- Make

## Build

```bash
make
```

Produces `airport-mapper` executable.

## Run

```bash
./airport-mapper
```

Or: `make run`

## Menu Options

| Option | Action |
|--------|--------|
| 1 | Consult airport by IATA code |
| 2 | Add new airport |
| 3 | Remove airport |
| 4 | List all airports (in-order) |
| 5 | List airports by tree level (BFS) |
| 6 | Print flight graph |
| 7 | Find optimal itinerary (by duration or cost) |
| 8 | Exit |

## Data Files

Must be in the same directory as the executable.

### aeropuertos.txt

One airport per line, space-separated:

```
CODE Name City Country Surface Terminals NationalDest InternationalDest
```

Example:

```
EZE Ministro-Pistarini Ezeiza Argentina 34.75 4 12 46
```

### vuelos.txt

One flight per line:

```
ORIGIN DESTINATION COST DURATION_HOURS
```

Example:

```
EZE LAX 68675 9.2
```

## Documentation

- `README.md` — This file
- `docs/DATA_FORMAT.md` — Data file format reference

## Project Structure

```
├── main.cpp              # Entry point
├── Menu.cpp/h            # User interface and orchestration
├── Grafo.cpp/h           # Graph, Dijkstra algorithm
├── Vertice.cpp/h         # Graph vertex
├── Arista.cpp/h          # Graph edge (flight)
├── ABB.h                 # Binary Search Tree (template)
├── NodoABB.h             # BST node
├── Cola.h                # Priority queue (template)
├── Nodo.h                # Queue node
├── Aeropuerto.cpp/h      # Airport entity
├── ArchivoAeropuerto.cpp/h   # Load airports from file
├── ArchivoVuelos.cpp/h       # Load flights from file
├── aeropuertos.txt       # Airport data
├── vuelos.txt            # Flight data
└── Makefile
```

## Data Structures

- **ABB**: Airport catalog indexed by IATA code. O(log n) search, insert, delete.
- **Grafo**: Adjacency list. Vertices = airports, edges = flights (with cost and duration).
- **Cola**: Priority queue for Dijkstra; lower priority value = higher urgency.

## License

Academic project.
