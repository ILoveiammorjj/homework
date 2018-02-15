#include <cstdio>
#include "main.h"
int main() {
    Ap z;
    FILE *fi, *fo;
    fi = fopen("in.txt", "r");
    fo = fopen("out.txt", "w");
    fscanf(fi,"%d%d%d%d",&z.a,&z.b,&z.c,&z.d);
    fprintf(fo,"%d %d %d %d",z.a,z.b,z.c,z.d);

    return 0;
}
