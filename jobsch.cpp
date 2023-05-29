#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Job {
    char id;
    int deadline; 
    int profit;
};

bool comparison(Job a, Job b)
{
    return a.profit > b.profit;
}

int totalprofit = 0;
vector<Job>alljob;

void Schedule(Job arr[], int n)
{
    sort(arr, arr+n, comparison);

    vector<bool>check(n);

    for(int i = 0; i < n; ++i)//Traversing jobs
    {
        for(int j = min(n,arr[i].deadline)-1; j >= 0; j--)//Traversing deadlines*************************
        {
            if(check[j]==false)
            {
                check[j]=true;
                totalprofit += arr[i].profit;
               
                alljob.push_back(arr[i]);
                break;
            }
        }
    }

}

int main()
{
    int n;
    cout<<"Enter number of jobs : \n";
    cin>>n;

    Job arr[n];
    for(int i = 0; i < n; ++i)
    {
        cout<<"Enter id : ";
        cin>>arr[i].id;
        cout<<"Enter deadline : ";
        cin>>arr[i].deadline;
        cout<<"Enter profit : ";
        cin>>arr[i].profit;
        cout<<endl;
    }
    cout<<"All Jobs : \n";
    cout<<"id   "<<"Deadline    "<<"Profit\n";
    for(int i = 0; i < n; ++i)
    {
        cout<<arr[i].id<<"\t"<<arr[i].deadline<<"\t   "<<arr[i].profit<<endl;
    }
    Schedule(arr,n);

    cout<<"After scheduling Jobs with max profit : \n";
    cout<<"id   "<<"Deadline    "<<"Profit\n";
    for(int i = 0; i < alljob.size(); ++i)
    {
        cout<<arr[i].id<<"\t"<<arr[i].deadline<<"\t   "<<arr[i].profit<<endl;
    }
    cout<<"Profit is : "<<totalprofit<<endl;
    
    return 0;
}