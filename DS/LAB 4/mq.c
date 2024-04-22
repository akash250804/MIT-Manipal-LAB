#include <stdio.h>
#include <stdbool.h>

#define MAX_QUEUES 10
#define MAX_ELEMS_PER_QUEUE 10
#define MAX_SIZE (MAX_QUEUES * MAX_ELEMS_PER_QUEUE)

typedef struct {
    int arr[MAX_SIZE];
    int front[MAX_QUEUES];
    int rear[MAX_QUEUES];
    int numQueues;
} MultiQueue;

void initialize(MultiQueue* mq, int n) {
    mq->numQueues = n;

    for (int i = 0; i < n; i++) {
        mq->front[i] = -1;
        mq->rear[i] = -1;
    }
}

bool enqueue(MultiQueue* mq, int item, int queueNum) {
    if (queueNum < 0 || queueNum >= mq->numQueues) {
        printf("Invalid queue number\n");
        return false;
    }

    int startIdx = queueNum * MAX_ELEMS_PER_QUEUE;
    int endIdx = startIdx + MAX_ELEMS_PER_QUEUE - 1;

    if ((mq->rear[queueNum] + 1) % MAX_ELEMS_PER_QUEUE == mq->front[queueNum]) {
        printf("Queue %d Overflow\n", queueNum + 1);
        return false;
    }

    if (mq->front[queueNum] == -1) {
        mq->front[queueNum] = mq->rear[queueNum] = startIdx;
    } else {
        mq->rear[queueNum] = (mq->rear[queueNum] + 1) % MAX_ELEMS_PER_QUEUE + startIdx;
    }

    mq->arr[mq->rear[queueNum]] = item;
    return true;
}

int main() {
    MultiQueue mq;

    int n, val;
    printf("Enter the number of queues (max %d): ", MAX_QUEUES);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_QUEUES) {
        printf("Invalid number of queues!\n");
        return 1;
    }

    initialize(&mq, n);

    for (int i = 0; i < n; i++) {
        printf("Enter the number of elements for Queue %d (max %d): ", i+1, MAX_ELEMS_PER_QUEUE);
        int numElems;
        scanf("%d", &numElems);

        if (numElems > MAX_ELEMS_PER_QUEUE) {
            printf("Error! More than %d elements are not allowed for Queue %d.\n", MAX_ELEMS_PER_QUEUE, i+1);
            continue;
        }

        printf("Enter the elements for Queue %d:\n", i+1);
        for (int j = 0; j < numElems; j++) {
            scanf("%d", &val);
            if (!enqueue(&mq, val, i)) {
                printf("Error enqueuing into Queue %d. Possibly reached its max capacity.\n", i+1);
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("Queue %d: ", i+1);
        if (mq.front[i] != -1) {
            int idx = mq.front[i];
            while (true) {
                printf("%d ", mq.arr[idx]);
                if (idx == mq.rear[i])
                    break;
                idx = (idx + 1) % MAX_ELEMS_PER_QUEUE + i * MAX_ELEMS_PER_QUEUE;
            }
        }
        printf("\n");
    }

    return 17;
}
