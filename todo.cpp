#include <iostream>
#include "common.h"

// Storage for todo
Todo TodoList[100];

// Add Todo to Todolist array
string addTodo(Todo todo) {
	// Check if currentSize is below array capacity
	if (currentSize < 101) {
		TodoList[currentSize] = todo;
		currentSize++;
		return "Added Todo";
	}
	// Error Handling: 
	// check if currentSize above array capacity
	// return message when triggered
	else {
		return "Todo Exceeded Maximum Array Capacity, Couldn't Add Data";
	}
}

// Print out Todos from inside the TodoList array
void readTodo() {
	// Check if currentSize is below array capacity
	if (currentSize < 101) {
		// Print out todos
		// Format Example: 1. Doing Something > Not Done 
		for (int i = 0; i <= currentSize; i++) {
			cout << TodoList[i].id;
			cout << ". ";
			cout << TodoList[i].title;
			cout << " > ";
			// Check isDone status: 
			// true -> [✓] = Done, 
			// false -> [] = Not Done
			if (TodoList[i].isDone) {
				cout << "Done" << endl;
			}
			else {
				cout << "Not Done" << endl;
			}
			cout << endl;
		}
	}
	// Error Handling: 
	// check if currentSize above array capacity
	// return message when triggered
	else {
		cout << "Todo Exceeded Maximum Array Capacity, Couldn't Read Todo" << endl;
	}
}

// Print out specific Todo from Todolist array by Id
// index as id paramater
void readTodoFromId(int index) {
	// Check if currentSize is below array capacity
	if (currentSize < 101) {
		// Print out specific todo
		for (int i = 0; i <= currentSize; i++) {
			if (TodoList[i].id == index) {
				cout << TodoList[i].id << ". ";
				cout << TodoList[i].title << endl;
				cout << "description: " << endl;
				cout << TodoList[i].desc << endl;
				cout << "status: ";
				// Check isDone status: 
				// true -> [✓] = Done, 
				// false -> [] = Not Done
				if (TodoList[i].isDone) {
					cout << "Done";
				}
				else {
					cout << "Not Done" << endl;
				}
			}
		}
	}
	// Error Handling: 
	// check if currentSize above array capacity
	// return message when triggered
	else {
		cout << "Todo Exceeded Maximum array capacity, Couldn't Read Todo" << endl;
	}
}

// Update Todo Title
string updateTodoTitle(int index, string newTitle) {
	// Check if currentSize is below array capacity
	if (currentSize < 101) {
		// Check if index is below currentSize
		if (index <= currentSize) {
			for (int i = 0; i <= currentSize; i++) {
				if (TodoList[i].id == index) {
					TodoList[i].title == newTitle;
				}
			}
		}
		// Error Handling: 
		// check if index above array capacity
		// return message when triggered
		else {
			return "id parameter above the current Todolist index, Couldn't Update Todo";
		}
	}
	// Error Handling: 
	// check if currentSize above array capacity
	// return message when triggered
	else {
		return "Todo Exceeded Maximum array capacity, Couldn't Update Todo";
	}
}

// Update Todo Description
string updateTodoDescription(int index, string newDesc) {
	// Check if currentSize is below array capacity
	if (currentSize < 101) {
		// Check if index is below currentSize
		if (index <= currentSize) {
			for (int i = 0; i <= currentSize; i++) {
				if (TodoList[i].id == index) {
					TodoList[i].title == newDesc;
				}
			}
		}
		// Error Handling: 
		// check if index above array capacity
		// return message when triggered
		else {
			return "id parameter above the current Todolist index, Couldn't Update Todo";
		}
	}
	// Error Handling: 
	// check if currentSize above array capacity
	// return message when triggered
	else {
		return "Todo Exceeded Maximum array capacity, Couldn't Update Todo";
	}
}

