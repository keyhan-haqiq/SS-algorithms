/*
    this file is the implementaion of the merge sort algorithm.

    complexity : O(nlogn);
    // because we have need to sort all ns in the log n section of the array.

    author : kq.
*/

//attach libs . 
#include <stdio.h>

// use for exit() . 
#include <stdlib.h>

// define the length of the array_size.
#define array_size 10


// check for the array assignments


//prototypes.
void mergeSort(int array[] , int low, int high);
void merge(int array[], int low, int middle,int high);
void arrayExpo(int *array, int size); // use for presentaion .
void line(); // use for dividing the output.


// entry.
int main(void) { 
    // init the array from the given length .
    int numbers[array_size] = {0,2,5,29,3,2,5,6,21,2};
    // present the unsorted array.
    arrayExpo(numbers,array_size);

    // draw 3 lines in the stdout.
    line();
    line();
    line();

    // sorting the array.
    mergeSort(numbers,0,array_size-1);


    // present the sorted array.
    arrayExpo(numbers,array_size);




}

// line impl :D
void line() { 
    printf("--------------------------------------------------------------------------- \n");
}


// array presentaion impl -> use the array pointer -> also it can do without pointer.
void arrayExpo(int *array, int size) { 
    printf("[");
    for (int i = 0; i < size ; i++) { 
        if (i >= size -1) { 
            // this means its the last element.
            printf("%i ] \n",array[i]);
        } else    { 
            printf("%i , " , array[i]);
        }

    }

}

void mergeSort(int array[],int low,int high) {
    // calculated the size
    int size = high - low;
    // if size is zero means no array or non initialized array.
    if (size < 0 ) { 
        printf("we exit the code due to the bad sizedarray");
        // we need to getout of this process. with bad codes :/
        exit(0);
        
    }

    // use long for big data instead of the int.
    if (low < high) {  
        int middle = low + (high - low) / 2; // same az getting the middle use for avoid overflow

        // middle = (low + high) >> 1;
        mergeSort(array,low,middle);
        //sort the left half of the array
        mergeSort(array,middle+1,high);
        // soft the right haf of the array execpt of the middle
        merge(array,low,middle,high);
    }

}
// OK


void merge(int array[],int low, int middle, int high) { 
    //merge the two sub array


    int leftArrayIterator,rightArrayIterator,mergedArrayIterator;


    int lenForLeftArray = middle - low + 1 ; // simply we try to get the size of the temp arrays that gonna store of subs
    // done + 1 because we use middle in the left half.
    int lenForRightArray = high - middle;   // get the size of the temp array 
    //creating the subArrays 

    // createing the tmp arrays of that size
    int leftArraySub[lenForLeftArray] , rightArraySub[lenForRightArray];


    //copy the incoming datas to our array;

    for (leftArrayIterator = 0; leftArrayIterator < lenForLeftArray;leftArrayIterator++) 
            leftArraySub[leftArrayIterator] = array[low + leftArrayIterator];
          // create a left half depends on the low 


    for ( rightArrayIterator = 0; rightArrayIterator < lenForRightArray;rightArrayIterator++) 
             rightArraySub[rightArrayIterator] = array[middle + 1 + rightArrayIterator];
            
            // create a right half depends on the middle + 1;
            

    // this will create the both left and right arrays and then ready them for the mergeing

    // merge the tmp arrays to the main Arrays

    // reinit the value for the second loop.
     // this will done for avoid extra variable using 
    leftArrayIterator = 0;
    rightArrayIterator = 0;
    mergedArrayIterator = low;




    while (leftArrayIterator < lenForLeftArray && rightArrayIterator < lenForRightArray) { 
        if (leftArraySub[leftArrayIterator] <= rightArraySub[rightArrayIterator]) { 
            // compare one from left and one from right
            array[mergedArrayIterator] = leftArraySub[leftArrayIterator];
            // here we try to change the real array starting with the zero index(merge iterator) and create new array from it and from 
            // the comparision of the two left and right array;

            leftArrayIterator ++;
            // you have to just increment what you pick from.
        } else { 
            array[mergedArrayIterator] = rightArraySub[rightArrayIterator];
            rightArrayIterator ++;
            // only if we put something from one of the left or right arrays we only increament the iterator of that array that we 
            // take something from it;
        }

    // this will always incer
        mergedArrayIterator ++;
        // this loop is created for the creating the merged  array and 
        // the main iterator of it is mergedArrayIterator;
    }

    //after we get out of this loop and done the mergeing and get the final merged array;
    // maybe some reminaing from the both left and right arrays remains;

    // for that

    //we dont mutate the iterators of both  left or right because we need to keep track of what kinds of values dont put on the main array;

    // we actually dont change the mergedArrayIterator to keep track of the merged indexes



    while (leftArrayIterator < lenForLeftArray) { 
        array[mergedArrayIterator] = leftArraySub[leftArrayIterator];
        leftArrayIterator ++;
        mergedArrayIterator ++;

    }
    // we done with the left array.



    while (rightArrayIterator < lenForRightArray) { 
        array[mergedArrayIterator] = rightArraySub[rightArrayIterator];
        rightArrayIterator ++;
        mergedArrayIterator ++;
    }
    // we done with the right array.
// done the merging.
}

// usage : ./run {path to the file}

// Ok.