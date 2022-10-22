class StockSpanner {
	private:
		stack<pair<int,int>> s;
		int idx;
	public:
		StockSpanner() {
			s.emplace({0,Max_INT});
			idx = 0;
		}

		int next(int price) {
			while(price >=s.top().second){
				s.pop();
			}
			int res = idx-s.top().first;
			s.emplace(price);
			return res;
		}
};
