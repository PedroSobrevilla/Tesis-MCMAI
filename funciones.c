//
//  funciones.c
//  IDEA
//
//  Created by Pedro Jose Sobrevilla Moreno on 5/13/14.
//
//

#include "IDEA.h"

void LLave(int k[8][6],int k9[4])
{
    int i;
    int j,l,m;
    int res;
    int aux, aux1;
    int Potencia[16];
    int sk[7][8];
    
    Potencia[0]=1;
    Potencia[1]=2;
    Potencia[2]=4;
    Potencia[3]=8;
    Potencia[4]=16;
    Potencia[5]=32;
    Potencia[6]=64;
    Potencia[7]=128;
    Potencia[8]=256;
    Potencia[9]=512;
    Potencia[10]=1024;
    Potencia[11]=2048;
    Potencia[12]=4096;
    Potencia[13]=8192;
    Potencia[14]=16384;
    Potencia[15]=32768;
    
    int llave[128];
    srand(time(NULL));
    
    //generacion aleatoria de la llave de 128 bits
    
    for (i=0; i<128; i++)
    {
        llave[i]=rand()%2;
        printf("%d", llave[i]);
    }
    
    // Subllaves para las primeras 8 rondas (48 subllaves)
    for (i=0; i<9; i++)
    {
        aux = 25*i;
        
        for (j=0; j<8; j++)
        {
            res = 0;
            if (aux > 127)
            {
                aux = aux%128;
            }
            
            aux1 = aux + (16*j);
            
            for (l = aux1; l < (aux1+16); l++)
            {
                if (l>127)
                {
                    m=l%128;
                    
                    if (llave[m]==0)
                    {
                        res = res + 0;
                    }
                    else
                    {
                        res = res + Potencia[aux1+15-l];
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
                        res = res + Potencia[aux1+15-l];
                    }
                }
            }
            
            sk[i][j]=res;
        }
    }
    printf("\n---------------------------- \n");
    imprime_matriz2f(sk);
    
    // Asignacion de llaves
    for (i=0; i<9; i++)
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
            for (j=0; j<6; j++)
            {
                k[i][j]=sk[2][j+2];
            }
        }
        else if(i==4)
        {
            for (j=0; j<6; j++)
            {
                k[i][j]=sk[3][j];
            }
        }
        else if (i==5)
        {
            k[i][0]=sk[3][6];
            k[i][1]=sk[3][7];
            for (j=0; j<4; j++)
            {
                k[i][j+2]=sk[4][j];
            }
        }
        else if (i==6)
        {
            for (j=0; j<4; j++)
            {
                k[i][j]=sk[4][j+4];
            }
            k[i][4]=sk[5][0];
            k[i][5]=sk[5][1];
        }
        else if (i==7)
        {
            for (j=0; j<6; j++)
            {
                k[i][j]=sk[5][j+2];
            }
        }
        else if (i==8)
        {
            for (j=0; j<4; j++)
            {
                k9[j]=sk[6][j];
            }
        }
    }
}

void LLaved(int k[8][6], int k9[4],int kd[8][6],int k9d[4])
{
    int i,j;
    
    for (i=0; i<6; i++)
    {
        if (i==0 || i==3)
        {
            kd[0][i]=AEE(k9[i],MAXM);
        }
        else if (i==1 || i==2)
        {
            kd[0][i]=-k9[i]+MAXN;
        }
        else if(i==4 || i==5)
        {
            kd[0][i]=k[7][i];
        }
    }
    
    for (i=1; i<8; i++)
    {
        for (j=0; j<6; j++)
        {
            if (j==0 || j==3)
            {
                kd[i][j]=AEE(k[8-i][j],MAXM);
            }
            else if (j==1)
            {
                kd[i][j]=(-k[8-i][j+1]+MAXN)%MAXN;
            }
            else if (j==2)
            {
                kd[i][j]=(-k[8-i][j-1]+MAXN)%MAXN;
            }
            else
            {
                kd[i][j]=k[7-i][j];
            }
        }
    }
    
    for (i=0; i<4; i++)
    {
        if (i==0 || i==3)
        {
            k9d[i]=AEE(k[0][i],MAXM);
        }
        else if (i==1 || i==2)
        {
            k9d[i]=-k[0][i]+MAXN;
        }
    }
}

void IDEA(int m[4], int K[8][6],int K9[4],int res[4])
{
    int i;
    int x1, x2, x3, x4;
    int e, f, g, h;
    int p, q;
    int r, s, t, u;
    
    x1 = m[0];
    x2 = m[1];
    x3 = m[2];
    x4 = m[3];
    
    for(i=0;i<8;i++)
    {
        
        e = prod(x1, K[i][0]);
        f = ((long)x2 + K[i][1]) % MAXN;
        g = ((long)x3 + K[i][2]) % MAXN;
        h = prod(x4, K[i][3]);
        
        p = e^g;
        q = f^h;
        
        
        r = prod(p, K[i][4]);
        s = ((long)r+q)%MAXN;
        t = prod(s, K[i][5]);
        u = ((long)t+r)%MAXN;
        
        x1 = e ^ t;
        x2 = g ^ t;
        x3 = f ^ u;
        x4 = h ^ u;
        
    }
    
    res[0] = prod(x1, K9[0]);
    res[1] = ((long)x3 + K9[1]) % MAXN;
    res[2] = ((long)x2 + K9[2]) % MAXN;
    res[3] = prod(x4, K9[3]);
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
    
    if (res==MAXN)
    {
        res=0;
    }
    
    return res;
}

long concatenate(long x, long y)
{
    unsigned long pow = 10;
    while(y >= pow)
        pow *= 10;
    return x * pow + y;
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

int AEE(long a, long b)
{
    long s,t,p,m,q,r,u,v,aux,aux1;
    
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

void imprime_matriz2f(int C[7][8])
{
    int i,j;
    for(i=0; i<7;i++)
    {
        for(j=0; j<8;j++)
        {
            printf("[%d]", C[i][j]);
        }
        printf("\n");
    }
}