#include<iostream>

int main(){
    int n, bt[20], wt[20], tat[20], avwt=0, avtat=0, i, j, index[20], itemp, temp;
    std::cout<<"Enter Number of Processes: ";
    std::cin>>n;
    std::cout<<"Enter Process Burst Time:"<<std::endl;
    for(i=0;i<n;i++){
        std::cout<<"P["<<i<<"]:";
        std::cin>>bt[i];
        index[i]=i;
    }
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            if(bt[j]<bt[i]){
                std::swap(bt[i], bt[j]);
                std::swap(index[i], index[j]);
            }
        }
    }
    wt[0]=0;
    std::cout<<std::endl<<"Process\t\tBurst Time\tWaiting Time\tTurnaround Time"<<std::endl;
    for(i=0;i<n;i++){
        wt[i+1]= wt[i]+bt[i];
        tat[i]= wt[i]+bt[i];
        avwt=avwt+wt[i];
        avtat=avtat+tat[i];
        std::cout<<"P["<<index[i]<<"]\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<std::endl;
    }
    std::cout<<std::endl<<"Average Waiting Time: "<<avwt/i<<std::endl;
    std::cout<<"Average Turnaround Time: "<<avtat/n<<std::endl;
    return 0;
}

