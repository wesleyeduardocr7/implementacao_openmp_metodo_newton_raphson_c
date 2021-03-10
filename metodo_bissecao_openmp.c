#include <stdio.h>
#include <math.h>
#include <omp.h>

int main(){

     omp_set_num_threads(4);

     int sstop, tn;
     sstop = 0;

     int iter = 0;
     float xe, xd, xm, fxm, erro, raiz;
     float f(float );
     float eps = 1.0E-6;

     printf("_______________________<>_____________________________\n");
     printf("Calculo de Raiz de Equacao com o Metodo da Bissecao\n\n");
     printf("Valores iniciais\n\n");
     printf("xe = ");
     scanf("%f", &xe);
     printf("xd = ");
     scanf("%f", &xd);

     fxm = 1.0;

     double start = omp_get_wtime();

     #pragma omp parallel
     {
        tn = omp_get_thread_num();
        while (!sstop){

          #pragma omp critical
          {
             iter++;
             xm = (xe + xd)/2;

             if (f(xe)*f(xm) > 0){
                xe = xm;
             }else{
                xd = xm;
             }

             if(fxm < eps){
                 printf("PAROU");
                 sstop = 1;
                 #pragma omp flush(sstop)
              }

             fxm = fabs (f(xm));
             printf("Thread = %d | Iteracao = %5d | f(x) = %10.6f |  \n",tn, iter, fxm);
          }

          if(fxm < eps){
             sstop = 1;
             #pragma omp flush(sstop)
          }
        }
    }

    raiz = xm;
    printf("Convergiu apos %4d iteracoes para a raiz = %10.6f", iter, raiz);
}

float f(float x) {
   return (x*x)-5*x+6;
}

/*
float f(float x)
{
      float fun;
      fun = exp(x) - 3*x;
      return(fun);
}*/
