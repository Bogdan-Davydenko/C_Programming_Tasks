#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

struct same{
    double prox;
    string word;
};

bool comp(same l,same r){
    return l.prox>r.prox||(l.prox==r.prox&&l.word<r.word);
}

int main(){
    setlocale(LC_ALL,"russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout<<"Введите язык текста('0'-английский,'1'-русский)\n";
    int lang;
    cin>>lang;
    char l,r,L,R;
    l = lang==0 ? 'a' : 'а';
    r = lang==0 ? 'z' : 'я';
    L = lang==0 ? 'A' : 'А';
    R = lang==0 ? 'Z' : 'Я';
    cout<<"Введите имя файла\n";
    string file;
    cin>>file;
    ifstream in(file);
    string s;
    vector <string> text;
    vector <string> wordlist;
    while(in>>s){
            cout<<s<<'\n';
        for(int i=0;i<s.length();i++){
            if(s[i]>=L&&s[i]<=R){
                s[i]-=(L-l);
            }
            if(s[i]<l||s[i]>r){
                s.erase(i);
            }
        }
        if(s.length()>0){
            text.push_back(s);
            wordlist.push_back(s);
        }
    }
    in.close();
    sort(wordlist.begin(),wordlist.end());
    map <string,int> index,amount;
    index[wordlist[0]]=0;
    amount[wordlist[0]]++;
    for(int i=1;i<wordlist.size();i++){
        amount[wordlist[i]]++;
        if(wordlist[i]==wordlist[i-1]){
            wordlist.erase(wordlist.begin()+i);
            amount[wordlist[i]]++;
            i--;
        }else{
            index[wordlist[i]]=i;
            amount[wordlist[i]]++;
        }
    }
    int n=wordlist.size();
    cout<<"Список слов:\n";
    for(int i=0;i<n;i++){
        cout<<i+1<<':'<<wordlist[i]<<'\n';
    }
    double arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        if(i>1){
            arr[index[text[i]]][index[text[i-2]]]++;
        }
        if(i>0){
            arr[index[text[i]]][index[text[i-1]]]++;
        }
        if(i<n-2){
            arr[index[text[i]]][index[text[i+2]]]++;
        }
        if(i<n-1){
            arr[index[text[i]]][index[text[i+1]]]++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]/=amount[wordlist[i]];
        }
    }
    //cout<<"Таблица близости:\n";
    double prox[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                prox[i][j]+=sqrt((arr[i][k]-arr[j][k])*(arr[i][k]-arr[j][k]));
            }
            //cout<<prox[i][j]<<' ';
        }
        //cout<<'\n';
    }
    vector <same> v[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            same x;
            x.prox=prox[i][j];
            x.word=wordlist[j];
            v[i].push_back(x);
        }
        sort(v[i].begin(),v[i].end(),comp);
    }
    while(true){
        cin>>s;
        cout<<s;
        for(int i=0;i<min(10,(int)v[index[s]].size());i++){
            cout<<i+1<<':'<<v[index[s]][i].word<<' '<<v[index[s]][i].prox<<'\n';
        }
    }
    return 0;
}
