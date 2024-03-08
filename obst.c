/*
 * Optimal Binary Search Tree (OBST) Algorithm Implementation
 * Author: Waleed Gudah
 * License: MIT
 *
 * This implementation of the Optimal Binary Search Tree (OBST) algorithm is designed for efficient
 * searching through a sorted array of elements, optimizing for the lowest average search time. It takes
 * into account the probability of each element's search and constructs the binary search tree based on
 * these probabilities to minimize the total search cost.
 *
 * Features:
 *  - Dynamic computation of OBST based on input probabilities
 *  - Outputs computational matrix, root, and minimum cost of the search tree
 *  - Utilizes dynamic programming for efficient computation
 *
 * Usage:
 *  - Enter the number of elements (keys)
 *  - Enter a numerical or alphabetic key for each element (a)
 *  - Enter the probability for each element's occurrence (p)
 *  - Enter the probability for searches falling between the elements (q)
 *
 * The program calculates and displays the minimum cost for the constructed OBST and its root.
 * Complexity in the worst-case scenario is O(n^3), where n is the number of keys.
 */

#include "obst.h"

/* Initial the variables and arrays we will be using,
   counters i,k;
*/
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
        // This function call remains valid but is defined in utils.c
        treeOutput(i, j, ar.w[i][j], ar.c[i][j], ar.r[i][j]);
      }
    }
  }
  // This function call remains valid but is defined in utils.c
  printLevel();
}

/*
    OBST, Produces Computational Matrix, Minimum cost, and Root
*/
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
        // This function call remains valid but is defined in utils.c
        treeOutput(i, j, ar.w[i][j], ar.c[i][j], ar.r[i][j]);
      }
    }
    // This function call remains valid but is defined in utils.c
    printLevel();
  }
}

int main()
{
  // This function call remains valid but is defined in utils.c
  getInput();
  initOBST();
  OBST();

  // Print Minimum cost to console
  printf("Minimum cost = %.03f\n", ar.c[0][ts.n]);

  // Set root variable to determined root
  ts.root = ar.r[0][ts.n];

  // Print root of tree to console
  printf("Root = %.03f\n", ts.root);

  // This function call remains valid but is defined in utils.c
  lineDraw();

  return 0;
}
