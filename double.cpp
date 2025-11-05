#include <iostream>
using namespace std;

struct node
{
    int info;
    node *next;
    node *prev; 
};

node *nb, *front, *rear, *temp, *hapus;

void buatqueue();
void enqueueD(int IB);
void enqueueB(int IB);
void dequeueD();
void dequeueB();
bool isEmpty();
void cetak();

int main(){
    buatqueue();
    cout << "enqueue depan" << endl;
    enqueueD(20);
    enqueueD(50);
    cetak();
    cout << "enqueue belakang" << endl;
    enqueueB(79);
    enqueueB(52);
    cetak();
    cout << "dequeue depan" << endl;
    dequeueD();
    cetak();
    cout << "dequeue belakang" << endl;
    dequeueB();
    cetak();

}

void buatqueue(){
    front = NULL;
    rear = NULL;
}

bool isEmpty(){
    if (front == NULL)
    {
        return true;
    } else {
        return false;
    }
}

void enqueueD(int IB){
    nb = new node();
    nb->info = IB;
    nb->next = NULL;
    nb->prev = NULL;

    if (isEmpty())
    {   
        front = nb;
        rear = nb;
    } else {
        nb->next = front;
        front->prev = nb;
        front = nb;
    }
}

void enqueueB(int IB){
    nb = new node();
    nb->info = IB;
    nb->next = NULL;
    nb->prev = NULL;

    if (isEmpty()) {   
        front = nb;
        rear = nb;
    } else {
        nb->prev = rear;
        rear->next = nb;
        rear = nb;
    }
}

void dequeueD(){
    if (isEmpty())
    {
        cout << "queue masih kosong" << endl;
    } else {
        if (front == rear)
        {
            buatqueue();
        } else {
            hapus = front;
            front = front->next;
            front -> prev = NULL;
            delete hapus; 
        }
    }
    
}

void dequeueB(){
    if (isEmpty()) {
        cout << "queue masih kosong" << endl;
    } else {
        if (front == rear)
        {
            buatqueue();
        } else {
            hapus = rear;
            rear = rear->prev;
            rear -> next = NULL;
            delete hapus; 
        }
    }
}

void cetak(){
    if (isEmpty())
    {
        cout << "queue kosong" << endl;
    } else {
        temp = front;
        while (temp != NULL)
        {
            cout << temp->info << " ";
            temp = temp-> next;
        }
        cout << endl << endl;;
    }
}


