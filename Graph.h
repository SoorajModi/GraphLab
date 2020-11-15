#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct adjListNode {
  int value;
  struct adjListNode* next;
} AdjListNode;

typedef struct vertex {
  int value;
  AdjListNode* adjList;    // Should always point to head
  struct vertex* next;
} Vertex;

typedef struct graph {
  int numVertices;
  int numEdges;
  Vertex* vertexList;   // Should always point to the head
} Graph;

Graph* createGraph();
Vertex* newVertex(int value);
AdjListNode* newAdjListNode(int value);
void addVertex(Graph* graph, int value);
void addAdjListNode(Vertex* vertex, int value);
void addEdge(Graph* graph, int vertex1, int vertex2);
void printGraph(Graph* graph);
int checkForVertex(Graph* graph, int src);
int getNumVertices(Graph* graph);
int getNumEdges(Graph* graph);
void freeGraph(Graph* graph);
void freeVertexList(Vertex* list);
void freeAdjList(AdjListNode* list);
