#include <iostream>
#include <vector>
using namespace std;

/*************************设计哈希集合********************************

不使用任何内建的哈希表库设计一个哈希集合

具体地说，你的设计应该包含以下的功能

    add(value)：向哈希集合中插入一个值。
    contains(value) ：返回哈希集合中是否存在这个值。
    remove(value)：将给定值从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。


示例:

MyHashSet hashSet = new MyHashSet();
hashSet.add(1);         
hashSet.add(2);         
hashSet.contains(1);    // 返回 true
hashSet.contains(3);    // 返回 false (未找到)
hashSet.add(2);          
hashSet.contains(2);    // 返回 true
hashSet.remove(2);          
hashSet.contains(2);    // 返回  false (已经被删除)


注意：

    所有的值都在 [1, 1000000]的范围内。
    操作的总数目在[1, 10000]范围内。
    不要使用内建的哈希集合库。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-hashset
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*******************************************************************/

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet()
    :vec(1000001, 0) {

    }
    
    void add(int key) {
        vec[key] = 1;
    }
    
    void remove(int key) {
        vec[key] = 0;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return vec[key] != 0;
    }
    vector<int> vec;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */


// 测试主程序
int main()
{
    // 测试用例
    
    MyHashSet* obj = new MyHashSet();
    obj->add(1);
    obj->remove(1);
    bool param_3 = obj->contains(1);



    return 0;
}