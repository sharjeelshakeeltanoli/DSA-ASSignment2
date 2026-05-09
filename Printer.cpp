#include <iostream>
#include "Printer.h"


Printer::Printer(int maxsize)
{
	front = 0;
	rear = 0;
	count = 0;
	capacity = maxsize;
	JobId = new int[capacity];
	Pages = new int[capacity];
}

Printer::~Printer()
{
	delete[] JobId;
	delete[] Pages;
}

bool Printer::isEmpty()
{
	return (count == 0);
}

bool Printer::isFull()
{
	return (count == capacity);
}

void Printer::Enqueue(int job_id,int page)
{
	if (isFull())
	{
		cout << "Queue is full";
		return;
	}
	JobId[rear] = job_id;
	Pages[rear] = page;
	rear = (rear + 1) % capacity;
	count++;
}



void Printer::Dequeue(int& jobid, int& pages)
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    jobid = JobId[front];
    pages = Pages[front];
    cout << "Printing Job ID: " << jobid << ", Pages: " << pages << endl;
    front = (front + 1) % capacity;
    count--;
}

void Printer::peek()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Next Job ID: " << JobId[front] << ", Pages: " << Pages[front] << endl;
}

void Printer::display()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Pending Print Jobs:" << endl;
    for (int i = 0; i < count; ++i)
    {
        int x = (front + i) % capacity;
        cout << "Job ID: " << JobId[x] << ", Pages: " << Pages[x] << endl;
    }
}

void Printer::totalPages()
{
    int total = 0;
    for (int i = 0; i < count; ++i)
    {
        int x = (front + i) % capacity;
        total += Pages[x];
    }
    cout << "Total pending pages: " << total << endl;
}



