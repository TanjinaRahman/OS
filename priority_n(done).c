#include<stdio.h>
int main(){

    int n,pro[5],p[5],bt[5],wt[5],tat[5],avwt=0,avtat=0,i,j,temp;

  printf("No of process :");
  scanf("%d",&n);

  printf("\nEnter Process Burst Time & Priority\n");
  printf("\n     BT P\n");
  for(i=0;i<n;i++)
  {
      pro[i]=i+1;
      printf("P[%d]:",pro[i]);
      scanf("%d%d",&bt[i],&p[i]);
  }

  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
        if(p[i]>p[j]){
            temp = p[i];
            p[i] = p[j];
            p[j] = temp;
            temp = bt[i];
            bt[i] = bt[j];
            bt[j] = temp;
            temp = pro[i];
            pro[i] = pro[j];
            pro[j] = temp;
        }
    }
  }

 /* for(i=0;i<n;i++){
    printf("%d %d\n",bt[i],p[i]);
  }*/

   wt[0]=0; ///first process
  for(i=1;i<n;i++)
  {
      wt[i]=0;
      for(j=0;j<i;j++)
        wt[i]+=bt[j];
  }


  printf("\nProcess \tBT  \tP  \tWT \tTAT\t\tAVG WT\t\tAVG TAT\n");
  for(i=0;i<n;i++)
  {
     tat[i]=bt[i]+wt[i];
     avwt+=wt[i];
     avtat+=tat[i];
     printf("\nP[%d]\t\t%d\t%d\t%d\t%d",pro[i],bt[i],p[i],wt[i],tat[i]);
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
   printf("P[%d]",pro[i]);
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
