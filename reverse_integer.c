#include <stdio.h>
#include <limits.h>

int pow(int x,int y){
    if(y==0) return 1;
    
    int result = 1;
    int i;
    for(i=0;i<y;i++){
        if(UINT_MAX/x < result){
            return 0;
        }
        result = result * x;
    }
    return result;
}

int reverse(int x) {
    int arr[10];
    int i=0;
    int negative = 0;
    if(x<0){
        x = -x;
        negative = 1;
    }
    while(x>0){
        arr[i++]=x%10;
        x=x/10;
    }
    int n=0;
    int j;
    for(j=0;j<i;j++){
        int power = pow(10,i-j-1);
        if(power==0){
            return 0;
        }
        if(UINT_MAX/power<arr[j]){
            return 0;
        }
        if(INT_MAX-arr[j]*power<n){
            return 0;
        }
        n+=arr[j]*(pow(10,i-j-1));
    }
    if(negative) n=-n;
    return n;
}
