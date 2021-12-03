#include <iostream>
#include <string.h>
#include <math.h>
#include <list>
using namespace std;
char getMostRepeated(list<string> list, short column, char draw)
{
    int zeroes = 0;
    int ones = 0;
    for (auto it : list)
    {
        if (it[column] == '1')
            ones++;
        else
            zeroes++;
    }
    if (ones == zeroes)
        return draw;
    else if (ones > zeroes)
        return '1';
    return '0';
}
char getLessRepeated(list<string> list, short column, char draw)
{
    int zeroes = 0;
    int ones = 0;
    for (auto it : list)
    {
        if (it[column] == '1')
            ones++;
        else
            zeroes++;
    }
    if (ones == zeroes)
        return draw;
    else if (ones > zeroes)
        return '0';
    return '1';
}
list<string> removeFromList(list<string> list, char character, short column)
{
    auto it = list.begin();
    while (it != list.end())
    {
        if ((*it)[column] == character)
            it = list.erase(it);
        else
            it++;
    }
    return list;
}
string getOxygenLevel(list<string> list, short length)
{
    for (short index = 0; index < length; index++)
    {
        if (list.size() == 1)
            return list.front();
        else
            list = removeFromList(list, getLessRepeated(list, index, '0'), index);
    }
    return list.front();
}
string getCarbonLevel(list<string> list, short length)
{
    for (short index = 0; index < length; index++)
    {
        if (list.size() == 1)
            return list.front();
        else
            list = removeFromList(list, getMostRepeated(list, index, '1'), index);
    }
    return list.front();
}
short *update_matrix(short *matrix, string input)
{
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == '1')
            matrix[i]++;
        else
            matrix[i]--;
    }
    return matrix;
}
short *getEpsilon(short *matrix, short length)
{
    for (int i = 0; i < length; i++)
        if (matrix[i] > 0)
            matrix[i] = 0;
        else
            matrix[i] = 1;
    return matrix;
}
short *getGamma(short *matrix, short length)
{
    for (int i = 0; i < length; i++)
        if (matrix[i] > 0)
            matrix[i] = 1;
        else
            matrix[i] = 0;
    return matrix;
}
int binToDec(short *matrix, short length)
{
    int return_int = 0;
    for (int i = 0; i < length; i++)
    {
        if (matrix[i] == 1)
        {
            return_int += pow(2, (length - 1) - i);
        }
    }
    return return_int;
}
int binToDec(string matrix, short length)
{
    int return_int = 0;
    for (int i = 0; i < length; i++)
    {
        if (matrix[i] == '1')
        {
            return_int += pow(2, (length - 1) - i);
        }
    }
    return return_int;
}
/*#Case 1
int main(void)
{
    string read_str = "";
    getline(cin, read_str);
    short length = read_str.length();
    short *vector = (short *)calloc(length * sizeof(short), 0);
    vector = update_matrix(vector, read_str);
    while (getline(cin, read_str))
        vector = update_matrix(vector, read_str); 
    vector = getGamma(vector, length);
    cout << "Binary Gamma rate is ";
    for (int i = 0; i < length; i++)
        cout << vector[i];
    int gamma = binToDec(vector, length);
    cout << "\nDecimal Gamma rate is " << gamma << endl;
    vector = getEpsilon(vector, length);
    int epsilon = binToDec(vector, length);
    cout << "Binary Epsilon rate is ";
    for (int i = 0; i < length; i++)
        cout << vector[i];
    cout << "\nDecimal Epsilon rate is " << epsilon << endl
         << "Answer is " << gamma * epsilon << endl;
}*/
//Case 2
int main()
{
    string read_str = "";
    list<string> list;
    getline(cin, read_str);
    list.push_back(read_str);
    short length = read_str.length();
    short *vector = (short *)calloc(length * sizeof(short), 0);
    while (getline(cin, read_str))
        list.push_back(read_str);
    string oxygenLevel = getOxygenLevel(list, length);
    cout << "Oxygen level " << oxygenLevel << " (" << binToDec(oxygenLevel, length) << ")" << endl;
    string carbonLevel = getCarbonLevel(list, length);
    cout << "Oxygen level " << carbonLevel << " (" << binToDec(carbonLevel, length) << ")" << endl;
    cout << binToDec(oxygenLevel, length) * binToDec(carbonLevel, length) << endl;
}