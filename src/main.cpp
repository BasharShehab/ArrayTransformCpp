#include <iostream>
using namespace std;

int a[100][100], lengtha, widtha, b[100][100], lengthb, widthb, d[100][100];
// declaring all matrices and dimensions so that all functions recognize them ( even when i dont pool them into the function when calling )
void read(int a[][100], int lengtha, int widtha, int b[][100], int lengthb, int widthb) {
	cout << "Enter the values for array A, one by one : " << endl;
	for (int i = 0; i < lengtha; i++) {
		for (int j = 0; j < widtha; j++) {
			cin >> a[i][j];
		}
	}
	cout << endl << "Enter the values for array B, one by one : " << endl;
	for (int i = 0; i < lengthb; i++) {
		for (int j = 0; j < widthb; j++) {
			cin >> b[i][j];
		}
	}
	cout << endl;
}

void print(int a[][100], int lengtha, int widtha, int b[][100], int lengthb, int widthb) {
	// printing out the matrices
	cout << "Array A is : ";
	for (int i = 0; i < lengtha; i++) {
		cout << endl;
		for (int j = 0; j < widtha; j++) {
			cout << a[i][j] << " ";
		}
	}
	cout << endl << "Array B is : ";
	for (int i = 0; i < lengthb; i++) {
		cout << endl;
		for (int j = 0; j < widthb; j++) {
			cout << b[i][j] << " ";
		}
	}
}
void arrc(int c[][100], int lengtha, int widtha, int lengthb, int widthb) {
	// sum only if its possible. the dimensions have to be the same.
	if (lengtha == lengthb && widtha == widthb) {
		for (int i = 0; i < lengtha; i++){
			for (int j = 0; j < widtha; j++) {
				c[i][j] = (a[i][j] + b[i][j]);
			}
		}

		cout << endl << "Array C, where C = A + B, is : ";
		for (int i = 0; i < lengtha; i++){
			cout << endl;
			for (int j = 0; j< widtha; j++){
				cout << c[i][j] << " ";
			}
		}
	}
	else
		cout << endl << endl << "Array C, which is A + B, cannot be found because array A and array B dimensions are not compatible " << endl;
}

int suma(int a[][100], int lengtha, int widtha) {
	int sum = 0;
	for (int i = 0; i < lengtha; i++) {
		for (int j = 0; j < i; j++) {
			sum = sum + a[i][j];
		}
		// NOTE : if you want to include the main diameter, change (<) to (<=) in both loops.
	}
	return sum;
}

void arrd(int d[][100]) {
	//using swap as i found it on google instead of using a temporary variable to swap the values ( i also think you told us about it before ). 
	swap(lengthb, widthb);
	for (int i = 0; i< lengthb; i++){
		for (int j = 0; j<widthb; j++) {
			d[i][j] = b[j][i];
		}
	}
	for (int i = 0; i < lengthb; i++) {
		cout << endl;
		for (int j = 0; j < widthb; j++) {
			cout << d[i][j] << " ";
		}
	}
}

int main() {
	// Entering the length and width of arrays
	cout << "Enter the amount of rows for array A : ";
	cin >> lengtha;
	cout << "Enter the amount of coloumns for array A : ";
	cin >> widtha;
	cout << "Now enter the amount of rows for array B : ";
	cin >> lengthb;
	cout << "Now enter the amount of coloumns for array B : ";
	cin >> widthb;
	// Entering arrays a and b using functions
	read(a, lengtha, widtha, b, lengthb, widthb);
	print(a, lengtha, widtha, b, lengthb, widthb);

	// declaring array c and calculating with arrc function and printing it out.
	int c[100][100];
	arrc(c, lengtha, widtha, lengthb, widthb);

	// sum of numbers below main diameter of A
	if (lengtha == widtha) {
		cout << endl << endl << "The sum of values below the main diameter of array A is : " << suma(a, lengtha, widtha) << endl;
	}
	else
		cout << endl << endl << "Array A is not a squared array. No main diameter." << endl;

	cout << endl << endl << "Array D, which is the transpose of array B, is : ";
	arrd(d);
	cout << endl;

	system("pause");
	return 0;
}

