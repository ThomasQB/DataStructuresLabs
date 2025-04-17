#include <stdio.h>
int heap[] = {52, 32, 42, 22, 12, 27, 37, 12, 7};;
int size = 9;

void swp(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void down(int i) {
    int max = i;
    int l  = 2*i + 1;
    int r = 2*i + 2;

    if ((l<size) && (heap[l]>heap[max]))
        max = l;
    if ((r<size) && (heap[r]>heap[max]))
        max = r;
    if (max != i) {
        swp(&heap[i], &heap[max]);
        down(max);
    }
}

void up(int i){
    if (i > 0) {
        int parent = (i - 1) /2;
        if (heap[i] > heap[parent]) {
            swp(&heap[i],&heap[parent]);
            up(parent);
        }
    }
}


int del() {
    if (size <= 0) return -1; 
    int root = heap[0];
    heap[0] = heap[size -1];
    size--;
    down(0);
    return root;
}

void insert(int i){
    heap[size++] = i;
    up(size-1);
}

int main() {
    del();
    del();
    del();
    insert(35);
    insert(24);
    insert(10);

    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }

    return 0;
}
