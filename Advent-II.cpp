#include <iostream>
#include <string.h>
using namespace std;
struct Coords
{
    int x, y, aim;
};
string getCmd(string input)
{
    return input.substr(0, input.find(" "));
}
int getValue(string input)
{
    return stoi(input.substr(input.find(" "), input.length()));
}
Coords updateCoords(Coords my_coords, string command, int value)
{
    string forward_str = "forward";
    string down_str = "down";
    string up_str = "up";
    // cout << "order:" << command << endl;
    // cout << "value:" << value << endl;
    if (command[0] == forward_str[0])
    {
        my_coords.x += value;
        my_coords.y += my_coords.aim * value;
        return my_coords;
    }
    if (command[0] == down_str[0])
    {
        my_coords.aim += value;
        return my_coords;
    }
    if (command[0] == up_str[0])
    {
        my_coords.aim -= value;
        return my_coords;
    }
    return my_coords;
}
int main(void)
{
    Coords my_coords;
    my_coords.x = 0;
    my_coords.y = 0;
    my_coords.aim = 0;
    string read_str = "";
    while (getline(cin, read_str))
        my_coords = updateCoords(my_coords, getCmd(read_str), getValue(read_str));
    cout << my_coords.x << " * " << my_coords.y << " = " << my_coords.x * my_coords.y << endl;
}