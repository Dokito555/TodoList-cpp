#include <iostream>
#include "common.h"

// Storage for todos
Todo TodoList[100];

// Add Todo to Todolist array
string addTodo(Todo todo) {
	// Check if currentSize is below array capacity
	if (currentSize < 101) {
		TodoList[currentSize] = todo;
		// Add current array size
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
		for (int i = 1; i < currentSize; i++) {
			// Check empty array element
			if (TodoList[i].id == 0) {
				continue;
			}
			cout << TodoList[i].id;
			cout << ". ";
			cout << TodoList[i].title;
			cout << " > ";
			// Check isDone status: 
			// true -> [✓] = Done, 
			// false -> [] = Not Done
			if (TodoList[i].isDone) {
				cout << "DONE";
			}
			else {
				cout << "NOT DONE";
			}
			cout << " > ";
			cout << TodoList[i].dueDate;
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
		if (index <= currentSize && index > 0) {
			// Print out specific todo
			for (int i = 1; i < currentSize; i++) {
				if (TodoList[i].id == index) {
					cout << TodoList[i].id << ". ";
					cout << TodoList[i].title << endl;
					cout << endl;
					cout << "description: " << endl;
					cout << TodoList[i].desc << endl;
					cout << endl;
					cout << "Due Date: " << endl;
					cout << TodoList[i].dueDate << endl;
					cout << endl;
					cout << "status: ";
					// Check isDone status: 
					// true -> [✓] = Done, 
					// false -> [] = Not Done
					if (TodoList[i].isDone) {
						cout << "[✓]";
					}
					else {
						cout << "[]" << endl;
					}
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

// Print out specific Todo from Todolist array by Date
void readTodoFromDate(string date) {
	if (currentSize < 101) {
		if (validateDate(date)) {
			for (int i = 1; i <= currentSize; i++) {
				if (TodoList[i].dueDate == date) {
					cout << TodoList[i].id << ". ";
					cout << TodoList[i].title << endl;
					cout << endl;
					cout << "description: " << endl;
					cout << TodoList[i].desc << endl;
					cout << endl;
					cout << "Due Date: " << endl;
					cout << TodoList[i].dueDate << endl;
					cout << endl;
					cout << "status: ";
					// Check isDone status: 
					// true -> [✓] = Done, 
					// false -> [] = Not Done
					if (TodoList[i].isDone) {
						cout << "[✓]";
					}
					else {
						cout << "[]" << endl;
					}
				}
			}
		}
		else {
			cout << "Wrong date format please try again.." << endl;
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
		if (index <= currentSize && index > 0) {
			for (int i = 1; i < currentSize; i++) {
				if (TodoList[i].id == index) {
					TodoList[i].title = newTitle;
					return "updated!";
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
		if (index <= currentSize && index > 0) {
			for (int i = 1; i < currentSize; i++) {
				if (TodoList[i].id == index) {
					TodoList[i].desc = newDesc;
					return "updated!";
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

// Update Todo Due Date
string updateTodoDueDate(int index, string newDate) {
	// Check if currentSize is below array capacity
	if (currentSize < 101) {
		// Check if index is below currentSize
		if (index <= currentSize && index > 0) {
			for (int i = 1; i < currentSize; i++) {
				if (TodoList[i].id == index) {
					TodoList[i].dueDate = newDate;
					return "updated!";
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
string toggleTodo(int index) {
	// Check if currentSize is below array capacity
	if (currentSize < 101) {
		// Check if index is below currentSize
		if (index <= currentSize && index > 0) {
			for (int i = 1; i < currentSize; i++) {
				if (TodoList[i].id == index) {
					// Toggle IsDone
					TodoList[i].isDone = !TodoList[i].isDone;
					return "status toggled!";
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
string deleteTodo(int index) {
	// Check if currentSize is below array capacity and index number below currentSize
	if (currentSize < 101) {
		// Check if index is below currentSize
		if (index <= currentSize && index > 0) {
			for (int i = 1; i < currentSize; i++) {
				if (TodoList[i].id == index) {
					// Temporary: Change the deleted Todo to an empty element
					// TODO: Fix this from empty element to actually delete the element and shift the remaining ones
					TodoList[i] = {};
					return "Todo Deleted";
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
		return "Todo Exceeded Maximum array capacity, Couldn't Delete Todo";
	}
}

int main() {
	int opt;
	Todo todo;
	string status, exitOpt, dateArg;
	do {
		cout << "WELCOME TO TODO LIST" << endl;
		cout << endl;
		cout << "1. Insert Todo" << endl;
		cout << "2. Read Todo" << endl;
		cout << "3. Read Todo From Id" << endl;
		cout << "4. Read Todo From Date" << endl;
		cout << "5. Update Todo" << endl;
		cout << "6. Delete Todo" << endl;
		cout << "9. Exit" << endl;
		cout << "Pick your option: ";
		cin >> opt;
		cout << endl;
		switch (opt)
		{
		case 1:
			// Initiate Insert Todo to Todolist array
			// Input Todo class instance as argument
			cout << "INSERT YOUR TODO" << endl;
			cout << endl;
			cout << "Insert Todo Title: ";

			cin.get();
			getline(cin, todo.title);
			cout << endl;
			cout << "Insert Todo Description: " << endl;
			getline(cin, todo.desc);
			cout << endl;
			cout << "Insert Your Todo Due Date in DD/MM/YYYY format: ";
			cin >> todo.dueDate;
			// Check date format
			if (!validateDate(todo.dueDate)) {
				cout << "Wrong date format please try again.." << endl;
				cout << endl;
				break;
			}
			cout << endl;
			cout << "Is it done yet? [Y/N]: ";
			status = "";
			cin >> status;
			if (status != "y" && status != "n" && status != "Y" && status != "N") {
				cout << "Wrong Answer format please try again" << endl;
				return 0;
			}
			if (status == "y" || status == "Y") {
				todo.isDone = true;
			}
			if (status == "n" || status == "N") {
				todo.isDone = false;
			}
			todo.id = currentSize;
			cout << addTodo(todo);
			cout << endl;
			break;
		case 2:
			// Initiate read Todo from Todolist array
			cout << "READ TODO" << endl;
			cout << endl;
			readTodo();
			cout << endl;
			cout << "Would you like to exit? [Y/N]: ";
			exitOpt = "";
			cin >> status;
			if (exitOpt != "y" && exitOpt != "n" && exitOpt != "Y" && exitOpt != "N") {
				cout << "Couldn't Read Option, Automatically exit..." << endl;
				break;
			}
			if (exitOpt == "y" || exitOpt == "Y") {
				cout << "Proceed to exit" << endl;
				cout << endl;
				break;
			}
			if (exitOpt == "n" || exitOpt == "N") {
				cout << "On stand by" << endl;
				cout << endl;
			}
		case 3:
			// Initiate Read Todo from id
			// Input id as argument
			int readId;

			cout << "READ TODO FROM ID" << endl;
			cout << endl;
			cout << "Which id?: ";
			cin >> readId;
			cout << endl;
			readTodoFromId(readId);
			cout << "Would you like to exit? [Y/N]: ";
			cin >> exitOpt;
			if (exitOpt != "y" && exitOpt != "n" && exitOpt != "Y" && exitOpt != "N") {
				cout << "Couldn't Read Option, Automatically exit..." << endl;
				break;
			}
			if (exitOpt == "y" || exitOpt == "Y") {
				cout << "Proceed to exit" << endl;
				cout << endl;
				break;
			}
			if (exitOpt == "n" || exitOpt == "N") {
				cout << "On stand by" << endl;
				cout << endl;
			}
		case 4:
			// Initiate Read Todo By Date
			cout << "READ TODO FROM DATE" << endl;
			cout << endl;
			cout << "Which Date?: ";
			cin >> dateArg;
			cout << endl;
			readTodoFromDate(dateArg);
			cout << "Would you like to exit? [Y/N]: ";
			cin >> exitOpt;
			if (exitOpt != "y" && exitOpt != "n" && exitOpt != "Y" && exitOpt != "N") {
				cout << "Couldn't Read Option, Automatically exit..." << endl;
				break;
			}
			if (exitOpt == "y" || exitOpt == "Y") {
				cout << "Proceed to exit" << endl;
				cout << endl;
				break;
			}
			if (exitOpt == "n" || exitOpt == "N") {
				cout << "On stand by" << endl;
				cout << endl;
			}
		case 5:
			// Initiate update Todo
			int updateId, updateOpt;
			cout << "UPDATE TODO" << endl;
			cout << endl;
			cout << "Which id?: ";
			cin >> updateId;
			cout << endl;
			cout << "What do you want to update?" << endl;
			cout << "1. Title" << endl;
			cout << "2. Description" << endl;
			cout << "3. Due Date" << endl;
			cout << "4. Status" << endl;
			cout << "9. Exit" << endl;
			cout << "Your option: ";
			cin >> updateOpt;
			cout << endl;
			switch (updateOpt)
			{
			case 1:
				cout << "Write your new title: ";
				cin.get();
				getline(cin, todo.title);
				cout << updateTodoTitle(updateId, todo.title);
				cout << endl;
				break;
			case 2:
				cout << "Write your new description: ";
				cin.get();
				getline(cin, todo.desc);
				cout << updateTodoDescription(updateId, todo.desc);
				cout << endl;
				break;
			case 3:
				cout << "Write your new Due Date: ";
				cin.get();
				getline(cin, todo.dueDate);
				cout << updateTodoDueDate(updateId, todo.dueDate);
				cout << endl;
				break;
			case 4:
				cout << toggleTodo(updateId);
				cout << endl;
				break;
			case 9:
				cout << "EXIT, Goodbye" << endl;
				break;
			default:
				break;
			}
			break;
		case 6:
			int deleteID;

			cout << "DELETE TODO" << endl;
			cout << endl;
			cout << "Which id?: ";
			cin >> deleteID;
			cout << endl;
			cout << deleteTodo(deleteID) << endl;
			break;
		case 9:
			cout << "EXIT, Goodbye" << endl;
			return 0;
		default:
			break;
		}
	} while (opt != 9);
	return 0;
}
