#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    int pid[n], at[n], bt[n],ct[n], tat[n], wt[n];
    for(int i = 0; i < n; i++) {
        cout << "Enter Process ID, Arrival Time, Burst Time: ";
        cin >> pid[i] >> at[i] >> bt[i];  }
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(at[i] > at[j]) {
                swap(at[i], at[j]);
                swap(bt[i], bt[j]);
                swap(pid[i], pid[j]); } } }
    int currentTime = 0;
    for(int i = 0; i < n; i++) {
        if(currentTime < at[i]) {
            currentTime = at[i]; }
        ct[i] = currentTime + bt[i];
        currentTime = ct[i]; }
    for(int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
    cout << "\nGantt Chart:\n\n";
    currentTime = 0;
    cout << "0";
    for(int i = 0; i < n; i++) {
        if(currentTime < at[i]) {
            cout << " ---- IDLE ---- " << at[i];
            currentTime = at[i];  }
        cout << " ---- P" << pid[i] << " ";
        currentTime += bt[i];
        cout << currentTime;  }
    cout << "\n\n";
    cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i = 0; i < n; i++) {
        cout << pid[i] << "\t" << at[i] << "\t" << bt[i] << "\t"
             << ct[i] << "\t" << tat[i] << "\t" << wt[i] << endl;   }
    return 0;
}

