/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zessadqu <zessadqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:29:22 by zessadqu          #+#    #+#             */
/*   Updated: 2023/04/25 00:40:36 by zessadqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_fixedPointValue = 0;
}

Fixed::Fixed(Fixed const &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::Fixed(int const n)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = n << this->_fractionalBits;
}

Fixed::Fixed(float const n)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(n * (1 << this->_fractionalBits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(Fixed const &copy)
{
    std::cout << "Assignation operator called" << std::endl;
    this->_fixedPointValue = copy.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)this->_fixedPointValue / (float)(1 << this->_fractionalBits));
}

int Fixed::toInt(void) const
{
    return (this->_fixedPointValue >> this->_fractionalBits);
}

std::ostream & operator<<(std::ostream &o, Fixed const &rhs)
{
    o << rhs.toFloat();
    return (o);
}