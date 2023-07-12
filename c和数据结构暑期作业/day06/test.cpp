class Solution {
private:
    int mulCore(int num, int count, int res) {
        if (count == 0)
            return num;
        
        res += mulCore(num, count - 1, res);
        return res;
    }
public:
    int multiply(int A, int B) {
        return mulCore(A, B, A) - A;
    }
};

int main() {
    Solution s;
    s.multiply(3, 5);
    return 0;
}