#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
��Ŀ��
A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. 

Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A),

write a program to output the skyline formed by these buildings collectively (Figure B).

The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates 

of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 �� Li, Ri �� INT_MAX, 

0 < Hi �� INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. 

A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to

 mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part 
 
 of the skyline contour.

For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

Notes:

The number of buildings in any input list is guaranteed to be in the range [0, 10000].
The input list is already sorted in ascending order by the left x position Li.
The output list must be sorted by the x position.
There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...]

 is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]
Credits:
Special thanks to @stellari for adding this problem, creating these two awesome images and all test cases.

��������Ŀ�Ƚϳ�����˼���Ǹ���һ����������ʾ���������ȷ����Щ���������ɵ�������ÿ��������һ����Ԫ��[Li, Ri, Hi]��ʾ, Li, Ri��ʾ����������λ�ã�
     �����������ϵ����������꣬Hi��ʾ�߶ȡ����һ���㹹�ɵ����飬��Щ��Ψһȷ��һ�������ߣ�ÿ������������ֱ����ֻ��Ҫһ���㣬����������ֱ���Ͽ���
	 �ж���㣬���ǲ�������Ҳ����˵��ÿ��ˮƽ�߶ε���˵㣬���һ�����������һ���������յ�λ�ã�����x���ϣ��߶�Ϊ0�������⣬��������֮��ĵ���
	 Ҳ�������ߵ�һ���֡�
һЩ����������
���뽨�����������ַ�Χ��[0,10000]�� �������������鰴Li���������У����������Ҳ�����Ժ�����������������������ָ߶���ȵ�ˮƽ�ߣ������������Ҫ����
�鲢��һ���㡣

˼·��
��1������Ϊ���������ұ߽磬����߽�ĸ߶ȴ�Ϊ����������������߽�ʹ�����У������ұ߽��ɾ����
    Ȼ�󿴵�ǰ״̬���޸ı䣬�ı��˻��Ͱ���߽�͵�ǰ�ĸ߶ȴ�������
multiset���ݽṹ����ô��������е�Ԫ���ǰ����ź���ģ�������Ԫ�ؽ�ȥ��������ģ�����ִ��ɾ��Ԫ��Ҳ�ɷ���Ľ�������ͬ��Ԫ��ɾ����

	ֻҪ��ǰ����߽����߶ȷ����仯������ô��Ȼ�����µ������㣬ʹ��һ����ϣ���¼�߶ȣ�
*/
class Solution {
public:
	vector<pair<int, int> > getSkyline(vector<vector<int > >& buildings) {
        vector<pair<int, int> > h, res;
		map<int, int> hcount; //��¼�߶ȣ�������ִ���
        int pre = 0, cur = 0;
        for (int i = 0; i < buildings.size(); ++i) {
            h.push_back(make_pair(buildings[i][0], -buildings[i][2])); //������λ�ã��������߶�����Ϊ������������
            h.push_back(make_pair(buildings[i][1], buildings[i][2]));
        }
		sort(h.begin(), h.end()); //ͳһ����
		hcount[0] = 1; //���ֵ���ʱ�����������Ϊ0�����
		for(int i = 0; i < h.size(); ++i){
			int x = h[i].first, y = h[i].second;
			if(y < 0) ++hcount[-y];
			else{ //�������ұ߽���֣�˵�����������Ѿ���¼�ˣ��ɽ���߶��ڹ�ϣ����ɾ����
				if(hcount[y] <= 1) hcount.erase(y);  
				else --hcount[y];
			}
			cur = hcount.rbegin()->first; //�����������ȡ���һ��Ԫ��
			if(cur != pre){ //ÿ�����߶ȷ����仯ʱ��
				res.push_back(make_pair(x, cur));
				pre = cur;
			}
		}
		return res;
	}
/*
    vector<pair<int, int> > getSkyline(vector<vector<int > >& buildings) {
        vector<pair<int, int> > h, res;
        multiset<int> m;
        int pre = 0, cur = 0;
        for (auto &a : buildings) {
            h.push_back({a[0], -a[2]}); //������λ�ã��������߶�����Ϊ������������
            h.push_back({a[1], a[2]});
        }
        sort(h.begin(), h.end());  //���������ͳһ����
        m.insert(0); //���һ���������������
        for (auto &a : h) {
            if (a.second < 0) m.insert(-a.second); //�����
            else m.erase(m.find(a.second)); //�ҵ�����㣬��ɾ����Ӧ�������
            cur = *m.rbegin(); //ȡ���һ��λ�õĸ߶�
            if (cur != pre) { //����߶Ⱥ���һλ�õĸ߶Ȳ�ͬ�������
                res.push_back({a.first, cur});
                pre = cur;
            }
        }
        return res;
    }
*/
};

int main(){
	Solution c;
	vector<vector<int > > b;
	vector<int > cur;
	cur.push_back(2); cur.push_back(9); cur.push_back(10); 
	b.push_back(cur); cur.clear();
	cur.push_back(3); cur.push_back(7); cur.push_back(15);
	b.push_back(cur); cur.clear();
	cur.push_back(5); cur.push_back(12); cur.push_back(12); 
	b.push_back(cur); cur.clear();
	cur.push_back(15); cur.push_back(20); cur.push_back(10); 
	b.push_back(cur); cur.clear();
	cur.push_back(19); cur.push_back(24); cur.push_back(8); 
	b.push_back(cur); cur.clear();
	vector<pair<int, int > > ans = c.getSkyline(b);
	for(int i = 0; i < ans.size(); ++i)
		cout << ans[i].first << " " << ans[i].second << endl;
	return 0;
}
