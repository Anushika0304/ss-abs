#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 200

struct objectcode
{
    unsigned char code[15];
    int add;
    char input[10];
}obcode[MAX];

int main()
{
    FILE *fp1,*fp2;
    int address,pstart,inc=0,textloc,extra,length,len,loc,x,i,n,count=0,start,s;
    char input[10],cher;
    fp1=fopen("input12.txt","r");
    fp2=fopen("output.txt","w");

    if(fp1==NULL || fp2==NULL)
    {
        printf("ERROR IN OPENING FILE\n");
        exit(0);
    }
fscanf(fp1,"%s",input);
    while(strcmp(input,"E")!=0)
    {
        //fscanf(fp1,"%s",input);
        if(strcmp(input,"H")==0)
        {
            fscanf(fp1,"%s",input);
            fscanf(fp1,"%X",&address);
            fscanf(fp1,"%X",&extra);
            pstart=address;
            loc=address;
        }


                else if(strcmp(input,"T")==0)
                {
                    fscanf(fp1,"%X",&textloc);
                    fscanf(fp1,"%X",&length);
                    for(i=0;i<(textloc-loc);i++)
                    {
                        strcpy(obcode[inc].code,"..");
                        obcode[inc++].add=pstart++;
                    }
                    loc=textloc+length;
                    printf("%x\t",textloc);
                    printf("%x\t",length);
                    printf("%x\n",loc);

                }

                else
                {
                    x=0;
                    len=strlen(input);
                    //printf("%s\n",input);
                    for(i=0;i<len;i++)
                    {
                        obcode[inc].code[x++]=input[i];
                        if(x>1){
                        obcode[inc++].add=pstart++;
                        x=0;
                        }


                    }
                }

                fscanf(fp1,"%s",input);
                //printf("%s\n",input);

        }

        if(strcmp(input,"E")==0)
            fscanf(fp1,"%s",input);



    n=0;
    count=0;
    s=pstart-16;
    fprintf(fp2,"%06X\t",s);
    for(int i=0;i<16;i++)
    {

        fprintf(fp2,"xx");
        if(i==4 || i==8 || i==12)
        {
            fprintf(fp2,"\t");

        }
    }
    printf("%x",obcode[0].add);

    fprintf(fp2,"\n%06X\t",obcode[0].add);
   // printf("%x",obcode[5].add);
    for(i=0;i<inc;i++)
    {

        fprintf(fp2,"%s",obcode[i].code);
        n++;

        if(n>3)
        {
            fprintf(fp2,"\t");
            n=0;
            count++;
        }

        if(count>3)
        {

            fprintf(fp2,"\n\n%06x\t",obcode[i+1].add);
                //printf("One");
            count=0;

        }
    }
    fclose(fp1);
    fclose(fp2);

    printf("Address\t\t\tContents");
    printf("\n--------------------------\n");
    fp1=fopen("output.txt","r");
    cher=fgetc(fp1);
    while (cher!=EOF)
    {
        printf("%c",cher);
        cher=fgetc(fp1);
    }
    fclose(fp2);
}
