#include <stdio.h>

int factorial(int n){
    int i;
    int total = 1;
    for(i = 0; i < n; i++){
        total *= n-i;
    }
    return total;
}

int sum_of_factorials(int n){
    int sum = 0;
    int i;
    while(n){
        sum += factorial(n%10);
        n /= 10;
    }
    return sum;
}

int check_numbers(int n){ //checks each number up to n for if n == sum_of_factorials(n). should hit a wall for large n
    int i;
    int total = 0;
    for(i = 10  ; i < n; i++){
        if(i == sum_of_factorials(i)){printf("%d\n\n", i);total += i;}
    }
    return total;
}

int main(){
    //9999999 is a reasonable upper bound as 7*9! < 999999999
    //therefore no numbers like 145 will be beyond that point
    printf("Total = %d", check_numbers(9999999));
    return 0;
}