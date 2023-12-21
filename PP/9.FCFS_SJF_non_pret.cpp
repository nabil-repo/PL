#include <iostream>
#include <algorithm>
using namespace std;

void FCFS(int processes[], int n, int burstTime[])
{
    int waitingTime[n], turnaroundTime[n];

    waitingTime[0] = 0;
    turnaroundTime[0] = burstTime[0];

    for (int i = 1; i < n; ++i)
    {
        waitingTime[i] = turnaroundTime[i - 1];
        turnaroundTime[i] = waitingTime[i] + burstTime[i];
    }

    cout << "First-Come, First-Served (FCFS) Scheduling:" << endl;
    cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << processes[i] << "\t\t" << burstTime[i] << "\t\t" << waitingTime[i] << "\t\t" << turnaroundTime[i] << endl;
    }
    cout << endl;
}

void SJF(int processes[], int n, int burstTime[])
{
    int waitingTime[n], turnaroundTime[n];

    sort(processes, processes + n, [&](int a, int b)
         { return burstTime[a - 1] < burstTime[b - 1]; });

    waitingTime[0] = 0;
    turnaroundTime[0] = burstTime[processes[0] - 1];

    for (int i = 1; i < n; ++i)
    {
        waitingTime[i] = turnaroundTime[i - 1];
        turnaroundTime[i] = waitingTime[i] + burstTime[processes[i] - 1];
    }

    cout << "Shortest Job First (SJF) Scheduling:" << endl;
    cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << processes[i] << "\t\t" << burstTime[processes[i] - 1] << "\t\t" << waitingTime[i] << "\t\t" << turnaroundTime[i] << endl;
    }
}

int main()
{
    int processes[] = {1, 2, 3, 4}; // Process IDs
    int n = sizeof(processes) / sizeof(processes[0]);

    int burstTimeFCFS[] = {10, 5, 8, 4}; // Burst times for FCFS
    int burstTimeSJF[] = {6, 3, 8, 1};   // Burst times for SJF

    FCFS(processes, n, burstTimeFCFS);
    SJF(processes, n, burstTimeSJF);

    return 0;
}
