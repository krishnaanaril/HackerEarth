# January Circuits 2018 - Editorial + Codebase

- Mike and congruence relation

      If k divides n, then there will be n/k numbers with same value. So the number of pairs will be,
      let cnt = n/k then ans = cnt*(cnt-1)/2 or nC2. If there are remainders then we need to consider them as well.

- Roads

      Input constraints are very small, we can try with dp for all possible values. 
