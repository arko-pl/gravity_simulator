/*
 * OpenCL based accelerator for base calculations.
 * Copyright (C) 2016  Michał Walenciak <MichalWalenciak@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef OPENCLACCELERATOR_HPP
#define OPENCLACCELERATOR_HPP

#include "iaccelerator.hpp"

class OpenCLAccelerator: public IAccelerator
{
    public:
        OpenCLAccelerator();
        OpenCLAccelerator(const OpenCLAccelerator &) = delete;
        ~OpenCLAccelerator();

        OpenCLAccelerator& operator=(const OpenCLAccelerator &) = delete;

        virtual double step();
};

#endif // OPENCLACCELERATOR_HPP
