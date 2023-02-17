#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename, vector<string> &names, vector<int> &scores, vector<char> &grades){
    ifstream source;
    source.open(filename);
    char text[200];
    char format[200] = "%[^:]: %d %d %d";
    char name[200];
    int a,b,c;
    while(getline(source,text)){
        sscanf(text,format,name,&a,&b,&c);
        names.push_back(name);
        scores.push_back(a+b+c);
        grades.push_back(score2grade(a+b+c));
    }
}

void getCommand(string &command, string &key){
    cout << "Please input your command: ";
    cin >> command >> key;
}

void searchName(vector<string> names, vector<int> scores, vector<char> grades, string key){
    for(int i = 0; i < names.size(); i++){
        if(key == toUpperStr(names[i])){
            cout << names[i] << "'s score =" << scores[i] << "\n";
            cout << names[i] << "'s grade =" << grades[i] << "\n";
        }
    }
}

void searchGrade(vector<string> names, vector<int> scores, vector<char> grades, string key){
    for(int i = 0; i < names.size(); i++){
        if(key.c_str() == toUpperStr(grades[i])){
            cout << names[i] << "'s score =" << scores[i] << "\n";
            cout << names[i] << "'s grade =" << grades[i] << "\n";
        }
    }
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
