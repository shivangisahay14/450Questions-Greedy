int minTaps(int n, vector<int>& ranges) {
        
        vector<pair<int,int>> cnt;
		for(int i=0;i<=n;i++){
			cnt.push_back({i-ranges[i],i+ranges[i]});
		}
		sort(cnt.begin(),cnt.end());
		int res=0;
		int cur=0;
		int l=0;
		int index=0;
		while(cur<n){
			for(int j=index;j<ranges.size() && cnt[j].first<=cur;j++){
				if(cnt[j].second>l){
					l=cnt[j].second;
					index=j;
				}

			}
			if(l<=cur) return -1;
			cur=l;
			res++;
		}
		return res==0 ? -1:res;         
    }
