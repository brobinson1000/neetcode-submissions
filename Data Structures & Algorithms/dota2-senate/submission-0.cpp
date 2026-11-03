class Solution {
public:
    string predictPartyVictory(string senate) {
        const int n = senate.length();
        std::queue<int> qD;
        std::queue<int> qR;

        for (int i{}; i < n; i++) {
            if (senate[i] == 'R') {
                qR.push(i);
            } else {
                qD.push(i);
            }
        }

        while(!qR.empty() && !qD.empty()) {
            int rIndex = qR.front();
            qR.pop();
            int dIndex = qD.front();
            qD.pop();

            if (rIndex < dIndex) {
                qR.push(rIndex + n);
            } else {
                qD.push(dIndex + n);
            }
        }

        return qR.empty() ? "Dire" : "Radiant";

    }
};