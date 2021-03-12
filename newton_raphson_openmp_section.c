#include <stdio.h>
#include <math.h>
#include <omp.h>

int main(){

    omp_set_num_threads(4);

    int sstop, tn;
    sstop = 0;

	int iter;
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

     #pragma omp parallel reduction(+: iter)
     {

        tn = omp_get_thread_num();
        while (!sstop){

             iter++;

             #pragma omp sections
             {
                #pragma omp section
                {
                    #pragma omp critical
                    {
                        xn = x0 - f(x0)/df(x0);
                    }
                }

                #pragma omp section
                {
                    #pragma omp critical
                    {
                       fxn = fabs (f(xn));
                    }
                }
             }

          printf("Thread = %d | Iteracao = %d  | f(x) = %10.6f\n", tn, iter, fxn);
          x0 = xn;

          if(f(xn) < eps){
             sstop = 1;
             #pragma omp flush(sstop)
          }
        }
    }

    double end = omp_get_wtime();
    printf("\nTime OpenMp = %f seconds\n\n",end - start);

	raiz = xn;
    printf("Convergiu apos %4d iteracoes para a raiz = %10.6f", iter, raiz);
    printf("\n", iter, raiz);
}

float f(float x) {
   return (x*x)-5*x+6;
}

float df(float x) {
   return 2*x-5;
}

