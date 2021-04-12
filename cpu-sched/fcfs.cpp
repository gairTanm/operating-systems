#include<bits/stdc++.h>
using namespace std;

int main() {
  int p, atime, btime;
  string pid;
  priority_queue<tuple<int, int, string>, vector<tuple<int, int, string> >, greater< > > pq;
  cout << "Enter number of processes: ";
  cin >> p;

  for (int i = 0; i < p; i++) {
    cout << "Enter process name of process " << i << ": ";
    cin >> pid;
    cout << "Enter the arrival time of process " << i << ": ";
    cin >> atime;
    cout << "Enter the burst time of process " << i << ": ";
    cin >> btime;
    pq.push({ atime, btime, pid });
  }

  double waiting_time = 0, turnaround_time = 0, total_time = 0, total_turnaround_time = 0, total_waiting_time = 0;

  cout << "\tProcess\tArrival Time\tBurst Time\tTurnaround time\tWait Time\tTotal Time\n\n";
  while (!pq.empty()) {
    tuple<int, int, string> curr = pq.top();
    waiting_time = total_time - get<0>(curr);
    turnaround_time = (total_time + get<1>(curr)) - get<0>(curr);
    cout << "\t" << get<2>(curr) << "\t" << get<0>(curr) << "\t\t" << get<1>(curr) << "\t\t" << turnaround_time << "\t\t" << waiting_time << "\t\t" << total_time + get<1>(curr) << "\n";
    total_time += get<1>(curr);
    total_waiting_time += waiting_time;
    total_turnaround_time += turnaround_time;
    pq.pop();
  }

  cout << "\nAverage Turnaround Time: " << total_turnaround_time / p << "\n";
  cout << "\nAverage Waiting Time: " << total_waiting_time / p << "\n";
  return 0;
}