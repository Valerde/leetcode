// #include<bits/stdc++.h>
class LRUCache {
	private:
		int cap;
		list<pair<int,int>> cache;
		map<int,list<pair<int,int>>::iterator> m;
	public:
		LRUCache(int capacity) {
			cap = capacity;
		}

		int get(int key) {
			if(m.find(key)==m.end()) return -1;
			auto it = *m[key];
			cache.erase(m[key]);
			cache.push_front(it);
			m[key] = cache.begin();
			return it.second;
		}

		void put(int key, int value) {
			if(m.find(key)==m.end()) {
				if(cache.size()==cap) {
					m.erase(cache.back().first);
					cache.pop_back();
				}
			} else {
				cache.erase(m[key]);
			}
			cache.push_front({key,value});
			m[key] = cache.begin();

		}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
