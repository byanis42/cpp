#!/bin/bash

# Define color codes for output formatting
GREEN="\033[0;32m"
RED="\033[0;31m"
NC="\033[0m" # No Color

# Array of test cases: each element is a string containing the input and expected output
tests=(
	# Format: "InputExpression|ExpectedOutput"
	"8 9 * 9 - 9 - 9 - 4 - 1 +|42"
	"7 7 * 7 -|42"
	"1 2 * 2 / 2 * 2 4 - +|0"
	"(1 + 1)|Error"
	"5 1 2 + 4 * + 3 -|14"
	"2 3 + 5 *|25"
	"9 5 1 2 + * + 7 -|17"
	"4 2 / 5 * 3 +|13"
	"3 5 +|8"
	"10 2 8 * + 3 -|Error"  # 10 is invalid input
	"2 3 ^|Error"  # Invalid operator
	"1 2 + +|Error"  # Too many operators
	"5|5"  # Single operand
	"|Error"  # Empty input
)

# Function to run a single test case
run_test() {
	input=$(echo "$1" | cut -d'|' -f1)
	expected=$(echo "$1" | cut -d'|' -f2)

	# Run the RPN program with the test input
	actual=$(./RPN "$input" 2>&1)

	# Compare the actual output with the expected output
	if [ "$actual" == "$expected" ]; then
		status="${GREEN}✔${NC}"
		result="Passed"
	else
		status="${RED}✘${NC}"
		result="Failed"
	fi

	# Display the test case result
	echo -e "Input: \"$input\""
	echo -e "Expected Output: $expected"
	echo -e "Actual Output:   $actual"
	echo -e "Result: $status $result"
	echo "----------------------------------------"
}

# Main loop to run all test cases
echo "Starting tests..."
echo "========================================"
for test_case in "${tests[@]}"; do
	run_test "$test_case"
done
echo "All tests completed."
