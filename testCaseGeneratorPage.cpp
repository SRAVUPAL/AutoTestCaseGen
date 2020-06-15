#include <iostream>
#include <string.h>
#include <vector>
#include "serviceFunctions.h"
using namespace std;
/*
 *
 */
vector<vector<string>> testCaseGeneratorFunction(vector<string> PCVector)
{
    vector<string> pcVec_cpy;
    vector<vector<string>> return_TCVec;

    pcVec_cpy = PCVector;
    for(int numberOfTC=0; numberOfTC<3; numberOfTC++)
    {
        vector<string> return_Vec;
        for (size_t i=0; i < pcVec_cpy.size(); i++)
        {
            if(int(pcVec_cpy[i][0]) == 33)
            {
                pcVec_cpy[i].erase(pcVec_cpy[i].begin(),pcVec_cpy[i].begin() + 2);
                pcVec_cpy[i].erase(pcVec_cpy[i].begin() + pcVec_cpy[i].size() - 1);
                if(pcVec_cpy[i].find("<")!= string::npos)
                {
                    replaceFunction(pcVec_cpy[i], "<", ">");
                }
                else if(pcVec_cpy[i].find(">")!= string::npos)
                {
                    replaceFunction(pcVec_cpy[i], ">", "<");
                }
                else if(pcVec_cpy[i].find("!")!= string::npos&&pcVec_cpy[i].find("!=")== string::npos)
                {
                    replaceFunction(pcVec_cpy[i], "!", "");
                }
                else if(pcVec_cpy[i].find("!=")!= string::npos)
                {
                    replaceFunction(pcVec_cpy[i], "!=", "==");
                }
                else if(pcVec_cpy[i].find("==")!= string::npos)
                {
                    replaceFunction(pcVec_cpy[i], "==", "!=");
                }
                else if(pcVec_cpy[i].find("=")!= string::npos && pcVec_cpy[i].find("==") == string::npos && pcVec_cpy[i].find("!=")==string::npos)
                {
                    replaceFunction(pcVec_cpy[i], "=", "!=");
                }
                else if(pcVec_cpy[i].find("NotSet")!= string::npos)
                {
                    pcVec_cpy[i]="page==0";
                }
            }
            if(pcVec_cpy[i].find("<")!= string::npos || pcVec_cpy[i].find("<=")!= string::npos)
            {
                if(!(int(pcVec_cpy[i][pcVec_cpy[i].size() - 1]) == 48 && int(pcVec_cpy[i][pcVec_cpy[i].size() - 2]) == 60))
                {
                    if(int(pcVec_cpy[i][pcVec_cpy[i].size() - 1]) == 48)
                    {
                        pcVec_cpy[i][pcVec_cpy[i].size() - 2] = char(int(pcVec_cpy[i][pcVec_cpy[i].size() - 2]) - 1);
                        pcVec_cpy[i][pcVec_cpy[i].size() - 1] = char(57);
                    }
                    else
                    {
                        pcVec_cpy[i][pcVec_cpy[i].size() - 1] = char(int(pcVec_cpy[i][pcVec_cpy[i].size() - 1]) - 1);
                    }
                }
            }
            else if(pcVec_cpy[i].find(">")!= string::npos || pcVec_cpy[i].find(">=")!= string::npos)
            {
                if(!(int(pcVec_cpy[i][pcVec_cpy[i].size() - 1]) == 57 && int(pcVec_cpy[i][pcVec_cpy[i].size() - 2]) == 62))
                {
                    if(int(pcVec_cpy[i][pcVec_cpy[i].size() - 1]) == 57)
                    {
                        pcVec_cpy[i][pcVec_cpy[i].size() - 2] = char(int(pcVec_cpy[i][pcVec_cpy[i].size() - 2]) + 1);
                        pcVec_cpy[i][pcVec_cpy[i].size() - 1] = char(48);
                    }
                    else
                    {
                        pcVec_cpy[i][pcVec_cpy[i].size() - 1] = char(int(pcVec_cpy[i][pcVec_cpy[i].size() - 1]) + 1);
                    }
                }
                else
                {
                    pcVec_cpy[i][pcVec_cpy[i].size() - 1] = char(49);
                    pcVec_cpy[i].insert(pcVec_cpy[i].end(), 1,'0');
                }
            }
            else if(pcVec_cpy[i].find("!=")!= string::npos && pcVec_cpy[i].find("!=\"") == string::npos)
            {
                if(!(int(pcVec_cpy[i][pcVec_cpy[i].size() - 1]) == 48 && int(pcVec_cpy[i][pcVec_cpy[i].size() - 2]) > 57))
                {
                    if(int(pcVec_cpy[i][pcVec_cpy[i].size() - 1]) == 48)
                    {
                        pcVec_cpy[i][pcVec_cpy[i].size() - 2] = char(int(pcVec_cpy[i][pcVec_cpy[i].size() - 2]) - 1);
                        pcVec_cpy[i][pcVec_cpy[i].size() - 1] = char(57);
                    }
                    else
                    {
                        pcVec_cpy[i][pcVec_cpy[i].size() - 1] = char(int(pcVec_cpy[i][pcVec_cpy[i].size() - 1]) - 1);
                    }
                }
            }
            else if(pcVec_cpy[i].find("NotSet")!= string::npos)
            {
                pcVec_cpy[i] = "page=NULL";
            }
            else if(pcVec_cpy[i].find("page==")!= string::npos)
            {
                if(int(pcVec_cpy[i][pcVec_cpy[i].size() - 1]) == 57)
                {
                    pcVec_cpy[i][pcVec_cpy[i].size() - 2] = char(int(pcVec_cpy[i][pcVec_cpy[i].size() - 2]) + 1);
                    pcVec_cpy[i][pcVec_cpy[i].size() - 1] = char(48);
                }
                else
                {
                    pcVec_cpy[i][pcVec_cpy[i].size() - 1] = char(int(pcVec_cpy[i][pcVec_cpy[i].size() - 1]) + 1);
                }
            }
            return_Vec.push_back(pcVec_cpy[i]);
        }
        return_TCVec.push_back(return_Vec);
    }
    return return_TCVec;
}
