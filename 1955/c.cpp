#include <iostream>
#include <vector>
#include <algorithm>

int sunk_ships(int n, int k, std::vector<int>& arr) {
  int start = 0, end = n - 1;
  while (k > 0 && start < end) {
    int a = arr[start], b = arr[end];
    if (a <= b) {
      if (k < 2 * a - 1) break;
      start++;
      arr[end] -= a - 1;
      k -= 2 * a - 1;

      if (k > 0) {
        arr[end] -= 1;
        if (arr[end] == 0) end--;
        k -= 1;
      }
    } else {
      if (k < 2 * b) break;
      end--;
      arr[start] -= b;
      k -= 2 * b;
    }
  }

  if (start == end && k >= arr[start]) start++;
  return n - (end - start + 1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
  
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int n, k;
        std::cin >> n >> k;

        std::vector<int> arr(n);
        for (int j = 0; j < n; j++) {
            std::cin >> arr[j];
        }

        std::cout << sunk_ships(n, k, arr) << '\n';
    }

    return 0;
}
