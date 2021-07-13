#include<bits/stdc++.h>
using namespace std;

int n;
class Ele{
    private:
    int pro_=-1;
    public:
    vector<int> v;
    int pro(){
        if (pro_==-1){
            for (auto vi=v.begin();vi!=v.end(); ++vi){
                pro_ *= (*vi);
                pro_ %= n;
            }
        }
    }
};

vector<Ele> V;
Ele proNum(vector<Ele>::iterator Vi,int num){
    vector<Ele> 
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i < n;++i){
        vector<Ele> Vt;
        Ele e;
        e.v.push_back(i);
        Vt.push_back(e);
        for(auto Vi = V.begin(); Vi != V.end(); ++Vi){
            Vt.push_back();
        }
    }
        return 0;
}