#include <iostream>

using namespace std;

int main()
{
    string animal, name, adjective, object, pastTenseVerb;

    cout << "Enter an animal: ";
    getline(cin >> ws, animal);
    cout << "Enter a name: ";
    getline(cin >> ws, name);
    cout << "Enter an adjective: ";
    getline(cin >> ws, adjective);
    cout << "Enter an object: ";
    getline(cin >> ws, object);
    cout << "Enter a past tense verb: ";
    getline(cin >> ws, pastTenseVerb);

    cout << "Once upon a time, there was a(n) " << animal << " named " << name << "." << endl;
    cout << name << " was a very " << adjective << " " << animal << "." << endl;
    cout << "That was why everyone would make fun of " << name << "." << endl;
    cout << "But one day, " << name << " found a magical " << object << " in his backyard." << endl;
    cout << name << " picked up the " << object << " and " << pastTenseVerb << " it." << endl;
    cout << "The next day, " << name << " became king of the world, and " << name << " lived happily ever after." << endl;
    return 0;
}
