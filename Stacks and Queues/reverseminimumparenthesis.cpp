int countBracketReversals(string input) {
		int cur = 0;
    
    	int reverse = 0;
    
    	for(auto p : input){
            	cur += ((p == '{') - (p == '}'));
            
            	if(cur < 0)	reverse++, cur += 2;
        }
    	
    	if(cur%2) return -1;
    	
    	return reverse + cur/2;
}