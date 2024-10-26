#include <iostream>
#include <string>
#include <map>

using namespace std;


int main()
{
    map<int, string> ticketMap;

    ticketMap[01] = "Miroslav";
    ticketMap[02] = "Oleg";
    ticketMap[101] = "Artem";

    for(auto& pair : ticketMap){
        cout << "ID: " << pair.first << "\nname: " << pair.second;
    }

    int searchID = 101;

    auto it = ticketMap.find(searchID);

    if (it != ticketMap.end())
    {
        cout << "ticket founded" << it->second << endl;
    }
    else
    {
        cout << "error" << endl;
    }
    
    ticketMap.erase(101);

    cout << ticketMap.at(101) << endl;
}