#include <iostream>
#include <string>
using namespace std;
    
struct SCP {
    int id;
    int objClass;
    string speConProcedures;
    string description;
    string* addendums;
    int numAddendums;
};

string convertToString(SCP obj) {
    string tmp;
    tmp = "Item #: SCP-";
    int n = to_string(obj.id).length();
    for (int i  = 1; i <= 3 - n; i++) {tmp += "0";}
    tmp = tmp + to_string(obj.id);
    string tmp2 = ((obj.objClass == 0) ? "Safe" : ((obj.objClass == 1) ? "Euclid" : "Keter"));
    tmp += "\nObject Class: " + tmp2 + "\nSpecial Containment Procedures: " + obj.speConProcedures + "\nDescription: " + obj.description + "\n";
    for (int i = 0; i < obj.numAddendums; i++){
        tmp += obj.addendums[i] + "\n";
    }
    return tmp;
}

int main()
{
     string* addendums = new string[2];
    addendums[0] = "Document #055-1: An Analysis of SCP-055\nThe author puts forward the hypothesis that SCP-055 was never formally acquired.";
    addendums[1] = "Document #055-2: Report of Dr. John Marachek\nSurvey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.";

    SCP obj {55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", addendums, 2};

    cout << convertToString(obj);

    delete [] addendums;   
    return 0;
}