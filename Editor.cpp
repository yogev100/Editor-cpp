#include <iostream>
#include <vector>
#include "Editor.h"
#include "Document.h"

using namespace std;

Editor::Editor(){
    doc = new Document();
}

Editor::Editor(string file){
    doc = new Document(file);
}

void Editor::loop(){
    string input;
    getline(cin, input);
    cout<<"before while"<<endl;
    while(input!="q"){
        cout<<"insdie while"<<endl;
        cout<<"input: "<<input<<endl;
       if(input.length()==1 && input.at(0)=='$' ){doc->goToEndRow();}
       else if(input.length()==1 && input.at(0)=='i'){doc->addRowsBefore();}
       else if(input.length()==1 && input.at(0)=='a'){cout<<"in a"<<endl;
       doc->addRowsAfter();}
       else if(input.length()==1 && input.at(0)=='c'){doc->changeRows();}
       else if(input.length()==1 && input.at(0)=='d'){doc->eraseRow();}
       else if(input.length()>=2 && input.at(0)=='/' && input.at(input.length()-1) == '/'){
           string to_find = input.substr(1,input.length()-2);
            doc->searchString(to_find);
       }
       else if(input.length()>=4 && input.at(0)=='s' && input.at(1)=='/'&&
         input.at(input.length()-1) == '/'){doc->replaceWord(input);}
        else if(input.length()==1 && input.at(0)=='j'){doc->unionRows();}
        else if(input.length()>=3 && input.at(0) =='w' && input.at(1) ==' '){doc->writeFile(input);}
        else{ doc->jumpToRow(input);}
        getline(cin,input);
    }

}
