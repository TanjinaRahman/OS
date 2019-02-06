#include<stdio.h>
int main(){

int    allo[5][10], maxneed[5][10],need[5][10],aval[5],i,j,n,finish[10],work[5][10];
    printf("Enter the no of process : ");
    scanf("%d",&n);
     printf("\nAllocation\n\nA B C\n");
    for(i=0;i<3;i++){
        for(j=0;j<n;j++){
            scanf("%d",&allo[i][j]);
        }
    }
     printf("\nMax need\n\nA B C\n");
    for(i=0;i<3;i++){
        for(j=0;j<n;j++){
            scanf("%d",&maxneed[i][j]);
        }
    }

    printf("\nAvailable\n\nA B C\n");
    for(i=0;i<3;i++){
        scanf("%d",&aval[i]);
    }
 printf("\nNeed\n");
     printf("A B C\n");
      for(i=0;i<3;i++){
        for(j=0;j<n;j++){
            need[i][j]=maxneed[i][j]-allo[i][j];
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<n;i++){
        finish[i]=0;
    }

    for(i=0;i<3;i++){
        for(j=0;j<n;j++){
            if(need[i][j]<=aval[i] && finish[i]==0){
                aval[i]=aval[i]+allo[i][j];
                finish[i]=1;
            }
        }
    }
    for(i=0;i<n;i++){
        if(finish[i]==1){
            printf("P[%d] ",i+1);
        }
        else
            printf("not safe");
    }

return 0;
}
