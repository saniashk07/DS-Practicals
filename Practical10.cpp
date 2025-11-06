#include <iostream> #include <string>
using namespace std; class Circular
{

string a[10]; int front, rear;
const int max = 10;



public:

Circular()

{

front = -1;

rear = -1;

}



void insertJob(string val)

{
 
if ((rear + 1) % max == front)

{

cout << "You cannot insert new job, the spooler is full.\n"; return;
}

if (front == -1 && rear == -1)

{

front = rear = 0;

}

else

{

rear = (rear + 1) % max;

}

a[rear] = val;

cout << "Print job \"" << val << "\" added to the spooler.\n";

}



void deleteJob()

{

if (front == -1 && rear == -1)

{

cout << "The spooler is empty, cannot process any job.\n"; return;
 
}

cout << "Processing and removing print job \"" << a[front] << "\" from the spooler.\n"; if (front == rear)
{

front = rear = -1;

}

else

{

front = (front + 1) % max;

}

}

void display()

{

if (front == -1 && rear == -1)

{

cout << "Cannot display jobs because spooler is empty.\n"; return;
}

cout << "Current print jobs in spooler: ";



for (int i = front;; i = (i + 1) % max)

{

cout << a[i];
 
if (i == rear)

break; cout << " -> ";
}

cout << endl;

}

};

int main()

{

Circular q; int choice; string name; do
{

cout << "\n--- Printer Spooler Menu ---\n"; cout << "1. Add Print Job\n";
cout << "2. Process Print Job\n"; cout << "3. Show All Print Jobs\n"; cout << "4. Exit\n";
cout << "Choose an option: "; cin >> choice;
switch (choice)

{
 
case 1:

cout << "Enter Print Job name: "; cin >> name;
q.insertJob(name); break;
case 2:

q.deleteJob(); break;
case 3:

q.display(); break;
case 4:

cout << "Exiting... Thank you!\n"; break;
default:

cout << "Invalid option. Try again.\n";

}

}

while (choice != 4); return 0;
}

