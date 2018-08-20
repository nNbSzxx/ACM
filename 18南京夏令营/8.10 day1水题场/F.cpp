//#include <iostream>
//#include <algorithm>
//#include <cstring>
//#include <cstdio>
//#include <set>
//#include <vector>
//using namespace std;
//const int MAX = 2e5 + 10;
//int n;
//
//struct node {
//	vector<int> v;
//	vector<int> id;
//	node() {}
//	node(int x, int idd) {
//		v.push_back(x);
//		id.push_back(idd);
//	}
//	bool operator== (const node& rhs) const {
//		return v.back() == rhs.v.back();
//	}
//	bool operator< (const node& rhs) const {
//		return v.back() < rhs.v.back();
//	}
//	bool operator!= (const node& rhs) const {
//		return v.back() != rhs.v.back();
//	}
//};
//
//set<node> s; 
//
////void display(const node& nd)
////{
////	for (auto a : nd.v) {
////		printf("%d ", a);
////	}
////	puts("");
////}
//
//int main()
//{
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i ++) {
//		int a;
//		scanf("%d", &a);
////		printf("a: %d\n", a);
//		auto it = lower_bound(s.begin(), s.end(), node(a, i));
//		if (it != s.begin()) {
//			-- it;
//			node tmp = *it;
////			printf("tmp: ");
////			display(tmp);
//			if (tmp.v.back() + 1 == a) {
////				printf("erase it\n");
////				printf("%d %d\n", tmp.v.back(), a);
//				s.erase(it);
//				tmp.v.push_back(a);
//				tmp.id.push_back(i);
////				printf("push_back: ");
////				display(tmp);
//				auto it2 = lower_bound(s.begin(), s.end(), tmp);
//				if (it2 != s.end()) {
////					printf("it2\n");
////					display(*it2);
//					if (tmp == *it2 && tmp.v.size() > it2 -> v.size()) {
//						s.erase(it2);
////						printf("erase it2:");
////						display(*it2);
//						s.insert(tmp);
//					} else {
//						s.insert(tmp);
//					}
//				} else {
////					printf("insert: ");
////					display(tmp);
//					s.insert(tmp);
//				}
//			} else {
////				printf("insert: ");
////				display(node(a, i));
//				s.insert(node(a, i));
//			}
//		} else {
//			//	printf("insert: ");
//			//		display(node(a, i));
//			s.insert(node(a, i));
//		}
//	}
//	int maxx = 0;
//	node ans;
//	for (auto it = s.begin(); it != s.end(); ++ it) {
//		if (it -> v.size() > maxx) {
//			maxx = it -> v.size();
//			ans = *it;
//		}
//	}
//	printf("%d\n", maxx);
//	for (auto a : ans.id) {
//		printf("%d ", a);
//	}
//	return 0;
//}

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

//struct node {
//	vector<int> id;
//	int last;
//	bool operator== (const node& rhs) const {
//		return last == rhs.last;
//	}
//};

const int MAX = 2e5 + 10;
map<int, int> mp;
int n;
int a[MAX];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		
		if (mp.count(a[i] - 1)) {
			mp[a[i]] = max(mp[a[i]], mp[a[i] - 1] + 1);
		} else {
			mp[a[i]] = 1;
		}
	}
	int maxx = 0;
	int end = -1;
	for (auto it = mp.begin(); it != mp.end(); it ++) {
		if (maxx < it -> second) {
			maxx = it -> second;
			end = it -> first;
		} 
	}
	printf("%d\n", maxx);
	int cur = end - maxx + 1;
	for (int i = 1; i <= n; i ++) {
		if (a[i] == cur) {
			printf("%d ", i);
			++ cur;
		}
		if (cur > end) {
			break;
		}
	}
	return 0;
}
