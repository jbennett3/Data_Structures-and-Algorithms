//Programmer Name: Justin Bennett//
/*Program description: The program will take in many diffent length of integers
 and use the karatusba method to calculate the products of the two integers*/
#include <iostream>
using namespace std;
int power(int, int);
int counter(int);
int karatsuba(int, int);
int main()
{
	//test cases for karatsuba multiplication//
	cout << "7*6 = " << karatsuba(7, 6) << endl; // 42
	cout << "15*15 = " << karatsuba(15, 15) << endl; // 225
	cout << "6*13 = " << karatsuba(6, 13) << endl; // 78
	cout << "51*49 = " << karatsuba(51, 49) << endl; // 2499
	cout << "111*111 = " << karatsuba(111, 111) << endl; // 12321
	cout << "5678*1234 = " << karatsuba(5678, 1234) << endl; // 7006652
	cout << "12345678*1 = " << karatsuba(12345678, 1) << endl; // 12345678
	cout << "12345678*0 = " << karatsuba(12345678, 0) << endl; // 0
	cin.get();
	return 0;
}
int counter(int n1)//counter function returns number of digits in integers//
{
	int compare = n1;
	int count1 = 0;

	while (compare != 0)
	{
		compare /= 10;
		count1++;
	}
	return count1;
}
int power(int base, int exponent)//recursive power fuction
{
	if (exponent != 0)
	{
		return (base*power(base, exponent - 1));
	}
	else
		return 1;
}
int karatsuba(int x, int y)
{

	int num1 = counter(x);//determine the number of digits of both integers
	int num2 = counter(y);
	int length = 0;//number of digits variable
	if (num1 == 1 && num2 == 1)//test cases where there are only single digits//
	{
		return x * y;
	}
	if (num1 == 1 || num2 == 1)
	{
		return x * y;
	}
	if (num1 == 0 || num2 == 0)//test case where 0 is being used as an input
	{
		return 0;
	}
	if (num1 > num2)//set the legnth variable to equal to which ever integer had the greatest length
	{
		length = num1;
	}
	if (num1 < num2)
	{
		length = num2;
	}
	if (num2 == num1)
	{
		length = num1;
	}

	length = (length / 2) + (length % 2);// have the length rounded up incase of odd number of digits//
	//this works like a ceil function//
	int denominator = power(10, length);
	// splt the two integers into two halves //
	int  xhalf1 = x / (denominator);
	int  xhalf2 = x - (xhalf1*denominator);
	int   yhalf1 = y / (denominator);
	int   yhalf2 = y - (yhalf1*denominator);
	//recursive call  of karatsuba for products of halves of x ,y//
	int equation0 = karatsuba(xhalf2, yhalf2);
	int equation1 = karatsuba(xhalf2 + xhalf1, yhalf2 + yhalf1);
	int equation2 = karatsuba(xhalf1, yhalf1);
	int final_result = equation0 + ((equation1 - equation0 - equation2)*denominator) + (equation2*(power(10, 2 * length)));
	//return the final result//
	return (final_result);

}

