#include <stdlib.h>
#include <stdio.h>

int global_i = 9; // globals should be avoided
// this is just for convenience of illustration

int iarray[10]; // declares an array of 10 integers
// until the elements are explicitly assigned,
// their contents are undefined (read, garbage)


// here's the syntax for literal array assignment
float farray[] = { 0.5, 8.6 };  // notice that you don't have to specify
// how many elements the array should have
// this is automatically calculated by the
// compiler

// character arrays are the basis of C-style strings
char cstring[] = "abracadabra"; // remember that C-style strings are
// NULL-terminated, so the number of
// elements of this array will be the
// number of characters plus one

// Arguments in C functions are passed BY VALUE, including pointers,
// so this function will not change the original variable the value
// of which was used to assign the argument, in this case, global_i.
// It will change the value of argument_i, but it is only a local
// copy of global_i (see the function call in main() below).
void wont_change(int argument_i) {
    argument_i = 10;
}

// If we want a function to change a variable outside (the scope of)
// the function, we need to pass it a pointer to that variable.
// This function will change the original
void change_inside(int *pointer_to_global_i) {
    *pointer_to_global_i = 10; // dereference and assign a new value
}

int will_return_it_changed(int argument_i) {
    return argument_i + 1;
}

void swap_ends(int iarr[], int size) {  // passing the size of the array is good practice
    // usually, the type is size_t, which can hold the
    // largest possible size (usually equivalent to
    // long long (you don't need to remember this now)
    // standard safe swap code
    int tmp = iarr[0];          // remember that iarr is of type int*, but iarr[n] is int
    iarr[0] = iarr[size - 1];
    iarr[size - 1] = tmp;
}

//int *get_array() {
//    int test[] = { 3, 4, 7, 1, 23 };

//    return test;
//}

struct student_record {
    char first_name[10];      // these are called members or fields
    char last_name[10];       // they can be of any type
    char nine_hundred[10];
    int year_first_enrolled;
};

typedef struct student_record student_t; // typedef [type] [type alias]

// the trailing _t is a good
// practice when declaring
// type aliases

typedef struct {              // the name is optional
    char first_name[10];
    char last_name[10];
    char nine_hundred[10];
    int year_first_enrolled;
} student_t2, *student_p;

// a function declaring a static local array
// it may cause the stack to overflow, but also
// slows down the program, because creating such
// a large stack frame takes time
void foo() {
    int iarr[1000][1000][1000];  // don't do that!

    // use iarr
}

// instead, consider passing a dynamically allocated
// array as an argument
// this will keep the stack frame at minimal size
void bar(int ***data_cube) {
    // use data_cube

}

void allocate_array(int **a) {
    *a = (int *) malloc(sizeof(int) * 100);
}

int *allocate_array2() {
    return (int *) malloc(sizeof(int) * 100);
}

int heapStuff() {
    // explicit allocation of an integer on the heap
    int *array_size = (int *) malloc(sizeof(int));
    int size = 8;

    // check if the allocation was successful
    // if it was, the pointer will be non-NULL
    if (array_size == NULL) {
        printf("ERROR: Memory allocation failed!\n");
        return 1;
    } else {
        *array_size = 10;
    }

    // explicit allocation of an integer array on the heap
    int *int_array = (int *) malloc(*array_size * sizeof(int));

    // check if the allocation was successful
    // if it was, the pointer will be non-NULL
    if (int_array == NULL) {
        printf("ERROR: Memory allocation failed!\n");
        return 0;
    } else {
        for (int i = 0; i < *array_size; i ++) {
            int_array[i] = i * *array_size;
            printf("Array element %d holds %d\n", i, int_array[i]);
        }
    }

    // free the allocated memory:
    // dynamically allocated memory
    // has to be released explicitly
    free(array_size);
    array_size = NULL; // this is good practice in case
    // the pointer might get reused

    free(int_array);
    int_array == NULL;


    float *data = (float *) malloc(sizeof(float) * 1000); // primitive
    if (data != NULL) {
        // use data...
        printf("data = %d\n", (float *) malloc(sizeof(float) * 1000));
        printf("data = %d\n", (*data));
    }
    free(data);
    data = NULL;

    double **square_table;  // the type of square_table is double **,
    // that is, a double pointer to double (LOL!)
    square_table = (double **) malloc(sizeof(double *) * 100);    // allocate the 1st dimension
    // notice the cast and base size!!
    if (square_table != NULL) {
        for (int i=0; i<100; i++)
            square_table[i] = (double *) malloc(sizeof(double) * 100); // allocate the 2nd dimension
        // use the 2D array
        // technically, you should check if the allocations worked
    }
// for the second dimension, you need to call free() in a loop!!
    for (int i=0; i<1000; i++) {
        free(square_table[i]);
        square_table[i] = NULL;
    }

// now you can free the first dimension
    free(square_table);
    square_table = NULL;

    student_p roster = (student_p) malloc(sizeof(student_t) * 35); // notice the base type
    // and the pointer (array) type
    if (roster) {  // notice that "if (roster) {}" is equivalent to "if (roster != NULL) {}"
        // use student roster...
    }
    free (roster);
    double ***data_cube;

// allocate 1st dimension
    data_cube = (double ***) malloc(sizeof(double **) * 1000);

// allocate 2nd dimension
    for (int i=0; i<1000; i++)
        data_cube[i] = (double **) malloc(sizeof(double *) * 1000);

// allocate 3rd dimension
    for (int i=0; i<1000; i++)
        for (int j=0; j<1000; j++)
            data_cube[i][j] = (double *) malloc(sizeof(double) * 1000);

// use the data cube...

// free 3rd dimension
    for (int i=0; i<1000; i++)
        for (int j=0; j<1000; j++)
            free(data_cube[i][j]);

// free 2nd dimension
    for (int i=0; i<1000; i++)
        free(data_cube[i]);

// free 1st dimension
    free(data_cube);

    int *int_array2;

    allocate_array(&int_array2);

    if (int_array2) {
        // use int_array...
    }

    int *int_array3 = allocate_array2();

    if (int_array3) {
        // use int_array...
    }
    return 0;
}

