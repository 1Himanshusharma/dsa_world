#include<iostream>
using namespace std;
// this is very very very infinate very famous problems 
// fun fact 
// this problem was not any solution until recursion was not introduced


// there are three paramenter that must be passed
// take a notebook and draw some examples then you will get to know that three tower can be formed with two tower solution and four tower with three tower
// and so on

// parameter A : where all the disks are placed
// parameter B : another empty tower by which we will take help
// parameter c : all the disks have to placed from A to c

// C++ recursive function to 
// solve tower of hanoi puzzle 
#include <bits/stdc++.h> 
using namespace std; 

void towerOfHanoi(int n, char from_rod, char to_rod, 
				char aux_rod) 
{ 
	if (n == 0) { 
		return; 
	} 
	towerOfHanoi(n - 1, from_rod, aux_rod, to_rod); 
	cout << "Move disk " << n << " from rod " << from_rod 
		<< " to rod " << to_rod << endl; 
	towerOfHanoi(n - 1, aux_rod, to_rod, from_rod); 
} 

// Driver code 
int main() 
{ 
	int N = 3; 

	// A, B and C are names of rods 
	towerOfHanoi(N, 'A', 'C', 'B'); 
	return 0; 
} 