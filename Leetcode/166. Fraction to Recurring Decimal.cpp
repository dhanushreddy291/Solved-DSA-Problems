class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string negative = "";
        if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) negative = "-";
        long numr = abs(numerator), denr = abs(denominator);
        string start = "0";
        if (numr == 0 || numr >= denr) {
            start = to_string(numr / denr);
            numr %= denr;
            if (numr == 0) return negative + start;
        }
        bool repeated = false;
        long num = 0;
        unordered_map <long, int> Map;
        numr *= 10;
        string fraction = start + ".";
        while (numr) {
            if (Map.find(numr) != Map.end()) {
                repeated = true;
                num = numr;
                break;
            }
            Map[numr] = fraction.size();
            fraction += to_string(numr / denr);
            numr %= denr;
            numr *= 10;
        }
        if (!repeated) return negative + fraction;
        return negative + fraction.substr(0, Map[num]) + "(" + fraction.substr(Map[num], fraction.size() - Map[num]) + ")";
    }
};