#include "../Header.h"

using namespace std;
string intToRoman(int num) {
    char item[] = "IVXLCDM";
    string result = "";
    int pos = 0, digit;
    while (num) {
        digit = num % 10;
        num /= 10;
        if (0 < digit && digit < 4) {
            string t(digit, item[pos]); 
            result = t + result; 
        } else if (digit == 4) {
            result = item[pos+1] + result;
            result = item[pos] + result;
        } else if (digit == 5) {
            result = item[pos+1] + result;
        } else if (digit != 0 && digit != 9) {
            digit -= 5;
            string t(digit, item[pos]); 
            result = item[pos+1] + t + result; 
        } else if (digit == 9) {
            result = item[pos+2] + result;
            result = item[pos] + result;
        }
        pos += 2;
    }
    return result;
}
int main(int argc, char const *argv[])
{
    srand((int)time(NULL));
	int num = random(3999);
    
    cout << num << "->" << intToRoman(num) << endl;
	return 0;
}
