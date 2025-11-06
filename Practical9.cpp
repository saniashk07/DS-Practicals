#include <iostream> #include <string>
using namespace std; #define MAX 10 class Queue
{

string arr[MAX]; int front, rear;
public:

Queue()

{

front = 0;
 
rear = -1;

}

bool isFull()

{

return (rear == MAX - 1);

}

bool isEmpty()

{

return (front > rear);

}

void enqueue(string name)

{

if (isFull())

{

cout << "Queue is full. Cannot add more customers.\n";

}

else

{

rear++;

arr[rear] = name;

cout << name << " joined the line.\n";

}

}
 
void dequeue()

{

if (isEmpty())

{

cout << "No customers in line.\n";

}

else

{

cout << arr[front] << "'s order is ready. They leave the line.\n"; front++;
}

}

void display()

{

if (isEmpty())

{

cout << "The line is empty.\n";

} else {

cout << "Current Line: ";

for (int i = front; i <= rear; i++)

{

cout << arr[i];

if (i < rear) cout << " -> ";
 
}

cout << endl;

}

}

};

int main()

{

Queue q; int choice;
string name; do
{

cout << "\n--- Coffee Shop Queue Menu ---\n"; cout << "1. New Customer Arrival (Enqueue)\n"; cout << "2. Serve Customer (Dequeue)\n";
cout << "3. Show Queue\n"; cout << "4. Exit\n";
cout << "Choose an option: "; cin >> choice;
switch (choice)

{

case 1:

cout << "Enter customer name: ";
 
cin >> name; q.enqueue(name); break;
case 2:

q.dequeue(); break;
case 3:

q.display(); break;
case 4:

cout << "Exiting... Thank you!\n"; break;
default:

cout << "Invalid option. Try again.\n";

}

} while (choice != 4); return 0;
}

