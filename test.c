#include "minirt.h"
#include <stdio.h>

int     main(void)
{
    t_vect  vector;

    vector = itovect(0x100);
    printf("%f\n%f\n%f\n", vector.x, vector.y, vector.z);
    return (0);
}