#include <iostream>
#include <vector>

std::pair<std::vector<int>, std::vector<int>> transposeGraph(const std::vector<int>& V, const std::vector<int>& E) {
    int n = V.size() - 1;
    int m = E.size();

    // Initialize V~ and E~ arrays
    std::vector<int> V_tilde(n+1, 0);
    std::vector<int> E_tilde(m, 0);
    std::vector<int> din(n, 0);

    V_tilde[0] = 1; // Based on provided pseudocode

    // Compute in-degrees (which will become out-degrees in the transposed graph)
    for (int e = 0; e < m; ++e) {
        din[E[e] - 1]++;
    }

    // Build V_tilde
    for (int i = 1; i <= n; ++i) {
        V_tilde[i] = V_tilde[i - 1] + din[i - 1];
    }

    // Build E_tilde
    for (int s = 0; s < n; ++s) {
        for (int e = V[s] - 1; e <= V[s + 1] - 2; ++e) {
            int old_target = E[e];
            int old_source = s + 1;
            din[old_target - 1]--;
            E_tilde[V_tilde[old_target - 1] - 1 + din[old_target - 1]] = old_source;
        }
    }

    return {V_tilde, E_tilde};
}

int main() {
    std::vector<int> V = {1,3,5,8,9,12,14};
    std::vector<int> E = {3,4,1,3,4,5,6,6,1,2,6,1,5};

    auto [V_transposed, E_transposed] = transposeGraph(V, E);

    std::cout << "V_transposed = ";
    for (int v : V_transposed) {
        std::cout << v << " ";
    }
    std::cout << "\nE_transposed = ";
    for (int e : E_transposed) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    return 0;
}
