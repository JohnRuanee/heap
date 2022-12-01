#include "minHeap.h"

using namespace std;

//parent equation
int minHeap::parentNode(int pos){
    return (pos - 1) / 2;
}
//left child equation
int minHeap::leftNode(int pos){
    return (pos * 2) + 1;
}
//right child equation
int minHeap::rightNode(int pos){
    return (pos * 2) + 2;
}

//sift up operation
void minHeap::siftUp(int pos){
    //parent var
    int parent = parentNode(pos);

    //if parent is greater than pos swap and recursive with parent
    if(heap[parent] > heap[pos]){
        swap(heap[pos], heap[parent]);
        siftUp(parent);
    }
}

//sift down operation
void minHeap::siftDown(int pos){
    //size left and right vars
    int size = heap.size();
    int left = leftNode(pos);
    int right = rightNode(pos);
    
    //set min to pos
    int min = pos;

    //if pos is greater than left child and left is less than size set min to left
    if((heap[pos] > heap[left]) && (left < size)){
        min = left;
    }
    
    //if right is less than size and min is greater than right set min to right
    if((right < size) && (heap[min] > heap[right])){
        min = right;
    }

    //if min isnt pos swap min and pos and sift down with min
    if(min != pos){
        swap(heap[pos], heap[min]);
        siftDown(min);
    }
}

//constructor takes data and puts it into a minheap
minHeap::minHeap(vector<int> data){
    //set heap to data
    heap = data;
    //sort heap by sifting down each member
    for(int pos = ((heap.size() / 2) - 1); pos >= 0; pos--){
        siftDown(pos);
    }
}

//insert function
void minHeap::insert(int value){
    //add value to end of the heap and sift it up
    heap.push_back(value);
    siftUp(heap.size() - 1);
}

int minHeap::removeMin(){
    //set temp to top of heap
    int temp = heap[0];
    //set top of heap to last member, delete last member and sift down 
    heap[0] = heap.back();
    heap.pop_back();
    siftDown(0);
    //return temp
    return temp;
}