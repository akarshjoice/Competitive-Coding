// Question:
/*
The task is to design and implement methods of an LRU cache. The class has two methods get() and set() which are defined as follows.
get(x)   : Returns the value of the key x if the key exists in the cache otherwise returns -1.
set(x,y) : inserts the value if the key x is not already present. If the cache reaches its capacity it should invalidate the least recently used item before inserting the new item.
In the constructor of the class the size of the cache should be intitialized.

Example 1:

Input:
N = 2
Q = 2
Queries = SET 1 2 GET 1
Output: 2
Explanation: Cache Size = 2
SET 1 2 GET 1
SET 1 2 : 1 -> 2
GET 1 : Print the value corresponding
to Key 1, ie 2.
Example 2:

Input:
N = 2
Q = 7
Queries = SET 1 2 SET 2 3 SET 1 5
SET 4 5 SET 6 7 GET 4 GET 1
Output: 5 -1
Explanation: Cache Size = 2
SET 1 2 SET 2 3 SET 1 5 SET 4 5
SET 6 7 GET 4 GET 1
SET 1 2 : 1 -> 2
SET 2 3 : 1 -> 2, 2 -> 3 (the most
recently used one is kept at the
rightmost position) 
SET 1 5 : 2 -> 3, 1 -> 5
SET 4 5 : 1 -> 5, 4 -> 5 (Cache size
is 2, hence we delete the least
recently used key-value pair)
SET 6 7 : 4 -> 5, 6 -> 7 
GET 4 : Prints 5
GET 1 : No key-value pair having
key = 1. Hence prints -1.
Your Task:
You only need to complete the provided functions get() and set(). 

Expected Time Complexity: O(1) for both get() and set().
Expected Auxiliary Space: O(1) for both get() and set(). (though, you may use extra space for cache storage and implementation purposes).

Constraints:
1 <= N <= 1000
1 <= Q <= 100000
1 <= x, y <= 1000
*/

// Code:

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



// design the class in the most optimal way

class LRUCache
{
private:
     
     struct Node {
         int key;
         int data;
         Node *next;
         Node *prev;
         Node (int k,int d) {
             key = k;
             data = d;
             next = NULL;
             prev = NULL;
         }
     } *head=NULL,*tail=NULL;
     map <int,Node *> mp;
     int capacity;
public:
    // constructor for cache
    LRUCache(int cap)
    {
        capacity = cap;
    }
    
    // this function should return value corresponding to key
    int get(int key)
    {   int val;
        if(mp.count(key)==1) {
            val = mp[key]->data;
            if(mp[key] == head)  {
               
               return head->data;
            }
            if(mp[key] == tail) {
                tail=tail->prev;
            }
            Node *curr = mp[key];
            curr->prev->next = curr->next;
            if(curr->next) curr->next->prev = curr->prev;
            curr->next = head;
            head->prev = curr;
            curr->prev = NULL;
            head = curr;
            return val;
        } else {
            return -1;
        }
    }
    
    // storing key, value pair
    void set(int key, int value)
    {   if(mp.count(key) == 1) {
            if(mp[key] == head)  {
               head->data = value;
               return;
            }
            if(mp[key] == tail) {
                tail=tail->prev;
            }
            Node *curr = mp[key];
            curr->prev->next = curr->next;
            if(curr->next) curr->next->prev = curr->prev;
            curr->next = head;
            head->prev = curr;
            curr->prev = NULL;
            head = curr;
            head->data = value;
            return;
        }
        
        if(mp.size()<capacity) {
            
            if(head == NULL) {
                Node *tmp = new Node(key,value);
                mp.insert({key,tmp});
                head = tmp;
                tail = tmp;
            } else {
                Node *tmp = new Node(key,value);
                mp.insert({key,tmp});
                head->prev = tmp;
                tmp->next = head;
                head = tmp;
            }   
        } else {
            Node *tmp = new Node(key,value);
            head->prev = tmp;
            if(head->next == tail) head->next = NULL;
            tmp->next = head;
            head = tmp;
            mp.erase(tail->key);
            mp.insert({key,tmp});
            
            tail=tail->prev;
            tail->next = NULL;
            
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends