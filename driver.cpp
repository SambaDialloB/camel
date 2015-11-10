//Name:
//Date: 6 November 2015
//Description:

#include <iostream>//cin, cout
#include <ctime>//srand()
#include <cstdlib>//rand, abs
#include <string>//string
#include <cctype>//tolower

using namespace std;

char menu ();
//Summary: Prints out game menu for play.
//Precondition: The bool variable, done, is logically equal to false.
//Postcondition: The user inputs a choice based on the available options.
//
//*****************************************************************************************
//

void status(int& valMiles, int& valDrinks, int& valNatives);
//Summary: Allows the user to view the number of miles traveled, number of
//drinks available, and how far back the Natives are.
//Precondition: The user enter ‘e’ as a choice.
//Postcondition: The bool variable done is still set to false.
//
//*****************************************************************************************
//

void rest(int& valCamel, int& valNatives);
//Summary: Allows the player to rest for a turn.
//Precondition: The user chose ‘d.’
//Postcondition: The users camel tiredness is reset to zero and the
//natives advance 7 - 14 miles.
//
//*****************************************************************************************
//

void nativeMiles(int& valNatives);//adds random # miles to natives distance
//Summary: Randomly generates the number of miles the Natives advance.
//The advancement is between 7 and 14 miles.
//Precondition: The user is still ahead of the Natives in the game play.
//Postcondition: The Natives advance a random number of miles.
//
//*****************************************************************************************
//

void fullSpeed(int& valMiles, int& valThirst, int& valTired, int& valNatives);
//Summary: Allows the user to advance between 10 and 20 miles and causes
//the camel to increase tiredness by one.
//Precondition: The user chooses ‘c.’
//Postcondition: The user advances a random number of miles and gets to play again.
//
//*****************************************************************************************
//

void modSpeed(int& valMiles, int& valThirst, int& valTired, int& valNatives);
//Summary: The user can advance between 5 and 12 miles and tiredness is
//increased by between 1 and 3.
//Precondition: The user chooses ‘b’
//Postcondition: The variable is still set to false and the user plays again.
//
//*****************************************************************************************
//

void drink(int& valThirst, int& valDrinks);
//Summary: Allows the user to drink to quench thirst.
//Precondition: The user still has drinks available.
//Postcondition: The user’s thirst is reset to zero and the number of drinks
//available is decreased by one.
//
//*****************************************************************************************
//

bool fight();
//Summary: sets the user up for a fight
//Precondition: needs to be called
//Postcondition: Decides if the user lives or dies randomly
//
//*****************************************************************************************
//


int main()
{
    bool done(false);
    char ans, dec = 'N';
    int miles(0);
    int thirst(0);
    int camelTiredness(0);
    int natives(-20);
    int drinks(3);
    srand(time(0));
    bool winornah;

    //cout introduction
    cout << "\nWelcome to Camel!\n"
         << "\nYou have stolen a camel to make your way across the great Mobi desert.\n"
         << "The natives want their camel back and are chasing you down!\n"
         << "Survive your desert trek and outrun the natives.\n" << endl;

    while (!done)
    {
        ans = menu();

        switch (ans)
        {
            case 'a': drink(thirst, drinks);
                break;
            case 'b': modSpeed(miles, thirst, camelTiredness, natives);//full speed
                break;
            case 'c': fullSpeed(miles, thirst, camelTiredness, natives);//full speed
                break;
            case 'd': rest(camelTiredness, natives);
                break;
            case 'e': status(miles, drinks, natives); //status function
                break;
            case 'q': done = true;
                break;
        }

        if (thirst > 4 && thirst < 6)
        {
            cout << "\nYou are thirst.\n" << endl;
        }

        if (thirst >= 6)
        {
            cout <<"\nYou died.\n" << endl;
            done = true;
        }

        if (camelTiredness > 5 && camelTiredness < 8)
        {
            cout << "\nYour camel is tired.\n" << endl;
        }

        if (camelTiredness >= 8)
        {
            cout << "\nYour camel is dead.\n" << endl;
        }

        if (natives >= miles)
        {
            cout << "\nThe natives caught up.\n" << endl;
            done = true;
        }

        if (miles - (natives) < 15)
        {
            cout << "\nThe natives are getting close!\n" << endl;
            cout << "They start to rush to you, you have no choice but to FIGHT!!: ";
                winornah = fight();
                if(winornah == 1)
                {
                    cout << "You won the fight! No Natives will ever bother you again! The dead and dying lay at your feet as you climb onto your camel. The locals will tell stories about your adventure for centuries. GG\n";
                    done = true;
                }
                else
                {
                    cout << "You lost...\nYour vision blurs as you bleed out onto the hot sand... \nWhy would you try to fight in a one versus four scenario??\n";
                    done = true;
                }
        }

        if (miles >= 200)
        {
            cout << "\nYou won!\n" << endl;
            done = true;
        }

    }


    return 0;
}
//**************************************************
char menu ()
{
    char choice;

    cout << "A. Drink from your canteen.\n"
         << "B. Ahead moderate speed.\n"
         << "C. Ahead full speed.\n"
         << "D. Stop and rest.\n"
         << "E. Status check.\n"
         << "Q. Quit.\n"
         << "Your choice? ";

    cin >> choice;

    choice = tolower(choice);

    return choice;

}//end menu()
//***************************************************
//
void status(int& valMiles, int& valDrinks, int& valNatives)
{
    cout << "\nMiles traveled: " << valMiles << endl
         << "Drinks in canteen: " << valDrinks << endl
         << "The natives are " << valMiles - (valNatives) << " miles behind you\n"
         << endl;
}//end status()
//***************************************************
//
void rest(int& valCamel, int& valNatives)
{
    valCamel = 0;//reset camel tiredness to zero
    cout << "\nThe camel is happy ^o^\n"
         << endl;

    nativeMiles(valNatives);

}//end rest()
//***************************************************
//
void nativeMiles(int& valNatives)
{
    int miles = rand()%8 + 7;//adds # [7,14] miles

    valNatives += miles;
  // cout << "NAtives traveled: " << valNatives << endl;
}//end nativeMiles()
//***************************************************
//
void fullSpeed(int& valMiles, int& valThirst, int& valTired, int& valNatives)
{
    int milesAdded = rand()%11 + 10;
    int tiredAdded = rand()% 3 + 1;
    valMiles += milesAdded;//add # [10, 20] miles to user

    cout << "\nYour traveled " << milesAdded << " miles." << endl;

    valTired += tiredAdded;

    valThirst++;

    nativeMiles(valNatives);//add miles to native distance

}//end fullSpeed
//***************************************************
//
void modSpeed(int& valMiles, int& valThirst, int& valTired, int& valNatives)
{
    int milesAdded = rand()%8 + 5;
    int tiredAdded = rand()% 3 + 1;
    cout << "Your traveled " << milesAdded << " miles." << endl;

    valTired += tiredAdded;

    valThirst++;

    valMiles += milesAdded;//add #[5,12 miles to user
}//end modSpeed()
//***************************************************
//
void drink(int& valThirst, int& valDrinks)
{
    valThirst = 0;
    valDrinks--;
    cout << "Thirst: " << valThirst << endl;
    cout << "num drinks: " << valDrinks << endl;

}//end drink()
//***************************************************
//
bool fight()
{
    int chosen, random;
    cout << "Choose a number between 1 and 5 inclusive. \nIf you guess correctly then you defeat the savages that are attacking you!\n Your number: ";
    cin >> chosen;
    random = rand()% 4 + 1;
    if(chosen == random)
        return 1;
    else
        return 0;

}



