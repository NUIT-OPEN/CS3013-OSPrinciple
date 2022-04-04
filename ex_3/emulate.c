#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

typedef char *string;
typedef struct PCB *PCB;

/*
    进程状态
    WFA ：进程还未到——所有非零时刻到达的进程执行前的初始状态
    Ready  ：进程到达后处于就绪状态，等待CPU资源
    Running：进程处于运行态
    Finish ：进程执行结束
*/

#define PS_WFA "WFA"
#define PS_READY "Ready"
#define PS_RUNNING "Running"
#define PS_FINISH "Finish"

struct PCB {
    string name;                          // 进程名 *
    double arrivalTime;                   // 进程到达时间 *
    double serviceTime;                   // 进程要求服务时间 *
    double startTime;                     // 进程开始执行时间
    double needServiceTime;               // 进程还需占用CPU时间
    double endTime;                       // 进程执行完成时间
    double priority;                      // 进程优先级
    double turnaroundTime;                // 进程周转时间
    double weightTurnaroundTime;          // 进程带权周转时间
    string status;                        // 进程状态
};


PCB *initProcess(int *pNum) {
    printf("# 该进程调度算法可以输出各关键时间节点的所有进程状态，目前时间仅支持整数 #\n");
    printf("请输入进程数：");

    scanf("%d", pNum);
    PCB *pcbs = malloc(sizeof(PCB) * (*pNum));

    printf("请依次输入 进程名 到达时间 服务时间（如：A 0 3)\n");
    for (int i = 0; i < *pNum; i++) {
        pcbs[i] = malloc(sizeof(struct PCB));

        string pName = malloc(sizeof(char) * 256);
        double pArriveTime, pServiceTime;

        scanf("%s %lf %lf", pName, &pArriveTime, &pServiceTime);
        pcbs[i]->name = pName;
        pcbs[i]->arrivalTime = pArriveTime;
        pcbs[i]->serviceTime = pServiceTime;
        if (!pArriveTime)
            pcbs[i]->status = PS_READY;
        else
            pcbs[i]->status = PS_WFA;
    }

    return pcbs;
}

bool isAllFinished(PCB *pcbOutput, int pNum) {
    for (int i = 0; i < pNum; ++i) {
        if (strcmp(pcbOutput[i]->status, PS_FINISH))
            return false;
    }
    return true;
}

int statusToValue(string status) {
    if (!strcmp(status, PS_WFA))
        return 3;
    else if (!strcmp(status, PS_READY))
        return 2;
    else if (!strcmp(status, PS_RUNNING))
        return 1;
    else if (!strcmp(status, PS_FINISH))
        return 4;

    return 0;
}

bool compareServiceTime(PCB a, PCB b) {
    // 短进程（服务时间）优先
    return (statusToValue(a->status) * 1000 + a->serviceTime)
           < (statusToValue(b->status) * 1000 + b->serviceTime);
}

void sortProcesses(PCB *pcbs, int p_num, bool compare(PCB a, PCB b)) {
    PCB *min, tmp;
    for (int i = 0; i < p_num; ++i) {
        min = &pcbs[i];
        for (int j = i + 1; j < p_num; ++j) {
            if (compare(pcbs[j], *min)) {
                tmp = *min;
                *min = pcbs[j];
                pcbs[j] = tmp;
            }
        }
    }
}

void printProcesses(PCB *pcbs, int p_num, int tick) {
    printf("\n* Tick: %d\n", tick);
    printf("进程名\t\t到达时间\t\t服务时间\t\t开始时间\t\t还需CPU时间\t完成时间\t\t优先级\t\t周转时间\t\t带权周转时间\t状态\n");
    for (int i = 0; i < p_num; ++i) {
        PCB pcb = pcbs[i];
        printf("%s\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%s\n", pcb->name, pcb->arrivalTime, pcb->serviceTime,
               pcb->startTime,
               pcb->needServiceTime, pcb->endTime, pcb->priority, pcb->turnaroundTime, pcb->weightTurnaroundTime,
               pcb->status
        );
    }

    fflush(stdout);
}

void emulateProcess(PCB *pcbs, int p_num) {
    PCB cpu_using = NULL;
    sortProcesses(pcbs, p_num, compareServiceTime);
    for (int tick = 0; !isAllFinished(pcbs, p_num); ++tick) {
        if (cpu_using) {
            PCB pcb = cpu_using;
            if (!strcmp(pcb->status, PS_READY)) {
                pcb->status = PS_RUNNING;
                pcb->startTime = tick;
                pcb->endTime = tick + pcb->serviceTime;
            } else if (!strcmp(pcb->status, PS_RUNNING)) {
                pcb->needServiceTime = pcb->endTime - tick;
                pcb->turnaroundTime = tick - pcb->arrivalTime;
                pcb->weightTurnaroundTime = pcb->turnaroundTime / pcb->serviceTime;

                if (tick >= pcb->endTime) {
                    pcb->status = PS_FINISH;
                    cpu_using = NULL;
                }
            }
        }

        for (int i = 0; i < p_num; ++i) {
            PCB pcb = pcbs[i];
            if (!strcmp(pcb->status, PS_FINISH))
                continue;
            else if (!strcmp(pcb->status, PS_WFA)) {
                if (tick >= pcb->arrivalTime)
                    pcb->status = PS_READY;
            }

            if (!strcmp(pcb->status, PS_READY)) {
                if (!cpu_using)
                    cpu_using = pcb;
            }
        }

        sortProcesses(pcbs, p_num, compareServiceTime);
        printProcesses(pcbs, p_num, tick);
    }
}

int main() {
    int p_num;
    PCB *pcbs = initProcess(&p_num);
    emulateProcess(pcbs, p_num);
    return 0;
}