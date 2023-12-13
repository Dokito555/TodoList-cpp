#pragma once
#include "todo.h"

// Global Scope Access
using namespace std;

bool validateDate(string date) {
	string checkDay;
	string checkMonth;
	// Check format length
	if (date.length() > 10) {
		cout << "length above 10";
		return false;
	}
	for (int i = 0; i <= date.length(); i++) {
		if (i == 0) {
			checkDay += date[i];
		}
		if (i == 1) {
			checkDay += date[i];
		}
		if (i == 2) {
			if (date[i] != '/') { 
				cout << "wrong symbol at index 2: " << date[i] << endl;
				return false;
			};
		}
		if (i == 3) {
			checkMonth += date[i];
		}
		if (i == 4) {
			checkMonth += date[i];
		}
		if (i == 5) {
			if (date[i] != '/') {
				cout << "wrong symbol at index 5: " << date[i] << endl;
				return false;
			};
		}
	}
	if (stoi(checkDay) > 31 && stoi(checkMonth) <= 0) {
		cout << "wrong day format";
		return false;
	}
	if (stoi(checkMonth) > 12 && stoi(checkMonth) <= 0) {
		cout << "wrong month format";
		return false;
	}
	return true;
}