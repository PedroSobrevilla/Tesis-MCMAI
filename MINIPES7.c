
//
//  main.c
//  criptminipes
//
//  Created by Pedro Jose Sobrevilla Moreno on 5/11/15.
//
//

//
//  main.c
//  MINIPES
//
//  Created by Pedro Jose Sobrevilla Moreno on 3/10/15.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NRONDAS 8
#define MAXN 16
#define MAXM 17
#define NBITS 4
#define numClaro 100000
#define LTEXTO 64
#define N 3
#define M 6


int prod(int a, int b);
void PES(int m[4], int K[3][6],int K9[4], int res[4]);
int potencia(int numero, int potencia);
void LLave(int k[3][6],int k9[4]);
void LLaved(int k[3][6], int k9[4],int kd[3][6],int k9d[4]);
void imprime_matrizf(int C[N][M]);
void imprime_matriz2f(int C[3][8]);
void imprime_matriz3f(int C[10][4]);
int AEE(long a, long b);
void intabin(int x, int y[NBITS]);
void LLaveCrack(int k[3][6],int k9[4], int llave1, int llave2,
                int llave3, int llave4);

int main(int argc, const char * argv[])
{
    
    int i,j,l;
    
    int z1,z2,z3,z4;
    
    int x1,x2,v1,v2,t1,t2,e1,e2;
    
    int y1,y2,w1,w2,h1,h2,u1,u2,f1,f2;
    
    int difft,diffe;
    int diffF,diffu;
    int contador;
    int max;
    int maxllave1;
    int maxllave2;
    int maxllave3;
    int maxllave4;
    
    maxllave1=-1;
    maxllave2=-1;
    maxllave3=-1;
    maxllave4=-1;
    
    int X1[640];
    int V1[640];
    int T1[640];
    
    int H[MAXN];
    int Y1[1752];
    int W1[1752];
    int U1[1752];
    
    int kc[8][6];
    int kc9[4];
    
    int m[NBITS];
    int c[NBITS];
    int prueba[NBITS];
    
    for(i=0;i<4;i++)
    {
        m[i]=1;
    }
    
    for(i=0;i<4;i++)
    {
        prueba[i]=-1;
    }
    
    contador=0;
    
    for (x1=0; x1<MAXN; x1++)
    {
        for (v1=0; v1<MAXN; v1++)
        {
            for (t1=0; t1<MAXN; t1++)
            {
                x2=(1-x1)%MAXN;
                if (x2<0)
                {
                    x2=(MAXN+x2)%MAXN;
                }
                v2=v1;
                t2=x1^x2^t1;
                e1=v1^t1;
                e2=v2^t2;
                difft=(t1+t2)%MAXN;
                diffe=(e1+e2)%MAXN;
                if (difft==1 && diffe==1)
                {
                    X1[contador]=x2;
                    V1[contador]=v2;
                    T1[contador]=t2;
                    contador++;
                }
            }
        }
    }
    
    for (h1=0; h1<MAXN; h1++)
    {
        h2=h1-1;
        H[h1]=h2;
    }
    
    contador=0;
    
    for (y1=0; y1<MAXN; y1++)
    {
        for (w1=0; w1<MAXN; w1++)
        {
            for (u1=0; u1<MAXN; u1++)
            {
                for (h1=0; h1<MAXN; h1++)
                {
                    y2=(1-y1)%MAXN;
                    w2=(w1+1)%MAXN;
                    if (y2<0)
                    {
                        y2=(MAXN+y2)%MAXN;
                    }
                    u2=y1^y2^u1^h1^H[h1];
                    f1=u1^w1;
                    f2=u2^w2;
                    diffu=(u1+u2)%MAXN;
                    diffF=(f1+f2)%MAXN;
                    if (diffF==1 && diffu==2)
                    {
                        Y1[contador]=y2;
                        W1[contador]=w2;
                        U1[contador]=u2;
                        contador++;
                    }
                }
                
            }
        }
    }
    
    printf("%d\n",numClaro);
    
    int aee[MAXN]; //Arreglo para guardar los inversos
    
    for(i=1;i<MAXM;i++) //Se generan inversos
    {
        aee[i]=AEE(i,MAXM);
    }
    
    int aux1;
    int aux2;
    int aux3;
    int aux4;
    
    
    int TP1[numClaro][4];
    int TP2[numClaro][4];
    int TC1[numClaro][4];
    int TC2[numClaro][4];
    
    
    int aux[4];
    int auxc[4];
    
    int llave1[MAXN][MAXN];
    int llave2[MAXN][MAXN];
    
    srand(time(NULL));
    
    unsigned long fullStartTime = time(NULL);//Prueba inicio reloj
    
    int k[8][6];
    int k9[4];
    
    LLave(k, k9); //Se crean la llaves de cifrado y se imprimen
    
    printf("\n--------------------------- \n");
    imprime_matrizf(k);
    for (i=0; i<4; i++)
    {
        printf("[%d]",k9[i]);
    }
    printf("\n--------------------------- \n");
    
    PES(m,k,k9,c);
    
    contador=0;
    
    while(k9[0]!=maxllave1 || k9[2]!=maxllave2 ||
          k9[1]!=maxllave3 || k9[3]!=maxllave4)
    {
        
        for(i=0;i<MAXN;i++)
        {
            for (j=0; j<MAXN; j++)
            {
                llave1[i][j]=0;
                llave2[i][j]=0;
            }
        }
        
        
        for (i=0; i<numClaro; i++) //Arreglo aleatorio de textos en claro
        {
            for (j=0; j<4; j++)
            {
                TP1[i][j]=rand()%MAXN;
            }
        }
        
        for (i=0; i<numClaro; i++) //Se cifran los textos en claro aleatorios
        {
            for (j=0; j<4; j++)
            {
                aux[j] = TP1[i][j];
            }
            
            PES(aux, k, k9, auxc);
            
            for (l=0; l<4; l++)
            {
                TC1[i][l]=auxc[l];
            }
            
        }
        
        for (i=0; i<numClaro; i++) //La diferencia de entrada es (0,0,0,1)
                                   //entonces se crean textos en claro con
                                   //dicha diferencia
        {
            aux1 = (1-TP1[i][0])%MAXN;
            if (aux1<0)
            {
                aux1=MAXN+aux1;
            }
            aux2 = (1-TP1[i][1])%MAXN;
            if (aux2<0)
            {
                aux2=MAXN+aux2;
            }
            aux3 = TP1[i][2];
            aux4 = (TP1[i][3]+1)%MAXN;
            
            
            TP2[i][0]=aux1;
            TP2[i][1]=aux2;
            TP2[i][2]=aux3;
            TP2[i][3]=aux4;
        }
        
        for (i=0; i<numClaro; i++) // Se cifra el segundo arreglo de textos
                                   //en claro que cumplen la diferencia (0,0,0,1)
        {
            for (j=0; j<4; j++)
            {
                aux[j] = TP2[i][j];
            }
            
            PES(aux, k, k9, auxc);
            
            for (l=0; l<4; l++)
            {
                TC2[i][l]=auxc[l];
            }
        }
        
        printf("hola\n");
        
        
        
        for (i=0; i<numClaro; i++)
        {
            for (l=0; l<MAXN; l++)
            {
                z1=prod(TC1[i][0],aee[X1[l]]);
                z2=(TC1[i][2]-V1[l])%MAXN;
                if(z2<0)
                {
                    z2=MAXN+z2;
                }
                llave1[z1][z2]++;
            }
        }
        
        max=-1;
        maxllave1=0;
        maxllave2=0;
        
        for (i=0; i<MAXN; i++)
        {
            for (j=0; j<MAXN; j++)
            {
                if (llave1[i][j]>max)
                {
                    max = llave1[i][j];
                    maxllave1=i;
                    maxllave2=j;
                }
            }
        }
        
        printf("%d, %d \n",maxllave1,maxllave2);
        
        printf("llave real %d, contador %d\n",k9[0],maxllave1);
        printf("llave real %d, contador %d\n",k9[2],maxllave2);
        
        
        for (i=0; i<numClaro; i++)
        {
            for (l=0; l<MAXN; l++)
            {
                z3=prod(TC1[i][1],aee[Y1[l]]);
                z4=(TC1[i][3]-W1[l])%MAXN;
                if(z4<0)
                {
                    z4=MAXN+z4;
                }
                llave2[z3][z4]++;
            }
        }
        
        max=-1;
        maxllave3=0;
        maxllave4=0;
        
        for (i=0; i<MAXN; i++)
        {
            for (j=0; j<MAXN; j++)
            {
                if (llave1[i][j]>max)
                {
                    max = llave2[i][j];
                    maxllave3=i;
                    maxllave4=j;
                }
            }
        }
        
        printf("%d, %d \n",maxllave3,maxllave4);
        
        printf("llave real %d, contador %d\n",k9[1],maxllave3);
        printf("llave real %d, contador %d\n",k9[3],maxllave4);
        
        contador++;
        
        printf("contador=%d\n",contador);
    }
    
    while(c[0]!=prueba[0] || c[1]!=prueba[1] || c[2]!=prueba[2] || c[3]!=prueba[3])
    {
        LLaveCrack(kc, kc9, maxllave1,maxllave3,maxllave2,maxllave4);
        
        printf("\n--------------------------- \n");
    	
    	imprime_matrizf(kc);
        
    	for (i=0; i<4; i++)
    	{
            printf("[%d]",kc9[i]);
    	}
    	
    	printf("\n--------------------------- \n");
        
    	PES(m,kc,kc9,prueba);
        
    	for (i=0; i<4; i++)
    	{
            printf("%d ",prueba[i]);
    	}
    	
    	printf("\n");
    }
    
    printf("\n--------------------------- \n");
    imprime_matrizf(k);
    for (i=0; i<4; i++)
    {
        printf("[%d]",k9[i]);
    }
    printf("\n--------------------------- \n");
    
    
    
    for (i=0; i<4; i++)
    {
        printf("%d ",c[i]);
    }
    
    printf("\n--------------------------- \n");
    
    
    unsigned long fullEndTime = time(NULL); //termina el reloj
	printf("Tiempo total = %ld segundos\n", (fullEndTime - fullStartTime));
    //imprime el tiempo
    
    return 0;
}

