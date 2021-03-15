#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int weight, degree;
};

bool comp(const Node& a, const Node& b){return a.weight >= b.weight;}

int main()
{
    int cases;
    cin>>cases;
    
    while(cases--)
    {
        int n;
        cin>>n;
        
        Node nodes[n];
        long long sum(0);
        for(auto &e : nodes)
        {
            cin>>e.weight;
            sum+=e.weight;
            e.degree = -1;
        }
        for(int i(1),head,tail;i<n;++i)//n-1
        {
            cin>>head>>tail;
            ++nodes[head-1].degree;++nodes[tail-1].degree;
        }
        
        sort(nodes, nodes+n,comp);
        
        int times(n-1  -1);
        size_t posit(0);
        
        cout<<sum<<' ';
        for(int i(0);i<times;++i)
        {
            while(nodes[posit].degree<=0)++posit;
            sum+=nodes[posit].weight;
            cout<<sum<<' ';
            --nodes[posit].degree;
        }
        cout<<'\n';
    }
    
    return 0;
}