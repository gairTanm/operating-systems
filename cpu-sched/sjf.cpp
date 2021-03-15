#include<bits/stdc++.h>
using namespace std;

int main() {
  int p, start, end, time;
  string pid;
  priority_queue<pair<int, string>, vector<pair<int, string> >, greater<pair<int, string> > > pq;
  cout << "Enter the number of processes: ";
  cin >> p;
  for (int i = 0; i < p; i++) {
    cout << "Enter the process id: ";
    cin >> pid;
    cout << "Enter the burst time: ";
    cin >> time;
    pq.push({ time,pid });
  }

  double waiting_time = 0, turnaround_time = 0, total_time = 0;

  cout << "\tProcess\tArrival Time\tBurst Time\tTurnaround time\tWait Time\n\n";
  while (!pq.empty()) {
    pair<int, string> curr = pq.top();
    total_time += curr.first;
    turnaround_time += total_time;
    cout << "\t" << curr.second << "\t" << 0 << "\t\t" << curr.first << "\t\t" << total_time << "\t\t" << total_time - curr.first << "\n";
    waiting_time += total_time - curr.first;
    pq.pop();
  }

  cout << "\nAverage Turnaround Time: " << turnaround_time / p << "\n";

  cout << "Average Waiting Time: " << waiting_time / p << "\n";
  return 0;
}