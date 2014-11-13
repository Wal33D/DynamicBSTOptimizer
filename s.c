
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define intMAX 10
#define charMAX 1000

char W[charMAX];
char C[charMAX];
char R[charMAX];
char a[charMAX];
char ele[intMAX][intMAX];
float w[intMAX][intMAX], c[intMAX][intMAX], r[intMAX][intMAX], p[intMAX], q[intMAX];
int temp=0, root, min, min1, n;
int i,j,k,b;  

void treeOutput(int i, int j, int w, int c, int r) {

   sprintf(W, "%sW[%d][%d]: %d\t",W,i,j, w);
   sprintf(C, "%sC[%d][%d]: %d\t",C,i,j, c);
   sprintf(R, "%sR[%d][%d]: %d\t",R,i,j, r);

  }

}

void printLevel(){

    printf("\n%s\n%s\n%s\n",W,C,R);
    sprintf(W,"");
    sprintf(C,"");
    sprintf(R,"");

}

void getInput(){

  printf("Enter the number of elements:");

  scanf("%d",&n);

  printf("\n--------------------------------\n");

  for(i=1; i <= n; i++) {

    printf("Enter the A of %d:",i);
   
    scanf("%s",&a[i]);
 
  }

  printf("\n--------------------------------\n");

  for(i=1; i <= n; i++) {

    printf("Enter the P (Element) of %d:",i);
   
    scanf("%f",&p[i]);
 
  }
  printf("\n--------------------------------\n");

  for(i=0; i <= n; i++) {

    printf("Enter the Q (Probability) of %d:",i);
   
    scanf("%f",&q[i]);

  }

   printf("\n--------------------------------");

}

void main() {

 getInput();
 printKeys();

  for(i=0; i <= n; i++){

    for(j=0; j <= n; j++){
      
      if(i == j){

        w[i][j] = q[i];

        c[i][j] = 0;

        r[i][j] = 0;

       treeOutput(i,j,w[i][j],c[i][j],r[i][j]);

      }

    }

  }

  printLevel();

  for(b=0; b < n; b++){

    for(i=0,j=b+1; j < n+1 && i < n+1; j++,i++) {

      if(i!=j && i < j)  {

        w[i][j] = p[j] + q[j] + w[i][j-1];
        
        min = 30000;

        for(k = i+1; k <= j; k++){

          min1 = c[i][k-1] + c[k][j] + w[i][j];

          if(min > min1){
        
            min = min1;

            temp = k;

          }

        }

        c[i][j] = min;
        r[i][j] = temp;
      }

      treeOutput(i,j,w[i][j],c[i][j],r[i][j]);
  

   
    }

  printLevel();

  }

  printf("\n-------------------------\nMinimum cost = %f\n",c[0][n]);

  root = r[0][n];

  printf("Root  = %d \n--------------------------------\n",root);

  getchar();

}