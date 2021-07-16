#include "LetterBag.h"
#include <iostream>
#include <stdio.h>

#include <vector>

using namespace std;

LetterBag::LetterBag()
{
    counts[26];
    size = 0;
}

/// string constructor
LetterBag::LetterBag(const string & s){

    int i = 0;
    clear();
    while(s[i] != '\0'){
         if(inRange(s[i])){
             counts[s[i] - 'a']++;
             size+=1;
        }
     i++;
     }
}

/// initialize counts using letters in v, omitting non letters.
/// e.g.  v = {'6','A','b','C','a','G','g','G','g','B','b','%','g'}
/// means counts = {2,3,1,0,0,0,5,...} and size = 10.
LetterBag::LetterBag(const vector<char> & v){

    int i  = 0;
    while(v[i]){
         if(inRange(v[i])== true){
             counts[tolower(v[i]) - 'a']++;
             size+=1;
        }
        i++;
     }
}
bool LetterBag::inRange(char ch){

    char b = tolower(ch);

    if(b >= 'a' || b <= 'z'){
        return true;
    }

    else
        return false;
}

int LetterBag::getCurrentSize()const{

    return size;
}

bool LetterBag::isEmpty()const{

    if(this -> size == 0)
            return true;

}

/// insert ch into a copy of the current object and return the copy.
/// if ch is out of range, do nothing.
LetterBag LetterBag::operator+(char ch) const{

        int place_holder = 0;

        LetterBag temp;  /// object to be returned from the function

        if(inRange(ch)== true){

            while(place_holder < this -> size)
                temp.counts[place_holder] = this -> counts[place_holder];
                temp.size++;   /// increment size by one
                place_holder++;
        }
        place_holder = tolower(ch) - 'a';
        temp.counts[place_holder]++;
       return temp;
}


/// insert ch into the current object and return the current object
/// if ch is out of range, do nothing.
LetterBag &LetterBag::operator+=(char ch){

    LetterBag other;
    int location = 0;

    if(inRange(ch)== true){

        location = ch - 'a';
        this ->counts[location] += other.counts[location];
        this ->size += other.size;
    }
    return *this;
}

 /// add the contents of other to a copy of the current object and return the copy.
LetterBag LetterBag::operator+(const LetterBag & other) const{

        LetterBag temp;

        for (int i = 0; i < 26; i++){

            temp.counts[i] = this -> counts[i] + other.counts[i];
                temp.size = this -> size + other.size;
        }
        return temp;

}

/// add the contents of other the current object and return the current object.
LetterBag &LetterBag::operator+=(const LetterBag & other){

        LetterBag *temp = NULL;

    for(int i = 0; i < 26; i++){
            temp -> counts[i] += other.counts[i];
    }
            temp -> size += other.size;

    return *temp;
}

/// remove one occurrence of ch from a copy of the current object and return the copy.
/// if ch is out of range or has count equal to zero do nothing.
LetterBag LetterBag::operator-(char ch) const{

        int place_holder = 0;

        LetterBag temp;  /// object to be returned from the function

        if(inRange(ch) && this -> size > 0 && temp.counts[place_holder] >=1 ){

            place_holder = tolower(ch) - 'a';
            temp.counts[place_holder] = counts[place_holder] - 1;
            temp.size--;                                            /// increment size by one
        }
       return temp;

}


/// remove one occurrence of ch from the current object and return the current object.
/// if ch is out of range or has count equal to zero do nothing.
LetterBag &LetterBag::operator-=(char ch){

    return *this = *this - ch;

}


/// remove all occurence occurrence of ch from the current object.
/// if ch is out of range or has count equal to zero do nothing.
void LetterBag::removeAll(char ch){

    int place_holder = 0;
    int val = 0;
    if(inRange(ch) == false || size  == 0){

            return;
    }
        else
            place_holder = tolower(ch) - 'a';
            val = counts[place_holder];
            this -> counts[place_holder] = 0;
            size = size - val;

}


/// remove all occurrences of all letters from the current object and set size to zero.
void LetterBag::clear(){

    for(int i = 0; i < 26; i++){

        this -> counts[i] = 0;
    }
    this -> size = 0;
}


/// return the number of occurence of ch in the current object.
int LetterBag::getFrequency(char c) const{

     int place_holder = 0;
    if (inRange(c)== true){

        place_holder = tolower(c) - 'a';
    }
    return this -> counts[place_holder];
}

/// return a string with the letters in this object, in sorted order and lowercase.
string LetterBag::toString() const{

        string word;

        for(int i = 0; i < 26; i++){

         if(counts[i] > 0){
            for(int b = 0; b < counts[i]; b++)
            word += (i + 'a');
        }
    }
     return word;
}

/// return a vector with the letters in this object, in sorted order and lowercase.
vector<char> LetterBag::toVector()const{

    vector<char> s('a');
    int a = 0;

    for (int i = 0 ; i < this -> size; i++){

        if (this -> counts[i] > 0){

            for(int b = 0; b < this -> counts[i]; b++){

                s.push_back(char(counts[i] + 'a'));
        }
    }

 }
   return s;
}
/// return true if the current object is a proper subbag of other.
bool LetterBag::operator<(const LetterBag & other) const{

    int i = 0;
    while (this -> counts[i]){

        if(this -> counts[i] <  other.counts[i]){
            return false;
        }
        i++;
    }
}

/// return true if the current object is a subbag of other.
bool LetterBag::operator<=(const LetterBag & other) const{

        return *this <= other;
}

/// return true if the other is a proper subbag of the current object.
bool LetterBag::operator>(const LetterBag & other) const{

    int i = 0;
    while (other.counts[i]){

        if( other.counts[i] > this -> counts[i]){
            return false;
        }
        i++;
    }
}

/// return true if the other is a subbag of the current object.
bool LetterBag:: operator>=(const LetterBag & other) const{

    return *this >= other;
}

/// return true iff the current object and other are equal.
bool LetterBag::operator==(const LetterBag & other) const{

    int i = 0;
    while(this -> counts[i]== other.counts[i]){

        if(this -> counts[i] != other.counts[i]){
                return false;
        }
    }
    return true;
}

/// return false iff the current object and other are equal.
bool LetterBag::operator!=(const LetterBag & other) const{

    return !(*this == other);
}

ostream& operator<< (ostream &out, const vector <char> &v){

    int index = 0;

    while(v[index]){
        out << v[index++];
    }
        return out;
}


ostream &operator<< (ostream &out, const LetterBag &s){

    int index = 0;

    while(s.counts[index]){
        out << s.counts[index];
        index++;
    }
        return out;
}
