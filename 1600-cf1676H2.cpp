/*
ANALYSIS:

*/
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <ctime>
#include <random>
#define int long long
#define i32 signed
#define endl '\n'
using namespace std;
const int MaxN=5;
#ifndef S_TREE_H
#define S_TREE_H

#define ROOT 1  //根节点下标
template <typename Node, typename Label = int>
class STree {
   public:
    STree(int start, int end, Node* arr,
          Node (*merge)(const Node& lchild, const Node& rchild),
          void (*modify)(Node& node, const Label& value) = NULL);
    virtual ~STree();
    void modify(int loc, const Node& new_data);           //单点修改
    void modify(int start, int end, const Label& value);  //区间修改
    const Node query(int start, int end);                 //区间查询
    const Node query(int loc);                            //单点查询
   private:
    Node* tree;    //节点数组
    Label* slack;  //懒标记
    const int length, loc_min, loc_max;
    Node (*f_merge)(const Node& lchild, const Node& rchild);  //区间合并函数
    void (*f_modify)(Node& node, const Label& value);  //区间修改函数

    void build_tree(int ind, int left, int right, Node* arr);
    Node query_in(int ind, int left, int right, int start, int end);
    void modify_in(int ind, int left, int right, int start, int end,
                   const Label& value);
    void down(int ind, int left, int right);  //懒标记下沉，同时更新信息
    void update(int ind);                     //更新信息
};

template <typename Node, typename Label>
STree<Node, Label>::STree(int start, int end, Node* arr,
                          Node (*merge)(const Node& lchild, const Node& rchild),
                          void (*modify)(Node& node, const Label& value))
    : length(4 * (end - start + 1)), loc_min(start), loc_max(end) {
    if (start > end) {
        throw "STree constructor error";
    }
    tree = new Node[length];
    slack = new Label[length];
    f_merge = merge;
    f_modify = modify;
    std::memset(slack, 0, length * sizeof(Label));
    build_tree(ROOT, start, end, arr);
}
template <typename Node, typename Label>
STree<Node, Label>::~STree() {
    delete[] tree;
    delete[] slack;
}
template <typename Node, typename Label>
void STree<Node, Label>::modify(int loc, const Node& new_data) {
    if (loc < loc_min || loc > loc_max) {
        throw "STree modify error";
    }
    int ind = ROOT;
    int left = loc_min;
    int right = loc_max;
    while (left < right) {//向下寻找节点
        if (slack[ind]) {
            down(ind, left, right);
        }
        int mid = (left + right) >> 1;
        if (loc <= mid) {
            right = mid;
            ind = ind << 1;
        } else {
            left = mid + 1;
            ind = ind << 1 | 1;
        }
    }
    tree[ind] = new_data;//修改节点
    int ind_p = ind >> 1;
    while (ind_p >= ROOT) {//向上更新
        Node temp = tree[ind_p];
        update(ind_p);
        if (temp == tree[ind_p]) {
            break;
        }
        ind_p = ind_p >> 1;
    }
}
template <typename Node, typename Label>
void STree<Node, Label>::modify(int start, int end, const Label& value) {
    if (start > end || start < loc_min || end > loc_max) {
        throw "STree modify error";
    }
    modify_in(ROOT, loc_min, loc_max, start, end, value);//递归区间修改
}
template <typename Node, typename Label>
const Node STree<Node, Label>::query(int loc) {
    return query_in(ROOT, loc_min, loc_max, loc, loc);//递归区间查询
}
template <typename Node, typename Label>
const Node STree<Node, Label>::query(int start, int end) {
    if (start > end || start < loc_min || end > loc_max) {
        throw "STree query error";
    }
    return query_in(ROOT, loc_min, loc_max, start, end);//递归区间查询
}

template <typename Node, typename Label>
void STree<Node, Label>::build_tree(int ind, int left, int right, Node* arr) {
    if (left == right) {
        tree[ind] = arr[left];
        return;
    }
    int mid = (left + right) >> 1;
    build_tree(ind << 1, left, mid, arr);
    build_tree(ind << 1 | 1, mid + 1, right, arr);
    update(ind);
}
template <typename Node, typename Label>
Node STree<Node, Label>::query_in(int ind, int left, int right, int start,
                                  int end) {
    if (start <= left && right <= end) {
        return tree[ind];
    }
    if (slack[ind] && left != right){
         down(ind, left, right);
    }
    //判断是否需要两边查询
    int mid = (left + right) >> 1;
    if (mid >= end) {
        return query_in(ind << 1, left, mid, start, end);
    } else if (mid < start) {
        return query_in(ind << 1 | 1, mid + 1, right, start, end);
    } else {
        return f_merge(query_in(ind << 1, left, mid, start, end),
                       query_in(ind << 1 | 1, mid + 1, right, start, end));
    }
}
template <typename Node, typename Label>
void STree<Node, Label>::modify_in(int ind, int left, int right, int start,
                                   int end, const Label& value) {
    if (value == 0 || right < start || left > end) {
        return;
    }
    if (start <= left && right <= end) {  //本区间包含在内
        f_modify(tree[ind], value);
        slack[ind] += value;
        return;
    }
    if (slack[ind] && left != right) down(ind, left, right);  //清除懒标记
    int mid = (left + right) >> 1;
    modify_in(ind << 1, left, mid, start, end, value);
    modify_in(ind << 1 | 1, mid + 1, right, start, end, value);
    update(ind);
    return;
}

template <typename Node, typename Label>
void STree<Node, Label>::down(int ind, int left, int right) {
    //需要调用者负责检查 是否应该调用该函数
    int mid = (left + right) >> 1;
    if (slack[ind << 1] && left != mid) {
        down(ind << 1, left, mid);
    }
    if (slack[ind << 1 | 1] && mid + 1 != right) {
        down(ind << 1 | 1, mid + 1, right);
    }
    f_modify(tree[ind << 1], slack[ind]);      //标记下沉
    f_modify(tree[ind << 1 | 1], slack[ind]);  //标记下沉
    update(ind);
    //懒标记更新
    slack[ind << 1] = slack[ind];
    slack[ind << 1 | 1] = slack[ind];
    slack[ind] = 0;
}

template <typename Node, typename Label>
void STree<Node, Label>::update(int ind) {
    tree[ind] = f_merge(tree[ind << 1], tree[ind << 1 | 1]);
}

#undef ROOT
#endif

int a[200005],b[200005],n;
void solution()
{
	cin>>n;
	int ans=0;
	memset(b,0,sizeof(b));
	STree<int> st(1,n,b,[](const int& l, const int& r){return l+r;},[](int& node, const int& value){node+=value;});
	for (int i = 1; i <= n; i++)
	{
		cin>>a[i];
		ans+=st.query(a[i],n);
		st.modify(a[i],a[i],1);
	}
	cout<<ans<<endl;
}

i32 main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for (int i=1;i<=T;i++) {
        try {
			cerr<<"Case #"<<i<<": ";
            solution();
        } catch (const char* e) {
            cerr << "Caught exception in solution: " << e << endl;
        }
    }
    return 0;
}
