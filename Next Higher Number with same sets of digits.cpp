// C++ program to find the smallest number which greater than a given number 
// and has same set of digits as given number 
#include <bits/stdc++.h> 
#include <cstring> 
#include <algorithm> 
using namespace std; 

// Utility function to swap two digits 
void swap(char *a, char *b) 
{ 
	char temp = *a; 
	*a = *b; 
	*b = temp; 
} 

// Given a number as a char array number[], this function finds the 
// next greater number. It modifies the same array to store the result 
string findNext(string number, int n) 
{ 
	int i, j; 

	// I) Start from the right most digit and find the first digit that is 
	// smaller than the digit next to it. 
	for (i = n-1; i > 0; i--) 
		if (number[i] > number[i-1]) 
			break; 

	// If no such digit is found, then all digits are in descending order 
	// means there cannot be a greater number with same set of digits 
	if (i==0) 
	{ 
		cout << "Next number is not possible"; 
		return number; 
	} 

	// II) Find the smallest digit on right side of (i-1)'th digit that is 
	// greater than number[i-1] 
	int x = number[i-1], smallest = i; 
	for (j = i+1; j < n; j++) 
		if (number[j] > x && number[j] < number[smallest]) 
			smallest = j; 

	// III) Swap the above found smallest digit with number[i-1] 
	swap(&number[smallest], &number[i-1]); 

	// IV) Sort the digits after (i-1) in ascending order 
	sort(number.begin() + i, number.begin() + n); 

	cout << "Next number with same set of digits is " << number<<endl; 

	return number; 
} 

// Driver program to test above function 
int main() 
{ 
	string digits = "534612"; 
	int n = digits.size();
	string str=digits;
	sort(digits.begin(),digits.begin()+n);
	reverse(digits.begin(),digits.begin()+n);
	cout<<str<<" "<<digits<<" "<<n<<endl;
	int i=0;
	while(1){
	str = findNext(str, n);
	if(str==digits)
		break;
	i++;
	} 
	return 0; 
} 
