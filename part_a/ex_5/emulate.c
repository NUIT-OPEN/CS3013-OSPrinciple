#include<stdio.h>

/*数据结构*/
int block_num;   /*分配的物理块数*/
int page_num;   /*要访问的页面序列个数*/
int page[100]; /*要访问的页面序列*/
int memory[10]; /*物理块中的页号*/
int table[100][10]; /*显示矩阵*/
int reg[10];  /*寄存器--记录页面的访问时间*/
char Que[100];  /*数组，记录是否缺页*/

/*主函数*/
int main() {
    int count = 0; /*记录缺页次数*/
    int i, j, k;

    while (1) {
        printf("请输入分配的物理块的个数(M<=10):\n");
        scanf("%d", &block_num);
        if (block_num > 10)
            printf("输入不合法，请重新输入");
        printf("\n");
        break;
    }

    while (1) {
        printf("请输入要访问的页面序列个数(P<=100):\n");
        scanf("%d", &page_num);
        if (page_num > 100)
            printf("输入不合法，请重新输入");
        printf("\n");
        break;
    }

    printf("请依次输入要访问的页面序列，以空格隔开:\n");
    for (i = 0; i < page_num; i++) {
        scanf("%d", &page[i]);
        Que[i] = 'N';
    }

    for (i = 0; i < block_num; i++)
        memory[i] = -1;   //初始内存块中默认为空，用-1表示

    //访问页面
    for (i = 0; i < page_num; i++) {
        if (i == 0)   //访问的第一个页面
        {
            memory[i] = page[i];
            reg[i] = i;
            for (j = 0; j < block_num; j++)
                table[i][j] = memory[j];
            Que[i] = 'Y';
            count++;
        } else {    /*判断新页面号是否在物理块中*/
            for (j = 0, k = 0; j < block_num; j++) {
                if (memory[j] != page[i])
                    k++;
                else {    /*新页面在内存块中*/
                    reg[j] = i;  //刷新该页面的访问时间
                    for (int n = 0; n < block_num; n++)
                        table[i][n] = memory[n];
                }
            }
        }
        if (k == block_num)   /*新页面不在物理块中，缺页*/
        {
            int q = 0;
            Que[i] = 'Y';
            count++;
            for (int j = 0; j < block_num; j++) {
                if (memory[j] == -1)   /*内存块未满*/
                {
                    memory[j] = page[i];
                    reg[j] = i;
                    for (int n = 0; n < block_num; n++)
                        table[i][n] = memory[n];
                    break;
                } else
                    q++;
            }
            if (q == block_num)/*内存块已满，需采用LRU置换算法选择换出页*/
            {
                int min = 0;  //记录换出页
                for (int m = 1; m < block_num; m++)
                    if (reg[m] < reg[min])
                        min = m;
                memory[min] = page[i];
                reg[min] = i; /*记录该页的访问时间（新到的页面进入之前min的位置，需将min位置的访问时间更改）*/
                for (int n = 0; n < block_num; n++)
                    table[i][n] = memory[n];
            }
        }
    }

    /*输出运行过程及结果*/
    printf("采用LRU页面置换算法结果如下: \n");
    printf("\n");
    printf("\n");
    printf("页号:");
    for (i = 0; i < page_num; i++)
        printf("%3d", page[i]);
    printf("\n");
    printf("-----------------------------------------------------\n");
    for (i = 0; i < block_num; i++) {
        printf("块%2d:", i);
        for (j = 0; j < page_num; j++)
            printf("%3d", table[j][i]);
        printf("\n");
    }
    printf("-----------------------------------------------------\n");
    printf("缺页:");
    for (i = 0; i < page_num; i++)
        printf("%3c", Que[i]);
    printf("\n");

    printf("-----------------------------------------------------\n");
    printf("\t缺页次数:%d\n", count);
    printf("\t缺页率:%d/%d\n", count, page_num);
    printf("-----------------------------------------------------\n");
}
