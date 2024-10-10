#include <iostream>

using namespace std;
const int MAX = 100;

class Queue
{
private:
    int queue[MAX];
    int front, rear, size;

public:
    Queue() : front(0), rear(0), size(0) {}

    void enqueue(int customer_id)
    {
        if (size == MAX)
        {
            cout << "Queue is full." << endl;
            return;
        }

        queue[rear] = customer_id;
        rear = (rear + 1) % MAX;
        size++;
        cout << "Customer with customer_ID \"" << customer_id << "\" added to the queue...!" << endl;
    }

    void dequeue()
    {
        if (size == 0)
        {
            cout << "Queue is empty." << endl;
            return;
        }

        int customer_id = queue[front];
        front = (front + 1) % MAX;
        size--;
        cout << "Customer with customer_ID \"" << customer_id << "\" checked out." << endl;
    }

    void display_queue()
    {
        if (size == 0)
        {
            cout << "Queue is Empty...!" << endl;
            return;
        }
        cout << "Current Queue: ";
        int temp = front;
        for (int i = 0; i < size; i++)
        {
            cout << queue[temp] << " ";
            temp = (temp + 1) % MAX;
        }
        cout << "\n--------------------------------------------" << endl;
    }

    bool is_empty()
    {
        return (size == 0);
    }
};

int main()
{
    Queue checkout_queue;

    int customer_ids[] = {13, 7, 4, 1, 6, 8, 10};
    int number_of_customers = sizeof(customer_ids) / sizeof(customer_ids[0]);

    for (int i = 0; i < number_of_customers; i++)
    {
        checkout_queue.enqueue(customer_ids[i]);
    }

    checkout_queue.display_queue();
    // cout << "_____________________________" << endl;

    while (!checkout_queue.is_empty())
    {
        checkout_queue.dequeue();
        checkout_queue.display_queue();
    }

    return 0;
}