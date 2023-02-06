#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

short int convertToInt(string s)
{
    istringstream i(s);
    short int x;
    if(i>>x)
    return x;
    return 0;
}

int main()
{
    fstream OpenFile;

    OpenFile.open("C:\\lammps/final/23/5ring/final/2.txt");
    short int array[11975];

    for (int j=1; j<11975; j++)
    {
        string ch;
        OpenFile>>ch;
        array[j]=convertToInt(ch);
    }
    OpenFile.close();

    short int anew3[37469];
    short int bnew3[37469];
    short int cnew3[37469];
    short int dnew3[37469];
    short int enew3[37469];
    short int fnew3[37469];

    OpenFile.open("C:\\lammps/final/23/5ring/final/52.txt");

    for (int a=1; a<37469; a++)
    {
        string ch1;
        string ch2;
        string ch3;
        string ch4;
        string ch5;
        string ch6;

        OpenFile>>ch1;
        anew3[a]=convertToInt(ch1);
        OpenFile>>ch2;
        bnew3[a]=convertToInt(ch2);
        OpenFile>>ch3;
        cnew3[a]=convertToInt(ch3);
        OpenFile>>ch4;
        dnew3[a]=convertToInt(ch4);
        OpenFile>>ch5;
        enew3[a]=convertToInt(ch5);
        OpenFile>>ch6;
        fnew3[a]=convertToInt(ch6);

    }
    OpenFile.close();


    short int anew4[3351];
    short int bnew4[3351];
    short int cnew4[3351];
    short int dnew4[3351];
    short int enew4[3351];
    short int fnew4[3351];
    short int gnew4[3351];

    int index3=1;
    int index4=1;


    for (int index3=1; index3<37469; index3++)
    {
        for (int p=1; p<11975; p++)
        {
            if ((p%2==1) && fnew3[index3]==array[p] && enew3[index3]!=array[p+1] && dnew3[index3]!=array[p+1] && bnew3[index3]!=array[p+1] &&  cnew3[index3]!=array[p+1] &&  anew3[index3]==array[p+1])
            {
                anew4[index4]=anew3[index3];
                bnew4[index4]=bnew3[index3];
                cnew4[index4]=cnew3[index3];
                dnew4[index4]=dnew3[index3];
                enew4[index4]=enew3[index3];
                fnew4[index4]=array[p];
                gnew4[index4]=array[p+1];
                index4+=1;
            }

            else if ((p%2==0) && fnew3[index3]==array[p] && enew3[index3]!=array[p-1] && dnew3[index3]!=array[p-1] && bnew3[index3]!=array[p-1] &&  cnew3[index3]!=array[p-1] &&  anew3[index3]==array[p-1])
            {
                anew4[index4]=anew3[index3];
                bnew4[index4]=bnew3[index3];
                cnew4[index4]=cnew3[index3];
                dnew4[index4]=dnew3[index3];
                enew4[index4]=enew3[index3];
                fnew4[index4]=array[p];
                gnew4[index4]=array[p-1];
                index4+=1;
            }
        }
    }



    fstream Out;
    Out.open("C:\\lammps/final/23/5ring/final/5f2.txt");
    for (int index1=1; index1<3351; index1++)
    {

        Out<<"topo addbond "<<anew4[index1]<<" "<<bnew4[index1]<<endl;
        Out<<"topo addbond "<<bnew4[index1]<<" "<<cnew4[index1]<<endl;
        Out<<"topo addbond "<<cnew4[index1]<<" "<<dnew4[index1]<<endl;
        Out<<"topo addbond "<<dnew4[index1]<<" "<<enew4[index1]<<endl;
        Out<<"topo addbond "<<enew4[index1]<<" "<<fnew4[index1]<<endl;
        Out<<"topo addbond "<<fnew4[index1]<<" "<<gnew4[index1]<<endl;

    }
    Out.close();

    return 0;

}

