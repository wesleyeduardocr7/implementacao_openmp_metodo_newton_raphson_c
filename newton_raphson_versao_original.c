#include <stdio.h>
#include <math.h>
#include <conio.h>

//Função utilizada para e exemplo ( f(x) = exp(x) – 3*x )

main(){

	int iter = 0;
	float x0, xn, fxn, raiz;
	float eps = 1.0E-6;
	float f(float );
	float df(float );

    printf("Cálculo da Raiz da Equacao com o Metodo Newton Raphson\n\n");
    printf("Valor inicial X0: ");
	scanf("%f", &x0);
	printf("%f\n", x0);
	fxn = 1.0;

	while (f(xn) > eps) {
		iter++;
		xn = x0 - f(x0)/df(x0);
		fxn = fabs (f(xn));
		printf("Iteracao %d   |f(x)|: %10.6f\n", iter, fxn);
		x0 = xn;
    }
	raiz = xn;
    printf("Convergiu apos %4d iteracoes para a raiz = %10.6f", iter, raiz);
	getch();
}

/*float f(float x){
	float func;
	func = exp(x) - 3*x;
	return(func);
}

float df(float x){
	float deriv;
	deriv = exp(x) - 3;
	return(deriv);
}*/

//-------------------------------//

float f(float x) {
   return pow(x,2)-5*x+6;
}

float df(float x) {
   return 2*x-5;
}
