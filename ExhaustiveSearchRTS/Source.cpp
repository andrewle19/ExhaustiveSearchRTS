/*
Author: Andrew Le
Email: andrewle19@csu.fullerton.edu
4/7/17

Rectilinear traveling salperson problem solved by using 
Exhaustive search generating permutations to pick the best
weight(lowest size)



*/

#include <iostream>
#include <string>
#include <chrono>
#include <cmath>
#include "permutations.h"
using namespace std;





int main()
{
	int n; // number of verticies 
	point *P; // P- holds the value of every point
	int *bestSet, *A; // best set- holds the indicies of the best set, A- used to permutate the algorithm
	float bestDist, Dist; // best dist -will hold the min length, Dist - holds max dist between two points

	// display the header
	cout << "CPSC 335 Programming Assignment #3" << endl;
	cout << "Rectilinear traveling salesperson problem: exhaustive optimization algorithm" << endl;
	cout << "Enter the number of vertices (>2) " << endl;
	// read the number of elements
	cin >> n;

	// if less than 3 vertices then terminate the program
	if (n < 3)
	{
		return 0;
	}
	P = new point[n]; // dynamically allocate space for number of points

	// read the sequence of distinct points
	cout << "Enter the points; make sure that they are distinct" << endl;
	for (int i = 0; i < n; i++) {
		cout << "x=";
		cin >> P[i].x;
		cout << "y=";
		cin >> P[i].y;
	}
	cout << "Input: n" << endl;
	cout << "n=" << n << endl;
	
	
	
	bestSet = new int[n]; // allocate space for indicies of the points
	A = new int[n]; // populate the starting array for the permutation algorithm
	// set the best set to be the list of indices, starting at 0 AND fill the arrary with values starting from 0 to n-1
	for (int i = 0; i < n; i++)
	{
		bestSet[i] = i;
		A[i] = i;
	}

	// starts the clock
	auto start = chrono::high_resolution_clock::now();

	// calculate the farthest pair of vertices (creates base for algorithm)
	Dist = farthest(n, P); // farthest distance from 2 points
	bestDist = n*Dist; // farthest distance between all points

	// calculate the Hamiltonian cycle of minimum weight
	print_perm(n, A, n, P, bestSet, bestDist);

	// end the clock
	auto end = chrono::high_resolution_clock::now();

	// after shuffling them print the min length cycle
	cout << "The Hamiltonian cycle of the minimum length " << endl;
	print_cycle(n, P, bestSet);
	cout << "Minimum length is " << bestDist << endl;



	int microseconds = chrono::duration_cast<chrono::microseconds>(end - start).count(); // microseconds
	double seconds = microseconds / 1E6; // convert to seconds
	cout << "elapsed time: " << seconds << " seconds" << endl;






	// de-allocate the dynamic memory space
	delete[] P;
	delete[] A;
	delete[] bestSet;
	system("pause");
	return 0;
}