void LLave(int k[3][6],int k9[4])
{
    int i;
    int j,l,m;
    int res;
    int aux, aux1;
    int sk[3][8];
    
    int llave[32];
    
    //generacion aleatoria de la llave de 128 bits
    
    for (i=0; i<32; i++)
    {
        llave[i]=rand()%2;
        printf("%d", llave[i]);
    }
    
    // Subllaves para las primeras 4 rondas (24 subllaves)
    for (i=0; i<3; i++)
    {
        aux = 6*i;
        
        for (j=0; j<8; j++)
        {
            res = 0;
            if (aux > 31)
            {
                aux = aux%32;
            }
            
            aux1 = aux + (4*j);
            
            for (l = aux1; l < (aux1+4); l++)
            {
                if (l>31)
                {
                    m=l%32;
                    
                    if (llave[m]==0)
                    {
                        res = res + 0;
                    }
                    else
                    {
                        res = res + (llave[m]*potencia(2, (aux1+3)-l));
                    }
                }
                else
                {
                    if (llave[l]==0)
                    {
                        res = res + 0;
                    }
                    else
                    {
                        res = res + (llave[l]*potencia(2, (aux1+3)-l));
                    }
                }
            }
            
            sk[i][j]=res;
        }
    }
    
    printf("\n---------------------------- \n");
    imprime_matriz2f(sk);
    
    for (i=0; i<4; i++)
    {
        if (i==0)
        {
            for (j=0; j<6; j++)
            {
                k[i][j]=sk[i][j];
            }
        }
        else if (i==1)
        {
            k[i][0]=sk[0][6];
            k[i][1]=sk[0][7];
            for (j=0; j<4; j++)
            {
                k[i][j+2]=sk[i][j];
            }
        }
        else if (i==2)
        {
            for (j=0; j<4; j++)
            {
                k[i][j]=sk[1][j+4];
            }
            k[i][4]=sk[2][0];
            k[i][5]=sk[2][1];
        }
        else if (i==3)
        {
            for (j=0; j<4; j++)
            {
                k9[j]=sk[2][j+2];
            }
        }
    }
}

