#include <iostream>
#include <string.h>
#include <ctime>
#include <cmath>
#include <unistd.h>


using namespace std;
#define M 8192
#define N 8192
int main(){

   // while(n<=4096){
        int **a;
        int **b;

       int i,j,ans=0;
       a=new int*[M];
        for(i=0; i<M; ++i){
            a[i]=new int[N];
        }
        b=new int*[M];
        for(i=0; i<M; ++i){
            b[i]=new int[N];
        }

        clock_t time0,time1;
        time0 =clock();

        int sum=0, tmp;
        /*improvement*/
        for(i=0; i<M; ++i){
            for(j=0; j<N; ++j){
                    tmp=a[i][j]-b[i][j];
                   sum += tmp*tmp;
            }
        }
        /*
        for(j=0; j<N; j++){
            for(i=0; i<M; i++){
                   sum += (a[i][j]-b[i][j])*(a[i][j]-b[i][j]);
            }
        }
        */
        ans=sum/(M*N);
        time1= clock();
        cout<<(double)(time1-time0)/CLOCKS_PER_SEC <<endl;

   // }
       for(int i = 0; i < M; ++i)
            delete [] a[i];
        delete []a;
}
