#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class TaxiBober
{
    private:
        string name;
        int balance;
        float rating;

    public:
    TaxiBober(string n, int b, float r)
    {
        name = n;
        balance = b;
        rating = r;
    }
    void inputInfo(){
        cout << "Input your name: " << endl;
        cin >> name;
        balance = 0;
        rating = 5.0;
    }

    void showInfo(){
        cout << "Driver info: \n";
        cout << "Driver's name: " << name << endl;
        cout << "Driver's balance: " << balance << "uah" << endl;
        cout << "Driver's rating: " << rating << endl; 
    }

private:
    void workDayStandart(){
        string stopWord;
        int cost;
        string choice;
        while (stopWord != "stop")
        {
            srand(time(NULL));
            int length = rand()% 201;
            int ratingForTrip = rand()% 5;

            cout << "You have new order, length " << length << "kilometres" << endl;
            cost = 15 * length;
            cout << "Cost of this order " << cost << "uah." << "Do you take this order?" << endl;
            cin >> choice;
            if (choice == "No")
            {
                continue;
            }
            else
            {
                balance += cost;

                rating += ratingForTrip;
                rating = rating / 5;

                cout << "Trip is end, if you want to stop your work day input 'stop' in console" << endl;
                cin >> stopWord;
                continue;
            }
        }   
    }

    void workDayComfort(){
        string stopWord;
        int cost;
        string choice;
        while (stopWord != "stop")
        {
            srand(time(NULL));
            int length = rand()% 201;
            int ratingForTrip = rand()% 5;

            cout << "You have new order, length " << length << "kilometres" << endl;
            cost = 25 * length;
            cout << "Cost of this order " << cost << "uah." << "Do you take this order?" << endl;
            cin >> choice;
            if (choice == "No")
            {
                continue;
            }
            else
            {
                balance += cost;

                rating += ratingForTrip;
                rating = rating / 5;

                cout << "Trip is end, if you want to stop your work day input 'stop' in console" << endl;
                cin >> stopWord;
                continue;
            }
        }   
    }

    void workDayBusiness(){
        string stopWord;
        int cost;
        string choice;
        while (stopWord != "stop")
        {
            srand(time(NULL));
            int length = rand()% 201;
            int ratingForTrip = rand()% 5;

            cout << "You have new order, length " << length << "kilometres" << endl;
            cost = 40 * length;
            cout << "Cost of this order " << cost << "uah." << "Do you take this order?" << endl;
            cin >> choice;
            if (choice == "No")
            {
                continue;
            }
            else
            {
                balance += cost;

                rating += ratingForTrip;
                rating = rating / 5;

                cout << "Trip is end, if you want to stop your work day input 'stop' in console" << endl;
                cin >> stopWord;
                continue;
            }
        }   
    }
public:
void chooseTarif(){
        int choiceTarif;
        cout << "Choose tarif - (standart -1, comfort -2, business -3)" << endl;
        cin >> choiceTarif;
        switch (choiceTarif)
        {
        case 1:
            workDayStandart();
            break;
        case 2:
            workDayComfort();
            break;
        case 3:
            workDayBusiness();
            break;
        default:
            break;
        }
    }
};

int main()
{
    TaxiBober taxist1(" ", 0, 0.0);

    taxist1.inputInfo();
    taxist1.showInfo();
    
    taxist1.chooseTarif();

    taxist1.showInfo();
}