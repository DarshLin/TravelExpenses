#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int daysSpent();
void travelTimes(double &, double &);
double flightCost();
double carRental();
double milesCost();
double parkingCost(int, double &);
double taxiCost(int, double &);
double registrationCost();
double hotelCost(int, double &);
double mealCost(double, double, int, double &);
double subTotalFees(double, double, double, double, double, double, double, double);
void moneySaved(double, double &, double);
double outOfPocket(double, double);
void displayInfo(int, double, double, double, double, double, double, double, double, double, double, double, double, double);


int main() {
	char carRent, personalVehicle, park, taxi;
	int days;
	double departure, arrival;
	double airfare, carFare, milesFees = 0, parkingFees, taxiFees, registrationFees, hotelFees, mealFees, totalPaid, subTotal;
	double savings = 0; //don't wanna mess with this variable in main


	days = daysSpent();
	travelTimes(departure, arrival);
	airfare = flightCost();
	savings += airfare;

	cout << "Was a car rented? (Y/N) ";
	cin >> carRent;

	if (carRent == 'y' || carRent == 'y') {
		carFare = carRental();
		savings += carFare;
		cout << "Were there any parking fees? (Y/N) ";
		cin >> park;
		
		if (park == 'Y' || park == 'y') {
			parkingFees = parkingCost(days, savings);
		}
	}
	else {
		carFare = 0;
		cout << "Was a personal vehicle used instead? (Y/N) ";
		cin >> personalVehicle;
		if (personalVehicle == 'Y' || personalVehicle == 'y') {
			milesFees = milesCost();
			savings += milesFees;
			cout << "Were there any parking fees? (Y/N) ";
			cin >> park;

			if (park == 'Y' || park == 'y') {
				parkingFees = parkingCost(days, savings);
			}
			else {
				parkingFees = 0;
			}
		}
	}

	cout << "Was a taxi used at any point during this trip? (Y/N) ";
	cin >> taxi;

	if (taxi == 'Y' || taxi == 'y') {
		taxiFees = taxiCost(days, savings);
	}
	else {
		taxiFees = 0;
	}

	registrationFees = registrationCost();
	savings += registrationFees;
	hotelFees = hotelCost(days, savings);
	mealFees = mealCost(departure, arrival, days, savings);
	subTotal = subTotalFees(airfare, carFare, milesFees, parkingFees, taxiFees, registrationFees, hotelFees, mealFees);
	totalPaid = outOfPocket(subTotal, savings);
	displayInfo(days, departure, arrival, airfare, carFare, milesFees, 
		parkingFees, taxiFees, registrationFees, hotelFees, mealFees, subTotal, savings, totalPaid);

	system("pause");
	return 0;
}

int daysSpent() {
	int days;
	
		cout << "How many days were spent on this trip? ";
		cin >> days;
		while (days < 1) {
			cout << "Please enter at least one day. Try Again." << endl;
			cout << "How many days were spent on this trip? ";
			cin >> days;
		}
	return days;
}

void travelTimes(double &departure, double &arrival) {

	cout << "When did this person depart on the \nfirst day of the trip (00.00 - 23.59)? ";
	cin >> departure;
	while (departure < 0 || departure > 23.59 || departure - (int)departure > .59) {
		cout << "Error in your input please try again" << endl;
		cout << "When did this person depart on the \nfirst day of the trip (00.00 - 23.59)? ";
		cin >> departure;
	}
	cout << "When did this person arrive home on the \nlast day of the trip(00.00 - 23.59)? ";
	cin >> arrival;
	while (arrival < 0 || arrival > 23.59 || arrival - (int)arrival > .59) {
		cout << "Error in your input please try again" << endl;
		cout << "When did this person arrive home on the \nlast day of the trip (00.00 - 23.59)? ";
		cin >> arrival;
	}
}

double flightCost() {
	double cost;

	cout << "How much was the flight? $";
	cin >> cost;
	while (cost < 0) {
		cout << "Error in your input, try again" << endl;
		cout << "How much was the flight? $";
		cin >> cost;
	}

	return cost;
}

double carRental() {
	double cost;

	cout << "How much was the car rental? $";
	cin >> cost;
	while (cost < 0) {
		cout << "Error in you input, try again" << endl;
		cout << "How much was the car rental? $";
		cin >> cost;
	}

	return cost;
}

double milesCost() {
	double miles, cost;
	cout << "How many miles were driven? ";
	cin >> miles;

	while (miles < 0) {
		cout << "Error in your input, try again" << endl;
		cout << "How many miles were driven? ";
		cin >> miles;
	}

	cost = miles * .27;

	return cost;
}

double parkingCost(int days, double &savings) {
	double cost, total = 0;

	for (int i = 1; i <= days; i++) {
		cout << "How much was the parking on day " << i << "? $";
		cin >> cost;

		while (cost < 0) {
			cout << "Error in your input, try again" << endl;
			cout << "How much was the parking on day " << i << "? $";
			cin >> cost;
		}
		moneySaved(6, savings, cost);
		total += cost;
	}
	return total;
}

double taxiCost(int days, double &savings) {
	double cost, total = 0;;

	for (int i = 1; i <= days; i++) {
		cout << "How much was the cost of taxi rides on day " << i << "? $";
		cin >> cost;

		while (cost < 0) {
			cout << "Error in your input, try again" << endl;
			cout << "How much was the cost of taxi rides on day " << i << "? $";
			cin >> cost;
		}
		moneySaved(10, savings, cost);
		total += cost;
	}
	return total;
}

