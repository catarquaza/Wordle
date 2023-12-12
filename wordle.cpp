#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>  // for rand and srand
#include <ctime>    // for time
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
using namespace std;

string makeWord()
{
    // Open the input .txt file
    ifstream inputFile("wordles.txt");
    // Read all words from the file into a vector
    vector<string> words;
    string word;
    while (inputFile >> word)
    {
        words.push_back(word);
    }
    // Close the input file
    inputFile.close();
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0)));
    // Generate a random index to pick a word from the vector
    size_t randomIndex = rand() % words.size();
    word = words[randomIndex];

    // Open the output C++ file
    ofstream outputFile("output.cpp");

    // Check if the file is open successfully
    if (!outputFile.is_open())
    {
        cerr << "Error opening output file!" << endl;
        exit(1);
    }

    // Write the word into the C++ file
    outputFile << "#include <iostream>\n\n";
    outputFile << "int main() {\n";
    outputFile << "    std::cout << \"" << word << "\" << std::endl;\n";
    outputFile << "    return 0;\n";
    outputFile << "}\n";

    // Close the output file
    outputFile.close();

    return word;
}
string checkWord(int x)
{
        // Open the input .txt file
    ifstream inputFile("wordles.txt");
    // Read all words from the file into a vector
    vector<string> words;
    string word;
    while (inputFile >> word)
    {
        words.push_back(word);
    }
    // Close the input file
    inputFile.close();
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0)));
    // Generate a random index to pick a word from the vector
    size_t randomIndex = rand() % words.size();
    word = words[x];

    // Open the output C++ file
    ofstream outputFile("output.cpp");

    // Check if the file is open successfully
    if (!outputFile.is_open())
    {
        cerr << "Error opening output file!" << endl;
        exit(1);
    }

    // Write the word into the C++ file
    outputFile << "#include <iostream>\n\n";
    outputFile << "int main() {\n";
    outputFile << "    std::cout << \"" << word << "\" << std::endl;\n";
    outputFile << "    return 0;\n";
    outputFile << "}\n";

    // Close the output file
    outputFile.close();

    return word;
}
int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int turn = 0;
    bool real;
    bool winner;
    string choice[6];
    string word = makeWord();
    while (turn < 6)
    {
        cout << "Choose a 5 letter word: ";
        while (true)
        {
            cin >> choice[turn];
            if (choice[turn].length() == 5)
            {
                break;
            }
        } 
        for (int s = -1; s < turn; s++)
        {
            for (int i = 0; i < 5; i++)
            {
                string a = choice[s+1].substr(i, 1);
                if (word.find(a) != string::npos)
                {
                    for (int c = 0; c < 6; c++)
                    {
                        string b = word.substr(c, 1);
                        if (b == a && c == i)
                        {
                            SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE);
                            cout << a;
                            break;
                        }
                        else if (c == 5)
                        {
                            SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_GREEN);
                            cout << a;
                        }
                    }
                }
                else
                {
                    SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    cout << a;
                }
            }
            cout << "\n";
        }
        for (int s = turn; s < 5; s++)
        {
            for (int i = 0; i < 5; i++)
            {
                SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                cout << "_";
            }
            cout << "\n";
        }
        if (word == choice[turn])
        {
            cout <<"Congrats you have won";
            winner = true;
            break;
        }
        turn ++;
    }
    if (winner == false)
    {
        cout << "Too bad you have lost the word is:" << word;
    }
}