#include<iostream>

#include<vector>

using namespace std;

bool IsVectorEven(vector<int> myVec);
bool IsVectorOdd(vector<int> myVec);

int main(){
 int totalNum = 0;
     int userNum = 0;
     vector<int> vctrList;
     cin >> userNum;
 for (int i = 0; i < userNum; i++) {
      cin >> totalNum;
      vctrList.push_back(totalNum);
 }
 if (IsVectorEven(vctrList) == true){
       cout << "all even" << endl;
 }
    else if (IsVectorOdd(vctrList) == true) {
      cout << "all odd" << endl;
 }
      else
         cout << "not even or odd" << endl;
          return 0;

}

bool IsVectorEven(vector<int> myVec) {
int j = 0;
for (int i = 0; i < myVec.size(); i++){
   if (myVec.at(i) % 2==0)
         j++;
}
   if (j == myVec.size())
         return true;
      else
         return false;
}
bool IsVectorOdd(vector<int> myVec) {
int j = 0;
for (int i = 0; i < myVec.size(); i++) {
   if (myVec.at(i) % 2!=0)
      j++;
   }
   if (j == myVec.size())
       return true;
       else
         return false;
}
