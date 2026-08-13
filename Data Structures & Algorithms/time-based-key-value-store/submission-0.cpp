class TimeMap {
public:
map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
         mp[key].push_back({timestamp,value});

    }
    
    string get(string key, int timestamp) {
                vector<pair<int,string>>&time = mp[key];
        int i=0; int j=time.size()-1; //string st=key+"-"+to_string(timestamp);
        while(i<=j){
            int mid=i+(j-i)/2;

            if(time[mid].first==timestamp) return time[mid].second;
            if(time[mid].first>timestamp) { j=mid-1;}
           else i=mid+1;
        }

        if(j>=0){
            

            return time[j].second;
        }
        return "";
    }
};
