#include <bits/stdc++.h>
#include "Test.h"
#include "TestBase.h"

using namespace std;

int main()
{
    vector <int> mn,mx;
    int mx_question_count=1e6;
    mn.resize(mx_question_count);
    mx.resize(mx_question_count);
    for(int i=0;i<mx_question_count;i++){
        mn[i]=-1e9;
        mx[i]=1e9;
    }
    string s;
    TestBase testBase;
    setlocale(LC_ALL,"russian");
    while(true){
        cin>>s;
        if(s=="add"){
            Test test;
            cin>>test;
            testBase.add(test);
        }else if(s=="sort"){
            testBase.sort();
        }else if(s=="add_to_sorted"){
            Test test;
            cin>>test;
            testBase.addToSorted(test);
        }else if(s=="find"){
            string name;
            int number;
            cin>>name>>number;
            int questions_count;
            cin>>questions_count;
            vector <int> top,bottom;
            for(int i=0;i<questions_count;i++){
                int x;
                cin>>x;
                top.push_back(x);
                bottom.push_back(x);
            }
            testBase.write(name,number,top,bottom);
        }else if(s=="delete"){
            string name;
            int number;
            cin>>name>>number;
            int questions_count;
            cin>>questions_count;
            vector <int> top,bottom;
            for(int i=0;i<questions_count;i++){
                int x;
                cin>>x;
                top.push_back(x);
                bottom.push_back(x);
            }
            testBase.remove(name,number,top,bottom);
        }else if(s=="test_info"){
            int n;
            cin>>n;
            testBase.getBallList(n);
        }else if(s=="load"){
            string file;
            cin>>file;
            ifstream in(file);
            in>>testBase;
            in.close();
        }else if(s=="save"){
            string file;
            cin>>file;
            ofstream out(file);
            out<<testBase;
            out.close();
        }else if(s=="clear"){
            testBase.remove("*",-1,mn,mx);
        }else if(s=="exit"){
            break;
        }else if(s=="help"){
            string s="help - Вывести этот текст\n save <имя файла> - записать список в файл\n load <имя файла> - загрузить список из файла\n";
            s+="clear - отчистить список\n";
            s+="add <имя> <номер_теста> <количество вопросов> <баллы> - добавить тест в список\n";
            s+="add_to_sorted <имя> <номер_теста> <количество вопросов> <баллы> - добавить тест в список c сохранением сортировки\n";
            s+="sort - отсортировать список\n";
            s+="find <имя> <номер_теста> <количество вопросов> <минимальные баллы> <максимальные баллы> - вывести тесты, удволетворяющие критериям(количество вопросов должно быть не меньше максимального для всех тестов из списка)\n";
            s+="delete <имя> <номер_теста> <количество вопросов> <минимальные баллы> <максимальные баллы> - удалить тесты, удволетворяющие критериям(количество вопросов должно быть не меньше максимального для всех тестов из списка)\n";
            s+="exit - завершить работу\n";
            cout<<s;
        }
    }
    return 0;
}
