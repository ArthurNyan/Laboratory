#include "gnom_sort.h"
int* gnom_sort(int length, int* date, int* numeration)
{
    int index = 0;
    int swap;
    while (index < length) {
        if (index == 0)
            index++;
        if (date[index] >= date[index - 1])
            index++;
        else {
            swap = date[index];
            date[index] = date[index - 1];
            date[index - 1] = swap;
            swap = numeration[index];
            numeration[index] = numeration[index - 1];
            numeration[index - 1] = swap;
        }
    }
    return numeration;
}
