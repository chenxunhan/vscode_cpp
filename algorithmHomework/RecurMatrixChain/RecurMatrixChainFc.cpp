n =, P[]     //num and vectorChain
    equation{//calculate m[i,j]
             //m[i,j] stand Ai*A(i+1)*...*A(j-1)*A(j)
             //Ai==A((i-1)*i)
             = 0（i == j） = min(m[i, k] + m[k + 1, j] + P(i - 1) * Pk * Pj) （i < j）}

resm[j + 1, j + 1];
ress[j + 1, j + 1];

f0(P[], n) {
    for (i = 1 to n) {
        resm[i, i] = 0;
        ress[i, i] = i;
    }
    // confirm chain len
    // move chain
    // div chain
    for (len = 2 to n) { //confirm j-i+1
        //len=2,n=5,idx1 to end =5-2+1=4
        for (idx1 = 1 to n - len + 1) { //confirm i
            idx2 = idx1 + len - 1;
            ress[idx1, idx2] = max; //prepare for resm[idx1, idx2]
            //do not be idx1==idx2
            for (k = idx1 to idx2 - 1) { //wa k must !=idx2 ,because down code k+1<=idx2
                now = resm[i, k] + resm[k + 1, idx2] + P[i - 1] * P[k] * P[idx2];
                if (ress[idx1, idx2] > now) {
                    ress[idx1, idx2] = now;
                    resm[idx1, idx2] = k;
                }
            }
        }
    }
}

printresm() {
    for (i = 1 to n) {
        for (j = 1 to n) {
            cout << resm[i, j] << " "
        }
    }
}

printress() {
    for (i = 1 to n) {
        for (j = 1 to n) {
            cout << resm[i, j] << " "
        }
    }
}

printA(int a) {
    printf("Aa");
}
printChar(char c, int n) {
    for (i = 1 to n) {
        printf("c");
    }
}
你好
left[n] = right[n] = {0} //save at index need howmany '(' and ')'
innerlr(a, b) {
    if (a == b) {
        return;
    }
    ++left[a], ++right[b + 1];
    innerlr(a, resm[a, b] + 1)
        innerlr(resm[a, b] + 1, b + 1)
}
A 1 2 3 4 5 6 ... n(1 2 3 4 5 6 7) 1 2 3 4 5 6 7 printres() {
    if (n <= 2) {
        for (i = 1 to n) {
            printA(i);
        }
        return;
    }
    memset left right 0 left[0] = -1, right
                                      innerlr(1, n)
        //cout<<res
        for (i = 1 to n) {
        printc(')', right[i])
            printc('(', left[i])
                printa(i)
    }
}

int main() {
    n =, P[n + 1] = ;
    f0(P[], n);

    return 0;
}
/*2 book worse change dp
n=,P[]//num and vectorChain
equation{//calculate m[i,j]
    //m[i,j] stand Ai*A(i+1)*...*A(j-1)*A(j)
    //Ai==A((i-1)*i)
    =0（i==j）
    =min(m[i,k]+m[k+1,j]+P(i-1)*Pk*Pj)（i<j） 
}
res[j+1,j+1]={-1};
resS[j + 1, j + 1] = {-1};

f(P[],i,j){
    if(res[i][j]!=-1){
        return res[i][j];
    }
    fm=max, fs;
    // if(i == j){
    //     m[i, j] = 0, s[i, j] = k;//wo
    //     return 0;
    //     }
    ////up code is be main process
    //else i<j
        for(k=i to j){
            now=f(P, i, k) + f(P, k + 1, j) + P[i-1] * P[k] * P[j]//wo
            if(fm>now){
                fm = now;
                fs = k;
            }        
    }
    m[i, j] = fm;
    s[i, j] = fs;
    return m[i, j];
}
int main(){
    n = ?, P[n] = {? };
    for(i=1 to n){
        res[i, i] = 0;
        resS[i, i] = i;
    }
    cout << f(P, 1, n);
    return 0;
}
*/

/*1book worse
n=,P[]//num and vectorChain
equation{//calculate m[i,j]
    //m[i,j] stand Ai*A(i+1)*...*A(j-1)*A(j)
    //Ai==A((i-1)*i)
    =0（i==j）
    =min(m[i,k]+m[k+1,j]+P(i-1)*Pk*Pj)（i<j） 
}
f(P[],i,j){
    m[i, j]=max, s[i, j];
    if(i == j){
        m[i, j] = 0, s[i, j] = k;//wo
        return 0;
        }
    //else i<j
        for(k=i to j){
            now=f(P, i, k) + f(P, k + 1, j) + P[i-1] * P[k] * P[j]//wo
            if(m[i,j]>now){
                m[i, j] = now;
                s[i, j] = k;
            }        
    }
    return m[i, j];
1 1 2 5 14 
}
int main(){
    n = ?, P[n] = {? };
    cout << f(P, 1, n);
    return 0;
}
*/