/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:23:59 by likong            #+#    #+#             */
/*   Updated: 2024/10/09 09:34:50 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure: public AMateria{
	public:
		Cure();
		Cure(const Cure &);
		~Cure() override;

		Cure		&operator = (const Cure &);

		AMateria	*clone() const override;
		void		use(ICharacter &target) override;
};
