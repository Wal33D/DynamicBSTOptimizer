/***************************************************************************************

* Course: Desgin & Analysis of Algorithms – Fall 2014
* Assignment <6>
* Name: <Waleed Gudah>
* E-mail: <waleed.h.gudah@wmich.edu>
* Submitted: <11/18/14>

  This is an Optimal Binary Search Tree Algorithms. 

   (1) Enter # of elements 
   (2) Enter a numerical or alphabetic key for each element (a)
   (3) Enter each element (p)
   (4) Enter the probability of each element (q)
  
  It outputs the computational matrix associated with p and q input sets, the root, and the min cost

  If all c(i, j )’s and r(i, j)’s are calculated, then OBST algorithm in worst case takes O(n3) time 
  
/****************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
#define INT_MAX 30000
#define charMAX 1000

struct treeStats {
  
  int n;
  float temp, root, min, min1;

}ts;

struct arrays {

  char ele[MAX][MAX], W[charMAX], C[charMAX], R[charMAX], a[charMAX];
  float w[MAX][MAX], c[MAX][MAX], r[MAX][MAX], p[MAX], q[MAX];

}ar;

/* Store W on 1 line, Store C on 1 line, Store R on 1 line */
void treeOutput(int i, int j, double w, double c, double r) {

   sprintf(ar.W, "%sW[%d][%d]: %.03f\t",ar.W,i,j, w);
   sprintf(ar.C, "%sC[%d][%d]: %.03f\t",ar.C,i,j, c);
   sprintf(ar.R, "%sR[%d][%d]: %.03f\t",ar.R,i,j, r);

}

/* Print current level of tree, Set W,C,R to empty string to prepare for next level */
void printLevel() {

    printf("\n%s\n%s\n%s\n",ar.W,ar.C,ar.R);
    sprintf(ar.W,"");
    sprintf(ar.C,"");
    sprintf(ar.R,"");

}

/* lineDraw() is used to print the divider inbetween prompts */
void lineDraw() {

  printf("\n--------------------------------\n");

}

/* Get user input, Keys, Elements, Probability */
void getInput(){
  
  int i;
  float numer,deno;
  printf("Enter the number of elements:");
  scanf("%d",&ts.n);

 /* Get Keys from user (a) */
  lineDraw();
  for(i=1; i <= ts.n; i++) {

    printf("Enter the A of %d:",i);
    scanf("%s",&ar.a[i]);
 
  }

 /* Get Elements from user (p) */
  lineDraw();
  for(i=1; i <= ts.n; i++) {

    printf("Enter the P (Element) of %d:\n-Fraction Numertator: ",i); 
     
    scanf("%f",&numer);
    
    printf("-Fraction Denominator: ");

    scanf("%f",&deno);

     printf("--%.0f/%.0f\n",numer, deno); 

    ar.p[i] = numer/deno;
    
  }

 /* Get Probabilities from user (q) */
  lineDraw();
  for(i=0; i <= ts.n; i++) {

    printf("Enter the Q (Probability) of %d:\n-Fraction Numertator: ",i); 
     
    scanf("%f",&numer);
    
    printf("-Fraction Denominator: ");

    scanf("%f",&deno);
   
    printf("--%.0f/%.0f\n",numer, deno); 
   
    ar.q[i] = numer/deno;

  }

   lineDraw();

}

/* Initial the the variables and arrays we will be using, 
   counters i,k;
*/
void initOBST(){

  int i, j;
 
  ts.temp = 0.0;

  for(i=0; i <= ts.n; i++) {

    for(j=0; j <= ts.n; j++) {
      
      if(i == j) {

        ar.w[i][j] = ar.q[i];
        ar.c[i][j] = 0.0;
        ar.r[i][j] = 0.0;

       treeOutput(i,j,ar.w[i][j],ar.c[i][j],ar.r[i][j]);

      }

    }

  }

  printLevel();

}

/* 
    OBST, Produces Computational Matrix, Minimum cost, and Root 

*/

void OBST(){
 
  int i, j, k, b;
 
  for(b = 0; b < ts.n; b++){

    for(i = 0, j = b + 1; (j < ts.n + 1) && (i < ts.n + 1); j++,i++) {

      if(i != j && i < j)  {

         ar.w[i][j] = ar.p[j] + ar.q[j] + ar.w[i][j-1];
        
         ts.min = INT_MAX;

        for(k = i+1; k <= j; k++){

            ts.min1 = ar.c[i][k-1] + ar.c[k][j] + ar.w[i][j];

          if(ts.min > ts.min1){
        
            ts.min = ts.min1;
            ts.temp = k;

          }

        }

        ar.c[i][j] = ts.min;
        ar.r[i][j] = ts.temp;

      }

      treeOutput(i,j,ar.w[i][j],ar.c[i][j],ar.r[i][j]);
   
    }

  printLevel();

  }

}

/* int main() is our control function */
int main() {

  /* Call our getInput() method to collect a, p & q */
  getInput();
  /*Initialize OBST*/
  initOBST();
  /* Call our OBST */
  OBST();
  /* Helper Method - it prints a line seperator */
  lineDraw();
  /* Print Minimum cost to console */
  printf("Minimum cost = %.03f\n",ar.c[0][ts.n]);
  /* Set root variable to determined root */
  ts.root = ar.r[0][ts.n];
  /* Print root of tree to console */
  printf("Root  = %.03f",ts.root);
  /* Helper Method - it prints a line seperator */
  lineDraw();

return 0;

}