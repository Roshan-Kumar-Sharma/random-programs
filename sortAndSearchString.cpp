#include <bits/stdc++.h>  
 
using namespace std;

void findIndexOfLastName(vector<pair<string, int>>& names, int numOfStudents){
    int spaceIndices[2], spaceCount = 0;

    for(int i=0; i<numOfStudents; i++){
        string temp = names[i].first;
        int k=0;
        for(int j=0; j<temp.length(); j++){
            if(temp[j] == ' '){
                spaceCount++;
                spaceIndices[k++] = j;
            }
        }
        if(spaceCount == 1){
            names[i].second = spaceIndices[0];
        }
        else if (spaceCount == 2)
        {
            names[i].second = spaceIndices[1];
        }
    }

}
 
int main()
{
    vector<pair<string, int>> names;
    int numOfStudents = 2;
    string fullName;

    for(int i=0; i<numOfStudents; i++){
        getline(cin, fullName);
        names.push_back(make_pair(fullName, -1));
    }

    findIndexOfLastName(names, numOfStudents);
    
    // for(int i = 0; i < numOfStudents; i++){
    //     cout << names[i] << endl;
    // }
    for(auto i = names.begin(); i != names.end(); i++){
        cout << (*i).first << endl;
    }


    return 0;
}