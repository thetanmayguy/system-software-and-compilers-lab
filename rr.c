#include<stdio.h>  
  
int main()  
{  
    // initlialize the variable name  
    int i, n, sum=0,flag=0, y, quant, wt=0, tat=0, at[10], bt[10], temp[10];  
    float avg_wt, avg_tat;  
    printf(" Total number of process in the system: ");  
    scanf("%d", &n);  
    y = n; // Assign the number of process to variable y  //remaining processes count
  
    // Use for loop to enter the details of the process like Arrival time and the Burst Time  
    for(i=0; i<n; i++)  
    {  
        printf("\n Enter the Arrival and Burst time of the Process[%d]\n", i+1);  
        printf(" Arrival time is: \t");  // Accept arrival time  
        scanf("%d", &at[i]);  
        printf(" \nBurst time is: \t"); // Accept the Burst time  
        scanf("%d", &bt[i]);  
        temp[i] = bt[i]; // store the burst time in temp array  
    }  
    // Accept the Time qunat  
    printf("Enter the Time Quantum for the process: \t");  
    scanf("%d", &quant);  
    // Display the process No, burst time, Turn Around Time and the waiting time  
    printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");  
    for(sum=0, i = 0; y!=0; )  
    {  
        if(temp[i] <= quant && temp[i] > 0) // process can be completed in time slice. 
        {  
            sum = sum + temp[i];  //sum-> time from start
            temp[i] = 0;  
            flag=1;  //flag=1 => just completed
        }     
        else if(temp[i] > 0)  
        {  
            temp[i] = temp[i] - quant;  
            sum = sum + quant;    
        }  
        if(temp[i]==0 && flag==1)  //just temp[i]=0 ! mean just completed
        {  
            y--; //decrement the remaining processes.  
            printf("\nProcess No[%d] \t\t %d\t\t\t\t %d\t\t\t %d", i+1, bt[i], sum-at[i], sum-at[i]-bt[i]);  
            wt = wt+sum-at[i]-bt[i];  
            tat = tat+sum-at[i];  
            flag=0;     
        }  
        if(i==n-1)    
            i=0;    
        else if(at[i+1]<=sum)    
            i++;    
        else    
            i=0;    
    }  
    // represents the average waiting time and Turn Around time  
    avg_wt = wt * 1.0/n;  
    avg_tat = tat * 1.0/n;  
    printf("\n Average Turn Around Time: \t%f", avg_wt);  
    printf("\n Average Waiting Time: \t%f", avg_tat);  
    return 0;
}  