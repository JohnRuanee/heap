#include "minHeap.h"

using namespace std;

int minHeap::parentNode(int pos){
    return (pos - 1) / 2;
}

int minHeap::leftNode(int pos){
    return (pos * 2) + 1;
}

int minHeap::rightNode(int pos){
    return (pos * 2) + 2;
}


void minHeap::siftUp(int pos){
    if(pos == 0)
        return;
    int parent = parentNode(pos);
    if(heap[parent] > heap[pos]){
        int temp = heap[pos];
        heap[parent] = heap[pos];
        heap[pos] = temp;
        siftUp(parent);
    }
}

void minHeap::siftDown(int pos){
    int size = heap.size();
    int left = leftNode(pos);
    int right = rightNode(pos);

    if(left >= size)
        return;
    
    int min = pos;

    if(heap[pos] > heap[left]){
        min = left;
    }
    
    if((right < size) && (heap[min] > heap[right])){
        min = right;
    }

    if(min != pos){
        int temp = heap[pos];
        heap[pos] = heap[min];
        heap[min] = temp;
        siftDown(min);
    }
}

minHeap::minHeap(vector<int> data){
    for(int pos:data){
        insert(pos);
    }
}

void minHeap::insert(int value){
    heap.push_back(value);
    siftUp(heap.size() - 1);
}

int minHeap::removeMin(){
    int temp = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    siftDown(0);
    return temp;
}