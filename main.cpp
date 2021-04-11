#include <iostream>
#include "Editor.h"


int main(int argc, char* argv[]){
    // Document d (argv[1]);
    // d.execute();
    for(int i=0;i<argc;i++){
        cout<<argv[i]<<endl;
    }
    switch (argc){
        cout<<"in argc"<<endl;
        case 1:{
            cout<<"in case 1"<<endl;
            Editor ed;
            cout<<"after ed"<<endl;
            ed.loop();
            break;
        }
    
        case 2:{
            cout<<"argv[1]:"<<argv[1]<<endl;
            string file = argv[1];
            Editor ee(file);
            ee.loop();
            break;
        }
    
        default:{
            cout<<"You should run the program with an text file name or without nothing."<<endl;
            break;
            }
    }
    return 0;
}