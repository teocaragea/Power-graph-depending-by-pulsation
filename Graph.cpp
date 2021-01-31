#include <iostream>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;
int Lungime=GetSystemMetrics(SM_CXSCREEN);
int latime=GetSystemMetrics(SM_CYSCREEN);

///Graficul Puterii in functie de pulsatia , Caragea Theodor 11-E

int main()
{Lungime=1366;
    latime=720;
    initwindow(Lungime,latime,"Graficul Puterii in functie de pulsatie");
     int R=3;
     float U=141.42;
     U*=U;
    double L=6.36619,C=1.59154;
    L=L/1000;
    C=C/1000;
    int ok=0;
    double P1,P2;
    int w;
    line(0,latime-50,Lungime,latime-50);
    line(Lungime,latime-50,Lungime-30,latime-30);
    line(Lungime,latime-50,Lungime-30,latime-70);

    line(latime/2-100,latime,latime/2-100,0);
    line(latime/2-100,0,latime/2-80,30);
    line(latime/2-100,0,latime/2-120,30);
    settextstyle(1,0,1);
    outtextxy(latime/2-130,latime-40,"0");
    outtextxy(latime/2-140,20,"P");
    outtextxy(Lungime-60,latime-40,"w");

    for(w=0; w<=800; w++)
    {
        P1=(R*U)/(R*R+(w*L-1/(w*C))*(w*L-1/(w*C)));
        P1/=10;
        w++;
        P2=(R*U)/(R*R+(w*L-1/(w*C))*(w*L-1/(w*C)));
        P2/=10;
        if(w%100==0 && w!=300)
        { setcolor(15);
            setlinestyle(1,0,0);
             char *x;
            //itoa(w,x,10);
            sprintf(x,"%d",w);
            outtextxy(w+latime/2-115,latime-35,x);
            line(w+latime/2-99,0,w+latime/2-99,latime-50);
            if(w!=500)
            {line(latime/2-100,latime-P1-51,Lungime,latime-P1-51);
           // itoa(P1,x,10);
           sprintf(x,"%d",P1);
            outtextxy(latime/2-150,latime-P1-51,x);
            }

        }
        if(P2<P1 && ok==0)
        {char *x;
            ok=1;
            setcolor(15);
            setlinestyle(1,0,0);
            line(w+latime/2-99,0,w+latime/2-99,latime-50);
            line(latime/2-100,latime-P1-51,Lungime,latime-P1-51);
            sprintf(x,"%d",P1);
           // itoa(P1,x,10);
            outtextxy(latime/2-150,latime-P1-51,x);
            sprintf(x,"%d",w);
           /// itoa(w,x,10);
            outtextxy(w+latime/2-115,latime-35,x);
            int p;
            p=(int)P1;
           // itoa(p,x,10);
           sprintf(x,"%d",p);

        }
        w--;
        setcolor(4);
        line(w+latime/2-97,latime-P1-51,w+latime/2-96,latime-P2-51);
       /// delay(20);
        line(w+latime/2-97,latime-P1-50,w+latime/2-96,latime-P2-50);
      line(w+latime/2-97,latime-P1-52,w+latime/2-96,latime-P2-52);
    }

    system("pause");



    return 0;
}
