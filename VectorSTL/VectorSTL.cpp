// VectorSTL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include <queue>
using namespace std;


enum TYPE{Noodles = 0, Cereal = 1, Pancakes = 2, Chicken = 3, Ribs = 4, Pizza = 4};
struct Meal {
	string food;
	TYPE Food;
	double cost;
};

struct People {
	string firstName;
	string lastName;
	vector< Meal*> meals;
};





void addMeal(People* person, Meal* meal){
	person->meals.push_back(meal);
}

/*void waitList(queue<People*> orderWait) {
	orderWait.pop();
	for (int i = 0; i < orderWait.size(); i++){
		cout << "[" << orderWait.front()->firstName << " " << orderWait.front()->lastName << "]";
		
	}		for (int j = 0; j < orderWait.front()->meals.size(); j++){
			cout << "[" << orderWait.front()->meals[j]->food << ", " << orderWait.front()->meals[j]->cost << "]";
			
	}
	
	cout << endl;
}*/

void waitList(queue<People*> orderWait) {
	if (orderWait.empty()) {
		cout << "empty" << endl;
	}
	else {
		while (!orderWait.empty()) {
			cout << "Q's not empty!" << endl;
			cout << "[" << orderWait.front()->firstName << " " << orderWait.front()->lastName << "]";
			for (int j = 0; j < orderWait.front()->meals.size(); j++){
				cout << "[" << orderWait.front()->meals[j]->food << ", " << orderWait.front()->meals[j]->cost << "]";

			}
			cout << endl;
			orderWait.pop();
		}
	}
}
void addCustomer(queue<People*> &orderWait, People* person) { //have to pass a refrence to a datastructure/type/container

	orderWait.push(person);
	cout << orderWait.front()->firstName << endl;
}


int _tmain()
{
	int x;
	queue <People*> orderWait;
	People* John = new People();
	John->firstName = "John";
	John->lastName = "Doe";
	Meal* myNoodles = new Meal();
	myNoodles->Food = Noodles;
	myNoodles->food = "Noodles";
	myNoodles->cost = 2.00;
	addMeal(John, myNoodles);
	

	People* Patrick = new People();
	Patrick->firstName = "Patrick";
	Patrick->lastName = "Star";
	Meal* myPizza = new Meal();
	myPizza->Food = Pizza;
	myPizza->food = "Pizza";
	myPizza->cost = 1.00;
	addMeal(Patrick, myPizza);
	addMeal(Patrick, myNoodles);
	addCustomer(orderWait, John); //not owrking?
	addCustomer(orderWait, Patrick); //not working?
	waitList(orderWait); //prints out people and list
	cin >> x;
	return 0;
}

