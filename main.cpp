#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <vector>

using std::cout;
using std::ifstream;

int main()
{
    ifstream df ("thing.off");
    std::string a;
    int v, f;
    getline(df,a);
    df>>v;
    df>>f;
    for(int i=0; i<=v; i++)
    {
        getline(df,a);
    }
    std::vector<int> poros[2];
    std::vector<int> temp;
    int e; //kol kas e pades irasinet i vektoriu
    for(int i=0; i<f; i++)
    {
        df>>e;
        temp.push_back(e);
        for(int j=0; j<temp[0]; j++)
        {
            df>>e;
            temp.push_back(e);
        }
        for(int j=1; j<temp[0]; j++)
        {
            poros[0].push_back(temp[j]);
            poros[1].push_back(temp[j+1]);
        }
        poros[0].push_back(temp[1]);
        poros[1].push_back(temp.back());
        temp.clear();
    }
    df.close();
    e=poros[0].size(); // cia e tampa poru/briaunu skaiciumi
    for(int i=0; i<e; i++)
    {
        for(int j=i+1; j<e; j++)
        {
            if((poros[0][i]==poros[1][j] && poros[1][i]==poros[0][j]) || (poros[0][i]==poros[0][j] && poros[1][i]==poros[1][j]))
            {
                poros[0].erase(poros[0].begin()+j);
                poros[1].erase(poros[1].begin()+j);
                e--;
                j--;
            }
        }
    }
    bool Incidence[v][e];
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<e; j++)
        {
            Incidence[i][j]=false;
        }
    }
    for(int i=0; i<e; i++)
    {
        Incidence[poros[0][i]][i]=true;
        Incidence[poros[1][i]][i]=true;
    }
    cout<<" \t";
    for(int i=1;i<=e;i++)
    {
        cout<<"e"<<i<<"\t";
    }
    cout<<"\n";
    for(int i=0; i<v; i++)
    {
        cout<<i<<"\t";
        for(int j=0; j<e; j++)
        {
            cout<<Incidence[i][j]<<"\t";
        }
        cout<<"\n";
    }
    return 0;
}
