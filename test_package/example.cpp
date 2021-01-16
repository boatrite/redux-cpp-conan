#include "redux.hpp"
#include <iostream>

enum Action {
	INCREMENT,
	DECREMENT
};

int reducer(int state, Action action) {
	switch(action) {
		case INCREMENT:
			return state + 1;

		case DECREMENT:
			return state - 1;

		default:
			return state;
	}
}

void log(int state) {
	std::cout << state << std::endl;
}

int main() {
	redux::Store<int, Action> store(reducer, 0);

	store.subscribe(log);

	store.dispatch(INCREMENT);
	// 1
	store.dispatch(INCREMENT);
	// 2
	store.dispatch(DECREMENT);
	// 1
}
