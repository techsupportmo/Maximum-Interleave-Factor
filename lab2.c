//  Mohammed Ahmed
//  1001655176
//  Lab 2
//  gcc lab2.c


#include <stdio.h>
#include <stdlib.h>

//function that creates interleave of subsequence X, checks if it is present in sequence A
int checkInterleave(int listA[], int listX[], int sizeA, int sizeX, int factor)
{
    
    int count = 0;
    int limit = factor;
    
    //make new subsequence based on factor and size of listX
    int sub[factor * sizeX];
    int sizeSub = factor * sizeX;
    
    
    //loop will run and fill new subsequence with values
    int i;
    for(i = 0; i < sizeX; i++)
    {
        //while the index of sub is less than the limit
        while(count < limit)
        {
            sub[count] = listX[i];
            //printf("%d",sub[count]);
            count++;
        }
        
        
        //increase limit by factor
        limit += factor;
        
    }
    

    
    
    int j;
    i = 0;
    j = 0;
    
    //loops through new subsequence
    while(j < sizeA && i < sizeSub)
    {
        if(sub[i] == listA[j])
        {
            i++;
            j++;
        }
        else
        {
            j++;
        }
        
    }
    
    //checks whether listA contained subsequence
    //returns true or false based on if it finds the entire subsequence
    if(sizeSub == i)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    

    
}




int main(void)
{
    
    int* listA;
    int* listX;
    
    int sizeA;
    int sizeX;
    int factor;
    
    int maxFactor;
    
    
    long buffer;
    
    //get the number of elements of array A
    scanf("%d",&sizeA);
    
    //get the number of elements of array X
    scanf("%d",&sizeX);
    
    
    //dynamically allocate memory based on size of the array (listA)
    listA = (int*)malloc(sizeA * sizeof(int));
    
    //dynamically allocate memory based on size of the array (listX)
    listX = (int*)malloc(sizeX * sizeof(int));
    
    //store values from file into array (list A)
    int i;
    for (i = 0; i < sizeA; i++)
    {
        scanf("%d", &listA[i]);
        
    }
    
    //inputs the buffer (-9999999)
    scanf("%ld",&buffer);
    printf("\n\n");
    
    //store values from file into array (list X)
    for (i = 0; i < sizeX; i++)
    {
        scanf("%d", &listX[i]);
        
    }
    
    //inputs the buffer (-9999999)
    scanf("%ld",&buffer);
    
    //calculate maximum interleave factor
    maxFactor = sizeA / sizeX;
    
    
    
    
    //BINARY SEARCH
    int low = 0;
    int high = maxFactor;
    int max = 0;
    int mid = 0;
    
    while (low<=high)
    {
        mid=(low+high)/2;
        
        //checks interleave subsequence
        if (checkInterleave(listA,listX,sizeA,sizeX,mid))
        {
            //prints passing result
            printf("low %d mid %d high %d passed\n",low,mid,high);
            max = mid;
            low=mid+1;
        }
        else
        {
            //prints failing result
            printf("low %d mid %d high %d failed\n",low,mid,high);
            high=mid-1;
        }
        
        
    }
    
    //maximum repeats
    printf("Maximum repeats is %d",max);
    
    
    //free memory
    free(listA);
    free(listX);
    
    return 0;
}

