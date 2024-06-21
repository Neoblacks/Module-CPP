/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:20:55 by amugnier          #+#    #+#             */
/*   Updated: 2023/11/29 13:21:56 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

// int main()
// {
// 	IMateriaSource *src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter *me = new Character("me");
// 	AMateria *tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	ICharacter *bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	delete bob;
// 	delete me;
// 	delete src;
// 	return 0;
// }

// int main()
// {
// 	IMateriaSource *src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	std::cout << "MateriaSource created" << std::endl;
// 	ICharacter *antoine = new Character("antoine");
// 	ICharacter *edouard = new Character("edouard");
// 	AMateria *ice;
// 	AMateria *cure;
// 	ice = src->createMateria("ice");
// 	antoine->equip(ice);
// 	ice = src->createMateria("ice");
// 	antoine->equip(ice);
// 	antoine->use(1, *edouard);
// 	cure = src->createMateria("cure");
// 	edouard->equip(cure);
// 	edouard->use(0, *antoine);
// 	edouard->use(1, *antoine);

// 	// ice = antoine->getAddress(0);
// 	// antoine->unequip(0);
// 	// ice = antoine->getAddress(1);
// 	// antoine->unequip(1);

// 	cure = edouard->getAddress(0);
// 	edouard->unequip(0);

// 	// delete ice;
// 	// delete cure;
// 	delete edouard;
// 	delete antoine;
// 	delete src;
// 	return 0;
// }

int main(void)
{
	IMateriaSource *src = new MateriaSource();
	std::cout << std::endl;
	std::cout << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << std::endl;

	ICharacter *me = new Character("me");
	std::cout << std::endl;

	AMateria *tmp;
	tmp = src->createMateria("ice");
	std::cout << std::endl;
	me->equip(tmp);
	tmp = src->createMateria("cure");
	std::cout << std::endl;
	me->equip(tmp);
	tmp = src->createMateria("test");
	std::cout << std::endl;
	me->equip(tmp);

	std::cout << std::endl;

	ICharacter *bob = new Character("bob");
	std::cout << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	std::cout << std::endl;

	AMateria *tmp1;
	AMateria *tmp2;
	AMateria *tmp3;

	tmp1 = me->getAddress(0);
	me->unequip(0);
	std::cout << std::endl;

	tmp2 = me->getAddress(1);
	me->unequip(1);
	std::cout << std::endl;

	tmp3 = me->getAddress(2);
	me->unequip(2);

	std::cout << std::endl;

	std::cout << std::endl;
	delete tmp1;
	delete tmp2;
	delete tmp3;
	std::cout << std::endl;

	delete bob;
	delete me;
	delete src;
	return 0;
}
