/*
 * Widget with ifnformation about simulation
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

#ifndef SIMULATIONINFOWIDGET_HPP
#define SIMULATIONINFOWIDGET_HPP

#include <QWidget>
#include <QGraphicsItem>
#include <QGroupBox>
#include "types.hpp"

class QLabel;

class SimulationInfoWidget: public QWidget
{
    public:
        SimulationInfoWidget(QWidget *);
        SimulationInfoWidget(const SimulationInfoWidget &) = delete;
        ~SimulationInfoWidget();

        SimulationInfoWidget& operator=(const SimulationInfoWidget &) = delete;

        void updateFps(int);
        void updateObjectCount(int);
		void updateObjectData(const QGraphicsItem *);

    private:
        QLabel* m_fpsValue;
        QLabel* m_objCountValue;
        QLabel* m_objIDValue;
        QLabel* m_objPosValue;
        QLabel* m_objMassValue;
        QLabel* m_objRadiusValue;
};

#endif // SIMULATIONINFOWIDGET_H
