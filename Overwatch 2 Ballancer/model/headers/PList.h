#pragma once
#include <memory>
#include <functional>
#include <vector>
#include <algorithm>
#include "Team.h"
#include "Player.h"

template <class T>
class PList {
private:
	std::shared_ptr<std::vector<T>> val;

public:
	PList();
	void erase(int id);
	PList<T> findAll(std::function<bool(T&)> pred);
	T operator[](int id);
	std::vector<T>* operator ->();
};