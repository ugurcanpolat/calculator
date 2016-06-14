#include <stdio.h>

#define PI 3.14159265

float add (float x);
float subtract (float x);
float multiply (float x);
float divide (float x);
float modulus (int x);
float exponent (float x);
float power (float x);
float absolute (float x);
unsigned int factorial (int x);
float tangent (float x);
float sine (float x);
float cosine (float x);
float sineT (float x);
float cosineT (float x);
float pi ();
void clear (float* result, float* tempResult);
void memory (float result, float* tempResult);
void memoryClear (float* result, float* tempResult);
float memoryReturn (float result, float tempResult);
/* TODO (#1#): ***Refactor 'prnt' function*** */
/* TODO (#2#): ***Use a new mechanism for 'scanf' *** */
float prnt (float result); /* This is a proplematic function  */
void wrong ();

int main (void) {
	float x = 0, y = 0, result = 0, tempResult = 0;
	char opertr[2];
	
	printf ("\n--------------------------------------------------------------\n");
	printf ("The list of operations in this simple calculator:\nsine (S), cosine (N), tangent (T), exponent (E)\n");
	printf ("power (W), absolute (A), factorial (F)\nadd (+), subtract (-), divide(/), multiply(*), modulus (%) \n");
	printf ("pi (P) \nMemory (M) \nClear (C) \nMemory Clear (MC) \nMemory Return (MR) \nQuit (Q) \n");
	printf ("--------------------------------------------------------------\n\n");
	
	do { //use "do-while" to ask whether the user wants to continue or not
		if (result == 0 && tempResult == 0)	{ //if result = 0 ask new number to calculate
			printf ("Enter integer1: "); //get the number from user
			scanf ("%f", &x);
		}
		else { 
			x = result;
		}
		
		printf ("Enter operator: "); //get operator from user 
		scanf ("%s", &opertr);
		
		if (opertr[1] != 0) {
			if (opertr[0] == 'M' && opertr[1] == 'C') { //'MC' memory clear
				opertr[0] = 'X';
				opertr[1] = 0;
			}
			else if (opertr[0] == 'M' && opertr[1] == 'R') { //'MR' memory return
				opertr[0] = 'Y';
				opertr[1] = 0;
			}
		}
		
			switch (opertr[0]) { 
	            case '+': result = add(x); break; 
	            case '-': result = subtract(x); break; 
	            case '*': result = multiply(x); break; 
	            case '/': result = divide(x); break; 
	            case '%': result = modulus(x); break; 
	            case 'F': result = factorial(x); break; 
	            case 'W': result = power(x); break; 
	            case 'E': result = exponent(x); break; 
	            case 'A': result = absolute(x); break;
	            case 'T': result = tangent(x); break; 
	            case 'S': result = sine(x); break;
	            case 'N': result = cosine(x); break;
	            case 'P': result = pi(); break;
	            case 'C': clear(&result, &tempResult); break;
	            case 'M': memory (result, &tempResult); break; 
	            case 'X': memoryClear(&result, &tempResult); break; 
	            case 'Y': result = memoryReturn(result,tempResult); break; 
	            case 'Q': break;
	            default : wrong ();
	    	}
	    	opertr[1] = 0;
	} while (opertr[0] != 'Q'); 
	return 0;
} 

float prnt (float result){ //custom print function that prints decimals if result have
	int prntResult = result;
	
		if (result == prntResult){
			printf ("%d\n", prntResult);
		}
		else {
			printf ("%.2f\n", result);
		}
	return result;
}

float add (float x) { //addition function
	float y, result;
	printf ("Enter integer2: ");
	scanf ("%f", &y);
	result = x + y;
	return prnt (result); 
}

float subtract (float x) { //subtraction function
	float y, result;
	printf ("Enter integer2: ");
	scanf ("%f", &y);
	result = x - y;
	return prnt (result);
}

float multiply (float x) { //multiplication function
	float y, result;
	printf ("Enter integer2: ");
	scanf ("%f", &y);
	result = x * y;
	return prnt (result);
}

float divide (float x) { //divide function
	float y, result;
	printf ("Enter integer2: ");
	scanf ("%f", &y);
	result = x / y;
	return prnt (result);
}

float modulus (int x) { //modulus function
	int y;
	float result;
	printf ("Enter integer2: ");
	scanf ("%d", &y);
	result = x % y;
	return prnt (result);
}

unsigned int factorial (int x) { //factorial fuction
	long factX = 1;
	for (; x >= 1; x--) factX *= x;
	printf ("%d\n", factX);
	return factX;	
}

