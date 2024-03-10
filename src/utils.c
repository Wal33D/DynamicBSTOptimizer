#include "utils.h"

struct treeStats ts;
struct arrays ar;

// Store W on 1 line, Store C on 1 line, Store R on 1 line
void treeOutput(int i, int j, double w, double c, double r)
{
  // Temporary buffers to store individual strings
  char tempW[100], tempC[100], tempR[100];

  // Safely format strings with snprintf and append using strncat
  snprintf(tempW, sizeof(tempW), "W[%d][%d]: %.03f\t", i, j, w);
  snprintf(tempC, sizeof(tempC), "C[%d][%d]: %.03f\t", i, j, c);
  snprintf(tempR, sizeof(tempR), "R[%d][%d]: %.03f\t", i, j, r);

  // Check and append if there's enough space
  if (strlen(ar.W) + strlen(tempW) < charMAX)
    strncat(ar.W, tempW, sizeof(ar.W) - strlen(ar.W) - 1);
  if (strlen(ar.C) + strlen(tempC) < charMAX)
    strncat(ar.C, tempC, sizeof(ar.C) - strlen(ar.C) - 1);
  if (strlen(ar.R) + strlen(tempR) < charMAX)
    strncat(ar.R, tempR, sizeof(ar.R) - strlen(ar.R) - 1);
}

// Print current level of tree, Set W,C,R to empty string to prepare for next level
void printLevel()
{
  printf("\n%s\n%s\n%s\n", ar.W, ar.C, ar.R);

  // Reset W, C, R to empty strings efficiently
  ar.W[0] = '\0';
  ar.C[0] = '\0';
  ar.R[0] = '\0';
}

// lineDraw() is used to print the divider inbetween prompts
void lineDraw()
{

  printf("\n--------------------------------\n");
}

// Get user input, Keys, Elements, Probability
void getInput(void)
{

    int i;
    float numer, deno;
    printf("Enter the number of elements:");
    scanf("%d", &ts.n);

    // Get Keys from user (a)
    lineDraw();
    for (i = 1; i <= ts.n; i++)
    {

        printf("Enter the A of %d:", i);
        scanf("%s", &ar.a[i]);
    }

    // Get Elements from user (p)
    lineDraw();
    for (i = 1; i <= ts.n; i++)
    {

        printf("Enter the P (Element) of %d:\n-Fraction Numertator: ", i);

        scanf("%f", &numer);

        printf("-Fraction Denominator: ");

        scanf("%f", &deno);

        printf("--%.0f/%.0f\n", numer, deno);

        ar.p[i] = numer / deno;
    }

    // Get Probabilities from user (q)
    lineDraw();
    for (i = 0; i <= ts.n; i++)
    {

        printf("Enter the Q (Probability) of %d:\n-Fraction Numertator: ", i);

        scanf("%f", &numer);

        printf("-Fraction Denominator: ");

        scanf("%f", &deno);

        printf("--%.0f/%.0f\n", numer, deno);

        ar.q[i] = numer / deno;
    }

    lineDraw();
}
