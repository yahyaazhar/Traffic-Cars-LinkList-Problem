/*Assignment 3 Problem 4
  Roll NO: 2018-CS-613
  Section: A
  Name: M Yahya*/

#include <iostream>
#include <string>
using namespace std;


/* Vertical Side*/
class verSide {
public:
	int* verArray;
	int size = 0;
	int front, rear = 0;

	verSide() {

	}
	verSide(int s) {
		size = s;
		verArray = new int[size];
		for (int i = 0; i < size; i++) {
			verArray[i] = -1;
		}
	}

	bool isFull() {
		if (rear == size) {
			return true;
		}
		else {
			return false;
		}
	}

	bool isEmpty() {
		if (rear == front) {
			return true;
		}
		else {
			return false;
		}
	}

	void verEnQueue(int value) {
		if (!isFull()) {
			verArray[rear] = value;
			rear++;
		}
		else {
			cout << "Vertical road is full!\n";
		}
	}

	int verDeQueue() {
		if (!isEmpty()) {
			int car;
			car = verArray[rear - 1];
			verArray[rear - 1] = -1;
			front++;
			if (front == size) {
				front = 0;
			}
			rear--;
			return car;
		}
		else {
			cout << "Vertical road is empty!\n";
		}
	}

	void showVerRoad() {
		cout << "Vertical Road Traffic: \n";
		for (int i = 0; i < rear; i++) {
			cout << verArray[i] << " ";
		}
		cout << endl;
	}


};

/* Right Queue*/
class rightSide {
public:
	int* rightArray;
	int size = 0;
	int front, rear = 0;


	
	rightSide() {
	}

	rightSide(int s) {
		size = s;
		rightArray = new int[size];

		for (int i = 0; i < size; i++) {
			rightArray[i] = -1;
		}
	}

	bool isFull() {
		if (rear == size) {
			return true;
		}
		else {
			return false;
		}
	}

	bool isEmpty() {
		if (rear == front) {
			return true;
		}
		else {
			return false;
		}
	}

	void rightEnQueue(int value) {
		if (!isFull()) {
			rightArray[rear] = value;
			rear++;
		}
		else {
			cout << "Right road is full!\n";
		}
	}

	int rightDeQueue() {
		if (!isEmpty()) {
			int car;
			car = rightArray[front];
			rightArray[front] = -1;
			front++;
			if (front == size) {
				front = 0;
			}
			rear--;
			return car;
		}
		else {
			return -1;
		}
	}


	void showRightRoad() {
		cout << "\t\t\t\tRight Road Traffic: \n\t\t\t\t\t";
		for (int i = 0; i < size; i++) {
			cout << rightArray[i] << " ";
		}
		cout << endl;
	}
};

/* Left Queue*/
class leftSide {
public:
	int* leftArray;
	int size = 0;
	int front, rear = 0;

	leftSide() {

	}
	leftSide(int s) {
		size = s;
		leftArray = new int[size];
		for (int i = 0; i < size; i++) {
			leftArray[i] = -1;
		}
	}

	bool isFull() {
		if (rear == size) {
			return true;
		}
		else {
			return false;
		}
	}

	bool isEmpty() {
		if (rear == front) {
			return true;
		}
		else {
			return false;
		}
	}

	void leftEnQueue(int value) {
		if (!isFull()) {
			leftArray[rear] = value;
			rear++;
		}
		else {
			cout << "Left road is full!\n";
		}
	}

	int leftDeQueue() {
		if (!isEmpty()) {
			int car;
			car = leftArray[front];
			leftArray[front] = -1;
			front++;
			return car;
		}
		else {
			cout << "Road is empty!\n";
		}
	}


	void showLeftRoad() {
		cout << "Left Road Traffic: \n";
		for (int i = 0; i < rear; i++) {
			cout << leftArray[i] << " ";
		}
		cout << endl;
	}
};





int main() {
	rightSide right_Traffic(3);
	leftSide left_Traffic(3);
	verSide ver_Traffic(3);


	cout << endl;
	int select = -1;

	cout << "To Insert Cars: Press 1\n";
	cin >> select;
	if (select == 1) {
		int l1, l2, l3 = 0;
		int r1, r2, r3 = 0;
		cout << "Enter Left Road Cars: \n";
		cin >> l1; cin >> l2; cin >> l3;
		left_Traffic.leftEnQueue(l1);
		left_Traffic.leftEnQueue(l2);
		left_Traffic.leftEnQueue(l3);
		cout << "Enter Right Road Cars: \n";
		cin >> r1; cin >> r2; cin >> r3;
		right_Traffic.rightEnQueue(r1);
		right_Traffic.rightEnQueue(r2);
		right_Traffic.rightEnQueue(r3);

		cout << endl << endl;

		left_Traffic.showLeftRoad();
		right_Traffic.showRightRoad();

		if (right_Traffic.isFull()) {
			cout << "Cant move to leftside! Road is full.\n";
			cout << "Moving right cars to vertical line......\n\n\n";
			for (int i = 0; i < right_Traffic.size; i++) {
				ver_Traffic.verEnQueue(right_Traffic.rightDeQueue());
			}
			ver_Traffic.showVerRoad();
			right_Traffic.showRightRoad();

			cout << "Movinig left car to right....\n";
			right_Traffic.rightEnQueue(left_Traffic.leftDeQueue());

			left_Traffic.showLeftRoad();
			right_Traffic.showRightRoad();
		}
		else {
			cout << "Road is free!\n";
			cout << "Movinig left car to right....\n";
			right_Traffic.rightEnQueue(left_Traffic.leftDeQueue());

			left_Traffic.showLeftRoad();
			right_Traffic.showRightRoad();
		}
		right_Traffic.rightDeQueue();
		cout << "Left car has been moved!\n\n";
		right_Traffic.showRightRoad();
		cout << "Moving vertical traffic back to right side.......\n";
		for (int i = 0; i < right_Traffic.size; i++) {
			right_Traffic.rightEnQueue(ver_Traffic.verDeQueue());
		}

		cout << "\t\tFinal Display....\n";
		left_Traffic.showLeftRoad();
		right_Traffic.showRightRoad();
		ver_Traffic.showVerRoad();

	}




	system("pause");
	return 0;
}