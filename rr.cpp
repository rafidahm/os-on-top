#include <iostream>
using namespace std;

int main() {

    // -------- INPUT SECTION --------
    int n, tq;
    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter Time Quantum: ";
    cin >> tq;

    int pid[n], at[n], bt[n], rt[n];
    int ct[n], tat[n], wt[n];

    for(int i = 0; i < n; i++) {
        cout << "Enter PID, AT, BT: ";
        cin >> pid[i] >> at[i] >> bt[i];
        rt[i] = bt[i];
    }

    int currentTime = 0, completed = 0;

    // -------- GANTT CHART + CALCULATION --------
    cout << "\nGantt Chart:\n0 ";

    while(completed < n) {

        bool allIdle = true;

        for(int i = 0; i < n; i++) {

            if(rt[i] > 0 && at[i] <= currentTime) {
                allIdle = false;

                cout << "P" << pid[i] << " ";

                // Execute for time quantum
                if(rt[i] > tq) {
                    currentTime += tq;
                    rt[i] -= tq;
                }
                else {
                    currentTime += rt[i];
                    rt[i] = 0;
                    ct[i] = currentTime;
                    completed++;
                }
            }
        }

        // If no process ready → CPU idle
        if(allIdle) {
            cout << "IDLE ";
            currentTime++;
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
