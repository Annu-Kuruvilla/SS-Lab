#include<stdio.h>
void main(){
 int i,j,k,rs[50],n,f,m[10],count=0,pf=0;
 printf("Enter the length of ref string: ");
 scanf("%d",&n);
 printf("Enter the reference string\n");
 for(int i=0;i<n;i++)
 {
  scanf("%d",&rs[i]);
 }
 printf("Enter the number of frames: ");
 scanf("%d",&f);
 for(i=0;i<f;i++)
 {
  m[i]=-1;
 }
 
 for(i =0;i<n;i++)
 {
  for(k=0;k<f;k++)
  {
   if(m[k]==rs[i])
   {
    break;
   }
  }
  if(k==f)
  {
   m[count]=rs[i];
   count++;
   pf++;
  }
  for(j=0;j<f;j++)
  {
   printf("\t%d " ,m[j]);
   
  }
  if(f==k)
  {
   printf(" PF NO %d",pf);
 
  }
   printf("\n");
  if(count==f)
  {
   count=0;
  }
 }
 
 printf("Total number of page faults=%d\n",pf);
}
  