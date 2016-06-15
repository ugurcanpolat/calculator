#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define PI 3.14159265

float add (float x, char operator);
float subtract (float x, char operator);
float multiply (float x, char operator);
float divide (float x, char operator);
float modulus (int x, char operator);
float exponent (float x, char operator);
float power (float x, char operator);
float absolute (float x);
unsigned int factorial (int x);
float tangent (float x);
float sine (float x, int controller);
float cosine (float x, int controller);
float pi ();
void clear (float *result, float *tempResult);
void memory (float result, float *tempResult);
void memoryClear (float *result, float *tempResult);
float memoryReturn (float result, float tempResult);
void get_input(float *integer, char *operator); 
void wrong ();

int main (void) {
	float result = 0, tempResult = 0, integer = 0;;
	char operator = 0;
	
	
	printf ("\n--------------------------------------------------------------\n");
	printf ("The list of operations in this simple calculator:\nsine (S), cosine (N), tangent (T), exponent (E)\n");
	printf ("power (W), absolute (A), factorial (F)\nadd (+), subtract (-), divide(/), multiply(*), modulus (%%) \n");
	printf ("pi (P) \nMemory (M) \nClear (C) \nMemory Clear (MC) \nMemory Return (MR) \nQuit (Q) \n");
	printf ("--------------------------------------------------------------\n\n");
	
	do { //use "do-while" to ask whether the user wants to continue or not
		if (result == 0 && tempResult == 0 && operator != 'Y')	{ //if result = 0 ask new number to calculate
			get_input(&integer, &operator);
		}
		else { 
			integer = result;
		}
		
		get_input(&integer, &operator);
		
		if (operator == 0)
			get_input(&integer, &operator);
		
		switch (operator) { 
			case '+': result = add(integer, operator); break; 
	        case '-': result = subtract(integer, operator); break; 
	        case '*': result = multiply(integer, operator); break; 
	        case '/': result = divide(integer, operator); break; 
	        case '%': result = modulus(integer, operator); break; 
	        case 'F': result = factorial(integer); break; 
	        case 'W': result = power(integer, operator); break; 
	        case 'E': result = exponent(integer, operator); break; 
	        case 'A': result = absolute(integer); break;
	        case 'T': result = tangent(integer); break; 
	        case 'S': result = sine(integer,0); break;
	        case 'N': result = cosine(integer,0); break;
	        case 'P': result = pi(); break;
	        case 'C': clear(&result, &tempResult); break;
	        case 'M': memory (result, &tempResult); break; 
	        case 'X': memoryClear(&result, &tempResult); break; 
	        case 'Y': result = memoryReturn(result,tempResult); break; 
	        case 'Q': break;
	        default : wrong ();
	    }
	    
		printf("%g\n", result);
			
	} while (operator != 'Q'); 
	return 0;
} 

void get_input(float *integer, char *operator){
	char *x = malloc(2 * sizeof(char));;
	printf("Enter input: ");
	scanf("%s", x);
	
	if (isdigit(x[0]) || isdigit(x[1])){
		*integer = strtod(x,NULL);
	}
	
	else {
		if (x[1] != 0) {
			if (x[0] == 'M' && x[1] == 'C') { //'MC' memory clear
				*operator = 'X';
			}
			else if (x[0] == 'M' && x[1] == 'R') { //'MR' memory return
				*operator = 'Y';
			}
		}
		
		else
			*operator = x[0];
	}
}

float add (float x, char operator) { //addition function
	float y, result;
	get_input(&y, &operator);
	result = x + y;
	printf("%g + %g = ", x, y);
	return result; 
}

float subtract (float x, char  operator) { //subtraction function
	float y, result;
	get_input(&y, &operator);
	result = x - y;
	printf("%g - %g = ", x, y);
	return result;
}

float multiply (float x, char  operator) { //multiplication function
	float y, result;
	get_input(&y, &operator);
	result = x * y;
	printf("%g * %g = ", x, y);
	return result;
}

float divide (float x, char operator) { //divide function
	float y, result;
	get_input(&y, &operator);
	result = x / y;
	printf("%g / %g = ", x, y);
	return result;
}

float modulus (int x, char operator) { //modulus function
	int a;
	float result, y;
	get_input(&y, &operator);
	a = y;
	result = x % a;
	printf("%d %% %d = ", x, a);
	return result;
}

