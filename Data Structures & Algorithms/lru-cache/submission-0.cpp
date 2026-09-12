class LRUCache {
public:
map<int,pair<list<int>::iterator, int>> mp;
list<int> dll;
int size;
    LRUCache(int capacity) {
        size = capacity;
    }
    void makemostrecent(int key){
        auto it = mp[key].first;
        dll.erase(it);
        dll.push_front(key);
        mp[key].first = dll.begin();
        return;
    }
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            makemostrecent(key);
            return mp[key].second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            makemostrecent(key);
            mp[key].second=value;
            return;
        }
        else{
            dll.push_front(key);
            mp[key]={dll.begin(),value};
            size--;
        }
        if(size<0){
            int key_del= dll.back();
            mp.erase(key_del);
            dll.pop_back();
            size++;
        }
    }

};
