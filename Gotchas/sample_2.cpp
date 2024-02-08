#include <iostream>
using std::cout;
using std::endl;

int main()
{
	// Case 1: *b++ = *a++;
	// Equivalent to *(b++) = *(a++);
	int arr1[] = {1, 2, 3, 4, 5};
	int arr2[5];

	int *a = arr1;
	int *b = arr2;

	for (int i = 0; i < 5; ++i)
	{
		*b++ = *a++;
	}

	// Now arr2 has the values of arr1
	for (int i = 0; i < 5; ++i)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;

	// Case 2: ++*d = ++c*
	// In this case, the associativity is right -> left
	// Values inside the pointers are accessed,
	// incremented, and then returned.
	// The returned value in the left side is ignored,
	// and *d ends up containing *c.
	int *c = new int;
	int *d = new int;
	*c = 5;
	*d = 1;

	++*d = ++*c;
	cout << *c << endl;
	cout << *d << endl;

	// Case 3: e++ = f++;
	// This is an error if e is a pointer regardless,
	// of the value on the right. This is because e++
	// evaluates to an rvalue, which cannot be
	// assigned to.

	return 0;
}
