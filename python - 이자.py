# -*- coding: utf-8 -*-
"""Untitled10.ipynb

Automatically generated by Colab.

Original file is located at
    https://colab.research.google.com/drive/1z7XCYCapLCUgbKXy-x4S0whMoxiVFq2n
"""

def interest_year(p, r, n):
  return p * (1+r)**n

p = 30000000
r = 0.051
n = 5
result = interest_year(p, r, n)

print('원금: {0}, 이자: {1}'.format(p, result-p))