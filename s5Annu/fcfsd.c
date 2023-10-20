

#include<stdio.h>
#include<stdlib.h>
void main()
{
 int n,i,rs[30],initial,totalHeadMovements=0;
 printf("Enter the number of requests: ");
 scanf("%d",&n);
 printf("Enter the request sequence\n");
 for(i=0;i<n;i++)
  {
   scanf("%d",&rs[i]);
  }
 printf("Enter the initial head position: ");
 scanf("%d",&initial);
 
 printf("Seek sequence\n");
 for(i=0;i<n;i++)
 {
  printf("%d",rs[i]);
  if(i!=n-1)
   printf("->");
  }
 //implementation
 for(i=0;i<n;i++)
  {
   totalHeadMovements=totalHeadMovements+ abs(rs[i] - initial);
   initial=rs[i];
  }
  
  printf("Total head movements=%d ",totalHeadMovements);
  }
  
