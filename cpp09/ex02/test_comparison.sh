#!/bin/bash

# Path to your sorting executable
PROGRAM=./PmergeMe

# Function to compute expected number of comparisons using bc
expected_comparisons() {
    n=$1
    sum=0
    for ((k=1; k<=n; k++)); do
        value=$(echo "scale=6; (3/4)*$k" | bc -l)
        log2=$(echo "l($value)/l(2)" | bc -l)
        ceil_log2=$(echo "($log2+0.999999)/1" | bc)
        sum=$((sum + ceil_log2))
    done
    echo $sum
}

echo "🔍 Running quick test (10 random sizes)..."

FAIL=0

for i in {1..10}; do
    # Random size between 1 and 3000
    n=$(( (RANDOM % 3000) + 1 ))

    # Generate sequence as a string
    SEQ=$(shuf -i 1-100000 -n $n | tr "\n" " ")

    # Run the program with the sequence as arguments
    OUTPUT=$($PROGRAM $SEQ)

    # Get comparison count from program output
    COMP=$(echo "$OUTPUT" | grep "Comparisons:" | awk '{print $2}')

    # Compute expected comparisons
    EXPECTED=$(expected_comparisons $n)

    # Compare and show result
    if [ "$COMP" -le "$EXPECTED" ]; then
        echo "✅ Test $i (size: $n): $COMP ≤ $EXPECTED"
    else
        echo "❌ Test $i (size: $n): $COMP > $EXPECTED"
        FAIL=$((FAIL+1))
    fi
done

echo
echo "📝 Summary:"
if [ "$FAIL" -eq 0 ]; then
    echo "🎉 All tests passed!"
else
    echo "⚠️  $FAIL test(s) failed."
fi

exit 0

