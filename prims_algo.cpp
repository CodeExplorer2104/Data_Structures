#include<iostream>
using namespace std;
class graph
{
    int n;
    int e,s,d,c;
    int cost[20][20];
    public:
    void create_graph();
    void display_graph();
    void prims();
};
void graph::create_graph()
{
    cout<<"ENTER NO. OF VERTICES";
    cin>>n;
    cout<<"ENTER NO. OF EDGES";
    cin>>e;
    for (int i=0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
        cost[i][j]=9999;
        }
    }
    for (int i=0;i<e;i++)
    {
        cout<<"ENTER SOURCE , DESTINATION AND COST";
        cin>>s>>d>>c;
    }
    cost[s][d]=cost[d][s]=c;
}
int main()
{
     graph g;
     g.create_graph();

}