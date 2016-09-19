//
//  main.c
//  IDEA
//
//  Created by Pedro Jose Sobrevilla Moreno on 3/26/14.
//
//

#include "IDEA.h"


int main(int argc, const char * argv[])
{
    int i;
    
    int m[4];
    
    int k[8][6];
    int k9[4];
    
    int kd[8][6];
    int kd9[4];
    
    int res[4];
    int res1[4];
    int res2[4];
    
    LLave(k, k9);
    
    LLaved(k, k9, kd, kd9);
    printf("\n--------------------------- \n");
    imprime_matrizf(k);
    for (i=0; i<4; i++)
    {
        printf("[%d]",k9[i]);
    }
    printf("\n--------------------------- \n");
    imprime_matrizf(kd);
    for (i=0; i<4; i++)
    {
        printf("[%d]",kd9[i]);
    }
    printf("\n--------------------------- \n");
    
    m[0]=76;
    m[1]=97;
    m[2]=32;
    m[3]=115;
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", m[0], m[1], m[2], m[3]);
    
    printf("--------------------------- \n");
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
   
    
    /*
    m[0]=117;
    m[1]=101;
    m[2]=99;
    m[3]=97;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    
    m[0]= 032;
    m[1]=83;
    m[2]=97;
    m[3]=114;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    m[0]=97;
    m[1]=104;
    m[2]=32;
    m[3]=83;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    m[0]=106;
    m[1]=111;
    m[2]=115;
    m[3]=116;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    m[0]=114;
    m[1]=111;
    m[2]=109;
    m[3]=044;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    m[0]=32;
    m[1]=99;
    m[2]=111;
    m[3]=109;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    m[0]=112;
    m[1]=108;
    m[2]=101;
    m[3]=116;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);

    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    m[0]=195;
    m[1]=179;
    m[2]=32;
    m[3]=101;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    m[0]=108;
    m[1]=32;
    m[2]=115;
    m[3]=195;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    m[0]=161;
    m[1]=98;
    m[2]=97;
    m[3]=100;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    m[0]=111;
    m[1]=32;
    m[2]=115;
    m[3]=117;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    m[0]=32;
    m[1]=115;
    m[2]=101;
    m[3]=109;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    m[0]=97;
    m[1]=110;
    m[2]=97;
    m[3]=32;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    m[0]=109;
    m[1]=195;
    m[2]=161;
    m[3]=103;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    m[0]=105;
    m[1]=99;
    m[2]=97;
    m[3]=32;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    m[0]=99;
    m[1]=111;
    m[2]=110;
    m[3]=032;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    m[0]=101;
    m[1]=108;
    m[2]=32;
    m[3]=114;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    m[0]=195;
    m[1]=169;
    m[2]=99;
    m[3]=111;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    m[0]=114;
    m[1]=100;
    m[2]=32;
    m[3]=100;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    m[0]=101;
    m[1]=108;
    m[2]=32;
    m[3]=109;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    m[0]=117;
    m[1]=110;
    m[2]=100;
    m[3]=111;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    m[0]=32;
    m[1]=100;
    m[2]=101;
    m[3]=032;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    m[0]=053;
    m[1]=48;
    m[2]=32;
    m[3]=109;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    m[0]=97;
    m[1]=114;
    m[2]=105;
    m[3]=112;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    m[0]=111;
    m[1]=115;
    m[2]=97;
    m[3]=44;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    m[0]=32;
    m[1]=50;
    m[2]=52;
    m[3]=46;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    m[0]=52;
    m[1]=51;
    m[2]=44;
    m[3]=32;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    m[0]=102;
    m[1]=105;
    m[2]=114;
    m[3]=109;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    m[0]=97;
    m[1]=100;
    m[2]=111;
    m[3]=115;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    m[0]=32;
    m[1]=101;
    m[2]=110;
    m[3]=32;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    m[0]=108;
    m[1]=111;
    m[2]=115;
    m[3]=32;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    m[0]=78;
    m[1]=97;
    m[2]=99;
    m[3]=105;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    m[0]=111;
    m[1]=110;
    m[2]=97;
    m[3]=108;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    m[0]=101;
    m[1]=115;
    m[2]=32;
    m[3]=115;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    m[0]=117;
    m[1]=101;
    m[2]=99;
    m[3]=111;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    m[0]=115;
    m[1]=046;
    m[2]=0;
    m[3]=0;
    
    printf("--------------------------- \n");
    
    IDEA(m, k, k9,res);
    
    printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
    
    printf("--------------------------- \n");
    
    IDEA(res, kd, kd9, res1);
    
    printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
    
    
    
    
    clock_t t, t1;
    LLave(k, k9);
    
    printf("\n---------------------------- \n");
    
    LLaved(k, k9, kd, kd9);
    
    t1 = clock();
    printf ("calculando...\n\n");
    
    for (j=0; j<10; j++)
    {
        t = clock();
        printf ("calculando...\n\n");
        
        for (i=0; i<4; i++)
        {
            m[i]=arc4random()%MAXN;
            //printf("x%d = %d ",i,m[i]);
        }
        
        //printf("\n--------------------------- \n");
        
        IDEA(m, k, k9,res);
        
        printf("%d, %d, %d, %d \n", res[0], res[1], res[2], res[3]);
        
        //printf("--------------------------- \n");
        
        IDEA(res, kd, kd9, res1);
        
        printf("%d, %d, %d, %d \n", res1[0], res1[1], res1[2], res1[3]);
        
        t = clock() - t;
        printf ("\nMe tarde %lu clicks (%f segundos).\n",t,((float)t)/CLOCKS_PER_SEC);
    }
    
    t1 = clock() - t1;
    printf ("\nMe tarde %lu clicks (%f segundos).\n",t1,((float)t1)/CLOCKS_PER_SEC);
    */
    return 0;
}

