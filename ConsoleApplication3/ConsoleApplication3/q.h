#pragma once
#include<vector>
using namespace std;
class queue {
private:
	vector<int> q;
public:
	//constructor
	queue() {};
	//checks if queue is empty
	bool empty() {
		return q.empty();
	}
	//returns front of queue
	int front(){
		return q.front();
	}
	//adds item to the queue
	void push(int item) {
		q.push_back(item);
	}
	//removes item from the front
	void pop() {
		q.erase(q.begin());
	}
	//returns the size of the queue
	int size() {
		return q.size();
	}
};