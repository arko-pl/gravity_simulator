/*
 * Simulation Controller
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

#ifndef SIMULATIONCONTROLLER_HPP
#define SIMULATIONCONTROLLER_HPP

#include <QTimer>

#include "simulation_engine.hpp"

class ObjectsScene;

class SimulationController: public QObject, ISimulationEvents
{
        Q_OBJECT

    public:
        SimulationController();
        SimulationController(const SimulationController &) = delete;
        ~SimulationController();
        SimulationController& operator=(const SimulationController &) = delete;

        void setScene(ObjectsScene *);

        void beginSimulation();
        int fps() const;

    private:
        SimulationEngine m_engine;
        QTimer m_timer;
        ObjectsScene* m_scene;
        int m_fps;
        int m_framesCounter;

        void tick();

        // ISimulationEvents:
        virtual void objectsColided(const Object&, const Object&) override;
        virtual void objectCreated(int id, const Object &) override;
        virtual void objectAnnihilated(const Object &) override;
        virtual void objectUpdated(int id, const Object &) override;

    signals:
        void fpsUpdated(int);
        void objectCountUpdated(int);
};

#endif // SIMULATIONCONTROLLER_HPP
