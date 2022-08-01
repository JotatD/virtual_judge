#include <iostream>
#include <vector>
using namespace std;

// class segTree{
// public:
// 	segTree* lChild;
// 	segTree* rChild;
// 	int l;
// 	int r;
// 	int sum;
// public:
// 	segTree(vector<int>& v) : segTree(0, v.size()-1, v) {}

// 	segTree(int left, int right, vector<int>& v){
// 		this->l = left;
// 		this->r = right;
// 		if (left == right){
// 			this->lChild = nullptr;
// 			this->rChild = nullptr;
// 			this->sum = v[l];
// 		}
// 		else{
// 			int mid = (left+right)/2;
// 			this->lChild = new segTree(left, mid, v);
// 			this->rChild = new segTree(mid+1, right, v);
// 			recalc();
// 		}
// 	}

// 	int calculate(int left, int right){
// 		if (left <= this->l && right >= this->r) return this->sum;
// 		else if (left > this->r || right < this->l) return 0;
// 		else return this->lChild->calculate(left, right) + rChild->calculate(left, right);
// 	} 

// 	void recalc(){
// 		if (l == r) return;
// 		else this->sum = lChild->sum + rChild->sum;
// 	}
// 	void pointUpdate(int index, int value){
// 		if (l == r){
// 			sum = value;
// 			return;
// 		}

// 		int mid = (this->l + this->r)/2;
// 		if (index <= mid) lChild->pointUpdate(index, value);
// 		else              rChild->pointUpdate(index, value);
	
// 		recalc();
// 	}
// };

class segTree{
public:
	segTree* lChild;
	segTree* rChild;
	int l;
	int r;
	int minimum;
public:
	segTree(vector<int>& v) : segTree(0, v.size()-1, v) {}

	segTree(int left, int right, vector<int>& v){
		this->l = left;
		this->r = right;
		if (left == right){
			this->lChild = nullptr;
			this->rChild = nullptr;
			this->minimum = v[l];
		}
		else{
			int mid = (left+right)/2;
			this->lChild = new segTree(left, mid, v);
			this->rChild = new segTree(mid+1, right, v);
			recalc();
		}
		cout << " l " <<  l  << " r "<< r << " minimum " << minimum << endl;
	}

	int calculate(int left, int right){
		if (left <= this->l && right >= this->r) return this->minimum;
		else if (left > this->r || right < this->l) return -1;
		else return max(this->lChild->calculate(left, right), rChild->calculate(left, right));
	} 

	void recalc(){
		if (l == r) return;
		else this->minimum = max(lChild->minimum, rChild->minimum);
	}
	void pointUpdate(int index, int value){
		if (l == r){
			this->minimum = value;
			return;
		}

		int mid = (this->l + this->r)/2;
		if (index <= mid) lChild->pointUpdate(index, value);
		else              rChild->pointUpdate(index, value);
	
		recalc();
	}
};


// int main(){
// 	vector<int> nums {0,1,2,3,4,5,6,7,8,9,10};

// 	segTree* st = new segTree(nums);

// 	nums[3] = 14;
// 	int sum = 0;
// 	int k = 10;
// 	for (int i = 0; i <= k; i++){
// 		sum+=nums[i];
// 	}

// 	st->pointUpdatePoint(14, 3);
// 	int n = st->calculate(0, k);
// 	cout << n << endl;
// 	cout << sum << endl;

// 	srand(static_cast<unsigned int>(time(nullptr)));
// 	for (int i = 0; i < w; i++){
// 		int a = std::rand()%100;
// 		nums.push_back(a);
// 	}
// 	cout << n << endl;
// 	for (int i = 0; i < 10000; i++){
// 		int a = rand()%w, b = a+(rand()%(w-a)); 
// 		int c = rand()%100, d = a + (rand()%(b-a+1));
// 		nums[d] = c;
// 		int sum = 0;
// 	   	for (int i = a; i <= b; i++){
// 	   		sum += nums[i];
// 	   	}

// 	   	st->pointUpdatePoint(c, d);
	   	
// 	   	int segSum = st->calculate(a, b);

// 	   	if (sum != segSum) {
// 	   		cout << a << " " << b << " " << c << " " << d << endl;
// 	   	}
// 	}
// }


int main(){
	vector<int> nums {1, 2, 3, 4};
	segTree* st = new segTree(nums);
	int segMin = st->calculate(1, 1);
	cout << segMin << endl;

	for(int i)
}





