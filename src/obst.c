#include "obst.h" 

// Initializes the matrices used in the OBST calculation.
void initOBST()
{
  int i, j; // Loop counters.
  treeStats.temporaryRoot = 0.0; // Initialize temporary root for calculation.
  
  // Initialize the weight (w), cost (c), and root (r) matrices.
  for (i = 0; i <= treeStats.n; i++)
  {
    for (j = 0; j <= treeStats.n; j++)
    {
      if (i == j) // Diagonal elements where tree only has one node.
      {
        treeData.w[i][j] = treeData.q[i]; // Weight is equal to the probability of searching for a non-existent element.
        treeData.c[i][j] = 0.0; // Cost is zero since there are no deeper levels.
        treeData.r[i][j] = 0.0; // Root is set to zero as placeholder.

        // Output the initial values for w, c, and r for this (i, j) pair.
        treeOutput(i, j, treeData.w[i][j], treeData.c[i][j], treeData.r[i][j]);
      }
    }
  }

  // Print the initialized level of matrices.
  printLevel();
}

// Main algorithm to calculate the OBST based on dynamic programming.
void OBST()
{
  int i, j, k, b; // Loop counters and indices.
  // Iterate through all possible subtrees and calculate costs.
  for (b = 0; b < treeStats.n; b++)
  {
    for (i = 0, j = b + 1; (j < treeStats.n + 1) && (i < treeStats.n + 1); j++, i++)
    {
      if (i != j && i < j) // Ensure we're looking at valid subtrees.
      {
        // Calculate weight of the subtree.
        treeData.w[i][j] = treeData.p[j] + treeData.q[j] + treeData.w[i][j - 1];
        // Initialize the minimum cost to a large value.
        treeStats.minimumCost = INT_MAX;
        // Iterate through possible roots of the subtree.
        for (k = i + 1; k <= j; k++)
        {
          // Calculate the cost if k is the root.
          treeStats.minimumCost1 = treeData.c[i][k - 1] + treeData.c[k][j] + treeData.w[i][j];
          // Update minimum cost and root if a new minimum is found.
          if (treeStats.minimumCost > treeStats.minimumCost1)
          {
            treeStats.minimumCost = treeStats.minimumCost1;
            treeStats.temporaryRoot = k;
          }
        }
        // Update matrices with the minimum cost and root found.
        treeData.c[i][j] = treeStats.minimumCost;
        treeData.r[i][j] = treeStats.temporaryRoot;

        // Output the calculated values for w, c, and r for this (i, j) pair.
        treeOutput(i, j, treeData.w[i][j], treeData.c[i][j], treeData.r[i][j]);
      }
    }

    // Print the calculated level of matrices.
    printLevel();
  }
}

// The main function driving the OBST program.
int main()
{
  // Gather input from the user regarding the elements, probabilities, etc.
  getInput();
  // Initialize the necessary matrices and variables for the OBST calculation.
  initOBST();
  // Perform the OBST calculation based on the provided input.
  OBST();

  // Print the final minimum cost to build the OBST.
  printf("Minimum cost = %.03f\n", treeData.c[0][treeStats.n]);

  // Determine and print the root of the OBST.
  treeStats.root = treeData.r[0][treeStats.n];
  printf("Root = %.03f\n", treeStats.root);

  // Draw a line for visual separation at the end.
  lineDraw();

  return 0; // End of program.
}
