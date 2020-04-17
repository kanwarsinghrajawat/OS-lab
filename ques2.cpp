// C++ program to demonstrate calculation in parent and 
// child processes using fork() 
#include <iostream> 
#include <unistd.h> 
using namespace std; 

// Driver code 
int main() 
{ 
	int studentMarks[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
	int sumChild = 0, sumParent = 0, n, i; 
	n = fork(); 

	// Checking if n is not 0 
	if (n > 0) { 
        sumParent = sumChild;  
	} 
 
	else { 
		for (i = 0; i < 10; i++) { 
				sumChild = sumChild + studentMarks[i]; 
		} 
        sumParent = sumChild; 
		cout << "Child process \n";  
	} 
    cout<<sumParent;
	return 0; 
}
