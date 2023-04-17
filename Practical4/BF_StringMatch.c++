#include <iostream>
using namespace std;

void naivePatternSearch(string mainString, string pattern, int array[], int *index) { //function to search the pattern
   int patLen = pattern.size(); //len of the pattern

   int strLen = mainString.size(); //len of the string

   for(int i = 0; i<=(strLen - patLen); i++) {
      int j;
      for(j = 0; j<patLen; j++) {//check for each character of pattern if it is matched
         if(mainString[i+j] != pattern[j])
            break;
      }

      if(j == patLen) {     //the pattern is found
         (*index)++;
         array[(*index)] = i; //return the index of the first occurence of the pattern
      }
   }
}

int main() {
   string mainString = "DATASTRUCUTURE";
   string pattern = "AT";
   int locArray[mainString.size()];
   int index = -1;
   naivePatternSearch(mainString, pattern, locArray, &index);

   for(int i = 0; i <= index; i++) {
      cout << "Pattern found at position: " << locArray[i]<<endl;
   }
}
