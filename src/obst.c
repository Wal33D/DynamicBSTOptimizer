// Name: <Wal33D>

// This is an Optimal Binary Search Tree Algorithms.

//  (1) Enter # of elements
//  (2) Enter a numerical or alphabetic key for each element (a)
//  (3) Enter each element (p)
// (4) Enter the probability of each element (q)

// It outputs the computational matrix associated with p and q input sets, the root, and the min cost
//
//  If all
//  c(i, j)’s and r(i, j)’s are calculated,
//  then OBST algorithm in worst case takes O(n3) time

#include "utils.h"

// Initial the the variables and arrays we will be using, counters i,k;

void initOBST()
{

  int i, j;

  ts.temp = 0.0;

  for (i = 0; i <= ts.n; i++)
  {

    for (j = 0; j <= ts.n; j++)
    {

      if (i == j)
      {

        ar.w[i][j] = ar.q[i];
        ar.c[i][j] = 0.0;
        ar.r[i][j] = 0.0;

        treeOutput(i, j, ar.w[i][j], ar.c[i][j], ar.r[i][j]);
      }
    }
  }

  printLevel();
}

// OBST, Produces Computational Matrix, Minimum cost, and Root

void OBST()
{

  int i, j, k, b;

  for (b = 0; b < ts.n; b++)
  {

    for (i = 0, j = b + 1; (j < ts.n + 1) && (i < ts.n + 1); j++, i++)
    {

      if (i != j && i < j)
      {

        ar.w[i][j] = ar.p[j] + ar.q[j] + ar.w[i][j - 1];

        ts.min = INT_MAX;

        for (k = i + 1; k <= j; k++)
        {

          ts.min1 = ar.c[i][k - 1] + ar.c[k][j] + ar.w[i][j];

          if (ts.min > ts.min1)
          {

            ts.min = ts.min1;
            ts.temp = k;
          }
        }

        ar.c[i][j] = ts.min;
        ar.r[i][j] = ts.temp;
      }

      treeOutput(i, j, ar.w[i][j], ar.c[i][j], ar.r[i][j]);
    }

    printLevel();
  }
}

// int main() is our control function
int main()
{

  // Call our getInput() method to collect a, p & q
  getInput();
  // Initialize OBST
  initOBST();
  // Call our OBST
  OBST();
  // Helper Method - it prints a line seperator
  lineDraw();
  // Print Minimum cost to console
  printf("Minimum cost = %.03f\n", ar.c[0][ts.n]);
  // Set root variable to determined root
  ts.root = ar.r[0][ts.n];
  // Print root of tree to console
  printf("Root  = %.03f", ts.root);
  // Helper Method - it prints a line seperator
  lineDraw();

  return 0;
}