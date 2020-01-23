#include<stdio.h>
void main()
{
    char ch, file_name[25];
     FILE *fp;
    printf("Enter name of a first file\n");
    gets(file_name);

    fp = fopen(file_name, "r");

    FILE *fp1;
    printf("Enter name of a second file\n");
    gets(file_name);
    fp1 = fopen(file_name, "r");
    while((ch = fgetc(fp)) != EOF)
      printf("%c", ch);

    while((ch = fgetc(fp1)) != EOF)
      printf("%c", ch);
}
