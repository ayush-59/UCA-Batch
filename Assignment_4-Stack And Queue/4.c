/*
 * Problem-4: Largest Rectangle in Histogram
 * Ayush Singh 1910990059 10/08/21
 * Assignment_4 -> Stack and Queue
*/

int largestRectangleArea(int* heights, int heightsSize){
    int i, j, count, currLength, currArea, maxArea = (int)(-INFINITY);
    for(i = 0; i < heightsSize; i++){
        currLength = heights[i];
        count = 1;  //stores no. of rect have same or less currLength
        //condition to avoid calculating duplicate rectangle area
        if(i != 0 && currLength == heights[i-1])
            continue;

        //Calculating length of rectangle with currLength on left
        for(j = i-1; j >= 0; j--){
            if(heights[j] >= currLength)
                count++;
            else
                break;
        }
        //Calculating length of rectangle with currLength on left
        for(j = i+1; j < heightsSize; j++){
            if(heights[j] >= currLength)
                count++;
            else
                break;
        }
        currArea = currLength*count;
        if(maxArea < currArea)
            maxArea = currArea;

    }
    return maxArea;
}
