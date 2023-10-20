#include<stdio.h>
void main()
{
 int n,i,f,rs[50],m[10],recent[10],j,min,next=0,count=0,pf=0,k;
 printf("Enter the length of reference string: ");
 scanf("%d",&n);
 printf("Enter the reference string\n");
 for(i=0;i<n;i++)
 {
  scanf("%d",&rs[i]);
  
 }
 printf("Enter the number of frames: ");
 scanf("%d",&f);
 for(i=0;i<f;i++)
 {
  m[i]=-1;
  recent[i]=0;
 }
 
 printf("Page replacement algorithm\n");
 for(i=0;i<n;i++)
 {
  for(k=0;k<f;k++)
  {
   if(m[k]==rs[i])
   {
    recent[k]=next;
    next++;
    break;//if you didnt give break even if after getting a correct case it increments k and check for other cases
    
   }
  }
  
  if(k==f)
  {
   if(i<f)
   {
    m[count]=rs[i];
    count++;
    recent[i]=next;
    next++;
   }
   
   else
   {
    min=0;
    for(j=1;j<f;j++)
    {
     if(recent[min]>recent[j])
     {
      min=j;
     }
    }
    m[min]=rs[i];
    recent[min]=next;
    next++;
   }
  pf++;
  }
  
  for(j=0;j<f;j++)
  {
   printf("\t%d ",m[j]);
  }
  
  if(k==f)
  {
   printf("PF No: %d",pf);
  }
  printf("\n");
  }
  
  printf("Total number of page faults = %d",pf);
  }
   
