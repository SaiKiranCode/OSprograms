#include <bits/stdc++.h>
using namespace std;

class Process
{
public:
    int PID;
    int priority;
    double arrival_time;
    double execution_time;
    double starting_time;
    double waiting_time;

    Process()
    {
    }

    Process(int PID, double arrival_time, double execution_time)
    {
        this->PID = PID;
        this->arrival_time = arrival_time;
        this->execution_time = execution_time;
        starting_time = 0;
        waiting_time = 0;
    }

    void Scan()
    {
        cout << "Enter PID : ";
        cin >> PID;
        cout << "Enter Arrival Time : ";
        cin >> arrival_time;
        cout << "Enter Execution Time : ";
        cin >> execution_time;
        cout << "Priority : ";
        cin >> priority;
        starting_time = 0;
        waiting_time = 0;
    }

    void Print()
    {
        cout << "|" << PID << "\t|\t" << priority << "\t|\t" << arrival_time << "\t|\t" << execution_time << "\t|\t" << starting_time << "\t|\t" << waiting_time << "\t|" << endl;
    }
};

bool operator<(const Process &p1, const Process &p2)
{
    return p1.priority > p2.priority;
}

bool comparator(Process a, Process b)
{
    return (a.arrival_time < b.arrival_time);
}

void Output(vector<Process> p)
{
    cout << "\n\n-----------------------------------------------------------------------------------------\n";
    cout << "|PID\t|  Priority  \t|Arrival Time\t|Execution Time\t|Starting Time\t|Waiting Time\t|\n";
    cout << "-----------------------------------------------------------------------------------------\n";
    for (auto i : p)
    {
        i.Print();
    }
    cout << "-----------------------------------------------------------------------------------------\n";
}

int main()
{

    freopen("input_PRIORITY.txt", "r", stdin);
   

    vector<Process> p;

    int n;
    cout << "Enter the number of processes : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        Process temp;
        temp.Scan();
        p.push_back(temp);
    }

    sort(p.begin(), p.end(), comparator);
   

    priority_queue<Process> pq;
    vector<Process> Final;

    double st = 0, wt = 0;
    pq.push(p[0]);
    int i = 1;
    while (!pq.empty())
    {
       

        Process temp = pq.top();
        wt = st - temp.arrival_time;
        temp.starting_time = st;
        temp.waiting_time = wt;
        st += temp.execution_time;
        Final.push_back(temp);
        pq.pop();

        double upto = temp.starting_time + temp.execution_time;
       
        for (; p[i].arrival_time <= upto && i < n; i++)
        {
           
            pq.push(p[i]);
        }
    }

    Output(Final);

    return 0;
}