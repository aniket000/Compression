#include <stdio.h>
#include <limits.h>
#include <errno.h>

int main()
{
    FILE *inFile;
    FILE *outFile;
    char file_name[100];
    int result;
    int mode;

    //options for project
    //  printf("Enter the full path of the file: \n")
    // scanf("%s",&file_name);

    inFile = fopen("test.txt","r");
    outFile = fopen("test.txt","w");

    if (inFile == NULL || outFile == NULL)
            {
              printf("Error! Could not open file\n");
              exit(-1); // must include stdlib.h
            }
    printf("What you want to do\n");
    printf("1.Encode\n2.Decode");
    scanf("%d",&mode);
    /* we have valid parameters encode or decode */
    switch (mode)
    {
        case 1:
            result = RleEncodeFile(inFile, outFile);
            break;

        case 2:
            result = RleDecodeFile(inFile, outFile);
            break;

        default:
            fprintf(stderr, "Illegal encoding/decoding option\n");
            result = EINVAL;
    }

    fclose(inFile);
    fclose(outFile);
    return result;
}
