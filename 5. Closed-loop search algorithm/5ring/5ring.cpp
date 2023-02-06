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

    OpenFile.open("C:\\lammps/final/23/4ring/2.txt");
    short int array[11974];

    for (int j=1; j<11975; j++)
    {
        string ch;
        OpenFile>>ch;
        array[j]=convertToInt(ch);
    }
    OpenFile.close();

    short int anew[11229];
    short int bnew[11229];
    short int cnew[11229];
    short int anew2[21167];
    short int bnew2[21167];
    short int cnew2[21167];
    short int dnew2[21167];

    short int anew3[39997];
    short int bnew3[39997];
    short int cnew3[39997];
    short int dnew3[39997];
    short int enew3[39997];

    int index1=1;
    int index2=1;
    int index3=1;
    int index4=1;



    int index0=1;
    for (int l=1; l<11975; l++)
    {
        for (int m=l+1; m<11975; m++)
        {
            if ((array[l]==array[m]) && (l%2==1) && (m%2==1) && (array[l]!=array[m+1]))
            {
                anew[index1]=array[l+1];
                bnew[index1]=array[l];
                cnew[index1]=array[m+1];
                index1+=1;

            }
            else if ((array[l]==array[m]) && (l%2==1) && (m%2==0) && (array[l]!=array[m-1]))
            {
                anew[index1]=array[l+1];
                bnew[index1]=array[l];
                cnew[index1]=array[m-1];
                index1+=1;
            }
            else if ((array[l]==array[m]) && (l%2==0) && (m%2==1) && (array[l-1]!=array[m+1]))
            {
                anew[index1]=array[l-1];
                bnew[index1]=array[l];
                cnew[index1]=array[m+1];
                index1+=1;
            }
            else if ((array[l]==array[m]) && (l%2==0) && (m%2==0) && (array[l-1]!=array[m-1]))
            {
                anew[index1]=array[l-1];
                bnew[index1]=array[l];
                cnew[index1]=array[m-1];
                index1+=1;
            }
        }
    }
    for (int index1=1; index1<11229; index1++)
    {
        for (int n=1; n<11975; n++)
        {
            if ((n%2==1) && cnew[index1]==array[n] && bnew[index1]!=array[n+1] &&  anew[index1]!=array[n+1])
            {
                anew2[index2]=anew[index1];
                bnew2[index2]=bnew[index1];
                cnew2[index2]=cnew[index1];
                dnew2[index2]=array[n+1];
                index2+=1;
            }
            else if ((n%2==0) && cnew[index1]==array[n] && bnew[index1]!=array[n-1] &&  anew[index1]!=array[n-1])
            {
                anew2[index2]=anew[index1];
                bnew2[index2]=bnew[index1];
                cnew2[index2]=cnew[index1];
                dnew2[index2]=array[n-1];
                index2+=1;
            }
        }
    }

    for (int index2=1; index2<21167; index2++)
    {
        for (int o=1; o<11975; o++)
        {
            if ((o%2==1) && dnew2[index2]==array[o] && bnew2[index2]!=array[o+1] &&  cnew2[index2]!=array[o+1] &&  anew2[index2]!=array[o+1] && bnew2[index2]!=cnew2[index2] && cnew2[index2]!=dnew2[index2] && anew2[index2]!=array[o+1])
            {
                anew3[index3]=anew2[index2];
                bnew3[index3]=bnew2[index2];
                cnew3[index3]=cnew2[index2];
                dnew3[index3]=dnew2[index2];
                enew3[index3]=array[o+1];
                index3+=1;
            }
            else if ((o%2==0) && dnew2[index2]==array[o] && bnew2[index2]!=array[o-1] &&  cnew2[index2]!=array[o-1] &&  anew2[index2]!=array[o-1] && bnew2[index2]!=cnew2[index2] && cnew2[index2]!=dnew2[index2]  && anew2[index2]!=array[o-1])
            {
                anew3[index3]=anew2[index2];
                bnew3[index3]=bnew2[index2];
                cnew3[index3]=cnew2[index2];
                dnew3[index3]=dnew2[index2];
                enew3[index3]=array[o-1];
                index3+=1;
            }
        }
    }

    fstream Out;
    Out.open("C:\\lammps/final/23/4ring/4.txt");
    for (int index1=1; index1<39997; index1++)
    {

        Out<<anew3[index1]<<" "<<bnew3[index1]<<" "<<cnew3[index1]<<" "<<dnew3[index1]<<" "<<enew3[index1]<<endl;
    }
    Out.close();

    return 0;

}

