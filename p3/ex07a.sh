#!/bin/bash
# Calculate the sum of a series of numbers.
SCORE="0"
SUM="0"
COUTER="0"
MEDIA="0"
while true; do
    echo -n "Enter your score [0-10] ('q' to quit): "
    read SCORE;
    if (("$SCORE" < "0")) || (("$SCORE" > "10")); then
        echo "Try again: "
    elif [[ "$SCORE" == "q" ]]; then
        echo "Sum: $SUM."
        echo "Media: $MEDIA."
        break
    else
        SUM=$((SUM + SCORE))
        COUTER=$((COUNTER + 1))
        MEDIA=$((SUM + COUNTER))
    fi
done
echo "Exiting."