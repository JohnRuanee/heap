#include "minHeap.h"

using namespace std;


void minHeap::siftUp(int pos){
    while ((pos / 2) > 0){
        int temp = heap[pos / 2];
        if (heap[pos] < temp){
            heap[pos / 2] = heap[pos];
            heap[pos] = temp;
        }
        pos = pos / 2;
    }
}

void minHeap::siftDown(int pos){
    int minLeaf;
    while ((pos * 2) <= heap.size()){
        if(pos * 2 + 1 > heap.size()){
            minLeaf = pos * 2;
        }else{
            if(heap[pos * 2] < heap[pos * 2 + 1]){
                minLeaf = pos * 2;
            }
            else{
                minLeaf = pos * 2 + 1;
            }
        }

        int temp = heap[pos];
        if (temp > heap[minLeaf]){   
            heap[pos] = heap[minLeaf];
            heap[minLeaf] = temp;
        }
        pos = minLeaf;
    }
}

minHeap::minHeap(vector<int> data){
    int pos = data.size() / 2;
    heap = data;
    while(pos > 0){
        siftDown(pos);
        pos = pos - 1;
    }
}

void minHeap::insert(int value){
    heap.push_back(value);
    siftUp(heap.size());
}

int minHeap::removeMin(){
    int temp = heap[1];
    heap[1] = heap[heap.size()];
    heap.pop_back();
    siftDown(1);
    return temp;
}