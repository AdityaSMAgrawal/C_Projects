#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int i,j,x=0;
    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    for(i=0;i<strlen(s)+1;i++)
    {
        if(s[i]==' '||s[i]=='\0')
        {
            for(j=x;j<i;j++)
            {
                printf("%c",s[j]);
            }
            x = i + 1;
            printf("\n");
        }
        else {
        continue;
        }
    }
    return 0;
}
