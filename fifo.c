#include <stdio.h>
int main(){
    int n,pf=0,m[10],fs,r[20],i,flag,j,index;    //pf:page faults, fs: frame size, m : frames, r:ref string 
    printf("frame size : ");
    scanf("%d",&fs);
    printf("reference string length : ");
    scanf("%d",&n);
    printf("reference string : ");
    for(i=0;i<n;i++)
        scanf("%d",&r[i]);

    //initialization
    for(i=0;i<fs;i++)
        m[i]=-1;

    for(i=0,index=-1;i<n;i++){
        flag=0;
        for(j=0;j<fs;j++)
            if(m[j]==r[i])
                flag=1;
        if(flag==0){
            index=(index+1)%fs;//fifo implementation
            m[index]=r[i];//page replacement
            pf++;//page fault
            printf("%d : ",r[i]);
            for(j=0;j<fs;j++)
                printf("%d ",m[j]);
            printf("\n");
        }
        else{
            printf("%d : ",r[i]);
            for(j=0;j<fs;j++)
                printf("%d ",m[j]); 
            printf("\n");
        }
    }

    printf("\ntotal page faults : %d\n",pf);

    return 0;
}