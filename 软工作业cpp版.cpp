#include<iostream>
using namespace std;
#include<queue>
#include<stdlib.h>
typedef struct Edge
{
	int start;
	int end;
	int weight;
}EData;//边的数据
typedef struct
{
	int sign;
}assist[30];
assist assists;
typedef struct
{
	char vexs[30];
	int vexnum,arcnum;
	EData arcs[30];//边的数据
}Graph,*PGraph;
void createGraph(Graph &G)
{
	cin>>G.vexnum>>G.arcnum;
    for(int i=1;i<=G.vexnum;i++)
	{
		assists[i].sign=i;
	}
	for(int k=0;k<G.arcnum;k++)
	{
		int start,end,weight;
		cin>>start>>end>>weight;
		G.arcs[k].start=start;
		G.arcs[k].end=end;
		G.arcs[k].weight=weight;
	}
}
void sort(Graph &G)
{
	int i,j;
	EData t;
	for(i=0;i<G.arcnum-1;i++)
	{
		for(j=0;j<G.arcnum-1-i;j++)
		{
			if(G.arcs[j].weight>G.arcs[j+1].weight)
			{
				t=G.arcs[j];
				G.arcs[j]=G.arcs[j+1];
				G.arcs[j+1]=t;
			}
		}
	}
}

void kruskal(Graph G)
{
	int index=0,num=0;
	EData rets[30];
	int i;
	sort(G);
	for(i=0;i<G.arcnum;i++)
	{
		int start=G.arcs[i].start;
		int end=G.arcs[i].end;
		if(assists[start].sign!=assists[end].sign)
		{
			rets[index++]=G.arcs[i];
			num++;
			
			
			int temp=assists[end].sign;
			for(int k=1;k<=G.vexnum;k++)
			{
				if(assists[k].sign==temp)
				{
					assists[k].sign=assists[start].sign;
				}
			}
		}
		if(num==G.vexnum-1)
		{
			break;
		}
	}
	int sum=0;
	for(i=0;i<index;i++){
		cout<<rets[i].start<<rets[i].end<<'\n';
	}
	for(i=0;i<index;i++)
	{
		sum=sum+rets[i].weight;
	}
	cout<<sum;
}
int main()
{
	Graph G;
	createGraph(G);
	kruskal(G);
	system("pause");
	return 0;
}



