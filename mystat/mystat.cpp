#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <numeric>

using namespace std;

class Mystat{
    public: 
    vector <string> Feedbacks;
    //заполнение отзывов 
    void pushFeedbacks()
    {
        Feedbacks.push_back("Mikhail, you always have interesting solutions! In general, you always have clean, neat code, and a cool exam paper, too. Keep it up!");
        Feedbacks.push_back("Mikhail, I see that you are trying and, in principle, everything is wonderful for you. It would be possible to find fault with the style of the code, etc., but at one time I drew such scribbles that it’s embarrassing to remember)) So, in comparison with me, you have a calligraphic style!");
        Feedbacks.push_back("Your efforts and dedication in learning Python and working with Tkinter make you an example to others. Your desire to improve and great potential promise a bright future in the field of programming. We are sure that you will be able to achieve everything you set your mind to.");
    }
    
};

class Student : public Mystat{
    public:
        string nickName;
        string password;
        Student() : nickName("Misha"), password("12345678") {}
        vector <int> Marks;
        int avarageMark;
        vector <int> Attendance;
        int attendance;
    void login(){
        string nickNameUser;
        string passwordUser;
        cout << "Input ur nicname: " << endl;
        cin >> nickNameUser;
        cout << "Input ur password" << endl;
        cin >> passwordUser;
        if (nickNameUser == nickName && passwordUser == password)
        {
            cout << "Welcome" << endl;
        }
        else
        {
            bool loginIsSucces = false;
        }
    }
//начинает урок (меняется посещяемость и появляются оценки)
    void lesson(){
        string answerTask;
        string answerLesson;
        cout << "its lesson now. Will u be with us?" << endl;
        cin >> answerLesson;
        if (answerLesson == "yes")
        {
            cout << "U are on the lesson, make the task and DENIS will give a candy (and a new mark)" << endl;
            cout << "Did u made task?: " << endl;
            cin >> answerTask;
            
            attendance = 1;
            Attendance.push_back(attendance);

            if (answerTask == "yes")
            {
                cout << "super, there is ur candy(and mark)" << endl;
                srand(time(NULL));
                int mark = rand()% 13;
                Marks.push_back(mark);
                cout << "u have new mark: " << mark << endl;
            }
            else
            {
                cout << "U are lame" << endl;
                int mark = 1;
                Marks.push_back(mark);
                cout << "u have new mark: " << mark << endl;
            }
        }
        else
        {
            cout << "U are lame2.0" << endl;
            attendance = 0;
            Attendance.push_back(attendance);
        }  
    }
//показавыет среднюю оценку человека
    void showAvarageMark(){
        int sum = accumulate(Marks.begin(), Marks.end(), 0);
        double averageMark = static_cast<double>(sum) / Marks.size();
        cout << "Ur avarege mark: " << avarageMark << endl;
    }
//показывает отзывы
    void showFeedback(Mystat *feedback){
        for (int i = 0; i <= 3; i++)
        {
            cout << feedback->Feedbacks[i] << endl;
        }        
    }


//инкапсуляция(запуск методов для пользавателя)
    void chooseAction(Mystat *feedback)
    {
        int choose;
        cout << "choose what u want to do(1 - lesson, 2 - show avarage mark, 3 - show feedback)" << endl;
        cin >> choose;
        switch (choose)
        {
        case 1:
            lesson();
            break;
        case 2:
            showAvarageMark();
            break;
        case 3:
            showFeedback(feedback);
            break;
        default:
            break;
        }
    }
};

int main()
{
    Mystat feedbacks;
    Student Miroslav;
    Miroslav.chooseAction(&feedbacks);
}