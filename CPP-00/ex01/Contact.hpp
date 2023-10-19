/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:24:44 by amugnier          #+#    #+#             */
/*   Updated: 2023/10/19 14:27:03 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact
{
public:

	Contact( void );
	~Contact(void);
	void		set_index(int index);
	void		display_contact_info(int index) const;
	void		initialization(void);
	void		viewing(int index) const;


private:

	int		_index;
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_number;
	std::string	_darkest_secret;

	std::string _get_contact(std::string str) const;
	std::string _printlen(std::string str) const;
};

#endif
