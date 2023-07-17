#include<stdio.h>

int main() {
	int ch, quantum, wait=0, turnaround=0, at[10], bt[10], rt[10];
	int i, n, time, flag=0, endTime, smallest, remain=0;

	printf("Enter the no. of processes: ");
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		printf("Enter arrival & burst time for P%d: ", i + 1);
		scanf("%d %d", &at[i], &bt[i]);
		rt[i] = bt[i];
	}

	printf("1. Round Robin \n2. SRTF\n");
	scanf("%d", &ch);
	switch(ch) {
		case 1:
			printf("Enter Time Quantum: ");
			scanf("%d", &quantum);
			printf("\nProcess time|Turnaround Time|Waiting Time\n");
			remain = n;
			for(i=0, time=0;  remain!=0;) {
				if(rt[i] <= quantum && rt[i] > 0) {
					time += rt[i];
					rt[i] = 0;
					flag = 1;
				}
				else if(rt[i] > 0) {
					rt[i] -= quantum;
					time += quantum;
				}
				if(rt[i]==0 && flag==1) { //just completed => print.
					remain--;
					wait += time - at[i] - bt[i];
					turnaround += time - at[i];
					printf("P[%d]\t|\t%d\t|\t%d\n", i + 1, turnaround, wait);
					flag=0;
				}
				if(i == n - 1)
					i = 0;
				else if(at[i + 1] <= time)
					i++;
				else
					i = 0;
			}
			break;

		case 2:
			remain = 0;
			printf("\nProcess time|Turnaround Time|Waiting Time\n");
			rt[9] = 9999;
			for(time=0; remain!=n; time++) {
				smallest = 9;
				for(i=0;i<n;i++)
					if(at[i] <=time && rt[i] < rt[smallest] && rt[i] > 0)
						smallest=i;
				rt[smallest]--;
				if(rt[smallest]==0) {
					remain++;
					endTime=time+1;
					printf("\nP[%d]\t|\t%d\t|\t%d\n", smallest + 1, endTime - at[smallest], endTime - bt[smallest] - at[smallest]);
					wait += endTime - bt[smallest] - at[smallest];
					turnaround += endTime - at[smallest];
				}
			}
			break;
		default:
			printf("Invalid\n");
			return 1;
	}
	printf("\nAverage Waiting Time = %.2f\n", wait * 1.0 / n);
	printf("Average Turnaround Time = %.2f\n", turnaround * 1.0 / n);
	return 0;
}

/*
Output:

Enter Quantum Size
2
Enter number of Processes
5
Enter details
Enter arrival time for Process 1
0
Enter burst time for Process 1
10

Enter arrival time for Process 2
0
Enter burst time for Process 2
1

Enter arrival time for Process 3
3
Enter burst time for Process 3
2

Enter arrival time for Process 4
5
Enter burst time for Process 4
1

Enter arrival time for Process 5
10
Enter burst time for Process 5
5

Process Scheduling
Current Time: 0 , Process: 1
Current Time: 2 , Process: 2
Current Time: 3 , Process: 1
Current Time: 5 , Process: 3
Current Time: 7 , Process: 1
Current Time: 9 , Process: 4
Current Time: 10 , Process: 1
Current Time: 12 , Process: 5
Current Time: 14 , Process: 1
Current Time: 16 , Process: 5
Current Time: 18 , Process: 5
Current Time: 19

Waiting Time
Process 1, Waiting Time: 6
Process 2, Waiting Time: 2
Process 3, Waiting Time: 2
Process 4, Waiting Time: 4
Process 5, Waiting Time: 4

Average Waiting Time: 3.6
*/

/*
Output:

Enter number of Processes
4
Enter details
Enter arrival time for Process 1
0
Enter burst time for Process 1
8

Enter arrival time for Process 2
1
Enter burst time for Process 2
4

Enter arrival time for Process 3
2
Enter burst time for Process 3
9

Enter arrival time for Process 4
3
Enter burst time for Process 4
5

Process Scheduling
CurrentTime: 0 , Process: 1
CurrentTime: 1 , Process: 2
CurrentTime: 2 , Process: 2
CurrentTime: 3 , Process: 2
CurrentTime: 4 , Process: 2
CurrentTime: 5 , Process: 4
CurrentTime: 6 , Process: 4
CurrentTime: 7 , Process: 4
CurrentTime: 8 , Process: 4
CurrentTime: 9 , Process: 4
CurrentTime: 10 , Process: 1
CurrentTime: 11 , Process: 1
CurrentTime: 12 , Process: 1
CurrentTime: 13 , Process: 1
CurrentTime: 14 , Process: 1
CurrentTime: 15 , Process: 1
CurrentTime: 16 , Process: 1
CurrentTime: 17 , Process: 3
CurrentTime: 18 , Process: 3
CurrentTime: 19 , Process: 3
CurrentTime: 20 , Process: 3
CurrentTime: 21 , Process: 3
CurrentTime: 22 , Process: 3
CurrentTime: 23 , Process: 3
CurrentTime: 24 , Process: 3
CurrentTime: 25 , Process: 3
Current Time: 26

Waiting Time
Process 1, Waiting Time: 9
Process 2, Waiting Time: 0
Process 3, Waiting Time: 15
Process 4, Waiting Time: 2

Average Waiting Time: 6.5
*/
