int jump(int* nums, int numsSize) {

    // If already at last index
    if(numsSize <= 1)
        return 0;

    int jumps = 0;
    int currentEnd = 0;
    int farthest = 0;

    for(int i = 0; i < numsSize - 1; i++) {

        // Find farthest reachable index
        if(i + nums[i] > farthest)
            farthest = i + nums[i];

        // End of current jump range
        if(i == currentEnd) {
            jumps++;
            currentEnd = farthest;
        }
    }

    return jumps;
}
