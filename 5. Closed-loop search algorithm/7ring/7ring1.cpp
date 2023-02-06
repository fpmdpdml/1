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

    OpenFile.open("C:\\lammps/final/23/6ring/2.txt");
    short int array[11975];

    for (int j=1; j<11975; j++)
    {
        string ch;
        OpenFile>>ch;
        array[j]=convertToInt(ch);
    }
    OpenFile.close();

    short int anew3[38001];
    short int bnew3[38001];
    short int cnew3[38001];
    short int dnew3[38001];
    short int enew3[38001];
    short int fnew3[38001];

    OpenFile.open("C:\\lammps/final/23/6ring/51.txt");

    for (int a=1; a<38001; a++)
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


    short int anew4[68346];
    short int bnew4[68346];
    short int cnew4[68346];
    short int dnew4[68346];
    short int enew4[68346];
    short int fnew4[68346];
    short int gnew4[68346];

    int index3=1;
    int index4=1;


    for (int index3=1; index3<38001; index3++)
    {
        for (int p=1; p<11975; p++)
        {
            if ((p%2==1) && fnew3[index3]==array[p] && enew3[index3]!=array[p+1] && dnew3[index3]!=array[p+1] && bnew3[index3]!=array[p+1] &&  cnew3[index3]!=array[p+1] &&  anew3[index3]!=array[p+1])
            {
                anew4[index4]=anew3[index3];
                bnew4[index4]=bnew3[index3];
                cnew4[index4]=cnew3[index3];
                dnew4[index4]=dnew3[index3];
                enew4[index4]=enew3[index3];
                fnew4[index4]=fnew3[index3];
                gnew4[index4]=array[p+1];
                index4+=1;
            }

            else if ((p%2==0) && fnew3[index3]==array[p] && enew3[index3]!=array[p-1] && dnew3[index3]!=array[p-1] && bnew3[index3]!=array[p-1] &&  cnew3[index3]!=array[p-1] &&  anew3[index3]!=array[p-1])
            {
                anew4[index4]=anew3[index3];
                bnew4[index4]=bnew3[index3];
                cnew4[index4]=cnew3[index3];
                dnew4[index4]=dnew3[index3];
                enew4[index4]=enew3[index3];
                fnew4[index4]=fnew3[index3];
                gnew4[index4]=array[p-1];
                index4+=1;
            }
        }
    }
    fstream Out;
    Out.open("C:\\lammps/final/23/6ring/61.txt");
    for (int index1=1; index1<68346; index1++)
    {
        /*Out<<"topo addbond "<<anew4[index1]<<" "<<bnew4[index1]<<" "<<endl;
        Out<<"topo addbond "<<bnew4[index1]<<" "<<cnew4[index1]<<" "<<endl;
        Out<<"topo addbond "<<cnew4[index1]<<" "<<dnew4[index1]<<" "<<endl;
        Out<<"topo addbond "<<dnew4[index1]<<" "<<enew4[index1]<<" "<<endl;
        Out<<"topo addbond "<<dnew4[index1]<<" "<<anew4[index1]<<" "<<endl;*/
        //Out<<"topo "<<anew[index1]<<" "<<bnew[index1]<<" "<<cnew[index1]<<endl;
        //Out<<"topo "<<anew3[index1]<<" "<<bnew3[index1]<<" "<<cnew3[index1]<<" "<<dnew3[index1]<<" "<<enew3[index1]<<endl;

        Out<<anew4[index1]<<" "<<bnew4[index1]<<" "<<cnew4[index1]<<" "<<dnew4[index1]<<" "<<enew4[index1]<<" "<<fnew4[index1]<<" "<<gnew4[index1]<<endl;

    }
    Out.close();
    /*
    Out.open("C:\\lammps/final/23/4.txt");
    for (int index2=1; index2<26991; index2++)
    {
        Out<<<<anew2[index2]<<" "<<bnew2[index2]<<" "<<cnew2[index2]<<" "<<dnew2[index2]<<endl;
    }
    */

    //for (int k=1; k<4265; k++)

    //cout<<array[1]<<endl;
    return 0;

}

