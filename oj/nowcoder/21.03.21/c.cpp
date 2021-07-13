#include<bits/stdc++.h>
using namespace std;

int caseNum, areaNum;
int wA, wB, allV;

class Area{
    public:
      int Anum=0,Bnum=0,V=0;
      int ka, kb;
      bool winIdx;//1a 0b
        int pa(){
            if(winIdx){
                return ka=Anum - 1 - V / 2;
            }else{
                return ka=Anum;
            }
        }
        int pb(){
            if(!winIdx){
                return kb=Bnum - 1 - V / 2;
            }else{
                return kb=Bnum;
            }
        }
        void disp(){
            V = Anum + Bnum;
            allV += V;
            winIdx = (Anum> Bnum);
            printf("%c %d %d\n", (winIdx ? 'A' : 'B'),pa(),pb());
            wA += ka, wB += kb;
        }
}area[10005];

int main(){
    scanf("%d%d", &caseNum, &areaNum);
    for(int i = 1,d,a,b; i <= caseNum; ++i){
        scanf("%d%d%d", &d, &a, &b);
        area[d].Anum += a,
            area[d].Bnum += b;                
    }
    for(int i = 1; i <= areaNum; ++i){
        area[i].disp();
    }
        printf("%.10lf\n", fabs(wA - wB) / allV);
    return 0;
}