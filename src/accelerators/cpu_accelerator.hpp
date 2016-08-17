/*
 * Cpu based accelerator for calculations.
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

#ifndef CPUACCELERATOR_HPP
#define CPUACCELERATOR_HPP

#include <vector>

#include "mt_accelerator_base.hpp"
#include "../object.hpp"

class Objects;

class CpuAccelerator: public MTAcceleratorBase
{
    public:
        CpuAccelerator(Objects &);
        CpuAccelerator(const CpuAccelerator &) = delete;
        ~CpuAccelerator();
        CpuAccelerator& operator=(const CpuAccelerator &) = delete;

    private:
        virtual void forcesFor(std::size_t, std::vector<XY> &) const override;
};

#endif // CPUACCELERATOR_HPP