int money, item;
int f[][];

f[money][item] = {
    {} {} {}}

F[money][item] = {{}, {}, {}}

x[money][item] = {}

int
F_(money, item) {

    if (F[money][item] != -1) {
        return F[money][item];
    }
    if (money == 0) {
        return F[0][item] = 0;
    }
    if (item == 1) {
        return F[money][1] = f[money][item]
    }
    nowF = 0;
    nowx for (i = 0 to money) { //wrong i=1
        tF = f[i][item] + F(money - i, item - 1);
        if (tF > nowF) {
            nowF = tF;
            nowx = i;
        }
        return F[money][item] = nowF;
    }

    printF() {
        cout << "F:\n";
        for (i = 0 to money) {
            for (j = 0 to item) {
                cout << F(i, j)
            }
        }
    }

    printx() {
        cout << "x:\n";
        for (i = 0 to money) {
            for (j = 0 to item) {
                cout << x[i][j]
            }
        }
    }

    printPlan(money, item, bool first) {
        if (item == 1) {
            "x1=" x[money][item]
        } else {
            printPlan(money - x[][], item - 1, 0);
            "x item=" x[][]
        }

        if (first) {
            ".\n"
        } else {
            ",\n"
        }
    }

    printMax(){
        "F%d(%d)=%d", item, money, F(money, item)}

    init(money_, item_, f_) {
        money = money_, item = item_, f = f_;
        for (int i = 0; i <= money; ++i) {
            for (int j = 0; j <= item; ++i) {
                F[][] = -1;
            }
        }
    }
    main {

        // money =, item = ;
        //  f_[][] = {} f = f0;//first col set real money
        f_[][] = {} init();
        printF;
        printx;
        printPlan;
        printMax;
    }