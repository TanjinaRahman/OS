#include <stdio.h>
int main()
{
 int p[6],at[6],bt[6],x[6],i,j,s,count=0,t,n;
 double ct,avg_wt=0,avg_tat=0,wt=0,tat=0;
  printf(" Please Enter The number of Process:");
  scanf("%d",&n);
 printf("\tAT BT\n");
 for(i=0;i<n;i++){
    p[i]=i+1;
    printf(" P[%d] : ",p[i]);
    scanf("%d%d",&at[i],&bt[i]);
 }
 //for(i=0;i<n;i++)
 //scanf("%d",&b[i]);
 for(i=0;i<n;i++){//copying bt
 x[i]=bt[i];
 }
  printf("\n Process \tAT  \tBT\t AVG WT\tAVG TAT\n ");
 for(i=0;i<n;i++){
    printf("\n P[%d]\t\t%d\t%d",p[i],at[i],bt[i]);
 }
  bt[5]=5555;
//printf("\");
 for(t=0;count!=n;t++)
 {
   s=5;
  for(i=0;i<n;i++)
  {
   if(at[i]<=t && bt[i]<bt[s] && bt[i]>0 )
   s=i;
  }
  bt[s]--;
  if(bt[s]==0)
  {
   count++;
   ct=t+1;

   wt=wt+ct-at[s]-x[s];
   avg_wt=avg_wt+wt;
   tat= tat+ct-at[s];
//printf("\n %.2lf\t%.2lf",wt,tat);
//printf("%d\n",ct);
  }
  printf("\n\nt = %d\n\n",t);
 }
//avg_wt=wt/n;
//avg_tat=tat/n;
    printf("\t%.2lf\t%.2lf\n\n",wt/n,tat/n);
    //printf("%.2lf",avg_tat);


    return 0;
}
