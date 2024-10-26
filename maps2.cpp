#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<string, int> marksMap;

    marksMap["Mirsolav"] = 11;
    marksMap["Oleg"] = 12;
    marksMap["Artem"] = 10;
    marksMap["Lina"] = 10;
    marksMap["Artur"] = 1;
    

    string name;
    int mark;
    for (int i = 0; i <= 5; i++)
    {
        cin >> name;
        cin >> mark;
        marksMap[name] = mark;
    }
   
    for(auto& pair : marksMap){
        cout << "Name: " << pair.first << "\nMark: " << pair.second;
    } 

    string searchName;
    cout << "Input needing name: " << endl;
    cin >> searchName;

    auto it = marksMap.find(searchName);

    if (it != marksMap.end())
    {
        cout << "student founded" << it->first << endl;
    }
    else
    {
        cout << "error" << endl;
    }
}
