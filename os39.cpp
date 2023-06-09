#include <stdio.h>

struct Process {
    int processId;
    int burstTime;
    int arrivalTime;
    int waitingTime;
    int turnaroundTime;
};
void sortProcesses(struct Process* processes, int numProcesses)
{
    for (int i = 0; i < numProcesses - 1; i++) 
	{
        for (int j = 0; j < numProcesses - i - 1; j++) 
		{
            if (processes[j].burstTime > processes[j + 1].burstTime) 
			{

                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}
void calculateAverageTimes(struct Process* processes, int numProcesses)
{
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    processes[0].waitingTime = 0; 

    for (int i = 1; i < numProcesses; i++) 
	{
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
        totalWaitingTime += processes[i].waitingTime;
    }

    for (int i = 0; i < numProcesses; i++) 
	{
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }

    float avgWaitingTime = (float)totalWaitingTime / numProcesses;
    float avgTurnaroundTime = (float)totalTurnaroundTime / numProcesses;

    printf("Average Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
}

int main()
{
    struct Process processes[3];
    int numProcesses = 3;

    for (int i = 0; i < numProcesses; i++) 
	{
        processes[i].processId = i;
        printf("Enter burst time for process %d: ", i);
        scanf("%d", &processes[i].burstTime);
        processes[i].arrivalTime = 0; 
    }

    sortProcesses(processes, numProcesses);
    calculateAverageTimes(processes, numProcesses);

    return 0;
}#include <stdio.h>
#include <stdlib.h>
void sort(int arr[], int n) 
{
    int i, j, temp;
    for (i = 0; i < n-1; i++) 
	{
        for (j = 0; j < n-i-1; j++) 
		{
            if (arr[j] > arr[j+1])
			{
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int calculateHeadMovement(int req[], int n, int head) 
{
    int i, index, totalMovement = 0;

    sort(req, n);

    for (i = 0; i < n; i++) 
	{
        if (req[i] >= head) 
		{
            index = i;
            break;
        }
    }
    for (i = index; i < n; i++) 
	{
        totalMovement += abs(head - req[i]);
        head = req[i];
    }
    for (i = 0; i < index; i++) 
	{
        totalMovement += abs(head - req[i]);
        head = req[i];
    }

    return totalMovement;
}

int main() 
{
    int n, head, i;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int req[n];

    printf("Enter the requests:\n");
    for (i = 0; i < n; i++) 
	{
        scanf("%d", &req[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    int totalMovement = calculateHeadMovement(req, n, head);
    float averageMovement = (float)totalMovement / n;

    printf("Total head movement: %d\n", totalMovement);
    printf("Average head movement: %.2f\n", averageMovement);

    return 0;
}
