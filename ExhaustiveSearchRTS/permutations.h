#pragma once

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// struct representing each point
struct point {
	float x; // x cordinate
	float y; // y cordinate
};

// function calculates the furthest distance between any(all) two 2D points
// INPUT: int n = the size of the array Point, *P - dynamic array of points
// OUTPUT: farthest distance
float farthest(int n, point *P)
{
	float max = 0; // holds the max distance between two points
	float dist; // distance of 2 points

				// loop through all points
	for (int i = 0; i < n - 1; i++)
	{
		dist = abs(P[i].x - P[i+1].x) + abs(P[i].y - P[i+1].y); // calculate the distance between two points
			if (dist > max) // if the distance is greater than max then dist is new max
			{
				max = dist;
			}
		
	}

	// return the furthest
	return max;

}


// Generate all the permutations with values in the range 0..n-1          
// INPUT: a positive integer n  = size of array, int dynamic arrary, size of the arrary                                                  
// OUTPUT: NONE      
void generate_perm(int n, int *A, int size)
{
	// print the permutation
	if (n == 1)
	{
		cout << '\n' << "Permutation:";

		for (int i = 0; i < size; i++)
		{
			cout << A[i] << " ";
		}
		cout << '\n';
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			generate_perm(n - 1, A, size); // recursivly call function

										   // if size is odd, swap first and last element
			if (n % 2 == 1)
			{
				swap(A[0], A[n - 1]);
			}

			// If size is even, swap ith and last element
			else
			{
				swap(A[i], A[n - 1]);
			}
		}

	}

}

// Function that prints the Hamiltoniman Cycle
// n- size of P,seq, P- dynamic array of points, seq- best sequence of minimum weight
void print_cycle(int n, point *P, int*seq)
{

	// prints entire cycle using the sequence stored in seq
	for (int i = 0; i < n; i++)
	{
		cout << "(" << P[seq[i]].x << "," << P[seq[i]].y << ") ";
	}
	cout << "(" << P[seq[0]].x << "," << P[seq[0]].y << ") "; // add on first point to end of print
	cout << '\n';
}


// Function to generate the best minimum wweight permutation indicies and store indicies in bestset
// INPUT: int n - size of point P,A,best, A-indicies to represent the permutations,int size = constant size of arrarys, 
// P- dynamic array of points, bestSet- stores indicies of best set, float &bestDist- best distance 
//OUTPUT: NONE
void print_perm(int n, int *A, int size, point *P, int *bestset, float &bestDist)
{
	float dist;

	if (n == 1)
	{
		dist = 0;
		// calculate distance of path
		for (int i = 0; i < size - 1; i++)
		{
			dist += abs(P[A[i]].x - P[A[i + 1]].x) + abs(P[A[i]].y - P[A[i + 1]].y);
		}
		// add the distance from the end back to the begigning 
		dist += abs(P[A[size - 1]].x - P[A[0]].x) + abs(P[A[size - 1]].y - P[A[0]].y);
		// if the min dist is less than the best dist then it becomes the best dist
		if (dist < bestDist)
		{
			// set dist to best dist
			bestDist = dist;

			// set best set indicies to the current set
			for (int i = 0; i < size; i++)
			{
				bestset[i] = A[i];
			}
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			print_perm(n - 1, A, size, P, bestset, bestDist); // recursivly call function

			// if size is odd, swap first and last element
			if (n % 2 == 1)
			{
				swap(A[0], A[n - 1]);
			}
			// If size is even, swap ith and last element
			else
			{
				swap(A[i], A[n - 1]);
			}
		}
	}
}