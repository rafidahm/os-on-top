#include <iostream>
using namespace std;

int main() {

    // -------- INPUT SECTION --------
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int pid[n], at[n], bt[n], rt[n];
    int ct[n], tat[n], wt[n];

    for(int i = 0; i < n; i++) {
        cout << "Enter PID, AT, BT: ";
        cin >> pid[i] >> at[i] >> bt[i];
        rt[i] = bt[i]; // remaining time
    }

    int currentTime = 0, completed = 0;

    // -------- GANTT CHART + CALCULATION --------
    cout << "\nGantt Chart:\n";

    while(completed < n) {

        int idx = -1, minRT = 1e9;

        // Find shortest remaining time process
        for(int i = 0; i < n; i++) {
            if(at[i] <= currentTime && rt[i] > 0 && rt[i] < minRT) {
                minRT = rt[i];
                idx = i;
            }
        }

        // If no process → CPU idle
        if(idx == -1) {
            cout << "IDLE ";
            currentTime++;
            continue;
        }

        // Execute for 1 unit (preemptive)
        cout << "P" << pid[idx] << " ";
        rt[idx]--;
        currentTime++;

        // If process finished
        if(rt[idx] == 0) {
            ct[idx] = currentTime;
            completed++;
        }
    }

    // -------- CALCULATE TAT & WT --------
    for(int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // -------- OUTPUT TABLE --------
    cout << "\n\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i = 0; i < n; i++) {
        cout << pid[i] << "\t" << at[i] << "\t" << bt[i] << "\t"
             << ct[i] << "\t" << tat[i] << "\t" << wt[i] << endl;
    }

    return 0;
}
