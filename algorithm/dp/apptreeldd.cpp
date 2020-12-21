#include <stdio.h>
#include <stdlib.h>

//可利用全
typedef struct Tree {
    int initialization, growSpeed;
} tree;
int room = sizeof(tree);

int comp(const void *a, const void *b) {
    return ((tree *) b)->growSpeed - ((tree *) a)->growSpeed;
}

int main() {

    int allTree, workDay, max, sum, record, maxChange, recChange;
    int j, k;
    while (~scanf("%d%d", &allTree, &workDay)) {
        tree orchard[allTree];

        //输入
        for (j = 0; j < allTree; ++j)
            scanf("%d", &orchard[j].initialization);
        for (j = 0; j < allTree; ++j)
            scanf("%d", &orchard[j].growSpeed);

        //依据增长速度排序
        qsort(orchard, allTree, room, comp);

        //先计算好前m棵树
        for (j = 0, max = 0; j < workDay; ++j)
            max += orchard[j].initialization + orchard[j].growSpeed * (workDay - j - 1);

        //计算后面的每一棵树
        for (j = workDay; j < allTree; ++j) {
            //尝试逐个替代并寻找最大值
            for (sum = 0, k = workDay - 1, record = workDay, maxChange = 0; k >= 0; --k) {
                if (orchard[j].initialization + sum > orchard[k].initialization +
                                                          (workDay - k - 1) * orchard[k].growSpeed) {
                    recChange = orchard[j].initialization - orchard[k].initialization + sum - (workDay - k - 1) * orchard[k].growSpeed;
                    if (recChange > maxChange) {
                        maxChange = recChange, record = k;
                    }
                }

                sum += orchard[k].growSpeed;
            }

            max += maxChange;
            //若找到则插入
            if (record < workDay) {
                for (k = record; k < workDay - 1; ++k)
                    orchard[k] = orchard[k + 1];

                orchard[workDay - 1] = orchard[j];
            }
        }

        printf("%d\n", max);
    }

    return 0;
}
