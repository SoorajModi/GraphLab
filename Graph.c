#include "Graph.h"

int main(void) {
  Graph* graph = createGraph();

  for (int i = 1; i < 6; i++) {
    addVertex(graph, i);
  }

  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);
  addEdge(graph, 2, 4);
  addEdge(graph, 3, 4);
  addEdge(graph, 4, 5);
  addEdge(graph, 4, 1);

  printGraph(graph);

  printf("Checking for Vertex 5: %d\n", checkForVertex(graph, 5));
  printf("Checking for Vertex 6: %d\n", checkForVertex(graph, 6));

  printf("Number of vertices: %d\n", getNumVertices(graph));
  printf("Number of edges: %d\n", getNumEdges(graph));

  freeGraph(graph);

  return 0;
}

Graph* createGraph() {
  Graph* graph = malloc(sizeof(Graph));

  graph->numVertices = 0;
  graph->numEdges = 0;
  graph->vertexList = NULL;

  return graph;
}

Vertex* createVertex(int value) {
  Vertex* vertex = malloc(sizeof(Vertex));

  vertex->value = value;
  vertex->adjList = NULL;
  vertex->next = NULL;

  return vertex;
}

AdjVertex* createAdjVertex(int value) {
  AdjVertex* node = malloc(sizeof(AdjListNode));

  node->value = value;
  node->next = NULL;

  return node;
}

void addVertex(Graph* graph, int value) {
  Vertex* vertex = graph->vertexList;

  if (vertex == NULL) {
    graph->vertexList = createVertex(value);
  } else if (vertex) {
    while (vertex->next) {
      vertex = vertex->next;
    }
    vertex->next = createVertex(value);
  }

  graph->numVertices++;
}

void addAdjVertex(Vertex* vertex, int value) {
  AdjVertex* node = vertex->adjList;

  if (node == NULL) {
    vertex->adjList = createAdjVertex(value);
  } else if (node) {
    while(node->next) {
      node = node->next;
    }
    node->next = createAdjVertex(value);
  }
}

void addEdge(Graph* graph, int vertex1, int vertex2) {
  Vertex* vertex = graph->vertexList;

  while (vertex) {
    if (vertex->value == vertex1) {
      addAdjVertex(vertex, vertex2);
    } else if (vertex->value == vertex2) {
      addAdjVertex(vertex, vertex1);
    }
    vertex = vertex->next;
  }

  graph->numEdges++;
}

void printGraph(Graph* graph) {
  Vertex* vertex = graph->vertexList;

  if (!vertex) printf("No vertices in the graph\n");

  while (vertex) {
    AdjListNode* adjNode = vertex->adjList;
    printf("Vertex %d has edges with vertices: ", vertex->value);

    if (adjNode) {
      while (adjNode) {
        printf("%d ", adjNode->value);
	      adjNode = adjNode->next;
      }
    } else if (adjNode == NULL) {
      printf("no adjacencent vertices");
    }

    printf("\n");
    vertex = vertex->next;
  }
}

int checkForVertex(Graph* graph, int src) {
  Vertex* vertex = graph->vertexList;

  while (vertex) {
    if (vertex->value == src) {
      return 1;
    }
    vertex = vertex->next;
  }

  return 0;
}

int getNumVertices(Graph* graph) {
  return graph->numVertices;
}

int getNumEdges(Graph* graph) {
  return graph->numEdges;
}

void freeGraph(Graph* graph) {
  freeVertexList(graph->vertexList);
  free(graph);
}

void freeVertexList(Vertex* node) {
  while (node) {
    Vertex* next = node->next;
    freeAdjVertexList(node->adjList);
    free(node);
    node = next;
  }
}

void freeAdjVertexList(AdjVertex* node) {
  while (node) {
    AdjVertex* next = node->next;
    free(node);
    node = next;
  }
}