// Toggle Todo IsDone Status
bool toggleTodo(int index) {
	// Check if currentSize is below array capacity
	if (currentSize < 101) {
		// Check if index is below currentSize
		if (index <= currentSize) {
			for (int i = 0; i <= currentSize; i++) {
				if (TodoList[i].id == index) {
					// Toggle IsDone
					!TodoList[i].isDone;
				}
			}
		}
		// Error Handling: 
		// check if index above array capacity
		// return message when triggered
		else {
			return "id parameter above the current Todolist index, Couldn't Update Todo";
		}
	}
	// Error Handling: 
	// check if currentSize above array capacity
	// return message when triggered
	else {
		return "Todo Exceeded Maximum array capacity, Couldn't Update Todo";
	}
}

// Delete Todo from Todolist array by Id
// index as id paramater
bool deleteTodo(int index) {
	// Check if currentSize is below array capacity and index number below currentSize
	if (currentSize < 101) {
		// Check if index is below currentSize
		if (index <= currentSize) {
			for (int i = 0; i <= currentSize; i++) {
				if (TodoList[i].id == index) {
					// Temporary: Change the deleted Todo to an empty element
					// TODO: Fix this from empty element to actually delete the element and shift the remaining ones
					TodoList[i] = {};
					return true;
				}
			}
		}
		// Error Handling: 
		// check if index above array capacity
		// return message when triggered
		else {
			cout << "id parameter above the current Todolist index, Couldn't Update Todo" << endl;
		}
	}
	// Error Handling: 
	// check if currentSize above array capacity
	// return message when triggered
	else {
		cout << "Todo Exceeded Maximum array capacity or Id above current array size, Couldn't Delete Todo" << endl;
		return false;
	}
}

int main() {
	int opt;
	Todo todo;
	string status, exitOpt;
	do {
		cout << "WELCOME TO TODO LIST" << endl;
		cout << endl;
		cout << "1. Insert Todo" << endl;
		cout << "2. Read Todo" << endl;
		cout << "3. Read Todo From Id" << endl;
		cout << "3. Update Todo" << endl;
		cout << "4. Delete Todo" << endl;
		cout << "9. Exit" << endl;
		cin >> opt;
		switch (opt)
		{
		case 1:
			cout << "INSERT YOUR TODO" << endl;
			cout << endl;
			cout << "Insert Todo Title: ";
			/*getline(cin, todo.title);*/
			cin >> todo.title;
			cout << endl;
			cout << "Insert Todo Description: ";
			/*getline(cin, todo.desc);*/
			cin >> todo.desc;
			cout << endl;
			cout << "Is it done yet? y/n: ";
			status = "";
			cin >> status;
			if (status != "y" && status != "n") {
				cout << "Wrong Answer format please try again" << endl;
				return 0;
			}
			if (status == "y") {
				todo.isDone = true;
			}
			if (status == "n") {
				todo.isDone = false;
			}
			addTodo(todo);
			break;
		case 2:
			cout << "READ TODO" << endl;
			cout << endl;
			readTodo();
			cout << "Would you like to exit? y/n: ";
			exitOpt = "";
			cin >> status;
			if (exitOpt != "y" && exitOpt != "n") {
				cout << "Couldn't Read Option, Automatically exit..." << endl;
				break;
			}
			if (exitOpt == "y") {
				cout << "Proceed to exit" << endl;
				break;
			}
			if (exitOpt == "n") {
				cout << "On stand by" << endl;
				break;
			}
		case 3:
			int id;

			cout << "READ TODO FROM ID" << endl;
			cout << endl;
			cout << "which id?" << endl;
			cin >> id;
			readTodoFromId(id);
			cout << "Would you like to exit? 1/0: ";
			cin >> exitOpt;
			if (exitOpt != "y" && exitOpt != "n") {
				cout << "Couldn't Read Option, Automatically exit..." << endl;
				break;
			}
			if (exitOpt == "y") {
				cout << "Proceed to exit" << endl;
				break;
			}
			if (exitOpt == "n") {
				cout << "On stand by" << endl;
				break;
			}
		case 4:

		case 9:
			cout << "EXIT, Goodbye" << endl;
			return 0;
		default:
			break;
		}
	} while (opt != 9);
	return 0;
}
