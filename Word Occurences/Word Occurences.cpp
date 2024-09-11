#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <filesystem>
#include <cctype>

using namespace std;

int main()
{
    ifstream inFile("Lorem Ipsum.txt");
    if (inFile.is_open() == true)
    {
        cout << "yippee" << endl;
    }
    else
    {
        cout << "bruh" << endl;
    }
    map<string, int> wordDic;
    string word;
    cout << filesystem::current_path() << endl;
    while (inFile >> word)
    {
        for (char c : word)
        {
            c = tolower(c);
            if (c == ',' || c == '.' || c == ' ')
            {
                c = NULL;
                word.resize(word.length() - 1);
            }
        }
        wordDic[word] += 1;
    }
    for (const auto item : wordDic)
    {
        cout << item.first << " : " << item.second << endl;
    }
}