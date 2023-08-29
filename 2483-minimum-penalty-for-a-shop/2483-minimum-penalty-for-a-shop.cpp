class Solution {
public:
    int bestClosingTime(string customers) {
        int curPenalty = count(customers.begin(), customers.end(), 'Y');
        int minPenalty = curPenalty;
        int earliestHour = 0;
        
        cout<<minPenalty<<endl;

        for (int i = 0; i < customers.size(); i++) {
            char ch = customers[i];
            
            if (ch == 'Y') {
                curPenalty--;
            } else {
                curPenalty++;
            }
            
            cout<<i<<" "<<curPenalty<<endl;

            // Update earliestHour if a smaller penatly is encountered.
            if (curPenalty < minPenalty) {
                earliestHour = i + 1;
                minPenalty = curPenalty;
            }
        }

        return earliestHour;
    }
};