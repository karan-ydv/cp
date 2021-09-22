#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct P{
    int x, y;
    void read(){
        cin >> x >> y;
    }
    P operator - (const P &b) const{
        return P{x - b.x, y - b.y};
    }
    void operator -= (const P &b){
        x -= b.x;
        y -= b.y;
    }
    P operator + (const P &b) const{
        return P{x + b.x, y + b.y};
    }
    void operator += (const P &b){
        x += b.x; y += b.y;
    }
    int operator * (const P &b) const{
        return x*b.y - y*b.x;
    }
    int triangle(const P &b, const P &c) const{
        return (b - *this)*(c - *this);
    }
    double dist(const P& b) const {
        return sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
    }
};
bool intersection(P p1, P p2, P p3, P p4){
    if((p2 - p1)*(p4 - p3) == 0){
        if(p1.triangle(p2, p3) != 0) return 0;
        for(int i = 0; i < 2; i++){
            if(max(p1.x, p2.x) < min(p3.x, p4.x) || max(p1.y, p2.y) < min(p3.y, p4.y)) return 0;
            swap(p1, p3); swap(p2, p4);
        }
    }
    else{
        for(int i = 0; i < 2; i++){
            long long sgn1 = (p3 - p1)*(p2 - p1), sgn2 = (p4 - p1)*(p2 - p1);
            if((sgn1 < 0 && sgn2 < 0) || (sgn1 > 0 && sgn2 > 0)) return 0;
            swap(p1, p3); swap(p2, p4);
        }
    }
    return 1;
}
bool segment_contains(P p1, P p2, P p){
    if(p.triangle(p1, p2)) return 0;
    if(max(p1.x, p2.x) < p.x || min(p1.x, p2.x) > p.x) return 0;
    if(max(p1.y, p2.y) < p.y || min(p1.y, p2.y) > p.y) return 0;
    return 1;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    cout << setprecision(12);
    for(int _ = 1; _ <= t; _ ++) {
        cout << "Case #" << _ << ": ";
        int n;  cin >> n;
        vector<P> v(n);
        for(P& x: v)    x.read();
        P point;        point.read();
        P out = P{point.x + 1, 4'000'000'000LL};
        
        double ans = 1e18;
        for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
        {
            bool boundary = segment_contains(v[i], v[j], point);
            int a = intersection(point, out, v[i], v[j]);
            if(!boundary)
            for(int k = j + 1; k < n; k++)
            {
                int b = intersection(point, out, v[j], v[k]);
                boundary |= segment_contains(v[j], v[k], point);
                int c = intersection(point, out, v[k], v[i]);
                boundary |= segment_contains(v[k], v[i], point);
                
                double perimeter;
                if(!boundary)
                if((a + b + c) & 1)
                {
                    perimeter = v[i].dist(v[j]) + v[j].dist(v[k]) + v[k].dist(v[i]);
                    ans = min(ans, perimeter);
                }
                else if(v[i].triangle(v[j], v[k]))
                for(int l = k + 1; l < n; l++)
                {
                    c = intersection(point, out, v[k], v[l]);
                    int d = intersection(point, out, v[l], v[i]);
                    if((a + b + c + d) & 1)
                    {
                        perimeter = v;
                        ans = min(ans, perimeter);
                    }
                }
            }
        }
        if(ans == 1e18)
            cout << "IMPOSSIBLE\n";
        else
            cout << ans << '\n';
    }
}