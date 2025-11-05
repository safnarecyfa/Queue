#include <iostream>
using namespace std;

struct node{
    int info;
    node *next;
};

node *front = NULL, *rear=NULL, *nb;

bool isEmpty() {
    if (front == NULL) {
        return true;
    } else {
        return false;
    }
}

void enqueue(int value){
    nb = new node();
    nb->info = value;
    nb-> next = NULL;

    if (isEmpty()) {
        front=nb;
        rear=nb;
    } else{
        rear->next=nb;
        rear=nb;
    }
    cout << "value " << value << " berhasil masuk" << endl;
}

void dequeue(){
    if (isEmpty()) {
        cout << "queue kosong" << endl;
    } else{
        if (front == rear)
        {
            front = NULL;
            rear = NULL;
        } else {
            node *temp = front;
            cout << front->info << " keluar dari queue" << endl;
            front = front->next;
            delete temp;
        }
    }
}

void display (){
    if (isEmpty()) {
        cout << "queue kosong" << endl;
    } else {
        node *temp = front;
        cout << "isi queue : ";
        while (temp != NULL) {
            cout << temp -> info << " ";
            temp = temp->next;
        }
        cout << endl << endl;
    }
}

int main (){
    enqueue (10);
    enqueue (23);
    enqueue (9);
    enqueue (45);
    enqueue (39);
    display();

    dequeue();
    dequeue();
    display();
}

