#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Job{
    char id;
    int deadline;
    int profit;
};

bool compare(const Job& a, const Job& b){
    return a.profit > b.profit;
}

void scheduling(vector<Job>& jobs){

    sort(jobs.begin(),jobs.end(),compare);

    int n = jobs.size();

    int maxDeadline = 0;

    for(const auto& job : jobs){
        maxDeadline = max(maxDeadline,job.deadline);
    }

    vector<int> schedule(maxDeadline,-1);
    vector<char> selectedJobs;
    int totalProfit = 0;

    for(const auto& job: jobs){
        for(int i = job.deadline - 1 ; i>=0; --i){

            if(schedule[i] == -1){
                schedule[i] = job.id;
                selectedJobs.push_back(job.id);
                totalProfit += job.profit;
                break;
            }
        }
    }
    cout<<"Selected Jobs with Deadlines: "<<endl;
    for(const auto& job : selectedJobs){
        cout<<"Job"<<job<<endl;
    }
    cout<<"Total profit: "<<totalProfit<<endl;
}

int main() {
    // Initialize job list
    vector<Job> jobs = {
        {'A', 2, 100},
        {'B', 1, 19},
        {'C', 2, 27},
        {'D', 1, 25},
        {'E', 3, 15}
    };

    // Call the job scheduling function
    scheduling(jobs);

    return 0;
}