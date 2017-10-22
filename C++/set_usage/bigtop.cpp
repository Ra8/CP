#include <iostream>
#include <iomanip>
#include <set>
#include <algorithm>
#include <cassert>
using namespace std;
typedef long long int lli;
typedef long double lld;

const long long int lower_x = -87999999;
const long long int upper_x = 99999999;

struct point {
	lli x, y;
};

bool a_shadows_b(point a, point b);
lld area_between(lli x1, lli y1, lli x2, lli y2){
	lli d = max(x1, x2) - min(x1, x2);
	if(max(x1, x2) == upper_x || min(x1, x2) == lower_x){

		return (max(y1, y2) * max(y1, y2)) / 2.0;
	}
	
	point p1, p2;
	p1.x = x1;
	p1.y = y1;
	p2.x = x2;
	p2.y = y2;
	assert(! a_shadows_b(p1, p2) && ! a_shadows_b(p2, p1));
	lli y_big, y_lil;
	y_big = max(y1, y2);
	y_lil = min(y1, y2);
	if(d > y_big + y_lil)
		return ((y_big * y_big + y_lil * y_lil)) / 2.0;
	lld alpha = (d + y_lil - y_big) / 2.0;
	lld base = d * (y_lil - alpha);
	lld t_sum = (alpha * alpha)/2.0 + (d - alpha)*(d-alpha)/2.0;
	lld ans = base + t_sum;
	if(ans < 0)
		cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	assert(ans > 0);
	return ans;	

}

bool operator<(const point &a, const point &b){
	return a.x < b.x;
}

bool a_shadows_b(point a, point b){
	if(a.x == lower_x || a.x == upper_x || b.x == lower_x || b.x == upper_x)
		return false;
	if(a.x < b.x)
		return a.y - (b.x - a.x) >= b.y;
	else
		return a.y - (a.x - b.x) >= b.y;
}

struct TentRep{
	set<point> curr_points;
	lld curr_area;
	lli i_area;
	void init(){
		point p_l, p_h;
		p_l.x = lower_x;
		p_l.y = 0;
		p_h.x = upper_x;
		p_h.y = 0;
		curr_points.insert(p_l);
		curr_points.insert(p_h);
		curr_area = 0.0;
		i_area = 0;
	}	

	void _remove_and_update(point tent){

		
		point lower = *(--curr_points.find(tent));
		point upper = *(++curr_points.find(tent));
		curr_area -= area_between(tent.x, tent.y, lower.x, lower.y); 
		curr_area -= area_between(tent.x, tent.y, upper.x, upper.y); 
		curr_area += area_between(lower.x, lower.y, upper.x, upper.y);
		curr_points.erase(tent);
	}

	void _add_and_update(point tent){
		
		curr_points.insert(tent);

		point lower = *(--curr_points.find(tent));
		point upper = *(++curr_points.find(tent));
		curr_area += area_between(tent.x, tent.y, lower.x, lower.y); 
		curr_area += area_between(tent.x, tent.y, upper.x, upper.y); 
		curr_area -= area_between(lower.x, lower.y, upper.x, upper.y);	

	
	}

	void add_tent(lli x, lli y){
		point p;
		p.x = x;
		p.y = y;
		point lower = *(--curr_points.lower_bound(p));
		point upper = *curr_points.upper_bound(p);
		//cout << "found upper and lower" << endl;
		if(a_shadows_b(lower, p) || a_shadows_b(upper, p)){
		
			return;
		}
	
		// fix lower
		//
		while(a_shadows_b(p, lower)){
			_remove_and_update(lower);
			lower = *(--curr_points.lower_bound(p));
			//cout << lower.x << endl;
		}

		while(a_shadows_b(p, upper)){
			_remove_and_update(upper);
			upper = *(curr_points.upper_bound(p));
				
		//	cout << upper.x << endl;
		}
		//cout << curr_area << " -> " << endl;
		_add_and_update(p);
		set<point>::iterator it;
		//for(it = curr_points.begin(); it != curr_points.end(); it++)
		//	cout << (*it).x << " ";

		//cout << endl << curr_area << endl;
	//	i_area = (lli)(4.0 * curr_area);
		assert(curr_area > 0);
	}


};

void solve(int case_num){
	lli N;
	cin >> N;
	lli x, a_x, b_x, c_x, h, a_h, b_h, c_h;
	cin >> x >> a_x >> b_x >> c_x;
       	cin >> h >> a_h >> b_h >> c_h;
	lld total_area = 0;
	TentRep curr_rep;
	curr_rep.init();
	for(int i = 0; i < N; i++){
		
		curr_rep.add_tent(x, h);
		total_area += curr_rep.curr_area;
		//cout << curr_rep.i_area << endl;		
		x = ((a_x * x) + b_x) % c_x + 1;
		h = ((a_h * h) + b_h) % c_h + 1;
	}
	cout << "Case #" << case_num << ": " << setprecision(99) << total_area << endl;
		
}

int main(){
	point p1, p2;
	p1.x = 1;
	p1.y = 1;
	p2.x = 2;
	p2.y = 2;
	assert(a_shadows_b(p2, p1));

	int T;
	cin >> T;
	for(int i = 0; i < T; i++)
		solve(i + 1);
	return 0;
	
}
