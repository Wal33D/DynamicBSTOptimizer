#include <stdio.h>
#include "obst.h"

// Function to get input from the user. This includes the number of elements, and for each element:
// - Its key (denoted as 'A')
// - Its associated probability (element 'P')
// - Its search probability when it's not found ('Q')
void getInput()
{
  int i; // Loop counter
  float numer, deno; // Temporary variables to store numerator and denominator for fractional inputs

  // Prompt user to enter the number of elements in the binary search tree
  printf("Enter the number of elements:");
  scanf("%d", &treeStats.n); // Read and store the number of elements in the treeStats structure
  lineDraw(); // Draw a line for visual separation

  // Loop to get the keys ('A') of the elements
  for (i = 1; i <= treeStats.n; i++)
  {
    printf("Enter the A of %d:", i); // Prompt for the i-th element's key
    scanf("%s", treeData.a[i]); // Read and store the key in the treeData structure
  }
  lineDraw(); // Draw a line for visual separation

  // Loop to get the elements ('P') and their numerator and denominator
  for (i = 1; i <= treeStats.n; i++)
  {
    printf("Enter the P (Element) of %d:\n-Fraction Numertator: ", i); // Prompt for the element's probability numerator
    scanf("%f", &numer); // Read numerator
    printf("-Fraction Denominator: "); // Prompt for the denominator
    scanf("%f", &deno); // Read denominator
    printf("--%.0f/%.0f\n", numer, deno); // Print the fraction for verification
    treeData.p[i] = numer / deno; // Calculate and store the fraction as a float
  }
  lineDraw(); // Draw a line for visual separation

  // Loop to get the search probabilities ('Q') for not found elements and their numerator and denominator
  for (i = 0; i <= treeStats.n; i++)
  {
    printf("Enter the Q (Probability) of %d:\n-Fraction Numertator: ", i); // Prompt for the probability's numerator
    scanf("%f", &numer); // Read numerator
    printf("-Fraction Denominator: "); // Prompt for the denominator
    scanf("%f", &deno); // Read denominator
    printf("--%.0f/%.0f\n", numer, deno); // Print the fraction for verification
    treeData.q[i] = numer / deno; // Calculate and store the fraction as a float
  }
  lineDraw(); // Draw a line for visual separation
}

// Function to draw a line in the console for visual separation of different sections
void lineDraw()
{
  printf("\n--------------------------------\n");
}

// Function to format and print the computed W, C, and R matrices' values for a given (i, j) pair
void treeOutput
