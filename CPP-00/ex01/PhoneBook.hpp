/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:09:38 by amugnier          #+#    #+#             */
/*   Updated: 2023/10/19 13:54:11 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook( void );
		~PhoneBook( void );

		void		add_new_contact(void);
		void		search_contact(void) const;
		void		display_contact(void) const;
		void		enter_phonebook(void) const;
	private:
		Contact		_contact[8];
		int			_readcin(void) const;
};

#endif
