#pragma once
#include <string>

static int currentSize = 0;

struct Todo {
	int id;
	std::string title;
	std::string desc;
	bool isDone;
};

