/* 
 * File:   main.c
 * Author: sidereus
 *
 * Created on 27 de enero de 2016, 11:57
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "funtions.h"

main() {

    
    unsigned i, j, k, l, max;
    unsigned long aux1, aux2, cont;
    unsigned lim, size;
    unsigned short alpha, beta, gamma, aux;
    unsigned short q1, q2, w1, w2, y1, y2;
    size = 1000;
    unsigned Z[7][10];
    short unsigned uskey[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    
    unsigned short kn[ fuyi ] = { 0 };
    unsigned short kp[ fuyi ] = { 0 };
        
    unsigned short **xs;
    block *plain;
    block *cipher;
    block *plainp;
    block *cipherp;
    
    srand( time( NULL ) );
    plain   = ( block * ) malloc( size * sizeof( block ) );
    cipher  = ( block * ) malloc( size * sizeof( block ) );
    plainp  = ( block * ) malloc( size * sizeof( block ) );
    cipherp = ( block * ) malloc( size * sizeof( block ) );
    
    generaDiferencias();
    generaInversos();
    
    key(uskey, Z, round);
    
    for( i = 1; i <= round + 1; i++ ) {
        
        for( j = 1; j <= 6; j++ )
            printf("%8d ", Z[ j ][ i ]);
        
        printf("\n");
        
    }
    
    cont = generaPares( plain, plainp, cipher, cipherp, size, Z, round, 0 );
    printf("\nParejas estudiadas %d, porcentaje de exito %8.6f \n", cont, ( float )size * 100.0 / ( float )cont );
    
    
    for( i = 0 ; i < size ; i++ ){
        printf("i: %d \n", i);
        for( j = 0; j < fuyi; j++ ){
            if((diffM( mul( cipher[i].w0 , j ), mul( cipherp[i].w0 , j ))==0)){
                for( k = 0; k < fuyi; k++ ){
                    if( (diffS( ( cipher[i].w2 + k) & one, ( cipherp[i].w2 + k ) & one ) == 0) ){
                        kn[j]++;
                        kp[k]++;
                    }
                } 
            }
        }
    }
    
     max =  kn[ 0 ];
    for( i = 1; i < fuyi; i++ )
        if( kn[ i ] > max )
            max = kn[ i ];
    
    printf("max = %d \n",max);
    
    /*
    for( i = 0, aux1 = 0, aux2 = 0; i < fuyi; i++ )
        if( kn[ i ] == max )
            printf("%5d %4d %5d %4d \n", i, kn[ i ], 3072, kn[ 3072 ]);
        else if( kn[ i ] != 0 )
            aux1++;
        else
            aux2++;
    
    
        printf("%d %d \n", aux1, aux2);
    */    
        max =  kp[ 0 ];
    for( i = 1; i < fuyi; i++ )
        if( kp[ i ] > max )
            max = kp[ i ];
    
    printf("max = %d \n",max);
    
    /*
    for( i = 0, aux1 = 0, aux2 = 0; i < fuyi; i++ )
        if( kp[ i ] == max )
            printf("%5d %4d %5d %4d \n", i, kp[ i ], 3584, kp[ 3584 ]);
        else if( kp[ i ] != 0 )
            aux1++;
        else
            aux2++;
    
        printf("%d %d \n", aux1, aux2);
    */
    //for( i = 0; i < 4096; i++ )
    //    printf("indice %04X contador %4d contenido %04X \n", i, contadores[ i ], base12BI[ i ] );
      
    
    /*for( alpha = 0, aux1 = 0, aux2 = 0; alpha < 4096; alpha++ ) {
        
        printf("%4d %8.5f %12lld %12lld\n", alpha, ( float )alpha * 100.0 / 4096.0, aux1, aux2 );
        
        for( beta = 0; beta < 4096; beta++ ) {
            for( gamma = 0; gamma < 4096; gamma++ )
                for( j = 0, cont = 0; j < M[ 0 ][ 1 ]; j++ ) {
                    
                    q1 = q1s[ ( alpha ^ beta ) * 73 + j ];
                    y1 = y1s[ ( beta ^ gamma )* 73 + j ];
                    w1 = w1s[ ( beta ^ gamma ) * 73 + j ];
                    aux = (unsigned short)~alpha ^ 0xF000;
                    q2 = q2s[ (   aux ^ beta ) * 73 + j ];
                    aux = (unsigned short)~gamma ^ 0xF000;
                    y2 = y2s[ ( beta ^ aux )* 73 + j ];
                    w2 = w2s[ ( beta ^ gamma ) * 73 + j ];
                    if( ( ( ( q1 + q2 ) & one ) == 0 ) && ( ( ( y1 + y2 ) & one ) == 1 ) && ( ( w1 - w2 ) == -1 ) )
                        aux1++;
                    else
                        aux2++;
                    
                }
        }
                
    
        
    }*/
    
    //for( i = 0; i < fuyi; i++ ) 
    //    printf("%05d%c", c[ i ],  ( ( ( i + 1 ) % 512 ) == 0 ) ? '\n' : ' ' );


    printf("\n");

    /*
     * 
    printf("\n");
    
    // to generate decryption key blocks
    de_key(Z, DK);
            
    for( i = 1; i <= 9; i++ ) {
        
        for( j = 1; j <= 6; j++ )
            printf("%8d ", DK[j][i]);
        printf("\n");
        
    }
     * 
    void kernelPES( unsigned b1, unsigned b2, unsigned k1, unsigned k2, unsigned s1, unsigned s2 )
    printf("\n");
    
    
    
    
    // to encipher plaintext XX to ciphertext YY by key blocks Z 
    
    
    
    // to decipher ciphertext YY to TT by decryption key blocks DK 
    cip(YY, TT, DK);
     */

    return 0;
}
