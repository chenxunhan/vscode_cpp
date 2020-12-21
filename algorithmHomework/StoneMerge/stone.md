h[index]
index: 1  2  3  4  5
value: 7  6  5  7  100
c[i,j]


max{c[i,(i+n-1)%n]},i=1,2,3...n

i==j: c[i,j]=h[i]  (may nowrite)

abs(i-j)==1: c[i,j]=h[i]+h[j] (bottom)

else 
max: c[i,j]=max{(c[i,k-1]+h[k]) + (c[i,k-1]+h[k] + c[k+1,j])  ,
                (h[k]+c[k+1,j]) + (c[i,k-1] + h[k]+c[k+1,j])} , k=i+1, i+2, ... j-2, j-1
min: c[i,j]=min{(c[i,k-1]+h[k]) + (c[i,k-1]+h[k] + c[k+1,j])  ,
                (h[k]+c[k+1,j]) + (c[i,k-1] + h[k]+c[k+1,j])} , k=i+1, i+2, ... j-2, j-1
max: c[i,j]=max{(c[i,k-1]+h[k]) + (c[i,k-1]+h[k] + c[k+1,j])  ,
                (h[k]+c[k+1,j]) + (c[i,k-1] + h[k]+c[k+1,j])} , k=i+1, i+2, ... j-2, j-1
min: c[i,j]=min{(c[i,k-1]+h[k]) + (c[i,k-1]+h[k] + c[k+1,j])  ,
                (h[k]+c[k+1,j]) + (c[i,k-1] + h[k]+c[k+1,j])} , k=i+1, i+2, ... j-2, j-1






h[index]
index: 1  2  3  4  5
value: 7  6  5  7  100
c[i,l] i~(i+l) l==current_length-1

max{c[i,l]}, l=n-1, i=1,2,..n

l==0: c[i,l]=0  (may nowrite)

l==1: c[i,l]=h[i]+h[i+l] (bottom)

else 
max: c[i,l]=(c[i,k-1] + h[i+k] + c[i+k+1,l-(i+k+1)])+
     max{c[i,k-1]+h[i+k],h[i+k]+c[k+1,l-(k+1)]} , k=1,2,...,l-1
min: c[i,l]=(sum[i,l])+
     min{c[i,k-1]+h[i+k],h[i+k]+c[k+1,l-(k+1)]} , k=1,2,...,l-1
lese2
max: c[i,l]=max{sum[i,l]+c[i,k]+c[k+1,l-(k+1)]} , k=1,2,...,l-1
min: c[i,l]=max{sum[i,l]+c[i,k]+c[k+1,l-(k+1)]} , k=1,2,...,l-1


MAXHEAPNUMBER
heap_number
heap_score[N]
subheap_score_sum[N,N]
max_merge_score[N,N]
maxmerge_headpart_lastindex[N,N]
min_merge_score[N,N]

initHeap(){
    cin>>heap_number
    cin>>heap_score[]
    loop:sub[][0]=heap_score[]
    heap_score[i,0]
    //init sub,起点不变，长度变
    for i=0 to n:
        for l=1 to n:
            if(l<=heap_number-i-l){
                sub[i,l]=sub[i,l-1]+score[getindex(i+l)]
            }
}

//每一次调用heap_score用这个
getHeapIndex(start_index_,length_){
    return (start_index+length_)%heap_number
}

dp_merge_score(){
    //max
    从0~n-1,长度为n-1的所有情况都要搞
    //for(start_index_=0 to n-1)

    分割位置从l:1~n-1都要搞
    for(idx1=0 to n-1){
        maxmerge[idx,1]=score[getindex(idx)]+score(getidx(idx+1))//len=1
    }
    for(idx1=0 to n-1)
    for(len=2 to n-1){
            max_score=INTMIN
            max_pos//前面子段的last一个score
            for(k=1 to len-1)
                if(subsum[idx1,len]+mergemax[idx1,k]+mergemax[k+1,len-(k+1)])>max_score{
                    max_score=subsum[idx1,len]+mergemax[idx1,k]+mergemax[k+1,len-(k+1)]
                    max_pos=k
                }
                
                
        }
    }

    //min

}