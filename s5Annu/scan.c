#include<stdio.h>
#include<stdlib.h>
void main()
{
 int n,i,rs[20],initial,temp,j,thm=0,size,dir,cur,seeksequence[10],index=0,left,right;
 printf("Enter the number of requests:");
 scanf("%d",&n);
 printf("Enter the request sequence\n");
 for(i=0;i<n;i++)
 {
  scanf("%d",&rs[i]);
 }
 printf("Enter the initial head position:");
 scanf("%d",&initial);
 
 printf("Enter the total disk size: ");
 scanf("%d",&size);
 
 printf("Enter the head movement direction for high 1 for low 0: ");
 scanf("%d",&dir);
 for(i=0;i<n-1;i++)
 {
  for(j=0;j<n-1-i;j++)
  {
   if(rs[j]>rs[j+1])
   {
    temp=rs[j];
    rs[j]=rs[j+1];
    rs[j+1]=temp;
   }
  }
 }
 
 for(i=0;i<n;i++)
 {
  if(rs[i]>initial)
  {
   right=i;
   left=i-1;
   break;
  }
 }
 
 if(dir==1)
 {
  for(i=right;i<n;i++)
  {
   cur=rs[i];
   seeksequence[index++]=cur;
  }
  
  for(i=left;i>=0;i--)
  {
   cur=rs[i];
   seeksequence[index++]=cur;
  }
  
  printf("Seek Sequence\n");
  for(i=0;i<index;i++)
  {
   printf("%d",seeksequence[i]);
   if(i!=n-1)
    printf("->");
  }
  thm=size-initial+size-rs[0];
  
  printf("\nTotal head movement if direction is high: %d",thm);
  } 
  
  
 if(dir==0)
 {
  for(i=left;i>=0;i--)
  {
   cur=rs[i];
   seeksequence[index++]=cur;
  }
  
   for(i=right;i<n;i++)
  {
   cur=rs[i];
   seeksequence[index++]=cur;
  }
 
 printf("Seek Sequence\n");
  for(i=0;i<index;i++)
  {
   printf("%d",seeksequence[i]);
   if(i!=n-1)
    printf("->");
  }
 
  thm=initial-0+rs[n-1];
   printf("Total head movement if direction is low: %d",thm);
  }
   }
