N 原始数据
tiedp[N+1人][N+1人]放对战联系01表
res[N+1人][N天]放答案
day

tieInRes(day){
    for(i:1~N){
        tiedp>>res[][day]
    }
}

f0(n){
    memset 
    {///day1
        tie(1,n)
        for(i:2~n-1){
            f(i)
        }
        tieInres(1)
        memset
    }
    //day2~N-1
    int dtp=n-1
    for(day:2~N-1){
        tie(n, dpt--);
        for(i:2~n-1){
            f(i)
        }
        tieInres(1)
        memset
    }
}

f(n){
    for (i:N~1){
        if(istied not){
            tie(n, i);
            return;
        }
    }
}

isTied(i,j){
    判断是否ok：
        前面或现在已经在比赛 : return 0;
    for (int di = 1; di <= day;++di){
        if(res[i][di]==j){
            return 0;
        }
    }
    return 1;
}

tie(i,j){
}

输入：
for(人){
    for(天)
    res
}

输出：
for(天){
    for(人)
}