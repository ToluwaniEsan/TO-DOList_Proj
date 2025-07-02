//This is a simple C++ program that implements the use of dynamic arrays to create a TO-DO list.
//I implemented the use of vectors for easy management of tasks, allowing users to add, view, and remove tasks dynamically.
//I also made use of functions to organize the code and improve scaibility and readability.

#include<iostream>
#include<vector>
#include<string>

using namespace std;

void Menu() {
	cout << "TO-DO LIST MENU" << endl;
	cout << "1. Add a task" << endl;
	cout << "2. View all tasks" << endl;
	cout << "3. Remove a task" << endl;
	cout << "0. Exit" << endl;
	cout << "Enter your choice: ";

}

void dispTasks(const vector<string>& tasks) {
	if (tasks.empty()) {
		cout << "No tasks added yet." << endl;
		return;
	}

	cout << "\nTasks: " << endl;
	for (size_t i = 0; i < tasks.size(); ++i) {
		cout << i + 1 << ", " << tasks[i] << endl;
	}
}

int main() {
	vector<string> tasks;
	int choice;
	string task;

	do {
		Menu();
		cin >> choice;
		cin.ignore();

		switch (choice) {
		case 1:
			cout << "Enter task: ";
				getline(cin, task);
				tasks.push_back(task);
				cout << "Task Added" << endl;
				break;

		case 2:
			dispTasks(tasks);
			break;

		case 3:
			dispTasks(tasks);
			if (!tasks.empty()) {
				int index;
				cout << "Enter the task number you want to remove: ";
				cin >> index;
				cin.ignore();

				if (index >= 1 && index <= tasks.size()) {
					tasks.erase(tasks.begin() + index - 1);
					cout << "Task removed" << endl;
				}
				else {
					cout << "Invalid task number." << endl;
				}

			}
			break;

		case 0:
			cout << "Goodbye" << endl;
			break;

		default:
			cout << "Invalid choice. Try again." << endl;
		}

	} while (choice != 0);

	return 0;
}