#include <bits/stdc++.h>

using namespace std;

struct arc{
    int direct;
    int length;
};

vector <arc> graph[1000001];
int ml=0,ch=0;
int n,m;
deque <int> ans;
deque <int> cur;
int st;
bool check[1000001];

void brute(int l){
    //cout<<cur.front();
    //cout<<"!1";
    if(l>ml||cur.size()>m*3) return;
    //cout<<"!2";
    if(ch==n&&cur.front()==st){
        //cout<<"!3";
        if(l<=ml){
            ans=cur;
            /*ans.clear();
            for(auto i=cur.begin();i!=cur.end();i++){
                cout<<(*i);
                ans.push_front(*i);
            }*/
            ml=l;
        }
        return;
    }
    for(int i=0;i<graph[cur.front()].size();i++){
        int x=graph[cur.front()][i].direct;
        int ll=graph[cur.front()][i].length;
        bool f=false;
        if(!check[x]){
            f=true;
            check[x]=true;
            ch++;
        }
        cur.push_front(x);
        brute(l+ll);
        if(f){
            check[x]=false;
            ch--;
        }
        cur.pop_front();
    }
}

int main(){
    setlocale(LC_ALL,"russian");
    cout<<"Введите количество вершин(2<=n<=1000000) и рёбер(1<=m<=1000000) графа\n";
    cin>>n>>m;
    cout<<"Введите рёбра в следующем формате:\nНачало Конец Длина пути(в пределах от 1 до 1000000)\nВершины пронумерованы от 1 до n\n";
    for(int i=0;i<m;i++){
        int x;
        arc a,b;
        cin>>x>>a.direct>>a.length;
        b.length=a.length;
        b.direct=x;
        graph[x].push_back(a);
        graph[a.direct].push_back(b);
        ml+=a.length*2;
    }
    for(int i=1;i<=n;i++){
        st=i;
        ch++;
        check[i]=true;
        cur.push_front(i);
        brute(0);
        ch--;
        check[i]=false;
        cur.pop_front();
    }
    cout<<"Искомый цикл:\n";
    cout<<ans.front();
    ans.pop_front();
    while(ans.size()){
        cout<<'-'<<ans.front();
        ans.pop_front();
    }
    return 0;
}
