int mutex1
int mutex2
int mutex3
int mutex4

main(){

    cobegin
        pd()//down
        pu()//up
        pl()//left
        pr()//right
    coend

}

pd(){
    P(mutex1)
    p(mutex3)
    running...
    v(mutex1)
    v(mutex3)
}

pu(){
    P(mutex4)
    p(mutex2)
    running...
    v(mutex4)
    v(mutex2)
}

pl(){
    P(mutex2)
    p(mutex1)
    running...
    v(mutex2)
    v(mutex1)
}

pr(){
    P(mutex3)
    p(mutex4)
    running...
    v(mutex3)
    v(mutex4)
}