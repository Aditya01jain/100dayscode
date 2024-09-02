class LRUCache {
private:
    class node{
        public:
        int key,val;
        node *prev,*next;

        node(int key,int val){
            this->key=key;
            this->val=val;
        }
    };

public:
    unordered_map<int,node*>mp;
    int capacity;
    node *head=new node(-1,-1),*tail=new node(-1,-1);

    LRUCache(int capacity) {
        this->capacity=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void add(node *newNode){
        node *temp=head->next;
        newNode->next=temp;
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode;
    }

    void dlt(node *dltNode){
        node *prevNode=dltNode->prev;
        node *nextNode=dltNode->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            node *resNode=mp[key];
            int ans=resNode->val;
            mp.erase(key);
            dlt(resNode);
            add(resNode);
            mp[key]=head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            node *curr=mp[key];
            mp.erase(key);
            dlt(curr);
        }
        if(mp.size()==capacity){
            mp.erase(tail->prev->key);
            dlt(tail->prev);
        }
        add(new node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */