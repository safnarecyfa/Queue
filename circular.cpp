#include <iostream>
using namespace std;

#define AKBAR 10

#define MAX 10

struct queue
{
    int elemen[MAX];
    int front;
    int rear;
};

queue q;

void buatqueue();
void enqueue(int IB);
void dequeue();
bool isEmpty();
bool isFull();
void cetak();

int main (){
    buatqueue();
    enqueue(12);
    enqueue(15);
    enqueue(18);
    enqueue(20);
    enqueue(25);
    enqueue(36);
    enqueue(79);
    cetak();
    dequeue();
    dequeue();
    cetak();
    enqueue(5);
    enqueue(8);
    cetak();

}

void buatqueue(){
    q.front = -1;
    q.rear = -1;
}

bool isEmpty(){
    if (q.front == -1) {
        return true;
    } else {
        return false;
    }
}

bool isFull(){
    if ((q.rear + 1) % MAX == q.front) {
        return true;
    } else {
        return false;
    }
}

void enqueue(int IB){
    if (isFull())
    {
        cout << "queue penuh" << endl;
    } else {
        if (isEmpty())
        {
            q.front = 0;
            q.rear = 0;
            q.elemen[q.rear] = IB;
        } else {
            q.rear = (q.rear + 1) % MAX;
            q.elemen[q.rear] = IB ;
        }
    }
}

void dequeue(){
    if (isFull())
    {
        cout << "queue penuh" << endl;
    } else {
        if (isEmpty())
        {
            cout << "queue kosong" << endl;
        } else {
            q.front = (q.front + 1) % MAX;
        }
    }
}

void cetak(){
    if (isEmpty())
    {
        cout << "queue kosong" << endl;
    } else {
        int i = q.front;
        while (i != q.rear)
        {
            cout << i << "-" << q.elemen[i] << endl;
            i = (i+1)%MAX;
        }
        cout << endl << endl;
    }
    
}
