#include <stdio.h>

struct money2
{
    int deposit;
    unsigned short numDeps;
    int withdraw;
    unsigned short numWithdraw;
};
struct money3
{
    int deposit;
    int withdraw;
    unsigned short numDeps;
    unsigned short numWithdraw;
};

struct money4
{
    int deposit;
    unsigned short numDeps;
    unsigned short numWithdraw;
};

struct money5
//12
{
    unsigned short A;
    unsigned short B;
    int C;
    int D;
};

struct money6
//12
{
    unsigned short A;
    int B;
    unsigned short C;
};

struct money7
//6
{
    unsigned short A;
    unsigned short B;
    unsigned short C;
};

int main(int argc, char *argv[])
{
    printf("%lu バイト\n", sizeof(int));
    printf("%lu バイト\n", sizeof(unsigned short));
    printf("%lu バイト\n", sizeof(struct money2));
    printf("%lu バイト\n", sizeof(struct money3));
    printf("%lu バイト\n", sizeof(struct money4));
    printf("%lu バイト\n", sizeof(struct money5));
    printf("%lu バイト\n", sizeof(struct money6));
    printf("%lu バイト\n", sizeof(struct money7));

    return 0;
}
//double 8
//unsigned short 2
//int 4
