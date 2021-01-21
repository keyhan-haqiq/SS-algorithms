/* this file implements the  binary search with the  efficiency of the O(log n) 

complexit : O(log n) 


author : kq.
*/

#include <stdio.h>
// import the standard lib.

// define the arraySize constant
#define array_size 10

// use for avoid using stdbool.h headerfile.
#define FALSE 0
#define TRUE 1


// binarySearch prototype .
int binarySearch(int *array, int size, int target);


// entry
int main(void) { 
    // init the sorted array from the constant time. - ARRAY MUST BE SORTED !!!!!
    int sortedArray[array_size] = {1,2,3,4,5,6,7,8,9};
    // here we search for the 100 in our sorted array.
    int res = binarySearch(sortedArray,array_size,100);

    // some checking.
    if (res) { 
        printf(" the value is there :D");
        //exit code 0 -> suc
        return 0;
    }

    printf(" canot found the value :( ");
    // exit code 1 -> fai
    return 1;

}

// binary search definition.
int binarySearch(int *array, int size, int target) { 
    // some user input checking.
    if (size < 1) { 
        return FALSE;
    }

    //end of the array.
    int head = size;

    // first of the array.
    int tail = 0;

    // order is -> tail to head not head to tail.

    // middle of the array.
    int middle;

    while (tail <= head) { 
        middle = (tail + head) >> 1;
        
        if (array[middle] == target) { 
            // true is the state is not the exit code of the one.
            return TRUE;


        } else if (array[middle] > target) { 
            head = middle - 1;
            // search the left half
            // if the head is  changed by this line the middle for the next iteration gonna changed.

        } else   { 
            // same as the above line.
            //search the right half
            tail = middle + 1;
        }

    }

    // not found the value.
    // false simply indicates the false state not the exit code in this function.
    return FALSE;
}

//usage from the root -> ./run {path to this file}

//OK.