
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define SIZE 32

typedef struct {
    uint8_t buffer[SIZE];
    uint8_t head;
    uint8_t tail;
    size_t count;
    pthread_mutex_t mutex;
}RingBuffer;

bool ring_buffer__init(RingBuffer* rb) {
    if (rb == NULL) {
        return false;
    }
    memset(&rb->buffer, 0, sizeof(rb->buffer));
    rb->head = 0;
    rb->tail = 0;
    rb->count = 0;
    return true;
}

bool ring_buffer__full(RingBuffer* rb) {
    if (rb == NULL) {
        return false;
    }
    return rb->count == (SIZE - 1);
}

bool ring_buffer__empty(RingBuffer* rb) {
    if (rb == NULL) {
        return false;
    }
    return rb->count == 0;
}

bool ring_buffer__push(RingBuffer *rb, uint8_t data) {
    if (rb == NULL) {
        return false;
    }
    pthread_mutex_lock(&rb->mutex);
    if (ring_buffer__full(rb)) {
        pthread_mutex_unlock(&rb->mutex);
        return false;
    }
    rb->buffer[rb->head] = data;
    rb->head = (rb->head + 1) % SIZE;
    rb->count++;
    pthread_mutex_unlock(&rb->mutex);
    return true;
}

bool ring_buffer__pop(RingBuffer *rb, uint8_t* data) {
    if (rb == NULL) {
        return false;
    }
    pthread_mutex_lock(&rb->mutex);
    if (ring_buffer__empty(rb)) {
        pthread_mutex_unlock(&rb->mutex);
        return false;
    }
    *data = rb->buffer[rb->tail];
    rb->tail = (rb->tail + 1) % SIZE;
    rb->count--;
    pthread_mutex_unlock(&rb->mutex);
    return true;
}

void* producer(void* _rb) {
    RingBuffer* rb = (RingBuffer*)_rb;
    uint8_t i = 0;
    while (true) {
        printf("pushing: %d\n", i);
        bool result = ring_buffer__push(rb, i);
        printf("Pushed value: (%d)\n", result, i);
        i++;
        sleep(1);
    }
}

void* consumer(void* _rb) {
    RingBuffer* rb = (RingBuffer*)_rb;
    uint8_t data = 0;
    while (true) {
        printf("consumer\n");
        bool result = ring_buffer__pop(rb, &data);
        printf("Popped value?(%d): %d\n", result, data);
        sleep(5);
    }
}

int main() {

    pthread_t t1, t2, p3, p4;
    RingBuffer rb;
    ring_buffer__init(&rb);

    pthread_create(&t1, NULL, producer, &rb);
    pthread_create(&t2, NULL, consumer, &rb);
    pthread_create(&p3, NULL, producer, &rb);
    pthread_create(&p4, NULL, producer, &rb);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(p3, NULL);
    pthread_join(p4, NULL);

    return 0;
}
