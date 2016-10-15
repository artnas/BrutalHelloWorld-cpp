#include <stdlib.h>
#include <iostream>

using namespace std;

long int seed_hello = -998802039;
long int seed_world = -1883776585;

bool correctSeed_Hello = false;
bool correctSeed_World = false;

string GetWord(long int seed){

    string text = "12345";

    srand(seed);

    for (int j = 0; j < 5; j++){

        text[j] = 65 + (rand() % 58);

    }

    return text;

}

void FindWordSeeds(){

    cout << "Looks like the default seeds did not work. Commencing manual search..." << endl;
    cout << "This can take a few minutes, we have 2^32 seeds to check." << endl;

    string text = "12345";

    string hello = "Hello";
    string world = "World";

    long int i;

    for (long int i = -2147483647; i < 2147483647; i++){     // check from -2^31 to 2^31

        srand(i);

        for (int j = 0; j < 5; j++){                         // set every char in "text" to a random character in range
                                                              // A -> z in ASCII
            text[j] = 65 + (rand() % 58);

        }

        if (i % 10000000 == 0) cout << i << endl;           // print a checkpoint on every 10kk tries

        if (text == hello){

            cout << hello << " : " << i << endl;

            correctSeed_Hello = true;

            if (correctSeed_Hello && correctSeed_World)
                break;

        }

        if (text == world){

            cout << world << " : " << i << endl;

            correctSeed_World = true;

            if (correctSeed_Hello && correctSeed_World)
                break;

        }

    }

    cout << "Found the correct seeds!." << endl;

}

void PrintHelloWorld(){

    cout << GetWord(seed_hello) << " " << GetWord(seed_world) << "!" <<  endl;

}

int main(){

    correctSeed_Hello = GetWord(seed_hello) == "Hello";     // Check if the default seeds (the ones which worked on my PC) produce the correct output
    correctSeed_World = GetWord(seed_world) == "World";

    if (!correctSeed_Hello || !correctSeed_World)
        FindWordSeeds();                                    // They did not work :( we have to find the seeds manually

    PrintHelloWorld();

    return 0;

}
