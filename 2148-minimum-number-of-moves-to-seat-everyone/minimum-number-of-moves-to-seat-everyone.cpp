class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        priority_queue<int> seat;
        priority_queue<int> student;
        for(int i=0;i<seats.size();i++){
            seat.push(seats[i]);
            student.push(students[i]);
        }
        int c=0;
        while(!seat.empty()){
            c+=abs(seat.top() - student.top());
            seat.pop();
            student.pop();
        }
        return c;
    }
};