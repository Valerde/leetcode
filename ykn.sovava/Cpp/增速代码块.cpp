	// 对于C++中的输入输出操作,这样可以减少时间 
	static const auto io_sync_off = []() {
		// turn off sync
		std::ios::sync_with_stdio(false);
		// untie in/out streams
		std::cin.tie(nullptr);
		return nullptr;
	}();
