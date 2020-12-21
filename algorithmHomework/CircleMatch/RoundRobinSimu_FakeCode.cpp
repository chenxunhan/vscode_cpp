int to_n(int n0) {
    if (n0 & 1)
        return n0;
    return n0 - 1;
}

int res[n+1(people)][n(day)];

void saveRes(int a[],int day){
    for(i:[0,n/2-1]){
        res[i][day] = a[n-i];
        res[n - i][day] = a[i];
    }
}

void Round(int a[],int len){
    int tail = a[len - 1];
    for(i:[len-1,1]){
        a[i] = a[i - 1];
    }
    a[0] = tail;
}

void f(int n){
    bool odd= n & 1;
    n = to_n(n);
    int a[n + 1];
    for(i:[0,n-1]){
        a[i] = i + 1;
        ++i;
    }
    if(oushu){
        a[n] = n + 1;
    }else{
        a[n] = 0;
    }
    do until include a[0]==2{
            saveRes;
            Round;
    } 
}

void print(){
    
}