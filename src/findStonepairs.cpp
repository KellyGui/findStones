#include "../src/findStonepairs.hpp"
using namespace std;



int main()
{
     Stone<double> s;
    vector<double> nums{1.2,2.2,5,7};
    double K = 3.5;
    vector<int> res = s.find_onepair(nums,K);
    vector<int> ans{1,2};
    for(auto i: res)
      cout<<i<<' ';
    // cout<<INT_MIN<<" "<< INT_MAX+2<<endl;
    
}