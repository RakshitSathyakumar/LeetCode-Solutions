//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

Node* findTargetNode(Node* root,int target){
    if(root==NULL)return NULL;
    if(root->data==target)return root;
    Node* left=findTargetNode(root->left,target);
    if(left)return left;
    Node* right=findTargetNode(root->right,target);
    if(right)return right;
    
}

public:

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        unordered_map<Node*,Node*>mp;//parent store krne ke liye
        queue<Node*>q;
        q.push(root);

        while(!q.empty()){
            Node* a=q.front();
            q.pop();

            if(a->left){
                mp[a->left]=a;//a ke left and right ka parent a hoga toh map me a ke left pr dala a
                q.push(a->left);
            }

            if(a->right){
                mp[a->right]=a;
                q.push(a->right);
            }
        }
        
        //o(k)
        unordered_map<Node*,bool>visited;
        //visited isliye bnaya taki wo do ke beech me hi na ghumta rhe
        // Node* t=new Node(target);
        // q.push(t);
        // visited[t]=true;
        Node* targetNode=findTargetNode(root,target);
        q.push(targetNode);
        visited[targetNode]=true;
       
        while(!q.empty()){
            if(k==0)break;

            int size=q.size();
            for(int i=0;i<size;i++){
                Node* b=q.front();
                q.pop();

                //check on the left
                if(b->left && !visited[b->left]){
                    q.push(b->left);
                    visited[b->left]=true;
                }
                //check on right
                if(b->right && !visited[b->right]){
                    q.push(b->right);
                    visited[b->right]=true;
                }

                //check on parent
                if(mp.find(b)!=mp.end() && !visited[mp[b]]){
                    q.push(mp[b]);
                    visited[mp[b]]=true;
                }
            }

            k--;
        }
        
        vector<int>ans;
        while(!q.empty()){
            Node* c=q.front();
            q.pop();

            ans.push_back(c->data);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends