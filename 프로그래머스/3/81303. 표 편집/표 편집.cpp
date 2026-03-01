#include <string>
#include <vector>
using namespace std;
struct Node{
    int val;
    Node* prev;
    Node* next;
};
string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    vector<int> s (n);
    vector<Node*> nodes(n);
    Node* firstNode = new Node();
    Node* lastNode = new Node();
    vector<int> removeNodes;
    int idx = k;
    for(int i = 0 ; i < n; i++){
        answer += "O";
        nodes[i] = new Node();
        nodes[i]->val = i;
    }
    for(int i = 0 ; i < n ; i++){
        if(i == 0 ){
            firstNode->next = nodes[0];
            nodes[0]->next = nodes[1];
            nodes[0]->prev = firstNode;
        }
        else if(i == n-1){
            lastNode->prev = nodes[n-1];
            nodes[n-1]->prev = nodes[n-2];
            nodes[n-1]->next = lastNode;
        }
        else {
            nodes[i]->prev = nodes[i-1];
            nodes[i]->next = nodes[i+1];
        }
    }
    Node* current = nodes[k];
    for( string command : cmd){
        if(command[0] == 'U'){
            int dist = stoi(command.substr(2));
            for(int i = 0 ; i < dist; i++){
                current = current->prev;
            }
        }
        else if(command[0] == 'D'){
            int dist = stoi(command.substr(2));
            for(int i = 0 ; i < dist; i++){
                current = current->next;
            }
        }
        else if(command[0] == 'C'){
            answer[current->val] = 'X';
            Node* tmp;
            if(current->next==lastNode){
                tmp = current->prev;    
            }
            else {
                tmp = current->next;
            }
            removeNodes.push_back(current->val);
            current->prev->next = current->next;    
            current->next->prev = current->prev;    
            
            current = tmp;
        }
        else{
            int tmp = removeNodes[removeNodes.size()-1];
            answer[tmp] = 'O';
            nodes[tmp]->next = nodes[tmp]->next->prev->next;
            nodes[tmp]->next->prev->next = nodes[tmp];    
            nodes[tmp]->prev = nodes[tmp]->next->prev;
            nodes[tmp]->next->prev = nodes[tmp];
            removeNodes.pop_back();
        }
    }
    return answer;
}