void LLaved(int k[3][6], int k9[4],int kd[83][6],int k9d[4])
{
    int i,j;
    
    for (i=0; i<6; i++)
    {
        if (i==0 || i==1)
        {
            kd[0][i]=AEE(k9[i],MAXM);
        }
        else if (i==2 || i==3)
        {
            kd[0][i]=-k9[i]+MAXN;
        }
        else if(i==4 || i==5)
        {
            kd[0][i]=k[2][i];
        }
    }
    
    for (i=1; i<3; i++)
    {
        for (j=0; j<6; j++)
        {
            if (j==0 || j==1)
            {
                kd[i][j]=AEE(k[3-i][j],MAXM);
            }
            else if (j==2 || j==3)
            {
                kd[i][j]=(-k[3-i][j]+MAXN)%MAXN;
            }
            else
            {
                kd[i][j]=k[2-i][j];
            }
        }
    }
    
    for (i=0; i<4; i++)
    {
        if (i==0 || i==1)
        {
            k9d[i]=AEE(k[0][i],MAXM);
        }
        else if (i==2 || i==3)
        {
            k9d[i]=(-k[0][i]+MAXN)%MAXN;
        }
    }
}

void PES(int m[4], int K[8][6],int K9[4],int res[4])
{
    int i;
    int x1, x2, x3, x4,t0,t1,t2,a,b;
    //int e, f, g, h;
    //int p, q;
    //int r, s, t, u;
    
    x1 = m[0];
    x2 = m[1];
    x3 = m[2];
    x4 = m[3];
    
    for(i=0;i<3;i++)
    {
        x1 = prod(x1, K[i][0]);
        x2 = prod(x2, K[i][1]);
        x3 = (x3+K[i][2])%MAXN;
        x4 = (x4+K[i][3])%MAXN;
        
        t0 = prod(K[i][4], (x1^x3));
        t1 = prod(K[i][5], (t0+(x2^x4))%MAXN);
        t2 = (t0+t1)%MAXN;
        
        a = x1^t1;
        b = x2^t2;
        x1 = x3^t1;
        x2 = x4^t2;
        x3 = a;
        x4 = b;
        
        /*
         e = prod(x1, K[i][0]);
         f = prod(x2, K[i][1]);
         g = ((long)x3 + K[i][2]) % MAXN;
         h = ((long)x4 + K[i][3]) % MAXN;
         
         p = e^g;
         q = f^h;
         
         
         r = prod(p, K[i][4]);
         s = ((long)r+q)%MAXN;
         t = prod(s, K[i][5]);
         u = ((long)t+r)%MAXN;
         
         x1 = g ^ t;
         x2 = h ^ u;
         x3 = e ^ t;
         x4 = f ^ u;
         */
    }
    
    res[0] = prod(x1, K9[0]);
    res[1] = prod(x2, K9[1]);
    res[2] = ((long)x3 + K9[2]) % MAXN;
    res[3] = ((long)x4 + K9[3]) % MAXN;
}




