class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max=0;
        int min=prices[0];
        int a=prices.size();
        for(int i=1;i<a;i++){
            if((prices[i]-min)>max){
                max=(prices[i]-min);
            }
            if(prices[i]<min){
                min=prices[i];
            }
        }
        return{max};
    }
};
