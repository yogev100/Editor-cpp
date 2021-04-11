
#include <iostream>
#include <fstream>
#include <vector>
#include "Document.h"

using namespace std;

Document::Document(){
    
    pos = -1;
}

Document::Document(string file){
    pos = 0;
    cout<<file<<endl;
    ifstream file_to_read(file);
    if(!file_to_read) cout<<"no open"<<endl;
    string content;
    while(getline(file_to_read,content) && content!="") {
        rows.push_back(content);
        pos++;
        cout<<"pos "<<pos<<" "<<content<<endl;
    }
}

vector<string>* Document::getRows(){
    return &rows;
}

void Document::jumpToRow(string input){
    int check_num;
    try{
        check_num = stoi(input);
        //check if the current row is valid
        if(input.at(0)=='+' || input.at(0)=='-'){
            // the row is out of range
            if(check_num + this->pos >=this->rows.size() || check_num + this->pos<0){
                cout<<"?"<<endl;
            }
            // change the row position according to the input number
            else{
                
                this->pos+= check_num;
                cout<<"pos:"<<this->pos<<"size:"<<this->rows.size()<<endl;
                cout<<this->rows.at(this->pos)<<endl;
            }
        }
        // the user insert only number without an operator before, change the current row to the input number
        else{
            if(check_num>=1 && check_num<=rows.size()){
                this->pos = check_num - 1;
                cout<<"pos:"<<this->pos<<" "<<"size:"<<this->rows.size()<<endl;
                cout<<this->rows.at(pos)<<endl;
            }
        }

    }
    // if the input is not a number, catch the exception
    catch(invalid_argument &e){
    }   
}

void Document::goToEndRow(){
    this->pos = this->rows.size()-1;
}

void Document::eraseRow(){
    this->rows.erase(this->rows.begin()+this->pos);
}

void Document::addRowsBefore(){
    string input;
    getline(cin, input);
    while(input!="."){
        if(input!=""){
            this->rows.insert(this->rows.begin()+this->pos, input );
            this->pos++;
        }
        getline(cin, input);
    }
    this->pos--;
}

void Document::addRowsAfter(){
    string input;
    getline(cin, input);
    int i = this->pos+1;
    cout<<"i="<<i<<" size="<<rows.size()<<endl;
    while(input!="."){
        if(input!=""){
            this->rows.insert(this->rows.begin()+i, input );
            i++;
            cout<<"i="<<i<<" size="<<rows.size()<<endl;
        }
        getline(cin, input);
    }
    this->pos = i-1;
}

void Document::changeRows(){
    string input;
    getline(cin, input);
    while(input==""){
        getline(cin, input);
    }
    // cout<<"change input:"<<input<<endl;
    this->rows[this->pos] = input;
    addRowsAfter();
}

int Document::searchString(string str){
    cout<<"str:"<<str<<endl;
    size_t found;
    int index = this->pos;
    for(int i=index+1; i<this->rows.size(); i++){
        cout<<"i = "<<i<<endl;
        cout<<"rows[i]="<<rows[i]<<endl;
        found = this->rows[i].find(str);
        if(found!=string::npos){
            cout<<str<<endl;
            this->pos = i;
            return 1;
        }
    }
    for(int i=0; i<=index; i++){
        if(i>=this->rows.size()){
            break;
        }
        cout<<"i = "<<i<<endl;
        cout<<"rows[i]="<<rows[i]<<endl;
        found = this->rows[i].find(str);
        if(found!=string::npos){
            cout<<str<<endl;
            this->pos = i;
            return 1;
        }
    }
    cout<<"?"<<endl;
    return 0;
    
}

void Document::replaceWord(string input){
    string sub_input = input.substr(2,input.length()-3);
    cout<<"sub_input:"<<sub_input<<endl;
    size_t sec_slash = sub_input.find('/');
    if(sec_slash!=string::npos){
        string s1 = sub_input.substr(0,sec_slash);
        string s2 = sub_input.substr(sec_slash+1);
        cout<<"s1:"<<s1<<" s2:"<<s2<<endl;
        size_t word_index = this->rows[this->pos].find(s1);
        if(word_index!=string::npos){
            this->rows[this->pos].replace(word_index, s1.length(), s2);
        }
        else{
            cout<<"?"<<endl;
        }
    }
    else{
        cout<<"?"<<endl;
    }
}

void Document::unionRows(){
    if(this->pos<this->rows.size()-1){
        string to_join = this->rows[this->pos +1];
        this->rows[this->pos].append(to_join);
        cout<<"after join: "<<this->rows[this->pos]<<endl;
        this->rows.erase(this->rows.begin() + this->pos +1);
    }
    else{
        cout<<"?"<<endl;
    }
}

void Document::writeFile(string input){
    string file_name = input.substr(2);
    cout<<"file name:"<<file_name<<endl;
    if(file_name!=""){
        ofstream outfile(file_name);
        if(!outfile.is_open()){
            cout<<"Failed to open the file"<<endl;
            return;
        }
        for(const auto &e: this->rows){
            outfile << e << "\n";
        }
        outfile.close();
    }
}
