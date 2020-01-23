#include<stdio.h>
void main()
{
    char ch, file_name[25], file_name1[25];
     FILE *fp, *fp2, *fp3;
    printf("Enter name of a first file\n");
    gets(file_name);

    fp = fopen(file_name, "w");

    printf("Enter name of a second file\n");
    gets(file_name1);

    fp2 = fopen(file_name1, "r");

    while((ch = fgetc(fp2)) != EOF)
      {
          fputc(ch, fp);
      }
        printf("\nContent in %s appended to %s", file_name1, file_name);


}
