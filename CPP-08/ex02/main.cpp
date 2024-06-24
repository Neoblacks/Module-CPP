// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.cpp                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/03/12 13:56:23 by amugnier          #+#    #+#             */
// /*   Updated: 2024/06/24 13:53:26 by amugnier         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "MutantStack.hpp"

// int main()
// {

// 	std::cout << "\033[32m----------TEST 1-----------\033[0m" << std::endl
// 			  << std::endl;

// 	std::list<int> list;

// 	list.push_back(5);
// 	list.push_back(17);

// 	std::cout << "Dernier élément après push_back(17): " << list.back() << std::endl; // Affiche 17

// 	list.pop_back();

// 	std::cout << "Taille de la liste après pop_back(): " << list.size() << std::endl; // Affiche la taille de la liste, qui devrait être 1

// 	list.push_back(3);
// 	list.push_back(5);
// 	list.push_back(737);
// 	list.push_back(0);

// 	std::list<int>::iterator ita = list.begin();
// 	std::list<int>::iterator itd = list.end();

// 	std::cout << std::endl
// 			  << "Contenu de la liste:" << std::endl;

// 	while (ita != itd)
// 	{
// 		std::cout << *ita << std::endl;
// 		++ita;
// 	}

// 	std::cout << std::endl;

// 	std::cout << "\033[32m----------TEST 2-----------\033[0m" << std::endl
// 			  << std::endl;

// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);

// 	std::cout << "Dernier élément après push(17): " << mstack.top() << std::endl; // Affiche 17

// 	mstack.pop();

// 	std::cout << "Taille de la pile après pop(): " << mstack.size() << std::endl; // Affiche la taille de la pile, qui devrait être 1

// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	mstack.push(0);

// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();

// 	std::cout << std::endl
// 			  << "Contenu de la pile:" << std::endl;

// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return 0;
// }

#include "MutantStack.hpp"

int main()
{
	std::cout << "\033[32m----------TEST 1-----------\033[0m" << std::endl << std::endl;

	std::list<int> list;

	list.push_back(5);
	list.push_back(17);

	std::cout << "Dernier élément après push_back(17): " << list.back() << std::endl; // Affiche 17

	list.pop_back();

	std::cout << "Taille de la liste après pop_back(): " << list.size() << std::endl; // Affiche la taille de la liste, qui devrait être 1

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

	std::list<int>::iterator ita = list.begin();
	std::list<int>::iterator itd = list.end();

	std::cout << std::endl << "Contenu de la liste:" << std::endl;

	while (ita != itd)
	{
		std::cout << *ita << std::endl;
		++ita;
	}

	std::cout << std::endl;

	std::cout << "\033[32m----------TEST 2 (avec std::deque)-----------\033[0m" << std::endl << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << "Dernier élément après push(17): " << mstack.top() << std::endl; // Affiche 17

	mstack.pop();

	std::cout << "Taille de la pile après pop(): " << mstack.size() << std::endl; // Affiche la taille de la pile, qui devrait être 1

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << std::endl << "Contenu de la pile:" << std::endl;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;

	std::cout << "\033[32m----------TEST 3 (avec std::list)-----------\033[0m" << std::endl << std::endl;

	MutantStack<int, std::list<int> > mstack_list;
	mstack_list.push(5);
	mstack_list.push(17);

	std::cout << "Dernier élément après push(17): " << mstack_list.top() << std::endl; // Affiche 17

	mstack_list.pop();

	std::cout << "Taille de la pile après pop(): " << mstack_list.size() << std::endl; // Affiche la taille de la pile, qui devrait être 1

	mstack_list.push(3);
	mstack_list.push(5);
	mstack_list.push(737);
	mstack_list.push(0);

	MutantStack<int, std::list<int> >::iterator it_list = mstack_list.begin();
	MutantStack<int, std::list<int> >::iterator ite_list = mstack_list.end();

	std::cout << std::endl << "Contenu de la pile:" << std::endl;

	while (it_list != ite_list)
	{
		std::cout << *it_list << std::endl;
		++it_list;
	}
	std::cout << std::endl;

	std::cout << "\033[32m----------TEST 4 (avec std::vector)-----------\033[0m" << std::endl << std::endl;

	MutantStack<int, std::vector<int> > mstack_vector;
	mstack_vector.push(5);
	mstack_vector.push(17);

	std::cout << "Dernier élément après push(17): " << mstack_vector.top() << std::endl; // Affiche 17

	mstack_vector.pop();

	std::cout << "Taille de la pile après pop(): " << mstack_vector.size() << std::endl; // Affiche la taille de la pile, qui devrait être 1

	mstack_vector.push(3);
	mstack_vector.push(5);
	mstack_vector.push(737);
	mstack_vector.push(0);

	MutantStack<int, std::vector<int> >::iterator it_vector = mstack_vector.begin();
	MutantStack<int, std::vector<int> >::iterator ite_vector = mstack_vector.end();

	std::cout << std::endl << "Contenu de la pile:" << std::endl;

	while (it_vector != ite_vector)
	{
		std::cout << *it_vector << std::endl;
		++it_vector;
	}

	std::stack<int, std::vector<int> > s_vector(mstack_vector);
	std::stack<int, std::list<int> > s_list(mstack_list);
	std::stack<int> s(mstack);
	return 0;
}
