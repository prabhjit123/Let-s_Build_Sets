#include <iostream>
#include <vector>
using namespace std;
class Node{
        public:
        int value;
        vector <int> v;
        Node(int value = 0, vector <int> v = vector <int>(), Node * next = nullptr, Node * previous=nullptr){
            this->value = value;
            this->v = v; 
            };
        ~Node(){};
        void insert_into_set(int val){
            vector <int>::iterator iter;
            iter = v.begin();
            if(v.size()==0){
                v.push_back(val);
            }
            else if(v.size()==1){
                if (val>v[0]){
                    v.push_back(val);
                }
                else{
                    v.insert(iter,val);
                };
            }
            else {
                while(*iter<val and iter<v.end()){
                    iter++;
                }
                v.insert(iter,val);
            };
        };
        void print_v(){
            for(vector<int>::iterator iter = v.begin(); iter<v.end(); iter++){
                if (iter!=v.end()-1){
                    cout << *iter << ',';
                }
                else {
                    cout << *iter;
                }
            }; 
            cout << endl;
        };
        int max_element(vector <int> v){
            int max_el = v[0];
            for(vector<int>::iterator iter = v.begin(); iter<v.end(); iter++){
                if (*iter > max_el) {
                    max_el = *iter;
                };
            };
            return max_el;
        };
        bool Existence(int val){
            int left = 0;
            int right = v.size()-1;
            while (left<=right) {
                int middle = (left +right)/2;
                if (v[middle]==val){
                    return true;
                    }
                else if (v[middle]<val)
                {
                    left = middle + 1;
                }
                else {
                    right = middle - 1;
                };
            };
        return false;
        };
        void delete_from_set(int val){
            if (Existence(val)== 1){
                for (vector <int>::iterator iter = v.begin(); iter<v.end();iter++){
                    if (*iter ==val){
                        v.erase(iter,iter+1);
                    };
                }
            }
            else {
                cout << v.size() << endl;
            }

        };
        }; //Node class ends    
class SETS{
        public:
        vector <Node> v;
        SETS(vector <Node> v = vector <Node>()){
            this->v = v;
        };
        int Exists(int val){
            if (v.size()==0){
                return -1;
            };
            int left = 0;
            int right = v.size()-1;
            while (true) {
                int middle = (left +right)/2;
                if ((v[middle]).value==val){
                    return middle;
                    break;
                }
                else if(left>=right){
                    return -1;
                }
                else if ((v[middle]).value <val)
                {
                    left = middle + 1;
                }
                else {
                    right = middle - 1;
                };
            };
        return -1;
        };
        void insert_into_set(Node new_node){
                if (v.size()==0){
                    v.push_back(new_node);
                }
                else if (new_node.value>v[v.size()-1].value)
                {
                    v.push_back(new_node);
                }
                else if (new_node.value<v[0].value)
                {
                    v.insert(v.begin(),new_node);
                }
                else {
                    vector <Node>::iterator iter;
                    iter = v.begin();
                    while ((*iter).value < new_node.value){
                        iter++;
                    };
                    v.insert(iter, new_node);
                }
            };
        void delete_set(int val, int val1){
            if (v[Exists(val)].Existence(val1)==1) 
            {
                v[Exists(val)].delete_from_set(val1);
                cout << v[Exists(val)].v.size();
            }
            else 
            {
                cout << v[Exists(val)].v.size();
            };
            };
        void print_elements_vector(int val){
            int index = Exists(val);
            if (index!=-1){
                (v[index]).print_v();
            };
        };
        int union_sets(int val_1, int val_2){
                Node * n1 = &v[Exists(val_1)];
                Node * n2 = &v[Exists(val_2)];
                if (val_1==val_2){
                    cout << (*n1).v.size() << endl;
                    return 1;
                };
               
                for (vector <int>::iterator iter = (*n2).v.begin(); iter< (*n2).v.end(); iter++){
                    if ((*n1).Existence(*iter)!=1){
                        (*n1).insert_into_set(*iter);
                    
                    };
                }; 
            cout << (*n1).v.size() << endl;
            return 1;
            };

        int  intersection_sets(int val_1, int val_2){
                if (val_1==val_2){
                    return 1;};
                Node  * n1 = &v[Exists(val_1)];
                Node  * n2 = &v[Exists(val_2)];
                Node * n3 = new Node(val_1);
                if ((*n1).v.size()==0 or (*n2).v.size()==0){
                    *n1=*n3;
                    return 1;
                }
                for (vector <int>::iterator iter = (*n2).v.begin(); iter< (*n2).v.end(); iter++){
                    if ((*n1).Existence(*iter)==1){
                        (*n3).insert_into_set(*iter);
                    };
                };
                *n1 = *n3;
                return 1;
            };
        int difference_sets(int val_1, int val_2)
                {
                if (val_1==val_2)
                {
                    v[Exists(val_1)].v = vector <int>();
                    cout << 0 << endl;
                    return 0;
                };
                Node  * n1 = &v[Exists(val_1)];
                Node  * n2 = &v[Exists(val_2)];
                Node * n3 = new Node(val_1);
                for (vector <int>::iterator iter = (*n2).v.begin() ; iter< (*n2).v.end(); iter++){
                    if ((*n1).Existence(*iter)==1){
                        (*n1).delete_from_set(*iter);
                    };
                };
            cout << (*n1).v.size() << endl;
            return 1;
            };
        int symmetric_difference(int val_1, int val_2){
                if (val_1==val_2){
                    v[Exists(val_1)].v = vector <int>();
                    cout << 0 << endl;
                    return 0;
                };
                Node  * n1 = &v[Exists(val_1)];
                Node  * n2 = &v[Exists(val_2)];
                for (vector <int>::iterator iter = (*n2).v.begin(); iter< (*n2).v.end(); iter++){
                    if ((*n1).Existence(*iter)==1){
                        (*n1).delete_from_set(*iter);
                    }
                    else {(*n1).insert_into_set(*iter);};
                    
                };
        cout << (*n1).v.size() << endl;
        return 1;
        }; 
        }; 
