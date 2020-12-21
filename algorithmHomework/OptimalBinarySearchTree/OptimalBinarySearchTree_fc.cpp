
typedef eleType char;
eleType *S;//注意不能取0，取0报错
int *P; //bi:idx=2*i-1;ai:idx=bi_idx+-1
int w[][];
int m[][],bj[][];

init(S_,P_){
    S = S_-1,//let first_ele be on the one_index
    P = P_;
    for(i=1 to n){
        for(j=1 to n){
            w[i][j] = P[2 * (i - 1)];
            for(k=i to j){
                w[i][j] += P[2*i]+P[2*i-1];//ai,bi
            }
        }
    }
}

dp(){
    for(len=1 to n){
            for (i = 1 to n - len + 1) {
                j = i - len + 1;
                temp = INTMAX;
                for (k = i to j) {
                    temp_ = 0;
                    i <= k - 1 &&temp_ += m[i][k - 1];
                    k + 1 <= j &&temp_ += m[k + 1][j];
                    temp_ < temp &&(temp = temp_,bj[i][j]=k);
                }                
                m[i][j] = temp+ w[i][j];
        }
    } 
}

printM();
printBJ();

printTree(int i,int j){
    if(i==j){
        printf(S[i]);
        return;
    }
    printf(S[bj[i][j]]);
    printf("(");
    printTree(i, bj[i][j] - 1);
    printf(",");
    printTree(bj[i][j] + 1, j);
    printf(")");
}
main(){
    S[];
    P[];
    init();
    dp();
    printM();
    printBJ();
}

