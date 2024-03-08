#include <stdio.h>
#include "obst.h"

void getInput()
{
  int i;
  float numer, deno;

  printf("Enter the number of elements:");
  scanf("%d", &treeStats.n);
  lineDraw(); 

  for (i = 1; i <= treeStats.n; i++)
  {
    printf("Enter the A of %d:", i);
    scanf("%s", treeData.a[i]); 
  }
  lineDraw(); 

  for (i = 1; i <= treeStats.n; i++)
  {
    printf("Enter the P (Element) of %d:\n-Fraction Numertator: ", i);
    scanf("%f", &numer);
    printf("-Fraction Denominator: ");
    scanf("%f", &deno);
    printf("--%.0f/%.0f\n", numer, deno);
    treeData.p[i] = numer / deno;
  }
  lineDraw(); 

  for (i = 0; i <= treeStats.n; i++)
  {
    printf("Enter the Q (Probability) of %d:\n-Fraction Numertator: ", i);
    scanf("%f", &numer);
    printf("-Fraction Denominator: ");
    scanf("%f", &deno);
    printf("--%.0f/%.0f\n", numer, deno);
    treeData.q[i] = numer / deno;
  }
  lineDraw(); 
}

void lineDraw()
{
  printf("\n--------------------------------\n");
}

void treeOutput(int i, int j, double w, double c, double r)
{
  sprintf(treeData.W, "%sW[%d][%d]: %.03f\t", treeData.W, i, j, w);
  sprintf(treeData.C, "%sC[%d][%d]: %.03f\t", treeData.C, i, j, c);
  sprintf(treeData.R, "%sR[%d][%d]: %.03f\t", treeData.R, i, j, r);
}

void printLevel()
{
  printf("\n%s\n%s\n%s\n", treeData.W, treeData.C, treeData.R);
  sprintf(treeData.W, "");
  sprintf(treeData.C, "");
  sprintf(treeData.R, "");
}