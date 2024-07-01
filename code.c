#include <stdio.h>

// Function prototypes
void ArrayCreate(int length, int array[]);
void ArrayPrint(int array[], int length);
void ArrayPrintReversed(int array[], int length);
int ArraySum(int array[], int length);
void ArrayCopy(int array[], int array_copy[], int length);
void ArrayFreqOfElements(int array[], int length);
void ArrayPrintUnique(int array[], int length);
void MergeTwoArrays(int a[], int b[], int c[], int length);
void ArraySort(int array[], int length);
void ArrayReverseSort(int array[], int length);
int MaxElement(int array[], int length);
int MinElement(int array[], int length);


int main() {
    int length, choice;

    // Prompt user for the desired length of the array
    printf("Enter the desired length of the array: ");
    scanf("%d", &length);

    // Declare arrays based on the user-provided length
    int array[length];
    int b[length];
    int c[length * 2];
    int array2[length];

    // Initialize array using user-defined function
    ArrayCreate(length, array);

    // Display menu and process user input
    do {
        // Display menu options
        printf("\nMenu Options:\n");
        printf("1) Print Array\n");
        printf("2) Print Array (Reversed)\n");
        printf("3) Calculate Array Sum\n");
        printf("4) Copy Array\n");
        printf("5) Frequency of Elements\n");
        printf("6) Print Unique Elements\n");
        printf("7) Sort Array (Ascending)\n");
        printf("8) Sort Array (Descending)\n");
        printf("9) Find Maximum Element\n");
        printf("10) Find Minimum Element\n");
        printf("11) Merge Two Arrays\n");
        printf("0) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Process user choice
        switch (choice) {
            case 1:
                printf("\nPrinting Array:\n");
                ArrayPrint(array, length);
                break;
            case 2:
                printf("\nPrinting Array in Reversed:\n");
                ArrayPrintReversed(array, length);
                break;
            case 3:
                printf("\nCalculating Array Sum:\n");
                int sum = ArraySum(array, length);
                printf("Sum: %d\n", sum);
                break;
            case 4:
                printf("\nCopying Array:\n");
                ArrayCopy(array, b, length);
                printf("Array copied successfully.\n");
                break;
            case 5:
                printf("\nFrequency of Elements:\n");
                ArrayFreqOfElements(array, length);
                break;
            case 6:
                printf("\nPrinting Unique Elements:\n");
                ArrayPrintUnique(array, length);
                break;
            case 7:
                printf("\nSorting Array in Ascending Order:\n");
                ArraySort(array, length);
                printf("Sorted Array: ");
                ArrayPrint(array, length);
                break;
            case 8:
                printf("\nSorting Array in Descending Order:\n");
                ArrayReverseSort(array, length);
                printf("Reverse Sorted Array: ");
                ArrayPrint(array, length);
                break;
            case 9:
                printf("\nFinding Maximum Element:\n");
                int max = MaxElement(array, length);
                printf("Max Element: %d\n", max);
                break;
            case 10:
                printf("\nFinding Minimum Element:\n");
                int min = MinElement(array, length);
                printf("Min Element: %d\n", min);
                break;
            case 11:
                printf("\nMerging Two Arrays:\n");
                printf("Enter elements for second array:\n");
                ArrayCreate(length, array2);
                MergeTwoArrays(array, array2, c, length);
                printf("Merged Array: ");
                ArrayPrint(c, length * 2);
                break;
            case 0:
                printf("\nExiting the program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}


// question (1.a) write a program to store elements in an array


// @brief creates an array of specified length.
// @param length the length of the array
// @param array[] the array you want to put values in
// @return nothing (void)
void ArrayCreate(int length, int array[]) {
    printf("- - - - - - - - - - - - -\n- - creating Array - -\n- - - - - - - - - - - - -\n");
    int x;
    for (int i = 0; i < length; i++){
        printf("enter value:   ");
        scanf("%d", &x);
        array[i] = x;
    }
}

// question (1.b): write a program to print elements of an array

// @brief prints an array elements, formatted.
// @param length the length of the array
// @param array[] the array you want to print
// @return nothing (void)
void ArrayPrint(int array[], int length){
    printf("[");
    for (int i = 0; i < (length - 1); i++){
        printf("%d, ",array[i]);
    }
    printf("%d", array[length - 1]);
    printf("]\n");

}


// question (2): write a program to print elements of an array in reverse

// @brief prints an array elements, reversed.
// @param length the length of the array
// @param array[] the array you want to print
// @return nothing (void)
void ArrayPrintReversed(int array[], int length){
    printf("[");
    for (int i = (length - 1); i > 0; i--){
        printf("%d, ",array[i]);
    }
    printf("%d", array[0]);
    printf("]\n");

}

// question (3): write a program to find the sum of array elements

// @brief return the sum of the elements of array
// @param length the length of the array
// @param array[] the array you want to print
// @return nothing (void)
int ArraySum(int array[], int length){
    int sum = 0;
    for (int i = 0; i < length ; i++)
        sum += array[i];
    
    return sum;
}


// question (4): write a program to copy elements from a[] to b[]

// @brief copy an array from one to another, of a similar length.
// @param length the length of the array
// @param array[] the array you want to copy from
// @param array_copy[] the array you want to copy to
// @return nothing (void)
void ArrayCopy(int array[], int array_copy[], int length){
    for (int i = 0; i < length; i++)
        array_copy[i] = array[i];
}


// question (5): write a program to count total number of MAX duplicate element in an aray

// @brief copy an array from one to another, of a similar length.
// @param length the length of the array
// @param array[] the array you want to check if a value in it
// @param val the value you want to check
// @return 1 if true;  0 if false
int ValueInArray(int array[], int val, int length){
    for (int i = 0; i < length ; i++){
        if (array[i] == val) return 1;
    }
    return 0;
}

// @brief copy an array from one to another, of a similar length.
// @param length the length of the array
// @param array[] the array you want to test
// @param i the value you want to check
// @return the number of occurnces of an element
int ArrayDuplicateCounter(int array[], int length, int i){
    int checker [length];
    int counter = 0;
    // if the element is not in the array
    if (ValueInArray(checker, array[i], length) == 0){              
            for (int j = 0; j < length; j++){
                // if equal but not same index increase counter
                if ((array[j] == array[i]) && (j != i)){                
                    counter++;
                }
            }
    }

    return counter;

}

// @brief return the element with max occurences
// @param length the length of the array
// @param array[] the array you want to check 
// @return the element with max occurences
int ArrayFindMaxDuplicate(int array[], int length){
    int counter = 0, max = 0;

    for (int i = 0; i < length; i++){
            counter = ArrayDuplicateCounter(array, length, i);
            if (counter > max)
                max = counter;
    }

    return max;
}


// question (6): write a program to find Unique elements in array

// @brief print unique elements (0 occurences)
// @param length the length of the array
// @param array[] the array you want to check 
// @return nothing (void)
void ArrayPrintUnique(int array[], int length){
    for (int i = 0; i < length; i++){
        // check if there is no duplicates
        if (ArrayDuplicateCounter(array, length, i) == 0)      
            printf("%d is unique\n", array[i]);    
    }
}

// question (7.a): write a program to merge two arrays of the same size

// @brief merge two input arrays. a and b should be of same length.
// @param a first array
// @param b second array
// @param c array to merge in
// @param length length of array a
// @return nothing (void)
void MergeTwoArrays(int a[], int b[], int c[], int length){
    for(int i = 0; i < length; i++){
        c[i] = a[i];
        c[i + length] = b[i];
    }
}

// question (7.b): sort array by descending order

// @brief sort an array
// @param length the length of the array
// @param array[] the array you want to check if a value in it
// @return nothing (void)
void ArraySort(int array[], int length){
    int counter = 0, flag = 0, tempo;

    while (flag != 1){
        for (int i = 0; i < (length - 1); i++){
            if (array[i] > array [i+1]){
                tempo = array[i+1];
                array[i+1] = array[i];
                array[i] = tempo;
                counter++;
            }
        }

        if (counter == 0)
            flag = 1;
        else    
            counter = 0;
    }

}

// @brief sort an array, reversely
// @param length the length of the array
// @param array[] the array you want to check if a value in it
// @return nothing (void)
void ArrayReverseSort(int array[], int length){
    ArraySort(array, length);
    int b[length];

    for (int i = 0; i < length; i++){
        b[i] = array[(length - 1) - i];
    }

    ArrayCopy(b, array, length);
}

// question (8): write program to count the frequency of each element of an array

// @brief check the frequenecy of an element in array
// @param length the length of the array
// @param array[] the array you want to check 
// @return nothing (void)
void ArrayFreqOfElements(int array[], int length){
    int tempo;
    int checker[length];
    for (int i = 0; i < length ; i++){
        // set a temporary value of count of duplicate
        tempo = ArrayDuplicateCounter(array, length, i);

        // check if current array element checked has been checked before
        if (ValueInArray(checker, array[i], length) == 0){
            printf("%d occurs %d times\n", array[i], tempo + 1);
            checker[i] = array[i];
        }
    }
}


// @brief check MAX element
// @param length the length of the array
// @param array[] the array you want to check 
// @return MAX element
int MaxElement(int array[], int length){
    int max = array[0];
    for (int i = 0; i < length; i++){
        if (array[i] > max)
            max = array[i];
    }

    return max;
}

// @brief check MIN element
// @param length the length of the array
// @param array[] the array you want to check 
// @return MIN element
int MinElement(int array[], int length){
    int min = array[0];
    for (int i = 1; i < length; i++){
        if (array[i] < min)
            min = array[i];
    }

    return min;
}
