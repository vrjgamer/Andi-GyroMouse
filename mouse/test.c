#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char str[100];
    int x,z;
    while (1) {
        gets(str);
        memmove(str, str+18, strlen(str));
        if (str[1] == 'R') {
            printf("RIGHT\n");
        } else if(str[1] == 'L') {
            printf("LEFT\n");
        } else if(str[1] == 'D'){
            memmove(str, str+2, strlen(str));
            sscanf(str, "%d %d", &x, &z );
            printf("%d %d\n", x, z);
        }
    }
    return 0;
}
