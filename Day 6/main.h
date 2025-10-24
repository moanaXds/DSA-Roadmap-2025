#include<iostream>

using namespace std;



class Customer {
private:
	string ticketno;
	string gender;

public:
	Customer()
	{

	}

	Customer(string ticketno, string gender)
	{
		this->ticketno = ticketno;
		this->gender = gender;
	}

	void Display()
	{
		cout << "THE CUSTOMERS DATA :\n";
		cout << ticketno << endl;
		cout << gender << endl;
	}
};





class Queue {
private:
	int front;
	int rear;
	Customer* arr;
	int size;

public:
	Queue(int size = 10)
	{
		front = -1;
		rear = -1;
		this->size = size;
		arr = new Customer[size];
	}

	void enqueue(Customer C1)
	{
		if (rear == size - 1)
		{
			cout << "No space for customer ";
			return;
		}

		if (front == -1 && rear == -1)
		{
			front = 0;
			rear = 0;
			arr[rear++] = C1;
		}
		else
		{
			rear++;
			arr[rear] = C1;
		}
	}

	void dequeue()
	{
		if (front == -1 && rear == -1)return;

		if (front == rear)
		{
			front = -1;
			rear = -1;
			return;
		}

		else
		{
			front++;
		}
	}

	void display()
	{
		if (front == -1)
		{
			cout << "EMPTY\n";

		}
		else
		{
			for (int i = front; i <= rear; i++)
			{
				arr[i].Display();
			}
		}
	}
};



class Cashiers
{
private:
	int id;
	string gendertype;

public:
	Cashiers()
	{
	}
	Cashiers(int id, string gendertype)
	{
		this->id = id;
		this->gendertype = gendertype;
	}
	void Display()
	{
		cout << "THE CASHIERS DATA :\n";
		cout << id << endl << gendertype << endl;

	}
};

class Bank {
	Queue q1;
	Cashiers c1;
	Cashiers c2;

public:
	Bank()
	{
		q1 = Queue(10);
		c1 = Cashiers(10, "male");
		c2 = Cashiers(11, "female");
	}

	void add_New_Customer(string ticketno, string gender)
	{
		Customer other(ticketno, gender);
		q1.enqueue(other);
	}

	void remove_customer()
	{
		q1.dequeue();
	}

	void DisplayQueue()
	{
		q1.display();
	}
};

#pragma once
