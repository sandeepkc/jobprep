#include<stdio.h>

void permute(char *, int, int);

void swap(char *a, char *b)
{
     char temp;
     temp = *b;
     *b = *a;
     *a = temp;
}
     

int main(int argc, char **argv)
{
    char a[] = "ABCD";
    permute(a, 0, 3);
    getch();
    return (0);
}

void permute(char *a, int i, int n)
{
             int j;
             if(i == n)
             printf("%s\n", a);
             else
                 {
                            for(j=i ; j<=n ; j++)
                                    {
                                          swap(a+i, a+j);
                                          permute(a, i+1, n);
                                          swap(a+i, a+j); 
                                    }
                 }
}
