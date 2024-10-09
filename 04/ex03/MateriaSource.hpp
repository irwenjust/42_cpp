/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:26:17 by likong            #+#    #+#             */
/*   Updated: 2024/10/08 18:54:09 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource{
	private:
		AMateria	*_inventory[4];
	
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		~MateriaSource() override;

		MateriaSource	&operator = (const MateriaSource &other);

		void			learnMateria(AMateria *m) override;
		AMateria		*createMateria(std::string const &type) override;
};
