#include "obst.h"

void initOBST()
{
  int i, j;
  treeStats.temp = 0.0;
  for (i = 0; i <= treeStats.n; i++)
  {
    for (j = 0; j <= treeStats.n; j++)
    {
      if (i == j)
      {
        treeData.w[i][j] = treeData.q[i];
        treeData.c[i][j] = 0.0;
        treeData.r[i][j] = 0.0;

        treeOutput(i, j, treeData.w[i][j], treeData.c[i][j], treeData.r[i][j]);
      }
    }
  }

  printLevel();
}

void OBST()
{
  int i, j, k, b;
  for (b = 0; b < treeStats.n; b++)
  {
    for (i = 0, j = b + 1; (j < treeStats.n + 1) && (i < treeStats.n + 1); j++, i++)
    {
      if (i != j && i < j)
      {
        treeData.w[i][j] = treeData.p[j] + treeData.q[j] + treeData.w[i][j - 1];
        treeStats.min = INT_MAX;
        for (k = i + 1; k <= j; k++)
        {
          treeStats.temporaryMinimumCost = treeData.c[i][k - 1] + treeData.c[k][j] + treeData.w[i][j];
          if (treeStats.min > treeStats.temporaryMinimumCost)
          {
            treeStats.min = treeStats.temporaryMinimumCost;
            treeStats.temp = k;
          }
        }
        treeData.c[i][j] = treeStats.min;
        treeData.r[i][j] = treeStats.temp;

        treeOutput(i, j, treeData.w[i][j], treeData.c[i][j], treeData.r[i][j]);
      }
    }

    printLevel();
  }
}

int main()
{

  getInput();
  initOBST();
  OBST();

  printf("Minimum cost = %.03f\n", treeData.c[0][treeStats.n]);

  treeStats.root = treeData.r[0][treeStats.n];

  printf("Root = %.03f\n", treeStats.root);

  lineDraw();

  return 0;
}