int prod(int a, int b)
{
    int res;
    
    
    if (a==0 && b!=0)
    {
        res = ((long)MAXN*b)%MAXM;
    }
    else if (b==0 && a!=0)
    {
        res = ((long)MAXN*a)%MAXM;
    }
    else if (a==0 && b==0)
    {
        res = ((long)MAXN*MAXN)%MAXM;
    }
    else
    {
        res = ((long)a*b)%MAXM;
    }
    
    if(res==16)
    {
        res=0;
    }
    
    return res;
}


int potencia(int numero, int potencia)
{
    int i;
    int res;
    
    res=1;
    
    if (potencia==0)
    {
        return res;
    }
    else
    {
        for (i=0; i<potencia; i++)
        {
            res=res*numero;
        }
        return res;
    }
}

void imprime_matrizf(int C[N][M])
{
    int i,j;
    for(i=0; i<N;i++)
    {
        for(j=0; j<M;j++)
        {
            printf("[%d]", C[i][j]);
        }
        printf("\n");
    }
}

void imprime_matriz2f(int C[3][8])
{
    int i,j;
    for(i=0; i<3;i++)
    {
        for(j=0; j<8;j++)
        {
            printf("[%d]", C[i][j]);
        }
        printf("\n");
    }
}

void imprime_matriz3f(int C[10][4])
{
    int i,j;
    for(i=0; i<10;i++)
    {
        for(j=0; j<4;j++)
        {
            printf("[%d]", C[i][j]);
        }
        printf("\n");
    }
}

