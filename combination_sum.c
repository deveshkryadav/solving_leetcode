/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int **result;
int *colSizes;
int resultCount;

void backtrack(int* candidates, int candidatesSize, int target,
               int start, int* path, int pathSize) {

    // found valid combination
    if (target == 0) {
        result[resultCount] = (int*)malloc(pathSize * sizeof(int));

        for (int i = 0; i < pathSize; i++) {
            result[resultCount][i] = path[i];
        }

        colSizes[resultCount] = pathSize;
        resultCount++;
        return;
    }

    // try every candidate from current index
    for (int i = start; i < candidatesSize; i++) {

        // skip if number becomes too large
        if (candidates[i] > target)
            continue;

        path[pathSize] = candidates[i];

        // i (not i+1) because same element can be reused
        backtrack(candidates, candidatesSize,
                  target - candidates[i],
                  i,
                  path,
                  pathSize + 1);
    }
}

int** combinationSum(int* candidates, int candidatesSize,
                     int target,
                     int* returnSize,
                     int** returnColumnSizes) {

    result = (int**)malloc(150 * sizeof(int*));
    colSizes = (int*)malloc(150 * sizeof(int));
    resultCount = 0;

    int path[100];

    backtrack(candidates, candidatesSize,
              target,
              0,
              path,
              0);

    *returnSize = resultCount;
    *returnColumnSizes = colSizes;

    return result;
}
