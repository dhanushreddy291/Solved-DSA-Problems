void GenerateParenthesis (int CountofOpeningBrackets, int CountofClosingBrackets, string temp, vector<string> &Answers)
{
    if (CountofClosingBrackets == 0 && CountofOpeningBrackets == 0)
    {
        Answers.push_back(temp);
        return;
    }

    if (CountofOpeningBrackets > 0)
    GenerateParenthesis (CountofOpeningBrackets - 1, CountofClosingBrackets, temp + '(', Answers);

    if (CountofClosingBrackets > CountofOpeningBrackets)
    GenerateParenthesis (CountofOpeningBrackets, CountofClosingBrackets - 1, temp + ')', Answers);

    return;
}


vector<string> Solution::generateParenthesis(int A) {
    
    string temp = "";
    vector <string> Answers;
    GenerateParenthesis(A, A, temp, Answers);

    return Answers;
    
}
