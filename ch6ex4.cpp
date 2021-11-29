/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Luke Faulkner
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Name_Value {
    private:
        string name;
        int score;
    public:
        void setName(string n){ name = n;};
        void setScore (int s){ score = s;};
        string getName(){return name;};
        int getScore(){return score;};
};

int uniqueNameValue(vector<Name_Value> nameValueSet, Name_Value valueToCheck);

int main(){
    // Variables / Main Vector
    vector<Name_Value> namesAndVals;
    Name_Value terminateVal;
    string ter = "NoName";
    terminateVal.setName(ter);
    terminateVal.setScore(0);
    int terminate = 0;
    string userNameInput;
    int userScoreInput;

    // Allow for inputs
    while (terminate == 0){
        // User input
        cin >> userNameInput;
        cin >> userScoreInput;

        // Value that holds input once parsed
        Name_Value newInput;
        
        // Set fields
        newInput.setName(userNameInput);
        newInput.setScore(userScoreInput);

        // Check if the termination value or a repeat value has been entered - if so, end program
        if ((newInput.getName().compare(terminateVal.getName()) == 0 && newInput.getScore() == terminateVal.getScore()) || uniqueNameValue(namesAndVals, newInput) == 0){
            terminate = 1;
        }
        else {
            namesAndVals.insert(namesAndVals.begin(), newInput);
        }
    }

    return 0;

}

int uniqueNameValue(vector<Name_Value> nameValueSet, Name_Value valueToCheck){
    for (int i = 0; i < nameValueSet.size(); i++){
        if (nameValueSet[i].getName().compare(valueToCheck.getName()) == 0 && nameValueSet[i].getScore() == valueToCheck.getScore()){
            return 0;
        }
    }
    return 1;
}