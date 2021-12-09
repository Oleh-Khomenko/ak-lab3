#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int START_INDEX = 1;

bool valid_letter(char let) {
    int code = (int)let;
    if ((64 < code && code < 91) || (96 < code && code < 123))
    {
        return true;
    }
    return false;
}

bool valid_arg(string arg) {
    if (arg[arg.size() - 1] == '-')
    {
        return false;
    }
    
    if (arg.size() > 2)
    {
        if (arg[0] == '-')
        {
            if (arg.size() == 3 && valid_letter(arg[1]) && valid_letter(arg[2]))
            {
                return true;
            }
            if (arg[1] == '-' && valid_letter(arg[2]))
            {
                return true;
            }
        }
        
    }
    if (arg.size() == 2 && valid_letter(arg[1]))
    {
        return true;
    }
    return false;
}

bool in(vector<string> vc, string arg, int start) {
    if (start > vc.size() - 1)
    {
        return false;
    }
    
    for (int i = start; i < vc.size(); i++)
    {
        if (vc[i] == arg)
        {
            return true;
        }
        if (arg.size() == 2)
        {
            if (vc[i][0] == arg[0] && vc[i][1] == arg[1])
            {
                return true;
            }
            if (vc[i].size() == 3 && vc[i][0] == arg[0] && vc[i][2] == arg[1])
            {
                return true;
            }
        }
        if (arg.size() > 2 && arg[0] == '-' && arg[1] == '-')
        {
            if (arg[1] == vc[i][0] && arg[2] == vc[i][1])
            {
                return true;
            }
            
        }
        
    }
    return false;
}

int main(int argc, char* argv[])
{
    vector<string> vc;
    for (int i = START_INDEX; i < argc; i++)
    {   
        string arg(argv[i]);
        if (valid_arg(arg))
        {
            vc.push_back(arg);
        } else {
            cout << "invalid argument: " << arg << endl;
        }        
    }


    for (int i = 0; i < vc.size(); i++)
    {
        if (!in(vc, vc[i], i + 1))
        {
            cout << vc[i] << endl;
        }        
    }
}
