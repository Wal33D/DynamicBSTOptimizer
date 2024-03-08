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
  float temp, root, min, min1;
};

struct arrays
{
  char ele[MAX][MAX], W[charMAX], C[charMAX], R[charMAX], a[charMAX];
  float w[MAX][MAX], c[MAX][MAX], r[MAX][MAX], p[MAX], q[MAX];
};

void treeOutput(int i, int j, double w, double c, double r);  // Store W on 1 line, Store C on 1 line, Store R on 1 line
void printLevel();  // Print current level of tree, Set W,C,R to empty string to prepare for next level
void lineDraw();  // lineDraw() is used to print the divider inbetween prompts
void getInput();  // Get user input, Keys, Elements, Probability
void initOBST();  // Initial the the variables and arrays we will be using, counters i,k;
void OBST();  // OBST, Produces Computational Matrix, Minimum cost, and Root 

#endif /* OBST_H */
