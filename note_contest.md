### 1. Setup:
- Set compiler flag:
  - *All:*
    - `-std=c++11, -D_GLIBCXX_DEBUG, -D_GLIBCXX_DEBUG_PEDANTIC -fno-sanitize-recover, -O2`
  - *Specific for Codeblock:*
    - `-Wconversion, -Wshadow, -pedantic, -Wunused-variable, -Wall, -Wextra,-Wfatal-errors`
  - *Pragma:*
    - `#pragma GCC optimize(3)`
    - `#pragma GCC target("avx2")`
- Write template files: `main.cpp`, `st.bat`

### 2. Thinking:
- Check understanding problem by samples

### 2. Algorithm Design:
- Develop the algorithm on paper.
- Verify correctness and time complexity before coding.
- Identify potential edge cases and tricky scenarios.

### 3. Testing:

- Stress test with small and large input values.
- Create manual test cases covering different scenarios.
- Don't use `if (fopen)` in brute.cpp, gen.cpp
