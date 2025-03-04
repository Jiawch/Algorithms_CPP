### 数学算法
 - [排列公式](./permutations.cpp)
   - A(n,m) = n! / (n-m)!
 - [组合公式](./combination.cpp)
   - C(n,m) = A(n,m) / m! = n! / (m!(n-m)!)
   - C(n,m) = C(n-1,m-1) + C(n-1,m)
 - [不同进制的转化](./binaryConversion.cpp)
   - 十进制转任意进制：倒除法，直到商为0停止
   - 任意进制转十进制：遍历，移位相加

### 概率

- 条件概率: P(B|A) = P(AB)/p(A)
- 全概率: P(A) = \sum P(AB_i)
- 乘法定理: P(ABC) = P(A)P(B|A)P(C|AB)
