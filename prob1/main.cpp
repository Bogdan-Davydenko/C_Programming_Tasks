#include <bits/stdc++.h>

using namespace std;

struct arc{
    int direct;
    int pass;
    int stream;
};

vector <arc> graph[1000001];
int pass[1000001];
bool check[1000001];
int stream[1000001];
int st,fn;

int dfs(int n,int str){
    if(n==fn){
        stream[n]+=str;
        return str;
    }
    for(int i=0;i<graph[n].size();i++){
        if(graph[n][i].stream<graph[n][i].pass){
            graph[n][i].stream=dfs(graph[n][i].direct,min(str,min(graph[n][i].pass-graph[n][i].stream,pass[graph[n][i].direct]-stream[graph[n][i].direct])));
            stream[n]+=graph[n][i].stream;
        }
    }
}

int main(){
    setlocale(LC_ALL,"russian");
    cout<<"Введите количество вершин(2<=n<=1000000) и дуг(1<=m<=1000000) графа\n";
    int n,m;
    cin>>n>>m;
    cout<<"Введите дуги в следующем формате:\nНачало Конец Пропускная способность(в пределах от 1 до 1000000)\nВершины пронумерованы от 1 до n\n";
    for(int i=0;i<m;i++){
        int x;
        arc a;
        a.stream=0;
        cin>>x>>a.direct>>a.pass;
        pass[x]+=a.pass;
        graph[x].push_back(a);
    }
    cout<<"Введите номер источника и стока\n";
    cin>>st>>fn;
    stream[st]=2e9;
    pass[st]=2e9;
    pass[fn]=2e9;
    int s=0;
    while(dfs(st,2e9)>0);
    cout<<stream[fn];
    return 0;
}
