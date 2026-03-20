# Data File Format

## aeropuertos.txt

Plain text, one airport per line. Fields separated by spaces.

| Field | Type | Description |
|-------|------|-------------|
| codigo | string | IATA 3-letter code (e.g. EZE, LAX) |
| nombre | string | Airport name (use hyphens for spaces) |
| ciudad | string | City name |
| pais | string | Country |
| superficie | float | Area in km² |
| cant_terminales | unsigned | Number of terminals |
| dest_nacionales | unsigned | Domestic destinations |
| dest_internacionales | unsigned | International destinations |

### Example

```
EZE Ministro-Pistarini Ezeiza Argentina 34.75 4 12 46
LAX Aeropuerto-Internacional-de-los-Angeles Los-Angeles EEUU 14 9 87 69
```

## vuelos.txt

Plain text, one direct flight per line.

| Field | Type | Description |
|-------|------|-------------|
| origen | string | IATA code of origin airport |
| destino | string | IATA code of destination airport |
| costo | float | Ticket price |
| duracion | float | Flight duration in hours |

### Example

```
EZE LAX 68675 9.2
LAX SFO 12500 1.2
```

**Note:** Both airports must exist in `aeropuertos.txt` for the graph to be complete. Flights define directed edges: A→B does not imply B→A.