double registrationCost() {
	double cost;

	cout << "How much was the cost of conference or registration fees? $";
	cin >> cost;

	while (cost < 0) {
		cout << "Error in your input, try again" << endl;
		cout << "How much was the cost of conference or registration fees? $";
		cin >> cost;
	}

	return cost;
}

double hotelCost(int days, double &savings) {
	char other;
	double cost, total = 0, otherCosts;
	cout << "How much was the cost of the hotel each night? $";
	cin >> cost;

	while (cost < 0) {
		cout << "Error in your input, try again" << endl;
		cout << "How much was the cost of the hotel each night? $";
		cin >> cost;
	}
	for (int i = 1; i <= days; i++) {
		moneySaved(90, savings, cost);
		total += cost;
	}
	cout << "Were there any other charges besides lodging? (Y/N) ";
	cin >> other;

	if (other == 'Y' || other == 'y') {
		cout << "How much was the total of all the other charges? $";
		cin >> otherCosts;
			if (otherCosts < 0) {
				cout << "Error in your input, try again" << endl;
				cout << "How much was the total of all the other charges? $";
				cin >> otherCosts;
			}
			total += otherCosts;
	}

	return total;
}

double mealCost(double departure, double arrival, int days, double &savings) {
	double breakfast, lunch, dinner, total = 0;

	for (int i = 1; i <= days; i++) {
		cout << "How much was breakfast on day " << i <<"? $";
		cin >> breakfast;
		while (breakfast < 0) {
			cout << "Error in your input, try again" << endl;
			cout << "How much was breakfast on day " << i << "? $";
			cin >> breakfast;
		}
		cout << "How much was lunch on day " << i << "? $";
		cin >> lunch;
		while (lunch < 0) {
			cout << "Error in your input, try again" << endl;
			cout << "How much was lunch on day 1 " << i << "? $";
			cin >> lunch;
		}
		cout << "How much was dinner on day " << i << "? $";
		cin >> dinner;
		while (dinner < 0) {
			cout << "Error in your input, try again" << endl;
			cout << "How much was dinner on day " << i << "? $";
			cin >> dinner;
		}
		if (i == 1) {
			if (departure <= 7) {
				savings += breakfast;
			}
			else if (departure > 7 && departure <= 12) {
				savings += lunch;
			}
			else if (departure > 12 && departure <= 18) {
				savings += dinner;
			}
		}
		if (i == days) {
			if (arrival >= 19) {
				savings += dinner;
			}
			else if (arrival >= 13) {
				savings += lunch;
			}
			else if (arrival >= 8) {
				savings += breakfast;
			}
		}
		if (i != 1 && i != days) {
			moneySaved(9, savings, breakfast);
			moneySaved(12, savings, lunch);
			moneySaved(16, savings, dinner);
		}
		total += breakfast + lunch + dinner;
	}
	
	return total;
}

double subTotalFees(double airfare, double carFare, double milesFees, double parkingFees, double taxiFees,
	double registrationFees, double hotelFees, double mealFees) {

	double subtotal;

	subtotal = airfare + carFare + milesFees + parkingFees + taxiFees + registrationFees + hotelFees + mealFees;

	return subtotal;
}

void moneySaved(double deductible, double &savings, double cost) {
	
	if (deductible <= cost) {
		savings += deductible;
	}
	else {
		savings += cost;
	}
}

double outOfPocket(double subtotal, double savings) {
	double total;

	total = subtotal - savings;

	return total;
}

void displayInfo(int days, double departure, double arrival, double airfare, double carFare, double milesFees, double parkingFees, 
	double taxiFees, double registrationFees, double hotelFees, double mealFees, double subTotal, double savings, double totalPaid) {
	
	cout << endl << endl;
	cout << fixed << showpoint << setprecision(2);
	cout << "Time of departure: " << departure << endl;
	cout << "Time of arrival: " << arrival << endl;
	cout << "Number of days: " << days << endl;
	cout << endl;
	cout << "Business Trip Travel expenses:" << endl;
	cout << setw(40) << left << "Total airfare:" << right << "$" << airfare << endl;
	cout << setw(40) << left << "Total Car Rental costs:" << right << "$" << carFare << endl;
	cout << setw(40) << left << "Total Cost for miles driven:" << right << "$" << milesFees << endl;
	cout << setw(40) << left << "Total Parking costs:" << right << "$" << parkingFees << endl;
	cout << setw(40) << left << "Total Taxi costs:" << right << "$" << taxiFees << endl;
	cout << setw(40) << left << "Total Registration fees:" << right << "$" << registrationFees << endl;
	cout << setw(40) << left << "Total Hotel costs:" << right << "$" << hotelFees << endl;
	cout << setw(40) << left << "Total Meal costs:" << right << "$" << mealFees << endl;
	cout << setw(40) << left << "Total Expenses:" << right << "$" << subTotal << endl;
	cout << setw(40) << left << "Total Savings:" << right << "$" << savings << endl;
	cout << setw(40) << left << "Out of Pocket Expenses:" << right << "$" << totalPaid << endl;

}