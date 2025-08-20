#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'maximizeDecryptionValue' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY scores
#  2. INTEGER_ARRAY decryptionStatus
#  3. INTEGER k
#

def maximizeDecryptionValue(scores, decryptionStatus, k):
    # Write your code her
    maxVal = scores[0]
    status = decryptionStatus
    
    for l in range(len(scores)):
        r = (l + k) % len(scores)

        status[l:r] = 1
        curr = 0
        for i in range(l:r):
            curr += scores[i]

        maxVal = max(maxVal, curr)
    return maxVal
        



if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    scores_count = int(input().strip())

    scores = []

    for _ in range(scores_count):
        scores_item = int(input().strip())
        scores.append(scores_item)

    decryptionStatus_count = int(input().strip())

    decryptionStatus = []

    for _ in range(decryptionStatus_count):
        decryptionStatus_item = int(input().strip())
        decryptionStatus.append(decryptionStatus_item)

    k = int(input().strip())

    result = maximizeDecryptionValue(scores, decryptionStatus, k)

    fptr.write(str(result) + '\n')

    fptr.close()