int main(){
    int a,b,c;
    SETS *sets_new = new SETS();

    while(true)
        {
        cin >> a >> b;
        if(!cin) {
            break;
        }
        int w, w_new;
        w = sets_new->Exists(b);
        if (a==1){ cin >> c;
        if (sets_new->Exists(b)==-1){
            vector <int> v_;
            v_.push_back(c);
            Node new_node(b,v_);
            sets_new->insert_into_set(new_node);
            cout << sets_new->v[sets_new->Exists(b)].v.size() << endl;
        }
        else {if ((sets_new->v)[w].Existence(c)==0)
        {
            (sets_new->v)[w].insert_into_set(c);
            cout << sets_new->v[sets_new->Exists(b)].v.size() << endl;
        }
        else {cout <<(sets_new->v)[w].v.size() <<endl;};
        };
        };
        if (a==2){cin >> c;
            if (w==-1){
                cout << -1 << endl;
            }
            else {
                sets_new->delete_set(b,c);
                cout << endl;
            };
        };
        if (a==3){cin >> c;
            if (w==-1){
                cout << -1 << endl;
            }
            else {
                cout << sets_new->v[w].Existence(c) << endl;
            };
    };
        if (a==4){cin >> c;
            w_new = sets_new->Exists(c);
            if (w==-1 and w_new==-1){
                Node *n1 = new Node(b);
                Node *n2 = new Node(c);
                sets_new->insert_into_set(*n1);
                sets_new->insert_into_set(*n1);
                sets_new->union_sets(b,c);
                
            }
            else if (w==-1 and w_new!=-1)
            {
                Node *n1 = new Node(b);
                sets_new->insert_into_set(*n1);
                
                sets_new->union_sets(b,c);
            }
            else if (w!=-1 and w_new==-1)
            {
                Node *n2 = new Node(c);
                sets_new->insert_into_set(*n2);
                sets_new->union_sets(b,c);
            }
            else {
                sets_new->union_sets(b,c);
            }
        };
        if (a==5){cin >> c;
            w_new = sets_new->Exists(c);
            if (w==-1 and w_new==-1){
                Node *n1 = new Node(b);
                Node *n2 = new Node(c);
                sets_new->insert_into_set(*n1);
                sets_new->insert_into_set(*n1);
                sets_new->intersection_sets(b,c);
                cout << sets_new->v[sets_new->Exists(b)].v.size() << endl;
            }
            else if (w==-1 and w_new!=-1)
            {
                Node *n1 = new Node(b);
                sets_new->insert_into_set(*n1);
                sets_new->intersection_sets(b,c);
                cout << sets_new->v[sets_new->Exists(b)].v.size() << endl;
            }
            else if (w!=-1 and w_new==-1)
            {
                Node *n2 = new Node(c);
                sets_new->insert_into_set(*n2);
                sets_new->intersection_sets(b,c);
                cout << sets_new->v[sets_new->Exists(b)].v.size() << endl;
            }
            else {
                sets_new->intersection_sets(b,c);
                cout << sets_new->v[sets_new->Exists(b)].v.size() << endl;
            }
        };
        if (a==6){
            if (w!=-1){
                cout << sets_new->v[w].v.size() << endl;
            }
            else if (w==-1)
            {
                Node *n1 = new Node(b);
                sets_new->insert_into_set(*n1);
                cout << sets_new->v[w].v.size() << endl;
            }
        };
        if (a==7){cin >> c;
            w_new = sets_new->Exists(c);
            if (w==-1 and w_new==-1){
                Node *n1 = new Node(b);
                Node *n2 = new Node(c);
                sets_new->insert_into_set(*n1);
                sets_new->insert_into_set(*n1);
                sets_new->difference_sets(b,c);
            }
            else if (w==-1 and w_new!=-1)
            {
                Node *n1 = new Node(b);
                sets_new->insert_into_set(*n1);
                sets_new->difference_sets(b,c);
            }
            else if (w!=-1 and w_new==-1)
            {
                Node *n2 = new Node(c);
                sets_new->insert_into_set(*n2);
                sets_new->difference_sets(b,c);
            }
            else {
                sets_new->difference_sets(b,c);
            }
        };
        if (a==8){cin >> c;
        w_new = sets_new->Exists(c);
            if (w==-1 and w_new==-1){
                Node *n1 = new Node(b);
                Node *n2 = new Node(c);
                sets_new->insert_into_set(*n1);
                sets_new->insert_into_set(*n1);
                sets_new->symmetric_difference(b,c);
            }
            else if (w==-1 and w_new!=-1)
            {
                Node *n1 = new Node(b);
                sets_new->insert_into_set(*n1);
                sets_new->symmetric_difference(b,c);
            }
            else if (w!=-1 and w_new==-1)
            {
                Node *n2 = new Node(c);
                sets_new->insert_into_set(*n2);
                sets_new->symmetric_difference(b,c);
            }
            else {
                sets_new->symmetric_difference(b,c);
            }
        };
        if (a==9){
            if (w==-1){
                cout << endl;
            }
            else{
            (sets_new->v)[w].print_v();}
        };
    };
    delete sets_new;
}