
#ifndef FUNCIONES_H
#define FUNCIONES_H

#ifdef __cplusplus
extern "C" {
#endif

#define maxim 65537                    // 2^16 + 1
#define fuyi  65536                    // 2^16
#define one   65535                    // vector uno (2^16 - 1) 0x0000FFFF
#define round 2    

typedef struct Q {
    unsigned short theta;
    unsigned short rho;
    unsigned short phi1;
    unsigned short phi2;
} qpleta;

typedef struct B {
    unsigned short w0;
    unsigned short w1;
    unsigned short w2;
    unsigned short w3;
} block;
    
void cip( block IN, block *OUT, unsigned Z[7][10], unsigned short n, int opc);
void key(short unsigned uskey[9], unsigned Z[7][10], unsigned short );
void de_key(unsigned Z[7][10], unsigned DK[7][10], unsigned );

unsigned inv(unsigned xin);
unsigned short inv2(unsigned short xin);
unsigned mul(unsigned a, unsigned b);
unsigned short mul2(unsigned a, unsigned b);

void kernelPES( unsigned b1, unsigned b2, unsigned k1, unsigned k2, unsigned s1, unsigned s2 );
void impBits( unsigned int , char c, int k );

unsigned diffS( unsigned a, unsigned b );
unsigned diffM( unsigned a, unsigned b );
unsigned potencia( unsigned b, unsigned e);
unsigned long generaPares( block plain[], block plainp[], block cipher[], block cipherp[],  unsigned size, unsigned Z[7][10], unsigned short n, int opc );
void generaTernas( unsigned short **xs, unsigned lim, int opt );
void generaQpletas( unsigned opc );
void generaDiferencias( void );
void generaInversos( void );

unsigned short diffPP[ fuyi ];
unsigned short invPP[ fuyi ];
short S[ 8 ] = { -1, 1, -3, 3, -5, 5, -7, 7 };
unsigned short t2[ 16 ] = { 17, 16, 15, 14, 13, 12, 11, 10,  9, 8, 7, 6, 5, 4, 3, 2 };
unsigned short r2[ 16 ] = { 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3 };

unsigned short    p2[ 8 ][ 16 ] = { {  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,  0 }, 
                                    { 15,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14 },
                                    {  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,  0,  1,  2 }, 
                                    { 13, 14, 15,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12 }, 
                                    {  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,  0,  1,  2,  3,  4 }, 
                                    { 11, 12, 13, 14, 15,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10 }, 
                                    {  7,  8,  9, 10, 11, 12, 13, 14, 15,  0,  1,  2,  3,  4,  5,  6 },
                                    {  9, 10, 11, 12, 13, 14, 15,  0,  1,  2,  3,  4,  5,  6,  7,  8 } };

unsigned short M[ 8 ][ 8 ] = {  {  0, 73, 36,  0,  0, 27,  2,  0 },
                                { 73,  0,  0, 36, 27,  0,  0,  2 },
                                { 36,  0,  0,  0, 18,  0,  0,  9 },
                                {  0, 36,  0,  0,  0, 18,  9,  0 },
                                {  0, 27, 18,  0,  0,  0,  0,  0 },
                                { 27,  0,  0, 18,  0,  0,  0,  0 },
                                {  2,  0,  0,  9,  0,  0,  0,  0 },
                                {  0,  2,  9,  0,  0,  0,  0,  0 } };

qpleta *box[ 8 ][ 8 ];

/* cifrado */

void cip( block IN, block *OUT, unsigned Z[7][10], unsigned short n, int opc ) {
    
    unsigned short r, x1, x2, x3, x4, kk, t1, t2, a;
    
    x1 = IN.w0;
    x2 = IN.w1;
    x3 = IN.w2;
    x4 = IN.w3;
    
    if( opc != 0 ) {
        printf("%8d %8d %8d %8d \t", x1, x2, x3, x4 );
        //impBits( x1, ' ', 16 );
        //impBits( x2, ' ', 16 );
        //impBits( x3, ' ', 16 );
        //impBits( x4, '\t', 16 );
        printf("Texto en plano \n");
        
    }
    
    for (r = 1; r <= n; r++) {
        
        x1 = mul(x1, Z[1][r]);
        x2 = mul(x2, Z[2][r]);
        
        x3 = (x3 + Z[3][r]) & one;
        x4 = (x4 + Z[4][r]) & one;
        
        kk = mul(Z[5][r], (x1^x3));
        t1 = mul(Z[6][r], (kk + (x2^x4)) & one);
        t2 = (kk + t1) & one;
        
        a  = x1^t1;
        x1 = x3^t1;
        x3 = a;
        a  = x2^t2;
        x2 = x4^t2;
        x4 = a;
        
        if( opc != 0 ) {
            printf("%8d %8d %8d %8d \t", x1, x2, x3, x4 );
            //impBits( x1, ' ', 16 );
            //impBits( x2, ' ', 16 );
            //impBits( x3, ' ', 16 );
            //impBits( x4, '\t', 16 );
            printf("Fin ronda %2d \n", r);
        }
    }
    
    OUT -> w0 = (unsigned short) mul(x1, Z[1][n + 1]);
    OUT -> w1 = (unsigned short) mul(x2, Z[2][n + 1]);
    OUT -> w2 = (unsigned short) (x3 + Z[3][n + 1]) & one;
    OUT -> w3 = (unsigned short) (x4 + Z[4][n + 1]) & one;
    
    if( opc != 0 ) {
        printf("%8d %8d %8d %8d \t", OUT -> w0, OUT -> w1, OUT -> w2, OUT -> w3);
        //impBits( OUT -> w0, ' ', 16 );
        //impBits( OUT -> w1, ' ', 16 );
        //impBits( OUT -> w2, ' ', 16 );
        //impBits( OUT -> w3, '\t', 16 );
        printf("Ultima ronda %u \n", OUT);
    }
    
}


/* multiplicacion modulo 2^16+1 */
unsigned mul(unsigned a, unsigned b) {
    
    long int p;
    long unsigned q;
    
    if (a == 0) 
        p = maxim - b;
    else if (b == 0) 
        p = maxim - a;
    else {
        q = a*b;
        p = (q & one) - (q >> 16);
        if (p <= 0) 
            p = p + maxim;
    }
    return (unsigned) (p & one);
}




/* Algoritmo extedndido de Euclides */
unsigned inv(unsigned xin) {
    
    long n1, n2, q, r, b1, b2, t;
    
    if (xin == 0) 
        b2 = 0;
    else {
        n1 = maxim;
        n2 = xin;
        b2 = 1;
        b1 = 0;
        do {
            r = (n1 % n2);
            q = (n1 - r) / n2;
            if (r == 0) {
                if (b2 < 0) b2 = maxim + b2;
            } else {
                n1 = n2;
                n2 = r;
                t  = b2;
                b2 = b1 - q*b2;
                b1 = t;
            }
        } while (r != 0);
    }
    return (unsigned) b2;
}


/* Funcion para crear llaves */
void key(short unsigned uskey[8], unsigned Z[7][10], unsigned short n ) {
    
    short unsigned S[55];
    int i, j, r;
    
    
    for ( i = 0; i < 8; i++ ) S[ i ] = uskey[ i ];
    
    for ( i = 8; i < 55; i++ ) {
        
        if ((i + 2) % 8 == 0)
            S[i] = (S[i - 7] << 9)^(S[i - 14] >> 7);
        else if ((i + 1) % 8 == 0)
            S[i] = (S[i - 15] << 9)^(S[i - 14] >> 7);
        else
            S[i] = (S[i - 7] << 9)^(S[i - 6] >> 7);
        
    }
    
    
    for (r = 1; r <= n + 1; r++) 
        for (j = 1; j < 7; j++)
            Z[j][r] = S[6 * (r - 1) + j - 1];
}

void impBits( unsigned int n, char c, int k ) {
    
    int i;
    unsigned int mask = 0x80000000;
    
    for( i = 0; i < 32 - k; i++, mask >>=1 ); 
    
    for( ; i < 32 ; i++, mask >>= 1 )
        printf("%c", ( n & mask )? '1' : '0' );        
    
    printf("%c", c);
    
    return;
    
}

unsigned diffS( unsigned a, unsigned b ) { return ( a - b  ); }

unsigned diffM( unsigned a, unsigned b ) { return ( mul( a, inv(b) ) ); }

unsigned potencia( unsigned b, unsigned e) {
    
    if( e == 0 )
        return 1;
    else if( e == 1 )
        return b;
    else 
        return b * potencia( b, e - 1 );
    
}

/*
 * ESTOS NO SON LOS INVERSOSO MULTIPLICATIVOS !!!!
 */
void generaDiferencias( void ) {
    
    unsigned i;
    
    for (i = 0; i < fuyi; i++)
        diffPP[ i ] = (~i + 2) & one;
    
}

void generaInversos( void ) {
    
    unsigned i;
    
    for( i = 0; i < fuyi; i++ )
        invPP[ i ] = inv( i );
    
}

/*
 * generaPares, genera las parejas de textos en plano y cifrados
 
 */
unsigned long generaPares( block plain[], block plainp[], block cipher[], block cipherp[],  unsigned size, unsigned Z[7][10], unsigned short n, int opc ) {
    
    unsigned i;
    unsigned long cont;
    block plano1, plano2;
    block cifrado1, cifrado2;
    
    for( i = 0, cont = 0; i < size; cont++ ) {
        
        plano1.w0 = ( unsigned short ) rand();
        plano1.w1 = ( unsigned short ) rand();
        plano1.w2 = ( unsigned short ) rand();
        plano1.w3 = ( unsigned short ) rand();
        
        cip( plano1, &cifrado1, Z, n, 0 );
        
        plano2.w0 = diffPP[ plano1.w0 ];
        plano2.w1 = diffPP[ plano1.w1 ];
        plano2.w2 = plano1.w2;
        plano2.w3 = S[ 0 ] + plano1.w3;
        
        cip( plano2, &cifrado2, Z, n, 0 );
        
        if( ( diffM( cifrado1.w0, cifrado2.w0 ) ) == 0 && ( diffM( cifrado1.w1, cifrado2.w1 ) == 0 ) && (  diffS( cifrado1.w2, cifrado2.w2  ) ) == 0  && (  diffS( cifrado1.w3, cifrado2.w3 ) ) == S[ 1 ] ) {
            
            plain[ i ]   = plano1;
            plainp[ i ]  = plano2;
            cipher[ i ]  = cifrado1;
            cipherp[ i ] = cifrado2;

            i++;
            
            printf("Parejas encontradas %4d \r", i);
        
        }
        
    }
    
    printf("\n");
    
    if( opc != 0 )
        for( i = 0; i < size; i ++ ) {

            printf("%04X %04X %04X %04X\t",   plain[ i ].w0,   plain[ i ].w1,   plain[ i ].w2,   plain[ i ].w3 );
            printf("%04X %04X %04X %04X\t",  cipher[ i ].w0,  cipher[ i ].w1,  cipher[ i ].w2,  cipher[ i ].w3 );
            printf("%04X %04X %04X %04X\t",  plainp[ i ].w0,  plainp[ i ].w1,  plainp[ i ].w2,  plainp[ i ].w3 );
            printf("%04X %04X %04X %04X\t", cipherp[ i ].w0, cipherp[ i ].w1, cipherp[ i ].w2, cipherp[ i ].w3 );
            printf("%04X %04X %04X %04X\n", diffM( cipher[ i ].w0, cipherp[ i ].w0 ), diffM( cipher[ i ].w1, cipherp[ i ].w1 ), diffS( cipher[ i ].w2, cipherp[ i ].w2 ), diffS( cipher[ i ].w3, cipherp[ i ].w3 ) );        

        }
    
    return cont;
    
}

void generaTernas( unsigned short **xs, unsigned lim, int opt ) {
    
    unsigned i, j, k, cont, aux, base, maskB = 0x8000;

    xs[ 1 ] = (unsigned short *) malloc(4 * sizeof (unsigned short));
    xs[ 1 ][ 0 ] = 0;
    xs[ 1 ][ 1 ] = 1;
    xs[ 1 ][ 2 ] = maskB;
    xs[ 1 ][ 3 ] = maskB + 1;

    for (i = 2; i <= lim; i++) {

        xs[ i ] = (unsigned short *) malloc(potencia(2, i) * sizeof ( unsigned short));
        base = maskB >> (i - 1);
        cont = potencia(2, i - 1);

        for (j = 0; j < cont; j++) {

            aux = (j << (17 - i)) ^ base;
            xs[ i ][ 2 * j ] = aux;
            xs[ i ][ 2 * j + 1] = aux + 1;

        }

    }
    
    // se despliegan los resultados de x y t dado un tamaño del bloque, en 
    // este caso 8. Encontramos un patrón sumamente interesante, la generacion
    // de estas ternas comple con precision los resultados formulados por Masey
    // en la pagina 17 de su artículo. es posible generar todas estas ternas 
    // de una manera combinatoria (la usada en el programa principal)
    if( opt != 0 ) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {

                impBits(xs[ 1 ][ j ], ' ', 16);                 // Dado un x
                impBits(xs[ 1 ][ k ], ' ', 16);                 // exploras los t's
                impBits(xs[ 1 ][ j ] ^ xs[ 1 ][ k ], '\n', 16); // g's

            }
            printf("\n");
        }
        printf("\n");

        for (i = 2; i <= lim; i++) {

            cont = potencia(2, i);

            for (j = 0; j < cont; j++) {
                for (k = 0; k < cont; k++) {

                    impBits(xs[ i ][ j ], ' ', 16);
                    impBits(xs[ i ][ k ], ' ', 16);
                    impBits(xs[ i ][ j ] ^ xs[ i ][ k ], '\n', 16);

                }
                printf("\n");
            }
            printf("\n");
        }
    }
        
}

