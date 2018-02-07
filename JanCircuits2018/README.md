# January Circuits 2018 - Editorial + Codebase

- Mike and congruence relation

If k divides n, then there will be n/k numbers with same value. So the number of pairs will be,
let cnt = n/k then ans = cnt*(cnt-1)/2 or nC2. If there are remainders then we need to consider them as well.

- Roads

Input constraints are very small, we can try with dp for all possible values.

- Array Construction

Approximate problem. Need to solve correctly (Pending).

- Buying items

First of all we have that if n≤m then n2≤n×m≤500⟹n≤22. Let's make a graph with each node representing a mask for 2n subsets of possible objects. After that we can add an edge for every seller i from node mask to node maskorM[i] with cost Ci and in the end the answer is the shortest path from 0 to 2n−1. Because the graph is directed and topologically sorted we can find the answer in O(2n×m). Similarly if m≤n⟹m≤22 so we can brute force all possible sellers and find the best answer with complexity O(2m×n×m32).
