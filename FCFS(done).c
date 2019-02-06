#include<stdio.h>
int main(){

  int n,bt[5],wt[5],tat[5],avwt=0,avtat=0,i,j;

  printf("No of process :");
  scanf("%d",&n);

  printf("\n Enter Process Burst Time\n");
  for(i=0;i<n;i++)
  {
      printf("P[%d]:",i+1);
      scanf("%d",&bt[i]);
  }

  wt[0]=0; ///first process
  for(i=1;i<n;i++)
  {
      wt[i]=0;
      for(j=0;j<i;j++)
        wt[i]+=bt[j];
  }


  printf("\nProcess \tBT  \tWT \tTAT\t\tAVG WT\t\tAVG TAT\n");
  for(i=0;i<n;i++)
  {
     tat[i]=bt[i]+wt[i];
     avwt+=wt[i];
     avtat+=tat[i];
     printf("\nP[%d]\t\t%d\t%d\t%d",i+1,bt[i],wt[i],tat[i]);
  }

  avwt=avwt/n;
  avtat=avtat/n;

  printf("\t\t%d\t\t%d",avwt,avtat);
printf("\n\n\n");


///gantt chart
printf(".");
for(i=0; i<n; i++)
{
   for(j=0;j<bt[i];j++){
   printf("__");
   }
   printf(".");
}
printf("\n|");
for(i=0; i<n; i++)
{
   for(j=0;j<bt[i]-3;j++){
   printf("  ");
   }
   printf("P[%d]",i+1);
   printf("  |");
}

printf("\n|");
for(i=0; i<n; i++)
{
   for(j=0;j<bt[i];j++){
   printf("__");
   }
   printf("|");
}
printf("\n0");

for(i=0; i<n; i++)
{
    for(j=0;j<bt[i];j++){
   printf("  ");
   }
printf("%d",bt[i]);
}
return 0;
}
