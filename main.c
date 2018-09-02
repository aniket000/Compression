#include<stdio.h>
#include<string.h>

char *encoding(char *str)
{
    int i;
    char scr;
    int len = strlen(str);
    for(i=0;i<=len;i++)
    {
        int count = 0;
        while(str[i]==str[i+1])
        {
            count++;
            i++;
            scr = str[i];
        }
        if(count>1)
        {
            str[i] = count;
            str[i+1] =scr;
        }
        else
            str[i] = scr;
    }

return str;
}

int main()
{
    char str;
    printf("Enter the string to encode\n");
    scanf("%c",&str);
    encoding(str);
    printf("Encoded string : \n",&str);
return 0;
}
