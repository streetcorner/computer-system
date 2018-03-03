#include <iostream>
#include <ctime>

using namespace std;


const int SrcW=2000;
const int SrcH=3000;

unsigned char *Src =new unsigned char[SrcW*SrcH];
unsigned char *Dest =new unsigned char[SrcW*SrcH];
//按照原图现行后列
int main(){

    int DstH=SrcW;
    int DstW=SrcH;
    int StrideS=SrcW;
    int StrideD=SrcH;

    clock_t time1,time2;
    /*
    time0 =clock();

    for (int Y = 0; Y < SrcH; Y++)
    {
        //cout<<Y<<endl;
        unsigned char *LinePS = Src + Y * StrideS;
        unsigned char *LinePD = Dest + Y;
        //cout<<Y<<endl;
        for (int X = 0; X < SrcW; X++)
        {
           // cout<<X<<endl;
            LinePD[0] = LinePS[X];
            LinePD += StrideD;
        }
    }
    */
    //display source
    time1 =clock();
    //按照目的图先行后列，更快一些
    int X, Y;
    for (Y = 0; Y < DstH; ++Y)
    {
        unsigned char *LinePS = Src + Y;
        unsigned char *LinePD = Dest + Y * StrideD;
        unsigned char tmp= LinePS[0];
        for (X = 0; X < DstW; X+=2)
        {
            LinePD[X] = tmp;
            LinePD[X+1]=tmp;
            LinePS += StrideS + StrideS;
        }
    }
    time2 =clock();
    //cout<<(double)(time1-time0)/CLOCKS_PER_SEC<<"   "
    cout<<(double)(time2-time1)/CLOCKS_PER_SEC <<endl;

}

