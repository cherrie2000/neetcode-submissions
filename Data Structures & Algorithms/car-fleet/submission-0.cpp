class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
               vector<pair<int,int >> cars;
        for(int i=0;i<speed.size();i++){
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.begin(),cars.end());

        stack<double> st;
        for(int i=0;i<speed.size();i++){
            double time = (target-cars[i].first)/double(cars[i].second);
            while(!st.empty() && st.top()<= time) st.pop();
            st.push(time);
        }
        return st.size();
    }
};
