/* this file is  implementaion of the selection sort algorithm
 
  complexity : O(n*n) and its very bad dont use it  
  
  author : kq.
  */

// lib attach
#include <stdio.h>

// array size constant -> avoid mem usage.
#define ARRAY_SIZE 10

// prototypes . 
int * selection_sort(int *array , int size);
void array_representaion(int *array, int size);

//entry.
int main(void) { 
    // on sorted.
   int numbers[ARRAY_SIZE] = {1,3,2,5,7,3,5,6,10,4};
   printf("before - > " );
   array_representaion(numbers,ARRAY_SIZE);
   selection_sort(numbers,ARRAY_SIZE);
   printf("after - > "); 
   array_representaion(numbers,ARRAY_SIZE); 
}




// represent arrays in the formated way to stdout.
void array_representaion(int *array,int size) { 
    //ret void.

   printf("[" );
   for (int i = 0;i < size ; i++ ) {
       if (i == (size - 1) ) {
            printf("%i", array[i]);
       }else {
        printf("%i ,",array[i]);
       }
   }
   printf("] \n");
}


// if the given size is < 1 means there is array with the length 0 so we return back the array
// otherwise we start the job 
int* selection_sort(int *array , int size) { 
    // some input checking.
    if (size < 1 ) { 
        printf("the array is already sorted");

        return array; 
    }
    
    
    // NOTE : init the variable outside the loop.
    // keep track of swaps.
    int swapCounter = 0; 
    int minIndex;
    int tmp; // use for swaping.

    
    for (int i = 0;i < size ;i++) { 
        // for each parent iteration we pick the min value
        minIndex = i;
            // for each child interation we just compare the min value for each of that array value.
            // if we find less we change the min to that index.
        for (int j = i + 1;j < size ; j++ ) {
            if (array[j] < array[minIndex]) { 
                minIndex = j;
            }
        }
        // we check if the parent iteration counter is not the min means that means was changed
        // so we have to do swaping.
        if( i != minIndex ) {
            // SWAP
            tmp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = tmp;
            swapCounter ++;
        }
    }
    // reports the swaps
    printf("number of swaps : %i \n" , swapCounter);
    return array; // return the pointer to the fn argument.

}

// run -> TERMINAL : ./run {path to this file}

// OK .






