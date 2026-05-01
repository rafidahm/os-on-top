#include <iostream>
using namespace std;

int main() {

    // -------- INPUT SECTION --------
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int pid[n], at[n], bt[n];
    int ct[n], tat[n], wt[n], done[n];

    for(int i = 0; i < n; i++) {
        cout << "Enter PID, AT, BT: ";
        cin >> pid[i] >> at[i] >> bt[i];
        done[i] = 0; // mark unfinished
    }

    int currentTime = 0, completed = 0;

    // -------- CALCULATION + GANTT LOGIC --------
    cout << "\nGantt Chart:\n0";

    while(completed < n) {

        int idx = -1;
        int minBT = 1e9;

        // Find shortest job among arrived processes
        for(int i = 0; i < n; i++) {
            if(at[i] <= currentTime && done[i] == 0 && bt[i] < minBT) {
                minBT = bt[i];
                idx = i;
            }
        }

        // If no process available → CPU idle
        if(idx == -1) {
            currentTime++;
            continue;
        }

        // Execute process fully (non-preemptive)
        cout << " ---- P" << pid[idx] << " ";
        currentTime += bt[idx];
        cout << currentTime;

        ct[idx] = currentTime;
        done[idx] = 1;
        completed++;
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
