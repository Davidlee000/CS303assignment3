#include <iostream>
#include "q.h"

using namespace std;

int main()
{
    queue q; // create a queue of integers
    int choice; // variable to store the user's choice
    int item; // variable to store the item to be pushed or popped
    bool exit = false; // variable to control the loop
    while (!exit) // loop until the user chooses to exit
    {
        cout << "Please choose one of the following options:\n"; // print the menu
        cout << "1. Push an item to the queue\n";
        cout << "2. Pop an item from the queue\n";
        cout << "3. Print the size of the queue\n";
        cout << "4. Print the front element of the queue\n";
        cout << "5. Exit the program\n";
        cin >> choice; // read the user's choice
        switch (choice) // execute the corresponding action
        {
        case 1: // push an item to the queue
            cout << "Enter the item to be pushed: ";
            cin >> item;
            q.push(item);
            cout << "The item " << item << " has been pushed to the queue\n";
            break;
        case 2: // pop an item from the queue
            if (q.empty()) // check if the queue is empty
            {
                cout << "The queue is empty, nothing to pop\n";
            }
            else // the queue is not empty
            {
                item = q.front(); // get the front element of the queue
                q.pop(); // pop the front element of the queue
                cout << "The item " << item << " has been popped from the queue\n";
            }
            break;
        case 3: // print the size of the queue
            cout << "The size of the queue is " << q.size() << endl;
            break;
        case 4: // print the front element of the queue
            if (q.empty()) // check if the queue is empty
            {
                cout << "The queue is empty, nothing to print\n";
            }
            else // the queue is not empty
            {
                cout << "The front element of the queue is " << q.front() << endl;
            }
            break;
        case 5: // exit the program
            cout << "Thank you for using the program. Goodbye!\n";
            exit = true; // set the exit flag to true
            break;
        default: // invalid choice
            cout << "Invalid choice, please try again\n";
            break;
        }
    }
    return 0;
}


