#include <stdio.h>
#include <stdlib.h>

float average(int numClass, int *classScores);

int main(void)
{
    int numClass;
    printf("Input the number of classes:\n");
    scanf("%d", &numClass);

    /* Fill the code here! */

    int *classScores;

    /* Fill the code here! */

    float avg = average(numClass, classScores);
    printf("Average: %f\n", avg);

    /* Fill the code here! */

    return 0;
}

float average(int numClass, int *classScores)
{
}
