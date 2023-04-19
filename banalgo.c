#include <stdio.h>
int main(){
    int np,nr,alloc[20][20],need[20][20],max[20][20],avail[20],i,j,ctr=-1,tot[20],safe[20];
    printf("no. of processes : ");
    scanf("%d",&np);
    printf("no. of resources : ");
    scanf("%d",&nr);
    printf("total resources(each) : ");
    for(i=0;i<nr;i++)
        scanf("%d",&tot[i]);
    printf("allocation chart :-\n");
    for(i=0;i<np;i++)
        for(j=0;j<nr;j++)
            scanf("%d",&alloc[i][j]);
    printf("max chart :-\n");
    for(i=0;i<np;i++)
        for(j=0;j<nr;j++)
            scanf("%d",&max[i][j]);
    printf("availabele : ");
    for(i=0;i<nr;i++)
        scanf("%d",&avail[i]);

    //initialization
    for(i=0;i<np;i++)
        safe[i]=0;

    //calculating need:-
    printf("need chart :-\n");
    for(i=0;i<np;i++){
        for(j=0;j<nr;j++){
            need[i][j]=max[i][j]-alloc[i][j];
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }

    //work same as avail.
    printf("safety criteria : ");
    while(ctr!=0){
        ctr=0;
        for(i=0;i<np;i++){
            if(safe[i]==0){
                for(j=0;j<nr && need[i][j]<=avail[j];j++);
                if(j==nr){ //safe
                    ctr++;
                    for(j=0;j<nr;j++)
                        avail[j]+=alloc[i][j];
                    safe[i]=1;
                    printf("%d ",i);
                }
            }
        }
    }
    for(j=0;(j<nr) && (avail[j]==tot[j]);j++);
    if(j==nr)
        printf("\nthe processes are safe from deadlock.\n");
    else
        printf("\nthe processes can be deadlocked.\n");

    return 0;
}