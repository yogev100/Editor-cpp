#pragma once

#include <iostream>
#include <vector>
#include "Document.h"


using namespace std;

class Editor{
    private:
        Document* doc;

    public:
        Editor();
        Editor(string file);
        ~Editor(){
            delete doc;
        };
        void loop();
};