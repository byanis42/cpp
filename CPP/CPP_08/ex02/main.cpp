#include "MutantStack.hpp"
#include <iostream>
#include <string>

void testBasicOperations() {
	std::cout << "=== Test Basic Stack Operations ===" << std::endl;
	MutantStack<int> mstack;

	// Ajouter des éléments
	mstack.push(10);
	mstack.push(20);
	std::cout << "Top after push: " << mstack.top() << std::endl; // Devrait afficher 20

	// Supprimer le sommet et vérifier
	mstack.pop();
	std::cout << "Top after pop: " << mstack.top() << std::endl; // Devrait afficher 10

	// Ajouter plusieurs éléments et vérifier la taille
	mstack.push(30);
	mstack.push(40);
	mstack.push(50);
	std::cout << "Stack size: " << mstack.size() << std::endl; // Devrait afficher 4
}

void testIterator() {
	std::cout << "\n=== Test Stack Iterator ===" << std::endl;
	MutantStack<int> mstack;
	for (int i = 1; i <= 5; ++i) {
		mstack.push(i * 10); // Ajoute 10, 20, 30, 40, 50
	}

	// Parcours avec itérateurs
	std::cout << "Stack elements (iterating): ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void testEmptyStack() {
	std::cout << "\n=== Test Operations on Empty Stack ===" << std::endl;
	MutantStack<int> mstack;

	// Vérifie que la pile n'est pas vide avant d'accéder à top() sinon segfault
	if (!mstack.empty()) {
		std::cout << "Top of stack: " << mstack.top() << std::endl;
	} else {
		std::cerr << "Stack is empty; cannot access top element." << std::endl;
	}

	// Vérifie que la pile n'est pas vide avant d'exécuter pop() sinon segfault
	if (!mstack.empty()) {
		mstack.pop();
		std::cout << "Popped from stack." << std::endl;
	} else {
		std::cerr << "Stack is empty; cannot pop element." << std::endl;
	}
}

void testCopyConstructorAndAssignment() {
	std::cout << "\n=== Test Copy Constructor and Assignment Operator ===" << std::endl;
	MutantStack<int> mstack;
	mstack.push(100);
	mstack.push(200);
	mstack.push(300);

	// Test du constructeur de copie
	MutantStack<int> copyStack(mstack);
	std::cout << "Elements in copied stack: ";
	for (MutantStack<int>::iterator it = copyStack.begin(); it != copyStack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// Test de l'opérateur d'affectation
	MutantStack<int> assignedStack;
	assignedStack = mstack;
	assignedStack.push(400); // Ajouter un élément pour vérifier l'indépendance des piles
	std::cout << "Elements in assigned stack after modification: ";
	for (MutantStack<int>::iterator it = assignedStack.begin(); it != assignedStack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << "Original stack should be unchanged: ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void testDifferentDataTypes() {
	std::cout << "\n=== Test MutantStack with Different Data Types ===" << std::endl;

	// Test avec des chaînes de caractères
	MutantStack<std::string> strStack;
	strStack.push("Hello");
	strStack.push("MutantStack");
	strStack.push("World");

	std::cout << "String stack elements: ";
	for (MutantStack<std::string>::iterator it = strStack.begin(); it != strStack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// Test avec des flottants
	MutantStack<float> floatStack;
	floatStack.push(1.1f);
	floatStack.push(2.2f);
	floatStack.push(3.3f);

	std::cout << "Float stack elements: ";
	for (MutantStack<float>::iterator it = floatStack.begin(); it != floatStack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int main() {
	testBasicOperations();
	testIterator();
	testEmptyStack();
	testCopyConstructorAndAssignment();
	testDifferentDataTypes();
	return 0;
}
