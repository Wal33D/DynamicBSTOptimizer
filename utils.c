#include <stdio.h>
#include "obst.h"

/* 
   Get user input, Keys, Elements, Probability 
   This function prompts the user to input the number of elements, 
   keys for each element, probability, and the fraction of each element.
*/

void getInput()
{
  int i;
  float numer, deno;
  
  // Prompt user for the number of elements
  printf("Enter the number of elements:");
  scanf("%d", &ts.n);
  lineDraw(); // Draw a line to separate prompts
  
  // Prompt user for keys of each element
  for (i = 1; i <= ts.n; i++)
  {
    printf("Enter the A of %d:", i);
    scanf("%s", ar.a[i]); // Removed & as it's not needed for array
  }
  lineDraw(); // Draw a line to separate prompts
  
  // Prompt user for elements (p)
  for (i = 1; i <= ts.n; i++)
  {
    printf("Enter the P (Element) of %d:\n-Fraction Numertator: ", i);
    scanf("%f", &numer);
    printf("-Fraction Denominator: ");
    scanf("%f", &deno);
    printf("--%.0f/%.0f\n", numer, deno);
    ar.p[i] = numer / deno;
  }
  lineDraw(); // Draw a line to separate prompts
  
  // Prompt user for probabilities (q)
  for (i = 0; i <= ts.n; i++)
  {
    printf("Enter the Q (Probability) of %d:\n-Fraction Numertator: ", i);
    scanf("%f", &numer);
    printf("-Fraction Denominator: ");
    scanf("%f", &deno);
    printf("--%.0f/%.0f\n", numer, deno);
    ar.q[i] = numer / deno;
  }
  lineDraw(); // Draw a line to separate prompts
}

/* lineDraw() is used to print the divider between prompts */
void lineDraw()
{
  printf("\n--------------------------------\n");
}

/* Store W on 1 line, Store C on 1 line, Store R on 1 line */
void treeOutput(int i, int j, double w, double c, double r)
{
  sprintf(ar.W, "%sW[%d][%d]: %.03f\t", ar.W, i, j, w);
  sprintf(ar.C, "%sC[%d][%d]: %.03f\t", ar.C, i, j, c);
  sprintf(ar.R, "%sR[%d][%d]: %.03f\t", ar.R, i, j, r);
}

/* Print current level of tree, Set W,C,R to empty string to prepare for next level */
void printLevel()
{
  printf("\n%s\n%s\n%s\n", ar.W, ar.C, ar.R);
  sprintf(ar.W, "");
  sprintf(ar.C, "");
  sprintf(ar.R, "");
}
