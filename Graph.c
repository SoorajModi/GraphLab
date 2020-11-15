#include "Graph.h"

int main(void) {
  printf("Hello world\n");
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
    vertex = newVertex(value);
  } else if (vertex) {
    while (vertex->next) {
      vertex = vertex->next;
    }
    vertex->next = newVertex(value);
  }

  graph->numVertices++;
}

void addAdjListNode(AdjListNode* node, int value) {
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
      addAdjListNode(vertex->adjList, vertex2);
    } else if (vertex->value == vertex2) {
      addAdjListNode(vertex->adjList, vertex1);
    }
    vertex = vertex->next;
  }

  graph->numEdges++;
}

void printGraph(Graph* graph) {
  Vertex* vertex = graph->vertexList;

  while (vertex) {
    AdjListNode* adjNode = vertex->adjList;
    printf("Vertex %d has edges with vertices:", vertex->value);

    if (adjNode) {
      while (adjNode) {
        printf("%d ", adjNode->value);
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