void generaQpletas( unsigned opc ) {
    
    unsigned i, j, k, cont;
    unsigned t1, r1, p1;
    short inicio, fin;
    
    for( j = 0; j < 8; j ++ )
        for( i = 0; i < 8; i ++ ) 
            if( M[ j ][ i ] != 0 )
                box[ j ][ i ] = ( qpleta * ) malloc( M[ j ][ i ] * sizeof( qpleta ) );
            else 
                box[ j ][ i ] = NULL;

    for (j = 0; j < 8; j++) {
        for (i = 0; i < 8; i++) {

            cont = 0;
            if (S[ i ] < 0) {
                inicio = 0;
                fin = 16 + S[ i ];
            } else {
                inicio = 0 + S[ i ];
                fin = 16;
            }

            for (t1 = 2; t1 < 16; t1++)
                for (r1 = 3; r1 < 16; r1++)
                    for (p1 = inicio; p1 < fin; p1++) {

                        if (((t1 ^ p1) + (t2[ t1 ] ^ p2[ i ][ p1 ])) == 16)
                            if (((p1 ^ r1) + (p2[ i ][ p1 ] ^ r2[ r1 ])) == 17)
                                if (((t1 ^ r1) - (t2[ t1 ] ^ r2[ r1 ])) == S[ j ] ) {
                                    
                                    
                                    box[ j ][ i ][ cont ].theta = t1;
                                    box[ j ][ i ][ cont ].rho   = r1;
                                    box[ j ][ i ][ cont ].phi1  = p1;
                                    box[ j ][ i ][ cont ].phi2  = p2[ i ][ p1 ];
                                    cont++;
                                    
                                }

                    }

            printf("%2d ", cont);

        }
        
    printf("\n");
    
    }
    
    // Solo está mostrando una pareja de entradas en M
    if( opc != 0 )
        for( i = 0; i < M[ 0 ][ 1 ]; i++ ) {
        
            impBits( box[ 0 ][ 1 ][ i ].theta, ' ', 4);
            impBits( box[ 0 ][ 1 ][ i ].rho, ' ', 4);
            impBits( box[ 0 ][ 1 ][ i ].phi1, ' ', 4);
            impBits( box[ 0 ][ 1 ][ i ].phi2, '\t', 4);
            impBits( box[ 1 ][ 0 ][ i ].theta, ' ', 4);
            impBits( box[ 1 ][ 0 ][ i ].rho, ' ', 4);
            impBits( box[ 1 ][ 0 ][ i ].phi1, ' ', 4);
            impBits( box[ 1 ][ 0 ][ i ].phi2, '\t', 4);
            impBits( box[ 0 ][ 1 ][ i ].theta - box[ 1 ][ 0 ][ i ].theta, ' ', 4 );
            impBits( box[ 0 ][ 1 ][ i ].rho   - box[ 1 ][ 0 ][ i ].rho, ' ', 4 );
            impBits( box[ 0 ][ 1 ][ i ].phi1  - box[ 1 ][ 0 ][ i ].phi2, ' ', 4 );
            impBits( box[ 0 ][ 1 ][ i ].phi2  - box[ 1 ][ 0 ][ i ].phi1, '\n', 4 );

        }
    
    for( i = 0, cont = 0; i < 8; i++ )
        for( j = 0; j < 8; j++ )            
            cont += M[ i ][ j ];
    
    printf("TOTAL qpletas %d \n", cont);
    
}



#ifdef __cplusplus
}
#endif

#endif /* FUNCIONES_H */

