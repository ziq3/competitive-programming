### 1. Setup:

- Uncheck "hide extensions for known file types"
- Set compiler flag:
  - *All:*
    - `-std=c++11, -D_GLIBCXX_DEBUG, -D_GLIBCXX_DEBUG_PEDANTIC -fno-sanitize-recover`
  - *Specific for Codeblock:*
    - `-Wconversion, -Wshadow, -pedantic, -Wunused-variable, -Wall, -Wextra`
- Write template files: `main.cpp`, `com.bat`, `st.bat`

### 2. Algorithm Design:

- Develop the algorithm on paper.
- Verify correctness and time complexity before coding.
- Identify potential edge cases and tricky scenarios.

### 3. Testing:

- Stress test with small and large input values.
- Create manual test cases covering different scenarios.
