#include <stdio.h>
#include <stdlib.h>
#include "linb.h"

int main()
{
    List l;

    CreateList(&l);

    int x = 55;
    InsertList(1, x, &l);

    printf("%d \n%d", ListFull(&l), ListSize(&l));

    return 0;
}
