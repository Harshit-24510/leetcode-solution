class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        // MM-DD
        int daysInMonth[]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        string arrive = max(arriveAlice, arriveBob); 
        string leave  = min(leaveAlice, leaveBob);    
        if (leave < arrive) return 0;
        int m1 = stoi(arrive.substr(0, 2));
        int d1 = stoi(arrive.substr(3, 2));
        int m2 = stoi(leave.substr(0, 2));
        int d2 = stoi(leave.substr(3, 2));

        int days = 0;

        if (m1 == m2) {
          
            days = d2 - d1 + 1;
        } else {
           
            days += daysInMonth[m1 - 1] - d1 + 1;

            for (int m = m1 + 1; m < m2; m++) {
                days += daysInMonth[m - 1];
            }
            days += d2;
        }

        return days;
    }
};