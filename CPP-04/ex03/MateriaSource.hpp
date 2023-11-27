/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:49:00 by amugnier          #+#    #+#             */
/*   Updated: 2023/11/27 17:52:26 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &); // ? src
		MateriaSource &operator=(MateriaSource const &);

		AMateria *createMateria(std::string const &type);
		AMateria *getMateria(std::string const &type);
		void learnMateria(AMateria *);
		~MateriaSource();

	private:
		AMateria *_materia[4];
};

#endif
