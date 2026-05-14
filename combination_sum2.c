/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int **result;
int *colSizes;
int resultCount;

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void backtrack(int* candidates, int candidatesSize,
               int target, int start,
               int* path, int pathSize) {

    // valid combination found
    if (target == 0) {

        result[resultCount] = (int*)malloc(pathSize * sizeof(int));

        for (int i = 0; i < pathSize; i++) {
            result[resultCount][i] = path[i];
        }

        colSizes[resultCount] = pathSize;
        resultCount++;

        return;
    }

    for (int i = start; i < candidatesSize; i++) {

        // skip duplicates
        if (i > start && candidates[i] == candidates[i - 1])
            continue;

        // sorted array optimization
        if (candidates[i] > target)
            break;

        path[pathSize] = candidates[i];

        // i + 1 because each number used once
        backtrack(candidates,
                  candidatesSize,
                  target - candidates[i],
                  i + 1,
                  path,
                  pathSize + 1);
    }
}

int** combinationSum2(int* candidates,
                      int candidatesSize,
                      int target,
                      int* returnSize,
                      int** returnColumnSizes) {

    qsort(candidates,
          candidatesSize,
          sizeof(int),
          compare);

    result = (int**)malloc(200 * sizeof(int*));
    colSizes = (int*)malloc(200 * sizeof(int));
    resultCount = 0;

    int path[100];

    backtrack(candidates,
              candidatesSize,
              target,
              0,
              path,
              0);

    *returnSize = resultCount;
    *returnColumnSizes = colSizes;

    return result;
}
