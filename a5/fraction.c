#include <stdio.h>
#include <assert.h>
#include "fraction.h"

int abs(int n) {
    return n < 0 ? -n : n;
}

int gcd(int a, int b)
{
    if (a == 0){
        return b;
    }
    return gcd(b % a, a);
}

struct fraction reduceFraction(struct fraction a){
   
    int divisor = gcd(abs(a.numerator), abs(a.denominator));
    a.numerator /= divisor;
    a.denominator /= divisor;
    return a;
}

struct fraction fractionCreate(int numerator, int denominator){
    struct fraction a = {numerator, denominator};
  
    if(a.numerator < 0){
        a.numerator = a.numerator * -1;
        a.denominator = a.denominator * -1;
    }
    a = reduceFraction(a);
    return a;
}

int get_numerator(struct fraction a){
    return a.numerator;
}

int get_denominator(struct fraction a){
    return a.denominator;
}

struct fraction fractionAdd(struct fraction a, struct fraction b){
    struct fraction c = fractionCreate(a.numerator * b.denominator + b.numerator * a.denominator, b.denominator * a.denominator);
    return c;
}

struct fraction fractionSubtract(struct fraction a, struct fraction b){
    struct fraction c = fractionCreate(a.numerator * b.denominator - b.numerator * a.denominator, a.denominator * b.denominator);
    return c;
}

struct fraction fractionMultiply(struct fraction a, struct fraction b){
    struct fraction c = fractionCreate(a.numerator * b.numerator, a.denominator * b.denominator);
    return c;
}

struct fraction fractionDivide(struct fraction a, struct fraction b){
    struct fraction c = fractionCreate(a.numerator * b.denominator, a.denominator * b.numerator);
    return c;
}