int AEE(long a, long b)
{
    long s,t,p,m,q,r,u,v,aux,aux1;
    
    if(a==0)
    {
        a = MAXN;
    }
    else if (b==0)
    {
        b=MAXN;
    }
    
    if (b>a)
    {
        aux1 = a;
        a = b;
        b = aux1;
    }
    
    aux = a;
    s = 1;
    t = 0;
    p = 0;
    m = 1;
    
    while (b != 0)
    {
        q = a/b;
        r = a%b;
        u = s - (q*p);
        v = t - (q*m);
        a = b;
        b = r;
        s = p;
        t = m;
        p = u;
        m = v;
    }
    
    if (t<0)
    {
        t = aux + t;
    }
    return (int)t;
}

void LLaveCrack(int k[3][6],int k9[4], int llave1, int llave2, int llave3, int llave4)
{
    int i;
    int j,l,m;
    int res;
    int aux, aux1;
    int sk[3][8];
    
    int llave[32];
    
    int z1[NBITS];
    int z2[NBITS];
    int z3[NBITS];
    int z4[NBITS];
    
    intabin(llave1,z1);
    intabin(llave2,z2);
    intabin(llave3,z3);
    intabin(llave4,z4);
    
    //generacion aleatoria de la llave de 128 bits
    
    for (i=0; i<32; i++)
    {
        llave[i]=rand()%2;
    }
    
    for(i=0;i<NBITS;i++)
    {
        llave[20+i]=z1[i];
    }
    
    for(i=0;i<NBITS;i++)
    {
        llave[24+i]=z2[i];
    }
    
    for(i=0;i<NBITS;i++)
    {
        llave[28+i]=z3[i];
    }
    
    for(i=0;i<NBITS;i++)
    {
        llave[i]=z4[i];
    }
    
    for (i=0; i<32; i++)
    {
        printf("%d", llave[i]);
    }
    
    // Subllaves para las primeras 4 rondas (24 subllaves)
    for (i=0; i<3; i++)
    {
        aux = 6*i;
        
        for (j=0; j<8; j++)
        {
            res = 0;
            if (aux > 31)
            {
                aux = aux%32;
            }
            
            aux1 = aux + (4*j);
            
            for (l = aux1; l < (aux1+4); l++)
            {
                if (l>31)
                {
                    m=l%32;
                    
                    if (llave[m]==0)
                    {
                        res = res + 0;
                    }
                    else
                    {
                        res = res + (llave[m]*potencia(2, (aux1+3)-l));
                    }
                }
                else
                {
                    if (llave[l]==0)
                    {
                        res = res + 0;
                    }
                    else
                    {
                        res = res + (llave[l]*potencia(2, (aux1+3)-l));
                    }
                }
            }
            
            sk[i][j]=res;
        }
    }
    
    printf("\n---------------------------- \n");
    imprime_matriz2f(sk);
    
    for (i=0; i<4; i++)
    {
        if (i==0)
        {
            for (j=0; j<6; j++)
            {
                k[i][j]=sk[i][j];
            }
        }
        else if (i==1)
        {
            k[i][0]=sk[0][6];
            k[i][1]=sk[0][7];
            for (j=0; j<4; j++)
            {
                k[i][j+2]=sk[i][j];
            }
        }
        else if (i==2)
        {
            for (j=0; j<4; j++)
            {
                k[i][j]=sk[1][j+4];
            }
            k[i][4]=sk[2][0];
            k[i][5]=sk[2][1];
        }
        else if (i==3)
        {
            for (j=0; j<4; j++)
            {
                k9[j]=sk[2][j+2];
            }
        }
    }
}

void intabin(int entero, int bin[NBITS])
{
    int i;
    
    for(i=0;i<NBITS;i++)
    {
        bin[i]=0;
    }
    
    i = NBITS-1;
    while(entero != 0)
    {
        bin[i]=entero%2;
        entero=entero/2;
        i--;
    }
}