int main() {
    global_i = 333;
    wont_change(global_i);
    printf("%d\n", global_i);
    global_i = will_return_it_changed(global_i);
    printf("%d\n", global_i);
    char test[] = "klnlnm";
    printf("%s\n", test);
    change_inside(&global_i);
    printf("%d\n", global_i);


    // here's a loop that zeros out the array
    for (int i = 0; i < 10; i ++) {
        iarray[i] = 0;
    }

    printf("zeroed out array is %d\n", iarray[0]);
    int integer_array[] = { 23, 56, 12, 9, 4, 356, 122, 0, 2, 7 };

    printf("The array element at index 8 is %d\n", integer_array[8]);

    int arr_size = sizeof(integer_array) / sizeof(integer_array[0]);

    printf("Number of elements of array is %d\n", arr_size);

    iarray[5] = 6;  // the type of 'iarray[5]' is integer (int)
    // the indexing is equivalent to dereferencing
    // (including the step calculation laid out above)

// we can make this explicit
    int *jarr = iarray;
    jarr[5] = jarr[5] + 1;
    printf("the size of the jarr array is %d\n", sizeof(jarr));

    int iarray[] = { 3, 4, 7, 1, 23 };

    printf("Start: %d; End: %d\n", iarray[0], iarray[4]);
    swap_ends(iarray, 5);
    printf("Start: %d; End: %d\n", iarray[0], iarray[4]);

    /*
     * This doesn't work
     */
    //int *testArray = get_array();
    //printf("Start: %d; End: %d\n", testArray[0], testArray[4]);

    struct student_record jm123 = { "john", "michaels", "900123456", 1994 };
    printf("%s-%s-%s-%d\n", jm123.first_name,
           jm123.last_name,
           jm123.nine_hundred,
           jm123.year_first_enrolled);

    struct student_record *student_pointer = &jm123;
    printf("%s-%s-%s-%d\n", student_pointer->first_name,
           student_pointer->last_name,
           student_pointer->nine_hundred,
           student_pointer->year_first_enrolled);

    //struct student_record *student_pointer2 = &jm123;
    printf("%s-%s-%s-%d\n", (*student_pointer).first_name,           // parentheses have among the
           (*student_pointer).last_name,            // highest precedences of C
           (*student_pointer).nine_hundred,         // operators, so to dereference
           (*student_pointer).year_first_enrolled); // first, and only then access
    // a member, we put the derefe-
    // rencing *student_pointer in
    // parentheses

    student_t lm245 = { "logan", "monaghan", "900987321", 2015 };
    student_t *student_handle = &lm245;
    printf("%s-%s-%s-%d\n", lm245.first_name,
           lm245.last_name,
           lm245.nine_hundred,
           lm245.year_first_enrolled);
    printf("%s-%s-%s-%d\n", (*student_handle).first_name,           // parentheses have among the
           (*student_handle).last_name,            // highest precedences of C
           (*student_handle).nine_hundred,         // operators, so to dereference
           (*student_handle).year_first_enrolled);

    int test2 = heapStuff();


    return 0;
}
