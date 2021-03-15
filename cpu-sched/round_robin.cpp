#include<bits/stdc++.h>
using namespace std;

void print_gantt_chart(vector<string> v) {
  string s = "|";
  cout << "____________________________________________________________________" << endl;
  for (auto p : v) s += p + "|";
  cout << s << "\n";
  cout << "￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣\n";
}

int main() {
  int p, start, end, atime, btime, quantum;
  string pid;
  priority_queue<tuple<int, int, string>, vector<tuple<int, int, string> >, greater<tuple<int, int, string> > > pq;
  cout << "Enter number of processes: ";
  cin >> p;

  for (int i = 0; i < p; i++) {
    cout << "Enter process name of process " << i + 1 << ": ";
    cin >> pid;
    cout << "Enter the arrival time of process " << i + 1 << ": ";
    cin >> atime;
    cout << "Enter the burst time of process " << i + 1 << ": ";
    cin >> btime;
    pq.push({ atime, btime, pid });
  }

  double waiting_time = 0, turnaround_time = 0, total_time = 0, total_turnaround_time = 0, total_waiting_time = 0;
  vector<string> v;

  cout << "\tProcess\tArrival Time\tBurst Time\tTurnaround time\tWait Time\tTotal Time\n\n";
  while (!pq.empty()) {
    
  }
  print_gantt_chart(v);
  cout << "\nAverage Turnaround Time: " << total_turnaround_time / p << "\n";
  cout << "\nAverage Waiting Time: " << total_waiting_time / p << "\n";
  return 0;
}
