/*
    this file implements the linear search algorithm

    complexity : O(n^n)


    author : kq.

*/
// lib attach
#include <stdio.h>

// define the array_size
#define array_size 10

// this values indicates the return state of the linear search function.
#define FALSE 0
#define TRUE 1


// prototypes
int linearSearch(int *array,int size, int target);

// this will create an sorted array and give us back the pointer to the first element of the source array add
int * arrayCreator(int *array_source , int size);

// entry
int main(void) { 
    //init the arrayt.
    int numbers[array_size];
    
    int *numbersArray_pointer =  arrayCreator(numbers,array_size);
    
    //return the state.
    int res =  linearSearch(numbersArray_pointer,array_size,9);
    

    // error checking.
    if (res) { 
        printf("the value you are looking for is exists");
        return 0 ;
        // this indicates that the linear search does its works;
    }
    
    printf("canot found the value");
    return 1;
    // this indicates that the linear search does not found the shit we want;

    
}

// return the pointer to the array source argument.
int * arrayCreator(int *array_source, int size) { 
// this will gives you some some sorted value but it will work for unsorted things as well
    for(int i = 0;i< size ; i++) { 
        array_source[i] = i;
    }       

    return array_source;
}



/* if find the target within the array it will return the true otherwise with any other causes with
 will return false */
int linearSearch(int *array, int size, int target) { 
    

    // some input checking.
    if (size < 1 ) {
        return FALSE;
    }

    for (int i = 0;i < size ; i++) { 
        // only find the first occurance.
        if (array[i] == target) { 
            // found.
            return TRUE;
        }
    }

    // not found.
    return FALSE;
        
}


// usage : ./run {path to this file}

//OK.

