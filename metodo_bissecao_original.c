/*
    Programa bissecao - Calculo da raiz da funcao f(x) = exp(x) - 3x
*/

#include <stdio.h>
#include <math.h>
#include <conio.h>

main()
{
     int iter = 0;		      /* Contador de iteracoes */
     float xe, xd, xm, fxm, erro, raiz;
     float f(float );		      /* Prototipo da funcao f(x) */
     float eps = 1.0E-6;
     printf("_______________________<>_____________________________\n");
     printf("Calculo de Raiz de Equacao com o Metodo da Bissecao\n\n");
     printf("Valores iniciais\n\n");
     printf("xe = ");
     scanf("%f", &xe);
     printf("xd = ");
     scanf("%f", &xd);
     //erro = 1.0;    /* para criterio de parada erro < |xe-xd| 1*/
     fxm = 1.0;	      /* Valor inicial de f(xm)(qualquer numero > eps) */
     //while (erro > eps) {     /* Executa o loop enquanto erro > eps 2*/
	while (fxm > eps)  {/* executa enquanto f(x) > eps*/
     iter++;	      /* Incrementa o contador de iteracoes */
	 xm = (xe + xd)/2;    /* Calculo do valor medio xm */
	 if (f(xe)*f(xm) > 0) /* Teste para verificar de que lado da raiz esta xm  */
	    xe = xm;	      /* xm esta´ `a esquerda da raiz */
	 else
	    xd = xm;	      /* xm esta´ `a direita da raiz */
    //  erro = fabs(xe - xd);	 /* Calculo do erro absoluto 3 */
     fxm = fabs (f(xm));	 /* Calculo de f(xm) */
	 printf("Iteracao %5d	f(x): %10.6f\n", iter, fxm);
	 //printf("Iteracao %5d	erro: %10.6f\n", iter, erro); /*resultado com parada pelo erro*/
    }				 /*  Fim do loop */
    raiz = xm;
    printf("Convergiu apos %4d iteracoes para a raiz = %10.6f", iter, raiz);
    getch();
}

/*
    Definicao da funcao f(x)
*/

float f(float x)
{
      float fun;
      fun = exp(x) - 3*x;
      return(fun);
}
