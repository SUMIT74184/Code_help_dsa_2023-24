#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
//implementing the heap data structure

class Heap{
    public:
    int *arr;
    int size;
    int capacity;

    Heap(int capacity){
        this->capacity=capacity;
       this->arr=new int[capacity];
       this->size=0;
    } 
//time complexity of insertion is O(log n)
    void insert(int val){
        if(size==capacity){
            cout<<"heap overflow"<<endl;
            return;
        }
        
        //size will gonna increase
        size++;
        int index=size;
        arr[index]=val;


    while(index>1){
        //implementing the min heap
        int parentIndex=index/2;
        if(arr[index]>arr[parentIndex]){//if the parent node is larger than chiled
            swap(arr[index],arr[parentIndex]);//we will swap
            index=parentIndex;//updating the new parentindex
        }else{
            break;
        }
    }
    }

    int deletion(){
        int answer=arr[1];
        //replacement
        arr[1]=arr[size];
        //last element should be deleted and placed on the root node
        size--;//from the entire we are deleting one
        
        int index=1;
        while(index<size){
            int leftIndex=2*index;
            int rightIndex=2*index+1;

            //find out the largest element 
            int largestIndex=index;

            //check the left child
            if(leftIndex<=size && arr[largestIndex]<arr[leftIndex]){
                largestIndex=leftIndex;
            }
            if(rightIndex<=size && arr[largestIndex]<arr[rightIndex]){
                largestIndex=rightIndex;
            }

            //no change is noticed then
            if(index==largestIndex){
                break;
            }
            else{
                swap(arr[index],arr[largestIndex]);
                index=largestIndex;
            }
        }

        return answer;
    }

    void print(){
        for(int i=1;i<=size;i++){
        cout<<arr[i]<<" ";
    }
    }
};

//time complexity is O(log n)

    void heapify(int *arr,int n,int index){
        int leftIndex=2*index;
        int rightIndex=2*index+1;
        int largestIndex=index;

        //3 mein se maximum lekar aayo
        if(leftIndex<=n && arr[leftIndex]>arr[largestIndex]){
            largestIndex=leftIndex;
//these two condition are used to find the largest numberindex 
        }
        if(rightIndex<=n && arr[rightIndex]>arr[largestIndex]){
            largestIndex=rightIndex;
        }
        //we will get our largest index then we will check again
        if(index!=largestIndex){
            swap(arr[index],arr[largestIndex]);
            index=largestIndex;
            heapify(arr,n,index);//recursive call
        }
    }
    void buidHeap(int arr[],int n){
        for(int index=n/2;index>0;index-- ){
            heapify(arr,n,index);
        }
    }

    void HeapSort(int arr[],int n){
        while(n!=1){
            swap(arr[1],arr[n]);//array is started from 1 that's why n
            n--;//size is reduced by 1 everytime
            heapify(arr,n,1);//calling that particular function

        }
    }

int main(){
    Heap h(20);//making the object and allocating the size
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(11);
    h.insert(6);

    cout<<"printing the content of Heap"<<endl;
    h.print();

    int ans=h.deletion();cout<<endl;
    cout<<"answer of the deleted heap is :"<<ans<<endl;
    cout<<"printing the new val of heaps"<<endl;
    h.print();


    return 0;
}