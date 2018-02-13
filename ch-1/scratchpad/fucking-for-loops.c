#include <stdio.h>

int main(){
    int i;
    int nums[5] = {0,1,2,3,4};

    printf("Array is {0,1,2,3,4}, so the first char is arr[0] and the last one is arr[4], but len(arr) is 5.\n\n");
    printf("Generally, your options for going through arrays are: \n\n");

    printf("for (i = 0; i < len; i++)\n");
    printf("for (i = 0; i < 5; i++)\n");
    for (i = 0; i < 5; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
    printf("No off-by-one.\n\n");

    printf("for (i = 0; i <= last_elem_index; i++)\n");
    printf("for (i = 0; i <= 4; i++)\n");
    for (i = 0; i <= 4; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
    printf("No off-by-one.\n\n");

    printf("for (i = last_elem_index; i => 0; i--)\n");
    printf("for (i = 4; i => 0; i--)\n");  
    for (i = 4; i >= 0; i--){
        printf("%d ", nums[i]);
    }
    printf("\n");
    printf("No off-by-one.\n\n");        

    printf("Anything else is off-by-one:\n");
    printf("for (i = 0; i <= 5; i++)\n");
    for (i = 0; i <= 5; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
    printf("WRONG.\n\n");

    printf("for (i = 4; i > 0; i--)\n");  
    for (i = 4; i > 0; i--){
        printf("%d ", nums[i]);
    }
    printf("\n");
    printf("WRONG (look how many elements are printed).\n\n");

    return 0;
}