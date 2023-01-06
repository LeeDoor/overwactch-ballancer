#pragma once
#include "Roles.h"
struct Role
{
public:
	int rank;
	int playHours; 
	int priority;
	bool primary;
	bool isActive; 
	bool secondary; 
	Roles type;
};

