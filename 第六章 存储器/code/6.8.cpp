#include<iostream>
#include<ctime>

using namespace std;

#define N 10000000

typedef struct{
    int vel[3];
    int acc[3];
} point;

point p[N];
//clock_t startTime1, endTime1,startTime2, endTime2,startTime3, endTime3;
void clear1(point *p, int n){
   // startTime1=clock();
    int i,j;
    for(i=0; i<n; i++){
        for(j=0; j<3; j++)
            p[i].vel[j]=0;
        for(j=0; j<3; j++)
            p[i].acc[j]=0;
    }
   // endTime1=clock();
}
void clear2(point *p, int n){
    //startTime2=clock();
    int i,j;
    for(i=0; i<n; i++){
        for(j=0; j<3; j++){
            p[i].vel[j]=0;
            p[i].acc[j]=0;
        }
    }
   // endTime2=clock();
}
void clear3(point *p, int n){
   // startTime3=clock();
    int i,j;
    for(j=0; j<3; j++){
        for(i=0; i<n; i++)
            p[i].vel[j]=0;
        for(i=0; i<n; i++)
            p[i].acc[j]=0;

    }
   // endTime3=clock();
}
int main(){


    clock_t time0, time1, time2, time3;

    time0 = clock();

    clear1(p, N);
    time1 = clock();

    clear2(p, N);
    time2 = clock();

    clear3(p, N);
    time3 = clock();

    cout<<(double)(time1-time0)/CLOCKS_PER_SEC <<" "<<(double)(time2-time1)/CLOCKS_PER_SEC <<" "<<(double)(time3-time2)/CLOCKS_PER_SEC <<" "<<endl;
/*
    cout << "Totle Time : " <<(double)(time3-time0) << "s" << endl;
    cout << "Totle Time : " <<(double)(time3-time0)/CLOCKS_PER_SEC << "s" << endl;


    cout<<(double)time0/ CLOCKS_PER_SEC<<" "<<(double)time1/ CLOCKS_PER_SEC<<" "<<(double)time2/ CLOCKS_PER_SEC
    <<" "<<(double)time3/ CLOCKS_PER_SEC <<endl;
*/
//    cout<<(double)startTime1/ CLOCKS_PER_SEC<<" "<<(double)endTime1/ CLOCKS_PER_SEC<<" "<<(double)startTime2/ CLOCKS_PER_SEC<<" "
   // <<(double)endTime2/ CLOCKS_PER_SEC<<" "<<(double)startTime3/ CLOCKS_PER_SEC<<" "<<(double)endTime3/ CLOCKS_PER_SEC<<" "<<endl;

}


