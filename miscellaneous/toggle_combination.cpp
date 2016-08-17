#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>

void toggler(char* x, int pos){
        if(pos==0){ printf("%s\n",x); return; }
        x[pos-1] = toupper(x[pos-1]);
        toggler(x, pos-1);
        x[pos-1] = tolower(x[pos-1]);
        toggler(x, pos-1);

        return;
}

int main(void){
        char str[500];
        scanf("%s",str);
        toggler(str, strlen(str));
        return 0;
}
