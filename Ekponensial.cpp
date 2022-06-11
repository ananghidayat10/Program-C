#include <iostream>
#include <iomanip>
#include <math.h> 
int main() {    
	int N = 11;
    double x[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	double y[] = {4.0, 4.4, 6.2, 7.5, 8.0,9.3,11.0, 12.2, 14.1, 17.5, 20.0};
	double Sx = 0, Sxx = 0 , Sy = 0, Sxy = 0, A, B;
	for (int i=0; i<N; i++) {      
		Sx  = Sx +x[i];
	      Sxx = Sxx+x[i]*x[i];
	      Sy  = Sy +log(y[i]);
	      Sxy = Sxy+x[i]*log(y[i]);
	}
	A = exp((Sxx*Sy-Sx*Sxy)/(N*Sxx-Sx*Sx));
	B = (N*Sxy-Sx*Sy)/(N*Sxx-Sx*Sx);
	  
	cout<< "y = A exp(Bx)" << endl;    
	cout << "A = " << A << endl;    
	cout << "B = " << B << endl;

}
