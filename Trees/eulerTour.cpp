// TÉCNICA QUE TRANSFORMA EL ARBOL EN UNA SECUENCIA LINEAL DE NODOS.
vector<int> adj[N+1]; // Lista de adyacencia del árbol (1-indexing)
vector<int> tour_sequence;
int tin[N+1], tout[N+1];
int timer = 0; // Índice actual en tour_sequence

void dfs_euler_tour(int u, int p) {
    // === 1. Entrada/Bajada (Primera Aparición) ===
    tin[u] = timer;
    tour_sequence.push_back(u);
    timer++;

    for (int v : adj[u]) {
        if (v != p) {
            // === 2. Recorrido a Hijos ===
            dfs_euler_tour(v, u);
        }
    }

    // === 3. Salida/Subida (Última Aparición) ===
    tout[u] = timer;
    tour_sequence.push_back(u); // Se registra de nuevo al subir
    timer++;
}

// Para usar:
// dfs_euler_tour(raiz, 0);

/*
APLICACIONES (clave) DE CAJA GRIS:
1. Identificar si u es Ancestro de v:
  u es ancestro de v <=> tin[u] <= tin[v] y tout[u] >= tout[v]

2. Consultas de Camino (LCA, distancia):
  Puedes usar solo el recorrido principal (tour_sequence) junto con un RMQ
  o un Segment Tree para encontrar el LCA (Mínimo Común Ancestro) de dos nodos.
  El LCA de u y v es el nodo con menor profundidad en el subarreglo de
  tour_sequence que va desde min(tin[u], tin[v]) hasta max(tout[u], tout[v]).

3. Consultas de Subárbol:
  El subárbol de un nodo u corresponde al rango continuo en la secuencia de
  Euler: [tin[u], tout[u]]. ¡Este es el patrón más potente! Si quieres
  sumar/actualizar algo en todo el subárbol de u, simplemente actualizas el rango
  [tin[u], tout[u]] en la estructura de datos lineal que hayas construido sobre
  tour_sequence.
*/
