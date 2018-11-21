#include <stdio.h>
#include <stdlib.h>

int reverse(int x);

int main()
{
    int output = reverse(1463847412);
    printf("%d\n", output);
}

int reverse(int x) {
    int min = -pow(2, 31);
    int max = pow(2, 31) - 1;
    int rev = 0;
    while (x != 0)
    {
        if (((x < 0) && (rev >= min / 10) && ((rev * 10) >= (min - x % 10))) || ((x > 0) && (rev <= max / 10) && ((rev * 10) <= (max - x % 10))))
        {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        else
            return 0;
    }
    return rev;
}
