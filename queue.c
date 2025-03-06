#include <stdio.h>
#include <stdlib.h>

typedef struct buf{
    int *buffer;     // 数据存储数组
    int capacity;    // 队列容量
    int front;       // 队头指针
    int rear;        // 队尾指针
    int count;       // 当前元素数量
} RingBuffer;

// 创建环形队列
RingBuffer* ring_buffer_create(int capacity) {
    RingBuffer* rb = (RingBuffer*)malloc(sizeof(RingBuffer));
    rb->buffer = (int*)malloc(sizeof(int) * capacity);
    rb->capacity = capacity;
    rb->front = 0;
    rb->rear = 0;
    rb->count = 0;
    return rb;
}

// 销毁环形队列
void ring_buffer_destroy(RingBuffer* rb) {
    free(rb->buffer);
    free(rb);
}

// 入队操作（队列满时覆盖最旧数据）
void ring_buffer_push(RingBuffer* rb, int data) {
    if (rb->count == rb->capacity) {
        // 队列满时覆盖队头数据并移动队头
        rb->front = (rb->front + 1) % rb->capacity;
    } else {
        rb->count++;
    }
    rb->buffer[rb->rear] = data;
    rb->rear = (rb->rear + 1) % rb->capacity;
}

// 出队操作
int ring_buffer_pop(RingBuffer* rb, int *data) {
    if (rb->count == 0) {
        return -1; // 队列空
    }
    *data = rb->buffer[rb->front];
    rb->front = (rb->front + 1) % rb->capacity;
    rb->count--;
    return 0;
}

// 判断队列是否为空
int ring_buffer_is_empty(RingBuffer* rb) {
    return rb->count == 0;
}

// 判断队列是否已满
int ring_buffer_is_full(RingBuffer* rb) {
    return rb->count == rb->capacity;
}

// 获取队列当前元素数量
int ring_buffer_size(RingBuffer* rb) {
    return rb->count;
}

// 测试代码
int main() {
    RingBuffer* rb = ring_buffer_create(3);

    printf("Push 1, 2, 3\n");
    ring_buffer_push(rb, 1);
    ring_buffer_push(rb, 2);
    ring_buffer_push(rb, 3);

    printf("Is full: %d\n", ring_buffer_is_full(rb)); // 输出1（true）

    int data;
    printf("Push 4 (mask old data)\n");
    ring_buffer_push(rb, 4); // 覆盖1

    printf("reject all elements: ");
    while (!ring_buffer_is_empty(rb)) {
        ring_buffer_pop(rb, &data);
        printf("%d ", data);
    }
    printf("\n"); // 输出: 2 3 4

    ring_buffer_push(rb, 5);
    ring_buffer_push(rb, 6);
    ring_buffer_push(rb, 7);
    ring_buffer_push(rb, 8); // 覆盖5

    printf("reject all elements: ");
    while (!ring_buffer_is_empty(rb)) {
        ring_buffer_pop(rb, &data);
        printf("%d ", data);
    }
    printf("\n"); // 输出: 6 7 8

    ring_buffer_destroy(rb);
    return 0;
}