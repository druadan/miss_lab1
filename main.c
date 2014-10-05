#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>


void print_fraction(mpz_t dividend, mpz_t divisor,  int d) {
    mpz_t quotient;
    mpz_t remainder;
    mpz_init(quotient);
    mpz_init(remainder);

    mpz_tdiv_qr(quotient, remainder, dividend, divisor);
    gmp_printf("%Zd", quotient);
    if(mpz_cmp_si(remainder,0) != 0){
        gmp_printf(".");
        mpz_abs(divisor,divisor);
        mpz_abs(remainder,remainder);
        int i;

        for(i=0;i<d && mpz_cmp_si(remainder,0) != 0;i++){
            mpz_mul_ui(remainder,remainder,10);  
            mpz_tdiv_qr(quotient, remainder, remainder, divisor);
            gmp_printf("%Zd", quotient);
        }
    }
    return;
}

void process(int d){
    mpz_t x;
    mpz_t sum;
    mpz_t count;
    mpz_init(x);
    mpz_init(sum);
    mpz_init(count);

    while (gmp_scanf("%Zd", x) > 0) {
        mpz_add_ui(count,count,1);
        mpz_add(sum,sum,x);
    }
    print_fraction(sum, count, d);
    gmp_printf("\n");

}

int main (int argc, char* argv[])
{
    if(argc == 2){ 
        int d = atoi(argv[1]);
        process(d);
    }else{
        printf("Wrong arguments count");
    }

    return 0;
}
