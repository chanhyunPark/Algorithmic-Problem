#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int N; // 노드 갯수
int h; // 로그 2*N 올림
int tree_size; // 트리 사이즈
long long init(vector<long long> &arr, vector<long long> &tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = arr[start];

	int mid = (start + end) / 2;

	return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);
}

void init2(vector<int> &arr, vector<int> &tree, int node, int start, int end) 
{
	if(start == end)
		tree[node] = start; //위치 저장 땜에
	else
	{
		int mid = (start + end) / 2;
		init2(arr, tree, node * 2, start, mid);
		init2(arr, tree, node * 2 + 1, mid + 1, end);
		if (arr[tree[node * 2]] <= arr[tree[node * 2 + 1]])
		{
			tree[node] = tree[node * 2];
		}
		else
		{
			tree[node] = tree[node * 2 + 1];
		}
	}
}

int query(vector<int> &arr, vector<int> &tree, int node, int start, int end, int i, int j)
{
	if (i > end || j < start) //end와 start 범위를 벗어나면 -1
	{
		return -1;
	}

	if (i <= start && end <= j) // i가 start거나 j가 end면 tree 반환
	{
		return tree[node];
	}

	int mid = (start + end) / 2;
	int m1 = query(arr,tree, 2 * node, start, mid, i, j);
	int m2 = query(arr, tree, 2 * node + 1,	mid + 1, end, i, j);

	if (m1 == -1)
	{
		return m2;
	}
	else if (m2 == -1)
	{
		return m1;
	}
	else
	{
		if (arr[m1] < arr[m2])
		{
			return m1;
		}
		else
			return m2;
	}
}

long long largest(vector<int> &arr, vector<int> &tree, int start, int end)
{
	int n = arr.size();
	int m = query(arr,tree,1,0,n-1,start,end);
	long long area = (long long)(end - start + 1) * arr[m]; // 가로 곱 세로
	
	if (start <= m - 1)
	{
		long long temp = largest(arr, tree, start, m-1);
		if (area < temp)
			area = temp;
	}
	
	if (m + 1 <= end)
	{
		long long temp = largest(arr, tree, m+1, end);
		if (area < temp)
			area = temp;
	}

	return area;
}

//tree 벡터, node 번호, start, end, index - 바꾸고자하는 인덱스 번호, 차이(전 값 - 후 값)
void update(vector<long long> &tree, int node, int start, int end, int index, long long diff)
{
	if (!(start <= index && index <= end))
		return;

	tree[node] += diff;

	if (start != end)
	{
		int mid = (start + end) / 2;
		update(tree, node * 2, start, mid, index, diff);
		update(tree, node * 2 + 1, mid + 1, end, index, diff);
	}
}

long long sum(vector<long long> &tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
	{
		return 0;
	}

	if (left <= start && end <= right)
	{
		return tree[node];
	}

	int mid = (start + end) / 2;
	return sum(tree, node * 2, start, mid, left, right) + sum(tree, node * 2 + 1, mid + 1, end, left, right);
}


//새그먼트 트리
int main(void)
{
	int N;
	while (true)
	{
		vector<int> v;
		cin >> N;

		if (N == 0)
			break;

		for (int n = 0; n < N; n++)
		{
			int num;
			cin >> num;
			v.push_back(num);
		}

		h = (int)ceil(log2(N)); // 2^k > N 
		tree_size = (1 << (h + 1)); // 2^k * 2를 하면 세그먼트 트리 크기
		
		vector<int> tree(tree_size);
		init2(v, tree, 1, 0, N-1);
		cout << largest(v, tree, 0, N - 1) << '\n';
	}
}