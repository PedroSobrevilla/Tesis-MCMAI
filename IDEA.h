//
//  IDEA.h
//  IDEA
//
//  Created by Pedro Jose Sobrevilla Moreno on 6/3/14.
//
//

#ifndef IDEA_IDEA_h
#define IDEA_IDEA_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NRONDAS 8
#define MAXN 65536
#define MAXM 65537
#define LTEXTO 64
#define N 8
#define M 6

int prod(int a, int b);
void IDEA(int m[4], int K[8][6],int K9[4], int c[4]);
long concatenate(long x, long y);
void LLave(int k[8][6],int k9[4]);
void LLaved(int k[8][6], int k9[4],int kd[8][6],int k9d[4]);
void imprime_matrizf(int C[N][M]);
void imprime_matriz2f(int C[6][8]);
int AEE(long a, long b);


#endif
