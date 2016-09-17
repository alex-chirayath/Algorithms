 /*Shirley Dsouza
  SE 6745 Batch:A
  Program :Copy one file to another*/

#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
 FILE *fp1,*fp2;
 char ch;
 if(argc!=3)
 {
  printf("File not present");
  exit(1);
 }
 fp1=fopen(argv[1],"r");
 if(fp1==NULL)
 {
  printf("File does not exit");
  exit(1);
 }
 fp2=fopen(argv[2],"w");
 if(fp2==NULL)
 {
  printf("File does not exit");
  exit(1);
 }
 while(1)
 {
  fscanf(fp1,"%c",&ch);
  if(ch==EOF)
  {
   break;
  }
  fprintf(fp2,"%c",ch);
 }
 fclose(fp1);
 fclose(fp2);
}











