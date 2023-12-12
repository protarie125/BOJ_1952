#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

int m, n;
vvl bd;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> m >> n;
  bd = vvl(m, vl(n, 0));
  bd[0][0] = 1;

  auto x = 0;
  auto y = 0;
  auto ans = ll{0};
  auto dir = 0;
  while (true) {
    if (0 == dir) {
      if (n <= x + 1 || 1 == bd[y][x + 1]) {
        if (m <= y + 1 || 1 == bd[y + 1][x]) {
          break;
        }

        ++ans;
        dir = 1;
      } else {
        bd[y][x] = 1;
        ++x;
      }
    } else if (1 == dir) {
      if (m <= y + 1 || 1 == bd[y + 1][x]) {
        if (x - 1 < 0 || 1 == bd[y][x - 1]) {
          break;
        }

        ++ans;
        dir = 2;
      } else {
        bd[y][x] = 1;
        ++y;
      }
    } else if (2 == dir) {
      if (x - 1 < 0 || 1 == bd[y][x - 1]) {
        if (y - 1 < 0 || 1 == bd[y - 1][x]) {
          break;
        }

        ++ans;
        dir = 3;
      } else {
        bd[y][x] = 1;
        --x;
      }
    } else {
      if (y - 1 < 0 || 1 == bd[y - 1][x]) {
        if (n <= x + 1 || 1 == bd[y][x + 1]) {
          break;
        }

        ++ans;
        dir = 0;
      } else {
        bd[y][x] = 1;
        --y;
      }
    }
  }

  cout << ans;

  return 0;
}