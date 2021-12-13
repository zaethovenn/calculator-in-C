#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
double Logn(double n, double r)
{
    return (n > r - 1) ? 1 + Logn(n / r, r) : 0;
}

int binAddition(int a, int b)
{
    int c;
    while (b != 0) {
        c = (a & b) << 1;
        a = a ^ b;
        b = c;
    }
    return a;
}

int binSubtracton(int a, int b)
{
    int carry;
    b = binAddition(~b, 1);

    while (b != 0) {
        carry = (a & b) << 1;
        a = a ^ b;
        b = carry;
    }
    return a;
}

int divide(int x, int y){
    if (y == 0){
        printf("Error!! Divisible by 0");
        exit(-1);
    }
    int sign = 1;
    if (x * y < 0) {
        sign = -1;
    }
    x = abs(x), y = abs(y);
    int quotient = 0;
    while (x >= y){
        x = x - y;
        quotient++;
    }
    printf("The remainder is %d\n", x);
    return sign * quotient;
}

int main() {
  int binAdd, binSub;
  char op;
  double first, second;
  double logged;
  long double result = 1.0;
  printf("Enter an operator (+, -, *, /, ^, &): ");
  scanf("%c", &op);
  printf("Enter two operands: ");
  scanf("%lf %lf", &first, &second);
  double n = first;
  double r = second;
  int x = first;
  int y = second;
  int product = 0;
  int dividend = first;
  int divisor = second;

  switch (op) {
    case '+':
      binAdd = binAddition(first, second);
      printf("Binary Addition: %d\n", binAdd);
      break;
    case '-':
      binSub = binSubtracton(first, second);
      printf("Binary Subtraction: %d\n", binSub);
      break;
    case '*':
      while(y != 0){
        product += x;
        y--;
      }
      printf("\nProuduct = %d\n", product);
      break;
    case '/':
      printf("The quotient is %d\n", divide(dividend, divisor));
      break;
    case '^':
      while (second != 0) {
        result *= first;
        --second;
      }
      printf("Answer = %.0Lf", result);
      break;
    case '&':
      printf("%f", Logn(n, r));
      break;

    // operator doesn't match any case constant
    default:
      printf("Error! operator is not correct");
  }
  return 0;
}
