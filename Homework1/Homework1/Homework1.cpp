/*
* Author: Delaina Hardwick
* Date: Sep 12 2023
* Assignment: (1) a function that outputs all numbers from 1-1000
*             that are divisible by two different numbers which
*             which should be passed to the function
*             (2) a function to reverse the letters in a string
*             (3) a function that returns a string with the vowels removed
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//using std::fmod; //This is a way to use the
                   //modulus operator with floats.
                   //I opted to use floats instead of
                   //ints to prevent errors caused by
                   //truncation. (For example 1 % 10 == 0
                   //is true if you use integers!)

//using std::ws;   //Not completely sure what this is,
                   //but it allows me to use the getline function
                   //after sending input to the cin stream.
                   //Without this, any previous input received
                   //will be reused!

                   //And if you use cin instead of getline,
                   //any white spaces in the user's input
                   //will be treated as the end of input.
                   //(For example, "Hello World" becomes "Hello")

void printMenu()
{
    cout << "Problem #1: divisibility function" << "\n";
    cout << "Problem #2: string reversal function" << "\n";
    cout << "Problem #3: vowel removal function" << "\n";
    cout << "Enter 0 to Exit" << "\n" << "\n";
}

string divisibility(float factor1, float factor2)
{
    string result = "";
    int length = 0;
    int temp;

    if (factor1 == 0.0f
        || factor2 == 0.0f)
    {
        return "Both factors must be nonzero. Try again.";
    }

    for (float i = 1; i <= 1000; i++)
    {
        if (fmod(i, factor1) == 0.0f
            && fmod(i, factor2) == 0.0f)
        {
            temp = (int)i;
            result = result + to_string(temp) + ", ";

            //Adds a new line for every 10 numbers added to the result
            if (++length % 10 == 0)
            {
                result = result + "\n";
            }
        }
    }

    //Shaves off the last two characters in the string
    //to get rid of the extra comma and space
    if (!result.empty())
    {
        result = result.substr(0, result.length() - 2);
    }

    return result;
}

string reversal(string input)
{
    string result = "";
    int last = input.length() - 1;

    //Traverses the user's string backwards,
    //adding each letter to the result from
    //right to left.
    for (int i = last; i >= 0; i--)
    {
        result = result + input[i];
    }

    return result;
}

string vowelRemoval(string input)
{
    string result = "";
    bool skip;
    char vowels[10] = {'a', 'e', 'i', 'o', 'u',
                       'A', 'E', 'I', 'O', 'U'};

    for (int x = 0; x < input.length(); x++)
    {
        skip = false; //Must reset each iteration
                      //so that any consonants occuring
                      //after a vowel are still included

        for (int y = 0; y < 10; y++)
        {
            if (input[x] == vowels[y]) //No function needed
                                       //Chars are compared using ASCII codes
            {
                skip = true;
                break;
            }
        }
        if (!skip) //Result is not altered if
                   //current character is a vowel
        {
            result = result + input[x];
        }
    }

    return result;
}

int main()
{
    string response = "";
    float num1 = 0.0f;
    float num2 = 0.0f;

    while (true)
    {
        cout << "Please select one of the following menu options" << "\n";
        cout << "by entering a single digit:" << "\n" << "\n";
        printMenu();
        cout << "Select: ";
        cin >> response;
        cout << "\n";

        if (response.compare("0") == 0)
        {
            cout << "Ending Program . . .";
            break;
        }
        else if (response.compare("1") == 0)
        {
            cout << "Please enter the first factor to test: ";
            cin >> response;

            try
            {
                num1 = stof(response);
            }
            catch (...)
            {
                cout << "Your response could not be converted into a floating point value." << "\n";
                cout << "Please try again." << "\n" << "\n";
                continue;
            }

            cout << "Please enter the second factor to test: ";
            cin >> response;

            try
            {
                num2 = stof(response);
            }
            catch (...)
            {
                cout << "Your response could not be converted into a floating point value." << "\n";
                cout << "Please try again." << "\n" << "\n";
                continue;
            }
            
            cout << "\n" << "Here are all the values 1-1000 divisible by " << num1 << " and " << num2 << ":" << "\n";
            cout << divisibility(num1, num2) << "\n" << "\n";

            response = "";
            num1 = 0.0f;
            num2 = 0.0f;
            continue;
        }
        else if (response.compare("2") == 0)
        {
            cout << "Enter a string of characters: ";
            getline(cin >> ws, response);

            cout << "\n" << "You entered: " << response;
            cout << "\n" << "The reversal of this is: " << reversal(response) << "\n" << "\n";

            response = "";
            continue;
        }
        else if (response.compare("3") == 0)
        {
            cout << "Enter a string of characters: ";
            getline(cin >> ws, response);

            cout << "\n" << "You entered: " << response;
            cout << "\n" << "Without vowels this becomes: " << vowelRemoval(response) << "\n" << "\n";

            response = "";
            continue;
        }
        else
        {
            cout << "Invalid Response. Try Again." << "\n" << "\n";
            continue;
        }
    }
}