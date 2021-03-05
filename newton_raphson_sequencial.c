#include <stdio.h>
#include <math.h>
#include <omp.h>

int main(){

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

    double start = omp_get_wtime();

	while (f(xn) > eps) {
		iter++;
		xn = x0 - f(x0)/df(x0);
		fxn = fabs (f(xn));
		printf("Iteracao %d   |f(x)|: %10.6f\n", iter, fxn);
		x0 = xn;
    }

    double end = omp_get_wtime();
    printf("\nTime = %f seconds\n\n",end - start);

	raiz = xn;
    printf("Convergiu apos %4d iteracoes para a raiz = %10.6f", iter, raiz);
    printf("\n", iter, raiz);
    printf("\n");
}

float f(float x) {
   return (x*x)-5*x+6;
}

float df(float x) {
   return 2*x-5;
}
