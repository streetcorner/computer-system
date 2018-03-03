#include <iostream>
#include <string.h>
#include <ctime>
#include <cmath>
#include <unistd.h>


using namespace std;
#define N 500
#define B 500


/* Multiply n x n matrices a and b  */
void mmm(double *a, double *b, double *c, int n) {
    int i, j, k, i1, j1, k1,sum,in;

    for (i = 0; i < n; i+=B)
        for (j = 0; j < n; j+=B)
            for (k = 0; k < n; k+=B)
		 /* B x B mini matrix multiplications */
                  for (i1 = i; i1 < i+B; ++i1){
                        in = i1 * n;
                        for (j1 = j; j1 < j+B; ++j1){
                            for (k1 = k; k1 < k+B; k1+=2){
                                c[in+j1] += a[in + k1] * b[k1*n + j1] + a[in + k1+1] * b[(k1+1)*n + j1];
                            }
                      }
                  }



}


int main(){
        double *a =new double[N*N];
        double *b =new double[N*N];
        double *c =new double[N*N];
        int tmp=N*N, i;
        for (i = 0; i < tmp; ++i)
           c[i]=0.0;

        clock_t time0,time1;
        time0 =clock();
        //cout<<"aaaa"<<endl;
        mmm(a, b, c, N);
        time1= clock();

        cout<<(double)(time1-time0)/CLOCKS_PER_SEC <<endl;

        delete[] a;
        delete[] b;
        delete[] c;
}
