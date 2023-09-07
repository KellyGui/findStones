#ifndef FIND_STONE_PAIRS_HPP
#define FIND_STONE_PAIRS_HPP
#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <assert.h>
#include <limits.h>
#include <cmath>
#include <typeinfo>
#include <set>

using namespace std;
/**
 * QuestionA: Description:
 * Given an N(N>=2) array nums[] which could be Integer or float pointing numbers, find a piar of stones the difference is D
 * Input: an array[], it could be Integer or float pointing numbers
 * Output: (i,j), which satisfies 
 *         1. 0<= i < j <=N-1
 *         2. |array[i]-array[j]| == D
 *         3. nums[i] could be the limit of its data type
*/

template <class T>
class Stone
{
public:

/**
 * time : O(n)
 * space: O(n)
*/
    vector<int> find_onepair(const vector<T> &nums, const T &D)
    { 
        //check input
        assert(nums.size()>=2);
        assert(D>=0);
        
        //if the input type is float or double, call function find_onepair_fp
        if(typeid(D)==typeid(float)||typeid(D)==typeid(double))
          return find_onepair_fp(nums,D);

        //build hash map and find the first satisfied piar
        int minN=-1,maxN=-1;
        unordered_map<T,int> numswithD;
        for(int i=0;i<nums.size();++i)
        {
            if(INT_MAX-D<nums[i])
            {
                T temp = nums[i]-D;
                if(numswithD.find(temp)!=numswithD.end())
                {
                    minN = min(i,numswithD[temp]);
                    maxN = max(i,numswithD[temp]);
                    break;
                }
            }
            else if(INT_MIN+D>nums[i])
            {
                T temp = nums[i]+D;
                if(numswithD.find(temp)!=numswithD.end())
                {
                    minN = min(i,numswithD[temp]);
                    maxN = max(i,numswithD[temp]);
                    break;
                }
            }
            else{
                
                if(numswithD.find(nums[i]+D)!=numswithD.end()){
                    minN = min(i,numswithD[nums[i]+D]);
                    maxN = max(i,numswithD[nums[i]+D]);
                    break;
                } 
                if(numswithD.find(nums[i]-D)!=numswithD.end())
                {
                    minN = min(i,numswithD[nums[i]+D]);
                    maxN = max(i,numswithD[nums[i]+D]);
                    break;
                }
                
            }
            
            numswithD.emplace(nums[i],i);
        }

        return {minN,maxN};  //{-1,-1} for not found
    }
/**
 * time: O(nlog(n))
 * space: O(n)
*/
    vector<int> find_onepair_fp(const vector<T> &nums, const T &D)
    {
        //check input
        assert(nums.size()>=2);
        assert(D>=0);
        T esp;
        if(typeid(D)==typeid(float))
            esp=1e-6;
        else
            esp=1e-8;

        
        vector<pair<T,int>> records;
        for(int i=0;i<nums.size();++i)
        {
            records.emplace_back(make_pair(nums[i],i));
        }
        sort(records.begin(),records.end());

        int l=0,r=1;
        while(l<records.size() && r<records.size())
        {   
            if(l==r) r++;
            if(l!=r && fabs(records[r].first-records[l].first-D)<esp)
            {
                int minN = records[l].second<records[r].second?  records[l].second: records[r].second;
                int maxN = records[l].second>records[r].second?  records[l].second: records[r].second;
                return {minN,maxN};
            }
               
            else if(l!=r&&records[r].first-records[l].first<D)
                r++;
            else l++;
            
        }
        return {-1,-1};
    }
 
    vector<pair<int,int>> find_pairs(const vector<T> &nums, const T &D)
    {
        //check input
        assert(nums.size()>=2);
        assert(D>=0);

        //build hash map
        unordered_map<T,vector<int>> numswithD;
        for(int i=0;i<nums.size();++i)
        {
            if(numswithD.count(nums[i]))
            {
                numswithD[nums[i]].emplace_back(i);
            }
            else
                numswithD.emplace(nums[i], vector<int>{i});
        }
        

        set<pair<int,int>>  res; 
        //if K==0, res is the permutation of indexes of the same number
        if(D==0)
        {
            for(auto &kv : numswithD)
            {
                int n = kv.second.size();
                if(n>=2)
                {
                    for(int i=0;i<n;++i)
                    {
                        for(int j=i+1;j<n;++j)
                        {
                            int minN = min(kv.second[i],kv.second[j]);
                            int maxN = max(kv.second[i],kv.second[j]);
                            res.emplace(make_pair(minN,maxN));
                        }
                    }
                }
            }
        }
        else{ //if k!=0
            for(auto &kv : numswithD)
            {
                 T key = kv.first;
                 if(numswithD.count(key-D))
                 {
                    vector<int> match = numswithD[key-D];
                    for(int i=0;i<match.size();++i)
                    {
                        for(int j=0;j<kv.second.size();++j)
                        {
                            int minN = min(match[i],kv.second[j]);
                            int maxN = max(match[i],kv.second[j]);
                            
                            res.emplace(make_pair(minN,maxN));
                        }
                    }
                 }
                 if(numswithD.count(key+D))
                 {
                    vector<int> match = numswithD[key+D];
                    for(int i=0;i<kv.second.size();++i)
                    {
                        for(int j=0;j<match.size();++j)
                        {
                            int minN = min(kv.second[i],match[j]);
                            int maxN = max(kv.second[i],match[j]);
                           
                            res.emplace(make_pair(minN,maxN));
                        }
                    }
                 }
                 
            }
        }

        //copy result from set to vector, less order
        vector<pair<int,int>> fres;
        for(auto s: res)
        {
            fres.emplace_back(s);
        }

        return fres;
       


    }

    
};

#endif
