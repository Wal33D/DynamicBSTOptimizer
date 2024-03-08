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

/* Initialize the OBST with given probabilities and keys */
void initializeOptimalBinarySearchTree()
{
    int indexI, indexJ;
    treeNodeStruct.tempProbability = 0.0;
    for (indexI = 0; indexI <= treeNodeStruct.numberOfElements; indexI++)
    {
        for (indexJ = 0; indexJ <= treeNodeStruct.numberOfElements; indexJ++)
        {
            if (indexI == indexJ)
            {
                arrayStruct.weightMatrix[indexI][indexJ] = arrayStruct.probabilityQ[indexI];
                arrayStruct.costMatrix[indexI][indexJ] = 0.0;
                arrayStruct.rootMatrix[indexI][indexJ] = 0.0;
                treeOutput(indexI, indexJ, arrayStruct.weightMatrix[indexI][indexJ], arrayStruct.costMatrix[indexI][indexJ], arrayStruct.rootMatrix[indexI][indexJ]);
            }
        }
    }
    printLevel();
}

/* Compute the OBST and its minimum cost */
void computeOptimalBinarySearchTree()
{
    int indexI, indexJ, indexK, breadth;
    for (breadth = 0; breadth < treeNodeStruct.numberOfElements; breadth++)
    {
        for (indexI = 0, indexJ = breadth + 1; (indexJ < treeNodeStruct.numberOfElements + 1) && (indexI < treeNodeStruct.numberOfElements + 1); indexJ++, indexI++)
        {
            if (indexI != indexJ && indexI < indexJ)
            {
                arrayStruct.weightMatrix[indexI][indexJ] = arrayStruct.probabilityP[indexJ] + arrayStruct.probabilityQ[indexJ] + arrayStruct.weightMatrix[indexI][indexJ - 1];
                treeNodeStruct.minimumCost = INT_MAX;
                for (indexK = indexI + 1; indexK <= indexJ; indexK++)
                {
                    treeNodeStruct.temporaryMinimumCost = arrayStruct.costMatrix[indexI][indexK - 1] + arrayStruct.costMatrix[indexK][indexJ] + arrayStruct.weightMatrix[indexI][indexJ];
                    if (treeNodeStruct.minimumCost > treeNodeStruct.temporaryMinimumCost)
                    {
                        treeNodeStruct.minimumCost = treeNodeStruct.temporaryMinimumCost;
                        treeNodeStruct.tempProbability = indexK;
                    }
                }
                arrayStruct.costMatrix[indexI][indexJ] = treeNodeStruct.minimumCost;
                arrayStruct.rootMatrix[indexI][indexJ] = treeNodeStruct.tempProbability;
                treeOutput(indexI, indexJ, arrayStruct.weightMatrix[indexI][indexJ], arrayStruct.costMatrix[indexI][indexJ], arrayStruct.rootMatrix[indexI][indexJ]);
            }
        }
        printLevel();
    }
}

int main()
{
    getInput();
    initializeOptimalBinarySearchTree();
    computeOptimalBinarySearchTree();

    printf("Minimum cost = %.03f\n", arrayStruct.costMatrix[0][treeNodeStruct.numberOfElements]);
    treeNodeStruct.root = arrayStruct.rootMatrix[0][treeNodeStruct.numberOfElements];
    printf("Root = %.03f\n", treeNodeStruct.root);
    lineDraw();

    return 0;
}
