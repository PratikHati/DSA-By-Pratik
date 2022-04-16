vector<int> GetPrimeSeiveEratothenis(int p,int max_length){
	vector<bool> prime(max_length+1,true);
	vector<int> ans;
	
	prime[0] = prime[1] = false;
	
	for(int i=2;i*i <= max_length;i++){
		if(prime[i] == true){
			for(int j = i*i; j<=max_length; j+= i){
				prime[j] = false;
			}
		}
	}
	
	for(int i=2;i<= max_length;i++){
		if(prime[i] == true){
			ans.push_back(i);
		}
	}
	
	return ans;
}
void fillUtil(vector<int> &util,vector<int> &primes,int index,long long curr_product, int p,int max_length){
	if(2*index >= max_length){
		return;
	}
	
	for(auto &x: primes){
		
		long long next_product = curr_product * x;
		
		if(next_product > p){		//as if p = 20 and x = 23, so neither 1 nor  2,3,4,... length is possible, so break
			break;
		}
		
		util[2*index+1] += 1;
		
		if(2*index + 2 > max_length){
			continue;
		}
		
		next_product = curr_product * x * x;
		
		if(next_product > p){
			continue;		//should not break as p = 20 and x = 5, so 25(5,5) will not be an candidate, but(7,2) is an candidate
		}
		
		
		util[2*index+2] += 1;
		
		fillUtil(util,primes,index+1,next_product,p,max_length);
	}
	return;
}
vector<int> solveChallenges(vector<int> &challenges, int p, int q) {
    // Write your code here.
	int max_length = 20;
	vector<int> ans;
	vector<int> primes = GetPrimeSeiveEratothenis(p,max_length);
	
	vector<int> util(max_length+1,0);	//to fill no of subsequences of given p
	
	fillUtil(util,primes,0,1,p,max_length);
	
	for(int i=1;i<=max_length;i++){	
		util[i] = util[i-1]+util[i]; 	//so find no of subsequence of all index
	}
	
	for(auto &x:challenges){
		int index = min(max_length,x);
		ans.push_back(util[index]);
	}
	
	return ans;
}