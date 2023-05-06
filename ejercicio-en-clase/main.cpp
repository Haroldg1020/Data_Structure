#include "cola-prioridad.cpp"
int main(){
    Cola pq;
    cout << pq.vaciaCola() << endl; 
    pq.enqueue(6);
    cout << pq.front() << endl;
    pq.enqueue(5);
    cout << pq.front() << endl;
    pq.enqueue(10);
    cout << pq.front() << endl;
    pq.enqueue(3);
    cout << pq.front() << endl;
    pq.enqueue(11);
    cout << pq.front() << endl;
    cout<<"el tamano es: " << pq.size() << endl;
    pq.enqueue(0);
    cout<<"el tamano es: " << pq.size() << endl;
    cout << pq.front() << endl;
    pq.enqueue(5);
    pq.enqueue(5);
    pq.enqueue(5);
    pq.enqueue(5);
    while(not pq.vaciaCola()){
        cout << pq.front() << " ";
        pq.deque();
    }
}