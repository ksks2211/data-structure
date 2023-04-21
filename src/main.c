#include <stdio.h>


int main() {

    int nums[5] = {1,2,3,4,5};

    printf("nums[1] is %d\n", nums[1]);
    

    printf("%p\n",&nums);
    printf("%p\n",&nums[1]);
    printf("%p\n",&nums[2]);

    return 0;
}
