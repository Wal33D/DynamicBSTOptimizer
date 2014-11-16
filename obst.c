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
  
  It outputs the computational matrix associated with p and q input sets
  
/****************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define intMAX 10
#define charMAX 1000

/*Error handling for pthread_create and pthread_join*/
#define handle_error_en(en, msg) \
        do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

  int n;

struct treeStats {

  int temp;
  int root;
  int min;
  int min1;

}treeStats;

char ele[intMAX][intMAX];
char W[charMAX], C[charMAX], R[charMAX], a[charMAX];
float w[intMAX][intMAX], c[intMAX][intMAX], r[intMAX][intMAX], p[intMAX], q[intMAX];

/* Store W on 1 line, Store C on 1 line, Store R on 1 line */
void treeOutput(int i, int j, int w, int c, int r) {

   sprintf(W, "%sW[%d][%d]: %d\t",W,i,j, w);
   sprintf(C, "%sC[%d][%d]: %d\t",C,i,j, c);
   sprintf(R, "%sR[%d][%d]: %d\t",R,i,j, r);

}

/* Print current level of tree, Set W,C,R to empty string to prepare for next level */
void printLevel() {

    printf("\n%s\n%s\n%s\n",W,C,R);
    sprintf(W,"");
    sprintf(C,"");
    sprintf(R,"");

}

/* Get user input, Keys, Elements, Probability */
void getInput(){
  
  int i;
  
  printf("Enter the number of elements:");
  scanf("%d",&n);

  lineDraw();
  for(i=1; i <= n; i++) {

    printf("Enter the A of %d:",i);
    scanf("%s",&a[i]);
 
  }

  lineDraw();
  for(i=1; i <= n; i++) {

    printf("Enter the P (Element) of %d:",i);
    scanf("%f",&p[i]);
 
  }

  lineDraw();
  for(i=0; i <= n; i++) {

    printf("Enter the Q (Probability) of %d:",i);
    scanf("%f",&q[i]);

  }

   lineDraw();

}
/* OBST, Produces Computational Matrix, Minimum cost, and Root */
void OBST(){

  int i;
  int j;
  int k;
  int b;

 treeStats.temp = 0;

 for(i=0; i <= n; i++) {

    for(j=0; j <= n; j++) {
      
      if(i == j) {

        w[i][j] = q[i];
        c[i][j] = 0;
        r[i][j] = 0;

       treeOutput(i,j,w[i][j],c[i][j],r[i][j]);

      }

    }

  }

  printLevel();

  for(b = 0; b < n; b++){

    for(i = 0, j = b + 1; (j < n + 1) && (i < n + 1); j++,i++) {

      if(i != j && i < j)  {

        w[i][j] = p[j] + q[j] + w[i][j-1];
        
         treeStats.min = 30000;

        for(k = i+1; k <= j; k++){

            treeStats.min1 = c[i][k-1] + c[k][j] + w[i][j];

          if(treeStats.min > treeStats.min1){
        
            treeStats.min = treeStats.min1;
            treeStats.temp = k;

          }

        }

        c[i][j] = treeStats.min;
        r[i][j] = treeStats.temp;

      }

      treeOutput(i,j,w[i][j],c[i][j],r[i][j]);
   
    }

  printLevel();

  }

}

/* lineDraw() is used to print the divider inbetween prompts */
void lineDraw() {

  printf("\n--------------------------------\n");

}

/* int main() is our control function */
int main() {

  /* Call our getInput() method to collect a, p & q */
  getInput();
  /* Call our OBST */
  OBST();
  /* Helper Method - it prints a line seperator */
  lineDraw();
  /* Print Minimum cost to console */
  printf("Minimum cost = %f\n",c[0][n]);
  /* Set root variable to determined root */
  treeStats.root = r[0][n];
  /* Print root of tree to console */
  printf("Root  = %d",treeStats.root);
  /* Helper Method - it prints a line seperator */
  lineDraw();

return 0;

}