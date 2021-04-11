#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Document{
    private:
        vector<string> rows;
        int pos;

    public:
        Document();
        Document(string file);

        vector<string>* getRows();

        void execute();
        void jumpToRow(string input);
        void goToEndRow();
        void eraseRow();
        void addRowsBefore();
        void addRowsAfter();
        void changeRows();
        int searchString(string str);
        void replaceWord(string input);
        void unionRows();
        void writeFile(string input);
};