#include <iostream>
#include <vector>
#include <stdio.h>
#include "LetterBag.h"

using namespace std;

int main()
{

    LetterBag obj1("aaabb");
    LetterBag obj2("cdejhghkghjgjhgj");
    LetterBag bag1 = obj1 + obj2;
    vector<char> v;
    v.push_back('a');
    v.push_back('c');
    LetterBag vec(v);
    cout << "\n\n\t\t\t\t Letter bags \n\n";



    cout << "\n here is the contents of the first bag: "<< obj1.toString()<< endl;

    cout << "\n this is the size of the first bag: "<< obj1.getCurrentSize()<< endl;
    cout << "\n here is the contents of the second bag: "<< obj2.toString() << endl;
    cout << "\n this is the size of the second bag: "<< obj2.getCurrentSize()<< endl;
    cout << "\n here is the contents of bagl and bag2 added together: "<< bag1.toString()<<endl;
    cout << "\n this is the size of bad1 and bag2 together: "<< bag1.getCurrentSize() << endl;
    
    // remove all 'h' within the second bag of letters
    cout << "\n we will now extract all of the 'h's' from the bag\n " << endl;
    obj2.removeAll('h');
    

    cout << "\n this is the content in the second bag after removing all 'h' within the bag " << obj2.toString() << endl;
    cout << "\n this is the size of the second bag after removing all of the 'h's within the bag '" << obj2.getCurrentSize() <<endl;
    cout << "\n this is the size of the vec bag: "<< vec.getCurrentSize() << endl;
    cout << "\n this is the content that is in the vect bag: "<< vec.toString();
    cout << "\n\n";
    return 0;

}
