#include<fstream>
#include<iostream>
using namespace std;
ifstream fin("spectacole.in");
ofstream fout("spectacole.out");

float start, stop;
int k, n, m=0, nr[100];
float O[100][2];


int citire()
{
fin>>start>>stop;
fin>>n;
for(int i=1; i<=n;i++)
{for(int j=1;j<=2;j++){fin>>O[i][j];}
nr[i]=i;}
fin>>k;
fin.close();
}

int sortare()
{
int aux, schimbat;
do{
schimbat=0;
for(int i=1;i<n;i++)
 if(O[nr[i]][2]>O[nr[i+1]][2]){aux=nr[i];
                            nr[i]=nr[i+1];
                            nr[i+1]=aux;
                            schimbat=1;}
} while (schimbat);
}

int compute(int n, int k)
{
int ora, minut, x;
for(int i=1;i<=n;i++)
    {
        x=O[nr[i]][2]*100;
        ora=x/100;
        minut=x%100+k;
        if(minut>=60)
        {
            ora++;
            minut=minut-60;
        }
        x=(ora*100+minut)/(float)100;
        O[nr[i]][2]=x;
    }
}

int rezolvare()
{
int ultimul=0;
for(int i=1;i<=n;i++){
if(O[nr[i]][1]>start && O[nr[i]][2]<stop){
 if(O[nr[i]][1]>=O[nr[ultimul]][2]){m++;
                                    ultimul=i;}}}
}

int main()
{
citire();
sortare();
compute(n, k);
rezolvare();
fout<<m;
fout.close();
return 0;
}
