class Solution {
private:
    void addTheNumber(vector<char> &chars, int count, int &index, int &length) {
        int startIndex = index;
        while (count) {
            int rem = count % 10;
            chars[index++] = (rem + '0');
            length++;
            count /= 10;
        }
        reverse(chars.begin() + startIndex, chars.begin() + index);
        return;
    }
public:
    int compress(vector<char>& chars) {
        int N = chars.size(), length = 0, i = 0, index = 0;
        while (i < N) {
            char ch = chars[i];
            if (i == N - 1 || chars[i + 1] != ch) {
                chars[index++] = chars[i++];
            } else {
                int count = 0;
                while (i < N && chars[i] == ch) {
                    count++;
                    i++;
                }
                chars[index++] = ch;
                addTheNumber(chars, count, index, length);
            }
            length++;
        }
        return length;
    }
};