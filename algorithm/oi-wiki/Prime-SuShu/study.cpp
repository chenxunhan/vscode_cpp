https://oi-wiki.org/math/prime/

//fermat ËØÐÔ²âÊÔ
bool millerRabin(int n){
    if(n<3){
        return n == 2;
    }
    int test_time = 8;//>=8
    for (int i = 0; i < test_time;++i){
        int a = rand() % (n - 2) + 2;//[2,n-1]
    }
    if(qpow(a,n-1,n)!=1){
        return 0;
    }
    return 1;
}


bool millerRabin(int n,int test_time){
    if(n<3){
        return 2 == n;
    }
    for (int i = 0; i < test_time;++i){
        int a = rand() % (n - 2) + 2;//[2,n-1]
        //[a,b] : rand%(b-a+1)+a
        if(qpow(a,n,n)!=a){
            return 0;
        }
    }
    return 1;
}