unsigned int factorial (int x) { //factorial fuction
	long factX = 1;
	int fact = x;
	for (; x >= 1; x--) factX *= x;
	printf ("Factorial(%d) = ", fact);
	return factX;	
}

float exponent (float x, char operator) { //exponent function
	float y = 0;
	int expX = 10, z;
	get_input(&y, &operator);
	z = y;
	for (; y>1; y--) expX *= 10; 
	expX *= x; 
	printf ("%g * exp(%d) = ", x, z);
	return expX;
}

float power (float x, char operator) { //power function
	float result;
	float powX = x;
	float y;
	int integer1, integer2;
	get_input(&y, &operator);
	integer2 = y;
	for (; y>1; y--) powX *= x; 
	result = powX;
	integer1 = x; 
	printf ("%d^%d = ", integer1, integer2);
	return result;
}

float absolute (float x) { //absolute function
	float absolX = 0;
	
	if (x<0) //if x < 0 it converts x to positive 
		absolX = 0 - x;
	
	else //if x >= 0
		absolX = x;
	
	printf("Absolute(%g) = ", x);
	return absolX;
}

float pi () { //prints defined PI
	printf ("PI defined as ");
	return PI;
}
	
double convertRadian(float degree) //function that converts degree to radian
{
	double cRadian = (degree / 180) * (PI);
	return cRadian;
}

double factorialTaylor(unsigned int number){ //factorial function for taylor series which uses in sine-cosine function
	if (number == 0) return 1;
	return number * factorialTaylor(number-1);	
}

double powerTaylor (float x, int y) { //power function for taylor series which is using by sine-cosine functions
	double powX = x;
	if (y==0) powX = 1;
 	for (; y>1; y--) powX *= x; 
	return powX;
}

float sine (float x, int controller) { //sine function 
	float result = 0;
	double radian = convertRadian (x); //calls convertRadian to convert degree to radian 
	int y;
	for(y=1; y<10; y++){ //loop to calculate taylor serie for sine
		int firstPart = powerTaylor (-1, (y-1)); //(-1)^(n-1)
		double secondPart = powerTaylor (radian,((2*y)-1)); // x^(2n-1)
		double thirdPart = factorialTaylor((2*y)-1); // (2n-1)!
		result = result + firstPart*(secondPart/thirdPart);
	}	
	
	if (!controller) 
		printf("Sin(%g) = ", x);
		
	return result;
} 

float cosine (float x, int controller) { //cosine function
	float result = 0;
	double radian = convertRadian (x); //calls convertRadian to convert degree to radian
	int y;
	for(y=1; y<10; y++){ //loop to calculate taylor serie for cosine
		int firstPart = powerTaylor(-1, (y-1)); //(-1)^(n-1)
		double secondPart = powerTaylor(radian,((2*y)-2)); // x^(2n-2)
		double thirdPart = factorialTaylor((2*y)-2); // (2n-2)!
		result = result + firstPart*(secondPart/thirdPart);
	}
	
	if (!controller)
		printf("Cosine(%g) = ",x);
		
	return result;
}

float tangent (float x) { //tangent function 
	float tanX;
	
	if (x != 90) { //tangent must be defined 
		tanX = sine(x,1) / cosine (x,1); 
		printf("Tan(%g) = ", x);
		return tanX;
		}
		
	else { 
		printf ("Tangent is undefined");
		return x;
	}
}

void clear (float *result, float *tempResult) { //function that clears result 
	*tempResult = *result;
	*result = 0;
}

void memory (float result, float *tempResult) { //function that keeps result in memory
	*tempResult = result;	
}

void memoryClear (float *result, float *tempResult) { //function that clears result and memory result
	*result = 0;
	*tempResult = 0;
}

float memoryReturn (float result, float tempResult) { //function that returns value of result
	result = tempResult;
	return result;
}

void wrong (){ //if user enters wrong character or number, prints operators
	printf ("\nInvalid character. Choose from the operators below:\n");
	printf ("--------------------------------------------------------------\n");
	printf ("The list of operations in this simple calculator:\nsine (S), cosine (N), tangent (T), exponent (E)\n");
	printf ("power (W), absolute (A), factorial (F)\nadd (+), subtract (-), divide(/), multiply(*), modulus (%%) \n");
	printf ("pi (P) \nQuit (Q) \nMemory (M) \nClear (C) \nMemory Clear (MC) \nMemory Return (MR) \n");
	printf ("--------------------------------------------------------------\n\n");
}

