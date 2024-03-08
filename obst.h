#ifndef OBST_H
#define OBST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
#define INT_MAX 30000
#define charMAX 1000

struct treeStats
{
  int n;
  float temp, root, minimumCost, temporaryMinimumCost;
};

struct arrays
{
  char ele[MAX][MAX], W[charMAX], C[charMAX], R[charMAX], a[charMAX];
  float w[MAX][MAX], c[MAX][MAX], r[MAX][MAX], p[MAX], q[MAX];
};

void treeOutput(int i, int j, double w, double c, double r);  
void printLevel();  
void lineDraw();  
void getInput();  
void initOBST();  
void OBST();  

#endif 