#!/bin/bash

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Function to print test header
print_header() {
    echo -e "\n${BLUE}===== $1 =====${NC}"
}

# Function to run a test case
run_test() {
    local test_name="$1"
    local command="$2"
    local expected_output="$3"
    local expected_exit_code="$4"
    
    echo -e "${YELLOW}Testing: $test_name${NC}"
    echo -e "Command: $command"
    
    # Run the command and capture output and exit code
    output=$(eval "$command" 2>&1)
    exit_code=$?
    
    # Check if the output matches the expected output
    if [[ "$output" == "$expected_output" ]]; then
        output_match=true
    else
        output_match=false
    fi
    
    # Check if the exit code matches the expected exit code
    if [[ $exit_code == $expected_exit_code ]]; then
        exit_match=true
    else
        exit_match=false
    fi
    
    # Print result
    if [[ $output_match == true && $exit_match == true ]]; then
        echo -e "${GREEN}✓ PASS${NC}"
    else
        echo -e "${RED}✗ FAIL${NC}"
        if [[ $output_match == false ]]; then
            echo -e "Expected output: '$expected_output'"
            echo -e "Actual output:   '$output'"
        fi
        if [[ $exit_match == false ]]; then
            echo -e "Expected exit code: $expected_exit_code"
            echo -e "Actual exit code:   $exit_code"
        fi
    fi
}

# Function to check for memory leaks with Valgrind
check_leaks() {
    local test_name="$1"
    local command="$2"
    
    echo -e "${YELLOW}Checking for memory leaks: $test_name${NC}"
    echo -e "Command: $command"
    
    # Run the command with Valgrind
    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --quiet $command > /dev/null 2>&1
    exit_code=$?
    
    # Check if Valgrind found any leaks
    if [[ $exit_code == 0 ]]; then
        echo -e "${GREEN}✓ NO LEAKS${NC}"
    else
        echo -e "${RED}✗ LEAKS DETECTED${NC}"
    fi
}

# Compile the program
print_header "Compiling push_swap"
make re

# Check if compilation was successful
if [[ $? != 0 ]]; then
    echo -e "${RED}Compilation failed. Exiting.${NC}"
    exit 1
fi

# Test cases for correct functionality
print_header "Testing correct functionality"

# Test with multiple numerical arguments
run_test "Multiple numerical arguments" "./push_swap 1 3 5 +9 20 -4 50 60 04 08" "" 0

# Test with a single string argument
run_test "Single string argument" "./push_swap \"3 4 6 8 9 74 -56 +495\"" "" 0

# Test with INT_MAX
run_test "INT_MAX" "./push_swap 2147483647 2 4 7" "" 0

# Test with INT_MIN
run_test "INT_MIN" "./push_swap 99 -2147483648 23 545" "" 0

# Test with INT_MAX in a string
run_test "INT_MAX in string" "./push_swap \"2147483647 843 56544 24394\"" "" 0

# Test with negative and positive numbers
run_test "Negative and positive numbers" "./push_swap \"95 99 -9 10 9\"" "" 0

# Test cases for error handling
print_header "Testing error handling"

# Test with non-numeric characters
run_test "Non-numeric characters" "./push_swap 1 3 dog 35 80 -3" "Error" 0

# Test with a single non-numeric character
run_test "Single non-numeric character" "./push_swap a" "Error" 0

# Test with mixed numeric and non-numeric characters
run_test "Mixed numeric and non-numeric characters" "./push_swap 1 2 3 5 67b778 947" "Error" 0

# Test with non-numeric characters in a string
run_test "Non-numeric characters in string" "./push_swap \" 12 4 6 8 54fhd 4354\"" "Error" 0

# Test with invalid format
run_test "Invalid format" "./push_swap 1 --    45 32" "Error" 0

# Test with duplicate numbers
run_test "Duplicate numbers" "./push_swap 1 3 58 9 3" "Error" 0

# Test with duplicate numbers (different format)
run_test "Duplicate numbers (different format)" "./push_swap 3 03" "Error" 0

# Test with duplicate numbers in a string
run_test "Duplicate numbers in string" "./push_swap \" 49 128     50 38   49\"" "Error" 0

# Test with numbers exceeding INT_MAX
run_test "Numbers exceeding INT_MAX" "./push_swap 54867543867438 3" "Error" 0

# Test with numbers exceeding INT_MIN
run_test "Numbers exceeding INT_MIN" "./push_swap -2147483647765 4 5" "Error" 0

# Test with numbers exceeding INT_MAX in a string
run_test "Numbers exceeding INT_MAX in string" "./push_swap \"214748364748385 28 47 29\"" "Error" 0

# Test with mixed strings and integers
run_test "Mixed strings and integers" "./push_swap \"1 2 4 3\" 76 90 \"348 05\"" "" 0

# Test with empty arguments
run_test "Empty arguments" "./push_swap" "" 0

# Test with empty string
run_test "Empty string" "./push_swap \"\"" "Error" 0

# Test with only spaces
run_test "Only spaces" "./push_swap \"   \"" "Error" 0

# Test with only signs
run_test "Only signs" "./push_swap \"+++ ---\"" "Error" 0

# Test with multiple signs
run_test "Multiple signs" "./push_swap \"1 ++2 3\"" "Error" 0

# Test with signs at the end
run_test "Signs at the end" "./push_swap \"1 2 3 + -\"" "Error" 0

# Check for memory leaks
print_header "Checking for memory leaks"

# Check for leaks with correct input
check_leaks "Correct input" "./push_swap 1 3 5 +9 20 -4 50 60 04 08"

# Check for leaks with string input
check_leaks "String input" "./push_swap \"3 4 6 8 9 74 -56 +495\""

# Check for leaks with error input
check_leaks "Error input" "./push_swap 1 3 dog 35 80 -3"

# Check for leaks with duplicate numbers
check_leaks "Duplicate numbers" "./push_swap 1 3 58 9 3"

# Check for leaks with INT_MAX
check_leaks "INT_MAX" "./push_swap 2147483647 2 4 7"

# Check for leaks with INT_MIN
check_leaks "INT_MIN" "./push_swap 99 -2147483648 23 545"

# Check for leaks with mixed strings and integers
check_leaks "Mixed strings and integers" "./push_swap \"1 2 4 3\" 76 90 \"348 05\""

echo -e "\n${BLUE}All tests completed!${NC}" 