#!/bin/bash

# Couleurs pour une meilleure lisibilité dans les résultats
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Fonction pour exécuter un test et comparer les résultats
run_test() {
	expected_output="$2"
	actual_output=$(./convert "$1" 2>&1) # Exécution de ./convert avec capture de sortie

	if [ "$actual_output" == "$expected_output" ]; then
		echo -e "${GREEN}Test with input '$1' passed.${NC}"
	else
		echo -e "${RED}Test with input '$1' failed.${NC}"
		echo -e "${RED}Expected output:${NC}"
		echo -e "$expected_output"
		echo -e "${RED}Actual output:${NC}"
		echo -e "$actual_output"
	fi
	echo "----------------------------------------"
}

echo "=== Running tests for ScalarConverter ==="

# Test 1: Conversion d'un entier valide
run_test "42" "char: '*'
int: 42
float: 42.0f
double: 42.0"

# Test 2: Conversion d'un float valide avec notation 'f'
run_test "42.0f" "char: '*'
int: 42
float: 42.0f
double: 42.0"

# Test 3: Conversion d'un double valide
run_test "42.0" "char: '*'
int: 42
float: 42.0f
double: 42.0"

# Test 4: Conversion d'un caractère affichable
run_test "a" "char: 'a'
int: 97
float: 97.0f
double: 97.0"

# Test 5: Conversion du pseudo-littéral 'nan'
run_test "nan" "char: impossible
int: impossible
float: nanf
double: nan"

# Test 6: Conversion du pseudo-littéral '+inf'
run_test "+inf" "char: impossible
int: impossible
float: +inff
double: +inf"

# Test 7: Conversion du pseudo-littéral '-inf'
run_test "-inf" "char: impossible
int: impossible
float: -inff
double: -inf"

# Test 8: Conversion de 0
run_test "0" "char: Non displayable
int: 0
float: 0.0f
double: 0.0"

# Test 9: Conversion d'un entier à la limite de INT_MAX
run_test "2147483647" "char: impossible
int: 2147483647
float: 2147483648.0f
double: 2147483647.0" # Float arrondi est un comportement normal et attendu

# Test 10: Conversion d'une valeur au-dessus de INT_MAX (overflow)
run_test "2147483648" "int: impossible (overflow)"

# Test 11: Conversion d'un entier à la limite de INT_MIN
run_test "-2147483648" "char: impossible
int: -2147483648
float: -2147483648.0f
double: -2147483648.0"

# Test 12: Conversion d'une valeur en dessous de INT_MIN (overflow)
run_test "-2147483649" "int: impossible (overflow)"

# Test 13: Conversion de FLT_MAX (la plus grande valeur float valide)
run_test "3.402823466e+38f" "char: impossible
int: impossible
float: 340282346638528859811704183484516925440.0f
double: 340282346638528859811704183484516925440.0"

# Test 14: Conversion d'une valeur dépassant FLT_MAX (overflow)
run_test "3.402823466e+39f" "float: impossible (overflow)"

# Test 15: Conversion d'un littéral invalide
run_test "abc" "Invalid literal: abc"

echo "=== Testing completed ==="
