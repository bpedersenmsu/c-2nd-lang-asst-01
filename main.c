#include <stdio.h>

/*int global_i = 9; // globals should be avoided
// this is just for convenience of illustration

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

int main() {
    printf("%d\n", global_i);
    wont_change(global_i);
    printf("%d\n", global_i);
    change_inside(global_i);
    printf("%d\n", global_i);

    return 0;

}*/
int global_i = 9; // globals should be avoided
// this is just for convenience of illustration

// Arguments in C functions are passed BY VALUE, including pointers,
// so this function will not change the original variable the value
// of which was used to assign the argument, in this case, global_i.
// It will change the value of argument_i, but it is only a local
// copy of global_i (see the function call in main() below).
int will_return_it_changed(int argument_i) {
    return argument_i + 1;
}

int main() {
    printf("%d\n", global_i);
    global_i = will_return_it_changed(global_i);
    printf("%d\n", global_i);

    return 0;
}