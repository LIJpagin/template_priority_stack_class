#include <iostream>
#include <ctime>
#include "PriorityStack.h"
using namespace std;

int main() {
	srand(unsigned(time(0)));
	PriorityStack <int> stack;
	string in;
	while (true) {
		while (in.empty()) {
			system("cls");
			cout << "Class template \"Priority stack\"\n";
			cout << " 1 - Fill the stack with random priorities and values\n";
			cout << " 2 - Add element\n";
			cout << " 3 - Extract the element with the highest priority\n";
			cout << " 4 - Extract element with minimum priority\n";
			cout << " 5 - Get stack element\n";
			cout << " 6 - Get elements of the same priority\n";
			cout << " 7 - Output the stack to the console\n";
			cout << " 8 - Clear the stack\n";
			cout << " 9 - Exit the program\n";
			cout << "\n > ";
			cin >> in;
			system("cls");
			int size, priority, data, index;
			switch (in[0]) {
			case '1':
				stack.clear();
				size = rand() % 10 + 1;
				cout << "Randomly generated values for priority and data:\n";
				for (auto i = 0; i < size; i++) {
					cout << " " << (priority = rand() % 5 + 1) << ", ";
					cout << (data = rand()) << endl;
					stack.push(priority, data);
				}
				cout << "\nOutput priority stack:\n";
				cout << stack << endl << endl;
				break;
			case '2':
				cout << "Enter the value to add the element (priority and value)\n";
				cin >> priority >> data;
				stack.push(priority, data);
				break;
			case '3':
				if (stack.isEmpty()) {
					cout << "Stack is empty";
					break;
				}
				cout << "Value extracted: " << stack.popMaxPriority() << endl;
				break;
			case '4':
				if (stack.isEmpty()) {
					cout << "Stack is empty";
					break;
				}
				cout << "Value extracted: " << stack.popMinPriority() << endl;
				break;
			case '5':
				if (stack.isEmpty()) {
					cout << "The stack is empty" << endl;
					break;
				}
				cout << "Enter the index: ";
				cin >> index;
				if (index < 0 || index > stack.size() - 1) {
					cout << "Going beyond the stack" << endl;
					break;
				}
				cout << (stack[index]) << endl;
				break;
			case '6':
				if (stack.isEmpty()) {
					cout << "Stack is empty";
					break;
				}
				cout << "Enter the priority: ";
				cin >> priority;
				cout << (stack(priority)) << endl;
				break;
			case '7':
				cout << stack << endl;
				break;
			case '8':
				stack.clear();
				cout << "Stack cleared" << endl;
			break;
			case '9':
				return 0;
			break;
			default:
				cout << "Something is wrong. . .\n Try again\n ";
				in.clear();
				break;
			}
			system("pause");
		}
		in.clear();
	}
}