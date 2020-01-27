/*
   1.name:maximum and minimum
   2.Author:
   3.Date of creation of the file:23-02-2019
   4.A few lines describing the purpose of the file.:
   5.Copyright notice
   6.The the file is the start of a program (contains the main() function), then a
   brief description of what the program does
   7.history in the form of Date, Authors Name or Initials and a 
   brief description of the change
 */
#include<stdio.h>

#define find(a,b) ((a|b)+(a&b)-a)<=a?a:b

main()
{
    int a;
    int b;

    scanf("%x%x",&a,&b);

    printf("greater number is %x \n",find(a,b));

}
