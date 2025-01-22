#!/bin/bash

problem="treeguessr"
grader_name="grader"

g++ -std=gnu++17 -O2 -Wall -pipe -static -o "${problem}.exe" "${grader_name}.cpp" "${problem}.cpp"
