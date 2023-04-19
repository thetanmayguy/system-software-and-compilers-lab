#include <stdio.h>
int main(){
    int n,pf=0,m[10],fs,r[20],i,flag,j,index,l[10],max;    //pf:page faults, fs: frame size, m : frames, r:ref string, l: lru buffer.
    printf("frame size : ");
    scanf("%d",&fs);
    printf("reference string length : ");
    scanf("%d",&n);
    printf("reference string : ");
    for(i=0;i<n;i++)
        scanf("%d",&r[i]);

    //initialization
    for(i=0;i<fs;i++){
        m[i]=-1;
        l[i]=0;
    }

    for(i=0,index=-1;i<n;i++){
        flag=0;
        for(j=0;j<fs;j++){
            if(m[j]==r[i]){
                flag=1; // the charecter is present in the frame buffer
                l[j]=0;
            }
            else
                l[j]++;
        }
        if(flag==0){ // page fault has occured.
            pf++;
            //find least recently used:-
            max=-1;
            index=-1;
            for(j=0;j<fs;j++){
                if(l[j]>max){
                    index=j;
                    max=l[j];
                }
            }
            m[index]=r[i]; //page 
            l[index]=0;    //replacement

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