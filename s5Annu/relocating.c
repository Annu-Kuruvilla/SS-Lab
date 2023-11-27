#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
    FILE *fp1,*fp2;
    int i,j,hexaddr,start_hexaddr;
    char ch, line[50],addr[10];
    fp1=fopen("input.txt","r");
    printf("enter starting address");
    scanf("%x",&start_hexaddr);
    do{
        fscanf(fp1,"%s",line);
        if(line[0]=='T')
        {
            for(i=1,j=0;i<7;i++,j++)
            addr[j]=line[i];
            addr[j]='\0';

            fp2=fopen("temp.txt","r+");
            fprint(fp2,"%s",addr);
            rewind(fp2);
            fscanf(fp2,"%x",&hexaddr);
            fclose(fp2);

            i=9;
            while(line[i]!='\0')
            {
                printf("%x \t%c%c\n",hexaddr+start_hexaddr,line[i],line[i+1]);
                hexaddr=hexaddr+1;
                i+i+2;
            }
        }
    }
     while(!feof(fp1));
            fclosee(fp1);
}
