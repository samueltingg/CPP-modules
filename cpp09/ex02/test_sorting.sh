#!/bin/bash

# Number of tests to run (default to 10 if not provided)
NUM_TESTS=${1:-10}

# Path to your program
PROGRAM="./PmergeMe"

# Test parameters
RANGE="1-100000"
COUNT=3000

# Counters
PASS=0
FAIL=0

echo "🔍 Starting $NUM_TESTS tests on $PROGRAM"
echo "-----------------------------------------"

for ((i=1; i<=NUM_TESTS; i++)); do
    # Generate random input
    INPUT=$(shuf -i $RANGE -n $COUNT | tr "\n" " ")

    # Run the program and capture output
    OUTPUT=$($PROGRAM $INPUT)

    # Check if "Sorted" appears in output
    if echo "$OUTPUT" | grep -q "Sorted"; then
        echo -e "✅ Test $i: Sorted"
        ((PASS++))
    else
        echo -e "❌ Test $i: Not Sorted"
        ((FAIL++))
    fi
done

echo "-----------------------------------------"
echo "🎉 Testing complete!"
echo "✅ Passed: $PASS / $NUM_TESTS"
echo "❌ Failed: $FAIL / $NUM_TESTS"

# Optional: exit code based on result
if [ "$FAIL" -eq 0 ]; then
    exit 0
else
    exit 1
fi
