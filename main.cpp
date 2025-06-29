#include<bits/stdc++.h>
#include <conio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

//  time(0)	 : Gets current time in seconds since 1970	Asks the OS for the current system clock value
// localtime() :	Converts seconds to local date/time (struct tm)
// strftime()	 : Formats struct tm as a string

string formatTime(time_t rawtime)                     // Function to format the time in HH:MM:SS format
{
    tm *timeinfo = localtime(&rawtime);
    char buffer[9];
    strftime(buffer, sizeof(buffer), "%H:%M:%S", timeinfo);
    return string(buffer);
}

class login                             // this login class handles login process and password checking
{ 
public:
    int loginsys();                           // Handles login process 
    string pass = "prajwal07";                // stores the login password
};

class Car
{
public:
    string drivername;
    string carname;
    string carid;
    time_t parkedAt;                           // it store the parking time

    // Car() {}                                                  // this is the Constructor with Member Initializer List
    // Car(string dname, string cname, string cid, time_t t)
    //     : drivername(dname), carname(cname), carid(cid), parkedAt(t) {}
   
    Car() {}                               // this is the default constructor for the Car class

    Car(string dname, string cname, string cid, time_t t)       //it is a Constructor with Assignment in the Body
    {
        drivername = dname;
        carname = cname;
        carid = cid;
        parkedAt = t;
    }                                      // When a user parks a car, a Car object is created and filled with the user info and the current time                                         
};

int login::loginsys()                       // this defines the loginsys method/function belongs to the login class.
{
    while (1)                                  // It loops until the correct password is entered.
    {
        string password;                                             // it will store the user's input password
        cout << "\n\n\n\n\t\t\t\t----------> WELCOME TO  CAR PARKING MANAGEMENT SYSTEM  <----------" << endl;
        cout << "\n\n\n\t\t\t\t\t   Please Login into Car Parking Reservation System ";
        cout << "\n\n\n\n\t\t\t\t\t\t    Enter Password to login : ";

        char ch;
        ch = _getch();              // _getch() is a function from <conio.h> that reads a single character from the keyboard without displaying it on the screen.

        while (ch != 13)                     // Keep reading characters until the user presses Enterkey (13 is the ASCII code for Enterkey)
        {
            password.push_back(ch);              // push the character to the password string.
            cout << '*';                     // Prints '*' instead of the actual character as _getch() function reads the character without displaying it on the screen.
            ch = _getch();                   //  reads the next character.
        }

        if (password == pass)
        {
            cout << "\n\n\n\n\t\t\t\t\t            Logged in successfully!  \n\n";
            system("PAUSE");           // The program waits until the user presses a key, then continues,  PAUSE displays: press any key to continue...
            break;                      // exits the infinite loop, allowing the program to continue.
        }
        else
        {
            cout << "\n\n\n\n\t\t\t\t\t Incorrect password, Please try again! \n";
            system("PAUSE");              
            system("CLS");                  // Clears the console screen.
        }                                 // The loop starts again, so the user can try again
    }
    return 1;                              // After a successful login the loop breaks and it returns 1
}

class ParkingManagement                          // ParkingManagement class for all parking operations
{
public:
    vector<Car> cars;                      // this vector stores objects of type Car
    void park();
    void cardetail();
    void removecar();
};

void ParkingManagement::park()                // this defines the park method/function belongs to the ParkingManagement class.
{
    cout << "                        -------------> Car Parking System <-------------" << endl << endl;

    Car CAR;                             // declares a new object named CAR from class Car. This will hold the details of the car being parked.
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Enter Your Name : ";
    getchar();                      // reads and removes that leftover newline character from the buffer which is created when we use cin>>, so that the next getline() works as expected and reads the full line typed by user
    getline(cin, CAR.drivername);

    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * "<<endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Enter Your Car Name : ";
    getline(cin, CAR.carname);

    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * "<<endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Enter Your Car Number Plate  : ";
    cin >> CAR.carid;

    CAR.parkedAt = time(0);               //  time(0) gets the current time from the computer clock and sets it in the parkedAt property of the Car object.

    cars.push_back(CAR);

    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * "<<endl;
    cout << "---------------------------------------------------" << endl;
    cout << " You Have Succesfully Parked Your Car At (HH:MM:SS) : " << formatTime(CAR.parkedAt) << endl;      // Function define at top which converts the stored time into a readable string like "18:30:45".
    cout << "---------------------------------------------------" << endl;
    cout << "Press Enter Key To Return" << endl;
    getch();                            // getch() from <conio.h>  pause the program untill any key is pressed but doesn't display it on the screen.  =>  similar to system("PAUSE") while this prints "Press any key to continue..." on console
}

