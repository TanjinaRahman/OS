#include<iostream>
#include<bits/stdc++.h>

using namespace std;

main()
{
    double time = 0,wt[99],  p[99],  protime,  n,  ptime[99],  totaltime =0,  povtime[99],  wait_time = 0;

    cout<<"Enter the number of process: ";
    cin>>n;

    cout<<"\nEnter Process Burst Time:\n"<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<"\t\tp["<<i<<"] = ";
        cin>>p[i];
        ptime[i] = p[i];
        totaltime += p[i];
        povtime[i] = 0;

    }
    cout<<endl<<"Quantum: ";
    cin>>protime;
    cout<<"\n\tStart\tProcess\tStop\n\t********************\n"<<endl;
    while(totaltime)
    {
        int i = 1;
        for(; i<=n; i++)
        {
            if(ptime[i])
            {
                cout<<"\t"<<time<<" \tp["<<i<<"]\t";
                if(ptime[i] > protime)
                {
                    time += protime;
                    ptime[i] -= protime;
                    totaltime -= protime;
                    cout<<time<<endl;
                }
                else
                {
                    time += ptime[i];
                    totaltime -= ptime[i];
                    povtime[i] = time;
                    ptime[i] = 0;
                    cout<<time<<endl;
                }
            }
        }
    }
    cout<<"\nProcess \tBT  \tWT \tTAT\t\n"<<endl;
    int tat=0;
    for(int i=1; i<=n; i++)
    {
        //cout<<"\t\tP["<<i<<"] = "<<(povtime[i] - p[i])<<endl;
        cout<<"P["<<i<<"]\t\t"<<p[i]<<"\t"<<(povtime[i] - p[i])<<"\t"<<povtime[i]<<endl;
        //wt[i]=povtime[i] - p[i];
        wait_time += povtime[i] - p[i];
        tat+=povtime[i];


    }

    cout<<endl<<"Avg waiting time = "<<wait_time/n<<endl;
    cout<<"Avg turnaround time = "<<tat/n<<endl;
}
