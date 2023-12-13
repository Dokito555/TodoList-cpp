#pragma once
#include <string>

static int currentSize = 1;

struct Todo {
	int id;
	std::string title;
	std::string desc;
	std::string dueDate;
	bool isDone;
};

