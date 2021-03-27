#include<stdio.h>
#include<math.h>

const long double PI = M_PI;
long double f(long double x) {
    long double y = 4 / (1 + x * x);
    return y;
}

int main() {
    int intervals = 256;
    printf("#intervals \t approximation \t error\n");
    while(intervals <= 1e9)
    {
        intervals *= 2;
        long double dx = 1.0 / intervals;
        long double approx = 0, x = 0;
        for(int i = 0; i < intervals; i++) {
            approx += f(x) * dx;
            x += dx;
        }
        long double error = approx - PI;
        printf("%10d \t%.12Lf  %.2Le\n", intervals, approx, error);
    }
}