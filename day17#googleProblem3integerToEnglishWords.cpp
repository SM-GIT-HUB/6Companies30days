class Solution {
public:
    vector<string> belowTwenty = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    vector<string> thousands = {"", "Thousand", "Million", "Billion"};

    string makeWords(int num)
    {
        string ans = "";

        if (num >= 1000)
        {
            int i = 0;
            long long p = 1000;

            while (num >= p)
            {
                i++;
                p = p * 1000;
            }

            p = p / 1000;

            ans += makeWords(num / p) + " " + thousands[i];

            if (num % p) {
                ans += " " + makeWords(num % p);
            }
        }
        else if (num >= 100)
        {
            int i = 0;
            int p = 100;

            while (num >= p)
            {
                i++;
                p = p * 100;
            }

            p = p / 100;

            ans += belowTwenty[num / p] + " " + "Hundred";

            if (num % p) {
                ans += " " + makeWords(num % p);
            }
        }
        else if (num >= 20)
        {
            ans += tens[num / 10];

            if (num % 10) {
                ans +=  " " + makeWords(num % 10);
            }
        }
        else if (num > 0)
        {
            ans += belowTwenty[num];
        }

        return ans;
    }

    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }

        string ans = makeWords(num);

        return ans;
    }
};
