#include <bits/stdc++.h>
using namespace std;

#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p)
{
	return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container,
	  typename T = typename enable_if<!is_same<T_container, string>::value,
					  typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
	os << '{';
	string sep;
	for (const T &x : v)
		os << sep << x, sep = ", ";
	return os << '}';
}
void dbg_out()
{
	cout << endl;
}
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T)
{
	cout << ", " << H;
	dbg_out(T...);
}