float exponent (float x) { //exponent function
	int expX = 10;
	int y;
	printf ("Enter integer2: ");
	scanf ("%d", &y);
	for (; y>1; y--) expX *= 10; //multiply expX with 10
	expX *= x; //multiply expX with x 
	printf ("%d\n", expX);
	return expX;
}

float power (float x) { //power function
	float result;
	float powX = x;
	int y;
	printf ("Enter user input: ");
	scanf ("%d", &y);
	for (; y>1; y--) powX *= x; 
	result = powX;
	return prnt (result);
}

float absolute (float x) { //absolute function
	float result;
	float absolX = 0;
	if (x<0){ //if x < 0 it converts x to positive 
		absolX = 0 - x;
	}
	else{ //if x >= 0
		absolX = x;
	}
	result = absolX;
	return prnt (result);
}

float pi () { //prints defined PI
	printf ("PI defined as 3.14159265\n");
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

float sine (float x) { //sine function 
	float result = 0;
	double radian = convertRadian (x); //calls convertRadian to convert degree to radian 
	int y;
	for(y=1; y<10; y++){ //loop to calculate taylor serie for sine
		int firstPart = powerTaylor (-1, (y-1)); //(-1)^(n-1)
		double secondPart = powerTaylor (radian,((2*y)-1)); // x^(2n-1)
		double thirdPart = factorialTaylor((2*y)-1); // (2n-1)!
		result = result + firstPart*(secondPart/thirdPart);
	}	
	return prnt(result);
} 

float cosine (float x) { //cosine function
	float result = 0;
	double radian = convertRadian (x); //calls convertRadian to convert degree to radian
	int y;
	for(y=1; y<10; y++){ //loop to calculate taylor serie for cosine
		int firstPart = powerTaylor(-1, (y-1)); //(-1)^(n-1)
		double secondPart = powerTaylor(radian,((2*y)-2)); // x^(2n-2)
		double thirdPart = factorialTaylor((2*y)-2); // (2n-2)!
		result = result + firstPart*(secondPart/thirdPart);
	}
	return prnt(result);
}

float sineT (float x) { //sine function for tangent function
	float result = 0;
	double radian = convertRadian (x);
	int y;
	for(y=1; y<10; y++){
		int firstPart = powerTaylor (-1, (y+1)); //(-1)^(n+1)
		double secondPart = powerTaylor (radian,((2*y)-1)); // x^(2n-1)
		double thirdPart = factorialTaylor((2*y)-1); // (2n-1)!
		result = result + firstPart*(secondPart/thirdPart);
	}	
	return result;
} 

float cosineT (float x) { //cosine function for tangent function
float result = 0;
	double radian = convertRadian (x); //calls convertRadian to convert degree to radian
	int y;
	for(y=2; y<10; y++){ //loop to calculate taylor serie for cosine
		int firstPart = powerTaylor (-1, (y+1)); //(-1)^(n+1)
		double secondPart = powerTaylor (radian,((2*y)-2)); // x^(2n-2)
		double thirdPart = factorialTaylor((2*y)-2); // (2n-2)!
		result = result + firstPart*(secondPart/thirdPart);
	}
	return result+1;
}

float tangent (float x) { //tangent function 
	float tanX;
	if (cosineT != 0) { //tangent must be defined 
		tanX = sineT (x) / cosineT (x); 
		return prnt (tanX);
		}
	else { 
		printf ("Tangent is undefined");
		return x;
	}
}

void clear (float* result, float* tempResult) { //function that clears result 
	*tempResult = *result;
	*result = 0;
}

void memory (float result, float* tempResult) { //function that keeps result in memory
	*tempResult = result;	
}

void memoryClear (float* result, float* tempResult) { //function that clears result and memory result
	*result = 0;
	*tempResult = 0;
}

float memoryReturn (float result, float tempResult) { //function that returns value of result
	result = tempResult;
	return prnt (result);
}

void wrong (){ //if user enters wrong character or number, prints operators
	printf ("\nInvalid character. Choose from the operators below:\n");
	printf ("--------------------------------------------------------------\n");
	printf ("The list of operations in this simple calculator:\nsine (S), cosine (N), tangent (T), exponent (E)\n");
	printf ("power (W), absolute (A), factorial (F)\nadd (+), subtract (-), divide(/), multiply(*), modulus (%) \n");
	printf ("pi (P) \nQuit (Q) \nMemory (M) \nClear (C) \nMemory Clear (MC) \nMemory Return (MR) \n");
	printf ("--------------------------------------------------------------\n\n");
}

