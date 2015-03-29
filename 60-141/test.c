#include <stdio.h>

int f(int);
int g(int, int);
int h(int);
int r(int);
int a = 2;

int f(int a)
{
    printf("%d", a);
    return g(a+1, a-1);
}

int g(int a, int b)
{
   b += h(a);
    return r(a-1);
}

int h(int c)
{
return a+=c*2;
}

int r(int a)
{
    if(a<= 1)
    {
        return 1;
    }
    else
    {
        return a+r(a-1);
    }
}

int main(void)
{
    printf("%d\t", a);
    printf("%d\t", f(a));
    printf("%d\n", h(a));
    a--;
    printf("%d\t", f(a));
    printf("%d\t", h(a));
    return a;
}
