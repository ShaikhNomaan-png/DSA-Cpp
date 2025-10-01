/*  🔹 Problem: Accounts Merge

Problem Statement:

You are given a list of accounts. Each account is a list:

accounts[i] = [name, email1, email2, ...]


name = account owner’s name

Emails = emails associated with this account

Goal:

Merge accounts that share at least one common email.

Two accounts belong to the same person if there is at least one email in common

Return merged accounts in any order, with emails sorted lexicographically.

🔹 Example

Input:

accounts = [
 ["John", "johnsmith@mail.com", "john00@mail.com"],
 ["John", "johnnybravo@mail.com"],
 ["John", "johnsmith@mail.com", "john_newyork@mail.com"],
 ["Mary", "mary@mail.com"]
]

Output:

[
 ["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],
 ["John", "johnnybravo@mail.com"],
 ["Mary", "mary@mail.com"]
]


Explanation:

First and third accounts share johnsmith@mail.com → merge

Second account has a unique email → no merge

Fourth account → Mary → stays separate

🔹 Approach

We can solve using Disjoint Set (Union-Find):

Assign unique ID to each email

For each account, union all emails in that account

Emails in the same set belong to the same person

Group emails by their parent ID, then sort and add the name
🔹 Explanation of Output

Emails grouped by parent (Union-Find):

Group 1: johnsmith@mail.com, john00@mail.com, john_newyork@mail.com → John
Group 2: johnnybravo@mail.com → John
Group 3: mary@mail.com → Mary


Each group → sorted emails + add name → final merged accounts.

✅ All accounts with common emails merged, emails sorted, names preserved.

🔹 Time Complexity

Let N = total emails, A = number of accounts

Union-Find operations: O(N α(N)) ~ almost linear

Sorting emails in each account: O(N log N)

Total: ~ O(N log N)
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int find(int u) {
        if(parent[u]!=u) parent[u]=find(parent[u]);
        return parent[u];
    }

    void unionByRank(int u,int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv]) parent[pu]=pv;
        else if(rank[pv]<rank[pu]) parent[pv]=pu;
        else { parent[pv]=pu; rank[pu]++; }
    }
};

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string,int> emailToID;
    unordered_map<string,string> emailToName;
    int id = 0;

    for(auto &acc: accounts){
        string name = acc[0];
        for(int i=1;i<acc.size();i++){
            string email = acc[i];
            emailToName[email] = name;
            if(emailToID.find(email)==emailToID.end())
                emailToID[email] = id++;
        }
    }

    DisjointSet ds(id);

    for(auto &acc: accounts){
        int firstID = emailToID[acc[1]];
        for(int i=2;i<acc.size();i++){
            ds.unionByRank(firstID,emailToID[acc[i]]);
        }
    }

    unordered_map<int,vector<string>> groups;
    for(auto &p: emailToID){
        string email = p.first;
        int parentID = ds.find(p.second);
        groups[parentID].push_back(email);
    }

    vector<vector<string>> res;
    for(auto &p: groups){
        vector<string> emails = p.second;
        sort(emails.begin(),emails.end());
        emails.insert(emails.begin(), emailToName[emails[0]]);
        res.push_back(emails);
    }

    return res;
}

int main() {
    vector<vector<string>> accounts = {
        {"John","johnsmith@mail.com","john00@mail.com"},
        {"John","johnnybravo@mail.com"},
        {"John","johnsmith@mail.com","john_newyork@mail.com"},
        {"Mary","mary@mail.com"}
    };

    vector<vector<string>> merged = accountsMerge(accounts);

    for(auto &acc: merged){
        for(auto &s: acc) cout << s << " ";
        cout << endl;
    }

    return 0;
}
