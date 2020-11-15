#include "Graph.h"

int main(void) {
  Graph* graph = createGraph();
  
  for (int i = 1; i < 6; i++) {
    addVertex(graph, i);
  }
  
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 4);
  addEdge(graph, 4, 5);
  addEdge(graph, 4, 1);
  
  printGraph(graph);
  
  return 0;
}

Graph* createGraph() {
  Graph* graph = malloc(sizeof(Graph));

  graph->numVertices = 0;
  graph->numEdges = 0;
  graph->vertexList = NULL;

  return graph;
}

Vertex* newVertex(int value) {
  Vertex* vertex = malloc(sizeof(Vertex));

  vertex->value = value;
  vertex->adjList = NULL;
  vertex->next = NULL;

  return vertex;
}

AdjListNode* newAdjListNode(int value) {
  AdjListNode* node = malloc(sizeof(AdjListNode));

  node->value = value;
  node->next = NULL;

  return node;
}

void addVertex(Graph* graph, int value) {
  Vertex* vertex = graph->vertexList;

  if (vertex == NULL) {
    graph->vertexList = newVertex(value);
  } else if (vertex) {
    while (vertex->next) {
      vertex = vertex->next;
    }
    vertex->next = newVertex(value);
  }

  graph->numVertices++;
}

void addAdjListNode(Vertex* vertex, int value) {
  AdjListNode* node = vertex->adjList;
  if (node == NULL) {
    node = newAdjListNode(value);
  } else if (node) {
    while(node->next) {
      node = node->next;
    }
    node->next = newAdjListNode(value);
  }
}

void addEdge(Graph* graph, int vertex1, int vertex2) {
  Vertex* vertex = graph->vertexList;

  while (vertex) {
    if (vertex->value == vertex1) {
      addAdjListNode(vertex, vertex2);
    } else if (vertex->value == vertex2) {
      addAdjListNode(vertex, vertex1);
    }
    vertex = vertex->next;
  }

  graph->numEdges++;
}

void printGraph(Graph* graph) {
  Vertex* vertex = graph->vertexList;
  
  if (!vertex) printf("no vertex\n");
  
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

int checkVertices(Graph* graph, int src) {
  Vertex* vertex = graph->vertexList;

  while (vertex) {
    if (vertex->value == src) {
      return 1;
    }
  }

  return 0;
}

void freeGraph(Graph* graph) {
  freeVertexList(graph->vertexList);
  free(graph);
}

void freeVertexList(Vertex* node) {
  while (node->next) {
    Vertex* next = node->next;
    freeAdjList(node->adjList);
    free(node);
    node = next;
  }

  free(node);
}

void freeAdjList(AdjListNode* node) {
  while (node->next) {
    AdjListNode* next = node->next;
    free(node);
    node = next;
  }

  free(node);
}
