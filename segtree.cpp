struct segtree{

    // its a segtree of sums
    // the vector representation will be like:
    // for 4 values in te base:|0|1|1|3|1|4|5
    /*
               TREE 
                5
            1       4
         0     1 1     3

    */

    int size;
    vector<long long> sums;
    
    void init(int n){
        size = 1;
        while(size<n) size*=2; // n is the number of elements in the base of tree
        
        sums.assign(2*size, 0LL); //number of nodes necessary for all tree
    }

    void set(int i, int v, int l, int r, int node){
        if(r - l == 1){

            sums[node] = v;
            return;
        }
        int m = (r + l)/2;
       
        if(i < m){
            set(i, v, l, m, 2*node+1);

        }
        else
            set(i, v, m, r, 2*node+2);

        sums[node] = sums[node*2+1] + sums[node*2+2];
    }

    void set(int i, int v){
        set(i, v, 0, size, 0);
    } 

    long long sum(int ls, int rs, int l, int r, int node){
        
        if(l >= rs || ls >= r) return 0;
        if(l >= ls && r <= rs) return sums[node];
       
        int m = (l + r) / 2;
        
        long long s1 = sum(ls, rs, m, r, node*2+2);

        long long s2 = sum(ls, rs, l, m, node*2+1);
            return s1 + s2;
       
            
    
    }

    long long sum(int ls, int rs){
       return sum(ls, rs, 0, size, 0);
    }


};
