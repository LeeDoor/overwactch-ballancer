#include "PList.h"

template <class T>
PList<T>::PList() {
	val = std::make_shared<std::vector<T>>();
}
template <class T>
void PList<T>::erase(int id) {
	val->erase(val->begin() + id);
}

template <class T>
PList<T> PList<T>::findAll(std::function<bool(T&)> pred) {
	PList<T> res;
	std::for_each(val->begin(), val->end(),
		[&](T& t) {
			if (pred(t)) res->push_back(t);
		});
	return res;
}

template <class T>
T PList<T>::operator[](int id) {
	return (*val)[id];
}
					
template <class T>
std::vector<T>* PList<T>::operator ->() {
	return val.get();
}
template class PList<std::shared_ptr<Team>>;
template class PList<std::shared_ptr<Player>>;