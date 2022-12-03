#pragma once

// описание одной роли
class Role
{
public:
	int rank; // ранг
	int playhours; // колво часов
	char priority; // приоритет роли
	bool isActive; // активный ли
	bool primary; // первый чекбокс
	bool secondary; // второй чекбокс
};

