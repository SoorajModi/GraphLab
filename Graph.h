#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct adjVertex {
  int value;
  struct adjVertex* next;
} AdjVertex;

typedef struct vertex {
  int value;
  AdjVertex* adjList;    // Should always point to head
  struct vertex* next;
} Vertex;

typedef struct graph {
  int numVertices;
  int numEdges;
  Vertex* vertexList;   // Should always point to the head
} Graph;

Graph* createGraph();
Vertex* createVertex(int value);
AdjVertex* createAdjVertex(int value);
void addVertex(Graph* graph, int value);
void addAdjVertex(Vertex* vertex, int value);
void addEdge(Graph* graph, int vertex1, int vertex2);
void printGraph(Graph* graph);
int checkForVertex(Graph* graph, int src);
int getNumVertices(Graph* graph);
int getNumEdges(Graph* graph);
void freeGraph(Graph* graph);
void freeVertexList(Vertex* list);
void freeAdjVertexList(AdjVertex* list);
