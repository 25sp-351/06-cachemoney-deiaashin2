#!/bin/bash

# this is testing the `money_converter` program.

echo "Compiling the program money_converter"
make 
if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

# Function to run a single test case
run_test() {
    input=$1
    expected_output=$2

    # Run the program and capture its output
    actual_output=$(echo "$input" | ./memoization)

    # Compare the actual output to the expected output
    if [ "$actual_output" == "$expected_output" ]; then
        echo "Test suceed: Input ($input)"
    else
        echo "Test failed: Input ($input)"
        echo "Expected: $expected_output"
        echo "Got: $actual_output"
        exit 1
    fi
}

# Run all test cases
echo "Running tests..."

# Test Case 1: cents
run_test 10 "10 cents: zero dollars and ten cents"

# Test Case 2: tens
run_test 1000 "1000 cents: ten dollars"

# Test Case 3: hundred
run_test 10000 "10000 cents: one hundred dollars"

# Test Case 4: thousand
run_test 100000 "100000 cents: one thousand dollars"

# Test Case 5: zero
run_test 0 "0 cents: zero dollars"

echo "All tests passed!"
