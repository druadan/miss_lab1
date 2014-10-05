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
    gmp_printf("\n");
    return;
}

void process(int d){
    mpz_t x;
    mpz_t sum;
    mpz_t sum2;
    mpz_t count;
    mpz_init(x);
    mpz_init(sum);
    mpz_init(sum2);
    mpz_init(count);

    while (gmp_scanf("%Zd", x) > 0) {
        mpz_add_ui(count,count,1);
        mpz_add(sum,sum,x);
        mpz_mul(x, x, x);
        mpz_add(sum2, sum2, x);
    }

    // print average
    print_fraction(sum, count, d);

    // print variation
    mpz_t count2;    // n^2
    mpz_t tmp1;      // Ex^2 * n
    mpz_t tmp2;      // (Ex)^2 
    mpz_t tmp3;      // Ex^2 * n - (Ex)^2 
    mpz_init(count2);
    mpz_init(tmp1);
    mpz_init(tmp2);
    mpz_init(tmp3);
    mpz_set(count2,count);
    mpz_mul(count2,count2,count2);

    mpz_mul(tmp1, sum2, count);
    mpz_mul(tmp2, sum, sum);
    mpz_sub(tmp3, tmp1, tmp2);

    print_fraction(tmp3, count2, d);


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
