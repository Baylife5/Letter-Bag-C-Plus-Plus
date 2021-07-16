#ifndef LETTERBAG_H
#define LETTERBAG_H

#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;

class LetterBag {

    friend ostream& operator<< (ostream& out, const LetterBag &s);
    friend ostream& operator<< (ostream &out, const vector <char> &v);
    private:

    int counts[26];  /// counts[0] represents the number of 'a's etc.
    static bool inRange(char ch);  /// return true iff ch is in range 'a'...'z' or 'A'...'Z'
    int size; /// total number of letters in the current object (equals the sum of the counts array)


    public:

    LetterBag() ;  /// no-parameter constructor for an empty LetterBag.

    /// initialize counts using letters in v, omitting non letters.
    /// e.g.  v = {'6','A','b','C','a','G','g','G','g','B','b','%','g'}
    /// means counts = {2,3,1,0,0,0,5,...} and size = 10.
    LetterBag(const vector<char> &v);

    /// similar to the vector constructor but using a string to initialize.
    LetterBag(const string &s);

    /// return this->size
    int getCurrentSize() const;  /// return the current size of the LetterBag

    /// return true iff this->size is zero
    bool isEmpty() const;

    /// insert ch into a copy of the current object and return the copy.
    /// if ch is out of range, do nothing.
    LetterBag operator+(char ch) const;

    /// insert ch into the current object and return the current object
    /// if ch is out of range, do nothing.
    LetterBag & operator+=(char ch);

    // add the contents of other to a copy of the current object and return the copy.
    LetterBag operator+(const LetterBag & other) const;

    // add the contents of other  the current object and return the current object.
    LetterBag & operator+=(const LetterBag & other);

    // remove one occurrence of ch from a copy of the current object and return the copy.
    // if ch is out of range or has count equal to zero do nothing.
    LetterBag operator-(char ch) const;

    // remove one occurrence of ch from the current object and return the current object.
    // if ch is out of range or has count equal to zero do nothing.
    LetterBag & operator-=(char ch);

    // remove the contents of other to a copy of the current object and return the copy.
    // note: anytime the count of a letter in other exceeds
    LetterBag operator-(const LetterBag & other) const;

    // remove the contents of other  the current object and return the current object.
    LetterBag & operator-=(const LetterBag & other);

    // remove all occurence occurrence of ch from the current object.
    // if ch is out of range or has count equal to zero do nothing.
    void removeAll(char ch);

    // remove all occurrences of all letters from the current object and set size to zero.
    void clear();

    // return the number of occurence of ch in the current object.
    int getFrequency(char c) const;

    // return a vector with the letters in this object, in sorted order and lowercase.
    vector<char> toVector() const;

    // return a string with the letters in this object, in sorted order and lowercase.
    string toString() const;

    // return true if the current object is a proper subbag of other.
    bool operator<(const LetterBag & other) const;

    // return true if the current object is a subbag of other.
    bool operator<=(const LetterBag & other) const;

    // return true if the other is a proper subbag of the current object.
    bool operator>(const LetterBag & other) const;

    // return true if the other is a subbag of the current object.
    bool operator>=(const LetterBag & other) const;

    // return true iff the current object and other are equal.
    bool operator==(const LetterBag & other) const;

    // return false iff the current object and other are equal.
    bool operator!=(const LetterBag & other) const;

};





#endif
