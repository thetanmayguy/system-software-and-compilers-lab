#include<stdio.h>

int main() {
    int pid[10], arrival_time[10], burst_time[10], remaining_time[10], completion_time[10], waiting_time[10], turnaround_time[10];
    int n, i, j, time = 0, min_remain_time, index, completed = 0, total_waiting_time = 0, total_turnaround_time = 0;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    printf("Enter the arrival time and burst time of each process:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d: ", i+1);
        scanf("%d%d", &arrival_time[i], &burst_time[i]);
        remaining_time[i] = burst_time[i];
        pid[i] = i+1;
    }
    
    while(completed != n) {
        min_remain_time = 9999;
        index = -1;
        
        for(i = 0; i < n; i++) { //find remaining shortest job
            if(arrival_time[i] <= time && remaining_time[i] < min_remain_time) {
                min_remain_time = remaining_time[i];
                index = i;
            }
        }
        
        if(index == -1) {
            time++;
            continue;
        }
        
        remaining_time[index]--;
        min_remain_time = remaining_time[index];
        
        if(min_remain_time == 0) {
            completion_time[index] = time+1;
            waiting_time[index] = completion_time[index] - arrival_time[index] - burst_time[index];
            turnaround_time[index] = completion_time[index] - arrival_time[index];
            total_waiting_time += waiting_time[index];
            total_turnaround_time += turnaround_time[index];
            completed++;
        }
        
        time++;
    }
    
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], arrival_time[i], burst_time[i], completion_time[i], waiting_time[i], turnaround_time[i]);
    }
    
    printf("\nAverage Waiting Time = %f", (float)total_waiting_time/n);
    printf("\nAverage Turnaround Time = %f", (float)total_turnaround_time/n);
    
    return 0;
}