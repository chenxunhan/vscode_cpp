n//����
divn//
P[]//�������� ����p1~pn
S[]//����¼
l[]//l[i]: ���һ�εĳ���
b[]//b[i]: pi�Ķ����Ƴ���
bm[]//bm[]: piΪ�������P�ָ�ε����һ����㣬��һ�εĸ����������Ƴ���
int length(p){
    if(p)
        return 1;
    length = 0;
    while(p){
        ++length;
        p >>= 1;
    }
}

//calculate l[] and S[] bm[] b[]
compress(P[]){
    header = 11, Lmax = 256;
    S[0] = 0;
    for (i = 1 to n) { 
            b[i] = length(i);
            //
            bmax = INT_MIN;
            S[i] = INT_MAX;
            //
            // bmax = b[i];
            // S[i] = S[i-1]+bmax;
            // l[i] = 1;
            for(j =1 to min(i,Lmax)){
                bmax = max(b[i-j+1],bmax);
                if(S[i-j]+j*bmax < S[i]){
                    S[i] = S[i - j] + j * bmax;
                    l[i] = j;
                    bm[i] = bmax;
                }
            }
            S[i] += header;
        }
}

//reverse
//get C[],divn
C[]//C[i]
Trackback(n,l){
    divn = 1;
    while (n){
        C[divn++] = l[n];
        n -= l[n];
    }
    --divn;
    for (int i = 1; i < divn;++i,--divn){
        swap(C[i],C[divn]);
    }
}

print_div(){
    for (int i = 1,index=0; i <= divn;++i) {
        index += C[i];
        printf("C[i]  bm[index]");
    }
    for (int i = 1,index = 1; i <= divn;++i) {
        printf("<");
        for (; index < C[i];++index) {
            printf("%d,", P[index]);
        }
        printf("%d>", P[index]++);
    }
}

print_savebit(){
    printf("",C[n]);
}

main(){
    copress()
    trackback()
    print_div()
    print_savebit()
}