#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>


using namespace std;


int getValue(const string& word, const unordered_map<char, int>& map) {
    int value = 0;
    for (char c : word) {
        value = value * 10 + map.at(c);
    }
    return value;
}


bool isValid(const vector<int>& perm, const vector<char>& letters, const string& equation) {
    unordered_map<char, int> map;
    for (size_t i = 0; i < letters.size(); i++) {
        map[letters[i]] = perm[i];
    }


    vector<string> parts;
    size_t pos = 0, found;
    while ((found = equation.find(' ', pos)) != string::npos) {
        parts.push_back(equation.substr(pos, found - pos));
        pos = found + 1;
    }
    parts.push_back(equation.substr(pos)); 


 
    int sum1 = getValue(parts[0], map);   
    int sum2 = getValue(parts[2], map);   
    int result = getValue(parts[4], map);    


    return sum1 + sum2 == result;
}


void solve(const string& equation) {
    unordered_set<char> lettersSet;  for (char c : equation) {
        if (isalpha(c)) {
            lettersSet.insert(c);
        }
    }


    
    vector<char> letters(lettersSet.begin(), lettersSet.end());


    
    vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};


    
    do {
        vector<int> perm(digits.begin(), digits.begin() + letters.size());
        if (isValid(perm, letters, equation)) {
            cout << "Solution found:" << endl;
            for (size_t i = 0; i < letters.size(); i++) {
                cout << letters[i] << " = " << perm[i] << endl;
            }
            return;
        }
    } while (next_permutation(digits.begin(), digits.end()));


    cout << "No solution found." << endl;
}


int main() {
    string equation = "LOVE + LIVE = PEACE";
    solve(equation);
    return 0;
}