void ParkingManagement::cardetail()
{
    system("CLS");
    int i = 0;
    string detailid;
    cout << "---------------------------------------------------" << endl;
    cout << "Enter Your Car Number Plate : ";
    getchar();                                               // Removes any leftover newline character in the input buffer (from previous cin >>), so getline() works correctly.
    getline(cin, detailid);
    cout << "                        -------------> Your Car Details <-------------" << endl << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * "<<endl;
    cout << "---------------------------------------------------" << endl;

    for (const auto& car : cars)
    {
        if (car.carid == detailid)
        {

            cout << "Driver Name : " << car.drivername << endl;
            cout << "Car Name : " << car.carname << endl;
            cout << "Car Number Plate : " << car.carid << endl;
            cout << "Parked At (HH:MM:SS): " << formatTime(car.parkedAt) << endl;
            cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * "<<endl;
            cout << "---------------------------------------------------" << endl;
            cout << "Press Enter Key To Return" << endl;
            cout << "---------------------------------------------------" <<endl;
            getch();
            i++;                                         // act as a flag to check if the car was found
            break;                                      // it exits the loop when it finds the car with the given car number plate.
        }
    }

    if (i == 0)
    {
        cout << "Car With Car Number Plate " << detailid << "  Not Found" << endl;
        cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * "<<endl;
        cout << "---------------------------------------------------" << endl;
        cout << " Please Try Again ! " << endl;
        cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * "<<endl;
        cout << "---------------------------------------------------" << endl;
        cout << "Press Enter Key To Return" << endl;

        cout << "---------------------------------------------------" << endl;
        getch();                                            // Waits for a any key to be pressed before returning to the menu.
    }
}

void ParkingManagement::removecar()
{
    system("CLS");
    string rcarid;

    cout << endl;
    cout << "                        -------------> Car Parking Check Out System <-------------" << endl;
    cout << endl;
    cout << "---------------------------------------------------" << endl;

    cout << "Enter Your Car Number Plate : ";
    cin >> rcarid;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * "<<endl;
    cout << "---------------------------------------------------" << endl;

    int found = 0;
    for (auto it = cars.begin(); it != cars.end(); ++it)
    {
        if (it->carid == rcarid)
        {
            time_t now = time(0);
            double seconds = difftime(now, it->parkedAt);             // here now and it->parkedAt are stored in time_t type i.e both are in seconds.
            double rate=1;                                 // 1 rupee per second
            double expense = seconds * rate; 

            cout << "Car was parked at: " << formatTime(it->parkedAt) << endl;
            cout << "Car removed at:    " << formatTime(now) << endl;
            cout << "Total time parked: " << seconds << " seconds" << endl;
            cout << "Your total parking expense is: " << expense << " Rupees" << endl;

            cout << "Good Bye" << endl
                 << "Thanks For Choosing Us!" << endl;

            cars.erase(it);
            found = 1;
            break;
        }
    }

    if (found==0)
    {
        cout << "Car with number plate " << rcarid << " not found in parking." << endl;
    }

    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * "<<endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Press any Key To Return" << endl;
    cout << "---------------------------------------------------" << endl;
    getch();
}

int main()
{
    system("CLS");
    login loginobj;
    loginobj.loginsys();
    ParkingManagement parkobj;

    while (1)                     // The program keeps running until the user chooses to exit.
    {
        system("CLS");
        int choice;
        cout << "                        -------------> Car Parking System <-------------" << endl << endl;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;
        cout << "1. Park Your Car " << endl;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;
        cout << "2. View Your Car Details" << endl;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;
        cout << "3. Remove Your Car" << endl;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;
        cout << "4. EXIT" << endl;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;
        cout << "ENTER YOUR CHOICE : ";
        cin >> choice;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;

        switch (choice)
        {
        case 1:
        {
            char yes;
            cout << "Do Your Want To Continue (y/n) : ";
            cin >> yes;
            system("CLS");
            if (yes == 'y')
            {
                parkobj.park();
            }
            system("CLS");
            break;
        }
        case 2:
            parkobj.cardetail();
            break;
        case 3:
            parkobj.removecar();
            break;
        case 4:
            cout << endl << endl;
            cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * ";
            cout << "---------------------------------------------------" << endl;
            cout << "Press Enter Key To EXIT";
            getch();
            exit(0);

        default:
            system("CLS");
            cout << "You Entered A Wrong Choice!" << endl;
            break;
        }
    }

    return 0;
}
