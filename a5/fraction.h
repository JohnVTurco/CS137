#ifndef FRACTIONS_H
#define FRACTIONS_H

struct fraction {
    int numerator;  int denominator;
};

struct fraction fractionCreate(int numerator, int denominator);

int get_numerator(struct fraction a);

int get_denominator(struct fraction a);

struct fraction fractionAdd(struct fraction a, struct fraction b);

struct fraction fractionSubtract(struct fraction a, struct fraction b);

struct fraction fractionMultiply(struct fraction a, struct fraction b);

struct fraction fractionDivide(struct fraction a, struct fraction b);

#endif