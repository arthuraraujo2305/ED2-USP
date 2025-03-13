#include <stdio.h>
#include <limits.h>

#define MAX 10

int resolve(int n, int v[]){
    int sparc, smax;
    smax = INT_MIN;
    for (int i = 0; i < n; i++){
        sparc = 0;
        for (int j = i; j < n; j++){
            sparc += v[j];
            if (sparc > smax){
                smax = sparc;
            }
        }
    }
    return smax;

}
int main(){
    int n, v[MAX];
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    printf("%d\n", resolve(n, v));
    return 0;
}