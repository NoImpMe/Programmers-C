#include <string>
#include <vector>
#include <stack>
#include <numeric>
#include <algorithm>
using namespace std;
struct Node{
    int nodenum;
    int val;
    int leftsum = 0;
    int rightsum = 0;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
};
void postSum( Node* node){
    if(!node) return;
    
    postSum(node->left);
    postSum(node->right);
    
    if(node->left){
        node->leftsum = node->left->val + node->left->leftsum + node->left->rightsum;
    }
    if(node->right){
        node->rightsum = node->right->val + node->right->leftsum + node->right->rightsum;
    }
}
bool check(Node* root, int limit, int k){
    int cutcnt = 0;
    stack<pair<Node*, bool>> st;
    st.push({root,false});
    vector<int> subsum (10001, 0);
    while(!st.empty()){
        auto [node, visited] = st.top();
        st.pop();
        if(visited){
            int lefts = node->left ? subsum[node->left->nodenum] : 0;
            int rights = node-> right ? subsum[node->right->nodenum] : 0;
            int s = node->val + lefts + rights;
            
            if(s > limit){
                if(lefts >= rights) {
                    cutcnt++;
                    s -= lefts;
                    if(s > limit){
                        cutcnt++;
                        s -= rights;
                    }
                }
                else{
                    cutcnt++;
                    s -= rights;
                    if(s > limit){
                        cutcnt++;
                        s -= lefts;
                    }
                }
            }
            subsum[node->nodenum] = s;
        }
        else{
            st.push({node, true});
            if(node->left){
                st.push({node->left,false});
            }
            if(node->right){
                st.push({node->right, false});
            }
        }
    }
    return cutcnt <= k-1;
}
int solution(int k, vector<int> num, vector<vector<int>> links) {
    int answer = 0;
    int lo = *max_element(num.begin(), num.end());
    int hi = accumulate(num.begin(),num.end(),0);
    vector<Node*> nodes;
    int cutcnt = k-1;
    Node* root = nullptr;
    
    for(int i = 0 ; i < num.size(); i++){
        Node* tmp = new Node();
        tmp->val = num[i];
        tmp->nodenum = i;
        nodes.push_back(tmp);
    }
    for(int i = 0 ; i< num.size(); i++){
        if(links[i][0] != -1){
            nodes[i]->left = nodes[links[i][0]];
            nodes[i]->left->parent = nodes[i];
        }
        if(links[i][1] != -1){
            nodes[i]->right = nodes[links[i][1]];
            nodes[i]->right->parent = nodes[i];
        }
    }
    
    for( auto node : nodes){
        if(!node->parent) {
            root = node;
            break;
        }
    }
    postSum(root);
    
    while(lo < hi){
        int mid = (lo + hi) / 2;   
        if(check(root,mid,k)) hi = mid;
        else lo = mid + 1;
    }
    answer = lo;
    return answer;
}