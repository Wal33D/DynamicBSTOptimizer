// utils.h
#ifndef UTILS_H
#define UTILS_H

#include <stdio.h> // For printf, scanf
#include <stdlib.h> // For dynamic memory management
#include <string.h> // For string operations

#define MAX 10
#define INT_MAX 30000
#define charMAX 1000

// Declare the struct types and global variables here if they are used across both obst.c and utils.c
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

extern struct treeStats ts;
extern struct arrays ar;

void treeOutput(int i, int j, double w, double c, double r);
void printLevel(void);
void lineDraw(void);
void getInput(void);
void initOBST(void);

#endif
