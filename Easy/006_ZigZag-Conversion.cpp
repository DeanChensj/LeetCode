#include <iostream>
#include <vector>
#include <string>
using namespace std;
   string convert(string s, int numRows) {
        if(numRows < 2) return s;
        char** charQueues = new char*[numRows];
        int *ptArray = new int[numRows];
        for(int i = 0; i < numRows; i++) {
            charQueues[i] = new char[s.length()];
            ptArray[i] = 0;
        }
        
        int pt = 0;
        bool flag = false;
        for (int i = 0; i < s.length(); i++) {
     
            if(pt == 0 || pt == (numRows - 1)) flag = !flag;
            charQueues[pt][ptArray[pt]++] = s[i];
            
            if (flag) {
                pt++;
            } else {
                pt--;
            }
  
        }
        string res = "";

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < ptArray[i]; j++) {
                res += charQueues[i][j];
            }
        }
        return res;
    }


int main(int argc, char const *argv[])
{


	cout << convert("twckwuyvbihajbmhmodminftgpdcbquupwflqfiunpuwtigfwjtgzzcfofjpydjnzqysvgmiyifrrlwpwpyvqadefmvfshsrxsltbxbziiqbvosufqpwsucyjyfbhauesgzvfdwnloojejdkzugsrksakzbrzxwudxpjaoyocpxhycrxwzrpllpwlsnkqlevjwejkfxmuwvsyopxpjmbuexfwksoywkhsqqevqtpoohpd",
4);   
	return 0;
}