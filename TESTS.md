# Testing `money_converter` Program

Guide for testing the `money_converter` program.

## Test Cases

### Test Case 1: cents
**Input:**
10
**Expected Output:**
10 cents: zero dollars ten cents

---

### Test Case 2: tens
**Input:**
1000
**Expected Output:**
1000 cents: ten dollars 

---

### Test Case 3: hundred
**Input:**
10000
**Expected Output:**
10000 cents: one hundred dollars 

---

### Test Case 4: thousand
**Input:**
100000
**Expected Output:**
100000 cents: one thousand dollars 

---

### Test Case 4: zero
**Input:**
0
**Expected Output:**
0 cents: zero dollars
---

### Instructions to Test
1. Compile the program using:
   make 

Run the program:
./memoization

2. To run tests.sh
   use comand chmod +x tests.sh

Run the test:
./tests.sh

Enter the rod length and piece data according to the test cases above.

Verify the output matches the expected results.
