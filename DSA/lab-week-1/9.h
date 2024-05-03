string implement(string s) {
    if (s.length() == 0) return "";
    return implement(s.substr(s.find(" ") + 1, s.length())) + " " + s.substr(0, s.find(" "));
}

string reverseSentence(string s) {
    // STUDENT ANSWER
    s += " ";
    string res = implement(s);
    res.replace(0,1, "");
    return res;
}

//cout << reverseSentence("data structure and algorithm is scary");
