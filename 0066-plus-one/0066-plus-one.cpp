class Solution {
public:
    vector<int> plusOne(vector<int>& numbers) {
        reverse(begin(numbers), end(numbers));
        int carry = 1;
        for(int i = 0; i < numbers.size(); ++i) {
            if(carry) {
                numbers[i] += 1;
                if(numbers[i] == 10) {
                    numbers[i] = 0;
                } else {
                    carry = 0;
                }
            } else {
                break;
            }
        }
        if(carry) {
            numbers.push_back(1);
        }
        reverse(begin(numbers), end(numbers));
        return numbers;
    }
};